
/*  NAME        : /command/mortal/pray.c                                   */
/*  DESCRIPTION : pray command for mortals, usage: pray <god> <message>    */
/*  CODER       : namhas                                                   */

#include <level.h>
#include <ansi.h>

main (string str)
{
    string god, msg;
    object ob;

    if (str)
    {
	if (sscanf (str, "%s %s", god, msg) == 2)
	{
	    write_file ("/log/prayers", ctime (time ()) + " :: " + this_player ()->query_name () +
	      " " + msg + " to " + capitalize (god) + "\n");

	    ob = find_player (god);

	    if (ob)
	    {
		if (ob->query_security() >= 31)
		{
		    tell_object (ob, "-----------------------------------------------------------------------------\n" +
		      "You hear " + this_player ()->query_name () + " praying your name and chanting: \"" + msg + "\"\n\n" +
		      "He has sacrificed items worth "+THIS->add_religion(ob->query_name(), -random(5))+" points and has alignment of " + (THIS->query_aligny() + THIS->query_alinx() / 2) + ".\n" +
		      "He has asked divine interventions 0 time(s). OBJ->\"" + file_name (environment (this_player ())) + "\"\n\n" +
		      "* reply to this prayer by using command \"rpray "+this_player()->query_name()+" [message]\", type\n" +
		      "  rpray without argument to see little help about special commands. if you\n" +
		      "  don't reply to this prayer in 5 minutes the player will receive \" Your \n" +
		      "  prayer remains unheard.\" message. \n" +
		      "-----------------------------------------------------------------------------\n");
		}
	    }
	    write ("You pray to " + C_BLD + capitalize (god) + C_NRM + ".\n");
	    call_out ("do_unheard", 60 * 5, this_player ());
	    return 1;
	}
    }
    else
    {
	write ("usage: pray <name> [message]\n\n" +
	  "This command is used for praying help from the gods and interacting\n" +
	  "with them. Do not use this frequently or you will get the gods angry\n" +
	  "and there is always danger to get zapped by the gods if you disturb\n" +
	  "them. If you report or do something which the certain god likes he\n" +
	  "can give you special awards, also if you're sacrificed enough stuff\n" +
	  "to the altar you can use pray command to request divine interventions\n" +
	  "to help you in your quest. It is rumoured if you are in the certain\n" +
	  "god's temple, you'll get better chance to contact that god. There is\n" +
	  "no list of all gods but every god you can worship should have own\n" +
	  "temple, maybe that will help you looking for your god?\n\n" +
	  "example: pray namhas Help me o' mighty, I am trapped in a buggy room.\n");

	return 1;
    }
}

do_answered ()
{
  remove_call_out ("do_unheard");
}

do_unheard (object ob)
{
    tell_object (ob, "Your prayer remains unheard.\n");
    remove_call_out ("do_unheard");
}

query_help()
{
  return "This command is used for praying help from the gods and interacting" 
  + " with them. Do not use this frequently or you will anger the gods" 
  + " and there is always danger to get zapped by the gods if you disturb" 
  + " them. If you report or do something which the certain god likes he"
  + " can give you special awards, also if you have sacrificed enough stuff" 
  + " to an altar you can use pray command to request divine interventions" 
  + " to help you in your quest. It is rumoured if you are in the certain"
  + " god's temple, you'll get better chance to contact that god. There is" 
  + " no list of all gods but every god you can worship should have own"
  + " temple, maybe that will help you looking for your god?";
}

query_example()
{
return "pray namhas Help me o' mighty, I am trapped in a buggy room.";
}

query_synopsis()
{
  return "pray <name> <msg>";
}

query_author()
{
  return "namhas";
}

query_position ()
{
  return POS_RESTING;
}

