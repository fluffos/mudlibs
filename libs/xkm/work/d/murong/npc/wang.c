// /u/chen/murong/npc/wang.c 王夫人
// by chen

inherit NPC;
string ask_job();

void create()
{
	set_name("王夫人",({"wang furen","wang","furen"}));
	set("gender", "女性");
	set("rank_info/respect", "夫人");
        set("title","曼佗罗山庄主人");
  	set("long", 
              "她就是曼佗罗山庄的主人，她看上去虽以四十有加，但风韵尤存。\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 20);
	set("int", 22);
	set("con", 28);
        set("per", 30);
	set("dex", 23);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 2500);
	set("jiali", 0);
	set("combat_exp", 80000);

	set_skill("force",130);
	set_skill("dodge",130);
	set_skill("blade",130);
	set_skill("sword",130);
	set_skill("strike",130);
	set_skill("parry",130);
	set_skill("literate",130);
	set_skill("douzhuan-xingyi",130);
	set_skill("murong-shenfa",130);
	set_skill("murong-daofa",130);
	set_skill("murong-jianfa",130);
	set_skill("xingyi-zhang",130);

	map_skill("strike","xingyi-zhang");
	map_skill("force","douzhuan-xingyi");
	map_skill("parry","douzhuan-xingyi");
	map_skill("dodge","murong-shenfa");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");

	prepare_skill("strike","xingyi-zhang");
        
	setup();
        carry_object("/d/murong/obj/shoe")->wear();
        carry_object("/d/murong/obj/red_silk")->wear();
        carry_object("/d/murong/obj/skirt")->wear();
        
        set("inquiry", ([
            "name" : "我就是曼佗罗山庄的主人，见到我难道没有什么表示吗？\n",
            "here" : "这里是曼佗罗山庄的庄院之所在，此处名为云锦楼？\n",
            "rumors" : "最近我那表亲慕容博不幸仙逝了。\n",
            "王语嫣" : "语嫣是我的宝贝女儿，你可别想打她的主意。\n",
            "慕容复" : "慕容复是我那不成器的侄儿，练就了以彼之道还施彼身的绝技，名震江湖。\n",
            "娘缳玉洞" : "娘缳玉洞是我曼佗罗山庄的藏书之处，一般人是别想进去了。\n",
            "曼佗罗山庄" : "这里就是曼佗罗山庄，我就是这里的主人。\n",
            "还施水阁" : "那是燕子坞的秘密之所在，不过还施水阁的藏书比那里可是多的多呀。\n",
       ]));
         set("chat_chance",5);
         set("chat_msg",({
				"王夫人说道：“慕容那一家没一个好人，可不能让语嫣这孩子嫁给他表哥。”\n",
                            
        }) );

}