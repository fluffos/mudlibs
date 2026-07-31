// /guanwai/xuedi2.c

inherit ROOM;

void create()
{
	set("short", "雪地");
	set("long", @LONG
这里是一片白茫茫的雪地，一眼望不到边际。四周一个人影也没有，厚
厚的积雪踩起来发出咯吱的响声，大地上留下一串孤独的脚印。寒冷的北风
呼啸而过，吹得脸生痛。暗淡的太阳低悬在天边，显得那么苍白。
LONG );
	set("exits", ([
		"east"       : __DIR__"xuedi3",
                "north"    :  "/d/feihu/road1",
		"southwest"  : __DIR__"xuedi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	me->receive_damage("qi",30);
	me->receive_wound("qi",30);
	tell_object(me,"一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n");
	return 1;
}
