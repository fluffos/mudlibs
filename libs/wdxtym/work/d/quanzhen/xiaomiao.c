// xiaomiao.c 土地庙 
inherit ROOM; 
void create() 
{ 
	set("short", "土地庙"); 
	set("long", @LONG 
这座庙宇原本是武功镇中的土地庙，不过因为很久没有修缮过， 
已经破烂不堪。土地爷的金身也只剩下了半截，供桌只剩下了三条 
腿，窗框已经全被下光了，被附近的贫苦百姓拿回家去生火取暖。 
这里平常是没有人来的，只有一些游手好闲的地痞流氓之类把这里 
当做了家。供桌下隐约露出了一个小洞。
LONG 
	);
	set("exits", ([ 
		"north" : __DIR__"xijie", 
	])); 
	set("item_desc", ([ 
		"【供桌】" : "一个只剩三条腿的破旧供桌，供桌下有个隐藏得很好的小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	])); 
	set("objects", ([ 
		 __DIR__"npc/dipi" : 1,
	]));	
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
			me->move("/d/gaibang/underwg"); 
			message("vision", 
				me->name() + "从洞里走了进来。\n", 
				environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


