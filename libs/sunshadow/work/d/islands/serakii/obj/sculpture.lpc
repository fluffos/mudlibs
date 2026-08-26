// sculpture

#include <std.h>
inherit OBJECT;

object ob;
int i;
string material;

void create(){
    ::create();
    set_name("oil sculpture");
    set_id(({"oil sculpture","sculpture"}));
    set_short("oil sculpture");
    set_long("oil sculpture\n");
    set_weight(10);
    set_value(1);

    i = random(4);
        switch(i){
        case 0..1: material = "%^C145%^ivory%^CRST%^";
                break;
        case 2: material = "%^C022%^jade%^CRST%^";
                break;
        case 3: material = "%^C231%^silver%^CRST%^";
        }

    i = random(7);
    switch(i){
        case 0..2:    // ruined

            set_value(100);
            set_short("%^C059%^ruined %^CRST%^"+material+" %^C060%^sculpture%^CRST%^");
            set_long("%^C059%^This small %^C060%^sculpture %^C059%^made from %^CRST%^"+material+"%^C059%^ has been absolutely wrecked by its time in the %^C241%^ruins%^C059%^. You can barely tell what it was supposed to be in the first place. If there is any %^C028%^value %^C059%^in this it is for the raw materials alone.%^CRST%^\n");
            break;

        case 3..5:    // damaged

            set_value(5000);
            set_short("%^C058%^damaged %^CRST%^"+material+" %^C060%^sculpture%^CRST%^");
            set_long("%^C116%^This small %^C060%^sculpture %^C116%^made from%^CRST%^ "+material+" %^C116%^has been damaged by its time in the %^C241%^ruins%^C116%^. The%^CRST%^ "+material+" %^C116%^has small %^C246%^nicks %^C116%^and %^C246%^scratches %^C116%^that would lower its value with art dealers but not enough to eliminate all buyers. Overall it has survived quite well for the time it was %^C246%^buried%^C116%^.%^CRST%^\n");
            break;

        case 6:       // perfect

            set_value(50000);
            set_short("%^C158%^perfect%^CRST%^ "+material+" %^C060%^sculpture%^CRST%^");
            set_long("%^C218%^This small %^C060%^sculpture %^C218%^made from %^CRST%^"+material+"%^C218%^ has survived in %^C254%^pristine %^C218%^condition. The %^CRST%^"+material+"%^C218%^ is %^C251%^clean %^C218%^and %^C229%^gleaming %^C218%^as the day the artist carved it. With its age and condition you are sure you could make quite the sum selling this art.%^CRST%^\n");
            break;

        }
}
