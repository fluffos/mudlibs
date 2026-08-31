#include <std.h>
#include <daemons.h>

inherit "/wizards/amarael/spells/elemspell_d";

int spell();

mapping active;

int cmd_defiance(string str) {
    object tp, ob;
    int valour, faith, effect;
    tp = this_player();
    if(str == "me")
      ob = tp;
    else
      ob = present(str, environment(tp));
    if(!active)
      active = ([ ]);
    valour = tp->query_skill("valor");
    faith  = tp->query_skill("faith");
    effect = (faith + valour)*2;
    
    if(!spell())
      return notify_fail("What?\n");
    if(this_player()->query_disable())
      return notify_fail("You are too busy with something else.\n");
    if(this_player()->query_magic_round())
      return notify_fail("You are already casting a spell.\n");
    if(tp->query_current_attacker())
      return notify_fail("Combat prevents you from casting this spell.\n");
    if(!ob)
      return notify_fail(capitalize(str)+" is not here.\n");
    if(!ob->is_living());
      return notify_fail("Only living things may accept the blessings of the gods.\n");
    if(ob->query_ghost())
      return notify_fail("Only living things may accept the blessings of hte gods.\n");
    if(tp->query_mp() < effect)
      return notify_fail("Your magical power is not strong enough.\n");
    if(member_array(tp->query_name(), active[ob->query_name()]) != -1)
      return notify_fail(ob->query_cap_name()+" has already received your prayer of defiance.\n");


    message("info", "%^%^You pray defiance for "+ob->query_cap_name()+".%^RESET%^", tp);
    message("info", "%^RESET%^BLUE%^"+tp->query_cap_name()+" utters a prayer.%^RESET%^", environemnt(tp), tp);

    if(effect < random(450)) {
      message("info", "Your prayer remains unanswered.", tp);
      return 1;
      }

    ob->add_skill_bonus("defense", (effect/2));
    ob->add_stat_bonus("constitution", (effect/9));
    ob->add_stat_bonus("dexterity", (effect/9));

    tp->set_magic_round();
    tp->add_skill_points("faith", faith/10);
    tp->add_skill_points("valor", valour/10);
    tp->add_mp(effect*3/2);
    
    message("info", "%^BOLD%^WHITE%^The gods answer your prayer for "+ob->query_cap_name()+".", tp);
    message("info", "%^BOLD%^WHITE%^The gods smile upon you, granting the defiance of your enemies.%^RESET%^", ob);

    return 1;
}



void help() {
write("
Syntax: <defiance <living>
A prayer of Paladins, to bring the blessing of
gods in defiance of one's enemies.
");
}

int spell() {
    object o;
    o = this_player();
    if(!o) 				 return 0;
    if(o->is_monster()) return 1;
    if(o->query_subclass() != "paladin") return 0;
    if(o->query_skill("valor") < 120)	 return 0;
    if(o->query_skill("faith") < 90)	 return 0;
    if(o->query_level() < 30)		 return 0;
    return 1;
}
