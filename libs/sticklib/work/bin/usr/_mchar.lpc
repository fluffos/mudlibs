/*************************************************

 NAME:    _mchar.c

 PURPOSE: Deal with multiple characters. Add, del
	  and view multiple chars.

 AUTHOR:  Tron

 NOTE:    man mchar
 *************************************************/

#include <coder_levels.h>
#include <daemons.h>
#include <mchar.h>

// 11-May-98 / Graah: Ready for mchar limits.

/*************************************************

 DESCRIPTION: Check if player can use function.

 ARGUMENT(S): o -option string.

 RETURN:      1 for valid, 0 for nonvalid.

 *************************************************/

nomask private status
_validUser(string o)
{
    int x;

    x = (int)this_player()->query_coder_level();
    if (x < LVL_CODER ||
      (x < LVL_SENIOR && (o == "d" || o == "a") ))
    {
	notify_fail("Option '"+o+"' is for \
coders, seniors and (co)admins only.\n");
	return 0;
    }

    return 1;
}

/*************************************************

 DESCRIPTION: Add, del and view multiple chars.

 ARGUMENT(S): s  -argument string from command.
	      ob -optional command user; not
		  used with this command.


 RETURN:      1 for success, 0 for failure.

 NOTE:        Options a, c and d:

	      a: add new multiple character pair.
	      c: check if player has multiple char.
	      d: del multiple character pair.

	      none: list multiple character pairs.

 *************************************************/

nomask varargs status
mchar_cmd(string s, object ob)
{
    string option;
    string chars;
    string owner, mchar;
    string tmp;
    int i;

    if (!s) {
	if ((int)this_player()->query_coder_level() < LVL_CODER)
	{
	    notify_fail("Yeah#sure#you#can\n");
	    return 0;
	}

	/* make this nicer */
	mchar = (string) MCHAR_D->query_multiple_char_string();
	if(!mchar || sizeof(mchar) <= 1)
	    write("Sorry, multiple character list is empty.\n");
	else write(mchar);
	return 1;
    }

    notify_fail("USAGE: mchar [-acd] [owner] [mchar]\n"+
      "'man mchar' for more information.\n");

    if (sscanf(s, "-%s %s", option, tmp) == 2)
    {
	tmp = lower_case(tmp);

	switch(option)
	{
	case "a":
	    if (!_validUser(option)) return 0;
	    if (sscanf(tmp, "%s %s", owner, mchar) != 2)
		return 0;

	    if ((int)MCHAR_D->query_no_of_mchars(owner) >= MAX_NO_OF_MCHARS)
	    {
		notify_fail(capitalize(owner)
		  + " already has "
		  + MAX_NO_OF_MCHARS
		  + ", the maximum allowed!\n");
		return 0;
	    }

	    if (!MCHAR_D->add_multiple_char(owner, mchar))
	    {
		notify_fail(capitalize(mchar)
		  + " is a multiple character already.\n");
		return 0;
	    }
	    break;

	case "d":
	    if (!_validUser(option)) return 0;
	    if (!MCHAR_D->del_multiple_char(tmp))
	    {
		notify_fail("No such multiple char '"+tmp+"'.\n");
		return 0;
	    }
	    break;

	case "c":
	    if (!_validUser(option)) return 0;
	    if (chars = (string)MCHAR_D->query_multiple_char(tmp))
	    {
		write(chars+"\n");
		i = (int)MCHAR_D->query_no_of_mchars(tmp);
		write("That is " + i + " mchar" + (i > 1 ? "s": "")
		  + " total.\n");
	    }
	    else
	    {
		notify_fail(capitalize(tmp)+" has no other chars.\n");
		return 0;
	    }
	    break;

	default:
	    write("No such option '"+option+"'.\n");
	    return 1;
	}
    } else return 0;

    write("Ok.\n");

    return 1;
}
