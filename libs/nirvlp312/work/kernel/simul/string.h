#ifndef _kernel_simul_string_h
#define _kernel_simul_string_h

varargs string break_string(string str,int width,mixed indent,
                            int special_first_line,string align);
string capitalize_coloured(string s);
varargs string describe(mixed what,mixed the,int full,int count,
                        status possessive_s,
                        string *uninteresting_state_descriptions);
string mprintf(string str,mapping ins);

#endif
