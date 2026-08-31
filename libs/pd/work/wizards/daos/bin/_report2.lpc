// report -- seeker
// Modified by Daos to show percentage


#include <std.h>

inherit DAEMON;

int cmd_report2(string str)
{
    string outp;

    int hp, max_hp, sp, max_sp, mp, max_mp;

    if (str == "percent on")
    {
	this_player()->set_property("reportper", 1);
	write("Your report will now be shown as a percentage.");
	return 1;
    }

    if (this_player()->query_property("reportper") && !str || str == "")
    {

	int percH;
	int percS;
	int percM;

	percH = to_int(100 * this_player()->query_hp() / this_player()->query_max_hp());
	percS = to_int(100 * this_player()->query_sp() / this_player()->query_max_sp());
	percM = to_int(100 * this_player()->query_mp() / this_player()->query_max_mp());

	this_player()->force_me("say I have "+percH+ "% hp, " +percS+ "% sp, " +percM+ "% mp.");
	this_player()->set_property("reportper", 1);
	return 1;
    }

    if (str == "percent off")
    {
	this_player()->remove_property("reportper");
	write("Your report will no longer be shown as a percentage.");
	return 1;
    }

    if(this_player()->query("bear"))
	return notify_fail("You growl like a bear.\n");
    hp = (int)this_player()->query_hp();
    max_hp = (int)this_player()->query_max_hp();
    sp = (int)this_player()->query_sp();
    max_sp = (int)this_player()->query_max_sp();
    mp = (int)this_player()->query_mp();
    max_mp = (int)this_player()->query_max_mp();

    outp = "I have "+hp+"/"+max_hp+" hp, "+sp+"/"+max_sp+" sp, "+mp+"/"+max_mp+" mp.";

    this_player()->force_me("say "+outp + "");
    return 1;
}
int help()
{
    write( @EndText
Syntax: report
Effect: allows you to report you hp, sp, and mp to the room.

See also: status
EndText
    );
    return 1;
}
