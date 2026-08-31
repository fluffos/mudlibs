//  all_langs

#include <daemons.h>

int cmd_all_langs() {
    object tp;
    string *lang;
    int i;

    if(!wizardp(this_player())) return 0;
    tp=this_player();
    lang=LANG_D->all_languages();
    i=sizeof(lang);
    while(i--) {
	tp->set_lang_prof(lang[i], 10);
    }
    write("You know all languages.\n");
    return 1;
}

