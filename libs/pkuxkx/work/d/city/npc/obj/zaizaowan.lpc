//再造丸
//made by icer
//奖励每月最受欢迎玩家
#include <ansi.h>
inherit ITEM;
int do_drink();
void create()
{
        set_name(HIY"再造丸"NOR, ({"zaizao wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIY"这是一颗呈金黄色的丸药，据说炼制它需要费时几十年，花去无数功夫。\n
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
        add_action("do_drink","eat");
}
int do_drink()
{
        mapping skills;
        object me = this_player();
        object ob = this_object();
        
        if (ob->query("owner") != me->query("id"))
        {
                write("这是巫师给" + ob->query("owner") + "的奖品，你怎么可以服用呢？\n");
                return 1;
        }
        log_file("helpnew/USE_AWARD",me->query("name") + "(" + me->query("id") + ")于" + ctime(time()) + "服用了再造丸。\n");
        message_vision(HIG"$N小心翼翼地取出" + HIY + "再造丸" + HIG + "，小心翼翼地放入口中，小心翼翼地咽了下去.....\n"NOR,me);
        tell_object(me,HIY"你感觉自己的生命力更强大了！！！\n");
        skills=me->query_skills();
        if(mapp(skills))
        {
                string *skname;
                skname=keys(skills);
                for(int i=0;i<sizeof(skills);i++)
                        skills[skname[i]]++;
        }
        me->add("potential", (int)me->query("potential")-(int)me->query("learned_points"));
        me->add("pot/gift", (int)me->query("potential")-(int)me->query("learned_points"));
        me->add("combat_exp",(int)me->query("combat_exp")/49);
        me->add("exp/gift",(int)me->query("combat_exp")/49);
        destruct(ob);
        return 1;
}
                
