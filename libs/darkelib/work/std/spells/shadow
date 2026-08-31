#include <security.h>



inherit "/std/spells/shadows/shadow";



object who_shadowed;

string exp_mesg;

int lev;



void set_level(int x) { lev = x; }



void start_shadow(object who, int dur, string mesg) {

  seteuid(UID_SHADOW);

  begin_shadow(who);

  who_shadowed = who;

  seteuid(getuid());

  exp_mesg = mesg;

  call_out("expire_just", dur, this_object());

  return;

}



int do_damage(string limb, int amt) {

  int res;

  object prev;



  res = (int)next_shadow()->do_damage(limb, amt);

  if(previous_object() && living(previous_object()))

    prev = previous_object();

  else if(previous_object() && objectp(previous_object()->

              query_caster()))

    prev = previous_object()->query_caster();

  else if(who_shadowed->query_current_attacker())

    prev = (object)who_shadowed->query_current_attacker();

  else return res;

  if(res > 0 && random(11) < lev)

    prev->do_critical(who_shadowed, prev, ({ "impact "+

                (({ "A","B" })[random(2)]) }) );

  return res;

}



void expire_just(object me) {

  if(me != this_object()) {

    next_shadow()->expire_just(me);

next_shadow()->expire_just(me);

    return;

  }

  if(exp_mesg)

    message("info", exp_mesg, who_shadowed);

  remove();

  return;

}



