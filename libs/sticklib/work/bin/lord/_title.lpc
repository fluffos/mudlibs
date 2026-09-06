#include <lord.h>

//
// Lord command:	title
// Syntax:		title <string>
// Conditions:
//		User must be level 26 or above
//		User must be able to move
//		Title must not contain rude words
// Effects:
//		Changes the users title to 'string'
//		prepending a 'the ' if they haven't
//		done it in the string already
//
// 28-Jul-96 / Graah: No "Gods" around :)...unless they really are!

int
title_cmd(string str)
{
    int i;
    string *tmp, tmp1, tmp2;
    string title;

    if (((int)TP->query_level() < 26) && !(CODER))
	return 0;

    if (!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if (!str)
    {
	TM("Your current title is " + TP->query_title() + ".");
	return 1;
    }

    if (sizeof(str) > TITLE_MAX_LEN)
    {
	notify_fail("That title is too long max length is: "+TITLE_MAX_LEN+".\n");
	return 0;
    }

    tmp = explode(lower_case(str), " ");
    /* Look for swearing/offensive etc */
    for (i = 0; i < sizeof(tmp); i++)
    {
	if(tmp[i][0..3] == "fuck" || tmp[i][0..3] == "shit" ||
	  tmp[i][0..3] == "piss" || tmp[i][0..3] == "cunt" ||
	  tmp[i][0..5] == "asshol")
	{
	    notify_fail("Please refrain from using swearing in your title.\n");
	    return 0;
	}
    }

    title = str;

    // No "God*"s...unless they really are one!
    if ((LL < 26) && (!CODER))
    {
	if (sscanf(title, "%s god%s", tmp1, tmp2) == 2)
	    title = tmp1 + " cod" + tmp2;
	if (sscanf(title, "%s God%s", tmp1, tmp2) == 2)
	    title = tmp1 + " Cod" + tmp2;
    }

    // Make the change
    TP->set_title(title);
    TP->tell_me("Ok. Your new title is: " +title+ ".");

    return 1;
}
