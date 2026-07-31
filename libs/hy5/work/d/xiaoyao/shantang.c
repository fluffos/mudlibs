// shantang.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "酒家");
	set("long", @LONG
这里是树林中的一间小小的酒家，地方虽然不大，但是也有不少逍遥派
的弟子光顾这里。你终于找到香味的来源了，看着可口的饭菜，你忍不住也
想叫 (order)一份了。
LONG );
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	set("ricewater", 5);
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/rice" : 5,
__DIR__"obj/bowl" : 3,
]));

	setup();
}
/*
void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
	object me;
	object food;
	object water;
	me=this_player();
	if (arg)  return notify_fail("小二哥跑出来道: 这样东西这里没有啊。\n");
	if (query("ricewater")>0)
	{
		message_vision("小二哥连声答应，从内厅一溜烟跑出来，端着一碗米饭和一碗水拿了给$N。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/bowl");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("小二哥在内厅对$N歉声应道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}
int valid_leave(object me,string dir)
{
	me=this_player();
if (me)
{
        if(dir=="north" && (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("小二说道：真抱歉，我们这里没有打包服务。\n");
}
        return ::valid_leave(me,dir);
}
*/