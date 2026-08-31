/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** mount.c
*/

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``mount <something>``
//
// Mount your horse or something else. 
//
// .. TAGS: RST

void do_mount_obj(object ob)
{
   ob->do_verb_rule("mount", "OBJ", ob);
}

create()
{
   add_rules(({"OBJ"}));
}
