#include "/sys/interactive_info.h"

#include <lord.h>
#include <room_defs.h>
#include <player_defs.h>
#include <conditions.h>
#include <guild.h>

/*
	Lord command:	summon
	Syntax:		summon <player>
	Conditions:
		User must be level 29 or above.
		User must be able to move.
		User must have required spell points.
		User must be in a location that allows teleport.
		Target must be user level or below.
		Target must be in a location that allows teleport.
	Effects:
		If sucessful, brings the targeted player to the
			users location.
*/

int
summon_cmd(string str)
{
    object target,here,there;
    string mname, tname, mposs, tposs, mpro, tpro;
    string tmp;
    status g;

    if (((int)TP->query_level() < 29) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: summon <player>.\n");
	return 0;
    }

    if (!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    tname = lower_case(str);
    target = find_player(tname);
    tname = capitalize(str);

    if(!target || !interactive(target) || !(there=environment(target)))
    {
	notify_fail("Cannot find player "+tname+" in the game.\n");
	return 0;
    }

    tname = (string)target->query_name();
    tposs = (string) target->Possessive();
    tpro = (string) target->Pronoun();
    mname = (string)TP->query_name();
    mposs = (string) TP->Possessive();
    mpro = (string) TP->Pronoun();

    if ((target->query_lord() > LL) && !(CODER))
    {
	notify_fail("You cannot summon higher players.\n");
	return 0;
    }

    if (target->query_coder_level() && !(CODER))
    {
	notify_fail("Sure we are going to allow you to summon coders.\n");
	return 0;
    }

    here = environment(TP);

    g = 0;

    // Added "|| !target->query(PLR_ALLOW_SUMMON)". I.e. no summon
    // if summontoggle is not on. Players think the victim is in
    // place that doesn't allow summon. And coders, keep your mouth
    // shut for once.
    if (there -> query(PREVENT_TELEPORT_FROM) ||
      (!g && !target->query(PLR_ALLOW_SUMMON)))
    {
	notify_fail(tname+" is currently in a place that doesn't allow summoning.\n");
	return 0;
    }

    if(target->query_ghost())
    {
	notify_fail(tname+" is dead.\n");
	return 0;
    }

    if(!interactive_info(target, II_IP_NUMBER))
    {
	notify_fail(tname+" is currently link-dead.\n");
	return 0;
    }

    if (here -> query(PREVENT_TELEPORT_TO))
    {
	notify_fail("You cannot summon anyone here.\n");
	return 0;
    }

    if(sscanf(object_name(here),"room/death/%s",tname) ||
      strstr(object_name(here), "areas/SUE/4_") >= 0)
    {
	notify_fail("It is not allowed to summon players here.\n");
	return 0;
    }

    if(here==there)
    {
	notify_fail("But "+capitalize(str)+" is here already.\n");
	return 0;
    }

    if(TP->is_fighting())
    {
	notify_fail("The fight ruins you concentration.\n");
	return 0;
    }

    if(SP < CO_SUMMON)
    {
	notify_fail(SP_MES);
	return 0;
    }

    if (FP < CO_SUMMON)
    {
	notify_fail(FP_MES);
	return 0;
    }

    /* A players luck factor contributes to their ability to summon someone */
    if (!target->query(PLR_ALLOW_SUMMON) &&
      (2 * TP->query_random_luck()) + random(10)
      <= target->query_random_luck() + random(10) )
    {
	notify_fail("Your concentration fails.\n");
	TP->add_sp((-CO_SUMMON/4)*3);
	TP->add_fp((-CO_SUMMON_FP/4)*3);
	return 0;
    }

    TP->add_sp(-CO_SUMMON);
    TP->add_fp(-CO_SUMMON_FP);

    if (random(100) <
      (5 - TP->query_random_luck() + target->query_random_luck()))
    {
	TM("Oops! Something went WRONG with your summon! Weird \
purple and sickly gray magical field builds around you...");
	environment(TP)->tell_here(sprintf("%s extends %s hand. \
%s draws %s finger down in a straight line, and is surrounded \
by a weird purple and sickly green glow! %s coughes and gasps, \
as wild magic fumble starts to build around %s!",
	    mname,mposs,capitalize(mpro),mname,mname,mposs), ({ TP }));
	if (random(100) < 50)
	    call_out("summonfumble1", 4 + random(3), ({target, here, TP}));
	else
	{
	    target->tell_me("\nThe air in front of you parts.\n\n\
Weird purple smoke engulfs you!\n\n");
	    call_out("summonfumble2", 4 + random(3), ({target, here, TP}));
	}
	return 1;
    }

    /* Tell me */
    TM("You reach out and slice into the air in front of you.");

    tmp = sprintf("%s extends %s hand. %s draws %s finger down in a \
straight line. %s finger cuts open the very air around it.",
      mname,mposs,capitalize(mpro),mposs,capitalize(mposs));

    /* Tell here except for me */
    environment(TP)->tell_here(tmp,({TP}));

    /* Tell there  (everyone) */
    there->tell_here("\nThe air in front of you parts.\n");

    call_out("summon2",2,({target, here, TP}));

    return 1;
}


int
summon2(object *data)
{
    if (!data[0] || !interactive(data[0]) || !data[1] ||
      environment(data[0])->query(PREVENT_TELEPORT_FROM) ||
      data[2]->is_fighting())
    {
	data[2] -> tell_me(
	  "The air suddenly shimmers and your opening vanishes.");
	data[2]->add_sp(CO_SUMMON/2);
	data[2]->add_fp(CO_SUMMON_FP/2);
	return 0;
    }

    /* Tell me */
    data[2] -> tell_me("You reach into the opening and rip it open.");

    /* Tell here except me */
    data[1]->tell_here((string)data[2]->query_name()+ " reaches into the opening and rips it open.\n",({data[2]}));

    /* Tell him */
    data[0]->tell_me("A pair of hands reach through the opening, they \
rip it wide open.\n" +
      capitalize((string)data[2]->query_real_name())+"'s face appears in the middle of the opening.\n\n");

    /* Tell there except for him */
    environment(data[0])->tell_here("The slit suddenly is ripped wide open.\nA pair of glowing blue hands reach through towards "+data[0]->query_name()+".\n",({data[0]}));

    call_out("summon3",1+random(5),data);
    return 1;
}

int
summon3(object *data)
{
    object there;
    string tmp;

    if (!data[0] || !data[1] || !interactive(data[0]) ||
      environment(data[0])->query(PREVENT_TELEPORT_FROM) ||
      data[2]->is_fighting())
    {
	if (objectp(data[2]))
	    data[2] -> tell_me("The air suddenly shimmers and your opening\
 vanishes.");
	data[2]->add_sp(CO_SUMMON/2);
	data[2]->add_fp(CO_SUMMON_FP/2);
	return 0;
    }

    there = environment(data[0]);

    /* Tell him */
    tmp = sprintf("%s's hands reach through the opening and grab ahold of you.\nYou are \
lifted off the ground and pulled through the opening.",capitalize((string)data[2]->query_real_name()));
    data[0] -> tell_me(tmp);

    /* Tell me */
    tmp=sprintf("You hands glow brightly as you reach through the opening and grab %s.\n\
With a last surge of effort you yank %s through.\n",data[0]->query_name(),
      (((int)data[0]->query_gender() -1) ? "her" : "him"));
    data[2]->tell_me(tmp);

    /* Tell here except for me */
    tmp=sprintf("%s reaches into the opening and grabs something. \
%s leans back and wave of blue energy surges through %s hands. \
%s pulls something through the opening.",
      data[2]->query_name(),capitalize((string)data[2]->query_pronoun()),
      data[2]->query_possessive(), capitalize((string)data[2]->query_pronoun()));

    data[1]->tell_here(tmp,({data[2]}));

    /* move_object(data[0], data[1]); */
    /* Use proper function! */
    data[0]->move_player("X", data[1]);

    /* Tell there */
    there->tell_here("There is a blinding flash of blue energy. \
When you can see again, you notice that something is missing.");

    data[1]->tell_here("The opening seals itself back into normal space.");

    return 1;
}

int
summonfumble1(object *data)
{
    if (!data[0] || !interactive(data[0]) || !data[1] || !data[2])
    {
	if (data[2])
	{
	    data[2] -> tell_me(
	      "The air suddenly shimmers and the magic field vanishes.");
	    data[2]->add_sp(CO_SUMMON/2);
	    data[2]->add_fp(CO_SUMMON_FP/2);
	}
	return 0;
    }

    /* Tell me */
    data[2] -> tell_me("\nYou are thrown through weird dimensional warp \
and get pretty confused! After a moment, you land somewhere...\n");

    /* Tell here except me */
    data[1]->tell_here((string)data[2]->query_name()+ " disappears into \
a cloud of purple and sickly green smoke!",({data[2]}));

    /* Tell there */
    environment(data[0])->tell_here(
      "\nSuddenly, " + (string)data[2]->query_name() + " appears from \
a purple and sickly gray cloud of smoke, coughing violently!\n");

    data[2]->set_condition(C_STUNNED, 1 + random(3));
    data[2]->move_player("X", environment(data[0]));

    return 1;
}

int
summonfumble2(object *data)
{
    object esummoner, etarget;

    if (!data[0] || !interactive(data[0]) || !data[1] || !data[2])
    {
	if (data[2]) {
	    data[2] -> tell_me(
	      "The air suddenly shimmers and the magic field vanishes.");
	    data[2]->add_sp(CO_SUMMON/2);
	    data[2]->add_fp(CO_SUMMON_FP/2);
	}
	if (data[0]) data[0]->tell_me(
	      "Somehow, the purple smoke just disappears. You wonder what it was...");
	return 0;
    }

    esummoner = environment(data[2]);
    etarget = environment(data[0]);

    /* Tell me */
    data[2] -> tell_me("\nYou are hurled through weird dimensional warp \
and get pretty confused! On the way through the warp, you notice "+
      capitalize((string)data[0]->query_real_name()) + " passing by with \
an amazed look on " + (string)data[0]->query_possessive() + " face!\n\n\
After a moment, you land somewhere...\n");
    data[0] -> tell_me("\nYou are hurled through a weird dimensional warp! \
On the way through the warp, you notice "+
      capitalize((string)data[2]->query_real_name()) + " passing by with \
an amazed look on " + (string)data[2]->query_possessive() + " face!\n\n\
After a moment, you land somewhere...\n");

    /* Tell here except me */
    esummoner->tell_here((string)data[2]->query_name()+ " disappears into \
a cloud of purple and sickly green smoke!",({data[2]}));
    etarget->tell_here((string)data[0]->query_name()+ " disappears into \
a cloud of purple and sickly green smoke!",({data[0]}));

    /* Tell there */
    etarget->tell_here(
      "\nSuddenly, " + (string)data[2]->query_name() + " appears from \
a purple and sickly gray cloud of smoke, coughing violently!\n");
    esummoner->tell_here(
      "\nSuddenly, " + (string)data[0]->query_name() + " appears from \
a purple and sickly gray cloud of smoke, with a confused look on " +
      (string)data[0]->query_possessive() + " face!\n");

    data[2]->set_condition(C_STUNNED, 3 + random(5));

    data[0]->move_player("X", esummoner);
    data[2]->move_player("X", etarget);

    return 1;
}
