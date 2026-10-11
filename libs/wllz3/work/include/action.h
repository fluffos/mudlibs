
// action.h

#ifndef __ACTION__
#define __ACTION__

varargs void start_busy(mixed busy, mixed interrupt);
varargs void query_override(string index);
int  run_override(string index);
void delete_override(string index);

#endif
