main(string str) {
    int i;
    string manuals;

    manuals = ({ "/doc", "/doc/applies", "/doc/applies/interactive", "/doc/applies/master",
		 "/doc/concepts", "/doc/defines", "/doc/defines/LPC",
                 "/doc/driver", "/doc/efuns/arrays", "/doc/efuns/buffers",
                 "/doc/efuns/calls", "/doc/efuns/compile", "/doc/efuns/ed",
                 "/doc/efuns/filesystem", "/doc/efuns/floats", "/doc/efuns/functions",
                 "/doc/efuns/general", "/doc/efuns/interactive", "/doc/efuns/internals",
                 "/doc/efuns/mappings", "/doc/efuns/mudlib", "/doc/efuns/numbers",
                 "/doc/efuns/objects", "/doc/efuns/parsing", "/doc/efuns/sockets",
                 "/doc/efuns/strings", "/doc/efuns/system", "/doc/efuns",
                 "/doc/lpc/constructs", "/doc/lpc/preprocessor", "/doc/lpc/types",
                 "/doc/lpc" });
    if (str == 0) {
	write("Topics:\n");
	while (i < sizeof(manuals)) {
	    write(manuals[i] + " ");
	    i += 1;
	}
	write("\n");
	return 1;
    }
    str = "/" + str;
    while(i < sizeof(manuals)) {
	if (file_size(manuals[i] + str) == -2) {
	    write("Sub topics " + manuals[i] + str + ":\n");
	    /* ls(manuals[i] + str); */
	    return 1;
	}
	if (file_size(manuals[i] + str) > 0) {
	    write(manuals[i] + str + ":\n");
	    this_player()->more_file(manuals[i] + str);
	    return 1;
	}
	i += 1;
    }
    write("Not found.\n");
    return 1;
}

