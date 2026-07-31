// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "华山秘道");
        set("long", @LONG
你来到一条黑暗的走廊，这里向北通向华山派的秘室。
LONG
        );

        set("exits", ([
                "out" : __DIR__"buwei2",
                "north" : __DIR__"mishi",
        ]));
        set("objects",([
                CLASS_D("huashan") + "/lao-zhe2" : 1,
//        	"/open/yuer/obj/zitanhua" : 1,
        ]));
        setup();
}



int valid_leave(object me, string dir)
{

        if( (this_player()->query("family/family_name")!="华山派")
        && (objectp(present("ai laozhe", environment(me)))) )
        {
                if (dir == "north" )
                {
                        return notify_fail("矮老者说道: 你非我华山弟子，不能进秘室。\n");
                }
        }
        return ::valid_leave(me, dir);
}
