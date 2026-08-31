//      /wizards/kalinash/bin/_langs.c
//      Shows what languages a player knows
//      Also shows numeric proficiency values
//      By Kalinash@Nightmare on 16 Dec 93

#include <std.h>

inherit DAEMON;

int cmd_langs(string str)
        {
        string *lang, tmp;
	int amt, x;
	object ob;

        if(!str || str=="me")
                {
                str=(string)this_player()->query_name();
                }
        if(!ob=find_player(str))
                {
		notify_fail(capitalize(str)+" is not in our reality.\n");
		return 0;
                }
	if(ob->query_invis() && !archp(this_player()))
		{
		notify_fail(capitalize(str)+" is not in our reality.\n");
		return 0;
		}
        lang = ob->query_all_languages();
        amt = sizeof(lang);
	if(!amt)
		{
		notify_fail("They know no languages!\n");
		return 0;
		}
        message("my_action", ob->query_cap_name()+" knows the following "
		"languages :\n", this_player());
	for(x=0;x<amt;x++)
                {
		tmp = lang[x];
		tmp = arrange_string(tmp, 15);
		tmp += ob->query_lang_prof(lang[x]);
		x++;
		if(x<amt)
			{
			tmp = arrange_string(tmp, 20);
			tmp += lang[x];
			tmp = arrange_string(tmp, 35);
			tmp += ob->query_lang_prof(lang[x]);
			}
		message("my_action", tmp, this_player());
		}
	return 1;
	}

void help()
	{
	message("help", "Usage : langs <who>\n\nThis is a wizard "
		"command to show the langues and proficiencies "
		"of players.", this_player());
	return;
	}
