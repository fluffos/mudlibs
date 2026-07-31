// Room: /d/changan/ca2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "万福酒楼");
        set("long", @LONG
老远你就已经看到的“酒”字招牌原来竖在这里，这就是长安城
最有名的万福酒楼，过往客商都会来这打尖，一些上京赶考的书生也
喜欢在这小住后再上路。你还看到有个后门可以出去。
LONG
);
        set("exits", ([
  "south" : __DIR__"ca18",
  "up" : __DIR__"ca3",
]));
        set("objects", ([
  __DIR__"npc/xiao-er" : 1,
]));

        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if (present("xiao er",environment(me))){
        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
        if ( me->query_temp("rent_paid") && dir == "south" && dir=="north" )
        return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }
        return 1;
}

