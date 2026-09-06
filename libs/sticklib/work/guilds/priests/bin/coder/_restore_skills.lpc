#include "../../priest.h"

status
restore_skills_cmd(object who, object sym, string str) {
    object ob, obs;
    string sw;

    if(!who->query_coder_level())
	return 0;

    if(!str) ob = this_player();
    else {
	sscanf(str, "-%s %s", sw, str);
	ob = find_player(str);
    }
    if(!ob)
	return notify_fail("No such player is on.\n"),0;

    if(ob->query_guild_object_name() != PRIEST_SYMBOL)
	return notify_fail("Not a member of priest guild.\n"),0;

    switch(sw) {
    case "v": case "validate":
	SKILL_SAVER->make_skills_valid(ob);
	who->tell_me("Ok.");
	return 1;
    }

    obs = ob->query_guild_object();
    if(SKILL_SAVER->restore_my_skills(ob, obs))
    {
	SKILL_SAVER->make_skills_valid(ob->query_real_name());
	who->tell_me("Ok.");
	return 1;
    }
    return 0;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
