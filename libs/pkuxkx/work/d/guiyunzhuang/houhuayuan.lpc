// houhuayuan.c 后花园
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是归云庄的后花园，种满了花草。几个庄仆正在浇花
西边是归云馆，庄主常在那里会客。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south": __DIR__"houhuayuan1",
  "west" : __DIR__"guan",
  "east" : __DIR__"taolin",
 ]));
        set("objects", ([/* sizeof() == 1*/
		__DIR__"npc/axiang":1,
        ]));

	
	setup();
}
int valid_leave(object me,string dir)
{
    if (me->query_temp("thnewbiejob/taolin/gua")&&dir=="east")
    {
        me->move(__DIR__"taohuazhen");
        return notify_fail("你来到了一片桃花林里，立刻迷失了方向。\n");
    }
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
	if(dir=="east"&& objectp(present("a xiang",environment(me)))
	    && living(present("a xiang",environment(me))))
		return notify_fail("阿香说道:"+RANK_D->query_respect(this_player())+"请留步，那边是我们庄里的禁地。\n");
	if(dir=="east")
		return notify_fail("你觉得自己似乎还没有征得庄主的允许，感到不太礼貌就退了回来。\n");
	return ::valid_leave(me,dir);
}
