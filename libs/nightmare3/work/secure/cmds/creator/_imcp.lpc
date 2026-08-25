
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_imcp(string str) {
    string *files,mudid;
    string tmp,x;
    object ob;
    int i;

    if(!str || sscanf(str ,"%s %s",x,mudid) !=2) {
        notify_fail("Correct syntax: <imcp [file]> <valid mudid>\n");
        return 0;
    }
    if((ob=previous_object())->query_forced()) {
        write("Someone attempted to force you to imcp "+str+".");
        return 1;
    }
    tmp = absolute_path((string)ob->get_path(), x);
if(!sizeof(files = (string *)ob->wild_card(tmp)))
      files = ({ tmp });
    if(!(i=sizeof(files))) {
        message("system", "File "+tmp+" does not exist.", this_player());
        return 1;
    }
    while(i--) {
        switch(file_size(files[i])) {
            case -1: message("system", "File "+files[i]+" does not exist.",
			     this_player()); break;
            case -2: message("system", files[i]+" is a directory.", 
			     this_player()); break;
            default: message("system","Intermud Copy startet at file :"+files[i]+" to "+mudid+".", this_player());
		     MCP_D->send_file(files[i],mudid);
	      break;
        }
    }
    return 1;
}

void help() {
    message("help", "Syntax: <imcp [file] [mudid]>\n\n"
	    "This command copies the file to the /ftp dir to the mud known "
	    "under the specified mudid. The copy command will work only if "
	    "the source file is located also in the /ftp dir.", this_player());
}
