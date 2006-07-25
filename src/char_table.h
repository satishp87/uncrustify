/**
 * @file char_table.h
 * A simple table to help tokenize stuff.
 * Used to parse strings (paired char) and words.
 *
 * $Id$
 */
#ifndef CHAR_TABLE_H_INCLUDED
#define CHAR_TABLE_H_INCLUDED


/**
 * bit0-7 = paired char
 * bit8 = OK for keyword 1st char
 * bit9 = OK for keyword 2+ char
 *
 * bit12 = open (not used)
 * bit13 = close (not used)
 */
static const int char_table[128] =
{
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   /* [........] */
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   /* [........] */
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   /* [........] */
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   /* [........] */
   0x0000, 0x0000, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0027,   /* [ !"#$%&'] */
   0x1029, 0x2028, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,   /* [()*+,-./] */
   0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200,   /* [01234567] */
   0x0200, 0x0200, 0x0000, 0x0000, 0x103e, 0x0000, 0x203c, 0x0000,   /* [89:;<=>?] */
   0x0200, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [@ABCDEFG] */
   0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [HIJKLMNO] */
   0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [PQRSTUVW] */
   0x0300, 0x0300, 0x0300, 0x105d, 0x0000, 0x205b, 0x0000, 0x0300,   /* [XYZ[\]^_] */
   0x0060, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [`abcdefg] */
   0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [hijklmno] */
   0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300,   /* [pqrstuvw] */
   0x0300, 0x0300, 0x0300, 0x107d, 0x0000, 0x207b, 0x0000, 0x0000,   /* [xyz{|}~.] */
};
#define CT_KW1       0x0100
#define CT_KW2       0x0200
#define CT_OPEN      0x1000
#define CT_CLOSE     0x2000
#define CT_OCP       (CT_OPEN | CT_CLOSE)
#define CT_EVAL      0x4000


static_inline int get_char_table(char ch)
{
   return(char_table[(int)ch & 0x7f]);
}

#endif   /* CHAR_TABLE_H_INCLUDED */
