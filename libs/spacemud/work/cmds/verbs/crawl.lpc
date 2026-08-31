/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Written 2-16-99 by Tigran
 */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``crawl <preposition> <something>``
//  |  ``i.e. crawl under bed``
//
// Crawl somewhere where they will not find you. Ever.
//
// .. TAGS: RST


void do_crawl_wrd_obj(string prep, object ob)
{
   ob->do_verb_rule("crawl", "WRD OBJ", prep, ob);
}

void create()
{
   add_rules(({"WRD OBJ"}), ({}));
}
