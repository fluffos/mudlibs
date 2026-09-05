// zine em newbie job
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("木制小球", ({"xiaoqiu","qiu"}));
	    set_weight(40);
        set("is_xiaoqiu",1);
	
		set("long", "一个木制的小球，制作十分精巧。\n");
		set("unit", "个");
		set("value", 0);
        setup();
}

void init()
{
    add_action("do_hehehe","guan");
}

int made(object me)
{
    object pld;
    int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-20;
    if (random(100)>29)
    {
        message_vision("$N把小球封口，一颗霹雳弹制成了。\n",me);
        pld=new(__DIR__"pilidan_2");
        pld->set("owner",me->query("id"));
        pld->move(me);
        destruct(this_object());
        return 1;
    }
    else
    {
        message_vision("$N一不小心把小球掉在了地上，硫磺和硝石洒了一地。\n",me);
        me->add_busy(random(3));
        if (random(100)>49&& me->query_skill("pili-dan",1)<limit_sk && me->query_skill("pili-dan",1)< 100)
        {
            me->improve_skill("pili-dan",50+random((int)me->query_skill("dodge")+(int)me->query_skill("throwing")));
            tell_object(me,HIW"你被落地的霹雳弹惊得目瞪口呆，却对霹雳弹的运用有了更深的认识。\n"NOR);
        }
        if (random(100)>39&& me->query_skill("throwing",1)<limit_sk && me->query_skill("throwing",1)< 100)
        {
            me->improve_skill("throwing",random(50)+random((int)me->query_skill("dodge")+(int)me->query_skill("throwing")));
            tell_object(me,HIW"你被落地的霹雳弹惊得目瞪口呆，却对基本暗器的运用有了更深的认识。\n"NOR);
        }
        this_object()->move(environment(me));
        return 1;
    }
    
}

int do_hehehe()
{
    object me=this_player();
    object xs,lh;
    if (!present("liuhuang fen",me))
    {
        tell_object(me,"制作霹雳弹还需要一些硫磺粉。\n");
        return 1;
    }
    if (!present("xiaoshi fen",me))
    {
        tell_object(me,"制作霹雳弹还需要一些硝石粉。\n");
        return 1;
    }
    xs=present("xiaoshi fen",me);
    lh=present("liuhuang fen",me);
    if (xs->query("owner")!=me->query("id")||!xs->query("is_xiaoshi"))
    {
        tell_object(me,"这些硝石粉从哪得来的？假货啊！\n");
        return 1;
    }
    if (lh->query("owner")!=me->query("id")||!lh->query("is_liuhuang"))
    {
        tell_object(me,"这些硫磺粉从哪得来的？假货啊！\n");
        return 1;
    }
    if (base_name(environment(me))!="/d/emei/houshan/ywdong")
    {
        tell_object(me,"峨嵋空气太过湿润，只有药王洞适合制作霹雳弹。\n");
        return 1;
    }
    message_vision(HIW"$N开始把硫磺和硝石灌进小球里。\n"NOR,me);
    destruct(lh);
    destruct(xs);
    me->add_busy(5);
    call_out("made",5,me);
    return 1;
}