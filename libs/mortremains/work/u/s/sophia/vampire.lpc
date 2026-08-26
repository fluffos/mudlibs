#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "sophia");
    set("short", "vampire");

    set( "long", wrap(
	"Hypnotic eyes make you hesitate and with the "+
	"brain cells that are still working you think this might be a fatal "+
	"mistake. "
      ) );

    set("id", ({"vampire", "monster", "vlad" }) );
    set_size(8);

    set_name("vlad");

    set("gender", "male");

    set("race", "human");

    set("undead", 1);

    set("damage", ({1,4 }) );

    set("weapon_name", "fists") ;

    set_verbs( ({"attack", "slice", "swing at" }) );

    set_verbs2( ({ "punches at", "swings at", "attacks" }) );

    set("natt", 1);

    set_level(40);

    arm("/doc/examples/knife") ;
}
