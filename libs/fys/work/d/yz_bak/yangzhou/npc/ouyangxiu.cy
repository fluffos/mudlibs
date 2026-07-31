//Mr.music yangzhou 欧阳修

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("欧阳修", ({ "ouyangxiu", "ouyang xiu","ouyang" }) );
        set("gender", "男性" );
        set("age", 54);
        set("str", 90);
        set("cor", 90);
        set("cps", 90);
        set("int", 90);

        set("max_force", 4000);
        set("force", 3000);
        set("force_factor", 3);

        set("rank_info/respect", "大人");

        set("long","这位就是扬州知府欧扬大人\n");

        create_family("翰林学社", 1, "社长");
        set("title","扬州知府");
        set("combat_exp", 100000);
        set("score", 2000);

        set_skill("unarmed", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("sword", 90);
        set_skill("force", 90);
        set_skill("literate", 300);

        setup();
        carry_object("/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
 {
        if( ((int)ob->query_skill("literate") <60 ) 
                return;
        
        command("smile");
        command("say " + RANK_D->query_respect(ob) + 
 "才思敏捷，见解不凡，孺子可教。\n");
        command("recruit " + ob->query("id") );
 }

 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shusheng");
 }
 

void init()
{
        ::init();
        add_action("do_chat", "chat");
}


int do_chat()
{
  object ob;
   ob=this_player(1);
  
   say("知府脸色一沉，喝道：大堂之上，竟敢喧哗！\n");
   say("两边衙役冲上前来，不由分说，一阵大板打得"+ob->query("name")+
           "皮开肉绽,昏了过去。\n");
   tell_object(ob,"知府脸色一沉，喝道：大堂之上，竟敢喧哗！\n");
   tell_object(ob,"两边衙役冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n");
   ob->unconcious();
   return 1;
  }

