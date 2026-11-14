#ifndef MOVE_H
#define MOVE_H

#ifndef COMPAT_FLAG

varargs void move(mixed dest) {
  if(!dest) dest = previous_object();
  move_object(this_object(), dest);
}

#endif /* NATIVE_MODE */

#endif /* MOVE_H */