// Room: /d/fuzhou/zhongxin.c
// Lklv 2001.9.6

inherit ROOM;

void create()
{
        set("short", "城中心");
        set("long", @LONG
这里是福州城的城中心，人来人往，很是热闹。因为是东南地区最大的一
个海港城市，所以往来的行人中形形色色、熙熙攘攘。其中也有很多挑着担子
拿着渔网的渔夫、船家，人们走路的姿势都很悠闲，看起来一付与世无争的样
子。东面的方向是一条石板街道，不断有渔人往来，看来那里就是渔港了。东
南方向隐约有一条小巷。
LONG
        );

        set("exits", ([
                "north" : __DIR__"beijie",
                "south" : __DIR__"nanjie",
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
        ]));
        set("objects", ([
                __DIR__"npc/huo" : 1,
        ]));

        set("outdoors", "福州");
	setup();
}
