// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/yamen.c

inherit ROOM;

void create()
{
        set("short", "衙门大门");
        set("long", @LONG
这里是长安城的衙门大门，两扇朱木大门紧紧关闭着。门口放着两个青铜
狮。“肃静”“回避”的牌子分放在两旁。前面有一个大鼓，显然是供小民鸣
冤用的。几名衙役在门前巡逻。
LONG
        );

        set("exits", ([
                "south" : __DIR__"westjie2",
                "north" : __DIR__"yamen2",
        ]));

        set("objects", ([
                __DIR__"npc/yayi" : 2,
        ]));

        set("incity",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north"){
                if( me->query_condition("killer"))
                        return notify_fail("衙役喝道：“你是谁？快快离开这里。”\n");
                else
                        return notify_fail("衙役喝道：“威……武……。”\n");
        }
        return ::valid_leave(me, dir);
}