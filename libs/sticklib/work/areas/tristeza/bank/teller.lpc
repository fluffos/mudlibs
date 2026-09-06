#include <group_npc.h>
#include <room_defs.h>
#include <areas.h>

#define BANK "bank/bank"
int shout,fight;

void
init()
{
    ::init();
    if (!is_fighting())
	shout = fight = 0;
    if (environment()
      && strstr(object_name(environment()),BANK)==-1)
    {
	environment()->tell_here("Teller says: Oh, my! Is it that late\
 already? I have some work to do!",this_object());
	move_player("Vheads her heels to the bank",
	  AREA_TRISTEZA+BANK);
    }
}

void
create_monster()
{
    set_name("teller");
    set_short("Teller");
    set_group("cityguard");
    set_id(({ "clerk", "official" }));
    set_alignment(AL_NICE);
    set(NPC_SET_PK_FLAG, 1);
    set_wimpy(40);
    set_gender(G_FEMALE);
    set_level(16);
    set_wc(80, 1);
    // Was 10. -+ Doomdark +-
    set_hp(4000);
    // Was 300. -+ Doomdark +-
    // Was 500. Made it ridiculous. -+ Graah -+
    set_long("She looks meticulous.");
    set_money(random(801) + 200);
}

varargs int
hit_player(int hit, int type, int hc, object enemy)
{
    if (enemy) {
	if (!shout) {
	    shout = 1;
	    call_out("yell", 1, enemy);
	}
	if (!fight) {
	    fight = 1;
	}
    }
    return ::hit_player(hit, type, hc, enemy);
}

void
yell(object ob)
{
    if (ob && living(ob)) {
	object *x;
	int i;
	string n;
	x = users();
	n = (string) ob -> query_name(0, this_object());
	for (i = sizeof(x) - 1; i-- > 0;)
	    // Let's only let players in city hear it! -+ Doomdark, 27-feb-95 +-
	    if (environment(x[i]) && environment(x[i])->query(IN_CITY))
		x[i] -> tell_me(
		  "You hear someone shout: Help! "+ob->query_name()+" is trying to rob the bank!\
 That might cause serious disturbance to our customer service!");
    }
}

int
run_away()
{
    if( strstr(object_name(environment()),BANK)!=-1)
    {
	environment()->tell_here("Teller takes a piece of parchment \
and writes something in it, then she places it on the counter.",
	  this_object());
	move_player("Vruns east", AREA_TRISTEZA+"virtual/S10_5");
	return 1;
    }

    return ::run_away();
}
