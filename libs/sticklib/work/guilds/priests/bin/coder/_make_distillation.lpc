#include "../../priest.h"

status
make_distillation_cmd(object who, object sym, string str)
{
    object ob;
    string race;
    int level;

    if(!who->query_coder_level() && !who->query_testplayer())
	return 0;

    if(!str || sscanf(str, "%s %D", race, level)!=2)
	return notify_fail("syntax: make_distillation <race> <level>\n"),0;

    ob = clone_object(PRIEST_OBJ_DIR "priest_bottle");
    ob->fill_with_blood(race, level);
    move_object(ob, this_player());
    who->tell_me(sprintf("Ok, filled a sample bottle with %s blood.", race));
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
