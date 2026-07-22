// chuwujian.c
// 储物间
inherit ROOM;
#include <room.h>
void create()
{
	set("short","储物间");
	set("long",@long
这里便是峨嵋华藏庵的储物间，四周都是架子。一个架上放满了各样兵
器，有长剑，拂尘，长鞭等，琳琅满目。另一个架上放了各种防具。还有一
个架上摆了许多小柜子，原来是装满药品的药柜。一位师太负责管理这里的
物品，正忙碌着整理防具。后面好象有个小楼梯。门外就是斋堂了。
long);
	set("exits",([
	    "north" : __DIR__"huazanganzt",
	    "up" : __DIR__"huazangancj",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-feng" : 1,	    
          ]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" && me->query("family/family_name") != "峨嵋派" && objectp(present("jingfeng shitai", environment(me))))
		return notify_fail("静风师太喝道：“藏经楼内外派弟子不得入内”。\n");
	return ::valid_leave(me, dir);
} 
