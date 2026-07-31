// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);

void create()
{
        set_name("令牌", ({ "lingpai"}));
        set("long", "待定");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 60);
                set("unit", "块");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","cisha");
}
int do_shouzhang(string arg)
{
object ob=this_object(),me=this_player();
string targ;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要刺杀谁？\n");
        targ=ob->query("name");
if (userp(ob))
return notify_fail("你想干什么!!\n");
        if ( targ != me->query_temp("menggu_job_target") )
return notify_fail("这是刺杀"+me->query_temp("menggu_job_target")+"的令牌!!\n");

         if(me->query_condition("menggu_mission")<=1)
                return notify_fail("你不能用这块令牌做任务。\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n");

        if (me->query_temp("mgjob")!=1)
                return notify_fail("你不能用这块令牌去收帐。\n");
        message_vision(HIG"\n$N在四周埋伏了下来!”\n"NOR,me);
	ob->set_temp("must_killby",me->query("id"));
        me->set_temp("mgjob",2);
       call_out("mgjob_1", 5, me, ob);
        return 1;
}

int mgjob_1(object me,object ob)
{
        object newob;

        newob = new(__DIR__"xiashi");
        newob->set("combat_exp",me->query("combat_exp") * 5 / 5);
        newob->set("max_qi",me->query("max_qi"));
        newob->set("eff_qi",me->query("max_qi"));
        newob->set("jiali", 60);
        newob->set("qi",me->query("max_qi"));
        newob->set("max_jingli",me->query("max_jingli"));
        newob->set("eff_jingli",me->query("max_jingli"));
        newob->set("jingli",me->query("max_jingli"));
        newob->set("max_neili",me->query("max_neili"));
        newob->set("neili",me->query("max_neili"));
        newob->set_skill("force", me->query_skill("force")*2/3);
        newob->set_skill("huifeng-jian", me->query_skill("force")*2/3);
        newob->set_skill("kunlun-shenfa", me->query_skill("force")*2/3);
        newob->set_skill("strike", me->query_skill("force")*2/3);
        newob->set_skill("kunlun-zhang",me->query_skill("force")*2/3);
        newob->set_skill("jinding-zhang",me->query_skill("force")*2/3);
        newob->set_skill("dodge", me->query_skill("force")*2/3);
        newob->set_skill("sword", me->query_skill("force")*2/3);
        newob->set_skill("linji-zhuang", me->query_skill("force")*2/3);
        newob->set_skill("parry", me->query_skill("force")*2/3);
        newob->set_skill("literate", me->query_skill("force")*2/3);
        newob->set("shen",(me->query("combat_exp")/20));
        newob->move(environment(me));
        message_vision("\n" + HIW + "$N发现来接头的人来了!\n"NOR, me);
        message_vision("\n" + HIR + "$N对$n大喝一声：“你等与大汉做对，找死！”\n"NOR, me, newob);
        me->kill_ob(newob);
        newob->kill_ob(me);
        me->kill_ob(ob);
        ob->kill_ob(me);
        destruct(this_object());
}
