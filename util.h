/*
 * Author: Floris Creyf
 * Date: May 2015
 */

#ifndef UTIL_H
#define	UTIL_H

/**
 * Assumes that end_bit is greater than start_bit and that the result is less than
 * 32 bits, length of an unsigned type.
 * TODO Could function a bit more efficiently.
 * @param buffer
 * @param start_bit
 * @param end_bit
 * @return {unsigned}
 */
unsigned get_bits(unsigned char *buffer, int start_bit, int end_bit);

/**
 * Uses get_bits() but mutates offset so that offset == offset + count.
 * @param buffer
 * @param offset
 * @param count
 */
unsigned get_bits_inc(unsigned char *buffer, int *offset, int count);

#endif	/* UTIL_H */
