#include <mudlib.h>   
    
inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Worm");
    set ("long", @EndText
This worm has a long slimy body which it commonly uses as a whip to
damage it's opponent.
EndText
);  
    set("id", ({ "monster", "worm" }) );
    set_size(6);
    set_name("worm") ;
    set("gender", "male");
    set("race", "worm");
    set("undead", 0);
    set("damage", ({ 6,11 }) );
    set("weapon_name", "body") ;
    set_verbs( ({ "whip" }) ) ;
    set("natt", 2);
    set_level(2);
    set("prevent_summon", 1);
    set("chat_chance",4);
    set ("chat_output", ({
      "The worm wriggles about.\n",
      "The worm starts digging a new tunnel.\n",
    }) );
    
}   
