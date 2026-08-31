/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``press <something>``
//  |  ``press <something> <in some way>``
//  |  ``press <something> with <something>``
//
//  Press or push a button, push it hard, press the flowers with the books.
//
// .. TAGS: RST

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

void create()
{
   add_rules(({"OBJ", "OBJ STR", "OBJ with OBJ"}), ({"push"}));
}
