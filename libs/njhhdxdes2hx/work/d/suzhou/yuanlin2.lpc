//ROOM:/d/suzhou/yuanlin2.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	你走进月洞门，只见迎面一带翠嶂，挡在北面。只见白石岭□，或
如鬼怪，或如猛兽，纵横拱立，上边苔藓成斑，藤萝掩映，其中微露羊肠小径。往北
进入翠嶂，往东是荷花池.
LONG
	);                                        
	set("exits", ([
		"north" : __DIR__"yuanlin3",  
		"east" : __DIR__"yuanlin4",  
		"south" : __DIR__"yuanlin",
]));                                     
	set("objects", ([
		__DIR__"npc/ren" : 2,
]));
	setup();
	replace_program(ROOM);
}
  

