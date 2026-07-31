//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
此处山道狭窄，林木特别茂密，山民踏出来的小道被纵横交错的
林木遮挡阻碍着，行路者不停地用刀劈砍开路，才能顺利前进。四面
青山峭立，丛林中时常有鸟兽惊走，偶尔还能看见美丽的孔雀飞过。
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov21",
		"southup" : __DIR__"minov27",
		]));

//	set("objects", ([
//		"/d/foshan/npc/zsnake.c" : 1,
//		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
