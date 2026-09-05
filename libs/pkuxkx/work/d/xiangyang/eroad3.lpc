#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "山路");
set("outdoors","xiangyang");
	set("long",
	CYN"你走啊走，不知走了多远，回头望去，襄阳城早已变得如火柴盒般大小
  路两旁蒿草繁茂，高过腰际，许多不知名的野花开得正艳。草丛中不时传来沙沙的
  声音，过了一会，探出了一个小脑袋，哈哈，原来是一只小鹿。\n"NOR
    	);
       	set("objects", ([
		__DIR__"npc/deer" : 1,
        ]));
	set("exits", ([
		"eastup" : __DIR__"chukou0",
		"west" : __DIR__"eroad2"          
	]));
	setup();
}

