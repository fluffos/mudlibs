//厚礼 By Zine HS newbie job
#include <ansi.h>
inherit ITEM;

void create()
{	
	set_name(HIY"礼物"NOR, ({ "li wu","gift"}));
	set_weight(50);
	set("long", "这是一包礼物。\n");
    set("is_liwu",1);
	set("material", "jade");
	set("unit", "包");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_store",1);
	setup();
    call_out("dest",1200);
}


void init()
{
    
    add_action("do_qing","wenhao");
 
}

int dest()
{
    destruct(this_object());
    return 1;
}


int do_qing(string arg)
{
    object me=this_player();
    object target,letter;
    if (!me->query_temp("hsnewbiejob/target"))
    {
        return 0;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!arg)
    return notify_fail("你要向谁问好？\n");
    if(!objectp(target = present(arg, environment(me))))
		return notify_fail("你要向谁问好？\n");
    if (member_array(target,me->query_temp("hsnewbiejob/target"))==-1)
    {
        tell_object(me,"你要问好的前辈不在这里。\n");
        return 1;
    }
    else
    {
        message_vision(HIM"$N对着$n深深一揖：鄙派掌门向"+target->query("name")+"问好。\n"NOR,me,target);
        tell_object(target,me->query("name")+"代表华山派岳不群掌门、宁中则掌门夫人向你问安。\n");
        CHANNEL_D->do_channel(target, "chat", target->query("name")+"在此，请"+me->query("name")+RANK_D->query_respect(me)+"也代为向岳掌门、宁女侠问好。");
        if (!random(5)||wizardp(me))
        {
            letter=new("/d/changjiang/obj/letter");
            letter->set("owner",target->query("id"));
            letter->move(target);
            tell_object(target,"你打开华山派的礼物，原来是一封家信。\n");
        }
        me->set_temp("hsnewbiejob/wenhaofinish",1);
        destruct(this_object());
        return 1;
    }
    
}

