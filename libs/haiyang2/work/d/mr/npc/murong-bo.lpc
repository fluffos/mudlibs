 // /u/beyond/mr/npc/murong-bo.c  慕容博
// this is made by beyond
// update 1997.6.23
inherit NPC;
inherit F_MASTER;
 

void create()
{
	set_name("慕容博",({"murong bo","murong","bo"}));
        set("title","姑苏慕容老爷子");
        set("nick","以彼之道 还施彼身");
	set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容博。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	
	set("max_qi", 26500);
	set("max_jing", 26500);
	set("neili", 28500);
	set("max_neili", 28500);
	set("jiali", 50);
	set("combat_exp", 9000000);
	set("score", 50000);                
        set_skill("xingyi-zhang",380);
        set_skill("strike",280);
        set_skill("finger",280);
        set_skill("dodge",280);
        set_skill("force", 280);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",380);       
        set_skill("shenyuan-gong", 380);
	set_skill("yanling-shenfa", 380);
        set_skill("douzhuan-xingyi", 380);
	set_skill("parry", 320);
	set_skill("sword", 300);
	set_skill("literate", 300);
        set_skill("murong-daofa", 380);
        set_skill("blade",250);
         set_skill("hand", 380);
         set_skill("qxxy-shou", 380);
        set_skill("six-sword",380);       
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("hand", "qxxy-shou");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	//if (random(3)==0)	map_skill("parry", "murong-jianfa");
	map_skill("sword", "six-sword");
                map_skill("strike", "xingyi-zhang");
       prepare_skill("finger", "canhe-zhi");
        prepare_skill("hand", "qxxy-shou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                 (: perform_action, "finger.jin" :),
                (: perform_action, "finger.canshang" :),
                 (: perform_action, "finger.lian" :),
                (: perform_action, "sword.lhj" :),
                (: perform_action, "sword.nbajian" :),
                (: perform_action, "sword.tx" :),
                (: perform_action, "sword.wbajian" :),
             		(: command("unwield sword") :),
		               (: command("wield sword") :),  
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
                (: perform_action, "hand.po" :),
                 (: perform_action, "hand.xy" :),
                (: perform_action, "hand.zhai" :),

        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("姑苏慕容",1,"弟子");

       	set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容博。\n",
                        "here" : "这里是少林寺的藏经楼。\n",
                        "rumors" : "我那慕容复儿在武林之中闯出了名头，老爷子我是真高兴呀！\n",
                        
                ]));
       	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
	
}
void attempt_apprentice(object ob)
{
          object me  = this_player();
 
        string name, new_name;
	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say 好吧，既然" + RANK_D->query_respect(ob) + "有我儿的信件，难为你" +
		"如此辛苦跑来，我就收下你吧。");
 
           new_name = "慕容" + name[2..3];
	   ob->set("name", new_name);
           command("say 从今以后你就叫做" + new_name + "，希望你能把慕容功夫发扬光大！");
           command("recruit " + ob->query("id"));
           command("chat 淡淡一笑，谁言 以彼之道 还施彼身 绝迹江湖！");
           command("chat* haha"); 
         }
        else
          command("say 我慕容博岂能随便收徒!");
        return;
           
}
 

