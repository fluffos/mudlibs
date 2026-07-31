// xiaoting.c 小厅
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "小厅");
        set("long", @LONG
这里是一个小小的厅堂，也许是为了连接前厅与正厅用的。你走
到这里，周围的光线亮了一些，你发觉壁上燃点着一些油灯。厅里的
布置整洁而不简陋，一桌一椅都收拾的井井有条。
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhengting",
                "north" : __DIR__"qianting",
                "west" : __DIR__"xiaowu1",
                "east" : __DIR__"xiaowu2",
        ]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");        
        set("objects", ([
           __DIR__"npc/gumudizi" : 2,
           "quest/menpai/gumu/shi" : 1,
                   ]));

        setup();
        replace_program(ROOM);
}
