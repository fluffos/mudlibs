//  _raise.c
//  from the Nightmare mudlib
//  raises a corpse from the dead
//  Created by Manny@Nightmare 940911

#include <std.h>
#include <objects.h>

inherit DAEMON;

int cmd_raise(string str) {
  object corpse, ob, me;
  int healing, faith, needs, sp_needed, level;
  string Class;

  if(!str) return notify_fail("Raise what?");

  me = this_player();

  if(me->query_ghost())
    return notify_fail("The dead cannot raise the dead.\n");

  Class=me->query_class();
  if(!(Class="cleric" || Class="kataan"))
    return notify_fail("You are unfamilar with such arts.\n");

  if(me->query_level() < 5)
    return notify_fail("You are too ingorant in the ways of the world.\n"
);

  if(!corpse=present(str, environment(this_player())))
    return notify_fail("You feel a bit lost..\n");

  if(!corpse->id("corpse"))
    return notify_fail("You oaf, you can only raise a corpse!!\n");

  needs=(int)me->query_alignment();
  if(Class=="cleric" && needs>1000)
    return notify_fail("You cringe at the thought of performing "
        "such an act of evil.\n");
  if(Class=="kataan" && needs<-800)
    return notify_fail("The gods no longer pay heed to your "
        "evil pleas.\n");
  needs=(needs<0 ? 100 : needs/4);
  me->add_alignment(-(needs<0 ? 100 : needs));

  if((healing=(int)me->query_skill("healing")) < (random(20)+60))
    return notify_fail("You lack the skill to perform such an act.\n");

  if((faith=(int)me->query_skill("faith")) < random(10)+40)
    return notify_fail("The gods fail to hear your words.\n");

  if(me->query_mp() < random(20)+130)
    return notify_fail("Your prayers go unanswered.\n");
  me->add_mp(-(random(50)+100));

  sp_needed=150-healing;
  if(sp_needed < 0) sp_needed=0;
  level = corpse->query_level();
  sp_needed += random(level*10) + 5*level;
  if(me->query_sp() < sp_needed)
    return notify_fail("Your concentration is just too weak.\n");
  me->add_sp(-sp_needed);

  this_player()->set_magic_round();
  ob = new(OB_UNDEAD);
  corpse->make_new_body(ob);
  ob->set_level(level-(200/needs));
  ob->set_decay_rate(to_int(5*sqrt(to_float(healing)))+random(100));
  ob->set_exp(random(100));
  ob->set("master", me);
  ob->move(environment(me));
  corpse->remove();
  me->add_follower(ob);
  me->add_skill_points("healing", random(healing/4));
  me->add_skill_points("faith", random(faith/8));

  message("say", "%^GREEN%^You call upon your "
    "gods to allow the dead one last chance of service.", me);
  message("say", "%^GREEN%^%^BOLD%^"+me->query_cap_name()+"Waves "+
    me->query_possessive()+" hands wildily in the air and chants a spell "+
    "of archaic words.  The dead corpse begins to rise.", environment(me));

  return 1;
}


void help() {
  message("help", "Syntax: raise <corpse>\n\n"
      "Attempt to raise a corpse from the dead.\n"
      "See also: order", this_player());
}


