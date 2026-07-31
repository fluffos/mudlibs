inherit ITEM;

#include <ansi.h>; 

void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("do_yanjiu", "yanjiu");
        add_action("do_yanjiu", "research");
}

void create()
{
        set_name(HIR "《葵花宝典》" NOR, ({ "kuihua baodian", "baodian", "book", "kuihua"}));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", HIR "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。\n" NOR);
                set("value", 1);
                set("material", "paper");
                set("no_sell", 1);
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int plvl, con, improve;
        int neili_lost;

        if (! arg || ! id(arg))
                return 0;

        if (me->is_busy())
        {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if (! SKILL_D("pixie-jian")->valid_learn(me))
        {
                write("你的无法从《葵花宝典》中学到辟邪剑法。\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (where->query("no_fight") && me->query("doing") != "scheme")
        {
                write("你无法在这里静下心来研读宝典。\n");
                return 1;
        }

        if ((string)me->query("gender") == "女性")
        {
                write("自古没有听说女人可以读《葵花宝典》的。\n");
                return 1;
        }

        if ((string)me->query("gender") == "男性")
        {
               write("《葵花宝典》的第一页写着：欲练神功，必先自宫。\n");
               return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if (me->query_skill("pixie-jian", 1) >= 180)
        {
                write("这本书你已经研究得差不多了，没什么好读的了。\n");
                return 1;
        }

        if ((int)me->query("combat_exp") < 200000)
        {
                        write("你的实战经验不足，再怎么读也没用。\n");
                        return 1;
        }

        if ((int)me->query("max_neili") < 500)
        {
                        write("你的内力太差，无法修炼此等神功。\n");
                        return 1;
        }

        switch (random(3))
        {
        case 0:
                message("vision", me->name() + "偷偷摸摸翻出"
                        "一本书在读。\n", environment(me), me);
                break;
        case 1:
                message("vision", me->name() + "边读书边骚首"
                        "弄姿，好象在模仿女人。\n", environment(me), me);
                break;
        case 2:
                message("vision", me->name() + "边读书边把腰"
                        "身扭来扭去，甚为诡异。\n", environment(me), me);
                break;
        }

        if ((int)me->query("jing") < 60)
        {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        plvl = me->query_skill("pixie-jian", 1);
        if (plvl > 165) neili_lost = 100; else
        if (plvl > 150) neili_lost = 60;  else
        if (plvl > 120) neili_lost = 40;  else
        if (plvl > 100) neili_lost = 30;  else
        if (plvl > 50)  neili_lost = 20;
                   else neili_lost = 10;

        con = me->query_con();

        if ((int)me->query("neili") < neili_lost)
        {
                write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

        if (! me->can_improve_skill("pixie-jian", 1))
        {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        if ((plvl > 10) && (con / 2 + random(con) < 50) && random(100) == 1)
        {
                tell_object(me, HIR "你依照着宝典所示运转内息，突"
                                "然只觉内息逆流而上，四肢冰凉，心火如\n"
                                "焚，惨嚎一声，晕了过去。\n" NOR);
                message("vision", HIR + me->name() + "突然惨"
                                  "嚎一声，晕了过去。\n" NOR,
                        environment(me), ({ me }));

                if ((int)me->query("max_neili") > 10)
                {
                        me->add("max_neili", -10 - random(10));
                }

                me->unconcious();
		return 1;
        }

        me->receive_damage("jing", random(30) + 30);
        me->add("neili", -neili_lost);
        me->improve_skill("pixie-jian", 10 + random(30));
        me->start_busy(random(1) + 1);
        write("你研读《葵花宝典》，颇有心得。\n");
        return 1;
}

int do_yanjiu(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        string pfm, jiasha;
        int lv;

        if (! arg)
        {
                write("研究葵花宝典指令格式：research|yanjiu <绝招> from <葵花宝典>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", pfm, jiasha) != 2)
        {
                write("研究葵花宝典指令格式：research|yanjiu <绝招> from <葵花宝典>\n");
                return 1;
        }

        if (me->is_busy())
        {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (where->query("no_fight") && me->query("doing") != "scheme")
        {
                write("你无法在这里静下心来研读宝典。\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if (! id(jiasha))
        {
                write("你要研究什么？\n");
                return 1;
        }

        if (pfm != "gui" && pfm != "duo" && pfm != "pi" && pfm != "po")
        {
                write("袈裟上并没有记载你想研究的绝招。\n");
                return 1;
        }

        if ((int)me->query("combat_exp") < 300000)
        {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        if ((int)me->query("jing") < 100)
        {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

        if (me->query("potential") < me->query("learned_points") + 10) 
        {
                write("你的潜能不够了，研究不出什么。\n");
                return 1;
        }

        // 辟邪剑法绝招夺目神剑
        if (pfm == "duo")
        {
                if ((int)me->query("can_perform/pixie-jian/duo"))
                {
                        write("你已经学会了这招，再研究也没用。\n");
                        return 1;
                }

                if (! (int)me->query_skill("pixie-jian"))
                {
                        write("你研究了半天，发现袈裟所记载的绝招与你毫无关系。\n");
                        return 1;
                }

                if ((int)me->query_skill("pixie-jian", 1) < 80)
                {
                        write("你发现袈裟上记载的绝招过于深奥，一时难以明白。\n");
                        return 1;
                }

                if (random(20) < 18)
                {
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "你对辟邪剑法有了更深的理解，但尚需进一"
                                       "步的研究。\n" NOR);
                } else
                { 
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "过得良久，陡然间你双目一亮，终于领悟了"
                                        "袈裟中所记载的辟邪剑法绝技「夺目神剑」的奥"
                                        "秘！\n" NOR + HIC "你学会了「夺目神剑」。\n" NOR);

                        if (me->can_improve_skill("sword"))
                                me->improve_skill("sword", 1500000);
                        if (me->can_improve_skill("dodge"))
                                me->improve_skill("dodge", 1500000);
                        if (me->can_improve_skill("parry"))
                                me->improve_skill("parry", 1500000);
                        if (me->can_improve_skill("pixie-jian"))
                                me->improve_skill("pixie-jian", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->set("can_perform/pixie-jian/duo", 1);
                }
                me->receive_damage("jing", 80);
                me->add("learned_points", 10);
                me->start_busy(2);
                return 1;
        }

        // 辟邪剑法绝招鬼魅身法
        if (pfm == "gui")
        {
                if ((int)me->query("can_perform/pixie-jian/gui"))
                {
                        write("你已经学会了这招，再研究也没用。\n");
                        return 1;
                }

                if (! (int)me->query_skill("pixie-jian"))
                {
                        write("你研究了半天，发现袈裟所记载的绝招与你毫无关系。\n");
                        return 1;
                }

                if ((int)me->query_skill("pixie-jian", 1) < 100)
                {
                        write("你发现袈裟上记载的绝招过于深奥，一时难以明白。\n");
                        return 1;
                }

                if (random(30) < 28)
                {
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "你对辟邪剑法有了更深的理解，但尚需进一"
                                       "步的研究。\n" NOR);
                } else
                { 
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "过得良久，陡然间你双目一亮，终于领悟了"
                                        "袈裟中所记载的辟邪剑法绝技「鬼魅身法」的奥"
                                        "秘！\n" NOR + HIC "你学会了「鬼魅身法」。\n" NOR);

                        if (me->can_improve_skill("sword"))
                                me->improve_skill("sword", 1500000);
                        if (me->can_improve_skill("dodge"))
                                me->improve_skill("dodge", 1500000);
                        if (me->can_improve_skill("parry"))
                                me->improve_skill("parry", 1500000);
                        if (me->can_improve_skill("pixie-jian"))
                                me->improve_skill("pixie-jian", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->set("can_perform/pixie-jian/gui", 1);
                }
                me->receive_damage("jing", 80);
                me->add("learned_points", 10);
                me->start_busy(2);
                return 1;
        }

        // 辟邪剑法绝招群邪辟易
        if (pfm == "pi")
        {
                if ((int)me->query("can_perform/pixie-jian/pi"))
                {
                        write("你已经学会了这招，再研究也没用。\n");
                        return 1;
                }

                if (! (int)me->query_skill("pixie-jian"))
                {
                        write("你研究了半天，发现袈裟所记载的绝招与你毫无关系。\n");
                        return 1;
                }

                if ((int)me->query_skill("pixie-jian", 1) < 120)
                {
                        write("你发现袈裟上记载的绝招过于深奥，一时难以明白。\n");
                        return 1;
                }

                if (random(40) < 38)
                {
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "你对辟邪剑法有了更深的理解，但尚需进一"
                                       "步的研究。\n" NOR);
                } else
                { 
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "过得良久，陡然间你双目一亮，终于领悟了"
                                        "袈裟中所记载的辟邪剑法绝技「群邪辟易」的奥"
                                        "秘！\n" NOR + HIC "你学会了「群邪辟易」。\n" NOR);

                        if (me->can_improve_skill("sword"))
                                me->improve_skill("sword", 1500000);
                        if (me->can_improve_skill("dodge"))
                                me->improve_skill("dodge", 1500000);
                        if (me->can_improve_skill("parry"))
                                me->improve_skill("parry", 1500000);
                        if (me->can_improve_skill("pixie-jian"))
                                me->improve_skill("pixie-jian", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->set("can_perform/pixie-jian/pi", 1);
                }
                me->receive_damage("jing", 80);
                me->add("learned_points", 10);
                me->start_busy(2);
                return 1;
        }

        // 辟邪剑法绝招破元神剑
        if (pfm == "po")
        {
                if ((int)me->query("can_perform/pixie-jian/po"))
                {
                        write("你已经学会了这招，再研究也没用。\n");
                        return 1;
                }

                if (! (int)me->query_skill("pixie-jian"))
                {
                        write("你研究了半天，发现袈裟所记载的绝招与你毫无关系。\n");
                        return 1;
                }

                if ((int)me->query_skill("pixie-jian", 1) < 180)
                {
                        write("你发现袈裟上记载的绝招过于深奥，一时难以明白。\n");
                        return 1;
                }

                if (random(50) < 48)
                {
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "你对辟邪剑法有了更深的理解，但尚需进一"
                                       "步的研究。\n" NOR);
                } else
                { 
                        message_vision(HIR "$N" HIR "仔细的研读袈裟上记载的绝招，似"
                                       "有所悟。\n" NOR, me);
                        tell_object(me, HIY "过得良久，陡然间你双目一亮，终于领悟了"
                                        "袈裟中所记载的辟邪剑法绝技「破元神剑」的奥"
                                        "秘！\n" NOR + HIC "你学会了「破元神剑」。\n" NOR);

                        if (me->can_improve_skill("sword"))
                                me->improve_skill("sword", 1500000);
                        if (me->can_improve_skill("dodge"))
                                me->improve_skill("dodge", 1500000);
                        if (me->can_improve_skill("parry"))
                                me->improve_skill("parry", 1500000);
                        if (me->can_improve_skill("pixie-jian"))
                                me->improve_skill("pixie-jian", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->set("can_perform/pixie-jian/po", 1);
                }
                me->receive_damage("jing", 80);
                me->add("learned_points", 10);
                me->start_busy(2);
                return 1;
        }
}

