//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "怡红院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下子
就明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里
妖气的女人分站两旁对你发出媚笑。一个老鸨婆连忙上前招呼客人。从楼
上传来了阵阵打情骂俏的声音。
LONG
);
	set("objects", ([
		__DIR__"npc/laobaopo" : 1,
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
		"south" : __DIR__"dongcha2",
		"up":	  __DIR__"library",
	]));

	setup();
	replace_program(ROOM);
}

