#include <mudlib.h>
inherit MONSTER ;

void create () {


    ::create() ;
    seteuid(getuid()) ;

set_level(4);
set("short", "Servant");
set("long", @BooBoo
This is one of the servants who work at the castle,
he is apparantly busy doing other things and cannot
be bothered by the likes of you.
BooBoo
);
set("id", ({"servant"}));
set_size(6);
    set ("mass", 2);
set_name("Castle Servant");
    enable_commands() ;
set_living_name("servant");
    set("natt", 1);
set ("damage" , ({3, 5}));
    set ("armor_class", 12);
set ("weapon_name", "fists");
   set_verbs(({"trie to punch at", "punche at", "punche", "attack"}));
set("wealth", (15)+random(25));
}


