#include <std.h>
#include <daemons.h>

inherit DAEMON;

int abil();

int cmd_slash(string str) {
    int x,y,i,dmg;
    string target_limb, typez;
    object ob, tp;
    object *wielded, *weaps;

    typez = ({ "knife", "blade", "axe"});
    tp = this_player();
    wielded = tp->query_wielded();
    weaps = ({ });

    i = sizeof(wielded);
    while(i--) {
      if(member_array(wielded[i]->query_type(), typez) != -1)
        weaps += wielded[i];
      }

    if(!abil())
      return notify_fail("What?\n");
    if(tp->query_rest_type())
      return notify_fail("You are not in a position to do that.\n");
    if(environment(tp)->query_property("no attack"))
      return notify_fail("Greater powers prevent your malice.\n");
    if(tp->query_ghost())
      return notify_fail("You'll need a body of your own for that.\n");
    if(!i = sizeof(weaps))
      return notify_fail("You'll need a sharp weapon to slash with.\n");
    if(tp->query_magic_round())
      return notify_fail("You are still casting a spell.\n");
    if(tp->query_disable())
      return notify_fail("You are busy already!\n");
    if(tp->query_sp() < 20)
      return notify_fail("You are too tired to slash.\n");

    if(!ob = present(str, environment(this_player()))) {
      if(!ob = tp->query_current_attacker() || !present(ob, environment(tp)))
        return notify_fail("Slash what?\n");
      }
    if(!ob->is_living())
      return notify_fail(ob->query_cap_name()+" isn't much good for target practice.\n");
    if(ob == tp)
      return notify_fail("Slash yourself, whatever for?\n");
    if(!tp->kill_ob(ob))
      return notify_fail("You cannot attack "+ob->query_cap_name()+"!\n");


    y = 1;
    if(tp->query_skill("blade") > random(120) && i > 1)
      y++;
    if(tp->query_skill("blade") > random(270) && i > 2)
      y++;
    if(tp->query_skill("blade") > random(480) && i > 3)
      y++;

    while(y--) {
      dmg  = tp->query_skill("attack")*3/4;
      dmg += tp->query_stats("strength")*3;
      dmg += tp->query_stats("dexterity")*5/3;
      dmg += weaps[i]->query_wc()*5/2;
      dmg -= ob->query_skill("defense")/2;
      dmg -= ob->query_stats("dexterity");
      dmg *= 2;
      dmg /= 5;

      target_limb = ob->return_target_limb();
      dmg -= ob->query_current_protection(target_limb);
      if(dmg < 10) {
        message("info", "You miss your slash.", tp);
        message("info", tp->query_cap_name()+" misses "+tp->query_possessive()+" slash.", environment(tp), tp);
        return 1;
        }
      dmg += ob->query_current_protection(target_limb);

      message("info", "You slash "+ob->query_cap_name()+" with your "+weaps[y]->query_cap_name()+".", tp);
      message("info", tp->query_cap_name()+" slashes "+ob->query_cap_name()+".", environment(tp), ({ tp, ob }) );
      message("info", tp->query_cap_name()+" slashes you with "+tp->query_possessive()+" "+weaps[y]->query_cap_name()+".", ob);
      ob->do_damage(target_limb, dmg);
      ob->check_on_limb(target_limb);
      this_player()->add_sp(dmg/7);
      }

    return 1;
}

int abil() {
    object tp;
    tp = this_player();
    if(!tp) return 0;
   if(tp->is_monster()) return 1;
    if(tp->query_class() != "fighter")	return 0;
    if(tp->query_level() < 5)		return 0;
    if(tp->query_skill("attack") < 15)	return 0;
    return 1;
}

void help() {
    write("Syntax: <slash [(living)]>\n\n"
      "A fighter command which enables you to use your\n"
      "sharp-edged weapons to slash powerfully at your opponent.\n"
      "If you are wielding more than one sword you have\n"
      "the ability to slash more than once.\n");
}
