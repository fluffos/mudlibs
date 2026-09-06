#include <cmd.h>

nomask int
sklist_cmd(string arg)
{
    object ob;
    string tmp;

    if (!arg) {
	write(TP->list_skills());
	return 1;
    }

    ob = present(arg, environment(TP));

    if ((!ob || !living(ob)) &&
      !(ob = find_living(arg))) {
	notify_fail("No such living being found.\n");
	return 0;
    }

    if (!(tmp = (string)ob->list_skills())) {
	write((string)ob->query_name() + " doesn't have any skills.\n");
	return 1;
    }

    write("Skills of " + (string)ob->query_name() + ":\n" + tmp);
    return 1;
}
