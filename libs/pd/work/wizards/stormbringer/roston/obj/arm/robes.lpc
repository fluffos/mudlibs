#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("tattered robes");
    set_short("Tattered Robes");
    set_long("These robes are made of a tattered old silk. Maybe you should examine them closer.");
    set_id( ({ "robes" , "tattered robes" , "roston deed" }) );
    set_ac(1);
    set_mass(20);
    set_curr_value("gold", 10);
    set_type("robes");
    set_limbs( ({ "torso","head" }) );
}

int query_auto_load(){ return 1; }

void init() {
 ::init();
 add_action("cmd_exam", "examine");
}

int cmd_exam(string str) {
    if (!str || str=="") return notify_fail("Examine what?\n");
    if (str!="robes") return notify_fail("Perhaps try examining the robes.\n");
    write( @EndText
You have found a map drawn on one of the flaps.

             Roston Layout
             
                   O        
                   |        
                   O-O-O-O  
                   |     |  
                   O     O  
                   |     |  
             S-S-O-O   T-T-T
             | |   |   | | |
             S-S   O   T-T-T
                   |        
                 O-O        
                   |        
             W-O-O-#-O-O-O-C
                   |        
                   O        
                   |        
                 A-O-O-I    
                   |        
                   E
EndText );
return 1;
}