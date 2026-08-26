// Childs Toy

#include <std.h>
inherit OBJECT;

object ob;
int i;
string material;

void create(){
    ::create();
    set_name("childs toy");
    set_id(({"childs toy","toy","child's toy"}));
    set_short("childs toy");
    set_long("childs toy\n");
    set_weight(1);
    set_value(1);

    i = random(3);
        switch(i){
        case 0: material = "%^C138%^cloth%^CRST%^";
                break;
        case 1: material = "%^C094%^wooden%^CRST%^";
                break;
        case 2: material = "%^C245%^tin%^CRST%^";
        }

    i = random(3);
    switch(i){
        case 0:    // broken

            set_value(100);
            set_short("%^C109%^broken %^CRST%^"+material+" %^C059%^child's toy%^CRST%^");
            set_long("%^C072%^This child's toy, made from%^CRST%^ "+material+" %^C072%^has been broken beyond most recognition. The%^CRST%^ "+material+" %^C072%^has been %^C124%^torn %^C072%^by some force and the whole toy is quite sad looking. No %^C174%^normal child%^C072%^ would want to play with it now. There might be some value in it, though most likely to a very %^C244%^morbid %^C072%^collector.%^CRST%^\n");
            break;

        case 1:    // bloody

            set_value(100);
            set_short("%^C001%^bloody %^CRST%^"+material+" %^C060%^child's toy%^CRST%^");
            set_long("This child's toy, made from "+material+" has been soaked with blood. The "+material+" has spent extended time in a pool of blood and it has been stained thoroughly with it. Even having it near you, you can almost taste the copper of it. No normal child would want to play with it now. There might be some value in it, though most likely to a very morbid collector.\n");
            break;

        case 2:       // scorched

            set_value(100);
            set_short("%^C246%^scorched %^CRST%^"+material+" %^C059%^child's toy%^CRST%^");
            set_long("%^C245%^This child's toy, made from %^CRST%^"+material+"%^C245%^ has been %^C088%^burned %^C245%^and %^C124%^scorched %^C245%^by intense flame. The %^CRST%^"+material+" %^C245%^is %^C241%^black %^C245%^and falling apart from the extensive %^C124%^fire damage%^C245%^. Even turning it over in your hands, %^C250%^ash %^C245%^falls from it and you feel like it might turn to %^C249%^dust %^C245%^in front of you. No %^C172%^normal child%^C245%^ would want to play with it now. There might be some value in it, though most likely to a very %^C241%^morbid %^C245%^collector.%^CRST%^\n");

            break;

        }
}
