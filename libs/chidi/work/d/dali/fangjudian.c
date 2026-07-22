// Room: /d/dali/fangjudian.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：22时8分7秒。

inherit ROOM;

void create()
{
        set("short", "薛记成衣铺");
        set("long", @LONG
这是一家老字号的成衣铺，里面摆满了各式各样的衣物。
绸、绢、丝、布、皮袄、大红斗蓬、葱黄绫子棉裙、水绿色
棉袄，秋香色团花。。。不一而足。墙上挂着个牌子(paizi)。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
]));
        set("item_desc", ([
                "paizi": "欢迎订做衣服。\n",
        ]) );

        set("objects", ([
                __DIR__"npc/caifeng" : 1,
        ]));

        setup();
}

