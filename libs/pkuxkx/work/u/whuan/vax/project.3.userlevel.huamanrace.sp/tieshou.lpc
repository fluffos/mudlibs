// tieshou.ce.c
inherit NPC;
#include <ansi.h>;
int do_bihua(string);
string ask_me();
int do_halt();
object board;

string s_skill;
string ask_special_skill();
void create()
{
        set_name("铁游夏", ({ "tie youxia", "tie", "tieshou" }) );
        set("nickname","铁手丹心");
        set("gender", "男性");
        set("age", 60);
        set("long",
               "这是一位白发苍苍的老人，早年曾是名动江湖的“四大名捕”之一，性
好任侠，公正无私。\n");
        set("combat_exp",100000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("apply/attack", 50);
        set("apply/defense", 50);
        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);
        set("neili", 800);
        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);
        set("no_get",1);
		
		// 特别技能指导能力
		s_skill = "master-str";
        set("inquiry", ([
                "比武大会"       : (: ask_me :),
                s_skill       : (: ask_special_skill :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}
void init()
{
        ::init();
           board = present("board",environment());
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}
string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句口诀。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得自身的力量也随之增强了。\n");
			return "要勤学苦练，要为正道出力。";
		}
	}
	return "什么？";
}

int accept_object(object user, object ob)
{
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	return 0;
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();
        if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";
        for ( i=sizeof(ob); i>0; i-- ) {
                ob[i-1]->move("/d/huashan/sheshen");
        }
        return "好，现在比武大会正式开始，全体集合！\n";
}
int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;
        ob1 = this_player();
        if( !arg || arg=="" ) return 0;
//          if ( arg == "tie youxia" || arg == "tie" || arg == "tieshou" )
/* {
             command("say " + "你不能跟我比划！\n");
             return 1;
} */
        if ( this_object()->query_temp("busy") )
                return notify_fail("每次只能有两人参加比武。\n");
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
          if(!ob2->is_character() || ob2->is_corpse())
           return notify_fail("你看清楚一点，它是活物吗!!!! \n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2
);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你
比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1
->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);
                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行
比试。\n" NOR);
                return 1;
        }
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
        remove_call_out("check");
//      ob1->set("qi",(int)ob1->query("max_qi"));
//      ob2->set("qi",(int)ob2->query("max_qi"));
        remove_call_out("fighting");
        call_out("fighting",0,ob1,ob2);
        call_out("check",1,ob1,ob2);
        return 1;
}
void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}
void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
            + "与" + ob2->query("name") + "，现在比武场上开始比武论剑！\n");
        call_out("observe",1,ob1,ob2);
}
int observe(object ob1,object ob2)
{
        object ob;
        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }
        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "落荒而逃了！\n");
                return 1;
        }
        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "落荒而逃了！\n");
                return 1;
        }
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("chat " + ob1->query("name") +
                       "中途放弃比武！\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") +
                       "中途放弃比武！\n");
                return 1;
         }
        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi")) {
                        command("chat " + ob1->query("name")
                                + "与" + ob2->query("name") + "比武不分胜负！\n
");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                  if (userp(ob1)&&userp(ob2))
                           board->do_record(ob1->query("name")+ "比武战胜" + ob2->query("name"));
                ob = new("clone/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
                  if (userp(ob1)&&userp(ob2))
                           board->do_record(ob2->query("name")+ "比武战胜" + ob1->query("name"));
                ob = new("clone/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }
        return 1;
}
int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}
