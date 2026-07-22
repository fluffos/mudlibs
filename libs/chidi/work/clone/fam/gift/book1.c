#include <ansi.h>
inherit ITEM;void init(){add_action("do_study", "dakai");}

void create()
{
        set_name(HIG "天书残谱-第2篇" NOR, ({ "tianshu canpu2", "tianshu2", "canpu2" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "这是一本炎帝遗留下来的天地魁宝--《炎帝书经》的第2篇残篇，你可以打开（dakai）看看。\n" NOR);
                set("unit", "本");
                 set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("no_get", 1);
                set("value", 10000);
                set("weight", 50);set("merit", 5);//价值

                set("only_do_effect", 1);
                set("gift_type", "can_dushu");
                set("gift_name", "《四库全书》");
                set("gift_point", 30);
                set("gift_msg", HIY "突然间自己身旁围绕着七彩朝霞。\n" NOR);
        }
        setup();
}

int do_study(string arg)
{
        int point;
        object book;
        point = query("gift_point");       
        
        if (this_player()->query_condition("can_yanjiu"))
          return notify_fail("你已经领悟过这本书的奥妙了！\n");

        if (!id(arg))
          return notify_fail("你要打开什么书？\n");        
        
        // 真命天子提升成功几率
        if (this_player()->query("special_skills/emperor"))
                point += 35;

        // 天煞孤星提升成功几率
        if (this_player()->query("special_skills/lonely"))
                point += 10;

        // 福星高照提升成功几率
        if (this_player()->query("special_skill/lucky"))
                point += 5;

        message_vision(WHT "$N" WHT "打开了一" +
                       query("unit") + name() + WHT
                       "。\n" NOR, this_player());
/*
        if (this_player()->query("gift/" + query("gift_type") + "/all") >= 100)
        {
                tell_object(this_player(), "你再也看不懂这本书的玄奥之处。\n");                
        } else
*/
        if (random(100) >= point)
        {
                tell_object(this_player(), HIR "你怎么也看不懂这本书的玄奥之处的"
                                "作用。\n" NOR);               

                // 记录失败的记号
                this_player()->add("gift/" + query("gift_type") + "/fail", 1);
        } else
        {
                tell_object(this_player(), query("gift_msg"));
                tell_object(this_player(), HIC "你得到了一本" + query("gift_name") +
                                HIC "。\n" NOR);

                // 记录成功的记号
                this_player()->add("gift/" + query("gift_type") + "/succeed", 1);

                // 增加相应的天赋属性
              book = new(__DIR__"int_book");  
              book->move(this_player());             
                
        }

        // 记录入吃丹的总量
        this_player()->add("gift/" + query("gift_type") + "/all", 1);  
        destruct(this_object());      
        return 1;
}
void owner_is_killed() { destruct(this_object()); }

