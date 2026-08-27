//#pragma save_binary

//	File	:  /cmds/xtra/_event.c
//	Creator	:  Watcher@TMI  (12/14/92)
//
//	Command which allows users to input scheduled events to the
//	central event daemon for future initiation.

#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit DAEMON;

// If you wish to improve responce time, periodically update the
// BASE define settings to be closer to your present date and time.
// This will cut down on search time when the daemon is scheduling.

#define BASE	723967200			// Dec 10 00:00:00 1992
#define DAY	86400
#define MAX	( 31 * DAY )
#define TYPES	({ "once", "hourly", "daily", "weekly" })
#define MONTHS	({ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", \
		   "Sep", "Oct", "Nov", "Dec" })

#define SYNTAX	"Syntax: event [command] [stack]\n\n" + \
		"	event add	[once/hourly/daily/weekly]\n" + \
		"	event add root	[once/hourly/daily/weekly] (admin only)\n" + \
		"	event remove	[once/hourly/daily/weekly]\n" + \
		"	event list	[once/hourly/daily/weekly]\n"

protected int list_stack(string type);
protected int add_event(string type, int root);
protected int rem_event(string type);
protected int root_check(string perm);

int busy;

int cmd_event(string str)
{
	string type, form;
	int root, chinese_mode;

 	chinese_mode = can_read_chinese();
	notify_fail( SYNTAX );
	if(!str || str == "")	return 0;

	// Check busy flag to see if the daemon is presently in use
	if(busy) {
		write("Sorry, the event daemon is busy right now.\n" +
			"Please try again in a few minutes.\n");
		return 1;
	}

	if(sscanf(str, "add %s", type) == 1) {
		form = "add";

		// Check to see if root permission settings are requested
		if(sscanf(type, "root %s", type) == 1) {
			if(!root_check(geteuid(this_player()))) {
				write("Only admin may set root permission events.\n");
  				return 1;
  			}
			root = 1;
		}

		if(member_array(type, TYPES) == -1)
			return 0;
	}
	else if(sscanf(str, "remove %s", type) == 1) {
		form = "remove";
		if(member_array(type, TYPES) == -1)
			return 0;
	}
	else if(str == "list")	form = "list";
	else if(sscanf(str, "list %s", type) == 1) {
		form = "list";
		if(member_array(type, TYPES) == -1)
			return 0;
	}
	else return 0;

	if(form == "list") return list_stack(type);
	else if(form == "add") return add_event(type, root);
	else if(form == "remove") return rem_event(type);

	return 0;
}

protected int root_check(string perm)
{
	if(perm == ROOT_UID || member_group(perm, "admin"))	return 1;
	return 0;
}

protected int list_stack(string type)
{
	mixed *stack;
	int loop;

	if(!type || type == "") {			// Check all stacks
		write("Event Stack status:\n");

		for(loop=0; loop<sizeof(TYPES); loop++) {
			stack = EVENT->query_stack(TYPES[loop]);
			if(!stack || stack == ({ }))
				write(" The \"" + TYPES[loop] + "\" stack is presently empty.\n");
			else
				write(" The \"" + TYPES[loop] + "\" stack has " +
			sizeof(stack) + " events queued.\n");
		}
		return 1;
	}

	// Read in particular event stack for element check and display
	stack = EVENT->query_stack(type);

	if(!stack || stack == ({ })) {
		write("The \"" + type + "\" stack is presently empty.\n");
		return 1;
	}

	// Display queued contents of selected event stack
	write("The \""+ type + "\" stack presently contains:\n");

	for(loop=0; loop<sizeof(stack); loop++)
		if(atoi(stack[loop][3]))
			write(wrap(" " + (loop + 1) + "] " + stack[loop][2] + "(" + stack[loop][3]+
				") on " + stack[loop][1] + " by " + capitalize(stack[loop][4]) +
				" [" + extract(ctime(stack[loop][0]), 4, 15) + "]\n"));
		else write(wrap(" " + (loop + 1) + "] " + stack[loop][2] + "(\"" +
			stack[loop][3] + "\") on " + stack[loop][1] + " by " +
			capitalize(stack[loop][4]) + " [" +
			extract(ctime(stack[loop][0]), 4, 15) + "]\n"));

	return 1;
}

protected int rem_event(string type)
{
	mixed *stack;

	// Read in particular event stack for element check
	stack = EVENT->query_stack(type);

	if(!stack || stack == ({ })) {
		write("The \"" + type + "\" stack is presently empty.\n");
		return 1;
	}

	busy = 1;					// Set busy flag

	// Display selected stack and request deletion event number
	list_stack(type);
	write("\nDelete which event? [num]  ");
	input_to("del_number", 0, type);

	return 1;
}

protected int del_number(string str, string type)
{
	mixed *stack;
	int num;

	// Read in selected stack for removal processing
	stack = EVENT->query_stack(type);
	num = atoi(str);

	// Check to see if requested deletion is within event bounds
	if(num < 1 || num > sizeof(stack)) {
		write("There is no such event available for removal.\n");
		busy = 0;
		return 1;
	}

	// Check to see if permissions match or are ROOT to allow deletion
	if(!root_check(geteuid(this_player())) &&
		geteuid(this_player()) != stack[num - 1][4]) {
		write("You do not have the proper permissions to remove that event.\n");
		busy = 0;
		return 1;
	}

	// Tell event daemon to remove selected event
	if(!EVENT->remove_event( type, stack[num - 1] )) {
		write("Error:  Unable to remove requested event.\n");
		busy = 0;
		return 1;
	}

	write("Event " + num + " removed from \"" + type + "\" event stack.\n");
	busy = 0;

	return 1;
}

protected int add_event(string type, int root)
{
	busy = 1;					// Set busy flag on

	write("\nInput [target filename],[function],[optional argument]\n: ");
	input_to("receive_event", 0, type, root);

	return 1;
}

protected int receive_event(string str, string type, int root)
{
	object target;
	string obj, func, arg;

	if(sscanf(str,"%s, %s, %s", obj, func, arg) != 3 &&
		sscanf(str,"%s,%s,%s", obj, func, arg) != 3 &&
		sscanf(str,"%s,%s", obj, func) != 2) {
	write("\nIllegal event addition format.\n");
	busy = 0;  return 1; }

	if(catch( call_other(obj, "???") )) {
		write("Error: Could not access " + obj + "\n");
		busy = 0;
		return 1;
	}

	target = find_object(obj);

	if(!target) {
	write("Error: Could not locate " + obj + "\n");
	busy = 0;  return 1; }

	if(geteuid(target) == ROOT_UID && !root_check(geteuid(this_player()))) {
	write("You have insufficient permissions to access that object.\n");
	busy = 0;  return 1; }

	write("\nInput activation time [Format: mm/dd/yyyy 24:00]\n: ");
	input_to("process_time", 0, type, root, obj, func, arg);

	return 1;
}

protected int process_time(string str, string type, int root, string obj,
			string func, string arg)
{
	string when, permit, target;
	int date, month, day, year, hour, minute;

	if(!str || sscanf(str,"%d/%d/%d %d:%d",month,day,year,hour,minute) != 5) {
		write("Illegal activation time format.\n");
		busy = 0;
		return 1;
	}

	// Discard requests outside standard time/date bounds
	if(month < 1 || month > 12 || day < 1 || day > 31 || year < 1992 ||
		hour < 0 || hour > 24) {  busy = 0;  return 0;  }

	// Discard requests for >30 on 30 day months
	if((month == 9 || month == 4 || month == 6 || month == 11) && day > 30) {
		write("Illegal activation time format.\n");
		busy = 0;
		return 0;
	}

	// Discard requests for >27 on February requests
	if(month == 2 && day > 27) {  busy = 0;  return 0;  }

	date = BASE;				// Set date to base start point
	permit = geteuid(this_player());	// Set user's permission string

	if(root)  permit = "Root";		// If root is requested..set it

	when = "" + hour + ":" + minute + "";
	if(hour < 10) when = "0" + when;
	if(!minute)	when += "0";

	// Target specific day-search string
	if(day < 10) target = (MONTHS[month-1] + "  " + day);
	else target = (MONTHS[month-1] + " " + day);

	// Loop through each day for a string match
	// Yes, I know...kludgy...but it works.

	while(extract(ctime(date),4,9) != target) {
		if(date > (time() + MAX)) {
			write("That date is too far in advance of present date.\n");
			busy = 0;
			return 1;
		}
		date += DAY;
	}

	// Isolate exact time down to minute
	while(extract(ctime(date),11,15) != when) date += 60;

//	if(date <= time()) {
//		write("That time has already gone past. Pick a time in the future.\n");
//		busy = 0;
//		return 1;
//	}

	if(!EVENT->add_event(type, ({ date, obj, func, arg, permit }))) {
		write("Error: Could not add requested event.\n");
		busy = 0;
		return 1;
	}

	write("\nEvent added to the \"" + type + "\" event stack.\n");
	busy = 0;

	return 1;
}

int help()
{
	write(SYNTAX + "\n" +
	 "This command allows a user to add or remove an event into one of four\n" +
	 "event stacks (once, hourly, daily, weekly).  If an event is scheduled\n" +
	 "in the \"once\" stack, then it will occur once at its preset time,\n" +
	 "then is removed from the stack.  The other three stacks involve the\n" +
	 "event being called at its scheduled time, then rescheduled to the next\n" +
	 "time slot corresponding to that particular stack.  Individual stacks\n" +
	 "or the entire stack set can be listed using the \"list\" parameter.\n\n" +
	 "Only the scheduler, or an admin, can remove an event from a stack,\n" +
	 "and only an admin may set an event to root permissions.\n");

	return 1;
}
