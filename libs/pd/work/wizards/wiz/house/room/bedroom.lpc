#include <wiz.h>
inherit ROOM;

void create() {
room::create();
   set_properties(([ "light":2, "night light":2,  "no steal":1,
                     "no bump":1, "no magic":1, "no castle":1, "no attack":1 ]));
    set_short("wiz's bedroom");
    set_long("This is the bedroom of %^BOLD%^%^RED%^wiz%^RESET%^."
             "It is this very room in where he sleeps.\n"
             "There is a poster on the wall, but oddly no bed..");
    set_items(([
        "poster" : "\n"
"            .'/,-Y\"     \"~-.  \n""            l.Y             ^.           \n"
"            /\\               _\\_      \"doh!\"   \n"
"           i            ___/\"   \"\\ \n"
"           |          /\"   \"\\   o !   \n"
"           l         ]     o !__./   \n"
"            \\ _  _    \\.___./    \"~\\  \n"
"             X \\/ \\            ___./  \n"
"            ( \\ ___.   _..--~~\"   ~`-.  \n"
"             ` Z,--   /               \\    \n"
"               \\__.  (   /       ______) \n"
"                 \\   l  /-----~~\" /    \n"
"                  Y   \\          / \n"
"                  |    \"x______.^ \n"
"                  |           \\    \n"
"                  j            Y  \n"
"\n"
"                h0h0!\n",
     ({"wall", "the wall", "walls"}):
     "The wall has a poster on it, maybe you should look at it.",
    "carpet" : "the carpet is nice and soft... mmmmm furry...." ]));
    set_exits(([ "north" : WIZHOUSE ]));
}
