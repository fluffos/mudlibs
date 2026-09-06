varargs nomask status
alias_cmd(string s, object me, string mode, int flags)
{
    string name, alias;
    mapping	aliases;
    string *tmp1, *tmp2;
    int	i, siz;

    if (!me && !(me = this_player()))
	return -1;

    if ((string)me->query_real_name() == "guest") return 0;

    if(!s || s == "") {

	aliases = (mapping)me->query_command_data("aliases");
	if(!aliases || !sizeof(aliases)) {
	    me->tell_me("Your alias buffer is empty.");
	}
	else {
	    tmp1 = m_indices(aliases);
	    tmp2 = m_values(aliases);
	    me->tell_me("Aliases:\n");
	    siz = sizeof(aliases);

	    while (i < siz) {
		tmp1[i] = sprintf("%3d) %-15s = %s",
		  i+1, tmp1[i], tmp2[i]);
		i++;
	    }
	    me->more(tmp1);
	}
	return 1;
    }

    sscanf(s, "%t%s", s);

    if(sscanf(s, "%s%.1t%s", name, alias) < 2 || !(i = sizeof(alias))) {
	name = s;
	alias = 0;
    }

    switch(name) {

    case "-h":
    case "-help":
	me->tell_me("Usage: alias [ [-h] [-help] [-clear] [-del[ete] <alias>] ] "+
	  "[<alias> [string]]");
	return 1;

    case "-clear":
	me->set_command_data("alias", 0, 0);
	return 1;

    case "-del":
    case "-delete":
	if(!alias) {
	    me->tell_me("Usage: alias -del <alias>");
	    return 1;
	}
	me->set_command_data("alias", alias, 0);
	return 1;

    default:
	if(!alias) {
	    aliases = (mapping)me->query_command_data("aliases");
	    if(!aliases || !sizeof(aliases)) {
		me->tell_me("Your alias buffer is empty.");
		return 1;
	    }

	    alias = aliases[name];
	    if(!alias) {
		me->tell_me(sprintf("Alias for '%s' not defined.", name));
		return 1;
	    }
	    me->tell_me(sprintf("Alias: %s = %s", name, alias));
	}
	else me->set_command_data("alias", name, alias);
    }

    return 1;
}
