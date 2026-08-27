/* This spell is a spell for the guildmaster so he can administrate his guild
it has wery dirty code, but it was needed (mostly because of my inexperience)
needs some changes in the messages.
Baldrick 
 * Ok, moving it to spells so the Leader can use it. 
 * Should do something with it tho..
*/

/* Syntax for adding this spell :
   add_spell("", path+name, "spell")
path+name should be understood :=) */

mixed cast_spell(string target);

int make_member(string target)
{
object goal;


if ((target== "") || (target== " "))
 {
  notify_fail ("You need to tell who you will make a member of " 
               "The Directorate.\n");
  return 0;
 } /* if */
else 
 {
  if (goal=find_player(target))
/* this test (over) gives a problem, it makes it possible to cast the spell at a player on the other side of the realms, not good. */
/*  if (present(target))  */
  {
  if (goal->query_property("directorate"))
     {
      notify_fail("This person is already a member of The Directorate.\n");
      return 0;
     } /* if query... */
    else
      {
       tell_object(goal, "A tingling surges through your body and you "
                         "feel the power of a member of your guild.\n"
         "It's your guildmaster.\n"
         "He tells you: You are now a member of The Directorate, use your " 
         "membership wise.\n\n");
       tell_object(this_player(), goal->query_cap_name()+" is now a " 
                   "member of The Directorate.\n\n");
       goal->add_property("directorate", 1);
       return 1;
      } /* else */
   } /* if  goal....*/
   else 
    {
     notify_fail ("You cannot find "+target+".\n");
     return 0;
    } /* else if (goal==...*/
   } /* else if (!target) */
} /* make_member... */

mixed ban_member(string target)
{
object goal;

if ((target== "") || (target== " "))
 {
  notify_fail ("You need to specify who you will ban.\n");
  return 0;
 } /* if */
else
 {
  if (goal=find_player(target))
  {
    if (!goal->query_property("directorate"))
      {
       notify_fail (goal->query_cap_name()+" is not a member of " 
                    "The Directorate.\n");
       return 0;
      } /* if  goal->....*/
     else
      {
       tell_object(goal, "A tingling surges through your body and you "
                         "feel the power of a member of your guild.\n"
         "It's your guildmaster.\n"
         "He tells you: " 
         "Your status as a member of The Directorate has been "
                         "removed. You know why.\n\n");
       tell_object(this_player(),goal->query_cap_mane() +" has been banned.\n");
       goal->remove_property("directorate", 0);
       return 1;
       } /* else if (goal->... */ 
   } /* if (goal=... */
   else
    {
     notify_fail ("You cannot find "+target+".\n");
     return 0;
    } /* else if (goal==...*/
   } /* else if (!target) */
} /* ban_member */

int help ()
/* the help message */
  {
  write ("Help :\n " 
         "Usage: cast admin [make / ban] person."
      "\n");
  return 1;
  } /* help */

mixed cast_spell (string yoman)
  {
  string target;
  string job;
  /* first the test for one parameter commands */
  if (!yoman)
     {
     notify_fail("you have to state what you want.");
     return 0;
     } /* if (!yoman....*/
  else
    {
    if (yoman == "help")
      {
      help ();
      return 1;
      } /* If (yoman == "help"... */} /* else if (!yoman ) */
 /* this is going to look stupid.not */
 if (!sscanf(yoman,"%s %s",job,target))
    {
    notify_fail("You need to state what/who you want to admin. " 
                " (try cast ... help)\n");
    return 0;
    } /* if (!sscanf..... */
  else
    {
    switch (job)
      {
      case "make" :
        if (make_member(target)) return 1;
        break;

      case "ban" :
        if (ban_member(target)) return 1;
        break;
 
      default :
        notify_fail("you failed to use your spell. Use spell... help \n");
        break;
      } /* switch */
    return 0;
  } /* else */
} /* spell */

