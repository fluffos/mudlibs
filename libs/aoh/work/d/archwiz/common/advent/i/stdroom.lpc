/* Advent - Standard Room -- Mateese, 04-Aug-96
 *
 * It implements:
 *  - default descriptions for Noise and Smell
 *  - the distinction between terse (original) and extended details
 *    (see P_ORIGLIST).
 *    It is handled by a set of {Add,Remove}Orig{Detail,Smell,Noise,ReadMsg}-
 *    Functions setting both the detail and the 'original tag'.
 *    Get{Detail,Smell,Noise,ReadMsg}() are overloaded to evaluate the tat.
 *  - players moving in the dark have a 25% chance of getting hurt.
 *  - the magic words 'xyzzy' and 'plugh' (said or commanded) teleport
 *    the player between the Treasure Dump and the Debris Room resp. Y2.
 *  - the magic words 'fee fie foe foo' (resp. '... fum') cause every present
 *    nest of golden eggs to heat up (by calling the function DoFoo() 
 *    in them).
 *  - the pirate who once (with a 3% chance) steals every treasure from the
 *    player and stores it in Pirates' Dead End.
 *  - the activation of the threatening little dwarf.
 * 
 * Properties:
 *   P_ORIGLIST: List of names of those details which originate from the
 *      original game. Each name is of the form '<type>:<detailid>',
 *      with <type> being 'look', 'smell', 'noise' or 'read'.
 *   P_NOORIG: Set to non-zero, it switches back to normal detail handling.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit "/std/room";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public varargs void create(int noreplace)
{
  ::create(noreplace);

  // Generic descriptions.
  Set(P_INT_SMELL, "The air is cold and smells stale and earthy.\n");
  Set(P_INT_NOISE, "It is silent.\n");

  // Miscellaneous
  Set(P_ADVROOM, 1);
  Set(P_ORIGLIST, 0);
  Set(P_NOORIG, 0);
}

void init()
{
  ::init();
  add_action("fdispatch", "", 1);
  /* Be careful with other commands here 'cause fdispatch needs to be
   * informed about every command given.
   */
}

/*-----------------------------------------------------------------------*/
/* Handle the distinction between original(terse) and new details.
 */

varargs void AddOrigTag (mixed list, string type)

/* Add <list> (string or string array) to P_ORIGLIST. If <type> is given,
 * every element in <list> is prefixed by "<type>:'.
 */

{
  string * oldlist;
    
  if (!pointerp(list))
    list = ({ list });
  else // don't modify the original array
    list = list + ({ });
  if (!stringp(type))
    list = map(list, #'norm_id);
  else
  {
    int i;
      
    for (i = sizeof(list); i--; )
      list[i] = norm_id(type+":"+list[i]);
  }
  oldlist = Query(P_ORIGLIST) || ({ });
  oldlist -= list;
  Set(P_ORIGLIST, oldlist + list);
}

varargs void RemoveOrigTag (mixed list, string type)

/* Remove <list> (string or string array) from P_ORIGLIST. If <type> is given,
 * every element in <list> is prefixed by "<type>:'.
 */

{
  string * oldlist;
    
  if (!pointerp(list))
    list = ({ list });
  else // don't modify the original array
    list = list + ({ });
  if (!stringp(type))
    list = map(list, #'norm_id);
  else
  {
    int i;
      
    for (i = sizeof(list); i--; )
      list[i] = norm_id(type+":"+list[i]);
  }
  oldlist = Query(P_ORIGLIST) || ({ });
  Set(P_ORIGLIST, oldlist - list);
}

public varargs void AddOrigDetail (mixed det, mixed desc, string exa) {
  AddOrigTag(det, "look");
  AddDetail(det, desc, exa);
}
public varargs void AddOrigSmell (mixed k, mixed v) {
  AddOrigTag(k, "smell");
  AddSmell(k, v);
}
public varargs void AddOrigNoise (mixed k, mixed v) {
  AddOrigTag(k, "noise");
  AddNoise(k, v);
}
public varargs void AddOrigReadMsg (mixed k, mixed v) {
  AddOrigTag(k, "read");
  AddReadMsg(k, v);
}

public void RemoveOrigDetail (mixed k) {
  RemoveOrigTag(k, "look");
  RemoveDetail(k);
}
public void RemoveOrigSmell (mixed k) {
  RemoveOrigTag(k, "smell");
  RemoveSmell(k);
}
public void RemoveOrigNoise (mixed k) {
  RemoveOrigTag(k, "noise");
  RemoveNoise(k);
}
public void RemoveOrigReadMsg (mixed k) {
  RemoveOrigTag(k, "read");
  RemoveReadMsg(k);
}

public mixed GetDetail(string str) {
  mixed list;
  list = Query(P_ORIGLIST)|| ({});
  if (!Query(P_NOORIG) && QueryFlag(F_TERSE, this_player()) && -1 == member(list, "look:"+norm_id(str)))
    return 0;
  return ::GetDetail(str);
}
public string GetSmell(string str) {
  mixed list;
  list = Query(P_ORIGLIST)|| ({});
  if (!Query(P_NOORIG) && QueryFlag(F_TERSE, this_player()) && -1 == member(list, "smell:"+norm_id(str)))
    return 0;
  return ::GetSmell(str);
}
public string GetNoise(string str) {
  mixed list;
  list = Query(P_ORIGLIST)|| ({});
  if (!Query(P_NOORIG) && QueryFlag(F_TERSE, this_player()) && -1 == member(list, "noise:"+norm_id(str)))
    return 0;
  return ::GetNoise(str);
}
public string GetReadMsg(string str) {
  mixed list;
  list = Query(P_ORIGLIST)|| ({});
  if (!Query(P_NOORIG) && QueryFlag(F_TERSE, this_player()) && -1 == member(list, "read:"+norm_id(str)))
    return 0;
  return ::GetReadMsg(str);
}

/*-----------------------------------------------------------------------*/
public void notify_enter (object from, int method, mixed extra)

/* Players moving in the dark are likely to get hurt.
 * Also, activate the pirate and/or the dwarf upon occasion.
 */

{
  int i, j;
      
  ::notify_enter(from, method, extra);
  if (!previous_object()->Query(P_IS_LIVING)
   || M_GO != method
     )
    return;
    
  /* Stumble in the dark. */
  if (objectp(from)
   && previous_object()->CantSee(from)
   && previous_object()->CantSee(this_object())
   && random(100) < 25
     )
  {
    if (random(2))
    {
      tell_object(previous_object(), "You stumble over a rock. Ouch!\n");
      show_room(this_object()
	       , ({ previous_object()->Query(P_NAME)+" stumbles over a rock.\n"
		  , "You hear a muffled 'Ouch!'\n" 
	         })
	       , ({ previous_object() })
	       );
    }
    else
    {
      tell_object(previous_object(), "You walk into a wall. Ouch!\n");
      show_room(this_object()
	       , ({ previous_object()->Query(P_NAME)+" walks into a wall.\n"
		  , "You hear a muffled 'Ouch!'\n" 
	         })
	       , ({ previous_object() })
	       );
    }
    previous_object()->DoDamage(5);
  }
  
  /* Activate the pirate */
  if (!QueryFlag(F_PIRATE, previous_object())
   && !Query(P_NODWARF)
   && !Query(P_NONPC)
   && Query(P_INT_LIGHT) < 10
   && to_string(this_object()) != ADVENT("r/darkroom")
   && to_string(this_object()) != ADVENT("r/s-canyon")
   && (i = random(100)) <= 4
     )
  {
    previous_object()->RegisterCmdFun("DoPirate", i);
  }

  /* Activate the dwarf */
  j = previous_object()->Query(P_DWARVES);
  if (j < ADV_DWARVES
   && (i = random(100)) <= 2 * (ADV_DWARVES - j)
   && !Query(P_NODWARF)
   && !Query(P_NONPC)
   && Query(P_INT_LIGHT) < 10
   && to_string(this_object()) != ADVENT("r/darkroom")
   && !present(ADV_BEAR, this_object())
   && !present(ADV_TROLL, this_object())
   && !present(ADV_DWARF, this_object())
     )
  {
    previous_object()->RegisterCmdFun("DoDwarf", i);
  }
}

/*-----------------------------------------------------------------------*/
public void DoPirate (int arg, int goterror)

/* Handle the Pirate.
 * The player can see it twice: once when no treasures are present,
 * and once when the Pirate steals every treasure in the room and
 * from the player.
 */

{
  object * tr;
    
  if (goterror || !this_player())
    return;

  /* The pirate is 'nearby'... */
  if (arg > 2
   || (   QueryFlag(F_PIRATE_S, this_object())
       && QueryFlag(F_PIRATE_R, this_object())
      )
     )
  {
    tell_room(this_object(), 
"There are faint rustling noises from the darkness behind you.\n"
	     );
    return;
  }

  if (present(ADV_DWARF, this_object()))
  {
    show_room(this_object(),
"A bearded pirate appears, catches sight of the dwarf and runs away.\n"
             );
  }

  /* Mark all treasures here in tr. */
  tr = all_inventory(this_object()) + deep_inventory(this_player());
  tr = filter_objects(tr, "IsTreasure", this_player(), 1);

  if (!sizeof(tr))
  {
    if (!QueryFlag(F_PIRATE_S, this_player()))
    {
      write(
"There are faint rustling noises from the darkness behind you. As you "
"turn toward them, you spot a bearded pirate. He is carrying a large "
"chest. 'Shiver me timbers!' he cries, 'I've been spotted! I'd best hide "
"myself off to the maze to hide me chest!' With that, he vanishes into "
"the gloom.\n"
	   );
      SetFlag(F_PIRATE_S, this_player());
      show(this_player()->Query(P_NAME)
	   +" turns around and stares into the gloom.\n");
      say("You hear a muffled voice, but can't understand the words.\n");
    }
  }
  else if (!QueryFlag(F_PIRATE_R, this_player()))
  {
    show_room(this_object(),
"Out from the shadows behind you pounces a bearded pirate!\n",
"Someone definitely unfriendly entered the room.\n"
	     );
    tell_room(this_object(),
"'Har har,' he chortles. 'I'll just take all this booty and hide it away "
"with me chest deep in the maze!'\n"
	     );
    map_objects(tr, "move", ADVENT("r/piratesend"), M_SILENT);
    write("He snatches your treasure and vanishes into the gloom.\n");
    show("He snatches several treasures and vanishes into the gloom.\n");
    SetFlag(F_PIRATE_R, this_player());
  }
}

/*-----------------------------------------------------------------------*/
public void DoDwarf (int arg, int goterror)

/* Activate the dwarf.
 */

{
  object dwarf;
  int count;
    
  if (goterror || !this_player())
    return;

  count = this_player()->Query(P_DWARVES);
    
  /* The dwarf is 'nearby'... */
  if (arg > ADV_DWARVES - count
   || present(ADV_DWARF, this_object())
     )
  {
    tell_room(this_object(), 
"From the darkness the pitter-patter of little feet can be heard.\n"
	     );
    return;
  }

  /* Is the dragon here? */
  if (present(ADV_DRAGON, this_object()))
  {
    show_room(this_object()
,"A dwarf appears, but with one casual blast the dragon vapourises him.\n"
,"FWOOOOOSHHH!\n"	      
	     );
    this_player()->Set(P_DWARVES, count+1);
    return;
  }

  /* First encounter: the dwarf just throws an axe.
   */
  if (!QueryFlag(F_DWARF))
  {
    dwarf = clone_object("/std/weapon");
    dwarf->Set(P_SHORT, "a dwarvish axe");
    dwarf->Set(P_LONG, "It's just a little axe.\n");
    dwarf->Set(P_VALUE, 100);
    dwarf->Set(P_WEIGHT, 750);
    dwarf->AddId(({ "dwarvish", "dwarven", "little" }));
    dwarf->Set(P_WEAPON_TYPE, WT_AXE);
    dwarf->Set(P_DAM_TYPE, DT_SLASH);
    dwarf->Set(P_WC, 6);
    dwarf->Set(P_NUMBER_HANDS, 1);
    if (ME_OK != dwarf->move(this_object(), M_SILENT))
      dwarf->remove();
    else
    {
      SetFlag(F_DWARF);
      show_room(this_object()
               , "A threatening little dwarf comes out of the shadows.\n"
	       );
      write(
"The dwarf throws a nasty little axe at you, misses, curses and runs away.\n"
	   );
      show(
"The dwarf throws a nasty little axe at "+this_player()->Query(P_NAME)
	                                 +", misses, "
"curses and runs away.\n"
	  );
    }
    return;
  }

  /* Move the dwarf into the room and start it up.
   * It might be that the dwarf can't enter the room or destructs at this.
   */
  dwarf = clone_object(ADVENT("o/dwarf"));
  if (ME_OK != dwarf->move(this_object(), M_SILENT))
  {
    if (dwarf)
      dwarf->remove();
    if (dwarf)
      destruct(dwarf);
    return;
  }

  show_room(this_object()
           , "A threatening little dwarf comes out of the shadows.\n"
	   );
    
  dwarf->Follow(this_player());
}

/*-----------------------------------------------------------------------*/
/* The teleporting commands 'xyzzy' and 'plugh' work both when said
 * or commanded. Take care that we don't 'port away from a fight.
 */

public varargs void doport(string verb, int goterror)
{
  mapping vdata;
  string dest, dest1, dest2;

  if (goterror)
    return;

  vdata = ([ "xyzzy" :F_XYZZY; ADVENT("r/debrisroom"); ADVENT("r/trdump")
           , "plugh" :F_PLUGH; ADVENT("r/y2"); ADVENT("r/trdump")
           ]);

  if (-1 == member(m_indices(vdata), verb))
    return;
    
  if (!QueryFlag(vdata[verb,0], this_player())
   || sizeof(this_player()->Query(P_ENEMIES))
     )
  {
    write("Nothing happens.\n");
    return;
  }
  
  dest1 = vdata[verb, 1];
  dest2 = vdata[verb, 2];
  if (to_string(this_object()) == dest1)
    dest = dest2;
  else if (to_string(this_object()) == dest2)
    dest = dest1;
  else
  {
    write("Nothing happens.\n");
    return;
  }

  if (ME_OK != this_player()->move(dest, M_TELEPORT))
    raise_error("Move to "+dest+" failed.\n");
}

/*-----------------------------------------------------------------------*/
/* The magic words 'fee fie foe foo' (resp. '... fum') cause every
 * nest of golden eggs in the room to heat up.
 * To do this, the function DoFoo() is called in every present nest.
 */

public varargs void dofoo (string verb, int goterror)
{
  int count, ok;
    
  if (goterror)
    return;

  if (-1 != member(verb, ' '))
  {
    write("Try saying the words one at a time.\n");
    this_player()->Set(P_FOOCOUNT, 0);
    return;
  }

  count = this_player()->Query(P_FOOCOUNT);
  switch (count)
  {
  case 0:
    ok = ("fee" == verb);
    break;
  case 1:
    ok = ("fie" == verb);
    break;
  case 2:
    ok = ("foe" == verb);
    break;
  case 3:
    ok = ("foo" == verb) || ("fum" == verb);
    break;
  default:
    this_player()->Set(P_FOOCOUNT, 0);
    return;
  }
    
  if (!ok)
  {
    write("Get the words right, dummy!\n");
    this_player()->Set(P_FOOCOUNT, 0);
    return;
  }
  
  count++;
  this_player()->Set(P_FOOCOUNT, count % 4);

  if (count > 3 && !QueryFlag(F_FIEFOO, this_player()))
     write("Nothing happens.\n");
  else if (count > 3)
  {
    object *nests;
      
    nests = filter_objects(deep_inventory(this_object()), "Query", ADV_NEST);
    if (!sizeof(nests))
      write("Nothing happens here.\n");
    else
    {
      nests = map_objects(nests, "DoFoo") - ({ 0 });
      if (!sizeof(nests))
	write("Something happened.\n");
    }
  }
}

/*-----------------------------------------------------------------------*/
public int doadvent (string arg)

/* Handle the metacommand 'advent' resp. 'adventure'.
 */

{
  arg = norm_id(arg||"");    
  
  if (-1 != member(({"terse", "original", "orig" }), arg))
  {
    write("Now using original descriptions and details.\n");
    SetFlag(F_TERSE, this_player());
    return 1;
  }
  if (-1 != member(({"extended", "ext" }), arg))
  {
    write("Now using extended descriptions and details.\n");
    ClearFlag(F_TERSE, this_player());
    return 1;
  }
  if (-1 != member(({"info", "" }), arg))
  {
    if (QueryFlag(F_TERSE, this_player()))
      write("Using original descriptions and details.\n");
    else
      write("Using extended descriptions and details.\n");
    return 1;
  }
  notify_fail(
"Syntax: adventure [original|extended]\n"
"Displays or changes the description and details between the original "
"and the extended versions.\n"
	     , NOTIFY_ILL_ARG
	     );
}

/*-----------------------------------------------------------------------*/
public int fdispatch (string arg)

/* Intersect any command to see if it interrupts the 'fee fie foe foo'
 * sequence.
 * And as we're doing this anyway, we also dispatch properly for the
 * 'say', 'porting and other commands.
 */

{
  string verb;
  string *args;
  int    rc, gotit;
  int    bIsSay;
    
  verb = query_verb();
  rc = 1;
  gotit = 0;
  bIsSay = 0;
    
  /* If it is the say command, pretend that the first word of 'arg'
   * is the verb said. This way we don't need to check for the magic
   * words in two places.
   */
  if (verb[0..0] == "'" || verb == "say")
  {
    rc = 0; /* So the 'say' will be passed to the player object. */
      
    if (!arg)
      return 0;
      
    if (verb[0..0] == "'")
      verb = verb[1..];
    else
    {
      args = explode(arg, " ") - ({ "" });
      if (sizeof(args))
        verb = lower_case(args[0]);
      else
	verb = "";
      arg = implode(args[1..], " ");
    }
    bIsSay = 1;
  }

  /* 'xyzzy' or 'plugh'? */
  if (-1 != member( ({ "xyzzy", "plugh" }), verb))
  {
    gotit = 1;
    this_player()->Set(P_FOOCOUNT, 0);
    if (!rc)
      this_player()->RegisterCmdFun("doport", verb);
    else if (arg)
      rc = 0;
    else
      doport(verb);
  }

  /* 'advent', 'adventure'? (not when said) */
  if (!bIsSay && -1 != member(({"advent", "adventure" }), verb))
  {
    gotit = 1;
    doadvent(arg);
  }
    
  /* 'fee fie foe foo fum'? */
  if (-1 != member(({"fee", "fie", "foe", "foo", "fum" }), verb))
  {
    gotit = 1;
    if (arg && strlen(arg))
      verb += " "+arg;
    if (!rc)
      this_player()->RegisterCmdFun("dofoo", verb);
    else
      dofoo(verb);
  }
  else
    this_player()->Set(P_FOOCOUNT, 0);

  return rc && gotit;
}

/*************************************************************************/
