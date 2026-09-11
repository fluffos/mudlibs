#include <mudlib.h>

inherit VERB_OB;
inherit M_PARSING;

void do_xiufu_obj_with_obj(object ob1, object ob2) {
    ob1->xiufu_with(ob2);
} 

mixed do_xiufu_obj(object ob)
{
    ob->xiufu();
}

array query_verb_info()
{
  return ({ ({ "OBJ", "OBJ with OBJ" })});
}
