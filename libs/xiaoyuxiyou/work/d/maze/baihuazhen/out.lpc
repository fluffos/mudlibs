#include <ansi.h>
inherit ROOM; 

void create() 
{ 
        set("short", "花海"); 
        set("long", @LONG 
放眼望去，但见天地间仿佛已被鲜花充满，但却是无人认得出的花
朵，只觉得这些花无比的鲜艳，无比的美丽。真是令人想不到，荒漠之
中，竟有这样的花海。

LONG
); 
        set("outdoors", "baihuazhen"); 
        set("no_magic",1);
        set("exits", ([ 
                "out" :__FILE__,
        ])); 
        setup();
}

int valid_leave(object me,string dir)
{
	if( userp(me) && dir=="out" )
	{
		if( me->query("family/family_name")== "百花谷" 
		&& me->query_level()>40 
		&& ( !me->query("shilian") || me->query("shilian")!="bhg" ) )
		{
			me->set("shilian","bhg");
			tell_object(me,HIY"【师门】恭喜你！你完成了百花谷的祖师试炼任务，境界符合要求即可拜凝眸仙子为师！\n"NOR);
			me->save();
		}
		me->move(sprintf("/d/baihuagu/flower%d",1+random(6)));		
		return 2;
	}
	return ::valid_leave(me,dir);
}