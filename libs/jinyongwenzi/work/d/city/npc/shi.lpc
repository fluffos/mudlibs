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
   set("long", "史青山曾经是武当山的俗家弟子，又跟丐帮有点关联，只是不知为何吃上了朝廷饭。\n");
       set("combat_exp", 200000);
       set("shen_type", 1);
       set("attitude", "heroism");

       set_skill("unarmed", 100);
set_skill("tiyunzong",100);
set_skill("yinyun-ziqi",100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("stick", 100);
       set_skill("dagou-bang", 100);
       map_skill("parry", "dagou-bang");
       map_skill("stick", "dagou-bang");
map_skill("dodge","tiyunzong");
       set_temp("apply/attack", 70);
       set_temp("apply/defense", 70);
       set_temp("apply/armor", 70);
       set_temp("apply/damage", 70);

        set("inquiry", ([
              
                "为官" : (: ask_me :),
                "报效朝廷" : (: ask_me :),
       ]));
       
       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
       carry_object("/clone/weapon/langya-bang")->wield();
       carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
       command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
       return 0;
}

void init()
{
       object ob;
       ::init();
       if (interactive(ob = this_player()) && living(this_object()) &&
               (int)ob->query_condition("killer")) {
               remove_call_out("kill_ob");
               call_out("kill_ob", 0, ob);
       }
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
       me->set_temp("apply/short", ({HIY"朝廷官员九品快捕 "NOR+me->name()+"("+me->query("id")+")"}));
       return "我辈身逢乱世，当为国家出力，为百姓造福啊！\n"; 
       }
       if (gftimes>=100 && gftimes<200){
       command("nod " + me->query("id"));
       command("say 我已将你的功劳报给了兵部尚书，前日兵部来函提升你为捕头。");
       me->set_temp("apply/short", ({HIY"朝廷官员八品捕头 "NOR+me->name()+"("+me->query("id")+")"}));
       return "好好干，老夫是不会亏待你的！\n";
       }
       if (gftimes>=200 && gftimes<500){
       command("pat " + me->query("id"));
       command("say 这位"+RANK_D->query_respect(me)+"的功劳早以传边大街小巷，特此提升你为铁捕！");
       me->set_temp("apply/short", ({HIY"朝廷官员七品铁捕 "NOR+me->name()+"("+me->query("id")+")"}));
       return "这位"+RANK_D->query_respect(me)+"的功劳不小，老夫下次进京，一定要亲自禀告兵部尚书！\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("thumb " + me->query("id"));
       me->set_temp("apply/short", ({HIY"朝廷官员六品都司 "NOR+me->name()+"("+me->query("id")+")"}));
       return "这位"+RANK_D->query_respect(me)+"的成绩不小，但不要和江湖中人打的火热，否则休怪老夫手下无情！\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("haha " + me->query("id"));
       command("say 这位"+RANK_D->query_respect(me)+"的武功才智均为百里挑一，继续努力吧！");
       me->set_temp("apply/short", ({HIY"朝廷官员五品游击 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说最近江南常有江洋大盗出没，你去查查看！\n";
       }
       if (gftimes>=1000 && gftimes<2000){
       me->set_temp("apply/short", ({HIY"朝廷官员四品参将 "NOR+me->name()+"("+me->query("id")+")"}));
       return "老夫已包举你为参将，以后功名利禄指日可待！\n";
       }
       if (gftimes>=2000 && gftimes<2500){
       me->set_temp("apply/short", ({HIY"朝廷官员正三品副将 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       }
       if (gftimes>=2500 && gftimes<3000){
       me->set_temp("apply/short", ({HIY"朝廷大将正二品总兵 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       }
       if (gftimes>=3000 && gftimes<3500){
       me->set_temp("apply/short", ({HIY"朝廷重臣正一品提督 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       }
         if (gftimes>=3500 && gftimes<4500){
        me->set_temp("apply/short", ({HIY"朝廷重臣正一品大将军 "NOR+me->name()+"("+me->query("id")+")"}));
       return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
        }
       if (gftimes>4500){
       me->set_temp("apply/short", ({HIY"朝廷钦差大臣 "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       return "怎麽，你想把官做的比老夫还大？\n";
       }
}

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")) ){
                killer->apply_condition("killer", killer->query_condition("killer")+100);
                command("say "+killer->name()+"你竟敢谋杀朝廷命官！来人啊。。。");
                }
        ::die();
}       

