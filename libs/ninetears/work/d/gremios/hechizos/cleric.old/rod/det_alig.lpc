#define SPELL_COST 20
 
mixed spell(string str, int cast);

/* Detect alignment. For priests.
   Made by Baldrick July 1993.
   This spell detects the alignment of a player or NPC.
   Have fun with it.
*/

string help() 
  {
  return
    ("This spell detects the alignment of a player or NPC.\n");
  }
 
int cast_spell(string str) 
  {
  mixed ret;

  ret = spell(str, 1);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int cast) 
  {     
  mixed ob;
  int alignment;

  if (!str || str == "")
    return "You feel nothing.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Where is " + capitalize(str) + " ?\n";
  if (!living(ob))
    return ("You know this is a living object.\n");

  if (cast && (int)this_player()->adjust_gp(-(SPELL_COST)) < 0)
    return "Too low on power.\n";
  
  write("You call upon the gods to help you detect the alignment of " +
        capitalize(str) + ".\n");
  alignment = ob->query_al();
  switch (alignment)
    {
    case -5000.. -250:
      return ("You feel this is a really good person.\n");

    case -249 .. -50:
      return ("You feel this is a good person.\n"); 

    case -49 .. -1:
      return ("You can't really decide, it is too weak.\n");

    case 0:
      return ("This is really neutrality.\n");

    case 1 .. 49:
      return ("You can't really decide, it is too weak.\n");

    case 100 .. 250:
      return ("You feel the evilness of this creature.\n");

    case 251 .. 400:
      return ("You fell this creature is really evil.\n");

    case 401 .. 5000:
      return ("You shrug over this evilness.");

    default:
      return (" BooHOO"+alignment);
    }

  return 1;
}
