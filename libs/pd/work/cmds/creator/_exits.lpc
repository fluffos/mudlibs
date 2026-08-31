//  Exits command
//  -- Whit
//  Improved to show invis exits

int cmd_exits() {
    mapping exit;
    int i;
    string out;
    out = "%^CYAN%^(%^BOLD%^{ %^RESET%^";
    exit = environment(this_player())->query_directions();
    i = sizeof(keys(exit));
    while(i--) {
	if(environment(this_player())->invis_exit(keys(exit)[i]))
	    out += "%^RESET%^%^BOLD%^(%^RESET%^"+keys(exit)[i]+"%^RESET%^%^BOLD%^)%^RESET%^ %^RED%^%^BOLD%^: %^RESET%^";
	else  out += keys(exit)[i]+" %^RED%^%^BOLD%^: %^RESET%^";
    }
    out += "%^BOLD%^%^CYAN%^}%^RESET%^%^CYAN%^)%^RESET%^";
    message("environment", out, this_player());
    return 1;
}

