inherit ROOM;

void create()
{
        set("short", "兵营");
        set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有的
独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视着四
周。
LONG
        );

        
        set("exits", ([
                "west" : __DIR__"jail",
                "east" : __DIR__"beimen",
        ]));

        set("objects", ([
                __DIR__"npc/liangdong" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 4,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("zhao liangdong", environment(me))) && 
                dir == "west")
                return notify_fail("赵良栋大声喝道：闲杂人等，一律离开。\n");

        return ::valid_leave(me, dir);
}

