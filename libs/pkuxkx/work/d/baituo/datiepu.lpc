//datiepu.cpu.c
//--by bibi--
inherit ROOM;
void create()
{
        set("short", "张记打铁铺");
        set("long",
             "这里是一家打铁铺，铁匠正在忙着打制铁制兵器，好卖给江湖中\n"
         "人。但是，你如果是买武器是用来防身的，那么在这里买就不是个好\n"
         "主意了，因为这里出售的兵器都是大且笨重的那种，非是画圈秀腿者\n"
         "所能用的了的！\n"
         "    屋子正中央挂着一把大砍刀，显示着这里卖的都是重型兵器。\n" 
            );
        set("exits", ([
                "north" : __DIR__"dongjie",
        ]));
        set("objects",([
                __DIR__"npc/smith" : 1,
        ]));
        setup();
}
