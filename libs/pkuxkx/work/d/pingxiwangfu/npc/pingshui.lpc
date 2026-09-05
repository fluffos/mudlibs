//made by goodtaste
// date: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
string ask_for_gong();
  


void create()
{
	set_name("萍水逢", ({ "ping shui" , "ping" ,"shui" }));
        set("long",
	"一个打扮得花枝招展的妖媚女人,举手投足之间都有难以抗拒的媚力,她是平西王最宠爱的小妾\n"
         );
	set("gender", "女性");
set("per",30);
	set("age", 16+random(2));
	set("attitude", "peaceful");
	set("shen_type", -1);
        set("shen", -50);
        set("count", 1);
	set("combat_exp", 200);
        set_skill("parry", 10);
        set("inquiry", ([
                "射月弓" :(:ask_for_gong:),
	        
	]) );
 set("chat_chance", 15);
   set("chat_msg", ({
  (: random_move :)
}) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        
        
}

string ask_for_gong()
{
        object me;
	object ob;
           me=this_player();
ob=this_object();
if(me->query_temp("moved")) return("你这厮明知故问,存心羞辱于我,看我杀了你!\n");
 command("say 我还以为此事做的人不知鬼不觉，没想到你小子却知道了，看来你命该绝,别怪姑奶奶下手无情!\n");
    set("per",30);
        set("age", 16+random(2));
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("shen", -50);
        set("qi", 800);
       set("max_qi", 800);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("combat_exp", 300000+random(100000));
	set_skill("sword",280);
       
	set_skill("force", 150);
	set_skill("dodge", 270);
	
	set_skill("parry", 190);
        set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 80);
	if (this_object()->query("count") == 1) 
	{
        	carry_object(__DIR__"obj/sheyuegong");
        	this_object()->set("count",0);
        }
        carry_object("/clone/weapon/changjian")->wield();
ob->kill_ob(me);
me->set_temp("moved",1);
       return "去死吧!!!";
}



