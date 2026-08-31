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
    set("short", "Cyans Bedroom");
    set("long", "%^BOLD%^%^WHITE%^One look into this room, and it is obvious that a man lives here. There are two main focuses in this room, the left side and the right side. On the left side, there is simply a bed, a %^BLACK%^leather chair %^WHITE%^and a %^RESET%^%^RED%^fireplace%^BOLD%^%^WHITE%^. On the right side there is a large bookshelf and a %^BLACK%^gigantic weapons rack%^WHITE%^. The big ass %^CYAN%^window %^WHITE%^in between the two sides ties it all together. %^RESET%^");
    set_items( ([ "bed": "%^BOLD%^%^WHITE%^This is a place for Cyan to rest his head.%^RESET%^", "chair": "%^BOLD%^%^BLACK%^This black leather chair is in the perfect spot, you can either watch the sky or the fireplace.%^RESET%^", "fireplace": "%^RESET%^%^RED%^Made of red bricks, the fireplace is %^BOLD%^%^RED%^ROARING%^RESET%^%^RED%^ with flames.%^RESET%^", "bookshelf" : "%^BOLD%^%^WHITE%^In his free time, Cyan likes to read to become one of the smartest %^YELLOW%^Angels %^WHITE%^ in the realm.  He has quite a collection.%^RESET%^", "rack" : "%^BOLD%^%^BLACK%^Cyan, althought a great %^YELLOW%^Angel%^BLACK%^, is a fierce fighter.  He keeps all his weapons inside his weapons rack until he needs them.%^RESET%^", "window" : "%^BOLD%^%^CYAN%^This big ass window is set directly in the middle of the side walls, it reaches from one end to the other and provides a FANTASTIC view." ]) );
    set_exits( ([ "east" : GUILDROOM+"bedroom_main" ]) );
}
