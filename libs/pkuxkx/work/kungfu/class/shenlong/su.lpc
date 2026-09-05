// su.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

int ask_wxb();
int ask_beauty();
void create()
{
	set_name("苏荃", ({ "su quan", "su" }));
	set("title",  HIY"神龙教"NOR"教主夫人" );
        set("no_get",1);
        set("long", "她就是神龙教教主洪安通的夫人。\n她看起来看模样不过二十三四岁年纪，微微一笑，媚态横生，艳丽无比。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
        set("max_qi", 4000);
        set("qi", 4000);
        set("max_jing", 3000);
        set("jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
        set("combat_exp", 10000000);
	set("score", 400000);
        set("shenlong/meiren", 1);
        set("shenlong/yingxiong", 1);


        set_skill("force", 300);
        set_skill("strike", 300);
        set_skill("whip", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("dagger",300);
        set_skill("dulong-bi",300);
        set_skill("yixingbu", 300);
        set_skill("shenlong-bian", 300);
        set_skill("huagu-mianzhang", 300);
        set_skill("shenlong-xinfa", 300);
        set_skill("literate", 300);
        map_skill("dodge", "yixingbu");
        map_skill("force", "shenlong-xinfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry", "shenlong-bian");
        map_skill("dodge", "yixingbu");
        map_skill("whip", "shenlong-bian");
        map_skill("dagger", "dulong-bi");
        prepare_skill("strike", "huagu-mianzhang");
	create_family("神龙教",2,"弟子");

        set("inquiry", ([
                "神龙教" :  "\n一般人是入不了我神龙教的!\n",
                "入教"   :  "\n一般人是入不了我神龙教的!\n",
                "韦小宝"   :    (: ask_wxb :),
                "绝招"   :    (: ask_beauty :),
                "美人三招"   :    (: ask_beauty :),
		"口号"   : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
//                "tuijiao": (: ask_tuijiao :),
        ]));
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: CHANNEL_D->do_channel(this_object(), "bd", "凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
                (: exert_function, "recover" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.yingxiong" :),
                (: perform_action, "dagger.yingxiong" :),
                (: perform_action, "dagger.yingxiong" :),
                (: exert_function, "recover" :),
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object(random(2)?"/clone/weapon/bishou":"/clone/weapon/changbian")->wield();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
//		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (!ob) return;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}

void attempt_apprentice(object ob)
{

        command("say 你要拜师还是找教主吧，我不收徒，不过如果你忠于本教，我可以传你三招! ");
        return;
}

int ask_tuijiao()
{
        object ob;
        ob=this_player();

        if(ob->query("party/party_name") != HIY "神龙教" NOR )
        {
        message_vision("苏荃莞尔一笑，对$N说道：你还没加入我神龙教呢，就想退教？\n",ob);
                return 1;
        }
        if(ob->query("family/family_name") == "神龙教" )
        {
message_vision("苏荃板起俏脸对$N说道：你已经是我神龙弟子，如何能退教？\n", ob);
                return 1;
        }
        command("look "+ob->query("id"));
        command("sigh ");
        command("nod ");
        command("say 异日你不要撞在我手上! ");
        ob->delete("party");
        ob->delete("rank");
        ob->delete("level");
        return 1;
}

int ask_beauty()
{
        object ob;
        ob=this_player();
        if(ob->query("party/party_name") != MAG "神龙教" NOR)
        {
        command("slap "+ob->query("id"));        
        message_vision("苏荃怒道：哪里来的奸细，给我滚！！！\n",ob);
        return 1;
        }
        if(ob->query("family/family_name") !=  "神龙教")
        {
        command("slap "+ob->query("id"));        
        message_vision("苏荃怒道：哪里来的奸细，给我滚！！！\n",ob);
        return 1;
        }
        if((int)ob->query("score") <1500)
        {
        command("consider");        
        message_vision("苏荃说道：你对本教的贡献太小了，绝招还不能传授给你！\n",ob);
        return 1;
        }
/*
       if((int)ob->query("shenlong/42jing") <1 )
        {
        command("consider");        
        message_vision("苏荃说道：本教正在全力寻找四十二章经，如果你能全部找到，我就把绝招传授给你！\n",ob);
        return 1;
        }
*/
        if(ob->query("shenlong/meiren"))
        {
        command("?");        
        message_vision("苏荃说道：我不是已经教会你了么？！\n",ob);
        return 1;
        }
        if((int)ob->query_temp("shenlong/findwxb")<1)
                                { 
        if(random(10)>8) {
                                command("sigh");
                                command("goaway "+ob->query("id")); 
        message_vision("苏荃说道：我现在心情不好，以后再说吧！\n",ob);
      }
     else {
                                command("look "+ob->query("id")); 
                                command("hmm "+ob->query("id")); 
        message_vision("苏荃说道：如果你能帮我找回一个人... ...\n",ob);
     }

        return 1;
        }
        command("wa1");
        command("great");
        command("say 感谢你把我的信送给了韦小宝! ");
        command("pat "+ob->query("id"));
        command("say 我现在就把美人三招传授给你! ");
                                ob->set("shenlong/meiren",1);
        return 1;
}
int ask_wxb()
{
        object ob,ob1,me;
        me=this_object();
        ob=this_player();
        if(ob->query("party/party_name") != MAG "神龙教" NOR)
        {
        return 0;
        }
        if(ob->query("family/family_name") !=  "神龙教")
        {
        return 0;
        }
        if((int)ob->query_temp("shenlong/findwxb")==1)
                                { 
        return 0;
        }
        if((int)ob->query("shenlong/meiren")==1)
                                { 
        return 0;
        }

/*
        if(random(ob->query("kar"))<15)
        {
        command("dono "+ob->query("id"));      
        return 1;
        }
*/
        if((int)ob->query_temp("shenlong/findwxb_su")==1 || (int)ob->query_temp("shenlong/findwxb_mu")==1 ||(int)ob->query_temp("shenlong/findwxb_fang")==1 )
        {
        command("quick "+ob->query("id"));  
        command("say 赶快去！我等着你的消息呢！");    
        return 1;
        }
        command("yi "+ob->query("id"));
        command("look "+ob->query("id"));  
        command("secret "+ob->query("id")); 
        command("say 跟我来！");
        me->move("/d/shenlongdao/dongxiangfang");  
        message_vision("你跟着苏荃来到了东厢房！\n",ob);   
        ob->move("/d/shenlongdao/dongxiangfang");        
        ob->set_temp("shenlong/findwxb_su",1);
        message_vision("苏荃给了你一封信！\n",ob);   
//        add("paper_count",-1);
        ob1 = new("/d/shenlongdao/obj/letter_suquan");
        ob1->move(ob);
        message_vision("苏荃意味深长地看了你一眼！\n",ob);         
        me->move("/d/shenlongdao/qianlongtang");  
        message_vision("苏荃说道：你如果帮我帮我带回他的消息，我就教你美人三招！\n",ob); 
        message_vision("苏荃说完就匆匆忙忙走开了！\n",ob); 
        return 1;
}

#include "/kungfu/class/masterdie.h"