// baobei.c 算命婆
#include <ansi.h>
inherit NPC;

int ask_map1();
int ask_map2();
int ask_map3();
int ask_map4();
int ask_map5();
int adv();
void create()
{
        set_name(HIW"小宝贝"NOR, ({"bao bei","xiao baobei","xiao"}) );
        set("nickname",HIR"算命婆"NOR);
        set("str",20);
        set("long",
                "她是一位颇有几分姿色的算命婆。\n");
	set("age",30);
        set("shen_type",0);
	set("gender","女性");
	set("combat_exp",1000000);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	set("chat_chance_combat",30);
	set("chat_chance", 4);
        set("chat_msg", ({
                
                (:adv:),
        }) );
	set("shen_type",1);set("score",200);setup();
        set("chat_msg",({"小宝贝拽住你的衣角不放：“这位爷，来算算人品吧?”\n",
            "小宝贝扯着嗓子大吼：“本小姐专算人品，一次一两黄金，算不准退钱喽~~~”\n",
            "小宝贝叹了口气，嘴里嘀咕：“这世道，网吧也不好开了，只能出来算命骗骗钱。。。”\n",
	}));
      set("inquiry", (["算人品" : "给我一两黄金就给你算算人品！\n",
                       "第一张图" : (: ask_map1 :),
                       "第二张图" : (: ask_map2 :),
                       "第三张图" : (: ask_map3 :),
                       "第四张图" : (: ask_map4 :),
                       "第五张图" : (: ask_map5 :),
          ]) );
	carry_object("/d/city/obj/cloth")->wear();
}

int adv()
{
    if (random(100)>95)
    {
        CHANNEL_D->do_channel(this_object(), "bd", "如果你记不得藏宝图丢在哪里了，也许我可以帮你。");
    }
        
}

int ask_map1()
{
    object me=this_player();
    if (me->query("balance")<100000)
    {
        command("say "+" 你好像钱不够呀！\n");
        return 1;
    }
    if (!me->query_temp("huyidaomap1"))
    {
        command("say "+" 你丢过这张图吗？我算不出来啊！\n");
        return 1;
    }
    else
    {
        command("whisper "+me->query("id")+" 好吧，好吧，我告诉你，你的地图丢在了"+me->query_temp("huyidaomap1")+"！\n");
        if (me->query_temp("baobeiasked"))
        {
            me->add("balance",-5000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
        else
        {
            me->add("balance",-100000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
    }
}

int ask_map2()
{
    object me=this_player();
    if (me->query("balance")<100000)
    {
        command("say "+" 你好像钱不够呀！\n");
        return 1;
    }
    if (!me->query_temp("huyidaomap2"))
    {
        command("say "+" 你丢过这张图吗？我算不出来啊！\n");
        return 1;
    }
    else
    {
        command("whisper "+me->query("id")+" 好吧，好吧，我告诉你，你的地图丢在了"+me->query_temp("huyidaomap2")+"！\n");
        if (me->query_temp("baobeiasked"))
        {
            me->add("balance",-5000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
        else
        {
            me->add("balance",-100000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
    }
}

int ask_map3()
{
    object me=this_player();
    if (me->query("balance")<100000)
    {
        command("say "+" 你好像钱不够呀！\n");
        return 1;
    }
    if (!me->query_temp("huyidaomap3"))
    {
        command("say "+" 你丢过这张图吗？我算不出来啊！\n");
        return 1;
    }
    else
    {
        command("whisper "+me->query("id")+" 好吧，好吧，我告诉你，你的地图丢在了"+me->query_temp("huyidaomap3")+"！\n");
        if (me->query_temp("baobeiasked"))
        {
            me->add("balance",-5000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
        else
        {
            me->add("balance",-100000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
    }
}

int ask_map4()
{
    object me=this_player();
    if (me->query("balance")<100000)
    {
        command("say "+" 你好像钱不够呀！\n");
        return 1;
    }
    if (!me->query_temp("huyidaomap4"))
    {
        command("say "+" 你丢过这张图吗？我算不出来啊！\n");
        return 1;
    }
    else
    {
        command("whisper "+me->query("id")+" 好吧，好吧，我告诉你，你的地图丢在了"+me->query_temp("huyidaomap4")+"！\n");
        if (me->query_temp("baobeiasked"))
        {
            me->add("balance",-5000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
        else
        {
            me->add("balance",-100000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
    }
}

int ask_map5()
{
    object me=this_player();
    if (me->query("balance")<100000)
    {
        command("say "+" 你好像钱不够呀！\n");
        return 1;
    }
    if (!me->query_temp("huyidaomap5"))
    {
        command("say "+" 你丢过这张图吗？我算不出来啊！\n");
        return 1;
    }
    else
    {
        command("whisper "+me->query("id")+" 好吧，好吧，我告诉你，你的地图丢在了"+me->query_temp("huyidaomap5")+"！\n");
        if (me->query_temp("baobeiasked"))
        {
            me->add("balance",-5000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
        else
        {
            me->add("balance",-100000);
            me->set_temp("baobeiasked",1);
            return 1;
        }
    }
}

int accept_object(object who,object ob)
{
	object me=this_player();
	int rp;
  if (ob->query("money_id") && ob->value() >= 10000) 
	{	
		rp = (int)me->query_temp("apply/magic");
    command("say "+" 好吧，我就给这位大爷算算人品。\n");
        if (rp < 100)
    command("say "+"考，算个屁啊，负的。赶紧给我消失！\n");
        else if (rp < 200)
    command("say "+"哦买告的，就你这人品居然也能活到现在？！\n");
        else if (rp < 400)
    command("say "+"我的妈呀，这位爷，天天踩狗屎真是辛苦你了！\n");
        else if (rp < 700)
    command("say "+"唉，怎么说呢，你也别太灰心，老秃人品比你还差呢，人家不也活得好好的？\n");
        else if (rp < 1100)
    command("say "+"恭喜你，人品超过老秃了！\n");
        else if (rp < 1600)
    command("say "+"不错不错，长得虽丑，人品却是好的紧！\n");
        else if (rp < 2200)
    command("say "+"这位爷简直是人中龙凤，您若不嫌弃的话，带小妹私奔吧！\n\n");
        else
    command("say "+"这么牛X的人品？死虫子，快把面具摘掉！\n");
    return 1;		
	}
}
