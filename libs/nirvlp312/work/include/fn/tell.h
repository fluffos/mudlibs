#ifndef TELL_H
#define TELL_H

/***************************************************************************/
/* tell_objects */

varargs void tell_objects(object *who, string str, object *reject) {
  int i;

  if (!reject) reject = ({});
  for (i = 0; i < sizeof(who); i++) {
    if (who[i] != this_player() && member(reject, who[i]) == -1) {
      tell_object(who[i], str);
    }
  }
}

#endif /* TELL_H */

