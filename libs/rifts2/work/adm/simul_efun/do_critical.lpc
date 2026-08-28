//    Automatically does a critical to an object.
//
//    DarkeLIB 0.1
//    -Diewarzau 2/21/95

varargs void do_critical(object from, object at, mixed crits, string limb) {
  object ob;
  string *arg_p;

  if(!stringp(crits) && !pointerp(crits)) return;
  if(!living(at)) return;
  if(stringp(crits)) arg_p = ({ crits });
  else arg_p = crits;
  seteuid(getuid(this_object()));
  ob = find_object_or_load("/std/spells/spell");
  ob->do_criticals(arg_p, limb, from, at);
  return;
}

