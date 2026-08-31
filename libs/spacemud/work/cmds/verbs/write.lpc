/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``write <text> on <something>``
//  |  ``write <something> with <text>``
//
// Write or inscribe something. We do not endorse graffiti.
//
// .. TAGS: RST

mixed can_verb_rule()
{
   return check_vision();
}

void do_write_str_on_obj(string str, object ob)
{
   ob->add_text(str);
   write("Done.\n");
}

void do_write_obj_with_str(object ob, string str)
{
   ob->add_text(str);
   write("Done.\n");
}

void create()
{
   add_rules(({"STR on OBJ", "OBJ with STR"}), ({"inscribe"}));
}
