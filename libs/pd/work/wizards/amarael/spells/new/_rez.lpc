// seeker (ressurect) 05/17/2000
// edit by Amarael
// resurrect players
// ************************************************************
// Ok Those if statements might be a bit shoddy, gotta test'em.
// ************************************************************

#include <daemons.h>
inherit DAEMON;
int spell();

int cmd_rez(string str) {
    object ob, corpse, tp;
    object *inv;
    int gift, divis, returned, i;
    tp = this_player();
    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Resurrect who?\n");
    if (tp->query_mp() < 700) return notify_fail("You do not have enough magical power to resurrect.\n");
    if (tp->query_ghost()) return notify_fail("You have to be alive yourself!\n");

    ob = find_player(str);

    if (!ob) return notify_fail("Could not find "+str+".\n");
    if (!ob->is_player()) return notify_fail("This soul cannot be resurrected.\n");
    if (!ob->query_ghost()) return notify_fail(capitalize(ob->query_name())+" is already alive.\n"); //I don't want it saying A shadow
    if(!present(ob, environment(tp))) return notify_fail(capitalize(ob->query_name())+" must be present to be resurrected.\n");
    if(ob->query_race() == "lich" || ob->query_race() == "vampire") return notify_fail("The Undead cannot be resurrected.\n");
    if((tp->query_skill("healing") < 360 && tp->query_skill("belief") < 360 && tp->query_skill("faith") < 360) && (ob->query_race() == "dragon" || ob->query_race() == "demon" || ob->query_race() == "archangel")) return notify_fail("You cannot summon the power to resurrect such a being.\n");

    if(tp->query_skill("healing") < 480 && tp->query_skill("belief") < 480 && tp->query_skill("faith") < 480) {
      corpse = present("corpse", environment(this_player()));
      if (!corpse) return notify_fail("You require a corpse to resurrect "+capitalize(ob->query_name())+".");
      if(member_array(corpse->query_old_race(), (string *)RACE_D->query_races()) == -1) return ("Such a body cannot hold "+capitalize(ob->query_name())+"'s soul.");
      if(corpse->query_old_race() != ob->query_race()) {
        if(ob->query_race() == "dragon" || ob->query_race() == "demon" || ob->query_race() == "archangel") return notify_fail("Such a body cannot hold "+capitalize(ob->query_name())+"'s soul.");
        divis = (tp->query_skill("healing") + tp->query_skill("belief") + tp->query_skill("faith"));
        if(divis > 1800) divis = 1800;
        ob->set_stats("strength", ob->query_stats("strength") * (divis/1800) );
        ob->set_stats("constitution", (int)ob->query_stats("constitution") * (divis/1800));
        ob->set_stats("dexterity", (int)ob->query_stats("dexterity") * (divis/1800) );
        ob->set_stats("charisma", (int)ob->query_stats("charisma") * (divis/1800) );
        ob->set_stats("intelligence", (int)ob->query_stats("intelligence") * (divis/1800) );
        ob->set_stats("wisdom", (int)ob->query_stats("wisdom") * (divis/1800) );
        ob->set_race(corpse->query_old_race());
        }
      else {
        if(divis >= 1200) returned = 1;
        if(divis >= 1500) returned = 2;
        if(divis >= 1800) returned = 3;
        if((ob->query_level() > 19 && ob->query_level() < 27) && returned > 0) ob->set_level(ob->query_level()+1);
        if((ob->query_level() > 26 && ob->query_level() < 40) && returned > 1) ob->set_level(ob->query_level()+2);
        if(ob->query_level() > 39 && returned > 2) ob->set_level(ob->query_level()+3);
        }
      }
    else {
      if(corpse = present("corpse", environment(this_player()))) {
        if(member_array(corpse->query_old_race(), (string *)RACE_D->query_races()) == -1) return ("Such a body cannot hold "+capitalize(ob->query_name())+"'s soul.");
        if(corpse->query_old_race() != ob->query_race()) {
          if(ob->query_race() == "dragon" || ob->query_race() == "demon" || ob->query_race() == "archangel") return notify_fail("Such a body cannot hold "+capitalize(ob->query_name())+"'s soul.");
          divis = (tp->query_skill("healing") + tp->query_skill("belief") + tp->query_skill("faith"));
          if(divis > 1800) divis = 1800;
          ob->set_stats("strength", ob->query_stats("strength") * (divis/1800) );
          ob->set_stats("constitution", (int)ob->query_stats("constitution") * (divis/1800));
          ob->set_stats("dexterity", (int)ob->query_stats("dexterity") * (divis/1800) );
          ob->set_stats("charisma", (int)ob->query_stats("charisma") * (divis/1800) );
          ob->set_stats("intelligence", (int)ob->query_stats("intelligence") * (divis/1800) );
          ob->set_stats("wisdom", (int)ob->query_stats("wisdom") * (divis/1800) );
          ob->set_race(corpse->query_old_race());
          }
        else {
          if(divis >= 1200) returned = 1;
          if(divis >= 1500) returned = 2;
          if(divis >= 1800) returned = 3;
        if((ob->query_level() > 19 && ob->query_level() < 27) && returned > 0) ob->set_level(ob->query_level()+1);
        if((ob->query_level() > 26 && ob->query_level() < 40) && returned > 1) ob->set_level(ob->query_level()+2);
        if(ob->query_level() > 39 && returned > 2) ob->set_level(ob->query_level()+3);
          }
        }
      }

    gift = ( ( (ob->query_level() * ob->query_level() * ob->query_level() ) / 20 ) * divis );
    ob->add_exp(( ob->query_exp() / 3 ) * (divis/1800));
    ob->add_exp(gift);

    ob->move(environment( tp ));
    message("info", "%^BOLD%^WHITE%^You have been resurrected from the dead!%^RESET%^", ob);
    message("info", "%^BOLD%^WHITE%^You resurrect "+(capitalize(ob->query_name()))+" from the dead!%^RESET%^", tp, );
    message("info", "%^BOLD%^WHITE%^"+tp->query_cap_name()+" resurrects "+(capitalize(ob->query_name()))+" from the dead!%^RESET%^", environment(tp), ({ tp, ob }) );
    tp->add_mp(-700);
    ob->revive();
    ob->new_body();
    ob->set_ghost(0);
    ob->add_hp(tp->query_mp());
    ob->add_sp(tp->query_mp());
    ob->add_mp(tp->query_mp());
    ob->set_heart_beat(1);
    ob->fix_skills();
    ob->fix_vital_bonus();
    ob->set_heal_rate(2);
    tp->set_sp(0);
    tp->set_mp(0);
    inv = all_inventory(corpse);
    this_player()->add_skill_points("healing", gift/10);
    i = sizeof(inv);
    while(i--) {
      inv[i]->move(ob);
      }
    corpse->remove();
    return 1;
}

int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "cleric") return 0;
    if (o->query_level() < 50) return 0;
    if (o->query_skill("belief") < 270) return 0;
    if (o->query_skill("healing") < 270) return 0;
    if (o->query_skill("faith") < 270) return 0;
    return 1;
}
void help() {
    write("Syntax: <resurrect [player]>\n\n"
      "Clerics of great power and belief may resurrect another into a new body.\n"
    );
}
