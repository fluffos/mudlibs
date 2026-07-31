//ROOM: xiaoshe.c

inherit ROOM;

void create()
{
	set("short", "小舍");
        set("long", @LONG
这是一间用翠竹搭成的小舍。一进门，便闻到一阵浓烈的花
香，房中挂着一幅仕女图，椅上铺了绣花锦垫，东边有一扇门，
挂着绣了一丛牡丹的锦缎门帏。难道这是谁家姑娘的闺房？
LONG    );
        set("exits", ([
            "east" : __DIR__"neishi",
            "out" :__DIR__"xiaohuayuan",
            "enter" :"/d/jinyong/book8/heimuya/neishi",
        ]));
        set("no_clean_up", 0);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
  	if(((int)me->query("jinyong/book8")!=8)&&(dir == "enter"))
	{
		return notify_fail("里面高手过招，刀枪无眼，不要进去找死了。\n");
	}
//return notify_fail((int)me->query("jinyong/book8"));
	return ::valid_leave();
}

