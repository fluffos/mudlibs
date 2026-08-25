// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** diagnose.c
**
*/

inherit VERB_OB;
inherit M_MESSAGES;

int need_to_see() {
    return 0;
}

int need_to_be_alive() {
    return 0;
}

int need_to_think() {
    return 0;
}

void do_diagnose()
{
    this_body()->my_action(this_body()->diagnose());

    // Deja vu.  Drive the players crazy :-)
    if (random(100) == 0)
        write("你有一种奇怪的感觉好象你来过这儿。\n");
}

mixed * query_verb_info()
{
   return ({ ({ "" }) });
}
