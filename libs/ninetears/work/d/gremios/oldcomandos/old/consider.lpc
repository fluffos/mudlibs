/* The consider command. Taken out from player.c to save memory 
 * Baldrick Jan '94
 * Has to be balanced to consider AD&D levels, not DW levels..
 *
 * Small change by Aragorn (capitalized() output)
 */


/*   Balancing + some fixing to new system done by Manshoon, Nov 8 1994.   */

int consider(string str,object x) 
  {
  object *obs,me;
  int i, ok, level, dif;

  if(x) me = x;
  else me = this_player();

  if (!str) {
    tell_object(me,"Syntax: consider <monster>\n");
    return 0;
  }
  str = lower_case(str);
  if (str == "all" || str[0..0] == "0")
  {
     tell_object(me,"Consider the whole world?! Think not.....\n");
     return 1;
  }
  obs = find_match(str, environment(me));
  if (!sizeof(obs)) 
  {
    tell_object(me,"You need to consider someone who exists.\n");
    return 1;
  }
  level = (int)me->query_level();
  for (i=0;i<sizeof(obs);i++) 
  {
    if((int)obs[i]->query_creator() )
    {
        tell_object(me,"Attacking an immortal would be ...... unwise.\n.");
	ok = 1;
	continue;
    }
    // Fix by wonderflug, dec '95.  Tells you if you're hidden or not.
    if ( obs[i] == me )
    {
      tell_object(me, "Why would you consider attacking yourself?\n");
      continue;
    }
    if (!living(obs[i]))
      continue;
    ok = 1;
    dif = (int)obs[i]->query_level() - level;
    if(dif > 50 )
    {
       tell_object(me,"Don't even think about attacking "+obs[i]->short()+"!.\n");
       continue;
    }
    if (dif > 10) {
      tell_object(me,"You would have to be moderately insane to attack "+
            obs[i]->short()+".\n");
      continue;
    }
    if (dif < -10) {
    	tell_object(me,"You could kill "+obs[i]->short()+" with a needle!\n");
	continue;
    }
    if (level > 13) {

		    // dif is now  -10...10
   dif += 10;       // dif is now between 0...20
   dif /= 2;        // dif is now between 0...10
   	


      // Fix by Aragorn, capitalized the short
     tell_object(me,capitalize((string)obs[i]->short())+({ " is too weak to bother attacking.\n",
                               " is a lot weaker than you are.\n",
                               " is much weaker than you are.\n",
                               " is weaker than you are.\n",
                               " is slightly weaker than you are.\n",
                               " is about equal with you.\n",
                               " is slightly tougher than you are.\n",
                               " is tougher than you are.\n",
                               " is much tougher than you are.\n",
                               " is a lot tougher than you are.\n",
                               " is into the 'don't think about it' region.\n"
                              })[dif]);

	} else {   // if level is less than 14

	dif += 10;	// 0...20
	dif /=  5;	// 0...4

    tell_object(me,capitalize((string)obs[i]->short())+({ " is too weak to bother attacking.\n",
                               " is a lot weaker than you are.\n",
                               " is about equal with you.\n",
                               " is a lot tougher than you are.\n",
                               " is into the 'don't think about it' region.\n"
                              })[dif]);

		}  // end else
  }
  if (!ok) {
    tell_object(me, "You cannot consider that.\n");
    return 1;
  }
  return 1;
}
