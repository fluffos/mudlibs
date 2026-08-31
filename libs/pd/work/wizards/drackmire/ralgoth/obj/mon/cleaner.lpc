#include <std.h>
#include "ralgoth.h"
inherit MONSTER;
void create()
{
 ::create();

	set_name("undead");
	set_id(({"streetsweeper", "street cleaner", "cleaner" }));
	set_short("an undead street cleaner");
	set_long("One of the many slaves of the necromancers of Ralgoth, "
	"this living dead has been purposed to keep the streets of the "
	"fortress clean.  There's a cruel irony to the fact that as it "
	"sweeps, rotting pieces of flesh fall from its body to the ground "
	"behind it.");
	set_property("undead", 1);
	set_alignment(-200);
 	set_race("undead");
 	set_gender("neuter");
 	set_body_type("human");
	set_level(30);
 	set_moving(1); 
 	set_speed(20);

	new(RALWEAP"broom")->move(this_object());
	command("wield broom");
}
