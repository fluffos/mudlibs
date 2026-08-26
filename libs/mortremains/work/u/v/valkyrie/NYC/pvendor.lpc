#include <mudlib.h>
    
inherit MONSTER ;
                
void create () {
    ::create();       
    seteuid(getuid()); 
    enable_commands() ;
    set("author", "valkyrie");
    set("short", "a pretzel vendor");
    set ("long", @EndText
The pretzel vendor is bundled up in lots of clothing, you can barely see
his eyes poking out from between the layers. He is posessively guarding 
his pretzel cart and glaring at people when they're not looking.
EndText
);
    set("id", ({ "vendor", "guy", "pretzel vendor", "pretzel guy" }) );
    set_size(6);
    set_name("vendor") ;
    credit(150+random(200));
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 1,10 }) );
    set("weapon_name", "stale pretzel") ;
    set_verbs( ({ "attack", "beat", "swing at" }) ) ;
    set("natt", 2);
    set ("chat_chance", 3);
    set ("chat_output", ({
      "The pretzel guy says : Hey, hows about a hot pretzel?.\n",
      "The pretzel guy slouches, drinking his coffee.\n",
    }) );
    set ("att_chat_output", ({
      "You filthy bastard!\n",
    }) );

    set_level(5);
}
