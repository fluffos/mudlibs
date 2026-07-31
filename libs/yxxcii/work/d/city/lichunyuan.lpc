// lichunyuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
int do_say(string arg);

void create()
{
	set("short", "丽春院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下子
就明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里
妖气的女人分站两旁对你发出媚笑。主人韦春芳上上下下、前前后后招呼
着客人。从楼上传来了阵阵打情骂俏的声音。
LONG );
	set("objects", ([
		CLASS_D("gaibang") + "/kongkong" : 1,
		__DIR__"npc/wei" : 1,
		"/d/city2/npc/mao18" : 1, 
	   ]));

	set("item_desc", ([
		"tu" :@TEXT
					  Ο	Ο	  Ο		 
					┌│	│	  │
	  ┌—Ο┌—  —┬——Ο	│┤	  ┌┘	  └┐
	—┘Ο—┘	————Ο  Ο——┘│  Ο—┼┴—  Ο——┴┼


   Ο	   Ο	ΟΟΟ		 Ο		  ○
   │	   │	│├┼	   ┌—Ο  ┌┼		  │
   ├ Ο┬┐┤	├└┼┐   —┘Ο——┘┤	  ○┬—┐┤
   │   ┘└│	│  │		 └		│  ││
TEXT
	]));
	set("exits", ([
		"west"  : __DIR__"nandajie2",
		"up"	: __DIR__"lichunyuan2",
	]));


	setup();
}
void init()
{
	add_action("do_say", "say");
}
int do_say(string arg)
{
	if( arg=="血海无边由我渡" ||  arg=="血海无边由我渡化") 
	{
		write("韦春花赶紧把你带到一间房里,在墙上按了一下。\n");
		message("vision", "一堵墙移来，出现道小门。\n", this_player());
		set("exits/down", "/d/xuedao/tulu1");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","只见小门又合上了。\n", room);
	room->delete("exits/down");
} 

