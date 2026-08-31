#include <std.h>

inherit ROOM;

void create() {
::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 1, "no
attack" : 0,
"no bump" : 0]) );
    set_short("Contagion Ward");
    set_day_long( "Contagion Ward\n"
"This is the worst place yet.  This is a hopital ward where beings "
"go to die.  There are all types of diseases and plagues to be found. "
"It's an assassin, coming out from behind to strike the unwary down. "
"The clerics shake their heads and weep real tears and try their best to "
"heal the unfortunate souls.  Here and there there is a child crying in "
"pain and some of them are starving to death with food right in front of "
"them because they're too sick to eat. Perhaps, if they had gone up, they "
"would have had more pleasant dreams.");
    set_night_long ("Contagion Ward\n"
"Night on the ward is a ghostly presence. Each bed contains someone who "
"hasn't the strength even to moan, though down the hall there are a few "
"who can.  As the clerics pass by, they cast the only magic that still "
"works, a sleep spell.  This gives the sufferers relief from the pain "
"for a few hours." ); 
set_items (([ "room" : "This room is dedicated to disease." , 
        "bodies" : "All of these people were once happy, healthy people." ]));
set_listen("default", "Low moans of pain are all that can be heard.");
set_smell("default", "The smell of vomitous and blood are mingling with "
        "that of an astringent.");

set_heart_beat(1);
}

void heart_beat() {
object *op;
int i;
op = all_inventory(this_object());
i = sizeof(op);
while(i--) {
if(op[i]->is_player())
op[i]->add_hp(-2);
}

}

//void reset() {
//  ::reset();
//if (!present("plague", this_object()))
//new (MOBS"plague")->move (this_object());
//}

