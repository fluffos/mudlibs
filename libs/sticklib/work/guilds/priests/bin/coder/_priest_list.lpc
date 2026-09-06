#include "../../priest.h"

status
priest_list_cmd(object who, object sym, string s) {
    string tmp;
    string *priests;

    if(!who->query_coder_level()) return 0;

    priests = sort_array(SKILL_SAVER->query_priests(), #'>);
    who->more(explode(sprintf("%-78#s", implode(priests,"\n")),"\n"));
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
