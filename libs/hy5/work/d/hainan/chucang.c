// Room: /d/hainan/chucang.c

inherit ROOM;

void create()
{
	set("short","白云庵储藏室");
	set("long", @LONG
用青石垒起来的一间储藏室.靠左边墙角有张床.....因为开了透气窗
的原因,所以一点都不显得气闷.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"shutang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/roujing_sword.c" : 3,
  "/d/shaolin/obj/qingshui-hulu" : 3,
"/d/shaolin/obj/mizhi-tianou" : 1,
"/d/shaolin/obj/jiaxin-biji" : 1,
"/d/shaolin/obj/basi-shanyao" : 1,		
"/d/shaolin/obj/furong-huagu" : 1,		
]));
 set("sleep_room", 1);
  set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_fan","xian");
}
int do_fan(string arg)
{
        object me,ob;   
        me = this_player();
        if (arg != "床板") return 0;
        if (me->query("family/family_name") != "白云庵")
                return notify_fail("你要干什么！！！\n");
        message_vision("$N掀开床板，忽然发现是一个地道的入口，你掉了下去。。。。\n\n",me);
        me->move(__DIR__"mishi");
        me->start_busy(2);
        return 1;
}

