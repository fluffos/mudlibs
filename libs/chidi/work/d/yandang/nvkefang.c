// Room: /d/yandang/nvkefang.c

inherit ROOM;

void create()
{
	set("short", "女客房");
	set("long", @LONG
相对于男客房,这儿的布置正是太好了.靠墙摆着张象牙床,上面张
着雪白的罗帐,床上摆着绣花红锦被.阳光从后面的窗户中照射进来,一
室皆暖,窗前的梳妆台上的花瓶中还插着几枝梅花.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yuanluo",
]));
	set("outdoors", "/d/yandang");
	set("no_magic", 1);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("hotel",1);

	setup();
	replace_program(ROOM);
}
