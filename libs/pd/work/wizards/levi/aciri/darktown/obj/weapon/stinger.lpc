#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("stinger");
   set_short("%^RESET%^%^MAGENTA%^a poi%^BOLD%^%^BLACK%^son%^WHITE%^ous %^RESET%^%^MAGENTA%^st%^BOLD%^%^BLACK%^in%^BOLD%^%^WHITE%^ge%^RESET%^r");
   set_long("The long, pointed stinger drips with poison at the point. This "
     "looks like a huge wasp stinger. Though it can not slash, it can stab, so "
     "the giant wasp stringer could be used as a knife.");
   set_weight(9);
   set_id(({ "poisonous stinger", "stinger" }));
   set_wc(6);
   set_type("knife");
   set_value(185);
   set("skill level", 35);
}

int query_auto_load() {
   if (this_player()->query_level() >= 22) return 0;
}

int weapon_hit() {
   int result;
   object atk, ob, env, tp;

   ob  = environment(this_object());
   env = environment(ob);
   atk = (object)this_player()->query_current_attacker();
   tp  = this_player();

   if(random(1000) >= 200) return 0;

   write("%^RESET%^%^MAGENTA%^You %^BOLD%^%^WHITE%^stab %^RESET%^%^MAGENTA%^the "
     "%^BOLD%^%^WHITE%^stinger %^RESET%^%^MAGENTA%^into "
     "%^BOLD%^%^WHITE%^"+atk->query_cap_name()+" %^RESET%^%^MAGENTA%^and%^BOLD%^%^WHITE%^ "
     "poison %^RESET%^%^MAGENTA%^drips %^BOLD%^%^WHITE%^into "
     "%^RESET%^%^MAGENTA%^"+atk->query_possessive()+" %^BOLD%^%^WHITE%^open "
     "%^RESET%^%^MAGENTA%^wound.");
   tell_room(env, "%^RESET%^%^MAGENTA%^"+tp->query_cap_name()+
     "%^BOLD%^%^WHITE%^stabs %^RESET%^%^MAGENTA%^"+tp->query_possessive()+
     "%^BOLD%^%^WHITE%^poisonous %^RESET%^%^MAGENTA%^stinger %^BOLD%^%^WHITE%^"
     "into %^RESET%^%^MAGENTA%^"+atk->query_cap_name()+" %^BOLD%^%^WHITE%^and "
     "%^RESET%^%^MAGENTA%^poison%^BOLD%^%^WHITE%^ drips %^RESET%^%^MAGENTA%^into "
     "%^BOLD%^%^WHITE%^"+atk->query_possissive()+" %^RESET%^%^MAGENTA%^open "
     "%^BOLD%^%^WHITE%^wound.", ({ atk, tp }));
   atk->add_poisoning(random(15)+13);
   return random(15);
}
