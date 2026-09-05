// 药铺老板
// created by Zine 5 Sep 2010

inherit NPC;
#include <ansi.h>

int ask_step1();
int ask_step2();
int ask_step3();
int ask_zi();
int ask_pi();
int ask_gc();
int ask_tong();
int ask_water();
int ask_knowledge();
void create()
{
	switch( random(1) ) 
	{case 0:
	set_name("郝巴", ({ "hao ba","hao","yaopu laoban"}) );
	set("title", "药铺老板");
	set("gender", "男性" );
	set("long", "郝老板在晋阳城经营这家药铺有二十几年了。\n");
	set("chat_chance", 20);
	set("chat_msg", ({
		this_object()->query("name")+"大声道：本店什么药都有，就是没有春药。\n",
		this_object()->query("name")+"偷偷的说：这位客官，你要的那东西诸葛不亮有。\n",
	}) );
	case 1:
	set_name("郝巴", ({ "hao ba","hao","yaopu laoban"}) );
	set("title", "药铺老板");
	set("gender", "男性" );
	set("long", "郝老板在晋阳城经营这家药铺有二十几年了。\n");
	set("chat_chance", 2);
	set("chat_msg", ({
		this_object()->query("name")+"大声道：本店什么药都有，就是没有春药。\n",
		this_object()->query("name")+"偷偷的说：这位客官，你要的那东西诸葛不亮有。\n",
	}) );
	}
    set("age", 50);
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 100);
    set("combat_exp", 1000000);
    set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
    set("inquiry", ([
           
			"交个朋友" : (: ask_step2 :),
            "帮助" : (: ask_step1 :),
			"千金方" : (: ask_step3 :),
			"独门秘方" : (: ask_step3 :),
			"木桶" : (: ask_tong :),
            "蛇床子" : (: ask_zi :),
            "地骨皮" : (: ask_pi :),
            "生甘草" : (: ask_gc :),
			"热水" : (: ask_water :),
			
            
       	]) );
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
    carry_object("/d/jinyang/obj/jycloth")->wear();
}

#include "die.h"

int ask_water()
{
    object me=this_player();
    if (!me->query("drugbath/intro"))
    {
        tell_object(me,"郝巴假装没听见你在说什么。\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“泡澡的热水最好用信阳的温泉水，你可以在扬州杂货铺买来水壶去灌(guan)热水。”\n");
        return 1;
    }
}


int ask_zi()
{
    object me=this_player();
    if (!me->query("drugbath/intro"))
    {
        tell_object(me,"郝巴假装没听见你在说什么。\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“蛇床子是常备药，可以去各大药铺看看。”\n");
        return 1;
    }
}

int ask_pi()
{
    object me=this_player();
    if (!me->query("drugbath/intro"))
    {
        tell_object(me,"郝巴假装没听见你在说什么。\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“地骨皮就是枸杞的皮，枸杞在灵州可以买到。”\n");
        return 1;
    }
}

int ask_gc()
{
    object me=this_player();
    if (!me->query("drugbath/intro"))
    {
        tell_object(me,"郝巴假装没听见你在说什么。\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“甘草剥开就是生甘草，可以入药，据我发现，甘草在白驼戈壁，雪山天溪和明教的沙漠边缘可以找到。”\n");
        return 1;
    }
}

int ask_step1()
{
    object ob=this_object();
    object me=this_player();
    if (me->query_temp("pkuhao/step1a"))
    {
        tell_object(me,"郝巴说道：“你人还不错，也许我们可以做个朋友。”\n");
        return 1;
    }
    if (me->query_temp("pkuhao/step1"))
    {
        tell_object(me,"郝巴说道：“你不是问过我了吗？不想帮就算了。”\n");
        return 1;
    }
    else
    {
        me->set_temp("pkuhao/step1",1);
        tell_object(me,"郝巴说道：“我这里没有蛇床子了，我又脱不开身，你能帮我到各大药铺看看吗？”\n");
        return 1;
    }
}

int ask_tong()
{
    object tong;
    object me=this_player();
    if (me->query_temp("药浴木桶"))
    {
        tell_object(me,"郝巴说道：“你不是刚从我这拿过木桶？”\n");
        return 1;
    }
    if (me->query("drugbath/intro"))
    {
        tong=new("/d/taishan/obj/mutong");
        tong->move(me);
        me->set_temp("药浴木桶",1);
        tell_object(me,"郝巴说道：“泡澡用的大木桶我就交给你了。”\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“我自己还要用，暂时不能给你。”\n");
        return 1;
    }
}

int ask_step3()
{
    object ob=this_object();
    object me=this_player();
    if (me->query_temp("pkuhao/step2"))
    {
        tell_object(me,"郝巴说道：“我家世代行医，也留下一些珍贵的秘方。”\n");
        tell_object(me,"郝巴说道：“蛇床子，地骨皮加生甘草用热水煮开，"+HIR+"每岁"+NOR"坚持泡澡，会有神奇的功效。”\n");
        tell_object(me,"郝巴说道：“二十岁之前坚持用这些药材"+HIR+"连续"+NOR"泡澡甚至有易筋锻骨的功效。”\n");
        tell_object(me,"郝巴说道：“唯一的遗憾这种夺天造化的功法似乎不青睐懒人，"+HIR+"发呆偷懒"+NOR"过的好像就没有什么效果了。”\n");
        me->set("drugbath/intro",1);
        return 1;
    }
    if (me->query("drugbath/intro"))
    {
        tell_object(me,"郝巴说道：“你又忘记了吗？蛇床子，地骨皮加生甘草这三味药材。”\n");
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“你就是打死我，我也不会说的。”\n");
        return 1;
    }
}

int ask_step2()
{
    object ob=this_object();
    object me=this_player();
    if (me->query_temp("pkuhao/step1a"))
    {
        tell_object(me,"郝巴说道：“好吧，你这人心肠不错，我们就交个朋友把。”\n");
        me->delete_temp("pkuhao");
        me->set_temp("pkuhao/step2",1);
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“你这人也奇怪，我们毫无渊源，乱攀啥关系？”\n");
        return 1;
    }
}

int dest(object items)
{
    if (items)
    {
        destruct(items);
    }
    return 1;
}

int accept_object(object me, object items)
{
    object ob=this_object();
    if (items->query("id") == "shechuang zi" && me->query_temp("pkuhao/step1"))
    {
        me->delete_temp("pkuhao");
        me->set_temp("pkuhao/step1a",1);
        tell_object(me,"郝巴说道：“不错，这正是我急需的蛇床子，麻烦你了。”\n");
        call_out("dest",1,items);
        me->add_busy(1);
        ob->add_busy(1);
        return 1;
    }
    else
    {
        tell_object(me,"郝巴说道：“你把我当回收站吗？”\n");
        return 1;
    }
}