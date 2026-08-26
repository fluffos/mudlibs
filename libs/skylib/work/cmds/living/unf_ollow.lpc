
inherit COMMAND_BASE;


int cmd(object *obs) {
  object *ok, ob;
  string s;

  ok = ({ });
  foreach (ob in obs)
    if (ob->remove_follower(TP))
      ok += ({ ob });

  if (!sizeof(ok)) {
    if (member_array(TP, obs) == -1)
      return notify_fail("You are not following "+query_multiple_short(obs)+
                         ".\n");
    else
      return notify_fail("You are not following " +
        query_multiple_short(obs - ({ TP }) + ({ "yourself" })) + ".\n");
  }

  write("You stop following "+(s=query_multiple_short(ok))+".\n");
  say(TP->the_short()+" stops following "+s+".\n", ok);
  foreach (ob in ok)
    tell_object(ob, TP->the_short() +
                " stops following "+query_multiple_short((ok + ({"you"})) -
                                                         ({ ob }))+".\n");
  return 1;
}

mixed *query_patterns() {
  return ({ "<indirect:living>", (: cmd($1) :) });
}
