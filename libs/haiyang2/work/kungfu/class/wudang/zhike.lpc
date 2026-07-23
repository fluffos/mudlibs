// zhike.c 知客

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("知客道长", ({ "zhike daozhang", "lingxu daozhang", "lingxu", "zhike" }));
        set("long",
                "他道号灵虚，是武当山的知客道长。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);
set("wdnpc",1);
        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("qi", 30000);
        set("jing", 30000);
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 13000);
        set("max_neili", 13000);

        set("combat_exp", 1800000);
        set("score", 1000);

      set_skill("force", 160);
        set_skill("dodge", 140);
        set_skill("unarmed", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("wudang-jian", 220);
        set_skill("taoism", 220);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 180);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 200);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 200);
	set_skill("wudang-array", 100);
	set_skill("array",100);
	set_skill("taoism", 100);
	set_skill("literate", 100);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 105);
	set_temp("apply/damage", 5);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
        }) );
        create_family("武当派", 3, "弟子");
        set("chat_chance",2);
        set("chat_msg", ({
            "知客道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
            "知客道长说道：玄岳门乃武当出入门户，我等一定要精心守卫(volunteer)，不可丝毫懈殆。\n"
            "知客道长说道：如果值班时间，到了请告诉我(finish)，不可丝毫懈殆。\n"
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_volunteer","volunteer");
        add_action("do_finish","finish");
}

void greeting(object ob)
{
        mapping myfam;
 
        myfam = (mapping)ob->query("family");
        if(!myfam || myfam["family_name"] != "武当派")
              say ("知客道长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，欢迎到武当来，进来喝杯茶，歇歇腿吧。\n");
        else
              say ("知客道长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，一路辛苦了。\n");
        return;

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}

int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

        if(me->query_condition("wudangjob"))
           return notify_fail("知客道长对你说：你先休息一会再来。\n");
        if(me->query_condition("guojob2_busy"))
           return notify_fail("知客道长对你说：你先休息一会再来。\n");

        if (this_object()->is_busy())
                return notify_fail("知客道长对你说：我正在布置守山门的事，你等一会。\n");

        if (me->query_temp("in_guard")) 
           return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");

        if( me->query("family/family_name") != "武当派")
           {
             if ( me->query("guarded") > 10) 
             {
            message_vision("知客道长大喝一声：作为别派的弟子，你已经为我派做了太多事了！\n", me);
                      return 1;
            }
           }
        if( me->query("family/family_name") == "武当派")
           {
             if ( me->query_skill("taiji-shengong",1) < 30) 
             {
            message_vision("知客道长大喝一声：你先去学一些本门的内功再来！\n", me);
                      return 1;
            }
           }

      if (me->query("guardwd"))
           return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");
      if (me->query_condition("wudang_guard"))
           return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");


        if (me->query_temp("in_guard")) 
           return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");

        ob = users();
        tell_room(environment(me),me->query("name")+"开始在武当山门值守。\n");
        set("qi", 30000);
        set("jing", 30000);
	me->set("guardwd", HIG"山门守卫"NOR);
        me->set_temp("in_guard","1"); 
        me->apply_condition("wudang_guard",12);
        me->start_busy(2);
this_object()->start_busy(15);
        me->save();
        return 1;
}
int do_finish()
{
 int exp,pot;
        object me=this_player();
        object* ob;
        int i;
if (me->is_busy())
           return notify_fail("知客道长对你说：你正忙着呢!\n");
        if (this_object()->is_busy())
                return notify_fail("知客道长对你说：我正在布置守山门的事，你等一会。\n");

if (me->is_fighting())
           return notify_fail("知客道长对你说：你正忙着呢!\n");
      if (!me->query("guardwd"))
           return notify_fail("知客道长对你说：你有来门值吗。\n");
if (me->query_condition("wudang_guard"))
           return notify_fail("知客道长对你说：门值守期还没有到呢!!\n");
if (!me->query_temp("in_guard"))
           return notify_fail("知客道长对你说：你有来门值吗。\n");
if (me->query_condition("wudangjob"))
           return notify_fail("知客道长对你说：你休息一会再来!!\n");

        me->delete("guardwd");
        me->delete_temp("in_guard"); 
if (environment(me)->query("short")=="玄岳门"){
pot=random(400) + 250;
exp=random(620) + 280;
             me->add("potential",pot);
             me->add("combat_exp",exp);
        me->add("guarded",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("wudangjob",7);
        tell_room(environment(me),me->query("name")+"在武当山门值守期已满。\n");
        tell_object(me,"你在武当山门值守期已满。\n");
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);

}
else {
        tell_room(environment(me),me->query("name")+"在武当山门值守走开，失败。\n");
        tell_object(me,"你在武当山门值守走开，失败。\n");
}

        set("qi", 30000);
        set("jing", 30000);
this_object()->start_busy(8);

        return 1;
}

void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_guard"); 

        ::die();
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
}