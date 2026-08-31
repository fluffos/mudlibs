#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();
void vortex();

int cmd_vortex(string str) {
   int dmg, i, x;
   object *all, *partym, tp, env;
   string party;
   tp = this_player();
   env = environment(tp);

   if(!spell())
     return notify_fail("What?\n");
   if(env->query_property("no attack"))
     return notify_fail("Greater powers prevent your malice.\n");
   if(env->query_property("no magic"))
     return notify_fail("Greater powers suppress your magic.\n");
   if(this_player()->query_disable())
     return notify_fail("You are too busy with something else.\n");
   if(this_player()->query_magic_round())
     return notify_fail("You are already casting a spell.\n");
   if(tp->query_mp() < 65)
     return notify_fail("Your magical power is depleted.\n");

   all = all_inventory(env);
   i = sizeof(all);
   party = tp->query_party();
   partym = PARTY_D->query_party_members(tp);

   message("info", "%^MAGENTA%^A sphere of protection envelops you as a vortex forms!%^RESET%^", tp);
   message("info", "%^MAGENTA%^"+tp->query_cap_name()+" shields you from his vortex.%^RESET%^", partym, tp);
   tp->set_paralyzed(1, "%^BOLD%^MAGENTA%^The shield's energy holds you still.%^RESET%^", "%^BOLD%^MAGENTA%^The shield releases you.%^RESET%^");

   while(i--) {
     if(all[i] != tp)
     if(all[i]->query_party() != party)
     if(living(all[i]))
     if(tp->kill_ob(all[i]))
     vortex(all[i]);
     }
   return 1;
}

void vortex(object ob) {
     object tp;
     int dmg;
     tp = this_player();
     dmg =  tp->query_skill("faith")/3;
     dmg += tp->query_skill("summoning")/3;
     dmg += tp->query_stats("wisdom") * 2;
     dmg += tp->query_skill("magic attack")/3;
     dmg += random(this_player()->query_level());
     dmg -= ob->query_skill("magic defense")/3;
     dmg -= ob->query_stats("wisdom");
     dmg -= ob->query_level();
     if(tp->query_mp() > 65)
       dmg  = dmg*3/2;
     message("info", "%^BOLD%^BLACK%^Demonic energy devours your life force.%^RESET%^", ob);
     message("info", "%^RED%^Demonic energy strikes "+ob->query_cap_name()+".%^RESET%^", environment(ob), ob);
     ob->do_elemental("unholy", dmg);
     tp->add_mp(-dmg/7);
     tp->add_skill_points("faith", dmg/10);
}

int spell() {
    object tp;
    tp = this_player();
    if(!tp)				 return 0;
    if(tp->is_monster())		 return 1;
    if(tp->query_subclass() != "kataan") return 0;
    if(tp->query_level() < 50)		 return 0;
    return 1;
}

void help() {
write("
Syntax: <vortex>
One of the kataan's most powerful spells, the vortex
attacks the lifeforce of all living beings in the area,
excluding the caster and their allies.
");
}
