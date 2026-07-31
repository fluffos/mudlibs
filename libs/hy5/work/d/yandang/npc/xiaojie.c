#include <ansi.h>
inherit NPC;
int have_yuzhuo=1;

void create()
{
	set_name("碧涟", ({ "bilian","girl", "xiaojie" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","小姐");
 set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
  set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("atman", 1000);
        set("max_atman", 5000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 350);




set_skill("flying-dragon",280);

set_skill("touch",280);
set_skill("softsword",280);



set_skill("qiusheng-blade",280);
set_skill("siqi-sword",280);
set_skill("qingpingsword",280);
set_skill("sharen-sword",280);
set_skill("lefthand-sword",280);
set_skill("longfenghuan",280);
set_skill("feidao",280);
set_skill("feixian-sword",280);


set_skill("ziwu-daxuefa",280);
set_skill("bluesea-force",280);
set_skill("demon-strike",280);
set_skill("nine-moon-claw",280);

set_skill("doomstrike",280);
set_skill("luoriquan",280);
set_skill("qinnashou",280);


        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",280);
        set_skill("demon-blade",280);
        set_skill("literate",280);
        set_skill("unarmed",280);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",280);
	set_skill("blade",280);
	set_skill("changquan",280);
        //set_skill("doomsword",280);
        //set_skill("chilian-shenzhang",280);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",280);
        set_skill("luohua-jian",280);
        set_skill("sword",280);
        set_skill("dagger",280);
        set_skill("feixian-sword",280);
        set_skill("bat-blade",280);
        set_skill("fengyu-piaoxiang",390);

        map_skill("strike","bluesea-force");
        map_skill("finger","bluesea-force");
        
        prepare_skill("strike", "bluesea-force");
        prepare_skill("finger", "bluesea-force");
        map_skill("dagger","ziwu-daxuefa");
        map_skill("force","bluesea-force");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","ziwu-daxuefa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "rorar" :),
                (: perform_action, "strike.bo" :),
                (: perform_action, "strike.hai" :),
                (: perform_action, "strike.jue" :),
                (: perform_action, "strike.nan" :),
                (: perform_action, "strike.xuan" :),
                (: perform_action, "dagger.dian" :),
                (: perform_action, "dagger.ding" :),
                (: perform_action, "dagger.feng" :),	
                (: perform_action, "dagger.jing" :),	
                (: perform_action, "dagger.kuangcao" :),	                	
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );


    set("chat_chance", 7);
	set("chat_msg", ({
		"唉,衣带渐宽众不悔,为伊销得人憔悴!\n",
		"碧涟抬头看着窗外,一动不动,似乎在想着什么.\n",
	}));
	set("inquiry", ([
		"玉簪" : "嗯,昨天不知道掉哪儿了？",
		"鱼肠剑" : "嘻嘻,这几天问这问题的人真多!",
		]) );	
	setup();
add_money("gold",1);
	carry_object("/clone/weapon/dagger")->wield();
carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who,object item)
{	
	if(item->query("id")=="biyuzan")
	{if (have_yuzhuo==1)
	   {  command("say 啊,是我的玉簪.....真谢谢你,这件小东西送给你。\n");
message_vision("小姐给$N一只"+HIC+"翠玉镯.\n"NOR,who);
clone_object(__DIR__"obj/cuiyuzhu.c")->move(who);
have_yuzhuo=0;		
return 1; }
       else command("say 唉,你来晚了,东西已经给别人拿走了!\n");
       return 0;
	}
	command("say 这又不是我的东西,给我干什么。\n");
	return 0;
}
