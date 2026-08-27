/* Detect alignment. For wizards.
   Made by Baldrick July 1993.
   This spell detects the alignment of a player or NPC.
   Have fun with it.
*/
/*** Know Alignment ****/
/*** modified for FR usage by Eerevann ***/

/*** Sphere MageDivination ****/
/*** Level 2nd ***/

#define SP_NAME "Know Alignment"
#define GP_COST 4

mixed spell(string str, int cast);


/*** Help file here ***/
string help() {
   return
   "\n\n"
   "Spell Name: "+SP_NAME+"\n"
   "Sphere:  Divination\n"
   "Level:  2nd\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
   "   This spell detects the alignment of a player or NPC.\n";
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
    return ("You know this is not a living object.\n");

  if (cast && (int)this_player()->adjust_gp(-(GP_COST)) < 0)
  return "You are too mentally drained to cast Know Alignment.\n";
  
 write("You cast Know Alignment on "+
        capitalize(str) + ".\n");
  say(this_player()->query_cap_name()+" casts some sort of divination "
       "magic.\n");
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
      return ("You shiver at its evilness.");

    default:
      return (" BooHOO"+alignment);
    }

  return 1;
}
