inherit "/obj/monster";

#include "path.h"

void setup()
{
    set_name("shaman");
    set_short("Tribe Shaman");
    set_long("The most important member of the Tribe of the %^YELLOW%^Sunshine%^RESET%^"
             ".  He heals and gives advices to the members of his tribe.\n");
             
    set_main_plural("Tribe Shamans");
    add_plural("shamans");

    set_level(7);
    set_race("human");
    set_guild("cleric");

    set_con(20);
    set_dex(23);
    set_str(11);
    
    set_gender(1+random(1));

    adjust_money(2,"silver coins");
    

    load_chat(40, ({
      1,"@prepares a new magical potion\n",
      1,"@prepares a new spell\n",
      1,"'Iohoi baclam bertu",
      1,"'bertanyo calema HOCHIN la ?",
    }));

    load_a_chat(70,({
      1,"@exclaims: Valtroy lackun hazzadd !!",
      1,"@yells: huqim lerala puchnem lackun !!!",
      1,"@makes an obscene gesture so explicit even you can understand it",
    }));

}
