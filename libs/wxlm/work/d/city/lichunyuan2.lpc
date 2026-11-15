// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
	set("short", "观乐楼二楼");
	set("long", @LONG
你站在观乐楼二楼。满耳的乐曲声音让你很舒畅。
LONG);
	set("exits", ([
	    "down" : __DIR__"lichunyuan",
	]));
	set("objects", ([
	    __DIR__"npc/guigong" : 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("piao_room", "1");
	setup();
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if (me->query_condition("prostitute"))
      return notify_fail("保卫一把抱住你：看你往哪里逃！\n");
    else  return 1;
}
