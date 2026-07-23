// Inherit: quarry.c 猎物
// Create by Vin for Heros.cn

#include <ansi.h>
inherit NPC;

int is_quarry()
{
	return 1;
}

void setup()
{
        if (this_object()->query("aves"))
        {
                set("limbs", ({ "头部", "身体", "左翅", "右翅",
                                "爪子", "尾巴" }));
                set("verbs", ({ "bite", "claw" }));
        } else
        {
                set("limbs", ({ "头部", "身体", "腹部", "背部",
                                "前脚", "后脚", "尾部" }));
                set("verbs", ({ "hoof", "bite", "claw" }));
        }
        set("race", "野兽");
        set("attitude", "aggressive");
        ::setup();
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;

        // 自动攻击驭兽术等级不高的玩家
        if (me->query("combat_exp") > 1000000
           && ! this_object()->query("no_auto_kill"))
        {
                remove_call_out("fight_ob");
                call_out("fight_ob", 0, me);
        }

        remove_call_out("disappear");
        call_out("disappear", 15);
}

void disappear()
{
        object ob = this_object();

        // 捕猎呼出的野兽会遁之
        if (living(ob) && ob->query("owner"))
        {
                message_vision(WHT "\n突然$N" WHT "猛地一窜，瞬间便"
                               "消失得无影无踪。\n\n", ob);
                destruct(ob);
        }
}

void die(object killer)
{
        object me, item;
        int kar, exp, pot;
        object ob = this_object();
        int power, skill;
        string msg;

        if (ob->query("aves"))
                message_vision(HIR "\n只见$N" HIR "扑腾了几下，从半"
                               "空中坠落下来，死了。\n\n" NOR, ob);
        else
                message_vision(HIR "\n只听$N" HIR "嚎了几声，倒在地"
                               "上扑腾了几下，死了。\n\n" NOR, ob);

        if (objectp(me = killer)
           || objectp(me = this_object()->query_temp("last_damage_from")))
        {
                // 如果为自己的猎物，则奖励之
                if (random(2)==0
                   && me->query("combat_exp") <= 1000000)
                {
                        // 根据猎物设定的参数来给予奖励

        exp = 35+random(50);
        pot = 25+random(30);
if (pot >exp ) pot=exp-10;
                  message_vision( "\n由于$N成功的杀死一个猎物，被奖励：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(1) + "点评价作为答谢。\n" , me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",1);
                }
                skill = me->query_skill("unarmed", 1);

                // 获得物品
                if (ob->query("item1") && random(skill) > 30)
                {
                        item = new(ob->query("item1"));
                        item->move(me, 1);

                        msg = HIC "你仔细翻寻" + ob->name() +
                              HIC "的尸体，从上面割下了一" +
                              item->query("base_unit") +
                              item->name() + HIC;

                        // 一定几率获得高级物品
                        if (ob->query("item3") && random(skill) > 100
                           && random(5) > 3)
                        {
	                        item = new(ob->query("item3"));
        	                item->move(me, 1);

	                        msg += "及一" + item->query("base_unit") +
                                       item->name() + HIC;
                        } else
                        if (ob->query("item2") && random(skill) > 60
                           && random(4) > 2)
                        {
	                        item = new(ob->query("item2"));
        	                item->move(me, 1);

	                        msg += "及一" + item->query("base_unit") +
                                       item->name() + HIC;
                        }
                        msg += "。\n\n" NOR;
                        tell_object(me, msg);
                }
        }
        destruct(ob);
}
