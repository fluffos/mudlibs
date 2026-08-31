#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();
void multi_hit();

int cmd_lightning(string str) {
    int i, dmg, wis;
    object tp, ob;

    tp = this_player();

    if(!spell())
      return notify_fail("What?\n");
    if(environment(tp)->query_property("no attack"))
      return notify_fail("Greater powers prevent your malice.\n");
    if(environment(tp)->query_property("no magic"))
      return notify_fail("Your voice is silenced.\n");
    if(tp->query_ghost())
      return notify_fail("Your voice is hollow.\n");
    if(tp->query_magic_round())
      return notify_fail("You are still casting a spell.\n");
    if(tp->query_disable())
      return notify_fail("You are busy already!\n");
    if(tp->query_mp() < 100)
      return notify_fail("Your magical power is depleted.\n");

    if(!ob = present(str, environment(tp)))
      if(!ob = present(tp->query_current_attacker(), environment(tp)))
        return notify_fail(capitalize(str)+" is not here.\n");


    dmg  = tp->query_skill("psionics")*3/2;
    dmg += tp->query_skill("magic attack")*3/2;
    dmg += tp->query_stats("intelligence");

    wis  = ob->query_skill("magic defense")/2;
    wis += ob->query_stats("wisdom")/2;



    if(( (dmg - wis)/2 - ob->query_current_protection()) < 10 || !tp->kill_ob(ob)) {
      message("info", "Lightning streaks from your fingers, glancing off "+ob->query_cap_name()+".", tp);
      message("info", "Lightning streaks from "+tp->query_cap_name()+"'s fingers, glancing off you.", ob);
      message("info", "Lightning streaks from "+tp->query_cap_name()+"'s fingers, glancing off "+ob->query_cap_name()+".", environment(tp), ({ tp, ob }) );
      tp->add_mp(-(dmg - wis)/20);
      }
    else {
      message("info", "Lightning streaks from your fingers, blasting "+ob->query_cap_name()+".", tp);
      message("info", "Lightning streaks from "+tp->query_cap_name()+"'s fingers, blasting you!", ob);
      message("info", "Lightning streaks from "+tp->query_cap_name()+"'s fingers, blasting "+ob->query_cap_name()+".", environment(tp), ({ tp, ob }) );
      ob->do_elemental("lightning", (dmg - wis));
      tp->add_mp(-(dmg - wis)/7);
      }
    if(tp->query_level() >= 65)
      multi_hit(tp, ob, dmg);
    tp->set_magic_round();
    return 1;
}

void multi_hit(object tp, object ob, int dmg) {
     object *allob;
     int wis, i;

     allob = all_inventory(environment(tp));
     i = sizeof(allob);
     tp->clean_up_attackers();

     while(i--) {
       if(member_array(allob[i], tp->query_attackers()) == -1) continue;
       if(tp->query_mp() < 50) continue;
       if(allob[i] == ob) continue;
       if(allob[i] == tp) continue;
       if(allob[i]->query_party() == tp->query_party()) continue;

       wis  = allob[i]->query_skill("magic defense")/2;
       wis += allob[i]->query_stats("wisdom")/2;
       message("info", "A bolt of lightning arcs, striking "+allob[i]->query_cap_name()+".", environment(tp), allob[i]);
       message("info", "A bolt of lightning arcs and strikes you!", allob[i]);
       ob->do_elemental("lightning", (dmg - wis)*3/4);
       }
}

int spell() {
    object tp;
    tp = this_player();
    if(tp->is_monster())			return 1;
    if(tp->query_subclass() != "sorceror")	return 0;
    if(tp->query_level() < 50)			return 0;
    if(tp->query_skill("psionics") < 270)	return 0;
    return 1;
}

void help() {
    write("Syntax: <lightning [living target]>\n"
	"Great Sorcerors have the ability to push pure electrical\n"
	"energy through their body to strike an opponent.");
}
