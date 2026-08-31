
#include <std.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <assist [who]>\n\n"
    "This command will let you try to help someone else in battle by "
    "putting you into combat with everyone he is currently fighting.\n"
    "Be sure to have permission before doing this.",
    this_player() );
}

int cmd_assist(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *tgt_att;

  if (tp->query_busy())
    return notify_fail("You are busy.");

  if (tp->query_ghost())
    return notify_fail("You would not be much help in your present form.");

  if (!str || !(tgt = present(str, env)))
    return notify_fail("Assist who?");

  if (!tgt->is_living())
    return notify_fail("That is not alive.");

  if (tgt == tp)
    return notify_fail("Assist yourself?");

  tgt_att = tgt->query_attackers();

  if (!sizeof(tgt_att))
    return notify_fail(
      capitalize(tgt->query_subjective())+
      " is not under attack."
    );

  // can't assist someone who is fighting you
  if (member_array(tp, tgt_att) != -1)
    return notify_fail("But "+tgt->query_subjective()+" is fighting you!");

  message("info", "%^BOLD%^%^RED%^You come to "+
    tgt->query_cap_name()+"'s aid.%^RESET%^", tp);
  message("info", "%^BOLD%^%^RED%^"+tp->query_cap_name()+
    " comes to your aid.%^RESET%^", tgt);
  message("info", "%^BOLD%^%^RED%^"+tp->query_cap_name()+
    " comes to "+tgt->query_cap_name()+"'s aid.%^RESET%^",
    env, ({ tp, tgt }) );

  // filter out anyone we wouldn't be able to attack with the 'kill' command
  tgt_att = filter(tgt_att, (: $2->ok_to_kill($1) :), tp);

  // add me to their attacker lists
  tgt_att->add_attacker(tp);

  // add them to my list
  tp->set_attackers( tp->query_attackers() | tgt_att );

  return 1;
}

