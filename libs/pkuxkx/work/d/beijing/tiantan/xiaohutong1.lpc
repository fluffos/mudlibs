// Room: /d/beijing/west/xiaohutong1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"小胡同"NOR);
	set("long",
CYN"这是一条北京城里极常见的小胡同，因为地处偏僻，所以行人
不多，地上看起来也不太干净，一有刮风就尘土飞扬。老北京口中
的“晴天是香炉，雨天是墨盒”，就是指这种小胡同。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : "/d/beijing/zhengyangdajie2",
  	"southwest" : __DIR__"beitianmen",
]));
        set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
