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
    set("short", "Amun Gazebo");
    set("long", "%^BOLD%^%^WHITE%^This Gazebo, which has two separate %^RESET%^%^ORANGE%^b%^RED%^r%^ORANGE%^idges %^BOLD%^%^WHITE%^attached to it, is suspended in the %^CYAN%^air %^WHITE%^and has flowing l%^RESET%^a%^BOLD%^%^WHITE%^c%^RESET%^e %^BOLD%^%^WHITE%^coverings and %^MAGENTA%^p%^CYAN%^i%^MAGENTA%^l%^CYAN%^l%^MAGENTA%^o%^CYAN%^w%^MAGENTA%^s %^WHITE%^layed in a circle in the middle of the floor.  Candles are placed on each pillar and the top is domed into a large opening allowing the %^RESET%^%^BLUE%^sky %^BOLD%^%^WHITE%^to peek through.%^RESET%^");
    set_items((["sky" : "%^BOLD%^%^WHITE%^The %^YELLOW%^moon %^WHITE%^and st%^YELLOW%^a%^WHITE%^rs are the only %^YELLOW%^light %^WHITE%^the %^BLACK%^da%^RESET%^%^BLUE%^rk%^BOLD%^%^BLACK%^ene%^RESET%^%^BLUE%^d s%^BOLD%^%^BLACK%^ky %^BOLD%^%^WHITE%^sees.  Even when it is %^YELLOW%^day%^WHITE%^li%^YELLOW%^ght %^WHITE%^in the mortal realm, it is always %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^here; as the owner^Rs of this house love the %^BLACK%^n%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t %^WHITE%^life.%^RESET%^", "candles" : "%^BOLD%^%^WHITE%^White and lit, the candles are floating by magic every 10 steps you take.  No wax is falling, showing you these candles are everlasting.%^RESET%^", "pillows" : "%^BOLD%^%^WHITE%^These pillows are laid in a circle in the middle of the floor. The are beautifully %^MAGENTA%^mu%^RESET%^%^MAGENTA%^lt%^BOLD%^%^YELLOW%^i-%^GREEN%^co%^BLUE%^lo%^RED%^re%^CYAN%^d %^WHITE%^and comfortable." ]));
    set_exits( ([ "west" : "/wizards/amun/bedroom" ]) );
}
void reset() {
    ::reset();
    if(!present("portal"))
	new("/wizards/amun/portal")->move(this_object());
}
