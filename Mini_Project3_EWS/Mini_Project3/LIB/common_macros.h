/*
 *  Module: Common
 *  File Name: common_macros.h
 *  Description: commonly used macros for bitwise operations
 *  Author: Esraa Khaled
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


/* Set a certain bit in any register --> bit = 1*/
#define SET_BIT(REG,BIT_NUM) (REG |= (1<<BIT_NUM))

/* Clear a certain bit in any register --> bit = 0*/
#define CLEAR_BIT(REG,BIT_NUM) (REG &= ~(1<<BIT_NUM))

/* Toggle a certain bit in any register --> bit = 1 --> bit = 0 --> bit = 1 ...*/
#define TOGGLE_BIT(REG,NIT_NUM) (REG ^= (1<<BIT_NUM))

/* Rotate Right the register value with a specific number of bits*/
#define ROR(REG, NUM) (REG = (REG >> NUM) | (REG << ((8*sizeof(REG)) - NUM)))

/* Rotate Left the register value with a specific number of bits*/
#define ROL(REG,NUM)  (REG = (REG << NUM) | (REG >> ((8*sizeof(REG)) - NUM)))

/* Checks a certain bit value and return its value --> bit = 1 or 0*/
#define GET_BIT(REG,BIT_NUM) ((REG & (1 << BIT_NUM)) >> BIT_NUM)

/* Checks if a certain bit is set in any register and return true if bit = 1 */
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM))

/*Checks if a certain bit is cleared i any register and return true if bit = 0 */
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM)))



#endif /* COMMON_MACROS_H_ */
