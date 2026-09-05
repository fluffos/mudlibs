// caoyao.c 草药

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
	add_action("do_fenjian", ({"fenjian","分拣"}));
}

void create()
{
	set_name("晒干的草药", ({"caoyao", "yao"}));
    set("is_gancaoyao",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片晒干的草药。\n");
		set("value", 100);
	}
	setup();
}

int do_fenjian()
{
    object me=this_player();
    object ob=this_object();
    object cy;
    int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-10;
    if (me->query_temp("emnewbiejob/jingci/task")!=1)
    {
        tell_object(me,"你想干嘛？\n");
        return 1;
    }
    if (ob->query("owner")!=me->query("id"))
    {
        tell_object(me,"你从哪捡的草药啊？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    me->add_busy(1);
    message_vision("$N开始仔细分拣晒干的草药，选出其中可以入药的部分。\n",me);
    if (random(100)>59)
    {
        tell_object(me,"你找到一份可以入药的草药。\n");
        if (random(2)&& me->query_skill("force",1)<limit_sk && me->query_skill("force",1)< 100)
        {
            me->improve_skill("force",((int)me->query_skill("force",1)/5+me->query("con")*5/3+random(me->query("kar"))));
            tell_object(me,HIW"受药物药力刺激，你的内功造诣有了进步。\n"NOR);
        }
        cy=new(__DIR__"caoyao3");
        cy->set("owner",me->query("id"));
        cy->move(me);
        destruct(ob);
        return 1;
    }
    else
    {
        tell_object(me,"这片草药药性全无，被你扔掉了。\n");
        if (!random(4)&& me->query_skill("force",1)<limit_sk && me->query_skill("force",1)< 100)
        {
            me->improve_skill("force",((int)me->query_skill("force")/5+me->query("con")*7/3+random(me->query("kar"))));
            tell_object(me,HIW"你想了想，扔了还不如自己服用，受药物药力刺激，你的内功造诣有了进步。\n"NOR);
        }
        destruct(ob);
        return 1;
    }
}

