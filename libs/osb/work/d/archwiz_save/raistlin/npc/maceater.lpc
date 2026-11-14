/* Fucking cool MacDonalds eater. */
 
#include <properties.h>
#include <living.h>
#include <doors.h>
#include <config.h>
#include <moving.h>

#define ME this_object()
inherit "/std/npc";
inherit "/lib/money";
inherit "/obj/lib/string";
int count;
 
int create (int arg)             /* ????? */
{
 if (::create()) return 0;        /* ????? */
 if (!arg)                        /* ????? */
 {
	SetRace("human");
	SetGender(MALE);
	SetName("MacEater");
	SetLevel(2);
	SetIds(({"Maceater","maceater","eater","living"}));
	SetAttributes(({({"int","con","dex","str"}),({4,3,3,2})}));
	SetHands(({({"right hand",0,2}),({"left hand",0,2}),({"right foot",0,2}),({"left foot",0,2})}));
	SetShort("An angry MacDonalds eater");
	SetLong("A guy like you, waiting to get something to eat...\n"
		+"He looks very angry, because he has been standing here "
		+"now for a LONG time!\n");
	SetAggressive(0);
	SetAlign(-100-random(50));
	SetAC(2);

        AddQuestion(({"mcdonalds", "macdonalds", "big mac", "big macs", "food" })
		   , "A MacEater says: Hmm, Big Macs are my kind of food - "
		     "and McDonalds serves the best!\n"
		   );
	InitChats(7, ({
			"A MacEater whispers: \"That's the 4th time i am here today!\"\n",
			"A MacEater gumbles something about waiting now for over 10 minutes.\n",
			"A MacEater shouts: \"WHY DOES IT TAKE SO FU**ING LONG?!\"\n",
			"A MacEater says: \"I am still under 300 pound, so i may still eat says my doctor.\"\n",
			"A MacEater looks hungrily around.\n",
			"A MacEater seems to need a toilet. Soon!\n",
			"A MacEater says: \"Come and visit the great McDonalds of Raistlin in NF city!\"\n"
		}));

	InitAChats(3, ({
			"A fighting MacEater says: You won't get MY bigmac!\n",
			"A fighting MacEater says: I will fill you up with ketchup!\n",
			"A fighting MacEater says: Eat or die!\n"
		}));

	SetChatChance(5);
	SetAChatChance(100);
	AdjustMoney(this_object(),random(20)+15,"copper");
        count=0;
 }
	return 1;
}


int init()
{
	::init();
	return 1;
}

int begin_move()
{
	InitChats(2, ({
		"A MacEater says: \"Come and visit the great McDonalds of Raistlin in NF city!\"\n",
		"A MacEater seems to eat some of his food.\n"
	}));

	SetChatChance(10);

	SetShort("A friendly MacDonalds eater");
	SetLong("This guy seems to have been at the McDonalds of Raistlin in NF city, as\n"
		+"you can watch him eating some Mc food.\n");

	SetGoChance(100);
	return 1;
}

GoAway () {
  mapping map_exits;
  mapping city_exits;
  string *key_exits;
  object *inv;
  object room;
  int i,num_exits;

  count++;
  if(count>50)
  {
    tell_room(environment(),"Wow! A MacEater explodes next to you. Seems as if he has eaten too much...\n");
    if(inv = deep_inventory())
      map(inv,#'destruct);
    if(!remove())
      destruct(this_object());
    return 1;
  }

  if (!(room = environment(ME))) return 0;

  map_exits = room->Query(P_EXITS_DEST);
  key_exits = m_indices(map_exits);
  num_exits = sizeof(key_exits);

  if(num_exits==0)
    return 2;

  city_exits = copy(map_exits);
  for(i=num_exits-1; i>=0; i--)
  {
    if(!stringp(city_exits[key_exits[i]]) 
     || (ladjcut(city_exits[key_exits[i]], 19) != "/d/archwiz/raistlin" && ladjcut(city_exits[key_exits[i]], 28) != "/d/archwiz/common/room/city/")
      )
    {
      m_delete(city_exits, key_exits[i]);
      num_exits--;
    }
  }

  if(num_exits==0)
    return 3;

  key_exits = m_indices(city_exits);
  i = random(num_exits);
  if (command_me(key_exits[i]) != ME_OK)
    return 4;

  return 5;
}
