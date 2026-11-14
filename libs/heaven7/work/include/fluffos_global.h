#ifndef FLUFFOS_GLOBAL_H
#define FLUFFOS_GLOBAL_H

#ifndef MUDOS
#define MUDOS
#endif

#define status int
#define copy_mapping copy
#define m_indices keys
#define mappingp mapp
#define query_imp_port() 0

varargs mixed move_object(mixed item, mixed dest) {
  object victim;

  if (undefinedp(dest)) {
    if (victim = query_shadowing(this_object()))
      return victim->move_object(item);
    efun::move_object(item);
    return this_object();
  }
  if (stringp(item))
    item = load_object(item);
  if (item != this_object())
    return item->move_object(dest);
  return move_object(dest);
}

int force_me(string str) {
  return efun::command(str);
}

varargs int command(string str, object ob) {
  if (!ob || ob == this_object())
    return efun::command(str);
  return ob->force_me(str);
}

#endif /* FLUFFOS_GLOBAL_H */
