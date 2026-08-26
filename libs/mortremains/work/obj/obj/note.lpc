/*
* /obj/note.c 
*   - generic note object - Truilkan@TMI (92/04/15)
*   - intended to interact with the generic bulletin board /obj/bull_board.c
*
*/

#include <config.h>
#include <mudlib.h>

inherit OBJECT ;

string filename;
string header;
int dirty;

int clean_up()
{
	return 1;
}

void dirty_note()
{
	dirty = 1;
	set("long","Try copying, writing, shredding, reading, or tacking it.\n");
}

void remove()
{
	if (dirty)
		rm(filename);
	::remove();
}

void create()
{
	int pid;

	dirty = 0;
	sscanf(file_name(this_object()),"/obj/note#%d",pid);
	filename = "/tmp/note_" + pid;
	set ("id", ({ "note" }) ) ;
	set("short", "a note") ;
	set("long", "It's blank.\n") ;
}

void init()
{
	add_action("shred_note","shred");
	add_action("write_note","write");
	add_action("read_note", "read");
	add_action("tack_note", "tack");
	add_action("copy_note", "copy");
}

int shred_note(string arg)
{
	if (!id(arg)) {
		notify_fail("You can't shred that.\n");
		return 0;
	}
	write("You shred the note.\n");
	say((string)this_player()->query("cap_name") + " shreds a note.\n");
	remove();
	return 1;
}

int copy_file(string head, string file)
{
	if (!dirty) {
		dirty_note();
		header = head;
		cp(file,filename);
		return 1;
	}
	return 0;
}

int copy_note(string arg)
{
	object note;

	if (!id(arg)) {
		notify_fail("You can't copy that.\n");
		return 0;
	}
	seteuid(getuid(this_object()));
	note = clone_object("/obj/note");
	note->copy_file(header,filename);
	note->move(this_player());
	return 1;
}

int tack_note(string arg)
{
	object board;

	if (!id(arg)) {
		notify_fail("You can't tack that.\n");
		return 0;
	}
	if (!(board = present("board",environment(this_player())))) {
		write("You don't see a place to tack it.\n");
		return 1;
	}
	this_player()->set_edit_filename(filename);
	board->postit(header);
	write("You tack a note on the board.\n");
	say((string)this_player()->query("cap_name") +
		" tacks a note on the board.\n");
	remove();
	return 1;
}

int read_note(string arg)
{
	if (!id(arg)) {
		notify_fail("You can't read that.\n");
		return 0;
	}
	say((string)this_player()->query("cap_name") + " reads a note.\n");
	this_player()->more(filename);
	return 1;
}

int write_note(string arg)
{
	header = arg;
	say((string)this_player()->query("cap_name") + " is writing a note.\n");
	/* still need a safer tmp area where other users can't read everything */
	this_player()->edit(filename, "postit", this_object());
	return 1;
}

int postit()
{
	dirty_note();
	return 1;
}
