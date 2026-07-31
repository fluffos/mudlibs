
// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long",
"这是一条宽敞坚实的青石板大道，大道两旁种著整齐的花木，从这里往北通往水烟阁，往南\n"
"则是衔接宁远城街道的路口。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sroad3",
]));
	set("outdoors", "ny");

	setup();
//  replace_program(ROOM);;
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里施工中，请改道。\n");
        return ::valid_leave(me, dir);
}
