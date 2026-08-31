#include <std.h>
#define WHT "%^BOLD%^%^WHITE%^"
#define YEL "%^YELLOW%^"
inherit ROOM;
object ob;
void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Chamber of %^BOLD%^%^YELLOW%^light%^RESET%^");
   set_long("%^BOLD%^%^YELLOW%^Light%^BOLD%^%^WHITE%^ fills this main chamber of the %^BOLD%^%^YELLOW%^angelic temple%^BOLD%^%^WHITE%^. Tall "
"doorways have been carved in the marble walls east and west. "
"The ground is made %^BOLD%^%^YELLOW%^completely of gold%^BOLD%^%^WHITE%^ with a platinum emblem "
"in the center of the room, about six feet in diameter. The "
"ceiling stretches so high up, the top cannot be seen. Long "
"and narrow %^RESET%^%^ORANGE%^sta%^RED%^ine%^GREEN%^d gl%^BLUE%^ass%^GREEN%^ wi%^RED%^nd%^ORANGE%^ows%^BOLD%^%^WHITE%^ depict %^BOLD%^%^YELLOW%^saints%^BOLD%^%^WHITE%^, %^BOLD%^%^YELLOW%^angels%^BOLD%^%^WHITE%^, "
"and other %^BOLD%^%^YELLOW%^divine figures%^BOLD%^%^WHITE%^ and %^BOLD%^%^YELLOW%^scenes%^BOLD%^%^WHITE%^. Outside through "
"the windows, clouds and sky can be seen.");
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
   set_smell("default", "The sweet scent of incense fills the temple.");
   set_smell("incense", "A sweet aroma, pleasing to the senses.");
   set_listen("default","Praying and chanting can be heard.");
   set_items(([
     "windows" : "The outside clouds can be seen through the stained glass "
                 "windows.",
     "outside" : "It appears that this temple is thousands of feet in the sky.",
     "doorways": "Both doorways have been expertly carved. There is an
inscription "
                 "above each doorway. The western doorway "
                 "reads, 'Shiir att sol annari' and the eastern, 'Annar "
                 "Tilin'.",
     "clouds"  : "The temple rests atop puffy white clouds.",
     "ceiling" : "It cannot be seen.",
     "emblem"  : "An emblem made out of platinum represents faith in good.",
     "sky"     : "Beautiful, blue sky stretches as far as the eye can see.",
     "marble"  : "A pure white marble makes up most of the temple.",
   ]));
   set_exits(([
     "west" : "/wizards/inferno/angel/west",
     "out"  : "/d/nopk/tirun/square",
     "east" : "/wizards/inferno/angel/east"
   ]));
    ob = new(BBOARD);
    ob->set_name("angel");
    ob->set_location("/wizards/inferno/angel/main");
    ob->set_id( ({ "board", "spell", "spell board" }) );
    ob->set_board_id("angel_room");
    ob->set_edit_ok( ({ "nulvect" }) );
    ob->set_max_posts(200);
    ob->set_short("Angel Board");
    ob->set_long("The Angel Board.");
}
