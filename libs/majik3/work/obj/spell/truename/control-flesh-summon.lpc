/* Coder : Harum */

do_success(object me, string target)
{
  
	object o, *all, *gods = ({});
	int i;

   	
	if (target && find_player(target)) 
		o = find_player(target);
		
	else 
	{
		all = users() - ({ THIS }) - all_inventory(ENV(THIS));
		for (i=0 ; i<sizeof(all) ; i++)
		{
			if (all[i]->query_security())
				gods += ({ all[i] });
		}
		all -= gods;
		if (all == ({})) 
			{
			message("spell", "You suddenly feel very lonely.\n", THIS);
			return 1;
			}
	
		o = all[random(sizeof(all))];
		
	}

	act(o, "$n starts to turn transparent. Few moments later, $n "
                     +"has vanished from your sight.", 0, o);

	message("spell" , "A reality before your eyes becomes distorted and for a short moment you feel sick. "
                 +"A second later you notice that the place has changed!\n", o);

	emote("An abrupt bright flash blinds your vision! "
                     +"A moment later you see $N standing before you..", me, o, ENV(me));
		
	

	o->move(ENV(me));
	o->force_us("look");
      	return 1;
    
}

do_failure(object me, string target)
{

  	if (target && find_player(target))
		message("spell", "You see a faint image of "
		+ find_player(target)->query_cap_name()+" but then it disappears.\n", THIS);

	else 
		message("spell", "You see a faint image of someone but then "
		+"it disappears.\n", THIS);
	
	message("spell", "You see a faint image of someone but then "
		+"it disappears.\n", ENV(THIS), ({THIS}));
	return 1;
}

query_offensive() { return 0; }
query_true_magick() { return 1; }
