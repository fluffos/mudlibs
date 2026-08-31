#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The path along Belief Trail ends at the base of a small clouded cliff. A beam of %^YELLOW%^sunlight shines brightly %^WHITE%^through the clouds, providing enough %^YELLOW%^light %^WHITE%^to see. Many Angels and god-like people climb up the hill after stopping shortly to speak to one another. A few %^GREEN%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^WHITE%^can be seen magically growing through a tuft of clouds.%^RESET%^");
    set_items( ([ "cliff": "%^BOLD%^%^WHITE%^This cliff is made of clouds and can easily be climbed up.%^RESET%^", "plants": "%^BOLD%^%^GREEN%^The plants seem to be growing magically through the clouds.%^RESET%^" ]) );
    set_exits( ([ "east" : SKYROOM "ls_5", "up" : SKYROOM "lsup_5", "south" : SKYROOM "ls_7" ]) );
}
