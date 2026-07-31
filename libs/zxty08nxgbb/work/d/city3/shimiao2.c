// Room: /chengdu/shimiao2.c
// oooc: 1998/06/26 

inherit ROOM;

void create()
{
        set("short", "大雄宝殿");
	set("long", @LONG
这里雄伟庄严的大雄宝殿，两边是青面撩牙的四大金刚，中间
供奉着如来佛祖的金像，殿内香烟缭绕，无数善男信女来此烧香磕
头，正中是一块蒲团，供香客礼拜。右手是善缘箱，供钱财布施用。
LONG
	);

	set("exits", ([
                "south" : __DIR__"shimiao",
	]));
        set("objects", ([
             __DIR__"npc/yuanseng" : 1,
             __DIR__"obj/box1" : 1,
        ]));
        setup();
}

