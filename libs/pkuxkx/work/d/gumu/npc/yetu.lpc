#include <ansi.h>
inherit NPC;

void create()
{
	set_name("灰兔", ({ "hui tu","rabbit","tu" }) );
	set("race", "野兽");
	set("age", 1);
	set("long", "一只大灰兔，眼中露出狡黠的光。\n它在草地上蹦来蹦去的。\n");
	set("limbs", ({ "头部", "身体", "前腿", "尾巴" }) );
	set("verbs", ({ "bite", }) );
    set("rabbit",1);
	set_temp("apply/dodge", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 10);
    setup();
    call_out("moving",1);
    call_out("checking",1);
}

int checking()
{
    object ob=this_object();
    object me;
    if (!ob->query("owner"))
    {
        message_vision("$N一蹦一跳地脱离了你的视线。\n",ob);
        destruct(ob);
        return 1;
    }
    me=find_player(ob->query("owner"));
    if (!me)
    {
        message_vision("$N一蹦一跳地脱离了你的视线。\n",ob);
        destruct(ob);
        return 1;
    }
    if (time()-me->query_temp("gmnewbiejob/yetutime")>120)
    {
        message_vision("$N一蹦一跳地脱离了你的视线。\n",ob);
        destruct(ob);
        return 1;
    }
    call_out("checking",1);
    return 1;
}

int moving()
{
    object ob=this_object();
    random_move();
    ob->set("zhuo",1);
    if (random(2))
    {
        random_move();
        ob->set("zhuo",1);
    }
    call_out("moving",4-random(2));
    return 1;
}

void init()
{
    add_action("do_zhuo","zhuo");
}

int do_follow()
{
    object me=this_player();
    tell_object(me,"像彻底跟上它？别做梦了。\n");
    return 1;
}

int zhuo(object me)
{
    if (base_name(environment(me))!=base_name(environment(this_object())))
    {
        tell_object(me,"等你要上前去，灰兔早已警觉，跑开了去。\n");
        me->add_busy(random(2));
        return 1;
    }
    if (random(100)>85)
    {
        message_vision("$N一把捉住兔子，忽然童心大起，要与它比赛轻功，要累得兔儿无力奔跑为止。\n",me);
        tell_object(me,"你放开了兔子。\n");
        me->add_temp("gmnewbiejob/yetucount",4);
        me->add_busy(2);
        return 1;
    }
    else
    {
        message_vision("$N笨手笨脚的，吓跑了兔子。\n",me);
        me->add_temp("gmnewbiejob/yetucount",1);
        me->add_busy(2);
        return 1;
    }
}

int do_zhuo()
{
    object me=this_player();
    if (!me->query_temp("gmnewbiejob/yetu"))
    {
        return 0;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!this_object()->query("zhuo"))
    {
        tell_object(me,"稍等等再动手吧。\n");
        return 1;
    }
    if (time()-me->query_temp("gmnewbiejob/yetutime")>120)
    {
        tell_object(me,"你出墓很久了，先回去看看小龙女有没有别的什么事吧。\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"这不是你刚才逗弄的那只兔子了。\n");
        return 1;
    }
    message_vision("$N蹑手蹑脚地走到兔子的身后，伸手抓去。\n",me);
    this_object()->delete("zhuo");
    me->add_busy(2);
    call_out("zhuo",2,me);
    return 1;
}