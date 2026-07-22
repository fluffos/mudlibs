// Room: /d/huashan/taijie.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "台阶");
        set("long", @LONG
这是依山石开凿的石阶，因为过往的人不多，上面步满了青苔，南面就是
华山派的中心所在。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shanlu2",
		"southup" : __DIR__"qianting",
	]));

	set("objects",([
		__DIR__"npc/liangfa" : 1,
]));

        set("outdoors", "华山" );

        set("coor/x",80);
  set("coor/y",0);
   set("coor/z",70);
   setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && me->query("family/family_name") != "华山派" && objectp(present("liang fa", environment(me))))
         return notify_fail("梁发喝道：“不是本派弟子休得往上半步。\n");
        if (dir == "northwest" && me->query("family/family_name") != "华山派" && objectp(present("liang fa", environment(me))))
         return notify_fail("梁发喝道：“不是本派弟子休得往上半步。\n");
        return ::valid_leave(me, dir);
}
