/* The torso and head */
#include <npc.h>

void
create_monster()
{
    set_name("great golem");
    set_id(({ "head" }));
    set_race("golem");
    set_short("The Great Golem");
    set_long(
      "You have never seen a monster so ENORMOUS as this one! It doesn't \
matter if it can't fight with it fists when you are so close to it: \
it might crush you with a nod of it's head or a wink of it's eye, \
unless you are quick enough to get out of the way."); 
    set_gender(G_NEUTER);
    set_level(25);
    set_ep(1300000);
    set_hp(750);
    load_chat(5,({"The Great Golem stares calmly at you.",
	"The Great Golem grins evilly."}));
    set_ac(35,1);
    set_wc(25);
    add_block( "north","all", 0, 0,
      "You cannot get past the Great Golem.",
      ":%<him.name%> tries to pass the Great Golem, but cannot.", 0,0 );

}

status
query_is_immune_vs_obj(object ob, int type)
{
    if (ob && !present("deaths_item", ob))
    {
	ob->tell_me("The Golem is not hurt by your attacks!");
	return 1;
    }
    return 0;
}
