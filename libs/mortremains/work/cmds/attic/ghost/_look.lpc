/* File:  /cmds/std/_look.c
   Creator:	Matt. D. Robinson (Yakker/Regret@TMI) 1991
   Updated:	Help added by Brian (1/28/92)
		Rewritten by Adam Beeman (Buddha@TMI) 6/25/92
		Light handling by Steven Schmidt (Mobydick@TMI) 11/9/92
		Contents processing routines, light handling updated,
		   and infravision by Glenn Ferguson (Watcher@TMI) 1/29/93
		Got querying item_desc to work properly if the
		   description was a function by Grendel @ TMI-2,
		   10 August 1993
		Rewritten and door/exit suppression added by Austin H.
		   Ziegler (Fantome@TMI) 11 August 1993

	This code allows a user to "look" in a room, or at a specific
object in the user's inventory or environment.
*/

#include <config.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

// If #BLOCK_ATTACK is defined, then players in combat will lose one
// attack if they look at something, taking attention away from the
// opponent. If it's not defined, that won't happen.

//#define BLOCK_ATTACK 1

/* Contents display format flag:
	0 == standard look
	1 == line by line processed
	2 == processed linked together
*/
#define FLAG 1

// prototypes...
string look_in_room (object room, int flag);
varargs string look_at_item (string item, object user, string in_what);
string look_in_item (string item, object user);
string convert_number (int num);
string process_contents (mixed *inv, int flag);
string content_match (object what);

mixed *number;
object viewingOb, env, it;
#ifndef BLOCK_ATTACK
int Attacking;
#endif

/* cmd_look (string)
  this function 'look's in a room and handles the case of
whether it's just the room or a separate object */
int cmd_look (string str) {
  int oldStatus;   
  string tmp, tmp2;
  mapping exits, doors;
  mixed *hidden_exits, *hidden_doors;
   
  it = 0;
  viewingOb = this_player();
  env = environment (viewingOb);
   
/* standard TMI-2 look blocks for 2 seconds, but I don't like that,
   so we've got another option available on compile-time */
#ifndef BLOCK_ATTACK
  Attacking = ((viewingOb->query_attackers()) ? 1 : 0);
#endif

/* Check to see if we have an argument list.  If we do, see if
we're trying to look at a particular object.  If so, get the
object's description.  Otherwise, ask the room for its description.
*/
  
// are we looking at our immediate environment?
  if (!str || !stringp (str)) {
    // do we have an environment?  If not, write the default message
    if (!env) {
      write ("There is nothing to see here.\n");
#ifdef BLOCK_ATTACK
      viewingOb->block_attack (2);
#endif
      return 1;
    }
/*
write (LANGUAGE_D->garble_string(look_in_room (env, (int)viewingOb->query_temp ("force_to_look")),"orcish")+"\n") ;
*/
    write (look_in_room (env, (int)viewingOb->query_temp ("force_to_look")));
#ifdef BLOCK_ATTACK
    viewingOb->block_attack (2);
#endif
    return 1;
  }

// are we looking at something in a container?
  if (sscanf(str, "at %s in %s", tmp, tmp2) == 2) {
    // we're looking inside a container
    // blocking a look in a locked/opaque container doesn't work yet. -- Fantome
    // hopefully will work soon
#ifndef BLOCK_ATTACK
    if (Attacking) {
      write ("You are too busy to get a detailed look at that!\n");
      return 1;
    }
#endif
    write (sprintf ("%-=75s", look_at_item (tmp, viewingOb, tmp2)));
    return 1;
  }

// are we looking at an object?
  if (sscanf(str, "at %s", tmp)) {
    write (sprintf ("%-=75s", look_at_item (tmp, viewingOb)));
    return 1;
  }
// are we looking in an object?
  if (sscanf(str, "in %s", tmp)) {
#ifndef BLOCK_ATTACK
    if (Attacking) {
      write ("You are too busy to get a detailed look at that!\n");
      return 1;
    }
#endif
    write (sprintf ("%-=75s", look_in_item (tmp, viewingOb)));
    return 1;
  }
// are we looking in the room?
  if (env) {
    exits = env->query ("exits");
    doors = env->query ("doors");
    hidden_exits = env->query ("exit_suppress");
    hidden_doors = env->query ("door_suppress");
    if (mapp (exits) && member_array (str, keys (exits)) != -1) {
      if (doors && doors[str]) {
	if (((!intp (hidden_doors) || (int)hidden_doors[0] != 1) ||
	    (!pointerp (hidden_doors) ||
		member_array (str, hidden_doors) == -1))
	    && doors[str]["status"] != "open") {
	  write ("The door is closed.\n");
#ifdef BLOCK_ATTACK
	  viewingOb->block_attack(2);
#endif
	  return 1;
	}
      }
      if ((!pointerp (hidden_exits) ||
		member_array (str, hidden_exits) == -1) ||
		(!intp (hidden_exits) || (int)hidden_exits[0] != 1)) {
	env = find_object_or_load (exits[str]);
	write (look_in_room (env, 0));
#ifdef BLOCK_ATTACK
	viewingOb->block_attack(2);
#endif
	return 1;
      }
    }
  }
   
  cmd_look (sprintf ("at %s", str));
  return 1;
}

int can_see (object who, object what) {
  int invis;

  if (!(what->query ("short")))
    return 0;
  invis = what->query ("invisible");
  if (!invis)
    return 1; 
  if (invis == 1 && wizardp (what))
    return 1;
  if (invis == 2 && adminp(what->query ("name")))
    return 1;
  return 0;
}

int can_see2 (object what, object who) {
  return can_see (who, what);
}

string living_description (object ob) {
  object *inv;
  int i;
  string a1, a2, tmp, reg, race, raceat, short, gender, genat;
   
  reg = (string)ob->query ("long");
  if (!reg)
    reg = "";
   
  race = (string)ob->query ("race");
  raceat = article (race) + " " + race;
  gender = (string)ob->query ("gender");
  genat = ((viewingOb == ob) ? "You are"
			      : capitalize (subjective (gender)) + " is");
  
  i = sizeof (inv = all_inventory(ob));
  while (i--)
    if (tmp = inv[i]->query ("extra_look")) {
      while (sscanf(tmp, "%s$N%s", a1, a2) > 1)
        tmp = sprintf ("%s%s%s", a1, ob->query ("cap_name"), a2);
      reg += tmp;
    }

  if (stringp (race) && race != "")
    reg = sprintf ("%s%s %s.\n", reg, genat, raceat);
   
#ifndef BLOCK_ATTACK
  if (!Attacking) {
#endif
  inv = filter_array (inv, "can_see2", this_object(), viewingOb);
  i = sizeof (inv);
  if (i) {
    reg = sprintf ("%s %s carrying:\n", reg, genat);
    while (i--) {
      short = (string)inv[i]->query ("short");
      if (short)
	reg = sprintf ("%s  %s%s%s.\n", reg, short,
		(inv[i]->query ("equipped") ? " (equipped)" : ""),
		(inv[i]->query ("wielded") ? " (wielded)" : ""));
    }
  } else
    reg = sprintf ("%s%s empty handed.\n", reg, genat);
#ifndef BLOCK_ATTACK
  }
#endif
  return reg;
}

varargs
string item_description (string str, object user, int infra, string in_what) {
  object inob;
  mapping items, doors;
  string tmp, ret, dir, foo;
     
  if (str == "me")
    str = (string)viewingOb->query ("name");
   
  if (str == "door" || sscanf (str, "%s door", dir)) {
#ifndef BLOCK_ATTACK
    if (Attacking)
      return "You are too busy to get a detailed look at that!\n";
#endif
    if (user && environment (user))
      doors = environment (user)->query ("doors");
    if(!doors || !sizeof(doors))
      return "You don't see any doors here.\n";
      
    if (!dir) {
      if (sizeof (doors) > 1)
	return "Which door do you wish to look at?\n";
      dir = keys (doors)[0];
    }
      
    if (infra)
      return "That door gives off no heat pattern.\n";
      
    if (!doors[dir])
      return sprintf ("There is no door in the %s direction.\n", dir);

    if (!doors[dir]["desc"])
      tmp = "";
    else
      tmp = sprintf ("%s.\n", capitalize(doors[dir]["desc"]));
      
    if (doors[dir]["status"])
      tmp = sprintf ("%sThe %s door is %s.\n", tmp, dir, doors[dir]["status"]);
      
#ifdef BLOCK_ATTACK
    viewingOb->block_attack (2);
#endif
    if (!tmp || tmp == "")
      return sprintf ("There is nothing special about the %s door.\n", dir);
    else
      return tmp;
  }
   
#ifndef BLOCK_ATTACK
  if (!Attacking) {
#endif
  if (in_what) {
    inob = present (in_what, user);
    if (!inob && env)
      inob = present (in_what, env);
    if (inob) {
      it = present (str, inob);
      if ((int)inob->query_is_closed() && (int)inob->query ("opaque"))
	return "Just how do you propose looking in a closed container?\n";
    }
  }
#ifndef BLOCK_ATTACK
  }
#endif
  if (!it)
    it = present (str, user);
#ifndef BLOCK_ATTACK
  if (!Attacking) {
#endif
  if (!it && env)
    it = present(str, env);
#ifndef BLOCK_ATTACK
  }
#endif
   
  if (it && !can_see (viewingOb, it))
    return "I don't see that here.\n";
   
  if (infra)
    if (living (it) || it->query ("hot"))
      return "Your infravision shows a bright heat pattern.\n";
    else
      return "Your infravision shows no heat pattern.\n";
   
  if (it) {
    if (living (it))
      ret = living_description (it);
    else
      ret = (string)it->query ("long");
  } else {
#ifndef BLOCK_ATTACK
    if (Attacking)
      return "You are too busy to get a detailed look at that!\n";
#endif
    if (env) {
/* okay, this is the way to get things built into the room.
   assuming that we _can_ look at objects, check for room-defined
   dummy items.  Fix to item_desc of @@fun by Grendel.*/
      tmp = env->query ("item_desc/" + str);
      if (tmp)
	ret = tmp;
      if (!ret) {
        tmp = env->query ("item_func/" + str);
	if (tmp) {
	  (string)call_other (env, tmp);
#ifdef BLOCK_ATTACK
	  viewingOb->block_attack (2);
#endif
	  return "";
	}
      }
    } else
      return "There is nothing to see here.\n";
  }

  if (!ret || ret == "")
    return "I don't see that here.\n";

  if (it) {
    if (it != viewingOb) {
      if (living (it))
	message ("tell_object",
		sprintf ("%s looks at you.\n", user->query ("cap_name")),
		it);
      foo = it->query("cap_name");
      if (!foo)
	foo = it->query("short") ;
      if (!foo)
	foo = "something";
    } else
      foo = sprintf ("%sself", objective ((string)viewingOb->query ("gender")));
      
    message ("say", sprintf ("%s looks at %s.\n", user->query ("cap_name"),
		(living (it) ? foo : lower_case (foo))), environment (user),
		({ user, it }));
  } else
    message ("say", sprintf ("%s looks at %s.\n", user->query ("cap_name"),
		str), environment (user), user);
#ifdef BLOCK_ATTACK
  viewingOb->block_attack (2);
#endif
  return ret;
}

varargs string look_at_item (string str, object user, string in_what) {
//Check if the user is blind.
  if ((int)user->query ("blind"))      
    return "You are blind and cannot see.\n";
   
//Check to see if the user can see.
  if ((int)user->query ("vision"))
    if (!undefinedp (in_what))
      return item_description (str, user, 0, in_what);
    else
      return item_description (str, user, 0);
   
//Check to see if user has infravision capabilities
  if ((int)user->query("infravision"))
    if (!undefinedp (in_what))
      return item_description (str, user, 1, in_what);
    else
      return item_description (str, user, 1);
   
//Guess there is no light here, then.
  return "It is dark and you can't see a thing.\n";
}

string lit_room_description(object room, int infra, int flag);

varargs string look_in_room (object room, int flag) {
//Check to see if the user is blind
  if (viewingOb->query("blind"))
    return "You are blind and cannot see.\n";

//Check to see if the room can be seen.
  if (room->query("no_vision"))
    return (string)room->query("no_vision") ;
   
//Check to see if the user can see within the room.
  if (viewingOb->query ("vision"))
    return lit_room_description (room, 0, flag);
   
//Check to see if the user has infravision
  if (viewingOb->query("infravision"))
    return lit_room_description (room, 1, flag);
   
//Looks like there isn't any light here.
  return "It is dark and you can't see a thing.\n";
}

int suppress_filt (string exit, string *suppress) {
  if (member_array (exit, suppress) == -1)
    return 1;
  return 0;
}

string lit_room_description (object room, int infra, int flag) {
  string long, str, tmp, *dirs;
  object *contents, *live;
  int i;
  mixed *suppress;
  mapping exits, doors ;
   
/*  Check the player's "brief" property and get either the long or short
description as is appropriate.  If infravision is being used, minimal
details of the surroundings are given. */
   
  if (infra)
    long = "";
  else
    if (flag && viewingOb->query ("brief")) {
      long = sprintf ("%s\n", room->query ("short"));
    } else {
#ifdef LONG_WITH_SHORT
      long = sprintf ("%s\n%s", room->query ("short"), room->query ("long"));
#else
      long = room->query ("long");
#endif
      if (!flag && room->query ("outside"))
        long += WEATHER_D->query_weather_msg();
    }

  if (!long)
    long = "";

/* Query a room's "door_suppress" property to see what, if any, doors
and their statuses will be displayed in the room. */

  suppress = room->query ("door_suppress");
  if (!suppress || pointerp (suppress)) {
    doors = room->query ("doors");
    if (doors && !infra) {
      dirs = keys (doors);
      if (pointerp (suppress))
	dirs = filter_array (dirs, "suppress_filt", this_object(), suppress);
      i = sizeof (doors);
      while (i--)
	long = sprintf ("%s The %s door is %s.\n", long, dirs[i],
		doors[dirs[i]]["status"]);
    }
  }
 
/* Query a room's "exit_suppress" property to see what, if any, obvious
exits will be displayed or not. */

  suppress = room->query ("exit_suppress");
  if (!suppress || pointerp (suppress)) {
    exits = room->query ("exits");
    if (exits)
      dirs = keys (exits);
    if (pointerp (suppress))
      dirs = filter_array (dirs, "suppress_filt", this_object(), suppress);
    i = sizeof (dirs);
    switch (i) {
      case 0: {
	long += ((infra) ? "\tYou cannot detect any obvious exits.\n"
			 : "\tThere are no obvious exits.\n");
	break;
      }
      case 1: {
	long = sprintf ("%s\tThe only obvious exit%s is %s.\n", long,
		((infra) ? " you can detect" : ""), dirs[0]);
	break;
      }
      case 2: {
	long = sprintf ("%s\t%sbvious exits %sare %s and %s.\n", long,
		((infra) ? "The only o" : "O"),
		((infra) ? "you can detect " : ""), dirs[0], dirs[1]);
	break;
	}
      default: {
	long = sprintf ("%s\t%sbvious exits %sare %s, and %s.\n", long,
		((infra) ? "The only o" : "O"),
		((infra) ? "you can detect " : ""),
		implode (dirs[0..(i-2)], ", "), dirs[i-1]);
	}
      }
  }
 
// Process inventory of the room/object being examined
  contents = all_inventory (room);
   
//  Check for infravision flag and living heat patterns
  if (infra) {
    i = sizeof (live = filter_array (contents, "filter_living", this_object()));
    switch (i) {
      case 0: {
	long += "Your infravision shows no other heat patterns.\n";
	break;
      }
      case 1: {
	long += "Your infravision shows only one heat pattern.\n";
	break;
      }
      default: {
	long = sprintf ("%sYour infravision shows %s heat patterns.\n",
		long, convert_number (i));
	break;
      }
    }
    return long;
  }
   
  if (!FLAG) {
    i = sizeof (contents);
    while (i--) {
      tmp = (string)contents[i]->query ("short");
      if (contents[i] != viewingOb && tmp && tmp != "")
	long = sprintf ("%s %s\n", long, capitalize (tmp));
    }
  } else
    long += process_contents (contents, FLAG);
   
  return long;
}

// Filter out all objects without a possible heat pattern
int filter_living (object what) {
  if (what == viewingOb || (userp (what) && !interactive (what)))
    return 0;
  return (living (what) && !what->query ("cold") || what->query ("hot"));
}

string look_in_item (string tmp, object user) {
  string tmp2;
  object *contents;
   
  it = present (tmp, user);
  if (!it && env)
    it = present (tmp, env);

  if (living (it))
    return "You must be kidding me!  Look INSIDE a living being?\n";

  if ((int)it->query_is_closed() && (int)it->query ("opaque"))
    return "Just how do you propose looking in a closed container?\n";

  if (it) {
// in our hands or in our environment.
    contents = all_inventory (it);
    if (!contents) {
      return "You don't see anything inside.\n";
    } else {
      tmp2 = process_contents (contents, FLAG);
      if (tmp2 == "")
	return "You don't see anything inside.\n";
      return sprintf ("%s contains:\n%s\n", capitalize (tmp), tmp2);
    }
  }
// this is where we could look for things in the room's properties.
  return "Look in what?\n";
}

string process_contents (mixed *contents, int flag) {
  mapping match;
  mixed *inv, *ninv;
  string tmp, ret;
  int loop, i; 
   
  ret = "";
  inv = contents;
   
// Remove all objects with no short desc or command initiator
  inv = filter_array (inv, "clean_objects", this_object());
   
// Compile list of objects with matching short descriptions
  match = unique_mapping (inv, "query", "short");
  ninv = keys (match);
   
//Loop through object contents and place them into a display string
   
  loop = sizeof (ninv);  
  while (loop--) {
/* older code handled living cases separately.  taken out by Mobydick @ TMI-2
on 10 April 1993, kept out by Fantome 24 July 1993 */
    i = sizeof (match[ninv[loop]]);
    if (i > 1)
      tmp = sprintf ("%s %s", convert_number (i), pluralize (ninv[loop]));
    else tmp = ninv[loop];
      
    if (flag == 1)
      ret = sprintf ("%s  %s\n", ret, capitalize (tmp));
    else
      ret = sprintf ("%s%s%s", ret, tmp,
		((loop > 1) ? ", " : ((!loop) ? "." : ", and ")));
  }
   
  if (flag == 2 && ret != "")
    ret = wrap (sprintf ("You see %s", ret));
   
  return ret;
}

// Remove all invisible objects from the room's content's list
int clean_objects (object what) {
  if (!can_see (viewingOb, what))
    return 0;
  return (((string)what->query ("short") && what != viewingOb) ? 1 : 0);
}

// Compare each object's short desc with processing short desc
string content_match (object what) {
  return (string)what->query("short");
}

// Convert numeric value to word format if below 21
string convert_number(int num) {
  if (!number)
    number = ({
"one", "two", "three", "four", "five", "six", "seven", "eight",
"nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
"twenty" });
   
  return ((num > 20) ? "many" : number[num - 1]);
}

int help() {
  write (@Help
Command: look
Syntax: look [at object]

If no object is specified this command makes you look
around the room.  If an object is specified it lets you
examine the object more closely.
Help
);
  return 1;
}
