//Zine 国战

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC "退出战场" NOR);
	set("long", "到了这里就退出了明、清长江大战，请用out离开此房间。\n");
	set("exits", ([
	]) );
	setup();
}

void init()
{
    add_action("do_out","out");
}

int leave(object me)
{
    if (me->query_temp("guozhan/side")=="明")
    {
        me->delete_temp("guozhan");
        me->move("/d/city/kedian");
    }
    else if (me->query_temp("guozhan/side")=="清")
    {
        me->delete_temp("guozhan");
        me->move("/d/city/kedian");
    }
    else
    {
        me->delete_temp("guozhan");
        me->move("/d/city/kedian");
    }
    return 1;
}

int do_out()
{
    object me=this_player();
    object *allob=all_inventory(me);
    int i;
    if (me->query_temp("guozhan/quitting"))
    {
        write("离开战场进行中……\n");
        return 1;
    }
    for (i=0;i<sizeof(allob);i++) //不许带出道具
    {
        if (allob[i]->query("guozhan"))
        {
            destruct(allob[i]);
            tell_object(me,"离开国战战场之前，你交出了"+allob[i]->query("name")+"。\n");
        }
    }
    me->set_temp("guozhan/quitting",1);
    call_out("leave",2,me);
    return 1;
}