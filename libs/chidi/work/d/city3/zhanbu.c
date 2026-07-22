//bye enter

inherit ROOM;

void create()
{
	set("short", "占卜铺子");
	set("long", @LONG
门口挂着一块招牌(sign),里面显得有些空空荡荡的,瞎眼先
生坐在一张黑漆的方桌后,桌上铺者一张白布,上面摆着一筒算命
用的竹签和几枚铜钱。方桌前有一张供客人坐的凳子。
LONG
	);

	set("exits", ([
                "south" : __DIR__"xijie1",
	]));

	set("item_desc",([
                 "sign": "人算不如天算，天算不如我算。\n",
                    ]));
        set("objects" ,([
                 __DIR__"obj/chair" : 1,
                    ]));

	setup();
	replace_program(ROOM);
}

