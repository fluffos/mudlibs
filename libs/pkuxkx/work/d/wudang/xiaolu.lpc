// xiaolu.c 小路
// seagate@pkuxkx 2010/10/30
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
双井子村中的小路，村子里只有稀稀落落的几件草屋，
村子里只留下几个老人小孩，自从土匪在附近落地生根以
后，能走的似乎都走了。
LONG
	);
  set("outdoors", "wudang");

	set("exits", ([
		"northwest" : __DIR__"cunkou",
		"west" : __DIR__"caowu1",
		"south" : __DIR__"caowu2",
	]));


//  "/newbiequest/wudang/fighter/fight_config"->init_virtualMap();
//  set("refreshtime",time());
	setup();
}

void init()
{
	add_action("do_look", "look");
  if(time()-query("refreshtime")>3600*12) {
 		this_player()->start_busy(1);
    "/newbiequest/wudang/fighter/fight_config"->init_virtualMap();
    "/newbiequest/wudang/fighter/fight2_config"->init_virtualMap();
    set("refreshtime",time());
  }
}

int valid_leave(object me, string dir)
{
  if(dir=="enter"&&
  	 (!userp(me) || 
  	  !me->query_temp("quest_fighter") || 
  	  time() - me->query_temp("quest_fighter/fight_stime")>=360 ) )
  	return notify_fail("前面的小树林中不时发出几声惨叫声，还是不要再往里走了！\n");
  else
  	return ::valid_leave(me, dir);
}

int do_look(string arg)
{
	if (arg=="enter") 
	{
		write("树林里面一片雾蒙蒙的啥也看不清楚。\n");
		return 1;
	}
	else 
		return 0;
}