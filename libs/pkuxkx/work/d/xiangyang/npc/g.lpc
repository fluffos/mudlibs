#include <ansi.h>
inherit NPC;
string ask_for_baoguo();
//string ask_for_toujun();

void create()  
{	set_name(RED "郭靖" NOR, ({ "guojing","jing","guo" }));
	set("nickname", GRN "一代大侠" NOR);
        set("title",YEL"洪七公亲传弟子"NOR+ MAG"威震中原"NOR);
        set("gender", "男性");
	set("age", 40);
	set("str", 30);
	set("dex", 26);
	set("long", "这就是一代大侠郭靖。\n");
	set("combat_exp", 1800000);
	set("shen_type", 100000);
	set("attitude", "peaceful");

	set_skill("strike", 200);
	set_skill("force", 200);
	set_skill("xianglong-zhang", 220);
         set_skill("xiaoyaoyou", 180);        // 逍遥游
	 set_skill("huntian-qigong", 180);    // 混天气功

        set_skill("dodge", 150);
	set_skill("parry", 200);                

	map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");

        set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 300);

	set("neili", 4000); 
	set("max_neili", 4000);
	set("jingli", 4000); 
	set("max_jingli", 4000);
	set("jiali", 500);
        
        set("inquiry",([ 

                "报国"  : (: ask_for_baoguo :),
        ]));


	set("chat_chance",100);
        set("chat_msg", ({
       "恩师云游四方，多年不见，也不知他老人家现在.\n绾?,
       "郭靖说着深深的叹了一口气.\n",
       "蒙古大军虽然撤兵，但总有一天要卷土重来，亡国之日不远矣.\n"
       "该想个釜底抽薪的办法才好.\n"
        }) );

        setup();
	carry_object(__DIR__"obj/tiejia")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

string ask_for_baoguo()
{
        object me,ob;
        me = this_player();
        if (!present("yao pai",this_player()))
           return "虽说国家兴亡匹夫有责，但寻常百姓还是好自为之，不要枉送性命.\n";
        if(!me->query_temp("shoujiang_asked"))
	{
	command("haha");
           command("wa");
           command("kill " + me->query("id"));
           return "你这腰牌是从那里来的?\n"; 
	}
        ob = new(__DIR__"obj/junling");
	ob->move(this_player());              
           command("say 蒙古骑兵锐不可当，要击败他们，必须釜底抽薪，擒贼先擒王.\n");
           command("say 我派你混入敌营，伺机刺杀蒙古皇帝.\n");
         message_vision("郭靖给了$N一大令。\n", me);
        me->set_temp("guojing", 1);  
        me->delete_temp("shoujiang_asked"); 
         return "国家兴亡，黎民生死，全仗英雄一人了！\n";
}

int accept_object(object me, object ob)
{
        object book;
        if (ob->query("id")=="bingfu")
     {
        if (!me->query_temp("刺客") ) {
               command("say 大胆狂徒，竟敢欺瞒本帅，这兵符是从那里仿造的？.");
               command("kill " + me->query("id"));
                return 1;
        }
        else {
                command("admire " + me->query("id"));
               me->delete_temp("刺客"); 
               me->delete_temp("杀"); 
                command("say 为国家为黎民出生入死，本帅不管送什么都无法表达我对" + RANK_D->query_respect(ob) + "的敬意,\n这本书记载了我一生的造诣，也许英雄有点用处，请收下\n");
                 book = new(__DIR__"obj/shediao");
	book->move(this_player());
         message_vision("女佣给了$N一本" + YEL"射雕英雄传"NOR + "。\n", me);

                return 1;
        }
    }     

}

