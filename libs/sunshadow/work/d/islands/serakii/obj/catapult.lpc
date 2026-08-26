//Catapult for Hound Camp - LoKi - 2021
#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("A stout wooden catapult");
    set_id(({"catapult","stout wooden catapult",}));
    set_weight(1000000);
    set_short("%^C094%^A stout wooden catapult%^CRST%^");
    set_long("%^C094%^Constructed from large wooden "+
	"logs hewn and reinforced with %^C246%^iron "+
	"bracers%^C094%^, this war machine is "+
	"capable of throwing %^C254%^rocks "+
	"%^C094%^or %^C124%^flaming pitch%^C094%^ "+
	"across a battlefield. An arm extends on "+
	"the top with a %^C137%^large net%^C094%^. "+
	"A winch then connects the arm via a "+
	"pulley system. It is heavy enough that a "+
	"team of %^C249%^horses %^C094%^would be "+
	"needed to move it into position and a "+
	"group of %^C245%^soldiers %^C094%^would "+
	"be needed to correctly operate it.\n%^CRST%^");
    set_value(0);
    set_property("no animate",1);
}

void init(){
   environment(this_object())->remove_item("catapult");
}
