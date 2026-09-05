// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
小庵不大，绕过佛像，就是方丈室了。方丈室中颇为澄澈，周围书架上摆满
经籍，一套茶具在矮几上摆着，云床上一位慈眉善目的长老正在盘膝打坐。看来
此处确是一个修身养性的绝妙所在。
LONG);

	set("exits", ([
		"west" : __DIR__"shanlu6",
	]));
	set("objects",([
		__DIR__"npc/zhanglao" : 1,
	]));

	setup();
	replace_program(ROOM);
}
