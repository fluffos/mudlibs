inherit ROOM;

void create()
{
        set("short", "杜甫草堂");
        set("long", @LONG
这里就是著名的杜甫草堂了。草堂内，小桥，流水，梅
园交错庭中，另有春之梅，夏之荷，秋之菊，冬之兰可赏，置
身其中，让人有发古之幽思，又享大自然之浪漫。
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaoxiang1",
            "east" : __DIR__"cdta",
            "north" : __DIR__"dufu_sleep",
            ]));

        set("no_clean_up", 0);
        set("objects",([
            __DIR__"npc/dufu" : 1,
            __DIR__"npc/xuetong" : 2,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("那是杜甫的私人寝室！！\n");
        return 1;
}

