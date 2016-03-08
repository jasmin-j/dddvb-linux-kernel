#ifndef _TDA18212DD_H_
#define _TDA18212DD_H_

#if IS_REACHABLE(CONFIG_DVB_TDA18212DD)

struct dvb_frontend *tda18212dd_attach(struct dvb_frontend *fe,
				       struct i2c_adapter *i2c, u8 adr);

#else

static inline struct dvb_frontend *tda18212dd_attach(struct dvb_frontend *fe,
					struct i2c_adapter *i2c, u8 adr);
{
	pr_warn("%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}

#endif /* CONFIG_DVB_TDA18212DD */

#endif /* _TDA18212DD_H_ */
