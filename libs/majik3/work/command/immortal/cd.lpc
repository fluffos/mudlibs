int
main (string dir) {

/*
    if (!dir) {
        dir = "/home/"+this_player()->query_name() ;
        if (file_size(dir) == -1) {
	    dir = "/" ;
	}
    } else {
	if (!absolute_path(dir)) {
	    dir = this_player()->query_cwd()+dir+"/" ;
	}
    }
    dir = resolve_path(dir) ;
    if (!dir) {
        write ("resolve_path: Failed to determine directory.\n") ;
	return 1 ;
    }
*/
    if (!dir) dir = "~";

    dir = true_path(dir);
    if (this_player()->set_cwd(dir)) {
        if (dir[0] == '/')
          message ("misc", "Current working directory: ^c1"+dir+"^c0\n", THIS);
        else
          message ("misc", "Current working directory: /^c1"+dir+"^c0\n", THIS);
        return 1 ;
    }
    write (dir + ": No such directory\n") ;
    return 1 ;
}

query_author() { return "namhas"; }

query_help()
{
  return "The cd (change directory) -command changes your current working directory."+
         " If no arguments are given, your working directory will be set as your "+
          "home-directory.";
}
query_see_also()
{
  return "pwd(2)";
}

