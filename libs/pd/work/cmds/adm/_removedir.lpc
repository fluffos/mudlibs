//  Removedir Command
//    -- Whit
#define DEBUG

int cmd_removedir(string str) {
    int i;
    string *con;
    if(!archp(this_player())) return 0;
    if(!str||str=="") return notify_fail("Syntax: <removedir [dir]>\n");
    str = resolv_path((string)this_player()->get_path(), str);
    if(file_size(str)!=-2) return notify_fail(str+" is not a directory.\n");

#ifdef DEBUG
   write("This Command (removedir) is in Debug Mode.\n");
#endif
   seteuid("Bb");
   seteuid(geteuid(previous_object()));
#ifdef DEBUG
   write("UID for Command: "+geteuid(this_object())+"\n");
#endif
    write("Recursivly removing all files in "+str+"\n\n");
    i=sizeof(con=get_dir(str+"/"));
    while(i--) {
#ifdef DEBUG
	write("Removing "+str+"/"+con[i]+"\n");
#endif
	if(file_size(str+"/"+con[i])==-2) write("Unable to remove directory: "+str+"/"+con[i]+"\n");
	else
	    rm(str+"/"+con[i]);
    }
     rmdir(str+"/");
     if(file_size(str+"/")==-2) write("Unable to completly remove directory.\n"); else
    write("Complete");
    return 1;
}

void help() {
    write("Syntax: <removedir [dir]>\n\n");
    write("This remove all the contents in a dir.\nNote: "
      "this will not remove subdirectories of [dir].\n");
}

