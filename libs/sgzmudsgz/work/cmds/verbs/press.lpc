// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
inherit M_PARSING;

/*mixed direct_press_obj(object ob) {
    return 1;
} */

void do_press_str(string str) {
	object ob;
	mixed ret;
	ob=MYENV_OB(str);
	if(!ob) return;
	ret=ob->press(str);
	if(!ret)
	{
        write( useless( "按动"+ob->short() ) );
		return;
	}
}
/*
void do_press_obj_with_obj(object ob1, object ob2) {
    ob2->use("press", ob1);
}

void do_press_obj_str(object ob, string str) {
    ob->press_str(str);
}

*/
mixed * query_verb_info() {
    return ({ ({ "STR" }), ({ "push" }) });
//    return ({ ({ "OBJ", "OBJ STR", "OBJ with OBJ" }), ({ "push" }) });
}

