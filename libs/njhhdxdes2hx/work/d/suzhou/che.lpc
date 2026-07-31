
inherit ROOM;

void create()
{
	set("short","马车");
	set("long", @LONG
    一辆四匹马拉的大车. 虽然不太好看,可是挺结实. 
马车夫坐在前面一甩鞭, 马儿就得得地跑起来.
LONG
	);

	setup();
}

void init()
{
	add_action("do_say","say");
}

int do_say(string arg)
{

	if(arg=="芝麻开门")
	{
		write("你的眼前一亮，车门打开了。\n");
               	set("exits/out", VOID_OB);
                remove_call_out("close");
       	        call_out("close", 5, this_object());
                return 1;
	}
	return 0;

}

void close(object room)
{
        message("vision","天上传来一声嘟囔：门开了，怎么不出去？\n", room);
        room->delete("exits/out");
}

int valid_leave(object me, string dir)
{
	this_object()->delete("youren");
	return ::valid_leave(me,dir);
}

