// wuhouci.c  诸葛亮殿 
inherit ROOM; 
void create() 
{ 
	set("short", "诸葛亮殿"); 
	set("long", @LONG 
这里是武侯祠的正殿诸葛亮殿。武侯羽扇纶巾一如生前。两边诸
葛瞻和诸葛尚父子塑像也栩栩如生。挂在殿门两壁的，由诗圣杜甫笔
下流露的千古名联：“三顾频繁天下事，两朝开济老臣心。”道尽了
这个千古风范的一生心事。殿角旁露出一个小洞(dong)。
LONG 
	);
	set("exits", ([ 
		"southdown" : __DIR__"liubeidian", 
	])); 
	set("item_desc", ([ 
		"【小洞】" : "一个在殿角边隐藏得很好的小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
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
			me->move("/d/gaibang/undercd"); 
			message("vision", 
				me->name() + "从洞里走了进来。\n", 
				environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


