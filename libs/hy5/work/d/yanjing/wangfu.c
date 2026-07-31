// Room: /d/yanjing/wangfu.c

inherit ROOM;

void create()
{
	set("short", "赵王府");
	set("long", @LONG
朱红的大门之前左右旗杆高耸，两头威武狰狞的玉石狮子盘坐门旁
一排白玉阶石直通到前厅，势派豪雄之极。大门正中写着“赵王府”三个
金字。赵王就是大金国的六皇子完颜洪烈.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinbing.c" : 4,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianyuan",
  "south" : __DIR__"street4",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
}

int valid_leave(object me,string dir)
{
	object npc1,npc2;

	npc1=present("qin bing",this_object());
	npc2=present("qin bing 2",this_object());

	if(dir=="north" && objectp(npc1) && living(npc1))	{
		write("王府亲兵喝道：竟敢私闯赵王府，给我拿下！\n");
		npc1->kill_ob(me);
		me->fight_ob(npc1);
	}
	if(dir=="north" && objectp(npc2) && living(npc2))	{
		write("王府亲兵喝道：我看你是吃了豹子胆了，竟敢找赵王爷的麻烦！\n");
		npc2->kill_ob(me);
		me->fight_ob(npc2);
	}
	if(dir=="north" && ((objectp(npc1)&&living(npc1))||
	(objectp(npc2)&&living(npc2)))) 
	return notify_fail("王府亲兵拦住你的去路！\n");
	return ::valid_leave(me,dir);
}

		
