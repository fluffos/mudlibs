// tuwu.c  小土屋
inherit ROOM; 
void create() 
{ 
	set("short", "小土屋"); 
	set("long", @LONG 
这是一座用黄土垒成的小屋，屋内打扫的很干净。四周的墙壁上
挂满了各种棍子，钎子，开山斧，小锯子等工具，看来似乎是采参所
用的工具。屋内西面的火炕上坐着一位上了年纪的老人，正在吸着旱
烟袋。角落里有一个小洞。
LONG 
	);
	set("exits", ([ 
		"north" : __DIR__"xiaoxiang", 
	])); 
	set("item_desc", ([ 
		"【小洞】" : "一个在角落里隐藏得很好的小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("outdoors", "guanwai"); 
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
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n", 
				environment(me), me); 
			me->move("/d/gaibang/undergw"); 
			message("vision", 
				me->name() + "从洞里走了进来。\n", 
				environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


