//Arbalest for Hound Camp - LoKi - 2021
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("A large arbalest");
    set_id(({"arbalest","a large arbalest",}));
    set_weight(1000000);
    set_short("%^C246%^A large arbalest%^CRST%^");
    set_long("%^C246%^This machine of war is a "+
	"%^C124%^wicked %^C246%^looking thing. It is "+
	"a %^C094%^giant crossbow%^C246%^, mounted "+
	"on the %^C094%^frame of a wagon%^C246%^. The "+
	"wings of the bow itself are %^C066%^fourteen "+
	"feet%^C246%^ across and the bolt that it must "+
	"fire would be the size of a %^C040%^tree%^C246%^"+
	". The bowstring is pulled back by a %^C243%^"+
	"heavy iron claw%^C246%^ and attached to a "+
	"winch and pulley to draw it back. A "+
	"%^C252%^bolt %^C246%^thrown by this could "+
	"easily tear through a group of soldiers, "+
	"or even a %^C095%^wooden building%^C246%^. "+
	"It is heavy enough that a team of %^C249%^"+
	"horses %^C246%^would be needed to move "+
	"it.\n%^CRST%^");
    set_value(0);
    set_property("no animate",1);
}

void init(){
   environment(this_object())->remove_item("arbalest");
}

