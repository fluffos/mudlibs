//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name(HIW"左三"NOR, ({ "zuo san", "zuo", "san"}));
        set("title", HIR"云中鹤"NOR);
        set("gender", "男性" );
        set("age", 32);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set_temp("no_kill",1);
        set("dex", 30);
        set("per", 30);
        set("long", 
HIB"武林中传说中的大恶人，他以降伏不愿为恶的人为乐!.\n"NOR);
        set("combat_exp", 2000000);
        set("shen_type", -1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("necromancy", 100);
        set_skill("force", 200);
        set_skill("longxiang", 300);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 300);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 300);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 250);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 200);
        set_skill("riyue-lun", 300);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 250);
	set("chat_chance_combat", 60);  
        set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("雪山寺", 3, "护教弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;


        if (who->query("shen") > 10000)
        {
                  tell_object(who,"你不配为我做事!\n");
                   return 0;
        }

        if (who->query_condition("jianghu_busy"))
        {
                  tell_object(who,"你休息一会!等会再来吧!\n");
                   return 0;
        }
        
        if (ob->query("money_id"))
        {
                  tell_object(who,"我钱有的是!\n");
                   return 0;
        }
        if (ob->query("id")=="renwu shi")
        {
                  tell_object(who,"此人是中立人士!\n");
                   return 0;
        }

        if (ob->query_temp("no_kill"))
        {
                  tell_object(who,"此人是中立人士!\n");
                   return 0;
        }

        if( userp(ob) )
        {
             tell_object(who,"俺不要这个这伙，送给你吧!\n");
             return 0;
        }

	if( !ob->is_character() ) {
        tell_object(who,"你不要和俺开玩笑！\n");
        return 0;
        }

	if( ob->query_temp("hunby") != who->query("id"))
	{
        tell_object(who,"此人好像不是你这个家伙降伏的！\n");
        return 0;
        }

	if (ob->query("id") == "corpse")
	{
        tell_object(who,"你给俺一个死人干什么?\n");
        return 0;
        }

	if (ob->query("id") == "skeleton")
	{
        tell_object(who,"你给俺一个死人干什么?\n");
        return 0;
        }

	if (ob->query("shen") < 0)
	{
        tell_object(who,"这分明是我们的同道中人!!\n");
        return 0;
        }

	if (ob->query("combat_exp") <= who->query("combat_exp")+100)
	{
        tell_object(who,"这个家伙，对你来说太方便了吧!!\n");
        return 0;
        }

             tell_object(who,"做的好，接下来就看俺如何对付这帮自命正派的家伙了！\n");
             exp = 150 + random(200);
             pot = 100 + random(100);
             score = 10 + random(5);
if ( who->query("combat_exp") > 1500000 )
{
             exp = exp/2;
             pot = pot/2;
             score = score/2;

}             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->apply_condition("jianghu_busy",3);
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->add("shen", -50);
             who->set("score", bonus);
             tell_object(who,HIC"恭喜你又降伏了一个敌人！\n"NOR);
             tell_object(who,HIG"你被奖励了：" + chinese_number(exp)
               + "点实战修为，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
	if( ob->is_character() ) {
       call_out("destroying", 5,ob);                              
}
        return 1;
}

void destroying(object ob)
{   
   destruct(ob);
}