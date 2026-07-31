// huang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "huangjobhy.c"
int ask_wldh();
void create()
{
    set_name("黄蓉", ({"huang rong", "huang", "rong"}));
    set("gender", "女性");
    set("age", 36);
    set("long", "她是北侠郭靖的夫人，东邪黄药师的爱女，前任丐帮帮主。\n");

    set("attitude", "peaceful");
    set_max_encumbrance(200000000);   
    set("per", 30);
    set("str", 300);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 8000);
    set("max_qi", 8000);
    set("jing", 8000);
    set("max_jing", 8000);
    set("neili", 20000);
    set("max_neili", 20000);
    set("jiali", 0);
       
    set("combat_exp", 5000000);
    set("score", 0);
       
    set_skill("force", 320);
    set_skill("bibo-shengong", 320);
    set_skill("unarmed", 320);
    set_skill("luoying-zhang", 320);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 320);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying-shenjian", 320);
    set_skill("qimen-wuxing", 320);
    set("inquiry", ([
		 "job"   : (: ask_job :),
         "功劳"  : (: ask_gonglao :),
         "完成"   : (: ask_jobover :),
         "over"   : (: ask_jobover :),
         "fangqi": (: ask_fangqi :),
         "放弃"  : (: ask_fangqi :),
         "武林大会" : (: ask_wldh() :),
		 ]));      
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("桃花岛", 2, "弟子");
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

int ask_wldh()
{

        object me = this_player();
        object ob,where,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
	
        int i, skill = 0;
	
        ob=this_object();
        who=me;
        where = environment(who);
        if(((int)me->query("jinyong/book10")!=2))
           {
                      message_vision("$N对着$n说道。最近没有招开武林大会。\n", this_object(), me);
	                      return 1;
            }


        if(where->query("short")!="郭府后花园")
           {
                      message_vision("$N对着$n说道。这里无法招开武林大会。\n", this_object(), me);
	                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高经验再来吧");
                return 1;
}
 
 
         fang = present("jinlun fawang",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你先对付敌人吧");
                return 1;
	}

         fang = present("daerba huofo",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你先对付敌人吧");
                return 1;
	}

         fang = present("huo du",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "你先对付敌人吧");
                return 1;
	}

        if (ob->query_temp("wldh") && !me->query_temp("book1033") && !me->query_temp("book1032") && !me->query_temp("book1031")) {
                command("kick " + me->query("id"));
                command("say 武林大会才开过啊。");
                return 1;
                }
if (!ob->query_temp("wldh")) {
                ob->set_temp("wldh",1);
fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(who));	
fang = load_object("/kungfu/class/xueshan/daerba");
	fang->move(environment(who));	
fang = load_object("/kungfu/class/xueshan/fawang");
	fang->move(environment(who));			

                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "武林大会，马上就要开了，可是来了一些蒙古走狗，你能帮我打发他们吗?");
	tell_object (me,"霍都,达而巴,金轮法王杀了进来！！\n");

return 1;
}

        if (!me->query_temp("book1033")) {
                command("kick " + me->query("id"));
                command("say 你打赢金轮法王了吗？");
                return 1;
                }
	
        if (!me->query_temp("book1032")) {
                command("kick " + me->query("id"));
                command("say 你打赢达而巴了吗？");
                return 1;
                }
                
        if (!me->query_temp("book1031")) {
                command("kick " + me->query("id"));
                command("say 你打赢霍都了吗？");
                return 1;
                }



  	if(((int)me->query("jinyong/book10")==2))
	{
		
 	i = 1200+random(2900);
	me->set("jinyong/book10",3);
	me->add("combat_exp",i+12880);
	me->add("potential",i*18);
	me->add("mpgx",10);
	me->add("expmax",3);

	tell_object (me,"你赢得了"+chinese_number(i+12880)+"点经验"+
	           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		
         }
                command("thank " + me->query("id"));
                command("say " + me->query("id") + "这次武林大会办完后，一定要打败蒙古人！" NOR);
                command("say " + me->query("id") + "听说法王一伙人到绝情谷去了！" NOR);

                return 1;
                             
}