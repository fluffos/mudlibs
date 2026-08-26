// Fallow Field

#include <std.h>
#include "../serakii.h"

inherit CROOM;
void pick_critters();


string seas;

void create() {
    pick_critters();
    set_repop(30);
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("no teleport",1);
    set_property("indoors",0);
    set_name("fallow fields");
    set_short("%^C221%^f%^C247%^a%^C221%^ll%^C143%^o%^C221%^w f%^C247%^i%^C142%^e%^C221%^l%^C247%^d%^C221%^s%^CRST%^");
    seas = season(time());
        set_long("blah");
        switch(seas){
        case "summer": 
            set_long("%^C168%^These %^C222%^fields%^C168%^ at one point were planted with %^C220%^corn%^C168%^ however it looks like for several seasons the fields have %^C249%^lay fallow%^C168%^. %^C094%^Mud%^C168%^ has churned up the %^C095%^soil%^C168%^ and the remains of %^C220%^corn cobs%^C168%^ and %^C220%^stalks%^C168%^ are everywhere. In the %^C125%^heat%^C168%^ of the season everything has %^C058%^dried%^C168%^ to a %^C058%^crisp%^C168%^. To the east you can see a %^C029%^forest%^C168%^ shrouded in %^C249%^fog%^C168%^ and a %^C246%^giant boulder%^C168%^. Far to the north you can see %^C251%^three fortresses%^C168%^.%^CRST%^\n");
            set_smell("default","%^C060%^You smell %^C095%^mud%^C060%^ and %^C228%^straw%^CRST%^");
            set_listen("default","%^C140%^You hear strange sounds coming from the %^C028%^forest%^C140%^ to the east%^CRST%^");
        break;

        case "spring": 
            set_long("%^C028%^These %^C220%^fields%^C028%^ at one point were planted with %^C220%^corn%^C028%^ however it looks like for several seasons the fields have %^C248%^lay fallow%^C028%^. %^C095%^Mud%^C028%^ has churned up the %^C094%^soil%^C028%^ and the remains of %^C220%^corn cobs%^C028%^ and %^C220%^stalks%^C028%^ are everywhere. With recent %^C063%^rains%^C028%^ everything is %^C058%^mucky%^C028%^ and the %^C095%^mud%^C028%^ is deep. To the east you can see a %^C022%^forest%^C028%^ shrouded in fog and a %^C248%^giant boulder%^C028%^. Far to the north you can see %^C250%^three fortresses%^C028%^.%^CRST%^\n");
            set_smell("default","%^C060%^You smell %^C095%^mud%^C060%^ and %^C228%^straw%^CRST%^");
            set_listen("default","%^C140%^You hear strange sounds coming from the %^C028%^forest%^C140%^ to the east%^CRST%^");
        break;

        case "winter":
            set_long("%^C249%^These fields at one point were planted with %^C220%^corn%^C249%^ however it looks like for several seasons the %^C220%^fields%^C249%^ have lay %^C244%^fallow%^C249%^. The whole %^C220%^field%^C249%^ is covered in a %^C253%^thin coating%^C249%^ of %^C231%^snow%^C249%^ and the %^C229%^corn stalks%^C249%^ are %^C045%^fr%^C253%^o%^C045%^zen sol%^C253%^i%^C045%^d%^C249%^. To the east you can see a forest shrouded in %^C244%^fog%^C249%^ and a %^C244%^giant boulder%^C249%^. Far to the north you can see %^C241%^three fortresses%^C249%^.%^CRST%^\n");
            set_smell("default","%^C060%^You smell nothing but %^C231%^snow%^C060%^ and %^C038%^ice%^CRST%^");
            set_listen("default","%^C142%^You hear little over the %^C231%^fi%^C110%^e%^C231%^rce wi%^C110%^n%^C231%^d%^C142%^!%^CRST%^");
        break;

        case "autumn":
            set_long("%^C131%^These %^C220%^fields%^C131%^ at one point were planted with %^C220%^corn%^C131%^ however it looks like for several seasons the fields have %^C248%^lay fallow%^C131%^. While the %^C220%^fields%^C131%^ haven't been planted properly, %^C220%^corn%^C131%^ still grows at wild angles and %^C088%^fallen leaves%^C131%^ line everywhere. To the east you can see a %^C029%^forest%^C131%^ shrouded in %^C247%^fog%^C131%^ and a %^C248%^giant boulder%^C131%^. Far to the north you can see %^C248%^three fortresses%^C131%^. %^CRST%^\n");
            set_smell("default","%^C060%^You smell %^C095%^mud%^C060%^ and %^C228%^straw%^CRST%^.");
            set_listen("default","%^C140%^You hear strange sounds coming from the %^C028%^forest%^C140%^ to the east%^CRST%^");
        break;
    }   

}

void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters(
({MOBS"farmer",MOBS"rat"}),({random(4),random(8)}) );
                   break;
         case 1:   set_monsters(
({MOBS"farmer"}),({random(5)}) );
                   break;
         case 2:   set_monsters(
({MOBS"farmer",MOBS"rat"}),({1,random(6)+2}) );
                   break;
         case 3:   set_monsters(
({MOBS"farmer"}),({random(5)}) );
                   break;
         case 4..5: break;
   }
}
