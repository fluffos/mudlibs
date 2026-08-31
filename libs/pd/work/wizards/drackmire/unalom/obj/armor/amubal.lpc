#include <std.h>                                                               


inherit ARMOUR;                                                                


int query_auto_load();
int do_heart_beat();
int undo_heart_beat();

void create() 
{ 
    ::create();  
    set_name("amulet of balance");
    set_id( ({ "amulet", "balance amulet", "amulet balance" })
    );
    set_short("%^BOLD%^WHITE%^am%^BLACK%^u%^WHITE%^l%^BLACK%^et%^WHITE%^ of "
      "%^YELLOW%^b%^WHITE%^al%^RESET%^YELLOW%^a%^BOLD%^n%^WHITE%^ce%^RESET%^");
    set_long("A shimmering amulet, made from an iridescent green metal. "
      "It feels warm when held in one hand, but cold when held in the other. "
    );
    set_ac(1);
    set_curr_value("gold", 2180);
    set_limbs( ({ "torso" }) );
    set_weight(3);
    set_type("necklace");
    set_wear((: do_heart_beat :));
    set_remove((: undo_heart_beat :));

}

int query_auto_load() { 
    return 1; 
}

int do_heart_beat(){
    set_heart_beat(1);
    return 1;
}

int undo_heart_beat(){
    set_heart_beat(0);
    return 1;
}

void heart_beat(){
    object me, them;
	if(random(2)) return;
    if (!this_object()) return;
    if (!this_object()->query_worn()) return;
    me = this_object()->query_worn();
	if(!me->query_current_attacker()) return;
    if(this_object()->query_worn()->query_current_attacker()){
       them = this_object()->query_worn()->query_current_attacker();
       me->add_mp(them->query_level()-me->query_level());
    }
}


