// renying.c

inherit NPC;
string inquiry_linghuchong();

void create()
{
        set_name("任盈盈", ({ "ren yingying","ren","ying"}) );
	set("gender", "女性" );
	set("age", 20);
	set("shen_type", 1);
	set("combat_exp", 1500000);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set_skill("literate", 180);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("changquan", 160);
         set_skill("sword", 180);
          set_skill("parry", 100);
        set_skill("literate",100);
          set_skill("dodge", 100);
          set_skill("unarmed", 100);
          set_skill("whip", 150);
          set_skill("force", 100);
         set_skill("tmzhang", 180);
        set_skill("staff", 160);
         set_skill("tmjian", 180);
         set_skill("tmdao", 180);
         set_skill("pmshenfa", 180);
          set_skill("strike",200);
         set_skill("blade", 200);
         set_skill("tmdafa", 320);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "unarmed.huashen" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.tmduan" :),                
        }) );
	set("attitude", "friendly");
	set("chat_chance",60);
    	set("chat_msg",({
        "任盈盈说道：不知令狐冲他，怎样了，是否又和那小贱人在一起......\n",
        "任盈盈说道：你若能把这封信捎给他，可太谢谢你了.............\n",
        "任盈盈说道：也不知蓝凤凰见没见到他，可真急死我了.......\n",
	   }) );
         set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);      
	   create_family("日月神教",2,"弟子 圣姑");
       set("inquiry",([
	   "令狐冲" : (: inquiry_linghuchong:),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/clone/cloth/female5-cloth")->wear();
       carry_object("/d/heimuya/npc/obj/letter");
	carry_object("/clone/weapon/changjian")->wield();
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("任盈盈说道：去年上华山一去就再无音信，他不会忘记我吧......\n", me );
 if(query_temp("letter")==0)
 {  message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我已经派
蓝凤凰去寻找了，也不知道怎么样了。\n",me);
   return "";
 }
   message_vision("任盈盈又说道：这位"+ RANK_D->query_respect(me)+"，我这里有
信，你要是找到令狐冲，就把信交给他，他会明白的。\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("这封信烦你交给令狐冲。\n");
}
