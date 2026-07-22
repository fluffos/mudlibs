//houyuan

#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", HIW"小屋"NOR);
	set("long",@LONG
这是一间很简单大房屋，只有一桌一椅，桌子上面放着几本经书，旁边的一
盏油灯散发着昏暗的光亮。椅子上坐着一个老者正在认真的观看经书。
LONG
    );
	set("exits",([
		"enter"  :    __DIR__"liwu",
		"north"  :   __DIR__"xiaojin1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		"/d/mr/npc/murong-bo": 1,
	]));
	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "少林派" || myfam["generation"] != 35 ) && dir != "north" 
               &&!present("jiaxin", me)&&objectp(present("murong bo", environment(me))))
        return notify_fail("慕容博拦住你说到，我师傅正在里面静修，不要去打扰他老人家。\n");
                
        return ::valid_leave(me, dir);
}
