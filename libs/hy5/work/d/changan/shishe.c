inherit  ROOM;
#include  <ansi.h>;
void  create  ()
{
    set  ("short",  "乐府诗社");
    set  ("long",  @LONG
高楼之上，满城繁华尽收眼底。文人骚客都喜欢在这里品茶吟
诗，谈古论今，你瞧，不知谁在茶桌上刚刚写好一首诗(poem)。里
边柜台上新贴了张启事(qishi)，你不由得走过去看了几眼。
LONG);

    set("exits",  ([
        "down"  :  __DIR__"yuefang",
        "east"  :  __DIR__"club",
    ]));
    set("objects",  ([
        __DIR__"npc/xiucai":  1,
        __DIR__"obj/tables"  :  1,
    ]));
    setup();
}

