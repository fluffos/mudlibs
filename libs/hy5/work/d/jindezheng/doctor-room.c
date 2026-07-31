// Room: /d/jindezheng/doctor-room.c

inherit ROOM;

void create()
{
	set("short", "天医阁");
	set("long", @LONG
天医阁的老板叶天士,妙手回春,医道深湛,人称天医星.不管大病小 
病,只要没断气,他都能把人给救回来,就是脾气古怪了点.据说跟家里人 
闹了点意见,三年前从杭州赌气来到此地,就在这开了个药铺,治病救人. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"street1",
]));
	set("no_fight", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/doctor.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
