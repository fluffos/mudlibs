#include <ansi.h>
inherit ITEM;void init(){add_action("do_eat", "eat");}

void create()
{
        set_name(HIY "九转速成丹" NOR, ({ "sucheng dan", "sucheng", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "传说此丹乃是盘古开天地时留下的神品，凡人吃了会有意想不到的效果。\n" NOR);
                set("unit", "颗");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("no_get", 1);
                set("value", 100000);
                set("weight", 50);set("merit", 2000);//价值

                set("only_do_effect", 1);
                set("gift_type", "mingsi");
                set("gift_name", "九转速成大法");
                set("gift_point", 20);
                set("gift_msg", HIY "冥冥中你似乎已经领悟了“九转速成大法”。\n" NOR);
        }
        setup();
}

int do_eat(string arg)
{
        int point;
        point = query("gift_point");
        if (!id(arg))
	return notify_fail("你要吃什么？\n");

        // 真命天子提升成功几率
        if (this_player()->query("special_skills/emperor"))
                point += 35;

        // 天煞孤星提升成功几率
        if (this_player()->query("special_skills/lonely"))
                point += 10;

        // 福星高照提升成功几率
        if (this_player()->query("special_skill/lucky"))
                point += 5;

        message_vision(WHT "$N" WHT "一仰脖，吞下了一" +
                       query("unit") + name() + WHT
                       "。\n" NOR, this_player());


        if (this_player()->query("gift/" + query("gift_type") + "/succeed") >= 500)
        {
                tell_object(this_player(), "你觉得这药好象没什么效果。\n");
        } else

        if (random(100) >= point)
        {
                tell_object(this_player(), HIR "不过你觉得这药好像没起到什么"
                                "作用。\n" NOR);

                // 记录失败的记号
                this_player()->add("gift/" + query("gift_type") + "/fail", 1);
        } else
        {
                tell_object(this_player(), query("gift_msg"));
                tell_object(this_player(), HIC "恭喜你领悟了" + query("gift_name") +
                                HIC "。\n" NOR);

                // 记录成功的记号
                this_player()->add("gift/" + query("gift_type") + "/succeed", 1);

                // 增加相应的天赋属性
                this_player()->set("jiuzhuan-12tian/"+ query("gift_type"), 1);
        }

        // 记录入吃丹的总量
        this_player()->add("gift/" + query("gift_type") + "/all", 1);
        destruct(this_object());
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

