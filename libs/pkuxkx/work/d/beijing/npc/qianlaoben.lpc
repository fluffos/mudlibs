// qianlaoben.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
//added by iszt@pkuxkx, 2006-09-13
int ask_zhu();

void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500);
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set_skill("hand", 70);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("yunlong-shou", 90);
	set_skill("yunlong-shenfa", 60);
	map_skill("hand", "yunlong-shou");
	map_skill("dodge", "yunlong-shenfa");

	prepare_skill("hand", "yunlong-shou");

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);

	create_family("天地会", 4, "弟子");

        set("vendor_goods", ({
//                __DIR__"obj/zhutou",
        }) );
	set("chat_chance", 5);
	set("chat_msg", ({
	"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
	"钱老本说：只有对本派弟子我才这么客气，对别的人啊，哼哼......\n",
        "钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	"钱老本说：呆会儿我还得把猪送到宫里去。\n",
	"钱老本突然吆喝道: 花雕芙苓猪啊，只卖黄金一两，谁买谁买啊？\n",
	"钱老本突然吆喝道: 燕窝人参猪啊，只卖黄金一两，谁买谁买啊？\n",
        "钱老本搔了搔头，说道：这么好的猪肉怎么没人要啊。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "反清复明" : "去棺材店和天桥仔细瞧瞧吧！\n",
                "进宫" : (: ask_zhu :),
                "花雕芙苓猪" : (: ask_zhu :),
                "燕窝人参猪" : (: ask_zhu :),
       ]) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	set("shen_type",-1);
set("score",5000);
setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 15);
}


void init()
{
        ::init();

        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 10000)
	{
		message_vision("\n钱老本对$N一揖作礼，说道：这位客官，要什么尽管说。\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	return 0;
}


int ask_zhu()
{
              object ob,ppl,me;
              ppl=this_player();
              me=this_object();
        if(ppl->query("family/family_name") ==  "天地会")
                        {
                                ob = new("/d/beijing/npc/obj/hgtongxing-ling");
              ob->move(ppl);
//              ppl->set_temp("apply/short",  HIY"一口"HIG"小小小小小小"HIR"猪 "NOR + ppl->query("name") + "(" + capitalize(ppl->query("id")) + ")");
              message_vision("钱老本给了$N一个皇宫通行令！\n",ppl);    
              command("say 大内禁地，不可久留！");     
                                return 1;
                        }
                                else 
                                    {
                                            if (ppl->query("repute")<50000)
                                            {
                                            command("sneer");
              command("say 你在江湖上只不过是无名小卒，靠边站！");
              message_vision("看起来你的江湖声望不够！\n",ppl); 
                                            return 1;
                                            }                   
                                            if (ppl->query_temp("money_paid"))
                                                        {
                                                        ppl->delete_temp("money_paid");
                                ob = new("/d/beijing/npc/obj/hgtongxing-ling");
              ob->move(ppl);
//              ppl->set_temp("apply/short",  HIY"一口"HIG"小小小小小小"HIR"猪 "NOR + ppl->query("name") + "(" + capitalize(ppl->query("id")) + ")");
              message_vision("钱老本给了$N一个皇宫通行令！\n",ppl);    
              command("say 大内禁地，不可久留！");  
                                                        say("钱老本说：您老现在可以走啦！\n");
                                                        return 1;
                                                        }
                                                        say("钱老本说：干什么也得先交钱啊。\n");
                                                        return 1;
                                                        }
}

