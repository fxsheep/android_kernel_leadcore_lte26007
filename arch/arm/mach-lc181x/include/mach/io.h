/* 
**
** Copyright (C) 2009 Leadcoretech, Inc.
**
** This software is licensed under the terms of the GNU General Public
** License version 2, as published by the Free Software Foundation, and
** may be copied, distributed, and modified under those terms.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
*/

#ifndef __ARCH_ARM_MACH_IO_H
#define __ARCH_ARM_MACH_IO_H

#define IO_SPACE_LIMIT 0xffffffff

#define __io(a)			((void __iomem *)(a))
#define __mem_pci(a)		(a)

#endif /* __ARCH_ARM_MACH_IO_H */
