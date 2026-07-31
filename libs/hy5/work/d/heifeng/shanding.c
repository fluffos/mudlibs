// Room: /d/heifeng/shanding.c

inherit ROOM;

void create()
{
	set("short", "山顶空地");
	set("long", @LONG
这里是黑风山的最顶峰，山风更加强劲，四周都是陡直的山
壁，下临万丈悬崖，偶尔向下瞟一眼都让人不寒而颤。向东北方
向眺望隐约能够看到京都长安。空地正中有一根不高但很是粗大
的木杆，上面挂着一幅黄穗镶边的黑旗，上面绣着“黑风寨”三
个斗大的白字。
LONG
	);

	set("outdoors","heifeng");

	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"downlu1",
]));
        set("objects", ([
             "/d/huanghe/yyd/npc/xiaozh" : 1,

        ]));


	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if(!arg || arg != "down")
		return 0;

	write("你小心翼翼地向下爬去。\n");
	me->start_busy(1);
	me->move(__DIR__"houshan");
	return 1;
}
