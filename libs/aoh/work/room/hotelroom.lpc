/*

	A generic hotelroom

	Please inherit these file and configure it in the create with
	'AddSleepCmd(<cmdname>, [<functionname>]);'
	and the normal 'std/room' functions(SetIntShort, SetIntLong, ...).

	<functioname> is an optional parameter that can give the name of
	a function in the hotelroom file which is executed before the
	player is sent to sleep.

	'AddSleepCmd' returns 1 for success and 0 for failure.

	It should cost a player something to stay over night in a hotelroom.
	Let the adventurer pay at the entrance of the hotel. For prices ask
	the Archwiz of Finance.
	(C) 1992 Randyandy@Nightfall with a lot of help from Tares.
	advanced and debugged by Thragor@Nightfall 27jan94

*/

#define HOTELCARD "/obj/hotelcard"

inherit "/std/room";

private nosave mapping sleepcmds;
private nosave string name;

varargs void AddSleepCmd(string cmdname,string funcname)
{
 if (!cmdname) return;
 if (funcname)
 {
  if (!function_exists(funcname, this_object()))
  {
   raise_error("There is no function '" + funcname + " defined!\n");
   return;
  }
 }
 else
  funcname = "default_func";

 sleepcmds += ([cmdname:funcname]);
}

void default_func()
{
 write("You enter the world of dreams ...\n");
}

mapping SetSleepCmds(mapping cmds)
{
 return sleepcmds = cmds;
}

mapping QuerySleepCmds()
{
 return sleepcmds+([]);
}

void SetHotelName(string str)
{
 SetIntShort("A room at the "+(name = (str?str:"hotel")));
}

string QueryHotelName() { return name; }

int _do_sleep()
{
 object ob, card;
 int i;
 string txt;

 i=0;
 if (sleepcmds[query_verb()])
  call_other(this_object(),sleepcmds[query_verb()]);

 card = clone_object(HOTELCARD); /* The autoloading object */
 card->SetHotelFilename(this_object()->QueryHotelName(),
       object_name(this_object()));
 /* Sets the card to this hotel */
 card->SetNewHome(this_player()->QueryHome());
 /* The original HOME of the player is stored */
 card->move(this_player());
 this_player()->SetHome(object_name(this_object()));
 /* Now the players home is set to the hotel-room */
 this_player()->quit();
 /* The player must immediately log out, else the funktion wake_up()
    in the card is called */
 return 1;
}

void init()
{
 int i;
 string *idx;

 ::init();

 /* Set default if no 'AddSleepCmd' was called. */

 if (!i = sizeof(idx = m_indices(sleepcmds))) add_action("_do_sleep","sleep");
 else
  while(i--)
   add_action("_do_sleep",idx[i]);
 add_action("_do_sleep","quit");
}


varargs void create()
{
 ::create();

 if (sizeof(explode(object_name(this_object()), "#")) > 1)
 {
  write("\
Don't 'clone' this object! (Only 'load' it!) An unique and constant\n\
filename is needed for an entry point!\n");
  remove();
 }

 SetIntShort("You are inside a little hotelroom");
 SetIntLong("\
You are inside a little hotelroom. With 'sleep' you can stay over night.\n\
You will drop all your belongings before you go to bed...\n");
 SetIndoors(1);

 sleepcmds = ([]);
}
