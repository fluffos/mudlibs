#include <lord.h>
#include <room_defs.h>

/* 
	Lord command:	teach
	Syntax:		teach <player>
	Conditions:
		Must be level 32 or above.
		Must be able to move.
		Specified target must be a player.
		Specified target must be below our level.
	Effects:
		Removes 1/2 of targets HPs
*/

int teach_cmd(string str)
{
    object target;
    string tposs, mposs, tname, mname;
    string mpro, tpro, tmp;
    int hp;

    if(((int)TP->query_level() < 32) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: teach <player>.\n");
	return 0;
    }

    str=lower_case(str);
    target=present(str,environment(TP));
    str=capitalize(str);

    if(!target)
    {
	notify_fail("Hmmm... now just who was this "+str+
	  " person you were looking for?\n");
	return 0;
    }

    if(target==TP)
    {
	notify_fail("Ok you go read a bunch on manners books and "+
	  "are much more polite now.\n");
	return 0;
    }

    if(target->query_coder_level())
    {
	notify_fail("Mail (co)admins if coders harass you.\n"+
	  "If (co)admins harass you, mail admins.\nIf "+
	  "admins harass you, you are in trouble.\n");
	return 0;
    }

    if(target->query_npc())
    {
	notify_fail("You cannot teach manners to monsters.\n");
	return 0;
    }

    if(!environment(target)->query(NO_PK))
    {
	notify_fail("This works only on non-playerkilling areas!\n");
	return 0;
    }

    if(target->query_level()>=TP->query_level())
    {
	notify_fail("You can only teach manners to lower players.\n");
	return 0;
    }

    if(target->query_attack() || target->query_alt_attack())
    {
	notify_fail("Not allowed to teach manners to players that are fighting.\n");
	return 0;
    }

    // Graah
    //Flagg:
    if(!this_player()->query_coder_level()){
	TP->tell_me("This command was misused to help playerkilling, \
and was removed.");
	return 1;
    }

    if(SP < CO_TEACH)
    {
	notify_fail(SP_MES);
	return 0;
    }

    hp=(int)target->query_hp();

    if(hp<10)
    {
	notify_fail("You start to swing\nSuddenly you notice how badly hurt "+str+" looks.\n"+
	  "You decide to wait till they have a few more HP\'s to take away");
	return 0;
    }

    tname= capitalize((string)target->query_name());
    mname= capitalize((string)TP->query_name());
    tposs = (string)target->query_possessive();
    mposs = (string)TP->query_possessive();
    tpro = (string)target->query_pronoun();
    mpro = (string)TP->query_pronoun();

    /* Our brief script */
    tmp=sprintf("A low growl starts in your throat.\n\
You reach out and grab %s by %s neck.\nYou stare into %s\'s eyes, slowing tightning your hand.\n\
As %s eyes bludge and their face turns blue you smile.\nJust before %s last gasp you\
 pick them up and slam them to the ground\nYou whisper a final warning before letting go.\n",
      tname,tposs,tname,tposs,tposs);
    write(tmp);

    tmp=sprintf("%s growls at you.\n%s grabs you by your neck.  It\'s suddenly hard to breathe.\n\
You choke and claw at %s hands but to no effect.\nThe world starts to fade from your vision.\n\
Is this the END!?\n%s suddenly lifts you higher.\n%s slams you to the ground and whispers \"Don't let\
 it happen again\".\n",
      mname,mpro,mposs,mname,mname);

    tell_object(target,tmp);

    tmp=sprintf("%s grabs %s by the throat.\n%s lifts %s\'s feet off the ground.\n%s\
 holds %s there slowly tightning %s hand.\n%s watches %s\'s eyes until %s thinks a lesson\
 has been learned.\n%s slams %s to the ground(by %s throat OUCH!).\n%s whispers a final warning\
 in %s ear.\n",mname, tname, mpro, tname, mname,tname,mposs,mname,tname,mpro,mname,tname,tposs,
      mname,tname);
    tell_room(environment(TP),tmp,({TP,target}));

    /* Reduce our spell points */
    TP->add_sp(-CO_TEACH);

    /* Do the actual work */
    target->add_hp(-(hp / 2));

    return 1;
}
