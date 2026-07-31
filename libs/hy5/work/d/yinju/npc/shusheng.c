#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_reply1();
string ask_reply2();
string ask_reply3();

void create()
{
	set_name("朱子柳", ({ "zhu ziliu", "zhu", "ziliu" }));
	set("title",  "大理国大宰相" );
	set("long", 
"他就是大理国的原大宰相，一灯大师的四大弟子之一。
只见他四十来岁年纪，头戴逍遥巾，手挥折叠扇，颏下
一丛漆黑的长须，确是个饱学宿儒模样。\n");
        set("nickname", HIY "渔樵耕读" NOR );
        set("gender", "男性");
        set("age", 45);

       set("age", 45);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 11500);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("score", 200000);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 175);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 155);
        set_skill("duanjia-sword", 150);
        set_skill("literate", 150);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("sword", "duanjia-sword");
        map_skill("staff", "duanjia-sword");
        map_skill("parry", "duanjia-sword");
        map_skill("cuff", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);
        set("inquiry", ([
                "一灯大师"   : "师父他老人家在里面。你答对了就可以见他了。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
                "辛未状元"   : (: ask_reply1 :),
                "霜凋荷叶，独脚鬼戴逍遥巾"   : (: ask_reply2 :),
                "魑魅魍魉，四小鬼各自肚肠"   : (: ask_reply3 :),
        ]) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
 add_action("do_answer", "answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        command("say 上联是琴瑟琵琶，八大王一般头面。那下联是什么");

        //if (ob->query_temp("help_nongfu"))
           //ob->delete_temp("help_nongfu");
	return;
}
int do_answer(string arg)
{
      object me=this_player();
          if( arg=="魑魅魍魉，四小鬼各自肚肠")
        {
            me->set_temp("answer_shusheng",1);  
          command("say 好对，好对，你去罢。\n");
         }
         else 
             command("say 错了，你对错了。\n");
        return 1;
}
        
string ask_reply1()
{
	object me = this_player();
	me->set_temp("yideng_du1", 1);
	if (me->query_temp("yideng_du2") && me->query_temp("yideng_du3"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
string ask_reply2()
{
	object me = this_player();
	me->set_temp("yideng_du2", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du3"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
string ask_reply3()
{
	object me = this_player();
	me->set_temp("yideng_du3", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du2"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
