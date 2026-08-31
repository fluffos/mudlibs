/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``knock on <something>``
//  |  ``knock at <something>``
//
// Knock on the door, rap on the window.
//
// .. TAGS: RST

void do_knock_on_obj(object obj)
{
   obj->do_knock();
}

void do_knock_at_obj(object obj)
{
   obj->do_knock();
}

void create()
{
   add_rules(({"on OBJ", "at OBJ"}), ({"rap"}));
}
