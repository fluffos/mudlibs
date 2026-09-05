inherit ROOM;
#include <ansi.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#include "/d/yingtianfu/neicheng/royal_area_access.h"
void init()
{
	object me=this_player();
	if (!identification(me,"御林军统领")&&me->query("id")!="zine") return;
	add_action("do_permit","permit");
	add_action("do_forbid","forbid");
}
int valid_leave(object me,string dir)
{  
    object* inv,ob;    
    int i;
    inv = deep_inventory(me);
	if (dir==this_object()->query("forbid_dir"))
    {
		for(i=sizeof(inv)-1; i>=0; i--)
		{
			if(userp(inv[i]))
			{
				me->unconcious();
				return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！”\n"NOR);
			}
		}
		if (forbid(me)==1&&!identification(me,"御前侍卫统领")&&!identification(me,"御林军统领"))
		{
			return notify_fail("此刻你被御林军统领禁止进入皇城！\n");
		}
        if (!me->query("mingpin")&&!me->query("ming/tj/pin")&& !present("entry permit",me))
        {
            return notify_fail("你不是大明官员，皇城岂可随意进入。\n");
        }
        if (me->query("mingpin")>4)
        {
			if (permit(me)==1)
			{
				if (ob=present("yulin jun",this_object()))
				{
					ob->bow2(me);
				}
				return ::valid_leave(me,dir);
			}
			if (me->query_temp("mingtasks/taichangsi/task")==2&&base_name(this_object())=="/d/yingtianfu/neicheng/damingmen")
			return ::valid_leave(me,dir);
            return notify_fail("你的官职太低，皇城岂可随意进入。\n");
        }
    }
	return ::valid_leave(me, dir);
}

