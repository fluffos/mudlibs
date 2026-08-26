
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "spooner");
    set("short", "concerned father");
    set ("long", @EndText
This man appears to be the proud Father of a very beautiful daughter.  He seems to be kind of edgy about something.  He is watching your every move!!!
EndText
    );  
    set("id", ({ "human", "father" }) );
    set_size(6);
    set_name("concerned father");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 1,5 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 2);
    set ("chat_chance", 3);
    set ("chat_output", ({
      "The man looks at you very intensly!!\n",
      "The man seems to start to pull SOMETHING from his coat but STOPS!!\n",
      "The man sits back down!\n",
    }) );
    set ("att_chat_output", ({
      "The man stares at you!!\n",
    }) );

    set ("base_stat",([
      "strength" : 18,
      "constitution" : 20,
      "dexterity" : 12 ]) );


    set_level(10);
}
