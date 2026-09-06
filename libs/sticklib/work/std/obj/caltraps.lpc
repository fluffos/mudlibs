#include <treasure.h>
#include <room_defs.h>
#include <attack.h>
#include <stats.h>
#include <guild.h>
#include <daemons.h>

#define TP this_player()

int x,y,dropped,used;
object dropper,*list;

void
create_treasure()
{
    set_name("caltraps");
    set_id(({"caltraps"}));
    set_weight(1);
    set_short("Some caltraps");
    set_long("These are small metal balls with four sharp spikes. When you drop "+
      "these to the ground one spike is always pointing up, giving a nasty "+
      "surprise to anyone who steps on them. Usage: 'drop caltraps'.");
    set_value(400);
}

init_treasure()
{
    int hp,dam;

    add_action("drop","drop");

    if(living(environment())) {
	dropped=0;
	return 1;
    }
    if(y>=x) dropped=1;
    y++;
    if(!dropped || environment()->query(NO_PK)) return;
    if(TP==dropper) {
	TP->tell_me("You remember that you dropped those caltrops here and avoid "+
	  "the trap.");
	return 1;
    }
    // Ninja should not have to step into traps...
    // ... provided the mud has ninjas

    if (
#ifdef GN_NINJA
      (string) TP->query_guild() == GN_NINJA ||
#endif
      random((int) TP->query_stat(ST_DEX)) > 10) {
	environment()->tell_here(TP->query_name()+" notices the traps and steps aside.");
	return 1;
    }
    if ((int) TP->query_stat(ST_DEX) > random(50)) return 1;
    TP->tell_me("OUCH! You stepped on caltraps!");
    environment()->tell_here(TP->query_name()+" steps on caltraps and swears "+
      "loudly!",({TP}));
    hp=TP->query_hp();
    dam=20+random(30);
    if(hp<dam) dam=hp;
    // TP->add_hp(0-dam); /* Changed from hit_player because... */
    TP->hit_player(dam, DT_PIERCE, 0); 
#ifdef FEET_D
    call_other(FEET_D, "add_to_mapping", TP, environment(TP));
#endif
    used++;
    if(used>=3) destruct(this_object());
    return 1;
}


drop(string str)
{
    if(environment()!=TP && (str=="caltraps") && !present("caltraps",TP))  
    {
	TP->tell_me("You must get them first!");
	return 1;
    }
    if(present("caltraps",environment(TP))) {
	TP->tell_me("But there already are caltraps here!");
	return 1;
    }
    if((str=="caltraps" || str=="all") &&  environment()==TP) {
	dropper=TP;
	dropped=0;
	list=filter_array(all_inventory(environment(TP)),"is_living",this_object());
	x=sizeof(list);
	y=0;
    }
    return 0;
}

status 
is_living(object ob) { return living(ob); }
