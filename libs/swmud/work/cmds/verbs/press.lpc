inherit VERB_OB;

void do_press_obj(object ob, string name)
{
   ob->do_press();
}

void do_press_obj_with_obj(object ob1, object ob2)
{
   ob1->do_press(ob2);
}

void do_press_obj_str(object ob, string str)
{
   ob->do_press(str);
}

void do_press_wrd_on_obj(string wrd, object ob)
{
   ob->do_press_wrd(wrd);
}

void create()
{
   add_rules( ({ "OBJ", "OBJ STR", "OBJ with OBJ", "WRD on OBJ" }), ({ "push" }) );
}