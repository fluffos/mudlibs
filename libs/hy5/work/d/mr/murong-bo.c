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
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 14500);
	set("max_neili", 14500);
	set("jiali", 50);
	set("combat_exp", 3000000);
	set("score", 50000);                
        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
        set_skill("xingyi-zhang",200);
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",300);       
        set_skill("shenyuan-gong", 300);
	set_skill("yanling-shenfa", 300);
        set_skill("douzhuan-xingyi", 300);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 300);
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
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "dodge.yanling" :),                
                (: perform_action, "dodge.yanling" :),                
        }));
        
        create_family("姑苏慕容",1,"弟子");

       	set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容博。\n",
                        "here" : "这里是少林寺的藏经楼。\n",
                        "rumors" : "我那慕容复儿在武林之中闯出了名头，老爷子我是真高兴呀！\n",
                        
                ]));
       	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	
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
 

