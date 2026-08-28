#ifndef __MORE_H
#define __MORE_H

varargs int more(mixed what, string cl, function endmore, mixed args);
nosave void do_more(string cmd);
void do_help();
nosave void regexp_fwd(string str);
nosave void regexp_bkwd(string str);
string getenv(string val);

#endif /* __MORE_H */
