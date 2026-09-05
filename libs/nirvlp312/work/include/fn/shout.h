#ifndef SHOUT_H
#define SHOUT_G

/****************************************************************************/
/* check_shout() */

varargs void check_shout(string str, string lang) {
  int i;
  object *user;

  user = users();
  for (i = 0; i < sizeof(user); i--;) {
    if (user[i] && this_player() != user[i]) user[i]->shout_tell(str, lang);
  }
}

#endif /* SHOUT_H */

