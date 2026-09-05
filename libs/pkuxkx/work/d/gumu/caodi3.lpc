// Room: /d/gumu/caodi3.c 
#include <ansi.h>
#include "/d/gumu/bonus.h"
inherit ROOM; 
 
void create() 
{ 
        set("short", "草地");
set("outdoors","gumu");
        set("long", @LONG
    这是一终南山山后中的一片草地，地上长着绿油油
的小草，走在上面感到很舒服，草间夹杂着许多野花，不时
散发出阵阵幽香.北边就是古墓了. 

LONG
        );
       set("exits", ([  
  "north" : __DIR__"duanlongshi",
 "south" : __DIR__"caodi2",
 
 
]));
 /* set("objects", ([
                __DIR__"npc/yangnu" : 1,
        ]));*/
        set("no_clean_up", 0);

        setup();
}

void init()
{
    object yetu;
    object me=this_player();
    add_action("do_qingli","qingli");
    add_action("do_tiqu","tiqu");
    if (me->query_temp("gmnewbiejob/yetu"))
    {
        if (time()-me->query_temp("gmnewbiejob/yetutime")<120)
        {
            if (!me->query_temp("gmnewbiejob/yetuappear")&&random(10)>6)
            {
                yetu=new(__DIR__"npc/yetu");
                yetu->set("owner",me->query("id"));
                yetu->move(this_object());
                me->set_temp("gmnewbiejob/yetuappear",1);
                message_vision("一只$N跳了出来，警惕的看着周围。\n",yetu);
            }
            return;
        }
        else
        {
            tell_object(me,"你出墓很久了，先回去看看小龙女有没有别的什么事吧。\n");
            return;
        }
    }
}

int do_tiqu()
{
    object me=this_player();
    int exp,pot;
	string msg;
    if (me->query("family/family_name")!="古墓派")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("gmnewbiejob/yangfeng_tiqu_degree"))
    {
        tell_object(me,"养蜂正如种地，需要一步步来，哪有现成的蜂蜜让你提取呢？\n");
        return 1;
    }
    if (time()-me->query_temp("gmnewbiejob/yangfeng_finish_time")<12)
    {
        tell_object(me,"玉蜂还没有成熟，暂时没有蜂蜜让你提取。\n");
        return 1;
    }
    if (me->query_temp("gmnewbiejob/yangfeng_tiqu_degree")>10+random(10))
    {
        me->set_temp("gmnewbiejob_yangfeng_finish",1);
        me->delete_temp("gmnewbiejob/yangfeng_tiqu_degree");
        me->delete_temp("gmnewbiejob/yangfeng_yinfeng_degree");
        me->delete_temp("gmnewbiejob/yangfeng_qingli_degree");
        message_vision(HIG"$N养蜂终于结束了，你可以回去看看小龙女还有什么别的任务交给你吧。\n"NOR,me);
        return 1;
    }
    if (time()-me->query_temp("gmnewbiejob/yangfengtime")>120)
    {
        tell_object(me,"你出墓很久了，先回去看看小龙女有没有别的什么事吧。\n");
        return 1;
    }
    message_vision("$N开始提取玉蜂的花蜜。\n",me);
    me->add_busy(2);
	msg=HIW"在劳作中，你增加了经验EXP点，潜能POT点！\n"NOR;
	bonus(me,1,random(4)+4,random(10)+10,0,msg);
    me->add_temp("gmnewbiejob/yangfeng_tiqu_degree",1);
    return 1;
}

int do_qingli()
{
    object me=this_player();
    int exp,pot;
	string msg;
    if (me->query("family/family_name")!="古墓派")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("gmnewbiejob/yangfeng_qingli_degree")>20)
    {
        exp=((int)me->query("combat_exp")+30000)/500;
        pot=((int)me->query("combat_exp")+30000)/900+random(exp);
        me->delete_temp("gmnewbiejob/yangfeng_qingli_degree");
        me->set_temp("gmnewbiejob/yangfeng_yinfeng_degree",1);
        message_vision(HIG"$N终于整理出一块适合养蜂的所在。\n"NOR,me);
        msg=HIW"在劳作中，你增加了经验EXP点，潜能POT点！\n"NOR;
		bonus(me,1,exp,pot,0,msg);
        tell_object(me,"你现在可以开始吹笛引蜂了。\n");
        return 1;
    }
    if (me->query_temp("gmnewbiejob/yangfeng_yinfeng_degree"))
    {
        tell_object(me,"这里已经清理完毕，你可以吹笛引蜂了。\n");
        return 1;
    }
    if (me->query_temp("gmnewbiejob/yangfeng_tiqu_degree"))
    {
        tell_object(me,"这里已经清理完毕，你也引来了蜜蜂，可以开始提取花蜜了。\n");
        return 1;
    }
    if (time()-me->query_temp("gmnewbiejob/yangfengtime")>120)
    {
        tell_object(me,"你出墓很久了，先回去看看小龙女有没有别的什么事吧。\n");
        return 1;
    }
    message_vision("$N开始清理这一片草地。\n",me);
    me->add_busy(2);
    me->add_temp("gmnewbiejob/yangfeng_qingli_degree",1+random(2));
    return 1;
}