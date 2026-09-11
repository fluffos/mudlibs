#include <mudlib.h>

inherit VERB_OB;
inherit M_PARSING;

void do_chuang_obj_with_obj(object ob1, object ob2) {
    ob1->chuang_with(ob2);
} 

mixed do_chuang_obj(object ob)
{
    ob->chuang();
}

array query_verb_info()
{
  return ({ ({ "OBJ", "OBJ with OBJ" }) });
}
