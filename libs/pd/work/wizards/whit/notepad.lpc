#include <std.h>

inherit OBJECT;
mapping notes;

void save();
int query_auto_load() { if(this_player()->query_name() == "whit") return 1; return 0; }

void create() {
    ::create();
    set_name("Whit's Notepad");
    set_long("This is a notepad with all of Whit's various ramblings on it.");
    set_short("a notepad");
    set_id(({ "notepad", "whits notepad" }));
    notes=([]);
    restore_object("/wizards/whit/notepad");
}

void init() {
    ::init();
    add_action("write_note", "write");
    add_action("list_note", "list");
    add_action("read_note", "read");
    add_action("remove_note", "remove");
}

int read_note(string s) {
    int i;
    string *k;
    if(!s) i=0;
    i=to_int(s);
    if(!i) return notify_fail("Syntax: <read [#]>\n");
    i--;
    k=keys(notes);
    if(!i > sizeof(k)) return notify_fail("Invalid note.\n");
    if(!k[i]) return notify_fail("Error!\n");
    s="["+(i+1)+"]: "+k[i]+"\n-------------------------------------------------------------------\n";
    s += ""+notes[k[i]];
    write(s+"");
    return 1;
}

int remove_note(string s) {
    int i;
    string *k;
    if(!s) i=0;
    i=to_int(s);
    if(!i) return notify_fail("Syntax: <remove [#]>\n");
    i--;
    k=keys(notes);
    if(!i > sizeof(k)) return notify_fail("Invalid note.\n");
    if(!k[i]) return notify_fail("Error!\n");
    map_delete(notes, k[i]);
    write("You erase your note.");
    save();
    return 1;
}

int write_note(string s) {
    string title, note;
    if(!s || s=="") return notify_fail("Syntax: <write [title]:[note]>\n");
    if(sscanf(s, "%s:%s", title, note)!=2) return notify_fail("Syntax: <write [title]:[note]>\n");
   say(this_player()->query_cap_name()+" jots some notes on the notepad.");
    write("Note added.");
    notes += ([ title:note ]);
    save();
    return 1;
}

int list_note() {
    int i;
    string s="", *k;
    i=sizeof(k=keys(notes));
    if(!i) {
	write("There are no notes on the notepad.");
    }
    while(i--) s += "["+(i+1)+"]: "+k[i]+"\n";
    write(s+"");
    return 1;
}

void save() {
    save_object("/wizards/whit/notepad");
}

