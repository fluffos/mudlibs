// fengmof.c     
//write by lysh
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
inherit F_MASTER;
void create()
{
	set_name("冯铁匠", ({ "feng tiejiang", "feng", "smith" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", 
"冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，\n"
"左腿残废，肩窝下撑著一根拐杖。\n");
      
	set("title", RED "桃花岛" NOR + GRN +"弟子" NOR);
        set("gender", "男性");
	set("class","平民");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 24);
        set("dex", 28);
	set("per", 20);

        set("max_qi", 300);
        set("max_jing", 260);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 20);
	set("combat_exp", 20000);
        set("score", 1000);

        set("chat_chance_combat", 80);

	set_skill("literate", 50);
	set_skill("qimen-bagua", 50);
        set_skill("force", 50);
	set_skill("taohua-force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("yuxiao-jian", 50);
	
	set_skill("baguabu", 50);
        set_skill("hand", 50);
        set_skill("lanhua-shou", 50);
        set_skill("strike", 50);
        set_skill("luoying-zhang", 50);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	
        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("桃花岛", 2, "弟子");

	set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);

//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "小人姓冯，村里人都叫我冯铁匠。",
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 抱歉，锄头已经卖光了...",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"剑"  : 
"哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。\n"
"嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。",
		"取剑": "小人一定要见了岳掌门的手信才能给剑。",
		"冯默风" : "唉～，这个名字小人已经好久没有听到过了...",
		"奇门遁甲" : "那都是小时候学的，平时没事解解闷罢了。",
	]) );
	setup();
        carry_object("/d/city/obj/gangjian")->wield();
         set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
        add_money("coin", 50);
}             
void init()
{               
        
         ::init(); 
         add_action("do_buy", "buy");

}

int accept_object(object who, object ob)
{
	object sword;
	object me=this_player();
	object obj=ob;
	sword = new(__DIR__"obj/youlong");
        if (!userp(ob) && (string)ob->query("id")=="letter") {
              if(!query("yl_trigger")) {
		say(
"冯铁匠说道：这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。\n"
"冯铁匠把" + sword->query("name") + "交给了" + who->query("name") + "。\n");
		sword->move(who);
                set("yl_trigger", 1);
              }
           else say("冯铁匠眼也不抬，说道：要剑自己进去拿。\n");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
	return 1;
	}
	return 0;
}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }

void attempt_apprentice(object ob)
{        
        if ( (int)this_player()->query("combat_exp")>100) 
         {   command("say 我派只收无家可归的孤儿。");
            return;
          }
        if ( this_player()->query("class")=="bonze")
        {
                command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
                return;
        }
        if ( this_player()->query("class")=="eunach")
        {
                command("say 我派不收太监，" + RANK_D->query_respect(ob) + "请回吧。");
                return;
        }

	if ((string)ob->query("class") == "taoist")
	{
		command("say 我派不收道士，"+ RANK_D->query_respect(ob) + "请回吧。");
	        return;
	}
        command("say 好吧，我就禀告恩师黄药师收下你了。");
        command("recruit " + ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        
        if (ob->query("age")<20)
        {
        	if((string)ob->query("gender")!="女性")
		{
                	ob->set("title",RED "桃花岛" NOR + GRN +"小童" NOR);
			return;
		}
        	else
		{
                	ob->set("title",RED "桃花岛" NOR + GRN +"女童" NOR);
			return;
		}
        }
        else 
	{
        	if((string)ob->query("gender")!="女性")
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"岛外弟子" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"岛外女弟子" NOR);
			return;
		}
        }
}
void re_rank(object student)
{
        if (student->query("age")<20)
        {
        	if((string)student->query("gender")!="女性")
		{
                	student->set("title",RED "桃花岛" NOR + GRN +"小童" NOR);
			return;
		}
        	else
		{
                	student->set("title",RED "桃花岛" NOR + GRN +"女童" NOR);
			return;
		}
        }
        else 
	{
        	if((string)student->query("gender")!="女性")
                {
			student->set("title",RED "桃花岛" NOR + GRN +"岛外弟子" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "桃花岛" NOR + GRN +"岛外女弟子" NOR);
			return;
		}
        }
}
