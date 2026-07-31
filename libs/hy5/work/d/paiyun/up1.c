// Room: /d/paiyun/up1.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
这是一条上山的土路，这条土路非常宽阔，路边长满了蒿草，
路上却满是脚印马蹄印，看来经常有人经过这里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"up2",
  "southdown" : "/d/wuyi/chadong",
]));

	set("outdoors", "paiyun");
	setup();
}

void init()
{
	object ob;
	if(objectp(ob = previous_object()) && ob->query_temp("pass_changan_dutu"))
		ob->delete_temp("pass_changan_dutu");
}
