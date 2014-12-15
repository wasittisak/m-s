#ifndef _I2CMASTER_H
#define _I2CMASTER_H   1
/************************************************************************* 
* Title:    C include file for the I2C master interface 
*           (i2cmaster.S or twimaster.c)
* Author:   Peter Fleury <pfleury@gmx.ch>  http://jump.to/fleury
* File:     $Id: i2cmaster.h,v 1.10 2005/03/06 22:39:57 Peter Exp $
* Software: AVR-GCC 3.4.3 / avr-libc 1.2.3
* Target:   any AVR device
* Usage:    see Doxygen manual
**************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

#include <avr/io.h>

#include "autoconf.h"
#include "../../twi.h"


struct _avr_twi_op {
  uint8_t address;
  uint8_t buflen;
  uint8_t bufpos;
  uint8_t *buf;
};

typedef struct _avr_twi_op avr_twi_op;

struct _avr_twi_device {
	struct _avr_twi_op op; 
	uint8_t status;
};

extern volatile struct _avr_twi_device _twi0;

#define hwtwi0_init(speed) ({\
	TWSR = 0;\
  TWBR = (uint8_t)(((F_CPU/speed)-16)/2);\
})

#define TWCR_DEFAULT (_BV(TWEA) | _BV(TWEN) | _BV(TWIE))

#define TWCR_NOT_ACK (_BV(TWINT) | _BV(TWEN) | _BV(TWIE))
#define TWCR_ACK (TWCR_NOT_ACK | _BV(TWEA))

#define TWI_ERR_BUSY 0x0100

/// always set when twi bus is ready to receive more data
#define TWI_READY 0
/// set when data has been sent but no stop condition has been sent yet
#define TWI_IDLE	1

extern void 		twi0_init_default(void);

/// sends a missing stop and prepares the device for receiving more data
#define twi0_begin() (\
	(_twi0.status & _BV(TWI_IDLE))?({twi0_end();}):(0),\
	_twi0.status &= ~(_BV(TWI_IDLE))\
)

/// sends stop signal on the bus
#define twi0_end() ({\
	TWCR = TWCR_DEFAULT | _BV(TWINT) | _BV(TWSTO);\
	_twi0.status |= _BV(TWI_READY);\
})

/// address is the first byte of data
extern uint16_t 		twi0_start_write(const uint8_t *data, size_t data_sz);
/// address is the first byte of data
extern uint16_t 		twi0_start_read(uint8_t *data, size_t data_sz);
/// waits until current transaction has completed
//extern void 		twi0_wait_until_transaction_completed(void);

#define twi0_status() (_twi0.status)
#define twi0_sync() do { } while(!(_twi0.status & (_BV(TWI_IDLE) | _BV(TWI_READY))))

//extern void 		twi0_start_transaction(i2c_op_list_t);
/*
#define twi0_is_busy() PFCALL(CONFIG_TWI0_NAME, is_busy)
#define twi0_wait() ({ while(twi0_is_busy()); })
#define twi0_start_transaction(op_list) PFCALL(CONFIG_TWI0_NAME, start_transaction, op_list)

extern void PFDECL(CONFIG_TWI0_NAME, init, void);
extern uint8_t PFDECL(CONFIG_TWI0_NAME, is_busy, void);
extern void PFDECL(CONFIG_TWI0_NAME, start_transaction, i2c_op_list_t);
*/
/*
extern void PFDECL(CONFIG_TWI0_NAME, stop, void);
extern unsigned char PFDECL(CONFIG_TWI0_NAME, start, unsigned char addr);
extern unsigned char PFDECL(CONFIG_TWI0_NAME, rep_start, unsigned char addr);
extern uint8_t PFDECL(CONFIG_TWI0_NAME, start_wait, unsigned char addr);
extern unsigned char PFDECL(CONFIG_TWI0_NAME, write, unsigned char data);
extern unsigned char PFDECL(CONFIG_TWI0_NAME, readAck, void);
extern unsigned char PFDECL(CONFIG_TWI0_NAME, readNak, void);
*/

#ifdef __cplusplus
}
#endif

/**@}*/
#endif
