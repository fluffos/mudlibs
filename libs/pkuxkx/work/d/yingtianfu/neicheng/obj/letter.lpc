//国书
//create by zine 29/3/2011
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(YEL"国书"NOR, ({ "guo shu","shu", "letter"}));
	set_weight(50);
	set("long", "这是一封国书。\n");
	set("material", "paper");
	set("unit", "封");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
	setup();
    call_out("busying",1);
}

void init()
{
    add_action("do_dijiao","dijiao");
}

int do_dijiao()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的国书？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/honglusi"))
    {
        tell_object(me,"你没有领任务在身，就不用假扮使者在外骗吃骗喝了吧？\n");
        return 1;
    }
    if (base_name(room)!=me->query_temp("mingtasks/honglusi/target"))
    {
        tell_object(me,"你的任务是到这里递交国书吗？连地址都搞错，大明无人啊！\n");
        return 1;
    }
    else
    {
        message_vision("$N将国书隆重的递交给"+me->query_temp("mingtasks/honglusi/tocountry")+"官员。\n",me);
        me->add_busy(1);
        tell_object(me,HIW"既然完成了使命，赶紧回鸿胪寺复命吧。\n"NOR);
        me->set_temp("mingtasks/honglusi/finished",1);
        if (this_object())
        {
            destruct(this_object());
        }
        return 1;
    }
}

int busying()
{
    object me=environment(this_object());
	if (!me||!userp(me))
	{
		destruct(this_object());
		return 1;
	}
    if (me && userp(me) && random(1000)>699)
    {
        me->add_busy(2);
        tell_object(me,"你打出大明使者的仪仗，停下来稍事休息。\n");
    }
	remove_call_out("busying");
    call_out("busying",4);
    return 1; 
}

