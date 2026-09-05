// wen.c 文泰来 by hubo

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("文泰来", ({ "wen tailai", "wen","tailai" }));
	set("title", HIR "红花会"HIG"四当家" NOR);
	set("nickname", HIW "奔雷手" NOR);
	set("long", "文泰来号称“奔雷手”，十五岁起浪荡江湖，手掌下不知击毙
过多少神奸巨憝、凶徒恶霸。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 10000000);

	set_skill("literate", 300);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("bingchuan-xinfa", 400);
	set_skill("zhuangzi-mengwu", 400);
	set_skill("baihua-cuoquan", 400);

	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "baihua-cuoquan");
	
	prepare_skill("cuff","baihua-cuoquan");
	set("env/wimpy", 20);
	create_family("红花会", 3, "弟子");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
              add_action("do_jiuren", "jiuren");
        if (interactive(this_player()) && !this_player()->is_fighting()) 
        {
            remove_call_out("greet");
            call_out("greet", 1, this_player());
        }

}

int do_jiuren()
{
        object me = this_player();
        
        if (me->query_temp("hhh_wt1") != 6)
        	return  notify_fail(HIM"文泰来疑惑的看看你说：不是总舵主派来的我是不会跟他走的。\n"NOR);
        
        if (me->query_temp("hhh_wt1") == 6)
        	write(HIW"你对文泰来说：文四当家的，总舵主派我来救你，快跟我走吧！\n"NOR);
        	write(HIW"文泰来抱拳说道：感谢大侠相救，咱们这就走。\n"NOR);

        	me->set_temp("hhh_wt1",7);
        	command("follow " + me->query("id"));
        	        	
          return 1;
      	
}

void greet(object me)
{
    object ob=this_object(),he,room;
    me = this_player();
    if ((me->query_temp("hhh_wt1")== 7) && (present("wang xinglong", environment(me)))
    	   && (file_name(environment()) == "/d/hangzhou/paozhang"))
    {
        command("follow none");
        message_vision("王兴隆看到文泰来激动的说：大侠终于把文四当家的救出来了，太好了！\n",me);
        me->set("hhh_wtl",1);
        me->delete_temp("hhh_wt1");
        
        if ((string)me->query("family/family_name") == "红花会")
        {
            message_vision("文泰来对你一抱拳说道：感谢大侠出手相救。无以回报，赠送你几手工夫吧！\n",me);
            me->set_skill("benlei-tiezhang",50);
            me->add("combat_exp",500000);
            me->add("score",500);
            me->add("repute",100000);
            write(HIC"\n你的「奔雷铁掌」进步了！\n"NOR);
            write(HIC"\n你的经验增加了！\n"NOR);
            write(HIC"\n你的声望增加了！\n"NOR);
            write(HIC"\n你的门忠增加了！\n"NOR);
           message( "channel:" + "chat",HIW + "【江湖谣传】"+HIY"据说" + me->query("name") +HIY "杀进提督府把文泰来营救出来了！\n"NOR,users());

            room = load_object("/d/hangzhou/td_dilao3");
            ob->move(room);

            return;
        }
        if ((string)me->query("family/family_name") != "红花会")
        {
            message_vision("文泰来对你一抱拳说道：感谢大侠出手相救。以后江湖上没人敢小看您！\n",me);
            me->add("combat_exp",500000);
            me->add("repute",100000);
            write(HIC"\n你的经验增加了！\n"NOR);
            write(HIC"\n你的声望增加了！\n"NOR);
          message( "channel:" + "chat",HIW + "【江湖谣传】"+HIY"据说" + me->query("name") +HIY "杀进提督府把文泰来营救出来了！\n"NOR,users());
            
            room = load_object("/d/hangzhou/td_dilao3");
            ob->move(room);

            return;
        }
        return;
    }
    return;
}

