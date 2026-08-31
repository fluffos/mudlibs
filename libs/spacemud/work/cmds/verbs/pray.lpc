/* Do not remove the headers from this file! see /USAGE for more info. */

#include <verbs.h>
inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``pray``
//  |  ``pray <something>``
//  |  ``pray to <something>``
//
//  Pray it works, pray to something that matters.
//
// .. TAGS: RST

void do_pray_to_obj(object ob)
{
   ob->do_pray();
}

void do_pray_obj(object ob)
{
   ob->do_pray();
}

void do_pray()
{
   environment(this_body())->do_pray();
}

void create()
{
   add_rules(({"OBJ", "", "to OBJ"}));
   clear_flag(NEED_TO_BE_ALIVE);
}
