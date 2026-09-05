#ifndef _kernel_simul_bits_h
#define _kernel_simul_bits_h

int count_bits_of_byte(int byte);
int count_bits(mixed flag_list);
mixed combine_bits(closure operator, mixed flag_list, mixed another_flag_list);

#endif

