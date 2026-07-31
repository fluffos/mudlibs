inherit  ROOM;
void  create  ()
{
        set  ("short",  "乐坊二楼");
        set  ("long",  @LONG 
乐坊楼上显得格外热闹，走廊里人来人往，几间屋子里人声嘈
杂，牌签骨骰钱币落盘的声音不绝。看样子，客人们赌得正欢呢。
LONG
); 
        set("exits",  ([
                "up"  :  __DIR__"shishe",
                 "west"  : "/d/changan/qinhuang/duroom",
                "down"  :  __DIR__"ca15",
        ]));
        set("objects",  ([
//               __DIR__"npc/libai"  :  1,
                 __DIR__"obj/tables"  :  3,
        ]));
        set("no_clean_up",  0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && (userp(me)))
                return notify_fail("赌场正在装修中，还是不要去了吧！！\n");
        return 1;
}

