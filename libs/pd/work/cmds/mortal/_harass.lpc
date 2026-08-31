//  Harass Command
//    Will log the output of a player to a folder.
#define SYNTAX "Syntax: <harass [on/off]>.  Please read the help before you use this.\n"
#define MAX_HARASS_LENGTH 300
#include <security.h>
mapping players;
int cmd_harass(string str) {
    if(!str || str=="") return notify_fail(SYNTAX);
    if(str != "on" && str != "off") return notify_fail(SYNTAX);
    if(str=="on") {
	if(present("harass_logger", this_player())) return notify_fail("You are "
	      "already logging a harassment claim.\n");
	new("/std/obj/harass")->move(this_player());
	write("----------------------------------------------------------------------------\n");
	write("Harass log started at "+ctime(time())+" for "+this_player()->query_name()+".\n\n");
	return 1;
    }
    if(str=="off") {
	write("Harass Log Stopped for "+this_player()->query_name()+".  Time: "+ctime(time())+"\n");
	this_object()->stop_harass(this_player()->query_name());
	return 1;
    }
}
void help() {
    write(SYNTAX);
    write("\nThis will log everything as a player you "
      "see on your terminal screen.  Use this only to "
      "report abusive players.  Do not use this for "
      "bugs/typos/etc.  This logger will automatically "
      "shut itself down after 300 lines of input.  "
      "Please do not leave this command on.  Players "
      "who abuse this service will be severly punished.\n");
}
void add_harass(string p, string msg) {
    object play;
    play=find_player(p);
    if(!play) return;
    if(!players) players=([]);
    write_file("/tmp/"+p+".harass", msg+"\n");
    seteuid(UID_LOG);
    if(file_length("/tmp/"+p+".harass") > MAX_HARASS_LENGTH) {
        this_object()->stop_harass(p);
	write("You have maxed your section of this log.");
	write("Harass Log Stopped for "+this_player()->query_name()+".  Time: "+ctime(time())+"\n");
    }
    seteuid(getuid());
}
int stop_harass(string p) {
    object play;
    int i;
    play=find_player(p);
    players[p]=0;
    if(!file_size("/tmp/"+p+".harass") || !read_file("/tmp/"+p+".harass")) return 0;
    if(present("harass_logger", play)) present("harass_logger", play)->remove();
    else return 0;
    seteuid(UID_LOG);
    write_file("/log/adm/.harass", read_file("/tmp/"+p+".harass"));
    seteuid(geteuid());
    rm("/tmp/"+p+".harass");
    return 1;
}
