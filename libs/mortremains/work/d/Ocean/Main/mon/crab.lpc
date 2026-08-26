
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a crab");
    set("prevent_summon" , 1);
    set ("long", @EndText
This is a small, red crab. It looks angry that you disturbed it.
EndText
    );
    set("id" , ({"crab"}) );
    set("stat/constitution", 12);
    set_size(1);
    set("wealth" , 200);
    set_name("crab");
    set("gender", "neuter");
    set("race" , "shellfish");
    set("damage" , ({1, 2}) );
    set("weapon_name", "claws") ;
    set_verbs( ({"claw at" , "swipe at" , "pinch"}) );
    set_verbs2( ({"claws at" , "swipes at" , "pinches"}) );
    set("chat_chance" , 6);
    set ("chat_output", ({
      "The crab shuffles about in the sand a bit. \n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(11);
}
