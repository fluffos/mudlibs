// Room: /d/kunlun/zhp.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这是一家杂货铺，大箱小箱堆满了一地，都是一些日常用品。掌柜懒洋洋
地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东西。摊
上立着一块招牌(zhaopai)。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"wft",
]));
        set("item_desc", ([
                "zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
]));
        set("objects", ([
                __DIR__"npc/zhanggui": 1,
]));
        setup();
        replace_program(ROOM);
}
