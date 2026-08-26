#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "valkyrie");
    set("short", "The Monster Under The Bed");
    set ("long", @EndText
The monster is a big fuzzy blue-green, bipedal monster. He has big eyes
and large teeth which show when he grins his wide smile at you. You may
wonder why it's not under the bed where it belongs, then you realize that
Val doesn't have a bed in here. The monster sits in an armchair in her
workroom, drinking coffee and reading.
EndText
);
    set("id", ({ "monster", "monster under the bed" }) );
    set_size(8);
    set_name("monster") ;
    set("gender","male");
    set("race", "monster");
    set("undead", 0);  
set_level(1);
    set("chat_chance",2);
    set ("chat_output", ({
      "The monster relaxes in an armchair, sipping his coffee.\n",
      "The monster turns a page in his book, reading quietly.\n",
      "The monster smiles and gives you a wave.\n",
    }) );

}
