// Room: /d/linzhi/lin38.c

inherit ROOM;

void create()
{
	set("short", "加兴沟瀑布");
	set("long", @LONG
这里是加兴沟最大的水帘洞瀑布，水帘瀑布高25米，分三帘
自洞顶垂落，洞外古藤缠绕，落日时云蒸雾暇，蔚为壮观。据说
洞内曲径通幽，有活佛留下的宝物，但还没听说有人跳过水帘找
到宝物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin37",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
