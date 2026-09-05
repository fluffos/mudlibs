
#include <ansi.h>
inherit NPC;
int ask_quest();

void create()
{
	set_name("老唐", ({ "lao tang", "tang","lao" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 40+random(25));
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
            "name" : "叫我老唐好了。",
            "here" : "这里是成都，我在这看门几十年了。",
			"quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
       	]) );

	setup();
    carry_object("/clone/cloth/cloth")->wear();

}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("jiangnanquest/finish"))
    {
        command("admire "+me->query("id"));
        return 1;
    }
    else if (me->query("jiangnanquest/step1"))
    {
        command("say 我这没什么事了，你去岳阳，找李保长看看他有什么事。\n");
		return 1;
    }
    else
    {
        command("say 你去岳阳楼，给我买一盘君山银针，记住，不是新鲜的我才不吃呢。\n");
        me->set_temp("jn/step1",1);
		return 1;
    }
}

int dest(object food,object me)
{
    int exp=random(100);
    if (food)
    {
        destruct(food);
    }
    me->add("combat_exp",exp);
    tell_object(me,HIW+sprintf("听完老唐的人生经历，你不禁感慨万千，你的经验增加了%d点。\n",exp)+NOR);
    return 1;
}

int accept_object(object me, object food)
{
	if( food->query("id") != "junshan yinzhen")
	return notify_fail("老唐说道，这是什么啊？不是君山银针啊。\n");
    if (!me->query_temp("jn/step1"))
    return notify_fail("老唐说道，非亲非故的，你给我这个干吗呀？\n");
    me->delete_temp("jn/step1");
    if (food->query("notfresh"))
    return notify_fail("老唐皱了皱眉，道：这个君山银针好像不太新鲜了。\n");
	if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着哪！\n");
    if (this_object()->is_busy() || this_object()->is_fighting())
    return notify_fail(this_object()->query("name")+"正忙着哪！\n");
	else
		{
			me->set("jiangnanquest/step1",1);
			command("say 不错，这就是我喜欢吃的君山银针啊。\n");
            tell_object(me,this_object()->query("name")+"开始给你讲了些人生的道理。\n");
            call_out("dest",1,food,me);
            this_object()->add_busy(1);
            me->add_busy(1);
            return 1;
		}
}
