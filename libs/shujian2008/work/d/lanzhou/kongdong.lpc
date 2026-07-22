// By River@SJ

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"崆峒山"NOR);
	set("long", @LONG
崆峒山林木葱茏，峰险石奇，既有北方山势之雄，又兼南国山色之秀，下
有宛如白练的径河、胭脂河绕山南北交儿东去。曾被宗教界誉为“十二仙山之
一”。古迹胜景甚多，有气势磅礴的马鬃山，奇特的香山胜景，幽雅别致的五
台风光，神秘的玄鹤洞，引人入胜的弹筝峡、月石峡等自然景观。 
LONG );
	set("exits", ([
		"northdown"  : __DIR__"shanlu1",
		"southwest" : __DIR__"jingyuan",
	]));

	set("outdoors", "兰州");
	setup();
}
