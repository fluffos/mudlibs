inherit NPC;
#include <ansi.h>

void create()
{
	set_name("点苍渔隐", ({ "diancang yuyin", "yu" }));
	set("title",  "大理国水军都督" );
	set("long", 
"他就是大理国的原水军都督，一灯大师的四大弟子之一。
他约莫四十来岁年纪，一张黑漆漆的锅底脸，虬髯满腮，
根根如铁。\n");
              set("nickname", HIY "渔樵耕读" NOR );   
        set("gender", "男性");
        set("age", 55);
          set("long", 
        "他就是当年大理国的御林军统领。一灯大师门下，就是渔樵耕读中的那位渔，
虬髯根根似铁，双眼一动不动盯着水面。\n");


        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 11000);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 100000);

        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("cuff", 180);
        set("inquiry", ([
                "一灯大师"   : "师父他老人家在上面。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
        ]) );
       map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("cuff",  "jinyu-quan");  
        map_skill("parry", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	   switch(random(3))
	   {
		case 0:command("say 我丢了师叔的娃娃鱼，怎么办。");break;
	  	case 1:command("say 娃娃鱼跑到瀑布里去了怎么办。");break;
	   	case 2:command("say 娃娃鱼，娃娃鱼快出来吧。");break;
	   }
     
	
	return;
}

  int accept_object(object who, object ob)
{
   if (ob->query("id")=="jin wawa")
   {
      who->set_temp("give_wawa",1);
      command("say 多谢了！");
      return 1;
   }
else
	message_vision("渔人皱眉对$N说：你能帮我捉到娃娃鱼吗。\n", who);
        return 0;
}      
