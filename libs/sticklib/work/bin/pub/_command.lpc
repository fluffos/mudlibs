

nomask int
command_cmd(string s, object me, string mode, int flags)
{
    string cmd, command;
    mapping commands;
    string	*tmp1, *tmp2;
    int	i, siz;

    if(!me)	return 0;

    if ((string)me->query_real_name() == "guest") return 0;


    if(!s) {

	commands = (mapping)me->query_command_data("commands");
	if(!commands || !sizeof(commands)) {
	    me->tell_me("Your command buffer is empty.");
	}
	else {
	    tmp1 = m_indices(commands);
	    tmp2 = m_values(commands);
	    me->tell_me("Commands:\n");
	    siz = sizeof(commands);

	    while(i < siz) {
		tmp1[i] = sprintf("%3d) %-15s = %s", i+1, tmp1[i], tmp2[i]);
		i++;
	    }
	    me->more(tmp1);
	}
	return 1;
    }

    sscanf(s, "%.1t%s", s);

    if(sscanf(s, "%s %s", cmd, command) < 2 || !sizeof(command)) {
	cmd = s;
	command = 0;
    }

    switch(cmd) {

    case "-h":
    case "-help":
	me->tell_me("Usage: command [ [-h] [-help] [-clear] [-del[ete] <command>]\
 [-delim [delim]] [-hist] [-rep <cmd>] ] [<command> [cmd line]]");

	return 1;

    case "-clear":
	me->set_command_data("command", 0, 0);
	return 1;

    case "-del":
    case "-delete":
	if(!command) {
	    me->tell_me("Usage: command -del <command>.");
	    return 1;
	}
	me->set_command_data("command", command, 0);
	return 1;

    case "-delim":
	me->set_command_data("delim", command);
	return 1;

    case "-hist":
	tmp1 = (string *)me->query_command_data("history");

	if(!tmp1 || !sizeof(tmp1)) 
	    me->tell_me("History buffer is empty.");
	else {
	    me->tell_me("History:\n");
	    siz = sizeof(tmp1);

	    while(i < siz) {
		me->tell_me(sprintf("%3d) %s\n", i, tmp1[i]));
		i++;
	    }
	}
	return 1;

    case "-rep":
	if(!command) {
	    me->tell_me("Usage: command -rep <repeated command>.");
	    return 1;
	}
	me->set_command_data("repeater", command);
	return 1;

    default:
	if (!command) {
	    command = (string)me->query_command_data("commands", cmd);
	    if (!command) {
		me->tell_me(sprintf("Command '%s' not found.", cmd));
		return 1;
	    }
	    me->tell_me(sprintf("Command: %s = %s", cmd, command));
	}
	else me->set_command_data("command", cmd, command);
    }

    return 1;
}
