/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``lock <something> with <something>``
//  |  ``lock <something>``
//
// Lock your door, lock a chest with a key.
//
// .. TAGS: RST

void do_lock_obj_with_obj(object ob1, object ob2)
{
   ob1->do_lock(ob2);
}

void do_lock_obj(object ob1)
{
   ob1->do_lock();
}

void create()
{
   add_rules(({"OBJ", "OBJ with OBJ"}));
}
