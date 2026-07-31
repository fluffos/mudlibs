//shanjing1.c 山径
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"山径"NOR);
        set("long",@LONG
山径只有一条，倒不会走错，只见山径越走越高，也是越是崎岖。旁边长
着各种荆棘，在山石参差的环境之下，越发显得阴森可怖。而且，海拔越高，
山风越是凌厉，吹得人双颊生疼。
LONG
);

        set("outdoors","绝情谷"); 
	set("exits",([
           "northup": __DIR__"shanding",
	   "southdown": __DIR__"shanjing",
	]));
	setup();
	replace_program(ROOM);
}

