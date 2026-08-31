//  hfile command
//  Whit

int help();

int cmd_hfile(string str) {
    string *dirs, out, *tmp;
    int i;

    if(!str) return help();

    dirs = ({ "/include/", "/include/domains/", 
      "/include/std/", "/include/cmds/", 
      "/include/daemon/", "/include/servers/", 
      "/adm/include/", });
    i = sizeof(dirs);
    tmp = ({});
    while(i--) {
	if(file_exists(dirs[i]+str+".h")) tmp += ({ dirs[i] });
    }
    if(!tmp || tmp == ({}) ) {
	write("No header file found.\n");
	return 1;
    }
    i = sizeof(tmp);
    if(i==1) {
	write("Header file exists.\nLocation: "+tmp[0]+"\n");
	return 1;
    }
    else {
	out = "There are "+i+" instances of that file.\nLocations: ";
	while(i--) {
	    if(i == 0) out += tmp[0]+"\n";
	    else out += tmp[i]+", ";
	}
	write(out);
	return 1;
    }
}

int help() {
    write(@END
Syntax: <hfile [header]>

This will tell you if a header file exists and
where it is located.
END);
    return 1;
}

