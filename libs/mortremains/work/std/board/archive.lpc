//
//	archive.c
//
// retrieve's archived boards.
//
// Original author unknown, seriously re-worked by Zak, 930314.
// (someone else @ TMI added SAVE_EXTENSION fixes 930506... who were you?)
// Zak, 930619: updated for new bboard object (WRT last_mod, etc)
// Yeah, except for failing to declare last_mod as a variable ;) 
// Moby took care of that on 6-28-93.

//

inherit "/std/board/bboard";

nosave string *files, curname;
nosave int cur_arc;
nosave int last_mod;

void
generate_files()
{
    int i, j, l, lse;
    string *tf;

    files = get_dir(query_attic_dir());
    if (!files)
	files = ({ });
    j = sizeof(files);
    i = j;
    tf = allocate(i);
    while (i--) {
	l = strlen(files[i]);
        lse = strlen(__SAVE_EXTENSION__);
	if (files[i][l-lse..l-1] != __SAVE_EXTENSION__)
	    continue;	// must be format: x.o
	if (l < 11+lse)
	    continue;	// must be format: x_999999999.o
	tf[--j] = files[i][l-(9+lse)..l-(lse+1)] + files[i][0..l-(11+lse)];
    }
    files = tf[j..sizeof(tf)-1];
}


string
query_short()
{
    if (!cur_arc)
	return sprintf("%s (%d archived boards)",
			bboard::query_short(),
			sizeof(files));
    else
	return sprintf("%s (archive: %s, # %d of %d)",
			bboard::query_short(),
                        curname,
			cur_arc,
			sizeof(files));
}

string
query_long()
{
    return bboard::query_long() + @ENDARC

Archive board commands: `list' to list archives, `retrieve #' to
load an archive into this board, `read #' to read a note in the
current archive, and `mailnote #' to mail a note to yourself

ENDARC
;
}


void
init()
{
    add_action("list","list");
    add_action("retrieve","retrieve");
    add_action("read", "read");   // use read func in bboard.c
    add_action("mail_note", "mailnote");
}


int
list(string arg)
{
    int		i, j, l;

    j = sizeof(files);
    for (i = 0; i < j; i++) {
	l = strlen(files[i]);
	printf("%3d (%s) %s\n", (i+1),
	    get_time(to_int(files[i][0..8])), files[i][9..l-1]);
    }
    return 1;
}


int
retrieve(string arg)
{
    int i;
    string base;
    if (!arg) {
	notify_fail("usage: retrieve #\n");
	return 0;
    }
    sscanf(arg,"%d",i);
    if (i < 1 || i > sizeof(files)) {
	notify_fail("Not that many archived boards\n");
	return 0;
    }
    i--;
    curname = extract(files[i], 9);
    base = curname + "_" + files[i][0..8];
    restore_object(query_attic_dir() + base);
    num_messages = sizeof(messages);
    cur_arc = i + 1;
    last_mod = time();
    return 1;
}


void
set_attic_dir(string s)
{
    bboard::set_attic_dir(s);
    generate_files();
}


void
create()
{
    bboard::create();
    set("short.text", "Archive Board");
    set("long.text", @ENDLONG
An empty archive board.
ENDLONG
);
    generate_files();
    last_mod = time();
    board_set = "board/archive";
}
