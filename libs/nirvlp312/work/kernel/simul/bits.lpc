/*
 * /kernel/simul/bits.c
 *
 * functions concerned with the handling of bit strings.
 * Rumplemintz
 */

#include "/kernel/simul/fold.h"

private string bit_count_string = "                                "
                                  "01121223122323341223233423343445"
                                  "12232334233434452334344534454556";
int count_bits_of_byte(int byte) {
  return bit_count_string[byte] - '0';
}

int count_bits(mixed flag_list) {
  if (!stringp(flag_list))
    raise_error("Bad argument to count_bits()\n");
  return fold_left(#'+,map(
                           to_array(flag_list)[0..strlen(flag_list)-1],
                           #'count_bits_of_byte));
}

mixed combine_bits(closure operator,mixed flag_list,mixed another_flag_list) {
  int i;
  mixed result;
  result = flag_list;
  for (i=strlen(result); i--; )
    result[i] = 32 + funcall(operator,result[i]-32,another_flag_list[i]-32);
  return result;
}

