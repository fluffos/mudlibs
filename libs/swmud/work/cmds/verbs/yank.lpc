// Last edited by deforce on 12-08-2007
inherit VERB_OB;

void do_yank_obj(object ob, string name)
{
   ob->do_yank(name);
}

void do_yank_obj_with_obj(object ob1, object ob2)
{
   ob2->use("yank", ob1);
}

void do_yank_obj_str(object ob, string str)
{
   ob->do_yank_str(str);
}

void create()
{
   add_rules( ({ "OBJ", "OBJ STR", "OBJ with OBJ" }) );
}