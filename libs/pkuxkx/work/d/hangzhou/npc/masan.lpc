// masan.c  by hubo

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("马三", ({ "ma san","ma"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long",
	        "他是杭州城最大绸缎庄的老板，虽然年纪不大，但做事沉稳，精明干练\n"
          "据说他是杭州红花会分舵舵主马善均的亲戚，既然与杭州最大黑社会红\n"
          "花会都有瓜葛，在杭州的地位自然不简单。\n");
     set("start_room","/d/hangzhou/chouduan");
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
  set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 500000);
        set_skill("force", 75);
        set_skill("dodge", 75);
           set_skill("strike", 75);
        set_skill("parry", 75);
        set_skill("sword", 75);
        set_skill("cuff",75);
	
  set("inquiry", ([
                "红花会" : "阁下如果还想多活两天，就不要问这些敏感话题",
                "马善均" : "那是我叔叔，退休在家呢，您想找他吗？",
                "马善均家" : "他家在杭州南边，西湖旁，倚山傍水，好楼盘呀",
        ]) );
   	
	setup();
	carry_object(__DIR__"obj/cdlf")->wear();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if (ob->query("gender")=="女性")
           {
            command("haha "+ ob->query("id"));
            command("admire "+ob->query("id"));
            command("say 这位姑娘，欢迎光临杭州最大绸缎庄！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("haha "+ ob->query("id"));
            command("nod");
            command("say 这位公公也要来购买绸缎吗，里边请！");
           } 
       else {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，欢迎光临杭州最大绸缎庄！");
             }
           
}

