// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit BHNPC;
inherit F_MASTER;

void create()
{
    set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");
      set("jh_dj/dj",20);
	set("age", 63);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
    set("no_suck",1);

	set("max_qi", 35000000);
	set("max_jing", 15000000);
    set("max_jingli", 15000000);
    set("jingli", 15000000);
	set("neili", 30000000);
	set("max_neili", 30000000);
	set("jiali", 150);

	set("combat_exp", 1900000000);
	set("score", 800000);

    	set_skill("force", 3600);
	set_skill("dodge", 2400);
	set_skill("parry", 2400);
	set_skill("unarmed", 3000);
	set_skill("hunyuan-yiqi", 2600);
	set_skill("shaolin-shenfa", 3400);
    	set_skill("qishang-quan", 3000);
    	set_skill("jingang-quan", 3500);
    	set_skill("literate", 1100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "qishang-quan");
    	map_skill("parry", "jingang-quan");

	prepare_skill("unarmed","qishang-quan");
	
	set_temp("apply/defense1", random(3000)+20);
   set_temp("apply/attack1",  random(3000)+20);//闪避
   set_temp("apply/damage",random(3000)+10);
   set_temp("apply/armor", random(3000)+10);
   set("chat_chance_combat", random(3000)+10);

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		 (: exert_function, "recover" :), 
		(: command("perform hunpofeiyang") :),
		 
	}) );

	setup();
     carry_object("/d/xiaoyao/obj/blade")->wield();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void die()
{
        object obj;
        object me = this_player();
        object killer;
       if(objectp(killer=this_object()->query_temp("last_damage_from") ))
   {          //以下是爆各类物品和几率设置
if (random(100) < 30)
    {
       obj = new("/obj/weapon/tulongdao");//屠龙刀
       obj->move(environment(this_player()));
    }
//if(!killer->query_temp("m_success/守卫者"))
                 // { 
        
               // killer->set_temp("m_success/守卫者",1);
            // message("channel:chat", HBMAG"【挑战BOSS】"+killer->query("name")+"成功地战胜了[桃花岛]的BOSS-守卫者，为泥谭增添了一份功绩!\n"NOR,users());
               //}
     // tell_object(killer,HIR "\n【系统提示】：恭喜你战胜了BOSS！！！\n"NOR);
  //tell_object(killer, HIR "\n\n突然时空逆转，一个飘渺地声音在空间回荡：我连你们这些菜鸟都打不过，可恨！我会回来报仇的！！\n"NOR); 
   }
  message_vision("$N：我义子会替我报仇的！\n", this_object());
      destruct(this_object());
      //  ::die();
} 


/*
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}*/

