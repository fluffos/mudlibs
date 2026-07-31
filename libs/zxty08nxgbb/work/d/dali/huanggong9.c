// Room: /d/dali/huanggong9.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
这里是大理皇宫的御花园，园内的茶花开得正艳。茶花是大理的
国花，而皇宫内的茶花更是名贵稀有，花匠养花之道天下手曲一指。
园中放着几盆新藕、甜瓜、枇杷、林擒等鲜果，椅上丢着几柄团扇，
看来皇帝临睡之前曾在这里乘凉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huanggong8",
]));

                 set("objects", ([
                __DIR__"npc/taijian" : 2,
        ]));

         
	setup();
}

