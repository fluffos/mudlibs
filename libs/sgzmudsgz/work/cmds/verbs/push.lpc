// Updated by stefan on 10 Jan 1997
// modified by row	
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
inherit M_PARSING;

mixed direct_push_obj(object ob) {
    return 1;
}

void do_push_obj(object ob) {
    if ( !ob->push() ) {
        write( useless( "推动"+ob->short() ) );
    }
}

/* void do_push_obj_with_obj(object ob1, object ob2) {
    ob2->use("push", ob1);
}

void do_push_obj_str(object ob, string str) {
    ob->push_str(str);
} */

void do_push_str(string str) {
	object ob;
	mixed ret;
	ob=MYENV_OB(str);
	if( !ob||!objectp(ob) ) return;
	do_push_obj(ob);
}

mixed * query_verb_info() {
    return ({ ({ "STR" }), ({ "yank" }) });
//    return ({ ({ "OBJ", "OBJ STR", "OBJ with OBJ" }), ({ "yank" }) });
}
