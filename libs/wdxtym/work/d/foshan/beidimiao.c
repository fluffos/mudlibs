// beidimiao.c  北帝庙 
inherit ROOM; 
void create() 
{ 
	set("short", "北帝庙"); 
	set("long", @LONG 
北帝庙坐北朝南。院子中一个大水塘，塘中石龟石蛇，昂然盘
踞。大殿神像石板上血迹殷然。北帝神像立于大殿正中。细看之下，
神像下面还有一个小洞。
LONG 
	);
	set("exits", ([ 
		"south" : __DIR__"street1", 
	])); 
	set("item_desc", ([ 
		"【神像】" : "在神像下隐藏仿佛有个小洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("no_fight", 1);
	set("valid_start_room", 1);
	set("no_sleep_room", 1);	
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
			me->move("/d/gaibang/underfs"); 
			message("vision", 
				me->name() + "从洞里走了进来。\n", 
				environment(me), ({me}) ); 
			return 1; 
		} 
		else  
			return notify_fail("这么小的洞，你钻得进去吗？\n"); 
	} 
} 


