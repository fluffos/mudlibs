#include <std.h>
#include <sindarii.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("extremist");
   set_short("a cult extremist");
   set_long("The extremists take the law and life into their own hands. They "
	"belong to a small anarchist cult.");
   set_alignment(-1000);
   set_race("human");
   set_body_type("human");
   if (random(10) > 5) set_gender("male");
   else set_gender("female");
   set_level(4);
   set_id(({ "cult extremist", "culist", "extremist", "punk" }));
   new(ROOMS"cult/obj/spear")->move(this_object());
   command("wield spear");
}
