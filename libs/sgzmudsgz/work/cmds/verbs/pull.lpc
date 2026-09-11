// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
inherit M_PARSING;

/*mixed direct_pull_obj(object ob) {
    return 1;
}*/

void do_pull_obj(object ob, string name) {
    if (!ob->pull(name)) {
        write( useless( "拉动"+ob->short() ) );
    }
}

/* void do_pull_obj_with_obj(object ob1, object ob2) {
    ob2->use("pull", ob1);
}

void do_pull_obj_str(object ob, string str) {
    ob->pull_str(str);
} */

void do_pull_str(string str) {
	object ob;
	mixed ret;
	ob=MYENV_OB(str);
	if(!ob) return;
	do_pull_obj(ob,str);
}

mixed * query_verb_info() {
    return ({ ({ "STR" }), ({ "yank" }) });
//    return ({ ({ "OBJ", "OBJ STR", "OBJ with OBJ" }), ({ "yank" }) });
}
