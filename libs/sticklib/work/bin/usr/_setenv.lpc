#include <cmd.h>

nomask int
setenv_cmd(string arg)
{
    string env;
    mixed d;

    if (!CHECK) return 0;

    if (!arg) {
	mapping m;
	string *s;
	int i;

	m = (mapping)this_player()->query_env(0);
	if (! mappingp(m)) {
	    write("Couldn't restore env variables.\n");
	    return 1;
	}
	m = m_delete(m, 0);	// Let's remove NULL-indices!
	s = m_indices(m);
	for (i = 0; i < sizeof (s); i++) {
	    d = m[s[i]];
	    if (d == "") {
		write(s[i] + " = \"\"\n");
	    } else {
		printf(stringp(d) ? "%s = \"%s\"\n" : "%s = %d\n", s[i], d);
	    }
	}
	return 1;
    }

    if (sscanf(arg, "%s %s", arg, env) != 2)
	this_player()->set_env(arg, "");
    else if (arg == "clear")
	this_player()->set_env(env, 0);
    else {
	string tmp;

	if (sscanf(d = env, "%d%s", d, tmp) && tmp != "") d = env;
	this_player()->set_env(arg, d);
    }
    write("Ok.\n");
    return 1;
}


