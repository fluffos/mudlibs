/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Written by Tigran, September 7, 2000
 */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``descend <something>``
//
// Descend from your high horse, a ladder, a tree or other things you find yourself on.
//
// .. TAGS: RST

void do_descend_obj(object ob)
{
   ob->do_verb_rule("descend", "OBJ", ob);
}

void create()
{
   add_rules(({
                 "OBJ",
             }),
             ({}));
}
