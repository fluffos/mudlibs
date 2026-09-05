#include "/obj/ansi.h"

id(str) { return str == "titler" || str == "device"; }

short() { return "A super-ghetto titler device"; }

get() { return 1; }

long() 
{
	write("This thing is so ghetto that kids with 'Mike' sneakers laugh at it.\n"+
	      "But it works. The commands 'mpretitle', 'mtitle', and 'msetal' are\n"+
		  "used to set the titles to hardcoded string values.\n"+
		  "Ghetto Industries, 2003\n");
}

init()
{
	add_action("on_pretitle","mpretitle");
	add_action("on_title","mtitle");
	add_action("on_setal","msetal");
}

on_pretitle()
{
	string result;

	/* the colorcodes from ansi.h... */
	result = HIR + "I AM A TOMATO" + HIB;

	this_player()->set_pretitle(result);
	write("Your pretitle has been set.\n");
	return 1;
}

on_title()
{
	string result;

	/* the colorcodes from ansi.h... */
	result = HIY + "the colorblind" + HIG + " wizard" + NORM;

	this_player()->set_title(result);
	write("Your title has been set.\n");
	return 1;
}

on_setal()
{
	string result;

	/* the colorcodes from ansi.h... */
	result = HIK + "nog" + NORM + NORM;

	this_player()->set_al_title(result);
	write("Your setal has been set.\n");
	return 1;
}
