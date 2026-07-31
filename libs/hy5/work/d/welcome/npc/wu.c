
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_liwu();
int accept_object2();
void create()
{
        set_name("武伯", ({ "wu bo" }) );
 set("title", HIR "武术教练" NOR);
	set("gender", "男性" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "
这是古村的武术教练，你可以拜他为师（bai wo bo）学习武功。
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);
        set_skill("literate", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("claw", 150);
        set_skill("hand", 150);
        set_skill("strike", 150);
        set_skill("finger", 150);
        set_skill("feixian-sword", 250);
        set_skill("softsword", 250);
        set_skill("cuff", 150);
        set_skill("blade", 150);
        set_skill("stick", 150);
        set_skill("club", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("throwing", 150);
        set_skill("bat-blade",250);
        set_skill("changquan",250);
        set_skill("jingyiforce",250);
set("skill_public", 1);
set("pubmaster", 1);
	create_family("古村", 1, "教练");
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);



	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
 	object who;
	
	who=ob;
        who->set_temp("marks/pingan_paied",1);
        who->set_temp("nbjob5",1);
        message_vision("武伯对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return;
}



void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();
        add_action("accept_object2","bai");
        add_action("give_job", "job");
	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}

int give_job()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/liangong")>0)
    {
                tell_object(me,"快去互相对练(duilian)吧。把武功练好。\n");
                return 1;
    } 



message_vision("$N对着$n说道：你去找一个武馆教练互相对练(duilian jiao tou)一下吧。\n", this_object(), me);
        me->set_temp("obj/liangong", 8);
        //me->set_temp("obj/menpai",changxiwhere);
        return 1;   
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"拜师请使用指令 bai 师傅ID "+HIR+"bai wu bo \n"NOR);
			say( HIG"查看师傅技能请使用 skills 师傅ID "+HIR+"skills wu bo \n"NOR);


}

int accept_object2()
{
	object who;
	who=this_player();
        who->set_temp("marks/pingan_paied",1);
        message_vision("武伯对$N说：好！这位" + RANK_D->query_respect(who) 
+ "想学什么呢？\n" , who);
        return 1;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/pingan_paied")==1) return 0;
        return 1;
}


int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
   if(obj->query("id") == "meat" ) {
       command("pat " + me->query("id"));
       command("say 多谢你了，知道我就好这一口！");
       me->set_temp("nbjob10",1);
       call_out("destroying", 0, obj); 
       return 1;
       }

   else return 0;       
}
void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;

 
destruct(obj);
   return;      
}