// zhangfang.c

#include <ansi.h>

inherit NPC;
int  chu_hai();
string do_answer();
void create()
{
	set_name("账房老夫子", ({ "lao zhangfang","zhangfang","lao" }));
	set("gender", "男性");
	set("age", 56);
	set("long",
	"这是一个见钱眼开的老账房。饱经风霜的脸上透出一丝狡猾。\n", );

	set("combat_exp", 10000);
	set("shen_type", 1);

	 set("eff_qi",2000);
	 set("qi",2000);
	set("max_neili", 1000);
	set("neili", 1000);
	set("jiali", 100);

	set_skill("force", 200);
	set_skill("unarmed", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set("inquiry", ([
	    "〖学武〗"  : "先交五两银子！\n",
	    "〖指南〗" : (: do_answer :),
		  ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 80000)
    {
	message_vision("老账房望着$N说：你的武功应该历练江湖才能再长进，不能埋没在这里了。\n", who);
	return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
	who->set_temp("marks/jinniu_paied",1);
	message_vision("老账房对$N说：好！既然这位" + RANK_D->query_respect(who) 
	  + "如此上进，那就进去找师傅学吧！\n" , who);
       	return 1;
    }
    else  
	message_vision("老账房皱眉对$N说：您给的也太少了点儿吧？\n", who);
	return 0;
}
string do_answer()
{
  string str="";    
write(HIY"「扬州武馆」"NOR"所传授基本武功\n");
 printf(HIC"≡"HIY"─────────────────────────────"HIC"≡"NOR"\n");
str+="  １）基本轻功 (dodge)	    ８）  基本拳法 (cuff) \n";
str+="  ２）基本内功 (force)	    ９）  基本刀法 (blade) \n";
str+="  ３）基本招架 (parry)	    １０）基本棒法 (stick) \n";
str+="  ４）基本爪法 (claw)	     １１）基本棍法 (club) \n";
str+="  ５）基本手法 (hand)	     １２）基本杖法 (staff) \n";
str+="  ６）基本掌法 (strike)	   １３）基本剑法 (sword) \n";
str+="  ７）基本指法 (finger)	   １４）基本暗器 (throwing) \n";
    write(str);
    write(HIG"\n  学习命令是: xue 师傅名 武功技能   <需要钱钱,至少5两> "NOR"\n");
 printf(HIC"≡"HIY"─────────────────────────────"HIC"≡"NOR"\n");

     return "你想要学些什么呢？";
}