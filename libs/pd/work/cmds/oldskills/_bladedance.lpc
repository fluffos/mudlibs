// stormy
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_bladedance(string str) {
   int dmg, hits, hitsl, hitsm, hitsn, hitso, i, clear, b;
   object ob, tp, env;
   object *wield;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_subclass() != "swashbuckler")
      return notify_fail("What?\n");
   if (tp->query_level() < 5)
      return notify_fail("You cannot do this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Your target is dead");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to slash with!\n");
        return 0;
    } 
   i = sizeof(wield);
   clear = 0;
   while (i--) {
     if (wield[i]->query_type() == "blade")
      clear = 1;
   }
   if (!clear) return notify_fail("You need a blade to dance with!\n");
   if (ob == tp)
      return notify_fail("That is not wise.\n");
   if (tp->query_sp() < 20) 
      return notify_fail("You are too tired.\n");
   write("%^BOLD%^WHITE%^You begin to dance around moving your blades in an intricate pattern!%^RESET%^");
   message("info", "%^BOLD%^WHITE%^"+tp->query_cap_name()+" begin to dance around moving "+tp->query_title_gender()+" blades in an intricate pattern!%^RESET%^", environment(tp), ({ tp }));
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   tp->set_disable();
   dmg = tp->query_skill("blade")/2 + tp->query_skill("attack")/2;
   dmg += tp->query_stats("dexterity")/3;
   dmg -= ob->query_stats("constitution")/4 + ob->query_stats("dexterity")/4;
   dmg -= ob->query_skill("defense")/4;
   if (dmg < 10) {
      write("You miss!");
      return 1;
   }
   write("%^BOLD%^WHITE%^You cut "+ob->query_cap_name()+" with your blade!%^RESET%^");
   tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you with a blade!%^RESET%^");
   tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" with a blade!%^RESET%^", ({ob, tp}));
   tp->add_sp(- (10 + random(dmg/10)));
   ob->damage(dmg);
   
if ((tp->query_level()) > 12 && random(18) < 8) {
hits = tp->query_skill("blade")/3 + tp->query_skill("attack")/3;
hits += tp->query_stats("strength")/3 + tp->query_stats("dexterity")/3;
hits -= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/4;
hits -= ob->query_skill("defense")/4;
write("%^BOLD%^WHITE%^You sneak another cut!%^RESET%^");
tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^",({ob,tp}));
tp->add_sp(-(10 + random(hits/11)));
ob->damage(hits);
}
if ((tp->query_level()) > 20 && random(18) < 8) {
hitsl = tp->query_skill("blade")/3 + tp->query_skill("attack")/3;
hitsl += tp->query_stats("strength")/3 + tp->query_stats("dexterity")/3;
hitsl-= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/4;
hitsl -= ob->query_skill("defense")/4;
write("%^BOLD%^WHITE%^You sneak in another cut!%^RESET%^");
tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^", ({ob,tp}));
tp->add_sp(-(10 + random(hitsl/13)));
ob->damage(hitsl);
}
if ((tp->query_level()) > 28 && random(18) < 8) {
hitsm = tp->query_skill("blade")/3 + tp->query_skill("attack")/3;
hitsm += tp->query_stats("strength")/3 + tp->query_stats("dexterity")/3;
hitsm -= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/4;
hitsm-= ob->query_skill("defense")/4;
write("%^BOLD%^WHITE%^You sneak in another cut!%^RESET%^");
tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^", ({ob,tp}));
tp->add_sp(-(10 + random(hitsm /15)));
ob->damage(hitsm);
}
if ((tp->query_level()) > 36 && random(18) < 8) {
hitsn = tp->query_skill("blade")/3 + tp->query_skill("attack")/3;
hitsn += tp->query_stats("strength")/3 + tp->query_stats("dexterity")/3;
hitsn -= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/4;
hitsn-= ob->query_skill("defense")/3;
write("%^BOLD%^WHITE%^You sneak in another cut!%^RESET%^");
tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you again!%^RESET%^");
tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" again!%^RESET%^", ({ob,tp}));
tp->add_sp(-(10 + random(hitsn /17)));
ob->damage(hitsn);
}
if ((tp->query_level()) > 44 && random(18) < 8) {
hitso = tp->query_skill("blade")/2 + tp->query_skill("attack")/2;
hitso += tp->query_stats("strength")/3 + tp->query_stats("dexterity")/3;
hitso -= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/4;
hitso-= ob->query_skill("defense")/3;
write("%^BOLD%^WHITE%^You cut your opponent on the cheak!%^RESET%^");
tell_object(ob, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts you on the cheak!%^RESET%^");
tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" cuts "+ob->query_cap_name()+" on the cheak!%^RESET%^",({ob,tp}));
tp->add_sp(-(10 + random(hitso /19)));
ob->damage(hitso);
}
return 1;
}
void help() {
write("
Syntax: <bladedance [victim]>
Swashbucklers dance around in an intricate show of swordsmanship.
The higher the swashbuckler's level, the more intricate the dance.
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 5)
   if (o->query_subclass() == "swashbuckler")
     return 1;
}
