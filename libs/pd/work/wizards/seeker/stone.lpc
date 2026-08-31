// MP REGEN STONE... seeker
/* 12-11-2000
 *     Found a problem in stones where the heart beats were not turned
 *     off in the un-used stones and filled up the heartbeat processing
 *     which in turn lagged the living crap out of the mud. It should be
 *     fine now since i re-wrote it so the first object is the ONLY one 
 *     that has a heart beat and it controls the following 3 stones,
 *     and the rest just sit there. The heart_beat is passed on to the 
 *     second stone if the first one is move()'d or remove()'d from the
 *     player. Also there is no heart beat if the owner is non-living.
 *     [seeker]
**/

#include <std.h>

inherit OBJECT;

int MANA;
int quick=0;
object owner;
void do_mana(int quickly);

void create()
{
    ::create();
    set_name("ashes");
set_short("Assassin");
 set_long("%^BOLD%^%^WHITE%^These Ashes are from the burnt corpses of the fallen "
          "members of the %^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^"
          "S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s%^WHITE%^ clan. To use the "          "power within the ashes you must <sprinkle> ashes.");

 set_id( ({ "ashes", "black ashes", "stonecheck" }) );

    MANA = random(6000)+6000;

}
int query_mana() { return MANA; }
int query_quick() { return quick; }
int set_mana(int x) { MANA = x; return x; }
int add_mana(int x) { MANA += x; }
int set_heart()     { set_heart_beat(1); }
void init()
{
    owner = environment(this_object());
    ::init();
    if (owner)
	if (present("stonecheck", owner)==this_object()) 
	    set_heart_beat(1);
    add_action("rub", "rub");
}

int rub(string str)
{
    if (environment(this_object())!=this_player())
	return 0;
    if (str!="ashes") return notify_fail("Sprinkle what?\n");
    if (this_player()->query_paralyzed()) return notify_fail("You cannot do that "
	  "while paralyzed.\n");
    write("%^BOLD%^%^WHITE%^You sprinkle ashes around your body and feel a rush of mana shot into your body.");

    quick = 1;
    return 1;
}

string query_short()
{
 string str;

 str = ::query_short()+" ";
 if (MANA >= 5000)
   str += "(circling)";
  else
 if (MANA >= 4000)
   str += "(levitateing)";
  else
 if (MANA >= 3000)
   str += "(riseing)";
  else
 if (MANA >= 2000)
   str += "(floating)";
  else
 if (MANA >= 1000)
  str += "(falling)";
 else
if (MANA < 500)
  str += "(spining)";
 return str;
}

void heart_beat()
{
    object ob2,ob3;
    owner = environment(this_object());
    if (!owner) return;
    if ((present("stonecheck", owner)!=this_object()) || 
      (!owner->is_living()))
    {
	set_heart_beat(0);
	return;
    }
    ob2 = present("stonecheck 2", owner);
    ob3 = present("stonecheck 3", owner);

    /* --- Give mana to the player --- */
    do_mana(quick);
    if (ob2) ob2->do_mana(quick);
    if (ob3) ob3->do_mana(quick);
}


void do_mana(int quickly)
{
    owner = environment(this_object());
    if (!owner->is_living())
    {
	if (random(100) > 50)
	    MANA -= 5;

	if (MANA > 0) return;
    }

    if (MANA <= 0)
    {
	message("info", "The magical stone turns into dust and blows away.", owner); 
	this_object()->remove();
	return;
    }
    if (random(100) > 40 )
	if (quickly && owner->query_mp() < owner->query_max_mp())
	{
	    if (random(100) < 25)
	    {
		owner->add_mp(400);
		MANA -= 400;
	    }
	    else
	    {
		if (random(100) < 50)
		    owner->add_mp(200);
		MANA -= 200;
	    }
	    if (owner->query_mp() >= owner->query_max_mp())
		quickly = 0;
	    return;
	}
    if (random(100) > 50)
    {
	owner->add_mp(10);
	MANA -= 10;
    }


}

int move(mixed dest)
{
    owner = environment(this_object());
    if (!owner) return ::move(dest);
    if (present("stonecheck 2", owner) &&
      owner->is_living())
	present("stonecheck 2", owner )->set_heart();
    return ::move(dest);
}

int remove()
{
    owner = environment(this_object());
    if (!owner) return ::remove();
    if (present("stonecheck 2", owner) &&
      owner->is_living())
	present("stonecheck 2", owner )->set_heart();
    return ::remove();
}
int query_heart() { return query_heart_beat(this_object()); }
