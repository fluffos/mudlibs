// 扫把
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("扫把", ({"sao ba", "saoba"}));
        set_weight(200);
        set("is_saoba",1);
        set("unit", "把");
        set("long","这是一把扫把。\n");
        set("material", "wood");
}

void init()
{
    add_action("do_dasao","dasao");
}


int do_dasao()
{
    object me=this_player();
    object env=environment(me);
    int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-5;
    if (!env)
    {
        return 0;
    }
    if (!me->query("emnewbiejob/qingjie/start"))
    {
        tell_object(me,"谁让你来打扫的呀？\n");
        return 1;
    }
	if (me->query_temp("emnewbiejob/qingjie/finish"))
	{
        tell_object(me,"这里已经完全恢复了原来的面貌，你可以回去复命了。\n");
		return 1;
	}
    if (!env->query("using"))
    {
        tell_object(me,"这里干干净净，不需要你多做打扫。\n");
		me->add_temp("emnewbiejob/qingjie/robot",1);
        return 1;
    }
    if (env->query("startdasao")&&env->query("startdasao")!=me->query("id"))
    {
        tell_object(me,"这里已经有人打扫了。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"看你手忙脚乱的。\n");
        return 1;
    }
    else
    {
        if (me->query_temp("emnewbiejob/qingjie/sao_degree")>random(10)+25)
        {
            me->set_temp("emnewbiejob/qingjie/finish",1);
            tell_object(me,"这里已经完全恢复了原来的面貌，你可以回去复命了。\n");
            env->set("long",env->query("old_long"));
            env->set_temp("mixed_long",env->query("long"));
            env->delete("using");
            env->delete("startdasao");
            return 1;
        }
        env->set("startdasao",me->query("id"));
        message_vision("$N认真地清扫着这里。\n",me);
        me->add_busy(1+random(2));
		if (!me->query_temp("emnewbiejob/qingjie/robot"))
		{
		
			if (!random(4)&& me->query_skill("sword",1)<limit_sk && me->query_skill("sword",1)< 100)
			{
				me->improve_skill("sword",((int)me->query_skill("literate",1)*3/5+me->query("int")*4/3+random(me->query("kar"))));
				tell_object(me,HIW"在扫地中，你突然福至心灵，悟出了一些用剑的心得。\n"NOR);
			}
			if (!random(4)&& me->query_skill("blade",1)<limit_sk && me->query_skill("blade",1)< 100)
			{
				me->improve_skill("blade",((int)me->query_skill("literate",1)*3/5+random(me->query("int")*4/3+me->query("kar"))));
				tell_object(me,HIW"在扫地中，你突然福至心灵，悟出了一些用刀的心得。\n"NOR);
			}
		}
        me->add_temp("emnewbiejob/qingjie/sao_degree",1);
        return 1;
    }
}