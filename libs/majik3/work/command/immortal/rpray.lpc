
/*  NAME        : /command/immortal/rpray.c                                */
/*  DESCRIPTION : rpray command for immortals, used when responsing prays  */
/*  CODER       : namhas                                                   */

#include <level.h>

#define CAP_NAME capitalize (this_player ()->query_name ())

main (string str)
{
    string mortal, msg;
    object ob;

    if (str && sscanf (str, "%s %s", mortal, msg ) == 2)
    {
	ob = find_player (mortal);

	if (ob)
	{
	    if (this_player ()->query_security() >= 31)
	    {
              if (ob->add_religion(THIS->query_name(), 0) < 0)
                tell_object (THIS, ob->query_cap_name() +
                  " isn't worthly enough to receive aid from you.\n");

		if (msg == "punish")
		{
		    tell_object (ob, CAP_NAME +
		      " stares at you with hatred and advances menacingly.\n\n");
		    if (random (100) < 50)
		    {
			tell_object (ob, "You hear a booming voice in your mind: " +
			  "\"Mortal, ye art a pest.\"\n");
		    }
		    else
		    {
			tell_object (ob, "You hear a booming voice in your mind: " +
			  "\"I hereby punish thee, puny mortal!\"\n");
		    }
		    if (this_player ()->query_al () > 350)
			tell_object (ob, "A bold of chilling energy HITS you!\n\n");
		    else
			tell_object (ob, "A bold of flaring fire HITS you!\n\n");

		    tell_object (ob, "You die.\n");

		    shout ("Info: " + capitalize (ob->query_name ()) + " is annihilated by the " +
		      "divine wrath of " + CAP_NAME + "\n");

                    ob->add_religion (THIS->query_name(), -50);
		    ob->die ();
		    write ("Mortal killed.\n");
		}
		else if (msg == "anger")
		{
                    ob->add_religion (THIS->query_name(), -25);
		    shout ("For some seconds the ground rumbles.\n");
		    write ("Done.\n");
		}
		else if (msg == "ignore")
		{
                    ob->add_religion (THIS->query_name(), -10);
		    tell_object (ob, "The gods seem to ignore you.\n");
		    write ("Done.\n");
		}
		else if (msg == "heal")
		{
                    ob->add_religion (THIS->query_name(), -5);
		    tell_object (ob, "You are healed by a golden light surrounding you.\n");
		    write ("Healed.\n");
		}
		else if (msg == "pleased")
		{
		    if (random (100) < 75)
			tell_object (ob, CAP_NAME + " seems to be very pleased with you.\n");
		    else if (ob->query_al () > 350)
		    {
                        ob->add_religion (THIS->query_name(), 5);
			tell_object (ob, "You feel inner peace.\n");
			ob->set_pow (ob->query_pow () + 1);
			ob->set_alignx (ob->query_al () + 100);
			write ("+1 POW +100 AL\n");
		    }
		    else
		    {
                        ob->add_religion (THIS->query_name(), 5);
			tell_object (ob, "You burn with anticipation of power.\n");
			ob->set_pow (ob->query_pow () + 1);
			ob->set_alignx (ob->query_al () - 100);
			write ("+1 POW -100 AL\n");
		    }
		    write ("Done.\n");
		}
		else
		{
		    tell_object (ob, "You hear a booming voice in your mind: \"" + msg + "\"\n");
		    write ("Done.\n");
		}
                "/command/mortal/pray"->do_answered();
		return 1;
	    }
	    else
	    {
		write ("No access.\n");
		return 1;
	    }
	}
	else
	{
	    write ("Player not found.\n");
	    return 1;
	}
    }
    else
    {
	write ("usage: rpray <name> [message/command]\n\n" +
	  "available commands (use all these cmds with care, all acts logged):\n\n" +
	  "punish        - punish player by killing mortal, use this with\n" +
	  "                care\n" +
	  "anger         - send standard anger message, send this if you aren't\n" +
	  "                pleased with that mortal\n" +
	  "ignore        - send \"The gods seem to ignore you\" message to the\n" +
	  "                mortal (the usual)\n" +
	  "pleased       - send standard pleased message, send this if you are\n" +
	  "                pleased with the mortal's act, little chance to award\n" +
	  "                pow points\n" +
	  "heal          - heal player and remove all special excepts, example\n" +
	  "                poison effects from the player, use this only if\n" +
	  "                you are pleased with that player, ie. he/she has\n" +
	  "                sacrificed enough stuff or something else\n" +
	  "\n" +
	  "or send the message, example \"rpray deicider Mortal, ye art a nuisance!\".\n");
    }
    return 1;
}
