
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "ursula the evil octupus");
    set("prevent_summon" , 1);
    set ("long", @EndText
Ursula is ugly! She has 8 massive tentacles, all swaying
around her. Her face looks almost human, expressions
and all.
EndText
    );
    set("id" , ({"ursula" , "octopus" , "ursula the octopus"}) );
    set("attrib1" , "ugly");
    set_size(13);
    set_name("ursula");
    set("gender" , "femail");
    set("race" , "fish");
    set("damage" , ({4,10}) );
    set("damage_type" , "crushing");
    set("weapon_name" , "tenticles");
    set_verbs( ({"tangle" , "squeeze" , "wrap" , "entwine"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
      "Ursula moves closer to you. \n",
      "Ursula tries to give you a hug! \n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(24);
}
