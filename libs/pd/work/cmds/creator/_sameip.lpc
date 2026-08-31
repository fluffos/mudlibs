//  Sameip Command
//  Whit

int cmd_sameip(string str) {
    mapping map;
    string *key, *key2, *ip;
    int i, tmp;

    if(str) {
	if(str[sizeof(str)-1..sizeof(str)] == "*") {
	    write("Please remove all wildcards (*) from the number.\n");
	    return 1;
	}
	ip="/daemon/sameip"->get_one_ip(str);
	if(!sizeof(ip)) {
	    write("There are no ip numbers containing "+str+"\n");
	    return 1;
	}
	i = sizeof(ip);
	write("%^RED%^%^BOLD%^These user's ip contains numbers of your query%^RESET%^:\n");
	while(i--) {
	    write("  "+ip[i]);
	}
	return 1;
    }

    map = "/daemon/sameip"->get_same_ips();
    i = sizeof(key = keys(map));
    if(!i) {
	write("No one is multiplaying.\n");
	return 1;
    }
    while(i--) {
	write("%^RED%^%^BOLD%^IP%^RESET%^: "+key[i]+"");
	tmp = sizeof(key2 = map[key[i]]);
	while(tmp--) {
	    write("     "+map[ key[i] ][tmp]+"");
	}
    }
    return 1;
}

