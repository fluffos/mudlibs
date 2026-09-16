#ifndef __ACTION_H__
#define __ACTION_H__

#include <daemons.h>

varargs void simple_action(mixed msg, mixed *obs...);
varargs void my_action(mixed msg, mixed *obs...);
varargs void other_action(mixed msg, mixed *obs...);
varargs void my_target_action(mixed msg, object target, mixed *obs...);
varargs void other_target_action(mixed msg, object target, mixed *obs...);
varargs void target_action(mixed msg, object target, mixed *obs...);
varargs void targetted_action(mixed msg, object target, mixed *obs...);

#endif // __ACTION_H__
