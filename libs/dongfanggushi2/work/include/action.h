// action.h

#ifndef __ACTION__
#define __ACTION__

int time_left();
void reset_time_unit();
varargs int act(function action, function time_short_func);

varargs void start_busy(mixed busy, mixed interrupt);
int is_busy();
void interrupt_me(object who, string reason);

#endif
