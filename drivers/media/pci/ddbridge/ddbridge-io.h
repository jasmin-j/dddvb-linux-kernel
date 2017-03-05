/*
 * ddbridge.c: Digital Devices PCIe bridge driver
 *
 * Copyright (C) 2010-2011 Digital Devices GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 only, as published by the Free Software Foundation.
 *
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * To obtain the license, point your browser to
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef _DDBRIDGE_IO_H_
#define _DDBRIDGE_IO_H_

#include <linux/pci.h>

#include "ddbridge.h"

int i2c_io(struct i2c_adapter *adapter, u8 adr,
		  u8 *wbuf, u32 wlen, u8 *rbuf, u32 rlen);
int i2c_read(struct i2c_adapter *adapter, u8 adr, u8 *val);
int i2c_read_regs(struct i2c_adapter *adapter,
			 u8 adr, u8 reg, u8 *val, u8 len);
int i2c_read_reg(struct i2c_adapter *adapter, u8 adr, u8 reg, u8 *val);
int i2c_read_reg16(struct i2c_adapter *adapter, u8 adr,
			  u16 reg, u8 *val);
int i2c_write_reg(struct i2c_adapter *adap, u8 adr,
			 u8 reg, u8 val);
int ddb_i2c_master_xfer(struct i2c_adapter *adapter,
			struct i2c_msg msg[], int num);
u32 ddb_i2c_functionality(struct i2c_adapter *adap);

void ddb_i2c_release(struct ddb *dev);
int ddb_i2c_init(struct ddb *dev);

/****************************************************************************/

#define ddbwritel(_val, _adr)        writel((_val), \
				     dev->regs+(_adr))
#define ddbreadl(_adr)               readl(dev->regs+(_adr))
#define ddbcpyto(_adr, _src, _count) memcpy_toio(dev->regs+(_adr), (_src), (_count))
#define ddbcpyfrom(_dst, _adr, _count) memcpy_fromio((_dst), dev->regs+(_adr), (_count))

/****************************************************************************/

#endif
