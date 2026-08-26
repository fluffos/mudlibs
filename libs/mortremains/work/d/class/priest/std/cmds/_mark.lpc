/*
** File: _mark.c
** Purpose: Creating marked sites for teleportation.
** Credits:
**   01 Jan 97   Cyanide wrote the file.
*/

#include <teleport.h>
#include <mudlib.h>

#define SYNTAX "Syntax: "mark" or "mark here"\n"

inherit DAEMON;

int cmd_mark(string str) {
    mapping marks;
    string *mark_names;
    object *mark_rooms;
    object tmp;
    int i;

    seteuid(getuid());

    if (TP->query("teleport_marks"))
	marks = TP->query("teleport_marks");
    else
	marks = ([]);

    mark_names = keys(marks);
    mark_rooms = values(marks);

    if (sizeof(mark_names)>=(TP->query_level()/2)) {
	write("You cannot have more marked sites than half your level.\n"+
	  "");
	return 1;
    }

    if (!str) {
	if (!sizeof(mark_names)) {
	    write("You do not yet have any marked sites.\n");
	    return 1;
	}
	str = "Marked sites:\n";
	for (i=0; i<sizeof(mark_names); i++) {
	    string Name;
	    object ob = mark_rooms[i];

	    if (!ob)
		Name = "";
	    else 
		Name = ob->query("short");

	    if (!ob || !Name) Name = "(Error in room)";   

	    str += sprintf("   %-15s   :   %-35s\n", mark_names[i], Name);
	}
	str += "Total number of marked sites: " + sizeof(mark_names) +
	" (Max: " + (TP->query_level()/2) + ")\n";

	write(str);
	return 1;
    }

    if (member_array(str, mark_names)!=-1) {
	write("\""+capitalize(str)+"\" is already in your marks list.\n");
	return 1;
    }

    if (environment(TP)->query("no_teleport")==NO_IN_OR_OUT ||
      environment(TP)->query("no_teleport")==NO_IN) {
	write("This room is teleport locked. You cannot mark it.\n");
	return 1;
    }

    marks += ([ str : base_name(environment(TP)) ]);
TP->set("teleport_marks", marks);

write("You have added "+environment(TP)->query("short")+
  " To your marks list.\n");
return 1;
}



