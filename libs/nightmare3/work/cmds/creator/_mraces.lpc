//	/wizards/kalinash/bin/_mraces.c
//	Lists monster races for you.
//	By Kalinash@Nightmare on 29 Dec 93

#include <std.h>

inherit DAEMON;

int cmd_mraces()
	{
	string *files;

	files = path_file((string *)this_player()->wild_card("/adm/db/mon_races/*"));
	message("system", "The following monster body types are available :\n", this_player());
	message("system", format_page(files[1], 4), this_player());
	return 1;
	}

void help()
	{
	message("help", "Usage : mraces\n\nThis lists the "
	  "non-standard monster body types available on Nightmare.",
	  this_player());
	return;
	}
