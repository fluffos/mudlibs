#include <std.h>
#include <sindarii.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("punk");
   set_short("a punk");
   set_long("A little anarchist punk thief. He'll rob you blind if you're not "
	"careful! The punk has a pierced ear and lip, and a chain connecting the "
	"two holes.");
   set_race("human");
   set_alignment(-500);
   set_body_type("human");
   set_gender("male");
   set_level(5);
   set_id(({ "cult extremist", "culist", "extremist", "punk" }));
   new(ROOMS"cult/obj/s_sword")->move(this_object());
   command("wield shortsword");
}
