#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "sophia");
    set("short", "A Redcap");

    set( "long", wrap(
	"Just a wiry old elf named Marmaduke, If you kill him you might "+
	"be able to steal one of the tickets he holds. "
      ) );

    set("id", ({"marmaduke", "monster", "redcap" }) );

    set_size(6);

    set_name("marmaduke") ;

    set("gender", "male");

    set("race", "elf");

    set("undead", 0);

    set("damage", ({1,4 }) );

    set("weapon_name", "fists") ;

    set_verbs( ({ "attack", "punch", "swing at" }) );

    set_verbs2( ({ "punches at", "swings at", "attacks" }) );

    set("natt", 1);

    set ("chat_chance", 3);

    set ("chat_output", ({
      "Tickets sir? Can i help you with your bags?\n",
    }) );


    set_level(20);

}
