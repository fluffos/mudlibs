/*  -*- LPC -*-
 *
 * QuickEditor 0.3T
 * Copyright (C) 1996 Cameron Kaiser (Evergreen) (ckaiser@ucsd.edu)
 *
 * This program is part of the OpenLib Mudlib distribution; it
 * is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * If you acquired this program as part of the OpenLib Mudlib
 * distribution, you should have received a copy of the GNU
 * General Public License in the file /doc/GPL; if not,
 * write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * Modified by Tim to use function pointers when OLD_MUDOS is _not_ defined.
 *     Also added VERSION define for ease of update.
 */

#include <mudlib.h>

#define VERSION "0.3T"

/* 
 * Define OLD_MUDOS if you're using:
 *
 * Anything that doesn't support [x..<y] array addressing (probably 20.x)
 * Have 0.9.19 (though personally I bet you'll still have some porting to do)
 * Are getting strange behaviour or can't compile this
 *
 * You should not need to define this with v22 and up, but if it doesn't
 * work, you might try it.
 *
 */
#undef OLD_MUDOS 


#define COMMANDS ([ "h" : "help", "d" : "delete", "i" : "insert", "f" : "insert_file", "v": "view_file", "q" : "ederror" , "e" : "jump_to_end", "r" : "ruler", "V" : "short_view_file" ])
#define RULER "     .........1.........2.........3.........4.........5.........6.........7\n"

inherit DAEMON;

#ifdef OLD_MUDOS
string *tbuf;
mixed *call_g;
int line;
#else
private string *tbuf;
private function call_g;
private int line;
#endif

void prompt();


// Because we're using the cardinal sin, a global variable, we have
// to clone instances of this object. edit() will handle this for us.


// Function name: edit
//
// If OLD_MUDOS is defined:
//
// Call this with an array of things to call back to, such as:
// ({ this_object(), "function", args, args ... })
// plus the starting buffer.
//
// Note that the starting buffer is optional, e.g. edit(({ ... }))
// starts with an empty buffer, and edit (({ ... }), ({ buf })) uses
// buf as the buffer, etc. You should get the idea.
//
// You should prototype the destination function as:
//
// public varargs destination_function(string *buf);
//---------------------------------------------------
// If OLD_MUDOS is undefined:
// 
// call like:   EDITOR_D->edit((: callback_func :));
//   OR         EDITOR_D->edit((: callback_func :), ({ ... }));
//
// Your callback function should look something like:
//
// public varargs void callback_func( ... , string* buffer);
//
// Of course this depends on how many arguments you pass in the function
// pointer.

#ifdef OLD_MUDOS
varargs void edit(mixed *call_back, string *ibuf) {
	object ob;

	if (!call_back || sizeof(call_back) < 2) 
		error("Required call_back to QuickEditor not present\n");
	call_back += ({ 0 }); // for ease of handling
#else
public varargs void edit(function call_back, string *ibuf) {
	object ob;

	if (!call_back) 
		error("Required call_back to QuickEditor not present\n");
#endif
	if (!ibuf) ibuf = ({ }); else write("Loading buffer (lines: "+
		sizeof(ibuf)+")\n\n");
	ob = clone_object(file_name(this_object()));
	if (!ob) error("Couldn't start editor (clone_object() returned 0)");
	ob->start_edit(call_back, ibuf);
}

// No other functions need be called from hence onward.

#ifdef OLD_MUDOS
void start_edit(mixed *call_back, string *ibuf) {
#else
void start_edit(function call_back, string *ibuf) {
#endif

// By this time, we can safely assume we're within a clone of the editor,
// so global variables should be no problem.

	call_g = call_back;
	line = sizeof(ibuf);
	tbuf = ibuf;
	write(""+
"     QuickEditor v" + VERSION + " (Evergreen)\n"+
"     Enter ~h on a blank line for help, or ** to save buffer and quit.\n"+
	RULER+
	"");
	prompt();
}

void prompt() {
	write(((line+1)+"    ")[0..3]+">");
	input_to("line_input");
}

void line_input(string str) {
	int i;

	if (str == "~q") {
		write("(aborted!)\n");
#ifdef OLD_MUDOS
		call_other(call_g[0], call_g[1], 0, call_g[2..-1]);
#else
                evaluate(call_g, 0);
#endif
		destruct(this_object());
		return; }
	if (str == "**" || str == ".")  {
#ifdef OLD_MUDOS
		call_other(call_g[0], call_g[1], tbuf, call_g[2..-1]);
#else
		evaluate(call_g, tbuf);
#endif
		destruct(this_object());
		return; }
	if (!str || str == "") str = " ";
	if (str[0..0] != "~") {
// "Insert a line at the line position code" is here.
#ifdef OLD_MUDOS
		if (sizeof(str) >= 2 && str[-2..-1] == "//") {
#else
		if (sizeof(str) >= 2 && str[<2..<1] == "//") {
#endif
			write("(ignored line)\n");
			prompt();
			return;
		}
		if (!tbuf || line == sizeof(tbuf)) {
			line++;
			tbuf += ({ str });
		} else {
			if (!line) {
				tbuf = ({ str }) + tbuf; 
				line++;
			} else 
				tbuf = tbuf[0..(line-1)] + ({ str }) +
					tbuf[(line++)..(sizeof(tbuf)-1)];
		}
		prompt();
		return;
	}
	if (str == "~") {
		write("(no ~ command given)\n");
		prompt();
		return; }
	if (sizeof(str) < 2) 
		str += "0000";
#ifdef OLD_MUDOS
	sscanf(str[2..-1], "%d", i);
#else
	sscanf(str[2..<0], "%d", i);
#endif
	if (!COMMANDS[str[1..1]]) {
		write("(Unknown ~ sequence! Type ~h for help.)\n");
		prompt();
		return;
	}
#ifdef OLD_MUDOS
	call_other(this_object(), COMMANDS[str[1..1]], i, str[2..-1]);
#else
	call_other(this_object(), COMMANDS[str[1..1]], i, str[2..<0]);
#endif
	prompt();
}

help(int ignore1, string ignore2) {
	write(""+
"--- Help for version " + VERSION + " QuickEditor ---\n"+
"\n"+
"Enter your text at the line prompt (e.g., 1 >>.) The text will be inserted\n"+
"at that line position. Type // at the end of a line to ignore it.\n"+
"\n"+
"Type ** or . alone on a line to exit and \"save\" your typing.\n"+
"\n"+
"The following ~-sequences must be typed alone on a line.\n"+
"~h		This help.\n"+
"~r 		Display ruler.\n"+
"~q		Abort edit.\n"+
"~v		List the entire text entered so far. Bad for long files.\n"+
"~V		View the last few lines from the current position, or, with\n"+
"		an argument, view a few lines at that point. e.g.  ~V35\n"+
"~f[filename]	Insert a file at this point. THE PATH MUST BE COMPLETE.\n"+
"		e.g. ~i/players/evergreen/embarrassing.document\n"+
"~d[line]	Delete a line. e.g. ~d5\n"+
"~i[line]	Start inserting at a certain line number. e.g. ~i5\n"+
"		lets you insert starting above line 5.\n"+
"~e		Jump to the end.\n"+
	"\n");
}

view_file(int ignore1, string ignore2) {
	int i, j;

	write("(viewing file)\n\n"+RULER);
	for (i=0, j=sizeof(tbuf); i<j; i++) 
		write(((i+1)+"    ")[0..3]+"|"+tbuf[i]+"\n");
}

short_view_file(int where, string ignore2) {
	int i, j, k;

	if (!where)
		i = ((sizeof(tbuf) < 15) ? 0 : (line-16));
	else {
		if (where > (sizeof(tbuf)+1)) {
			write("(position exceeds buffer size)\n");
			return; }
		i = --where; }
	if (i < 0) i = 0; // oops!
	k = (((i+15) > (sizeof(tbuf)-1))  ? (sizeof(tbuf)-1) : (i+15));
	write("(viewing chunk)\n"+RULER);
	for (j=i; j<=k; j++) 
		write(((j+1)+"    ")[0..3]+"|"+tbuf[j]+"\n");
}

ruler(int ignore1, string ignore2) { write(RULER); }

insert(int where, string ignore) {
	if (where > (sizeof(tbuf)+1)) {
		write("(position exceeds buffer size)\n");
		return; }
	if (!where) {
		write("(invalid insert position)\n");
		return; }
	line = --where;
}

jump_to_end(int ignore1, string ignore2) { 

// This means I don't have to write an ~a call as well to append.
// Just ~i to the line you want to insert in front of, and ~e for the end.

	write("(jumping to end)\n");
	line = sizeof(tbuf); }

delete(int where, string ignore) {
	if (where > (sizeof(tbuf)+1)) {
		write("(position exceeds buffer size)\n");
		return; }
	if (!where) {
		write("(invalid delete line)\n");
		return; }
	write("(deleted line "+where+")\n");
	where--;
	if (!where)
#ifdef OLD_MUDOS
// God, I'm sick of this define!
		tbuf = tbuf[1..-1];
#else
		tbuf = tbuf[1..<0];
#endif
	else
		if (where == sizeof(tbuf))
#ifdef OLD_MUDOS
			tbuf = tbuf[0..-2];
#else
			tbuf = tbuf[0..<1];
#endif
		else
#ifdef OLD_MUDOS
			tbuf = tbuf[0..(where-1)] + tbuf[(where+1)..-1];
#else
			tbuf = tbuf[0..(where-1)] + tbuf[(where+1)..<0];
#endif
	if (line >= where)
		line--;
}

insert_file(int ignore1, string file) {

// You should add a hook here to catch non-wizards trying to use this.
// However, since they can't have files anyway, there ought to be little
// difficulty if your master object is fairly astute.

	string s, *abuf;

	if (!file) {
		write("(insert which file?)\n");
		return; }
	if (file[0..0] != "/") {
		write("(must specify full pathname to insert file)\n");
		return; }

// You're probably asking, why didn't I do something like this_player()->
// expand_path() or something? The reason is, I don't like using a lot
// of lib-dependent lfuns, and this code is supposed to be portable.
// If you want it, fix it for yourself.

	if (file_size(file) < 1) {
		write("(nonexistent file, empty file, or no access)\n");
		return; }
	write("(loading "+file+")\n");
	s = read_file(file);
	abuf = ((s) ? explode(s,"\n") : ({ }));
	if (!abuf || !sizeof(abuf)) {
		write("(error occurred while loading file!)\n");
		return; }
	write("(inserting lines (total: "+sizeof(abuf)+"))\n");
#ifdef OLD_MUDOS
	tbuf = tbuf[0..(line-1)] + abuf + tbuf[(line+1)..-1];
#else
	tbuf = tbuf[0..(line-1)] + abuf + tbuf[(line+1)..<0];
#endif
	line += sizeof(abuf);
}

ederror() {

// This is a catch-all, but it only catches one thing so far.

	error("Logic error in QuickEditor (buffer lost!)\n"+
		"Debug stack:\n\n"+
		implode(call_stack(), "\n"));
}
