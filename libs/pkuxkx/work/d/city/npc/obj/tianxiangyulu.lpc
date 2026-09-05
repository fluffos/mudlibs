//天香玉露
//made by icer
//奖励每周最受欢迎玩家
#include <ansi.h>
inherit ITEM;
int do_drink();
void create()
{
        set_name(HIG"天香玉露"NOR, ({"tianxiang yulu","yulu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", HIG"这是一瓶武林中人人垂涎的至宝，据说服用(drink)之后可以平添一甲子之功力。\n
                是巫师用来奖励最受欢迎玩家的奖品。只能由获奖者自己服用。\n"NOR);
                set("value", 100000);
                set("no_give",1);
                set("no_drop",1);
                set("no_store",1);
                set("no_pawn",1);
        }
        setup();
}
void init()
{
        add_action("do_drink","drink");
}
int do_drink()
{
        int i,skill_level;
        mapping skl;
        object me = this_player();
        object ob = this_object();
        
        if (ob->query("owner") != me->query("id"))
        {
                write("这是巫师给" + ob->query("owner") + "的奖品，你怎么可以服用呢？\n");
                return 1;
        }
        log_file("helpnew/USE_AWARD",me->query("name") + "(" + me->query("id") + ")于" + ctime(time()) + "服用了天香玉露。\n");
        message_vision(HIG"$N打开天香玉露，小心地闻了闻，醺醺欲醉，口水直流。\n一仰头全部喝了下去，感觉浑身上下无处不充满了力量！\n"NOR,me);
        tell_object(me,HIG"你的最大精力增加了100点！\n你的最大内力增加了100点！\n");
	me->add("max_neili",100);
	me->add("max_jingli",100);
        skl = me->query_skills();
        if(!sizeof(skl)) 
                tell_object(me,HIR"你丝毫没有功夫根基，无法增长功力！\n"NOR);
        else {
                i = random(sizeof(skl));
                skill_level = 5 + random(6);
                me->set_skill(keys(skl)[i],skill_level + me->query_skill((keys(skl))[i],1));
                tell_object(me,HIG"你的" + to_chinese((keys(skl))[i]) + "增加了" + chinese_number(skill_level) + "级！\n");
                log_file("helpnew/USE_AWARD",me->query("name") + "的" + to_chinese((keys(skl))[i]) + "增加了" + chinese_number(skill_level) + "级。\n");
        }
        destruct(ob);
        return 1;
}
                
