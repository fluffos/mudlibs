// action.h

#ifndef __ACTION__
#define __ACTION__

varargs void start_busy(mixed busy, mixed interrupt);
int is_busy();
void interrupt_me(object who, string reason);

#endif
