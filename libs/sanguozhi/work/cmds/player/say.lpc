// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Say
// Some cheap hack probably done in a hurry by Rust.

#include <ansi.h>
#include <mudlib.h>

inherit CMD;
inherit M_GRAMMAR;

void create()
{
    ::create();
    no_redirection();
}

private void main(string s) {
    if (!s || s == "") {
	out("说什么？\n");
	return;
    }
    this_body()->simple_action(CYN"$N说道：$o"NOR, punctuate(s));
}

nomask int valid_resend(string ob) {
    return ob == "/cmds/player/converse";
}
