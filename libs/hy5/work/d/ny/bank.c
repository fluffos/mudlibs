
// bank.c

inherit BANK;


void create()
{
        set("coor",({-50,4800,10}));
	set("short", "彝源钱庄");;
        set("long",
"这是一间素来以公平信用著称的钱庄，钱庄的老板还是个曾经中过举人的读书人，你可以看\n"
"到钱庄里里外外都打扫得乾乾净净，一个胖胖的中年人坐在柜台後面，柜台上放著一块牌子\n"
"(sign)，往南是宁远城大街\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet2",
]));

        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

convert     兑换钱币


TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/banker": 1 ]) );
        setup();
}

