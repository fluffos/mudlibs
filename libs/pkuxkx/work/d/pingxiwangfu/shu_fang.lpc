// Modified by iszt@pkuxkx, 2007-03-24

inherit ROOM;

void create()
{
	object con, item;
	set("short","书房");
	set("long", @LONG
这里便是平西王的书房。书房虽不大，却高爽宽敞，窗台明亮。堂中挂一幅
无名小画，设一张紫檀木书桌(desk)。桌凳之类，色色洁净。打扫得地下无纤毫
尘垢。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"corror3",
	]));
	set("no_beg",1);
	set("objects", ([
		__DIR__"npc/wusangui" : 1,
		__DIR__"npc/huyuan" : 4,
	]) );
	set("no_newbie_task",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string cock)
{
	object hu;
	int i;
	if(!(cock)||!(cock=="desk"))
		return notify_fail("你要推什么？\n");
	if (!(this_player()->query("permit")) )
	{
		for(i=0; i<4; i++)
			if( objectp( hu = present("hu yuan "+(i+1), environment(this_player())) ) )
			{
				message_vision("护院武士叫到：「哪里来的毛贼！」\n", this_player());
				hu->kill_ob(this_player());
			}
		message_vision("这里是王府，还是小心一点好。\n", this_player());
	}
	else
	{
		set("exits", ([ /* sizeof() == 4 */
			"down" : __DIR__"secret1",
			"south" : __DIR__"corror3",
		]));
		write("你推开书桌，发现了一条秘道。\n");
		remove_call_out("close");
		call_out("close",10,this_object());
		this_player()->delete("permit");
	}
	return 1;
}

void close(object room)
{
	message("vision","书桌缓缓地回到原位，将秘道封闭!\n",room);
	room->delete("exits/down");
}