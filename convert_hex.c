#include "main.h"

unsigned int convert_x(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_x - Converts an unsigned int argument to hex usi-
 * ng abscdef and stores it to a buffer contained in a str-
 * uct.
 * @args: A va_list pointing to the argument to be converted
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */

unsigned int convert_x(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
  unsigned long int num;
  unsigned int ret = 0;
  char *lead = "0x";

  if (len == LONG)
    num = va_arg(args, unsigned long int);
  else
    num = va_arg(args, unsigned int);

  if (HASH_FLAG == 1 && num != 0)
    ret += convert_ubase(output, num, "0123456789abcdef", flags, wid, prec);

  ret += print_neg_width(output, ret, flags, wid);

  return (ret);
}

/**
 * convert_X - converts an unsigned int argument to hex usi-
 * ing ABCDEF and stores it to a buffer contained in a stru-
 * ct.
 * @args: A va_list pointing to the argument to be convert-
 * ed.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */

unsigned int convert_X(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
  unsigned long int num;
  unsigned int ret = 0;
  char *lead = "0X";

  if (len == LONG)
    num = va_arg(args, unsigned long);
  else
    num = va_arg(args, unsigned int);

  if (len == SHORT)
    num = (unsigned short)num;

  if (HASH_FLAG == 1 && num != 0)
    ret += _memcpy(output, lead, 2);

  if (!(num == 0 && prec == 0))
    ret += convert_ubase(output, num, "0123456789ABCDEF", flags, wid, prec);

  ret += print_neg_width(output, ret, flags, wid);

  return (ret);
}
