// Room: /d/fuzhou/xixiang4.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "西巷");
	set("long", @LONG
这里是福州城西大街旁边的一条小巷，巷子里的路很宽，看起来好象比西
街窄不了多少，两边开有一些小铺子。西面是家茶馆，因为福建的茶叶很有名
气，所以除了本地人，来这里品茶的外乡客也不少。南面是家客栈，门口高高
挂有一幅烫金牌匾，上写着“吉祥客栈”四个大字。
LONG
	);

	set("exits", ([
                "west" : __DIR__"chalou",
                "north" : __DIR__"xixiang3",
                "south" : __DIR__"kezhan",
	]));
        set("objects", ([
                "/d/huashan/npc/haoke" : 1,
        ]));
	set("outdoors", "福州");
	setup();
}
