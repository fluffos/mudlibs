#include <mudlib.h>
inherit VERB_OB;
inherit M_PARSING;
mixed direct_zhe_obj(object ob) {
    return 1;
}
void do_zhe_obj(object ob, string name) {
    if (!ob->zhe(name)) {
        write( useless( "折动"+ob->short() ) );
    }
}
void do_zhe_obj_with_obj(object ob1, object ob2) {
    ob2->use("zhe", ob1);
}
void do_zhe_obj_str(object ob, string str) {
    ob->zhe_str(str);
}
mixed * query_verb_info() {
    return ({ ({ "OBJ", "OBJ STR", "OBJ with OBJ" }) });
}
