// 铲子 zine

#include <weapon.h>
inherit BLADE;
#include <ansi.h>
void create()
{
	set_name("小铲子", ({ "xiao chanzi", "chan" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄小铲子。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(2);
	setup();
}

void init()
{
    add_action("do_chan","chan");
}

int do_chan()
{
    object me=this_player();
    object env=environment(me);
    object thing;
    int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-8;
    if (!env)
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("emnewbiejob/jingci/task")!=2)
    {
        tell_object(me,"未经许可，不得擅自毁坏峨嵋器物。\n");
        return 1;
    }
    if (base_name(env)=="/d/emei/houshan/shdong2"&&random(2))
    {
        thing=new(__DIR__"liuhuang2");
        thing->set("owner",me->query("id"));
        thing->move(me);
        message_vision("$N用"+this_object()->name()+"挖下了一些硫磺粉末。\n",me);
        if (random(100)>55&& me->query_skill("dodge",1)<limit_sk && me->query_skill("dodge",1)< 100&&me->query_temp("emnewbiejob/jingci/chanskill")<10)
        {
            me->add_temp("emnewbiejob/jingci/chanskill",1);
            me->improve_skill("dodge",((int)me->query_skill("dodge",1)+me->query("dex")/2+random(me->query("kar"))*7/5));
            tell_object(me,HIW"你的洁癖作祟，展身避开纷纷落下的硫磺粉末，躲避过程中，你的轻功略有提高。\n"NOR);
        }
        return 1;
    }
    if (base_name(env)=="/d/emei/huayuan1"&&random(2))
    {
        thing=new(__DIR__"xiaoshi");
        thing->set("owner",me->query("id"));
        thing->move(me);
        message_vision("$N用"+this_object()->name()+"挖下了一些硝石粉末。\n",me);
        if (random(100)>60&& me->query_skill("parry",1)<limit_sk && me->query_skill("parry",1)< 100&&me->query_temp("emnewbiejob/jingci/chanskill")<10)
        {
            me->add_temp("emnewbiejob/jingci/chanskill",1);
            me->improve_skill("parry",((int)me->query_skill("parry",1)+me->query("con")/2+random(me->query("kar"))*8/5));
            tell_object(me,HIW"你的玩心大起，把硝石粉末当作了对手，躲避过程中，你的招架略有提高。\n"NOR);
        }
        return 1;
    }
    else
    {
        message_vision("$N用"+this_object()->name()+"在地上，墙上胡乱砸着，什么也没有发现。\n",me);
        return 1;
    }
}