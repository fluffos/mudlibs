// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "内帐");
	set("long", @LONG
这里是札木合、桑坤的帅帐的内帐。
LONG
	);

	set("exits", ([
		
        "out" : __DIR__"d_menggubao0",
	]));
	set("sleep_room", "1");
    set("no_task", 1);
    set("no_robber",1);
	set("objects", ([
        	__DIR__"npc/sangkun" : 1,
	]));
	setup();
}

int dest_all_shi()
{
    int i;
    object *all_shi=all_inventory(this_object());
    for (i=0;i<sizeof(all_shi);i++)
    {
        if (all_shi[i]->query("d_menggu_shi"))
        {
            tell_room(this_object(),all_shi[i]->query("name")+"眼见大势已去，决定自杀殉主！\n");
            all_shi[i]->die();
        }
    }
    return 1;
}

int continue_trap(object killer)
{
    object *all_shi,shi=new(__DIR__"npc/d_shi");
    int i,flag=0;
    all_shi=all_inventory(this_object());
    if (!killer)
    {
        return 1;
    }
    if (environment(killer)!=this_object())
    {
        return 1;
    }
    if (time()-killer->query_temp("shediaoquest/jdfm/kill_sangkun")>100+random(100))
    {
        if (killer->query_temp("shediaoquest/jdfm/jdfm"))
        {
            killer->set("shediaoquest/jdfm",1);
        }
        dest_all_shi();
        tell_room(this_object(),HIG+"此刻，铁木真大汗带领大队骑兵攻入此间，桑坤、札木合败亡，都史在乱军中被杀！\n"+NOR);
		tell_object(killer,"你和大队骑兵汇合，班师返回。\n");
		killer->delete_temp("apply/name");
        killer->delete_temp("apply/id");
        killer->delete_temp("apply/short");
        killer->delete_temp("apply/long");
        killer->delete_temp("apply/age");
        killer->delete_temp("apply/gender");
        killer->delete_temp("apply/shen");
		killer->delete_temp("apply/class");		
		killer->delete_temp("apply/mud_age");
		killer->move(__DIR__"jinzhang");
		tell_object(killer,"快去见见大汗吧，他有话要对你说。\n");
		return 1;
    }
    for (i=0;i<sizeof(all_shi);i++)
    {
        if (all_shi[i]->query("d_menggu_shi"))
        {
            flag+=1;
        }
    }
    if (flag<15)
    {
        for (i=flag;i<12;i++)
        {
            shi->move(this_object());
            shi->kill_ob(killer);
        }
        remove_call_out("continue_trap");
        call_out("continue_trap",1,killer);
        return 1;
    }
    else
    {
        remove_call_out("continue_trap");
        call_out("continue_trap",1,killer);
        return 1;
    }
}
int trap(object killer)
{
    if (!killer)
    {
        return 1;
    }
    if (environment(killer)!=this_object())
    {
        return 1;
    }
    message_vision(HIR"桑坤临死前，大喝：“$N"+HIR+"是奸细！”\n"NOR,killer);
    tell_object(killer,"帐外的卫士闻讯冲了进来，限于帐内空间有限，大部卫士把帐外堵了个水泄不通。\n");
    tell_object(killer,"此刻，铁木真大汗接到讯号，开始分四路攻击札木合、桑坤的部落，只要能再坚持片刻，胜利即在眼前！\n");
    continue_trap(killer);
    return 1;
}
void init()
{
    object me=this_player();
    //add_action("do_say","say");
    //add_action("do_say",",");
    if (me->query_temp("shediaoquest/jdfm/kouling")!="finish")
    {
        tell_object(me,"口令更改，你被卫士们赶了出去。\n");
        me->move("/d/menggu/d_menggubao0");
        return;
    }
}

int valid_leave(object me,string dir)
{
    if (dir=="out")
    {
        return notify_fail("卫士们拦住了你。\n");
    }
    return ::valid_leave(me,dir);
}