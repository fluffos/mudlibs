// mutong.c 木桶
// by Zine
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("大木桶", ({ "mu tong", "mutong", "tong" }));
	set_weight(5000);
	set("unit", "个");
	set("long", "这是一个大木桶，可以用来泡澡(bath)。你可以往里面加(add)药材和热水。\n");
    set("value", 1000);
	set("material", "wood");
    set("dgp",0);
    set("scz",0);
    set("sgc",0);
    set("drug",0);
    set("full",0);
	setup();
    call_out("pricedown",1);
}

int pricedown()
{
    this_object()->set("value", 0);
}
void init()
{
	add_action("do_add", "add");
    add_action("do_bath","bath");
}

int do_add(string arg)
{
    object me=this_player();
    object ob=this_object();
    object item;
    if (!arg)
    {
        return notify_fail("你要往木桶里加什么？\n");
    }
    if ((arg=="digu pi"||arg=="pi"||arg=="地骨皮"||arg=="drug")&&present("digu pi",me))
    {
        item=present("digu pi",me);
        ob->add("dgp",1);
        ob->add("drug",1);
        if (item)
        {
            destruct(item);
        }
        message_vision("$N将一份地骨皮放入大木桶中。\n",me);
        return 1;
    }
    if ((arg=="sheng gancao"||arg=="gancao"||arg=="生甘草"||arg=="drug")&&present("sheng gancao",me))
    {
        item=present("sheng gancao",me);
        ob->add("sgc",1);
        ob->add("drug",1);
        if (item)
        {
            destruct(item);
        }
        message_vision("$N将一份生甘草放入大木桶中。\n",me);
        return 1;
    }
    if ((arg=="shechuang zi"||arg=="zi"||arg=="蛇床子"||arg=="drug")&&present("shechuang zi",me))
    {
        item=present("shechuang zi",me);
        ob->add("scz",1);
        ob->add("drug",1);
        if (item)
        {
            destruct(item);
        }
        message_vision("$N将一份蛇床子放入大木桶中。\n",me);
        return 1;
    }
    if ((arg=="re shui"||arg=="shui"||arg=="水壶")&& present("re shui",me))
    {
        if (ob->query("full")>3)
        {
            tell_object(me,"大木桶已经倒满热水了，再倒就要漫出来了。\n");
            return 1;
        }
        item=present("re shui",me);
        ob->add("full",1);
        if (item)
        {
            destruct(item);
        }
        message_vision("$N将一大壶热水倒入大木桶中。\n",me);
        return 1;
    }
    else
    {
        tell_object(me,"你只能将药材放入大木桶。\n");
        return 1;
    }
}

int normal_bathing(object me)
{
    int n;
    string* desc=({"片刻之间，房间里弥漫着水气。\n","热水氤氲之气升腾，你全身都很轻松。\n","水中的热力渗透入全身，你舒服地呻吟了一声。\n","你全身浸泡在水里，肌肉无比放松。\n",});
    if ((int)me->query_temp("drugbath/times")>20+random(10))
    {
        me->delete_temp("drugbath/times");
        if (base_name(environment(me))!="/d/xinfang/xinfang")
        {
            tell_object(me,"你洗澡怎么洗到大街上来了？\n");
            return 1;
        }
        else
        {
            write(HIW"你在木桶里泡了良久，跨了出来，全身筋骨非常轻松。\n");
            me->fullme();
            return 1;
        }
    }
    else
    {
        if (base_name(environment(me))!="/d/xinfang/xinfang")
        {
            tell_object(me,"你洗澡怎么洗到大街上来了？\n");
            return 1;
        }
        else
        {
            n=2+random(3);
            tell_object(me,desc[random(sizeof(desc))]+NOR);
            me->add_temp("drugbath/times",1);
            me->start_busy(n);
            call_out("normal_bathing",n,me);
            return 1;
        }
    }
}

int bathing(object me)
{
    int n;
    string* desc=({"片刻之间，房间里弥漫着药材的香味。\n","热水氤氲之气升腾，你全身都很轻松。\n","热水中的药力渗透入全身，你赶忙运功引导。\n","你全身浸泡在水里，肌肉无比放松。\n",});
    if (base_name(environment(me))!="/d/xinfang/xinfang")
    {
        tell_object(me,"你洗澡怎么洗到大街上来了？\n");
        return 1;
    }
    else
    {
        if ((int)me->query_temp("drugbath/times")>20+random(10)+(int)me->query("drugbath/continue")*20)
        {
            write(HIG"你在木桶里泡了良久，跨了出来，全身筋骨非常轻松。\n"NOR"这时木桶四分五裂开来，汤水漏了一地。\n");
            me->delete_temp("drugbath/times");
            me->fullme();
            if ((int)me->query("drugbath/continue")>=4 && !me->query("drugbath/con") && !me->query("idleapply") && (int)me->query("age")>18 && (int)me->query("age")<24)//一mudage泡1次，连续5次且不使用发呆室的福利。by Zine
            {
                if (random(1000)>998) //千里挑一，相当于yy小说里开金手指的主角。 by Zine
                {
                    me->add("con",1);
                    me->add("xiantian/con/jinyang_mutong",1);

                }
                n=1+random(2);
                me->add("con",n);
                me->add("xiantian/con/jinyang_mutong",n);
                me->set("drugbath/con",1);
                write(HIC"经过少年时期药水的不断浸泡，你觉得自己的先天根骨有了明显提高！\n"NOR);
                destruct(this_object());
                return 1;
            }
            if ((int)me->query("drugbath/continue")>2)
            {
                n=random(100);
                if (n>66)
                {
                    me->add_temp("apply/dexerity",3+random(5));
                    write(HIY"经过药水的浸泡，你觉得自己身轻如燕一般。\n"NOR);
                    destruct(this_object());
                    return 1;
                }
                if (n>33)
                {
                    me->add_temp("apply/strength",3+random(5));
                    write(HIY"经过药水的浸泡，你觉得自己举重若轻，力大无穷。\n"NOR);
                    destruct(this_object());
                    return 1;
                }
                else
                {
                    me->set_temp("forceextra",1);
                    write(HIY"经过药水的浸泡，你觉得自己瞬间内力的掌控无比精纯。\n"NOR);
                    destruct(this_object());
                    return 1;
                }
            }
            else
            {
                destruct(this_object());
                return 1;
            }
        }
        else
            {
                n=2+random(3);
                tell_object(me,desc[random(sizeof(desc))]+NOR);
                me->add_temp("drugbath/times",1);
                me->start_busy(n);
                call_out("bathing",n,me);
                return 1;
            }
     }
}

int do_bath()
{
    object me=this_player();
    object ob=this_object();
    if (ob->query("full")<3)
    {
        return notify_fail("大木桶的热水没有放满，不够你泡澡。\n");
    }
    if (me->query("drugbath/time")>=me->query("age"))//一个age只能洗一次
    {
        return notify_fail("你上次用药浴不久，老洗会脱皮的。\n");
    }
    if (base_name(environment(me))!="/d/xinfang/xinfang")
    {
            tell_object(me,"你只能在自己家里洗澡。\n");
            return 1;
    }
    else
    {
        if (ob->query("dgp")==1 && ob->query("sgc")==1 && ob->query("scz")==1 && ob->query("drug")==3)
        {
            me->set("drugbath/lasttime",me->query("drugbath/time"));
            me->set("drugbath/time",me->query("age"));
            if ((int)me->query("drugbath/time")-(int)me->query("drugbath/lasttime")==1)//连续坚持泡澡获得加成
            {
                me->add("drugbath/continue",1);
            }
            if ((int)me->query("drugbath/time")-(int)me->query("drugbath/lasttime")!=1)//否则中断
            {
                me->set("drugbath/continue",0);
            }
            if (me->query("drugbath/continue")>5)
            {
                me->set("drugbath/continue",0);
            }
            bathing(me);
            return 1;
        }
        else
        {
            me->set("drugbath/lasttime",me->query("drugbath/time"));
            me->set("drugbath/time",me->query("age"));
            normal_bathing(me);
            return 1;
        }
    }
}