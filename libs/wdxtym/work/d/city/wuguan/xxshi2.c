//xxshi2.c
inherit ROOM;

void create()
{
        set("short", "女休息室");
        set("long", @LONG
这里是武馆内的休息室，由于经常打扫地非常干净，所以屋子透出一股清
新的气息。一排床铺靠墙摆着，不断的有人进来休息或醒后离去，你也悄悄的
找个空铺睡了起来。
LONG);

        set("exits", ([              
	     "north" : __DIR__"zoulang7",
	]));

        set("sleep_room", 1);

     	set("no_fight", 1);

        setup();
}

void init()
{
        add_action("do_get", "get");        
        add_action("do_get", "drop");
}

int do_get()
{
        write("手脚轻一些，你不怕惊醒别人吗？！\n");
        return 1;
}

