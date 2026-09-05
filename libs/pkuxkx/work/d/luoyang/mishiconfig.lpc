//room /d/luoyang/密室配置文件
//Zine 11 Oct 2010
#include <ansi.h>
inherit ROOM;

int initkiller();
void create()
{
    
    set("no_task",1);
}

void init()
{
    object me=this_player();
    if (userp(me) && !me->query_temp("tiejiangjob/ticket"))
    {
        tell_object(me,"严肃点，这不是捉迷藏，救命呢，你是从哪混进来的？\n");
        me->move(__DIR__"datiepu");
    }
	add_action("do_none","guard");
}

int do_none()
{
	tell_object(this_player(),"密室太过狭窄，无法施展得开。\n");
	return 1;
}
int initkiller()
{
    object tj;
    object* all =all_inventory(this_object());
    int i;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="tie jiang")
        {
            tj=all[i];
        }
    }
    if (tj)
    {
        object killer;
        killer=new(__DIR__"npc/killer");
        killer->move(this_object());
        return 1;
    }
  
}
