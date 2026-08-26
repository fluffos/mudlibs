#include <std.h>

inherit WEAPONLESS;

object puppet;

void create(){
   ::create();

   set_name("doppleganger");
   set_short("A doppleganger");
   set_id(({"puppet", "doppleganger" }));
   set_long("");
   set_hd(60,6);
   set_level(60);
   set_mlevel("fighter", 60);
   set_hp(3500);
   set_gender("none");
   set_race("shadow");
   add_limb("whiplike whorl","",0,0,0);
   add_limb("shadow tendril","",0,0,0);
   set_attacks_num(3);
   set_property("damage resistance", 20);
   set_property("spell damage resistance", 20);
   set_property("void resistance percent", 50);
   set_property("radiant resistance percent", -50);
   set_monster_feats( ({ "resistance", "evasion", "stalwart", "death ward", "bravery" }) );
   set_overall_ac(-70);
}

object set_puppet(object ob) { puppet = ob; return ob; }
object query_puppet() { return puppet; }
    
void die()
{
    if(objectp(puppet))
        puppet->move_player(environment(this_object()));
    
    tell_room(environment(this_object()), "%^BOLD%^\n" + puppet->query_cap_name() + " shakes + " + puppet->query_possessive() + " head and seems to be themselves once more!\n", puppet);
    tell_object(puppet, "%^YELLOW%^You shake your head and feel like yourself once more!%^RESET%^");
    puppet->remove_paralyzed();
    
    ::die();
}
