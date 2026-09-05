/* Storage object for the players' equipment after they left the game.
   All not persistent items are stored in clones of this object, one
   clone for each player. */

/* Do not delete this file, do not enter it, do not update it, do not take 
   any item from it, do not destruct anything that is in this object */

/* DO NOTHING AT ALL WITH THIS OBJECT !!!! */

private mapping clone_list;
private string owner;

void notify_leave(object ob, mixed to) {
  if (!first_inventory(this_object())) 
    call_out(#'destruct, 0, this_object());
}

#if 0
void reset(int arg) {
  if (arg &&
      !first_inventory(this_object()))
    call_out(#'destruct, 0, this_object());
}
#endif

status prevent_move() {
  return 1;
}

string identify(object who) {
  if (!who)
    return 0;
  if (query_once_interactive(who))
    return who->query_real_name();
  else
    return object_name(who);
}

object find_clone(mixed who) {
  string identifier;
  if (clonep(this_object()))
    return load_name(this_object())->find_clone(who);
  identifier = stringp(who) ? who : identify(who);
  return clone_list && clone_list[identifier];
}

void set_owner(string identifier) {
  if (!owner)
    owner = identifier;
}

string query_owner() {
  return owner;
}

object load_clone(mixed who) {
  string identifier;
  object ob;
  if (clonep(this_object()))
    return load_name(this_object())->load_clone(who);
  identifier = stringp(who) ? who : identify(who);
  ob = clone_list && clone_list[identifier];
  if (ob)
    return ob;
  ob = clone_object(load_name(this_object()));
  if (clone_list)
    clone_list[identifier] = ob;
  else
    clone_list = ([ identifier : ob ]);
  ob -> set_owner(identifier);
  return ob;
}

void notify_destruct() {
  object *clones;
  int i;
  if (this_interactive())
    log_file("ILLEGAL", ctime() + " " + this_interactive()->query_real_name() +
                        " destructed " + object_name(this_object()) + ".\n");
  if (clonep(this_object()) || !clone_list)
    return;
#if 0
  clones = m_values(clone_list);
  for (i=0;i<sizeof(clones);i++)
    if (clones[i])
      destruct(clones[i]);
#endif
}



