void help();

int cmd_lines(string str) {
    object TP=this_player();

    string *channels =sort_array(TP->query_channels(),-1);
    string *my_report=({});
    int x=sizeof(channels);

    if(!str) {help(); return 1;}

    if(str == "status") {
	while(x--) {
	    if(TP->query_blocked(channels[x])) {
		my_report += ({ "%^BLACK%^%^BOLD%^"+channels[x]+"%^RESET%^" }); }
	    else {
		my_report += ({ "%^GREEN%^%^BOLD%^"+channels[x]+"%^RESET%^" }); }
	    continue; }

	write("\nChannels allocated to "+TP->query_cap_name()+" :: ( %^GREEN%^%^BOLD%^ON%^RESET%^ or %^BLACK%^%^BOLD%^OFF%^RESET%^ )\n");
	write(format_page(my_report,6));
	return 1; }

   else if( str == "color" ) {
	while(x--) {
	    string line_color=TP->query_line_color(channels[x]);

	    my_report += ({ line_color + channels[x] + "%^RESET%^" }); }
	write("\nThe follow listing are the colors selected for each line for "+TP->query_name()+"\n");
	write(format_page(my_report,6));
	write("\nPlease see \"%^CYAN%^%^BOLD%^help customize%^RESET%^\" to change the selected colors.\n");
	return 1; }

    else if( str == "on" ) {
	while(x--) {
	    if(TP->query_blocked( channels[x] )) TP->set_blocked( channels[x]); }
	write("\nAll of your lines are now turned %^GREEN%^%^BOLD%^ON%^RESET%^.\n");
	return 1;}

    else if( str == "off" ) {
	while(x--) {
	    if(!TP->query_blocked( channels[x] )) TP->set_blocked( channels[x]); }
	write("\nAll of your lines are now turned %^RED%^%^BOLD%^OFF%^RESET%^.\n");
	return 1;}

    else { help();return 1; }

    return 1; }

void help() {
    write("%^RED%^%^BOLD%^SYNTAX ::%^RESET%^ lines status");
    write("%^RED%^%^BOLD%^SYNTAX ::%^RESET%^ lines color");
    write("%^RED%^%^BOLD%^SYNTAX ::%^RESET%^ lines off");
    write("%^RED%^%^BOLD%^SYNTAX ::%^RESET%^ lines on");
    write("\nIf you use the command with color, You will get a table showing currently selected color scheme for your lines. If you the command with status, you will get a table showing if the lines are turned on or off.\n");
   write("Using this command with off or on will turn on or turn off all your lines.\n");
}

