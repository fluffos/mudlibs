// Room: /d/dali/dangpu.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时50分23秒。

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
此当铺是南大街对面的赌场所设。以方便手头不宽的赌客。鸣玉坊的姑娘们也经
常光顾这里，典当或是卖掉客人们高兴之余所赏赐的小玩意儿。此当铺虽然是赌场所
属，但却是童叟无欺。当铺挂有牌（ｓｉｇｎ）一块。
LONG
	);
        set("item_desc", ([
                "sign": @TEXT
    本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。客倌可以在这里
看货(list)、购买(buy)、估价(value)、典当(pawn)、赎回(redeem)、卖
断(sell)各种货物。
TEXT
        ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nandajie1",
]));

        set("no_fight", 1);
        set("no_beg",1);

        set("objects", ([
                __DIR__"npc/zhou" : 1,
        ]));

	setup();
}
