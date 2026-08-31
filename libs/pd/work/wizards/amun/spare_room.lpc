#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Amun Bedroom");
    set("long", "%^BOLD%^%^WHITE%^This room was made in secret by Amun. Only certain people are allowed to venture into this area. The entire room is made up of doors, each one leading to a different area. The doors are marked with the areas they lead to.%^RESET%^");
    set_items((["doors" : "%^BOLD%^%^WHITE%^The entire room is made up of doors, each one leading to a different area. The doors are marked with the areas they lead to.%^RESET%^" ]));
    set_exits( ([ "marsh" : MARSHROOM "marsh_square", "tomb" : ROOMS "hamen_square", "sky" : SKYROOM "square", "out" : "/wizards/amun/bedroom" ]) );
}
