#ifndef AES_H
#define AES_H
#include "includes.h"

#ifdef EN_ALG_SW

/**
**  p:    plaintxt
**  plen: plaintxt length
**  key:  AES key
**  ciper:cipertext
**/
void aes(sint8 *p, sint32 plen, sint8 *key, sint8 * cipher);

/**
** c         : ciphertext
** clen      : ciphertext length
** key       : AES key
** pPlainText: plaintxt
**/
void deAes(sint8 *c, sint32 clen, sint8 *key, sint8 * pPlainText);
#endif

#endif

