// cjgqian.c 藏经阁小院
// seagate@pkuxkx by 2011.02.17

inherit ROOM;

void create()
{
	set("short", "藏经阁小院");
	set("long", 
"幽静的竹林深处一条青石小径通向了一幢三层的小楼，楼前到处都是僧兵。\n"
	);
	
	set("exits", 
	  ([ "enter":"/d/shaolin/zhulin5",
	  	 "west": __DIR__"cjg1" ]));

	set("objects",([
    __DIR__"npc/huangmeiseng":1]));

  set("no_fight", 1);
  set("no_perform", 1);

  set("outdoors", "shaolin/cjg");	
	setup();
}

void init()
{
	object me=this_player();
	
	me->delete_temp("pfm_skip");
	if ( userp(me) &&
		   me->query_temp("cjg/teams")>2 &&
		   !me->query_temp("cjg/teams3") )
	{
	  me->set_temp("cjg/teams3", sizeof(me->query_team()));


	}
	add_action("do_none","exert");
  add_action("do_none","team");
}

int do_none()
{
	write("这里你就老老实实呆着吧！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir=="out" )
		return notify_fail("竹林里面危险重重，你好不容易到了这里，还是不要再冒险了。\n");
	else
		return ::valid_leave(me, dir);
}