// referee.c 公平子

inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
string ask_me();
int do_halt();
int do_no();

void create()
{
        set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
        set("gender", "男性");
        set("age", 35);
        set("no_get", 1);
        set("long",
                "这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
        set("combat_exp",60000);
        set("shen_type", 1);
        set("attitude", "friendly");

        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        set("inquiry", ([
                "比武大会"       : (: ask_me :),
                "武林大会"       : (: ask_me :),
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}


void init()
{
        ::init();
        add_action("do_start", "start");
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "hit");
        add_action("do_bihua", "kill");
        add_action("do_bihua", "fight");
        add_action("do_bihua", "qiecuo");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
        add_action("do_no", "beg");
        add_action("do_no", "steal");
        add_action("do_no", "quanjia");
        add_action("do_no", "persuade");
        add_action("do_no", "touxi");
        add_action("do_no", "ansuan");
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";
/*
        for ( i=sizeof(ob); i>0; i-- ) 
        {
                if (environment(ob[i-1]))
                {
                        ob[i-1]->move("/d/city/wudao1");
        		ob[i-1]->set_temp("view_leitai",1);
                }
        }
*/
        return "好，现在比武大会正式开始，全体集合！\n";
}

int do_no()
{
        command("say " + "这里众目睽睽，岂能做此不才之事。\n");
        return 1;
}
int do_start()
{
        int i,j;
	object *allob, ob1, ob2, old_target, where;

        if (!wizardp(this_player()))
        {
             command("say " + "比武要巫师发令才开始！\n");
             return 1;
        }
        allob = all_inventory(environment(this_player()));
        ob1 = this_object();
        ob2 = this_player();

        j = 0;
        for ( i=sizeof(allob); i>0; i-- ) {
             if ( userp(allob[i-1]) &&
                 !wizardp(allob[i-1]))
             {
                if (j == 0)
                {
                    ob1 = allob[i-1];
                    j = 1;
                }
                else ob2 = allob[i-1]; 
             }
        }
        if (ob2 != this_player()) ob1->fight_ob(ob2);
        if (ob1 == ob2) return notify_fail("只有一个人不能比武。\n");

/*
        ob1 = this_player();

        if ( this_object()->query_temp("busy") )
                return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("只有一个人不能比武。\n");

        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
                return 1;
        }
*/
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("qi",(int)ob1->query("max_qi"));
//      ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}
int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
        {
             command("say " + "你不能跟我比划！\n");
             return 1;
        }

        if ( this_object()->query_temp("busy") )
                return notify_fail("每次只能有两人参加比武。\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
	if (ob1->query("max_qi") > ob1->query("qi"))
                return notify_fail("你受伤太重不能比武。\n");
	if (ob1->query("max_qi") > ob1->query("eff_qi"))
                return notify_fail("你受伤太重不能比武。\n");
	if (ob2->query("max_qi") > ob2->query("qi"))
                return notify_fail("对方受伤太重不能比武。\n");
	if (ob2->query("max_qi") > ob2->query("eff_qi"))
                return notify_fail("对方受伤太重不能比武。\n");
// 允许玩家自比
        command("say " + "比武要裁判发令才开始！\n");
        return 1;


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("qi",(int)ob1->query("max_qi"));
//      ob2->set("qi",(int)ob2->query("max_qi"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

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
                + "与" + ob2->query("name") + "，现在擂台上开始比武夺帅！\n");
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
                command("chat " + ob1->query("name") + "被打落擂台了！\n");
                command("chat " + ob1->query("id") + "被打落擂台了！\n");
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "被踢下擂台了！\n");
                command("chat " + ob2->query("id") + "被踢下擂台了！\n");
                return 1;
        }

        if (ob1->query_temp("halted"))
         {
                ob1->delete_temp("halted");
                command("chat " + ob1->query("name") + "中途放弃比武！\n");
                command("chat " + ob1->query("id") + "中途放弃比武！\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
                ob2->delete_temp("halted");
                command("chat " + ob2->query("name") + "不愿继续比武了！\n");
                command("chat " + ob2->query("id") + "不愿继续比武了！\n");
                return 1;
         }

        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                if  (ob2->query("qi")*2 > ob2->query("max_qi")) {
                        command("chat " + ob1->query("name")
                                + "与" + ob2->query("name") + "比武不分胜负！\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                ob = new("clone/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
                ob = new("clone/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }

        return 1;

}

int do_halt()
{
	object me = this_player();
	if (me->is_fighting()) me->set_temp("halted",1);
	return 0;
}
