#include <std.h>                                                             



inherit ARMOUR;                                                              



int query_auto_load();
int do_heart_beat();
int undo_heart_beat();

void create() 
{ 
    ::create();  
    set_name("ring of free movement");
    set_id( ({ "ring", "ring of movement" })
    );
    set_short("ring of %^GREEN%^fr%^BOLD%^WHITE%^e%^RESET%^CYAN%^e mo%^GREEN%^ve%^BOLD%^WHITE%^men%^CYAN%^t%^RESET%^");
    set_long("A small brass ring in the shape of the Ouroboros. "
    "The eyes of the serpent are decorated with brightly glowing "
    "%^RED%^BOLD%^rubies%^RESET%^ while random scales seem to be made "
    "out of %^GREEN%^jade%^RESET%^ and %^BLUE%^sapphire%^RESET%^. "
    "The ring is warm and slippery to the touch."
    );
    set_ac(1);
    set_curr_value("gold", 3450);
    set_limbs( ({ "left hand", "right hand", "first hand", "second hand" }) );
    set_weight(3);
    set_type("ring");
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
    if(me->query_paralyzed()) {
          me->set_paralyzed(0);
          me->set_disable();
          tell_object(me, "%^YELLOW%^BOLD%^The ring glows brightly, freeing you from your paralysis!%^RESET%^");
    }
}
