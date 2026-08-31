#include <teststd.h>
#include <tirun.h>
#include <daemons.h>
#include <security.h>
#include <move.h>
inherit ROOM;
mapping people;
string path;
void create() {
    ::create();
    seteuid(UID_VOTESAVE);
    if(path)
	restore_object(path);
    seteuid(geteuid());
    if(!people)
	people = ([]);
}
int set_path(string str) { path = str; }
int save_thing(string str) {
    object ob;
    if(!str){
	write("Store what?");
	return 1;
    }
    if(!(ob = present(str, this_player()))) {
	write("You do not have that!");
	return 1;
    }
    if(people[this_player()->query_name()] &&
      people[this_player()->query_name()] != "") {
	write("You already have something stored.");
	return 1;
    }
    if(ob->drop() || ob->query("no store"))
        return notify_fail("You cannot store that!\n");
    people[this_player()->query_name()] = base_name(ob);
    seteuid(UID_VOTESAVE);
    if(path){
	if(!save_object(path)) write("Error saving object.");
    }
    else
	write("no path set.");
    seteuid(geteuid());
    write("You put your "+ob->query_short()+" in your locker.");
    ob->remove();
    return 1;
}
int get_thing(string str) {
    object ob;
    if(!people[this_player()->query_name()] ||
      people[this_player()->query_name()] == "") {
	write("You have nothing in your locker.");
	return 1;
    }
    if(this_player()->query_level() > 5) {
	if(this_player()->query_money("gold") < this_player()->query_level() * 3) {
	    write("You need "+(string)(this_player()->query_level()*3)+" gold"
	      " to pay for your storage!");
	    return 1;
	}
    }
    this_player()->add_money("gold",-(this_player()->query_level()*3));
    ob = new(people[this_player()->query_name()]);
    if(!ob) {
	write("It seems that your object cannot be found.  Please <bug> this error.\n");
	seteuid(UID_LOG);
	if(this_player()->query_name() == "whit") write("EUID: "+geteuid()+"\n");
	write_file("/adm/save/votes/error", "(reclaim) "+people[this_player()->query_name()]+
	  " for "+this_player()->query_name()+".\n");
	seteuid(geteuid());
	people[this_player()->query_name()] = "";
	seteuid(UID_VOTESAVE);
	if(path)
	    save_object(path);
	seteuid(geteuid());
	return 1;
    }
    people[this_player()->query_name()] = "";
    seteuid(UID_VOTESAVE);
    if(path)
	save_object(path);
    seteuid(geteuid());
    write("You get your "+ob->query_short()+" from your locker.");
    if(ob->move(this_player()) == MOVE_NO_ROOM) {
	write("Your hands are full and you drop your "+ob->query_short()+".");
	ob->move(environment(this_player()));
    }
    return 1;
}
void init() {
    ::init();
    add_action("save_thing", "store");
    add_action("get_thing", "reclaim");
}

string query_item(string who) {
  if(people[who])
    return people[who];
  return "Nothing stored.";
}
