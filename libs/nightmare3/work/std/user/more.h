#ifndef __MORE_H
#define __MORE_H

varargs int more(mixed what, string cl, function endmore, mixed args);
protected  void do_more(string cmd);
void do_help();
protected  void regexp_fwd(string str);
protected  void regexp_bkwd(string str);
string getenv(string val);

#endif /* __MORE_H */
