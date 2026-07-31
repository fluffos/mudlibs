// /u/beyond/mr/npc/wang.c 王夫人
// this is made by beyond
// update 1997.6.29
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job1();
#include "/quest/givegift.c"
void create()
{
	set_name("王夫人",({"wang furen","wang","furen"}));
	set("gender", "女性");
	set("rank_info/respect", "夫人");
        set("title","曼佗罗山庄主");
  	set("long", 
              "她就是曼佗罗山庄的主人，她看上去虽以四十有加，但风韵尤存。\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 22);
	set("con", 28);
        set("per", 30);
	set("dex", 30);
	
	set("max_qi", 29500);
	set("max_jing", 29500);
	set("neili", 45000);
	set("max_neili", 45000);
	set("jiali", 0);
	set("combat_exp", 0500000);
	set("score", 15000);

        set_skill("xingyi-zhang",320);
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 320);
	set_skill("murong-jianfa",320);       
        set_skill("shenyuan-gong", 320);
	set_skill("yanling-shenfa", 320);
        set_skill("douzhuan-xingyi", 320);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 320);
        set_skill("blade",200);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "dodge.yanling" :),                
   
        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("姑苏慕容",1,"弟子");
        
	setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
	carry_object("/clone/weapon/changjian")->wield();        
        set("inquiry", ([
            "name" : "我就是曼佗罗山庄的主人，见到我难道没有什么表示吗？\n",
            "here" : "这里是曼佗罗山庄的庄院之所在，此处名为云锦楼？\n",
            "rumors" : "最近我那表亲慕容博不幸仙逝了。\n",
            "王语嫣" : "语嫣是我的宝贝女儿，你可别想打她的主意。\n",
            "慕容复" : "慕容复是我那不成器的侄儿，练就了以彼之道还施彼身的绝技，名震江湖。\n",
            "娘缳玉洞" : "娘缳玉洞是我曼佗罗山庄的藏书之处，一般人是别想进去了。\n",
            "曼佗罗山庄" : "这里就是曼佗罗山庄，我就是这里的主人。\n",
            "还施水阁" : "那是燕子坞的秘密之所在，不过还施水阁的藏书比那里可是多的多呀。\n",       
                       "浇花" : (: ask_job1 :),
                       "工具" : "你去问严妈妈要吧！", 
                       "work" : (: ask_job1 :),
                       "tools" : "你去问严妈妈要吧！", 

       ]));
}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
 
       add_action("do_task","task"); 
     
}

string ask_job1()
{
        object me;
        object ob;
        string target;
        mapping fam;
        ob=this_player();
        me=this_object();
        fam = ob->query("family");
        
        if(!fam || fam["family_name"] != "姑苏慕容")
         return ("用你去做花肥好吗？\n");
        if (ob->query_temp("mr_job"))
         return ("你不是已经领了工作吗？还不快去做。\n");
        if ( (int)ob->query_condition("mr_job" ) > 0 )
                return RANK_D->query_respect(ob) + 
                "花刚浇过，等会再来。";
         ob->set_temp("mr_job","浇花");
         ob->apply_condition("mr_job", 4);
         return "我种了很多花，你有空的话，帮我去浇一下吧。";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me;
        ob=this_player();
        me=this_object();


        if(!(arg||arg=="ok")) return 0;
        if(!ob->query_temp("mr_job")) 
            return notify_fail(HIC"我不记得让你去浇花的事啊？\n"NOR);
        if(!ob->query_temp("mark/还了")) 
            return notify_fail(CYN"王夫人说道：你先把工具还给严妈妈，再来覆命吧。\n"NOR);
        if(!(ob->query_temp("mark/浇完")))
            return notify_fail(CYN"王夫人说道：花浇好了吗? \n"NOR);
        if( arg=="ok"&& (ob->query_temp("mark/浇完")))
        {
          command("smile "+ob->query("id"));
          command("say "+RANK_D->query_respect(ob)+"谢谢你啊！");

        money =random((int)(ob->query_skill("shenyuan-gong",1)/10))+1;
        pot =40+random(30);
        exp =50+random(50);
        shen =random(10)+30;
        if (money > 15) money=15;
        me->add_money("silver",money);
        command("give "+ob->query("id")+" "+ money +" silver");
exp=exp/2+8;
addnl(ob,"exp",exp);
        ob->add("shen",shen);
ob->start_busy(5);
        ob->delete_temp("mr_job");
        ob->delete_temp("mark");        
        return 1;
        }
        return 1;
}

