// Room: /d/songshan/luyanpubu.c
inherit BUILD_ROOM;

void create()
{
	set("short", "芦岩瀑布");
	set("long", @LONG
忽听水声如雷，峭壁上两条玉龙直挂下来，双瀑并泄，屈曲
回旋，飞跃奔逸，水花映日，淡淡冕生。
    瀑布一侧有一小小芦岩寺，瀑布斜过就是胜观峰。瀑布之侧
有路可上。
LONG );
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"	: __DIR__"tieliang",
	]));

	set("max_room", 1);

	set("outdoors", "songshan");
	setup();
}
 
int valid_leave(object me, string dir)
{
    if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
    {
	return notify_fail("你使劲儿一蹦，离瀑布顶还有数丈远就掉了下来，摔的鼻青脸肿。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
    {
	return notify_fail("你奋力一跃，却离瀑布顶还有一丈多远，看来是白费力气。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
    {
	return notify_fail("你纵身而起，离瀑布顶只差一点点了，再加把劲。\n");
    }

    return ::valid_leave(me, dir);
}

