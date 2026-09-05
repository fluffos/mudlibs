// hsljboard.c
//华山论剑报名板
// by yuer

#include <ansi.h>


#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

int do_baoming();
int do_cancel();

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

	add_action("do_cancel", "cancel");
	add_action("do_baoming","baoming");
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
		return ::short() + HIW"【没有报名记录】"NOR;

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


int do_baoming()
{
	mapping note;
        mapping *notes;
	object me;
	int num;
	string str;
	me = this_player();

    if((me->query("combat_exp"))<4000000) return notify_fail("您的经验不足,还是不要参加的好.\n");
	notes = query("notes");

	for(num = 1; num<=sizeof(notes); num++)
	if( (notes[num-1]["register"] == me->query("name")) && (notes[num-1]["register_id"] == me->query("id"))) return notify_fail("你已经报过名了.");
	

	note = allocate_mapping(5);
	note["title"] = me->query("name")+"("+me->query("id")+")报名";
	note["author"] = "华山论剑";
	note["time"] = time(); 
	note["register"] = me->query("name");
	note["register_id"] = me->query("id");
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
	message_vision(HIY "$N报名参加华山论剑.\n" NOR, this_player());
	return 1;
}

int do_cancel()
{
	mapping *notes;
	int num;
	object me;
	me = this_player();

	notes = query("notes");
	for(num = 1; num<=sizeof(notes); num++)
	{
		if( (notes[num-1]["register"] == me->query("name")) && (notes[num-1]["register_id"] == me->query("id"))) 
	        {	
		notes -= ({ notes[num-1] });
		set("notes", notes);
		save();
		message_vision(HIY "$N取消参加华山论剑.\n" NOR, this_player());
		return 1;
		}
	}
	return notify_fail("你没有报过名.");
	return 1;
}
