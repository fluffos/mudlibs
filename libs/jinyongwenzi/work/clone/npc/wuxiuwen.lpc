// wuxiuwen.c武修文

inherit NPC;

 
int ask_ji();
void consider();

void create()
{
	set_name("武修文", ({ "wu xiuwen","wu","xiuwen" }) );
	set("gender", "男性" );
	set("age", 26);
	set("long", "身材修长，面目俊朗，一看就是名门后代。\n");
	set("attitude", "friendly");
//      set("nickname", "");
        set("str", 35);
	set("con", 30);
	set("int", 20);
	set("dex", 30);
 

	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 2000);
        set("eff_jingli", 1500);
	set("max_neili", 2000);
	set("jiali", 100);
	set("shen", 6500);
	set("startroom","/d/xiangyang/outsroad1");

	 
	set("combat_exp", 850000);

	set_skill("force", 140); 
	set_skill("strike", 140);
	set_skill("blade", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("huntian-qigong", 140);
	set_skill("literate", 140);
	set_skill("xianglong-zhang", 150); 
	set_skill("liuhe-daofa", 140);
	set_skill("xiaoyaoyou", 140);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(: perform_action, "strike.paiyun" :)
        }));

	map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("strike", "xianglong-zhang");
        map_skill("parry", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");

	create_family("丐帮", 19, "挂名弟子");

 set("inquiry", ([
       "叫化鸡" : (: ask_ji :),
      ]));
	set("chat_chance", 20);
	set("chat_msg", ({
		"武修文说到：“要能学得郭伯伯两三成功夫，那也可也...\n",
		"武修文说到：“不知道郭芙心理到底怎麽想的？\n",
                 (: random_move :)
	}) );

	setup();
        carry_object("/d/city/obj/cloth")->wear();
         
}
  int ask_ji()
{
  object ob;
  ob=this_player();
if (ob->query("shen")<=0) return 0;
if (ob->query_temp("marks/jiaohua-ji") || ob->query_temp("marks/lost-ji") )
{
command("cry");
command("say 刚刚在扬州,..在扬州,我把鸡搞丢了!我不敢回去见老爷子了,他知道准把我打死!\n");
command("cry "+ob->query("id")+"\n");
ob->delete_temp("marks/jiaohua-ji",1);
ob->set_temp("marks/lost-ji",1);
return 1;
} else {
command("dunno");
return 1;
}
}
 

