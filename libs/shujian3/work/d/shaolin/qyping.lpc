// Room: /d/shaolin/qyping.c

inherit ROOM;

void create()
{
	set("short", "青云坪");
	set("long", @LONG
这里便是少室绝顶。极目望去，只见白云缕缕，如苍龙绕岭；嵩山拔翠
，似金刚擎天。山腰五道瀑布飞泻而下，石级蜿延曲折，宛若一条长虫，游
人纷纷其上，已如蚁蛭。面前的平地上寸草不生，正中三棵巨松围成一圈，
圈中央似乎有什么东西在闪闪发光。
LONG);
	set("exits", ([
		"southdown" : __DIR__"shulin14",
		"enter" : __DIR__"fumoquan",
	]));

	set("outdoors", "shaolin");
   	setup();
}
int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
	object *inv = deep_inventory(me);
	object *obj;
	obj = filter_array(inv,(:get_object:));

	if( sizeof(obj) && dir =="enter" )
            return notify_fail("有个威严的声音道: 休要鬼鬼祟祟地，将你背上的人放下来先。\n");
	if ( dir == "enter" && me->query("family/family_name") !="少林派" ){
          if ( present("huangjin nao", me) || present("jingang zhao", me) || present("fumo nao", me)
            || present("huangjin nao", environment(me)) || present("jingang zhao", environment(me))
            || present("fumo nao", environment(me)))
		return notify_fail("只听里面有人说道: 大侠上回已来过此处，此刻身携重宝，不便进入，\n恕老衲等失礼了。\n");
          }
	return ::valid_leave(me, dir);
}
