// xilingqiao.c  西泠桥
inherit ROOM; 
void create() 
{ 
	set("short", "西泠桥"); 
	set("long", @LONG 
西泠桥衔结孤山，跨过里西湖。桥的东南边是孤山。北边则是一 
条青石大道。桥下有一个小洞。
LONG 
	);
	set("exits", ([ 
		"southeast" : __DIR__"gushan",
	      "north"     : __DIR__"road7",
	])); 
	set("item_desc", ([ 
		"【小洞】" : "一个在桥下隐藏得很好的小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("outdoors", "hangzhou"); 
	set("no_clean_up", 0);       
	setup(); 
} 
      
void init() 
{ 
	add_action("do_enter", "enter"); 
	add_action("do_enter", "zuan"); 
} 

int do_enter(string arg) 
{ 
	object me; 
	mapping fam; 
       
	me = this_player(); 
	if (! arg || arg == "") return 0; 
	if (arg == "dong") 
	{ 
		if (me->query("family/family_name") == "丐帮")  
		{ 
			message("vision", 
				me->name() + "运起丐帮缩骨功，一弯腰往洞"
					     "里钻了进去。\n", 
				environment(me), me); 
			me->move("/d/gaibang/underhz"); 
			message("vision", 
				me->name() + "从洞里走了进来。\n", 
				environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


