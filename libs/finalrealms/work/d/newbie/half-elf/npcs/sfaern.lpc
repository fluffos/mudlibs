//modified by Ljen okt -96
//By Joram on the 13th of Sept. '96
inherit "/obj/monster";

void setup()
{
    set_name("sfaern");
    set_short("Sfaern, The Smithy Worker");
    set_long("This is the member of the tribe in charge of the smithy.  He has "
             "to take care of the forge, and to keep it in order.  "
             "All he knows, the people of the castle has teached him, "
	     "taking him under their protection.\n");
             
    set_main_plural("Sfaerns");

    set_level(9);
    set_race("half-elf");
    
    set_gender(1);
    add_property("SFAERN",1);

    adjust_money(2,"silver coins");
    
    load_chat(40, ({
      1,"@cleans the counter",
      1,"'Want something ?",
      1,"'Can I help you with anything ?",
    }));

    load_a_chat(70,({
      1,"@exclaims: my friends will help me !!",
      1,"@yells: inklater opere !!!",
      1,"@makes an obscene gesture so explicit even you can understand it",
    }));

}
