/* Do not remove the headers from this file! see /USAGE for more info. */

#include <verbs.h>
inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``ready <something>``
//
//  Ready your crossbow, ready things.
//
// .. TAGS: RST

void ready_one(object ob)
{
   ob->do_ready();
}

// Rely on default support for obj, which handles the TRY_TO_ACQUIRE check

// Rely on default support for OBS

void create()
{
   add_flag(TRY_TO_ACQUIRE);
   add_rules(({"OBS", ""}), ({}));
}
