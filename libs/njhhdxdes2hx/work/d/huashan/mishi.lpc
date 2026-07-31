// Room: /d/huashan/mishi.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "华山秘室");
        set("long", @LONG
这里是华山派的秘室，别派人物无法进入，里面放了很多华山秘籍。
LONG
        );

        set("exits", ([
		"south" : __DIR__"midao",
        ]));
        set("objects",([
                CLASS_D("huashan") + "/lao-zhe" : 1,
                "d/huashan/obj/taxue" : 1,
		"d/huashan/obj/parry" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if ( present("gao laozhe", environment(me)) )
        if ( present("huashan miji", me)
        ||   objectp(ob = present("corpse", me)) && present("huashan miji", ob)
)
        {
                if (dir == "south" )
                {
                        return notify_fail("高老者说道: 武功秘籍只许在秘室里研习，不得携带外出 !\n");
                }
        }
          return ::valid_leave(me,dir);
}
