
//这是五指山中妓女的设定。玩家可以搭救之。如果成功，则掉落宝石，如果失败，则妓女变土匪杀之。
#include <ansi.h>


inherit NPC;

#include "../npc_setup.h"

int ask_me();
int give_gem(object me);

void create()
{
	set_name("土匪窝妓女", ({ "ji nv","girl" }) );
	set("gender", "女性" );
	set("age", 29);
	set("long",
		"她从小被卖到五指山，每天只能强颜欢笑，任人凌辱。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);

	set("shen_type",1);set("score",200);setup();

    carry_object("/d/city/obj/flower_shoe")->wear();
    carry_object("/d/city/obj/pink_cloth")->wear();

    set("inquiry", ([
                "搭救"   : (:ask_me:),
        ]) );
}

int ask_me()
{
	object tufei;
    object me;
	string npc_type = "xingxiu";
	int tufeilevel = 9;

    me=this_player();   
	if( me->query("jiaofei/xinren")>0)
	{
		command("say 官人乃山中头领,别来消遣小女子了");
		return 1;
	}


	if(JIAOFEI_D->istaskstart() != 1)
	{
		command("say 这里戒备好严，英雄小心糟了害。小女子听说朝廷即将剿灭这些天杀的土匪，英雄不如趁那时来救我。");
		return 1;
	}

	if((random(2)==1))
	{
		command("bow " + me->query("id"));
        command("say 英雄大恩大德，小女子永世不忘。此宝石乃小女祖传之物，还请笑纳。");
        write("妓女急急忙忙的离开了。\n"); 
	    remove_call_out("destroy");
        call_out("destroy",1,this_object());
		give_gem(me);
        return 1;
	}
	else
	{
        command("hehe " + me->query("id"));
        command("say 英雄大恩大德，小女子永世不忘。");
        write(HIR"言罢，盈盈下拜，你赶忙抢前一步将其扶起，却不料她肩头突然一缩，几支小箭破空而来。\n");
        if(random(20)<15)
		{
			write("你措手不及，被扎成了刺猬。\n");
			me->set("eff_qi",me->query("eff_qi")/2);
        }
		else
		{
			write(HIY"你急忙来了个懒驴打滚，将小箭堪堪避过，却也是闹了个灰头土脸，好不丢人。\n");
        } 
        write(HIW"妓女说到：哼，居然敢打山上女人的主意，纳命来吧！！\n");
        write(HIW"说罢，撕下伪装扑了上来，你定睛一看，却原来是土匪假扮的。\n");

        tufei=new(__DIR__"tufei");

		tufei->set("level",tufeilevel);
		tufei->set("name",npc_colors[tufeilevel-1]+"土匪"+NOR);
		tufei->set("combat_exp",1000000*tufeilevel+1000000);
		
		if(undefinedp(npc_family_setup[npc_type])) 
		{
			npc_type = "xingxiu";
		}

		evaluate(npc_family_setup[npc_type],tufei,50*tufeilevel+100,1);

		tufei->set("str", 50);
		tufei->set("int", 10);
		tufei->set("con", 50);
		tufei->set("dex", 25);    
		tufei->set("neili", 5000+300*tufeilevel);
		tufei->set("max_neili", 5000+300*tufeilevel);
		tufei->set("jingli", 5000+300*tufeilevel);
		tufei->set("max_jingli", 5000+300*tufeilevel);
		tufei->set("jiali", (5000+300*tufeilevel)/10);		
		tufei->set("max_qi",3000+300*tufeilevel);
		tufei->set("eff_qi",3000+300*tufeilevel);
		tufei->set("qi",3000+300*tufeilevel);    
		
		tufei->wield_weapon();

		tufei->set("chat_chance_combat", tufeilevel*10);

	    tufei->move(environment(this_object()));

        tufei->kill_ob(this_player());
	    remove_call_out("destroy");
        call_out("destroy",1,this_object());
		return 1;
		
    }
}

int give_gem(object me)
{
	int level = 3;
	int rnd = random(1000);
	object obj;
	int i;
	string gemtype;

	if(rnd < 500)
	{
		level = 3;
	}
	else if(rnd < 800)
	{
		level = 4;
	}
	else if(rnd < 900)
	{
		level = 5;
	}
	else if(rnd < 980)
	{
		level = 6;
	}
	else if(rnd < 998)
	{
		level = 7;
	}
	obj = new("/obj/gem/gem");
	//种类不太重要，直接设定
	i = random(19);
	if (i < 3) gemtype = "ruby";
	else if (i < 6) gemtype = "topaz";
	else if (i < 9) gemtype = "sapphire";
	else if (i < 12) gemtype = "emerald";
	else if (i < 15) gemtype = "amethyst";
	else if (i < 18) gemtype = "diamond";
	else gemtype = "skull";//skull的出现几率为其余宝石的1/3
						   
	switch(level)
	{
		case 3:
			obj->set_level(9445,9445,gemtype);
			break;
		case 4:
			obj->set_level(9815,9815,gemtype);
			break;
		case 5:
			obj->set_level(9940,9940,gemtype);
			break;
		case 6:
			obj->set_level(9980,9980,gemtype);
			break;                            
		case 7:
			obj->set_level(9995,9995,gemtype);
			break;                        
		default:
			break;                                                                                
	}
	obj->move(me);	
	tell_object(me,"你得到了一颗"+obj->query("name")+"\n");
	return 1;
}
void destroy(object me)
{
	destruct(me);
	return;
}

