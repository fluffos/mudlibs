// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit NPC;
int ask_yq();


void create()
{
	set_name(HIG"孔翘"NOR, ({"kong qiao", "kong", "qiao",}));
	set("long", "这是一个十八九岁的少女，颇有几分姿色。\n");
	set("gender", "女性");
    set("title","孔子第三十八代孙女");
	set("attitude", "friendly");
	set("age", 18);
	set("shen_type",1);
	set("str", 13);
	set("int", 30);
	set("con", 17);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 100);
	set("combat_exp", 6400);
	set_skill("dodge", 20);
	set_skill("parry", 20); 
	set_skill("cuff", 40);
	
    set("inquiry", ([
		
    "燕青": (:ask_yq:),
    "浪子燕青": (:ask_yq:),
    "yanqing": (:ask_yq:),
	]) );
	setup();
}

int dest(object items)
{
    if (items)
    {
        command("drink yutoudoufu tang");
        destruct(items);
        return 1;
    }
}

int accept_object(object me, object items)
{
    object ob=this_object();
    if (ob->is_busy() || ob->is_fighting())
	{
		return notify_fail("孔翘正忙着呐！\n");
    }
    if (items->query("id")!="yutoudoufu tang")
    {
        return notify_fail("孔翘道：你给我这个干吗？\n");
    }
    if (items->query("liquid/remaining")>random(9)+3)
    {
        return notify_fail("孔翘道：我怎么知道有没有毒？你喝几口给我看看。\n");
    }
    if (items->query("liquid/remaining")<7)
    {
        return notify_fail("孔翘道：汤都给你喝完了，我才不要呢。\n");
    }
    else
    {
        call_out("dest",1,items);
        me->set_temp("yanqing",1);
        tell_object(me,"孔翘道：好吧，既然你请我吃了鱼头汤，我也不会白要你的，有什么事你就问吧。\n");
        return 1;
    }
}

int ask_yq()
{
    object me=this_player();
    object ob=this_object();
    if (me->query_temp("yq"))
    {
        command("say 我不是刚告诉过你吗？还老问什么啊？");
        return 1;
    }
    if (!me->query_temp("yanqing"))
    {
        command("say 我好像听说过这个人，又好像没听说过。");
        command("say 一般情况下，我吃过鱼头豆腐汤记忆力会比较好。");
        command("taste");
        return 1;
    }
    
    else
    {
        command("say 燕大哥和师师姐马上就要飘洋过海离开中土了。");
        command("say 你马上去黄河入海口，也许还能见上他们一面。");
        command("say 去了记得替我喊一声，问一个好。");
        me->delete_temp("yanqing");
        me->set_temp("yq",1);
        return 1;
    }
}