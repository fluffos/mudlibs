#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","%^RESET%^The path branches off towards the north and south to the shops. Although this area is not as beautiful as others it still has its charm. Along the path there is a family of %^ORANGE%^chipmunks %^RESET%^eating peacefully. On the other side of the path, a group of %^MAGENTA%^b%^BOLD%^%^MAGENTA%^u%^RESET%^%^BLUE%^t%^BOLD%^%^BLUE%^t%^GREEN%^e%^RESET%^%^RED%^r%^ORANGE%^f%^BOLD%^%^WHITE%^l%^RED%^i%^CYAN%^e%^YELLOW%^s %^RESET%^can be seen flying throughout the small patch of %^BOLD%^%^YELLOW%^f%^WHITE%^l%^MAGENTA%^%^o%^WHITE%^w%^CYAN%^e%^WHITE%^r%^RED%^s%^RESET%^.");
    set_items(([ "path" : "Although it's not as beautiful as others, this path has it's charms.", "chipmunks" : "%^ORANGE%^The chipmunks are feasting on acorns they found.%^RESET%^", "butterflies" : "%^BOLD%^%^YELLOW%^The %^MAGENTA%^b%^BOLD%^%^MAGENTA%^u%^RESET%^%^BLUE%^t%^BOLD%^%^BLUE%^t%^GREEN%^e%^RESET%^%^RED%^r%^ORANGE%^f%^BOLD%^%^WHITE%^l%^RED%^i%^CYAN%^e%^YELLOW%^s flutter in and out of the patch of %^YELLOW%^f%^WHITE%^l%^MAGENTA%^%^o%^WHITE%^w%^CYAN%^e%^WHITE%^r%^RED%^s.", "flowers" : "%^BOLD%^%^MAGENTA%^The flowers have %^YELLOW%^begun to bloom %^RED%^beautifully throughout the %^CYAN%^area." ]));
    set_exits( ([ "east" : GROOM "r_main3", "west" : GROOM"r_main", "enter weapon shop" : GROOM"shop3", "enter armoury" : GROOM"shop4" ]) );
    add_exit_alias("enter weapon shop", "shop");
    add_exit_alias("enter armoury", "armoury");
}
