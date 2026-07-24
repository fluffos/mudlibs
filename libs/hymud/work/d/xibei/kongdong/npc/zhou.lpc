// zhou.c

inherit NPC;
#include <ansi.h>
string *pashan_msg = ({
        HIR"周真人深深吸了几口气，沿着颤颤悠悠的栈道走了过去......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,        
        HIG"眼看周真人已经到了栈道中央了......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,
        HIR"只见周真人慢慢地一步一步地往前挪......\n"NOR,         
        });



void create()
{
        set_name("周真人", ({ "zhou zhenren","zhou","zhenren" }) );
        set("title","苦修者");
        set("gender", "男性" );
        set("age",40);
        set("social_exp",2000);
        set("combat_exp",10000000);

        set("attitude", "friendly");
   set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}

void init()
{
    object ppl;

    ::init();
    if ( userp( ppl = this_player() ) 
        &&!this_object()->query_temp("have") ) 
    {
        remove_call_out( "Greeting" );
        call_out( "Greeting", 5, ppl );
       	this_object()->set_temp("have",1);
    }
    if(environment(this_object())->query("short")==WHT"玄鹤洞"NOR)
        remove_call_out( "say" );
        call_out( "say", 5, ppl );    
}

void Greeting( object ppl )
{
    command("nod "+ppl->query("id"));
    command( "climb 栈道" );     
}

void say(object ppl)
{
	
	}
/*
int refuse_killing(object me)
{
        command("nokill "+me->query("id"));
        me->unconcious();
    return 1;
}
*/

