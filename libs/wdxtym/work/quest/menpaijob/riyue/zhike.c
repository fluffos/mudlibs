// zhike.c 知客

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIM"左三"NOR, ({ "riyue hufa", "hufa" }));
        set("long",
                "他是日月神教左护法。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);

        set("str", 40);
        set("int", 40);
        set("con", 45);
        set("dex", 40);

        set("eff_qi", 30000);
        set("qi", 30000);
        set("jing", 30000);                
        set("eff_jing", 30000);                
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 33000);
        set("max_neili", 33000);

        set("combat_exp", 800000);
        set("score", 1000);

        set_skill("force", 260);
        set_skill("dodge", 340);
        set_skill("unarmed", 240);
        set_skill("parry", 340);
        set_skill("sword", 240);
        set_skill("wudang-jian", 220);
        set_skill("taoism", 220);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        set_temp("apply/defense",450);
        set_temp("apply/armor", 800);

        create_family("日月神教", 3, "左护法");
        set("chat_chance",2);
        set("chat_msg", ({
            "左护法说道：最近有官兵来抓我教弟子，我等一定要精心护卫(huwei)，不可丝毫懈殆。\n"
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
        add_action("do_volunteer","huwei");
        add_action("do_finish","finish");
}

void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if(!myfam || myfam["family_name"] != "日月神教")
              say ("左护法冷冷地说：这位"+RANK_D->query_respect(ob) + "，不要再往里走了。\n");
        else
              say ("左护法冷冷地说：这位"+RANK_D->query_respect(ob) + "，教主在招集弟子，快上山吧。\n");
        return;

}


int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

        if(me->query_condition("riyuejob"))
           return notify_fail("左护法对你说：你先休息一会再来。\n");
        if(me->query_condition("guojob2_busy"))
           return notify_fail("左护法对你说：你先休息一会再来。\n");
        if (me->query_temp("in_guard")) 
           return notify_fail("左护法对你说：你专心守好平定州，别想打两份工。\n");
        if (this_object()->is_busy())
                return notify_fail("左护法对你说：我正在布置护法的事，你等一会。\n");

        if( me->query("family/family_name") != "日月神教")
           {
            message_vision("左护法大喝一声：你是哪里来的？我没见过你！\n", me);
                      return 1;
           }
        if( me->query("family/family_name") == "日月神教")
           {
             if ( me->query_skill("kuihua-xinfa",1) < 30
             ||  me->query_skill("tmdafa",1) < 30) 
             {
            message_vision("左护法大喝一声：你先去学一些本门的内功再来！\n", me);
                      return 1;
            }
           }

        if (me->query_temp("in_guard")) 
           return notify_fail("左护法对你说：你专心守好平定州，别想打两份工。\n");
      if (me->query("guardry"))
           return notify_fail("左护法对你说：你专心守好平定州，别想打两份工。\n");
      if (me->query_condition("riyue_guard"))
           return notify_fail("左护法对你说：你专心守好平定州，别想打两份工。\n");

        ob = users();
        tell_room(environment(me),me->query("name")+"开始在平定州护法值守。\n");
        set("qi", 30000);
        set("jing", 30000);
	me->set("guardry", HIG"日月护法"NOR);
        me->set_temp("in_guard",1); 
        me->apply_condition("riyue_guard",12);
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
           return notify_fail("左三对你说：你正忙着呢!\n");
if (me->is_fighting())
           return notify_fail("左三对你说：你正忙着呢!\n");
        if (this_object()->is_busy())
                return notify_fail("左护法对你说：我正在布置护法的事，你等一会。\n");

      if (!me->query("guardry"))
           return notify_fail("左三对你说：你有来护法吗。\n");
if (me->query_condition("riyue_guard"))
           return notify_fail("左三对你说：护法守期还没有到呢!!\n");
if (me->query_condition("riyuejob"))
           return notify_fail("左三对你说：你休息一会再来!!\n");

if (!me->query_temp("in_guard"))
           return notify_fail("左三对你说：你有来护法吗。\n");
        me->delete("guardry");
        me->delete_temp("in_guard"); 
if (environment(me)->query("short")=="平定州"){
pot=random(400) + 250;
exp=random(620) + 280;
             me->add("potential",pot);
             me->add("combat_exp",exp);
        me->add("guarded",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("riyuejob",9);
        tell_room(environment(me),me->query("name")+"在平定州护法守期已满。\n");
        tell_object(me,"你在平定州护法守期已满。\n");
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);

}
else {
        tell_room(environment(me),me->query("name")+"在平定州护法走开，失败。\n");
        tell_object(me,"你在平定州护法走开，失败。\n");
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
