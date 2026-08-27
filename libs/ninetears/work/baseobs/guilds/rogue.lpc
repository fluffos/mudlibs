inherit "/std/guild";

void setup() {
  set_name("rogue");
  set_short("rogue");
  set_long(
    "Rogues are the thieves and scoundrels of Magisk Jord "
    "They are good at opening locks, disarming traps,  "
    "at relieving other people of things they no longer require "
    "and general sneaking around.  "
    " Their survival depends on their speed and ready tongue.\n");
  reset_get();
}

void create()
  {
  ::create();
} /* setup() */

void check_stab(object ob) {
  if (ob && random(4))
    call_out("do_it", 0, ob);
} /* check_stab() */

void do_it(object ob) {
  if (ob)
    do_command("backstab", ob->query_name());
} /* do_it() */

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  if ( w1->query_attack_type() != 3 || w2->query_attack_type() != 3 )
    return 50;

  bon = 50 - (int)me->query_level()*3/2;
  bon = ( bon<10 ? 10 : bon );

  return bon;
}

void on_death(object player, object killer) {
}
