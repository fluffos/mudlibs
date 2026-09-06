
/* Bleeding Daemon for TTH  */

mapping bleed;

status add_bleeder(object who,int bleed_length)
{
    if (!bleed)
    {   
	bleed = ([]);
	remove_call_out("bleeding");
	call_out("bleeding",5);
    }
    bleed += ([ who : bleed_length; time() ]);
return 1;
}
/* in case someone codes band-aids? :) */
status remove_bleeder(object who, int silently)
{
    if (!silently)
    {
	who->tell_me("You finally stop bleeding!");
	environment(who)->tell_me(who->query_name() + " stops bleeding!",who);
    }
    m_delete(bleed,who);
    return 1;
}

status clean_bleeders()
{
    int i;
    object *bleeders;

    bleeders = m_indices(bleed);
    for(i=0;i < sizeof(bleeders);i++)
    {
	if (bleeders[i]->is_ghost() || bleeders[i]->query_dead())
	{
	    remove_bleeder(bleeders[i],1);
	}
	else
	{
	    if ((time() - bleed[bleeders[i],1]) >= bleed[bleeders[i],0])
	    {   
		bleeders[i]->tell_me("The bleeding slows to a trickle.");
		environment(bleeders[i])->tell_here(bleeders[i]->query_name() +
		  " appears to have stopped bleeding.",bleeders[i]);
		m_delete(bleed,bleeders[i]);
	    }
	} 
    }
    m_delete(bleed,0);
    return 1;
}

varargs status bleeding(int dmg)
{
    object *bleeders;
    string bleed_msg, *bleed_mesg;
    int i;

    clean_bleeders();

    bleeders = m_indices(bleed);
    for(i=0;i < sizeof(bleeders);i++)
    {
	if (bleeders[i])
	{
	    bleed_msg = ({
	      "You wounds bleed uncontrollably!#" + bleeders[i]->query_name() +
	      "'s wounds bleed uncontrollably!",
	      "You feel light-headed as blood rushes from your wound!#" +
	      bleeders[i]->query_name() + " looks pale, probably because of " +
	      "all the blood loss!",
	      "Your wound makes a sucking noise as blood flows from it!#" +
	      bleeders[i]->query_name() + "'s wound makes a cool sucking " +
	      "noise as blood rushes from it!",
	      "Blood oozes from your wound!#Blood oozes from " +
	      bleeders[i]->query_name() + "'s wound!",
	      "Sticky red blood spurts from your wound and gets all over you!#"+
	      "Sticky red blood spurts all over the place from " +
	      bleeders[i]->query_name() + "'s wound!",
	      "Blood sprays from your gaping wound.  You almost slip in it!#"+
	      bleeders[i]->query_name() + " almost slips in the spray of " +
	      " blood coming from " + bleeders[i]->query_possessive() + 
	      " wound!",
	    })[random(6)];
	    bleed_mesg = explode(bleed_msg,"#");
	    bleeders[i]->tell_me(bleed_mesg[0]);
	    environment(bleeders[i])->tell_here(bleed_mesg[1],bleeders[i]);
	    if (!dmg)
		dmg = bleeders[i]->is_npc() ? 70 + random(75) :
		30 + random(11);
	    random(10)+20;
	    bleeders[i]->hit_player(dmg);
	}
    }
    clean_bleeders();
    call_out("bleeding",8 + random(10));
    return 1;
}

object *query_bleeders()
{
    return m_indices(bleed);
}




