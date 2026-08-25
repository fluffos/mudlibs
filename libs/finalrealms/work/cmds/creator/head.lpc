/** coded by Raskolnikov July 1996 **/
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}



protected int cmd(string str, object me) {
    string *filename, text;
   int file;
    int range;

    if (!str) {
        notify_fail("Usage : head -range|file\n");
	return 0;
    }
    if(sscanf(str, "-%d %s", range, file) == 2) {
	filename = this_player()->get_files(file);
	if (!sizeof(filename)) {
	    notify_fail("Invalid file\n");
	    return 0;
	}
	if(range < 0) {
	    notify_fail("Invalid range : "+range+"\n");
	    return 0;
	}
	if(!range) range = 10;
	text = read_file(filename[0], 0, range);
	printf("%-=*s", this_player()->query_cols(), text);
        this_player()->set_trivial_action();
	return 1;
    }
    else {
	sscanf(str, "%s", file);
	filename = this_player()->get_files(file);
	if(!sizeof(filename)) {
	    notify_fail("Invalid file\n");
	    return 0;
	}
	text = read_file(filename[0], 0, 10);
	printf("%-=*s", this_player()->query_cols(), text);
        this_player()->set_trivial_action();
	return 1;
    }
} /* head_file() */

string query_short_help() {
    return "This command allows the user to see the contents "
    "of file starting at the first line and ending at line range. "
    " A default of 10 lines is returned if range is not specified.\n\n"
    "Ex. head -20 /std/room.c.\n"
    "will return the first 20 lines of the file room.c.\n\n"
    "Note: Thextension must be specified.";
}

string query_usage() {
    return "head -range|file";
}
