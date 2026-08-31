/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``listen``
//  |  ``listen to <something>``
//  |  ``listen to <something> with <item>``
//
// Listen to your heart, the sounds in the room, listen to the wall with a glass.
//
// .. TAGS: RST

void do_listen_to_obj_with_obj(object ob1, object ob2)
{
   ob2->do_listen(ob1);
}

void do_listen_to_obj(object ob)
{
   ob->do_listen();
}

void do_listen()
{
   environment(this_body())->do_listen();
}

void create()
{
   add_rules(({"", "to OBJ", "to OBJ with OBJ"}));
}
