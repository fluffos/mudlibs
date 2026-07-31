//writen by lnwm
//gudi.c

inherit ROOM;
void create()
{
    set("short", "谷地");
    set("long", @LONG
你眼前豁然一阵开阔,群山都已在你的脑后,山势陡然一缓,一个包于群山之中
的山谷在你脚下.谷中芳草如茵.一条小溪潺潺从北侧一个山坳中流出,然后在谷中
折了几个来回后向南经直而去了.将你的视线穿越谷地向西. 你能看到远远的的天
边有高耸入云的雪峰矗立.那里就是青藏高原天然的屏障.
LONG
        );
    set("exits", ([ 
	    "east"      :       __DIR__ "outshangu", 
    ]));
    set("item_desc", ([
        "山坳"     :	 "被绿树所掩的山坳，周围的草有些倒伏，似乎有人经常出入。\n",
        ]) );
    set("outdoors","lnwm");
    setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_enter","go");
}

int do_enter(string arg)
{
    object me;
    if(!arg || arg=="")
    {
        write("你要去哪？\n");
        return 1;
    }
    if( arg == "shanao" || arg == "山坳" )
    {
        me = this_player();
		if((int) me->query("combat_exp") >= 100000 )
    	{
		message_vision("$N向山坳走去。\n", me);
		me->move(__DIR__ "shanpo");
		return 1;
		}
		else
        {
			tell_object(me,"你忽然有些害怕，刚抬起的脚又缩了回去。\n");
        	return 1;
		}
    }
}    