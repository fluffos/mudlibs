#include <std.h>
#include <sindarii.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("craz");
   set_short("Craz the crazed");
   set_long("Craz is one psycho woman. Every now and then she goes into "
	"murderous fits and her body convulses. She is dangerous and a lead "
	"figure in the anarchist cult.");
   set_race("goblin");
   set_alignment(-1400);
   set_body_type("human");
   set_gender("female");
   set_level(9);
   set_id(({ "craz", "craz the crazed" }));
   new(ROOMS"cult/obj/jacket")->move(this_object());
   command("wear coat");
}
