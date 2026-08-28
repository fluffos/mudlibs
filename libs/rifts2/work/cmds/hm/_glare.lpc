//      /bin/dev/_glare.c

//      from the Darkemud Mudlib

//      force a low level player to flee

//      created by Shadowraith the Damned 960921



#include <std.h>

#include <security.h>



inherit DAEMON;



int cmd_glare(string str) {

    string who;

    object ob;

    int x, att;


    if(!str || ((sscanf(str, "at %s", who) != 1) &&

      (sscanf(str, "%s", who) != 1))) {

        notify_fail("Correct syntax: <glare at [who]>\n");

        return 0;

    }

    if(this_player()->query_invis()) {

    	notify_fail("You cannot glare at someone while invisible.\n");

    	return 0;

    }

    if(sizeof(this_player()->query_attackers())>0) {
        notify_fail("You cannot glare while in combat.\n");
        return 0;
    }
   ob = find_living(who);

    if(!present(ob,environment(this_player()))) {

        notify_fail("There is no-one named "+str+" present.\n");

        return 0;

    }

    if(ob==this_player()) {

    	notify_fail("You become cross-eyed trying to glare at yourself.  You have a headache.\n");

    	return 0;

    }

    if(wizardp(ob) && !wizardp(this_player())) {

    	tell_room(environment(ob),capitalize(this_player()->query_name())+" flees"+

    	    " in terror after foolishly trying to cower a God.\n");

    	notify_fail("You start to glare at a God when the foolishness of your action causes you to flee.\n");

      catch(x=(int)this_player()->run_away());

      catch(x=(int)this_player()->run_away());

      return 0;

    }

    if(ob->is_player() && (!high_mortalp(this_player()) && !wizardp(this_player()) )) {

    	  tell_object(ob,capitalize(this_player()->query_name())+" glares balefully at you.\n");

        notify_fail("You glare at "+capitalize(who)+"!\n");

        return 0;

    }

    if(((this_player()->query_level() - 25) < ob->query_level()) || (ob->query_level() > 9) && !wizardp(this_player()) ) {

        	notify_fail("You fail to force "+capitalize(who)+" to flee.\n");

        	tell_object(ob, "You stand your ground under "+capitalize(this_player()->query_name())+

        	        "'s withering glare.");

        	return 0;

        }

    if(member_group(geteuid(ob), "superuser")) return 1;

    seteuid(UID_FORCE);

    seteuid(UID_LOG);

    seteuid(getuid());

    if (!wizardp(this_player())) {

    	tell_object(ob, capitalize(this_player()->query_name())+" glares at you"+

                " with such menace that you are compelled to flee.");

      message("my_action", "You intimidate "+capitalize(who)+" into fleeing.",

               this_player());

      catch(x=(int)ob->run_away());

      return 1;         

    }

    tell_object(ob, capitalize(this_player()->query_name())+" turns the"+

                " divine might of his gaze upon you...you flee in terror.\n");

    message("my_action", "You cause "+capitalize(who)+" to flee in terror.\n",

            this_player());

    catch(x=(int)ob->run_away());

    catch(x=(int)ob->run_away());

    return 1;

}



void help() {

    message("help",

      "Syntax: <glare (at) [who] >\n\n"

      "Forces a player or monster to flee. "

      "Only a High Mortal may force someone to flee. Do"

      " not abuse this power.", this_player()

    );

}

