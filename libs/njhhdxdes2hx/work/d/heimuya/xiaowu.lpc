// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
这是一间极其普通的小屋，但它出现在这里却显得有些诡异。你仔
细向四下里打量着，希望有所发现。看来西面的墙似乎有些与众不同也
许隐藏着什么秘密也说不定。
LONG
        );

	set("exits", ([
		"south" :__DIR__"cdd",
	]));
        create_door("south", "铁门", "north", DOOR_CLOSED);

	setup();
}


void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if( (arg == "west" )&&(!query("is_here")))
        {
	                 message("vision", 
"地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
                        this_object() );

	 set("exits/down", __DIR__"midao/midao1");
	 call_out("close_passage", 10);

	 return 1;
	}
	else
	{
	write("你要推什么?\n");
	return 0;
	}	

}
void close_passage()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision", 
"地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖住了。\n",
                this_object() );
        delete("exits/down");
}


