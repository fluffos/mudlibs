#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The clouds gather slightly the more west the path leads on Belief Trail. Facing south, there is a sign on the side of a building that reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Drink Shop'. To the north, the sound of %^BLACK%^dr%^RED%^ag%^BLUE%^on%^WHITE%^s can be heard. A few %^GREEN%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^WHITE%^can be seen magically growing through a tuft of clouds.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Drink Shop'.%^RESET%^", "plants": "%^BOLD%^%^GREEN%^The plants seem to be growing magically through the clouds.%^RESET%^"]) );
    set_smell("default", "%^BOLD%^%^WHITE%^The smell of %^BLACK%^dr%^RED%^ag%^BLUE%^on%^WHITE%^s is flowing through the %^CYAN%^air%^WHITE%^.%^RESET%^");
    set_exits( ([ "east" : SKYROOM "ls_2", "west" : SKYROOM "ls_4", "north" : SKYROOM "dragon_hall1", "south" : SKYROOM "drink_shop" ]) );
}
