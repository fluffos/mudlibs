// Npc : /clone/npc/enemy.c
// Create by lonely for Nitan@Mud (03/28/2002)
// 守卫任务 NPC。

#include <ansi.h>
inherit NPC;
#include <npc_name.h>

void leave_here();
void create()
{
        string id1,id2,idf1,idf2;
        string name1,name2,title;
        int index1,index2,exp;
        index1=random(sizeof(first_name));
        index2=random(sizeof(first_name));        
        name1=first_name[index1]["name"];
        name2=first_name[index2]["name"];
        id1=first_name[index1]["id"];
        id2=first_name[index2]["id"];
        idf1=id1;
        idf2=id2;
        index1=random(sizeof(second_name1));
        index2=random(sizeof(second_name2));
        name1+=second_name1[index1]["name"];
        name2+=second_name2[index2]["name"];
        id1+=" "+second_name1[index1]["id"];
        id2+=" "+second_name2[index2]["id"];



        index1=random(sizeof(third_name1));
        index2=random(sizeof(third_name2));
        name1+=third_name1[index1]["name"];
        name2+=third_name2[index2]["name"];
        id1+=third_name1[index1]["id"];
        id2+=third_name2[index2]["id"];
        exp=100000 + random(500000);

        set_name(name1,({id1,idf1}) );
        set("max_neili",500+random(500));
        set("max_jingli",500+random(500));
        set("max_qi",500+random(500));
        set("max_jing",500+random(500));
        set("age", 18 + random(30));
        set("long", "这人是前来攻打" + (string)query("is_attacking")?query("is_attacking") : "别的门派"
                   + "的一名" + (string)query("family/family_name")?query("family/family_name") : "未知门派" +"弟子。\n"); 

        set("combat_exp", exp);
/*
        if(exp>10000000) title+=HIR"   世外高人"NOR;
        else if(exp>8000000) title+=HIG"   江湖名宿"NOR;
        else if(exp>6000000) title+=MAG"   武林宗师"NOR;
        else if(exp>4000000) title+=HIB"   威震一方"NOR;
        else if(exp>2000000) title+=RED"   声名赫赫"NOR;
        else if(exp>1000000) title+=HIC"   当世英杰"NOR;
        else title+=HIW"   后起之秀"NOR;
*/
        set("title",title);  
        set("attitude", "peaceful");

        set("str", 20 + random(20));
        set("con", 20 + random(20));
        set("dex", 20 + random(20));
        set("int", 20 + random(20));

        set("chat_chance", 5);
        set("chat_msg", ({
        (: leave_here :), 
        (: random_move :), 
        (: random_move :), 
        }));

        setup();
        if (query("is_attacking") ){
        if (query("is_attacking")=="武当派"||query("is_attacking")=="华山派")
        carry_object("/clone/weapon/sword")->wield();
        else
        carry_object("/clone/weapon/blade")->wield();
        }

        carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        object me = this_player();

        ::init();

        if( interactive(me) && visible(me) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_nod", "nod"); 
}

void greeting(object me)
{
        if (!me || !present(me, environment())) return;

        if (interactive(me) && me->query_temp("swjob/allow") && !me->query_temp("swjob/finish"))
        {
                // 这里的描写似乎需要调整（正派说这种话不合身份）
                command("grin");
                message_vision(HIW "只见$N" HIW "狞笑着对$n" HIW "道：“嘿嘿，不知死活的" +
                        RANK_D->query_rude(me) +"，竟然敢和我们" + query("family/family_name") +"做对？！"
                        "\n看我来教训教训你！”\n", this_object(), me );
                kill_ob(me);
                return;
        }
        message_vision(HIW "$N" HIW "冷冷地扫了$n" HIW "一眼。\n", this_object(), me );
}

void kill_ob(object me)
{
        object ob = this_object();

        if ( !me->query_temp("swjob/allow") || me->query_temp("swjob/finish"))
                return ::kill_ob(me);
        else
        {
                // 复制状态，需要调整。
                NPC_D->set_from_me(ob, me, 100 + random(20));
                NPC_D->init_npc_skill(ob, NPC_D->check_level(me) + (10 + random(20)));
                ::kill_ob(me);
                return;
        }
}

// 如果接受了贿赂
int do_nod(string arg)
{
        object me = this_player();
        object ob = this_object();
        int amount;

        if ( !me->query_temp("swjob/waiting") || me->query_temp("swjob/finish")
        || stringp(arg))
                return 0;

        else {
                me->command("nod");
                if (intp(me->query_temp("swjob/waiting")))
                {
                        amount = me->query_temp("swjob/waiting");

                        message_vision(HIW "只见$N" HIW "长笑三声：“哈哈哈，识时务者为俊杰，" +
                                RANK_D->query_respect(me)+ "果然是明白人，嘿嘿，这区区" +
                                chinese_number(amount) +"两白银就归你了，哈哈。”\n\n" NOR,
                                ob, me);
                        // 因为是“两”为单位，所以要 * 100。
                        MONEY_D->pay_player(me, amount * 100);
                        me->set_temp("swjob/accepted", 1);
                        tell_object(me, HIR + ob->name() + "递给了你" + chinese_number(amount) 
                                + "两白银以后，吐出一口鲜血，扬长而去。\n" NOR );
                        return 1;
                }
                else return  0;
        }
}
void leave_here()
{
        object ob = this_object();

        if ( ob->is_fighting() || ob->is_busy() || ob->query("qi") < 40
        || ! ob->query("is_attacking")|| ob->is_unconcious())
                return;
//        move_enemy(ob, ob->query("is_attacking"));
        DEFEND_D->move_enemy(ob, ob->query("is_attacking"));
        return;
}
void die()
{
        object me, ob = this_object();
        string *pills, pill;
        int percent;
        int amount = 300 + random(300);
        string *condition = ({
                "气喘吁吁，就要不支", "头重脚轻，马上就倒", 
                "呕血成升，眼冒金星", "伤痕累累，无力招架", 
        });

        if (objectp(me = query_temp("last_damage_from")) 
        && environment() == environment(me) 
        && me->query_temp("swjob/allow") 
        && !me->query_temp("swjob/finish")
        && !me->query_temp("swjob/waiting"))
        {
                switch (random(15)) {
                        case 1: {
                                message_vision(HIR "眼见$N" HIR + condition[random(sizeof(condition))]
                                                +"，突然$N大喝一声，急退几步，\n“扑通”给$n跪了下来。"
                                                "\n" NOR, ob, me);
                                tell_object(me, HIW + ob->name()+"突然从怀里掏出一堆白花花的银子，小声"
                                                "对你道：“这位" + RANK_D->query_respect(me) + "，\n你"
                                                "就网开一面（nod）如何，这" + chinese_number(amount) +
                                                "两白银就归你了！”\n" NOR);
                                this_object()->remove_all_enemy(0); 
                                me->set_temp("swjob/waiting", amount);
                                return;
                        }
                        default: {
                                // 奖励
                                   me->add_temp("swjob/killed", 1); 
                                ::die();
                        }
                }
                return;
        }
                                   me->add_temp("swjob/killed", 1); 
        ::die();
}

