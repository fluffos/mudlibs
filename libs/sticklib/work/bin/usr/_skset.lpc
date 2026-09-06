#include <cmd.h>

nomask int
skset_cmd(string arg)
{
    string skname;
    int value;

    if (!arg || sscanf(arg, "%s %d", skname, value) != 2) {
	notify_fail("Usage: skset <skillname> <value 0..100000>\n");
	return 0;
    }

    skname = lower_case(skname);

    if (!TP->query_liv_Skill(skname))
	write("Adding a new skill \"" + skname + "\"...\n");

    if (value < 0 || value > 100000)
	write("Warning: skill score " + value + " is beyond normal range.\n");

    if (!TP->set_skill_value(skname, value)) {
	notify_fail("Cannot set skill \"" + skname + "\"!\n");
	return 0;
    }

    write("Ok.\n");

    return 1;
}
