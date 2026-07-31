// shi.c 史青山
#include <ansi.h> 
inherit NPC;
string ask_me();
void create()
{
	set_name("史青山", ({ "shi qingshan", "shi" }));
	set("title", "扬州守将");
	set("gender", "男性");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long", "史青山曾经是武当山的俗家弟子，不知为何吃上了朝廷饭。\n");
	set("combat_exp", 400000);
	set("shen", 4000);
	set("attitude", "heroism");

	set_skill("unarmed", 70);
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("taiji-quan", 120);
        set_skill("cuff", 120);
	set_skill("parry", 120);
	set_skill("taiji-jian", 120);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        prepare_skill("cuff", "taiji-quan");
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 20);
        set("inquiry", ([
              
                "为官" : (: ask_me :),
                "报效朝廷" : (: ask_me :),
       ]));
	set("max_qi", 1000);
	set("neili", 1200); 
	set("max_neili", 1200);
        set("jiali", 20);

	setup();
	carry_object(__DIR__"gangjian")->wield();
        carry_object(__DIR__"tiejia")->wear();
}

int accept_fight(object me)
{
	command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
	return 0;
}
string ask_me()
{        
       object ob, me;
       int gftimes;

       me = this_player();
       ob = this_player();
       gftimes = (int)ob->query("gf_job",1);
       
       if (gftimes<1)
       return "这位"+RANK_D->query_respect(me)+"还没有为朝廷出过力，何谈功名呢？！\n"; 
       if (gftimes>=1 && gftimes<50)
       return "这位"+RANK_D->query_respect(me)+"目前功劳不够，继续努力吧？！\n"; 
       if (gftimes>=50 && gftimes<100){
       command("nod ");
       command("say 我已将你的功劳报给了兵部尚书，前日兵部来函提升你为快捕。");
       me->set_temp("apply/short", ({HIY"九品快捕 "NOR+me->name()+"("+me->query("id")+")"}));
       return "我辈身逢乱世，当为国家出力，为百姓造福啊！\n"; 
       }
       if (gftimes>=100 && gftimes<200){
       command("nod " + me->query("id"));
       command("say 我已将你的功劳报给了兵部尚书，前日兵部来函提升你为捕头。");
       me->set_temp("apply/short", ({HIY"八品捕头 "NOR+me->name()+"("+me->query("id")+")"}));
       return "好好干，老夫是不会亏待你的！\n";
       }
       if (gftimes>=200 && gftimes<500){
       command("pat " + me->query("id"));
       command("say 这位"+RANK_D->query_respect(me)+"的功劳早以传边大街小巷，特此提升你为铁捕！");
       me->set_temp("apply/short", ({HIY"七品铁捕 "NOR+me->name()+"("+me->query("id")+")"}));
       return "这位"+RANK_D->query_respect(me)+"的功劳不小，老夫下次进京，一定要亲自禀告兵部尚书！\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("thumb " + me->query("id"));
       me->set_temp("apply/short", ({HIY"六品都司 "NOR+me->name()+"("+me->query("id")+")"}));
       return "这位"+RANK_D->query_respect(me)+"的成绩不小，但不要和江湖中人打的火热，否则休怪老夫手下无情！\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("haha " + me->query("id"));
       command("say 这位"+RANK_D->query_respect(me)+"的武功才智均为百里挑一，继续努力吧！");
       me->set_temp("apply/short", ({HIY"五品游击 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说最近江南常有江洋大盗出没，你去查查看！\n";
       }
       if (gftimes>=1000 && gftimes<2000){
       me->set_temp("apply/short", ({HIY"四品参将 "NOR+me->name()+"("+me->query("id")+")"}));
       return "老夫已包举你为参将，以后功名利禄指日可待！\n";
       }
       if (gftimes>=2000 && gftimes<2500){
       me->set_temp("apply/short", ({HIY"三品副将 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       }
       if (gftimes>2500){
       me->set_temp("apply/short", ({HIY"正国侯 "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       return "怎麽，你想把官做的比老夫还大？\n";
//       return "怎麽，你想把官做的比老夫还大？\n";
       }
}
void kill_ob(object me)
{
	command("say 大胆刁民，竟敢谋害朝廷命官？！。\n");
        me->apply_condition("killer", 100);
	::kill_ob(me);
}
 
