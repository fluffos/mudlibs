
int cmd_lines(string str) {
    object TP=(!str || !userp(to_object(str)) || !archp(this_player()) ) ?
    this_player() : to_object(str);

    string *channels= TP->query_channels();
    string *my_report=({});
    int x=sizeof(channels);

    while(x--) {
        if(TP->query_blocked(channels[x])) {
            my_report += ({ "%^BLACK%^%^BOLD%^"+channels[x]+"%^RESET%^" }); }
        else {
            my_report += ({ "%^GREEN%^%^BOLD%^"+channels[x]+"%^RESET%^" }); }
        continue; }


    write("\nChannels allocated to "+TP->query_cap_name()+" ::\n");
    write(format_page(sort_array(my_report,1),6));
    write("                     %^BLACK%^%^BOLD%^Blocked%^RESET%^ || %^GREEN%^%^BOLD%^Open%^RESET%^\n");
    return 1; }


void help() {
    write("NAME :: lines");
    write("SYNTAX :: lines "+(archp(this_player()) ? "<user>" : "")+"\n");
    write("This command will allow you to see the status of your channels.");
   if(archp(this_player())) write("\nArchwizards, such as you, may aim it atother users.\n It will then report on that player's lines instead of yourlines.\n\n"); }
