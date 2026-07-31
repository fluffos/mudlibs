// dawu.c 林中大屋 
inherit ROOM; 
	
void create() 
{ 
	set("short", "林中大屋"); 
	set("long", @LONG 
这是一幢原木制成的三层高大建筑，看上去已有些年月但仍坚固
异常，底层是由数根巨木架空，一座木梯通向二楼，三楼的楼顶上挂
着一面绣着一条青龙的大旗，看上去已破旧不堪。人们只知道主人姓
李。墙角有一个不起眼的小洞。
LONG 
	);
	set("exits", ([ 
		"west"     : __DIR__"kongdi", 
	])); 
	set("item_desc", ([ 
		"【小洞】" : "一个在墙角边隐藏得很好的小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	])); 
	set("objects", ([ 
		 __DIR__"npc/ye" : 1,
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
			message("vision", me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n", environment(me), me); 
			me->move("/d/gaibang/underlz"); 
			message("vision", me->name() + "从洞里走了进来。\n", environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


