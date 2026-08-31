mapping member, council, leader, main, post;
int cmd_member(string str) {
    mixed guild;
    string *names;
    int i;
    if(!str) return notify_fail("Syntax: <member [guild]>\n");
    guild = str;
    if(!file_exists("/d/guilds/save/"+guild+".o")) return notify_fail("No such "
	  "guild.\n");
    restore_object("/d/guilds/save/"+guild);
    write("%^CYAN%^                          Current Guild Statistics for "+
      guild+"\n ");
    write("%^BLUE%^Main Leaders%^RESET%^");
    for (i = sizeof((names = keys(main))); i-- >   0;)
	write(names[i]);
    write("\n");
    write("%^BLUE%^Leaders%^RESET%^");
    for (i = sizeof((names = keys(leader))); i-- >   0;)
	write(names[i]);
    write("\n");
    write("%^RED%^Councilors%^RESET%^");
    for (i = sizeof((names = keys(council))); i-- >   0;)
	write(names[i]);
    write("\n");
    write("%^BOLD%^Members%^RESET%^");
    for (i = sizeof((names = keys(member))); i-- >   0;)
	write(names[i]);
    write("\n");
    return 1;
}

