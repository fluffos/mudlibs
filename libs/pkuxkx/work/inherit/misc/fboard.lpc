// fboard.c
//比武大会记录板
// by aiai       98/9/14
//modify by yuer

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_discard", "discard");
	
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + HIW"【没有任何比武记录】"NOR;

	return ::short();

}

string long()
{
	mapping *notes;
	int i;
	string msg, myid;

	notes = query("notes");

	msg = query("long");

	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

    for(i=sizeof(notes)-1; i>=0; i--)
          msg += sprintf("[%2d]"+"        "+HIG"%-30s"NOR+" %12s (%s)\n",
			i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
	this_player()->start_more(msg);
	return "";
}


int do_record(string arg)
{
	mapping note;
        mapping *notes;
	
	if(!arg) return 0;
	note = allocate_mapping(3);
	note["title"] = arg;
	note["author"] = "铁游夏";
	note["time"] = time(); 
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	save();
	return 1;
}
int do_discard(string arg)
{
	mapping *notes;
	int num;
	if(!wizardp(this_player())) return notify_fail("玩家不能删除记录\n");

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( 	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
	&&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
		return notify_fail("你无权修改这里\n");

        notes -= ({ notes[num] });
	set("notes", notes);
	save();
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	return 1;
}
