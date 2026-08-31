#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
set_short("%^RED%^D%^ORANGE%^r%^RED%^a%^ORANGE%^g%^RED%^o%^ORANGE%^"
          "n%^RED%^S%^ORANGE%^c%^RED%^a%^ORANGE%^l%^RED%^e %^ORANGE%^"
          "A%^RED%^r%^ORANGE%^m%^RED%^o%^ORANGE%^u%^RED%^r%^RESET%^");
    set_long("This Armour was made from the giant fire dragon "
             "that took over the Drow island. After the drows "
             "defeated it they used its scales for armour"); 
    set_id( ({ "armour" , "dragon scale armour" }) );
    set_ac(11);
    set_mass(65);
    set_wear("%^ORANGE%^The Scales wrap around your body and you feel "
             "protected.");
    set_remove("%^RED%^You feel less protected.");
    set_curr_value("gold", 200);
    set_type("armour");
    set_limbs( ({ "torso","head","right arm","left arm"}) );
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() < 50) return 0;
 return 1;
}
