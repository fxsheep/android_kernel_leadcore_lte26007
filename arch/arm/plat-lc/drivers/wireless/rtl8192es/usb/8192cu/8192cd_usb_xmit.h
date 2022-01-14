/*
 *  Header files defines some USB TX inline routines
 *
 *  $Id: 8192cd_usb_xmit.h,v 1.4.4.5 2010/12/10 06:11:55 family Exp $
 *
 *  Copyright (c) 2009 Realtek Semiconductor Corp.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#ifndef _8192CD_USB_XMIT_H_
#define _8192CD_USB_XMIT_H_

#include "./8192cd_usb.h"


#define NR_XMITFRAME	512
// stop netdev tx queue if the remaining amount of xmitframe is equal to threshold when allocating xmitframe
#define STOP_NETIF_TX_QUEUE_THRESH		40
// restart netdev tx queue if the available amount of xmitframe is equal to threshold when recycling xmitframe
#define WAKE_NETIF_TX_QUEUE_THRESH		80

#define MAX_TX_AGG_PKT_NUM		16

#ifdef CONFIG_USB_TX_AGGREGATION
#define MAX_XMITBUF_SZ	16384	//20480	// 20k
#else
#define MAX_XMITBUF_SZ	(2048)
#endif

#define NR_XMITBUFF	5	//(4)

#define XMITBUF_ALIGN_SZ 512

// xmit extension buff defination
#define MAX_XMIT_EXTBUF_SZ	(1536)

#define NR_XMIT_EXTBUFF	(32)

#define MAX_BCN_XMITBUF_SZ	512

#define NR_BCN_XMITBUFF	2

#define TXDESC_SIZE 32

#define PACKET_OFFSET_SZ (8)

#define DEFAULT_TXPKT_OFFSET	1

#define TXAGG_DESC_ALIGN_SZ	8

#define MAX_TCP_ACK_AGG		10
#define TCP_ACK_TIMEOUT		msecs_to_jiffies(10)

enum {
	TXPATH_HARD_START_XMIT = 0,
	TXPATH_SLOW_PATH,
	TXPATH_FIRETX
};

struct xmit_buf {
	_list list;
	_list tx_urb_list;
	
	u16	ext_tag; // 0: Normal xmitbuf, 1: extension xmitbuf.
	u8	*pallocated_buf;
	u8	*pkt_head;
	u8	*pkt_data;
	u8	*pkt_tail;
	u8	*pkt_end;
	
	struct rtl8192cd_priv *priv;
	u8	q_num;
	
	u8	agg_num;
	void    *agg_start_with;

	struct tx_desc_info txdesc_info[MAX_TX_AGG_PKT_NUM];
	
	u8	pkt_offset;	// indicate the num of 8-byte dummy data between TX descriptor and TX packet
	u8	use_hw_queue;	// indicate whether got the ownership to use HW queue
	
	struct urb *pxmit_urb;
	dma_addr_t dma_transfer_addr;	/* (in) dma addr for transfer_buffer */
	
	u8 isSync; //is this synchronous?
	int status; // keeping urb status for synchronous call to access
	struct completion done; // for wirte_port synchronously
};

struct xmit_frame {
	_list list;

	struct tx_insn txinsn;
	struct rtl8192cd_priv *priv;
};


int _rtw_init_xmit_priv(struct rtl8192cd_priv *priv);
void _rtw_free_xmit_priv(struct rtl8192cd_priv *priv);

struct xmit_buf *rtw_alloc_xmitbuf(struct rtl8192cd_priv *priv, u8 q_num);
s32 rtw_free_xmitbuf(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf);

struct xmit_buf *rtw_alloc_xmitbuf_ext(struct rtl8192cd_priv *priv, u8 q_num);
s32 rtw_free_xmitbuf_ext(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf);

struct xmit_buf *rtw_alloc_beacon_xmitbuf(struct rtl8192cd_priv *priv);
s32 rtw_free_beacon_xmitbuf(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf);

struct xmit_frame *rtw_alloc_xmitframe(struct rtl8192cd_priv *priv);
s32 rtw_free_xmitframe(struct rtl8192cd_priv *priv, struct xmit_frame *pxmitframe);
void rtw_free_xmitframe_queue(struct rtl8192cd_priv *priv, _queue *pframequeue);

#ifdef CONFIG_TCP_ACK_TX_AGGREGATION
int rtw_xmit_enqueue_tcpack(struct rtl8192cd_priv *priv, struct tx_insn *txcfg);
void rtw_tcpack_servq_flush(struct rtl8192cd_priv *priv, struct tcpack_servq *tcpackq);
#endif

int rtw_send_xmitframe(struct xmit_frame *pxmitframe);

void rtw_txservq_flush(struct rtl8192cd_priv *priv, struct tx_servq *ptxservq);

void rtw_pspoll_sta_enqueue(struct rtl8192cd_priv *priv, struct stat_info *pstat, int insert_tail);
void rtw_pspoll_sta_delete(struct rtl8192cd_priv *priv, struct stat_info *pstat);
int rtw_enqueue_xmitframe(struct rtl8192cd_priv *priv, struct xmit_frame *pxmitframe, int insert_tail);
struct xmit_frame* rtw_txservq_dequeue(struct rtl8192cd_priv *priv, struct tx_servq *ptxservq);
struct xmit_frame* rtw_dequeue_xmitframe(struct rtl8192cd_priv *priv, int q_num);

void rtw_xmitbuf_aggregate(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf, struct stat_info *pstat, int q_num);

u32 usb_write_port(struct rtl8192cd_priv *priv, u32 addr, u32 cnt, u8 *wmem, int timeout_ms);
void usb_write_port_cancel(struct rtl8192cd_priv *priv);

__inline static u32 usb_write_port_async(struct rtl8192cd_priv *priv, u32 addr, u32 cnt, u8 *wmem)
{
	return usb_write_port(priv, addr, cnt, wmem, -1);
}

__inline static int usb_write_port_sync(struct rtl8192cd_priv *priv, u32 addr, u32 cnt, u8 *wmem)
{
	return usb_write_port(priv, addr, cnt, wmem, RTW_USB_CONTROL_MSG_TIMEOUT);
}

u32 usb_submit_xmitbuf(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf, int timeout_ms);

__inline static u32 usb_submit_xmitbuf_async(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf)
{
	return usb_submit_xmitbuf(priv, pxmitbuf, -1);
}

__inline static int usb_submit_xmitbuf_sync(struct rtl8192cd_priv *priv, struct xmit_buf *pxmitbuf)
{
	return usb_submit_xmitbuf(priv, pxmitbuf, RTW_USB_CONTROL_MSG_TIMEOUT);
}

int rtl8192cd_usb_tx_recycle(struct rtl8192cd_priv *priv, struct tx_desc_info* pdescinfo);
void rtl8192cd_usb_cal_txdesc_chksum(struct tx_desc *ptxdesc);


#endif // _8192CD_USB_XMIT_H_

