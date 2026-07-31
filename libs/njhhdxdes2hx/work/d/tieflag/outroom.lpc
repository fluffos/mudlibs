// 茅屋外
inherit ROOM;

void create()
{
        set("short", "茅屋外");
        set("long", @LONG
前面是处山谷，郁郁苍苍，满山树木。西面山坡上，竟简陋的建有三间歪歪侧
侧的茅屋，茅屋前还悬着面木牌（ｓｉｇｎ）。一阵阵肉香自茅屋中飘散而出，窗
户里似乎有人探首出来，向你瞧了几眼。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maoroom",
  "southdown" : __DIR__"road1",
]));

        set("item_desc", ([
                "sign": "木牌上写的竟是：小小少林寺\n"
        ]) );
        set("outdoors", "tieflag");
        setup();
        replace_program(ROOM);
}

