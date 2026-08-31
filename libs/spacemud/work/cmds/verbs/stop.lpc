/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Written 15/12/2024 by Tsath
 */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``stop``
//  |  ``i.e. stop what you're doing, stop channeling, searching etc.``
//
// Stop it, whatever it is. Just ...
//
// .. TAGS: RST

void do_stop()
{
   this_body()->stop_busy();
   this_body()->simple_action("$N $vstop what $n $vare doing.");
}

void do_stop_liv(object target)
{
   this_body()->targetted_action("$N $vstop $t, right there.", target);
}

void create()
{
   add_rules(({"", "LIV"}), ({}));
}
