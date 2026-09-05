#include <ansi.h>
inherit ITEM;
int pen2(object);
void create()
{

        set_name(HIB"香水"NOR, ({ "xiang shui", "shui" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIG"这是一瓶西夏国进贡的香水，专供皇后公主使用，\n据说用了(pen)可以增加女性的容貌、魅力！\n" );
                set("unit","瓶");
                set("value",100000);
        }
}

void init()
{
        add_action("do_tu","pen");
}

int do_tu(string arg)
{
        object me;
	
        me = this_player();
        
        if (me->query("gender") == "男性")
        {
        	write("你一个大男人，也好意思用女人家的香水？\n");
        	return 1;
        }
        tell_object(me,HIG"你将香水瓶打开，小心地向自己喷了喷。\n"NOR);
        message("vision",HIG + me->name() + "小心地打开一瓶" + HIB + "香水" + HIG + "，向自己身上喷了喷。\n"+NOR, environment(me),({me}));
        call_out("pen2",10,me);
        return 1;
}
int pen2(object me)
{
        me->apply_condition("xs_condition",5);
        tell_object(me,HIW"香水慢慢在你身体周围弥漫开......\nwa～～～！你发现自己沐浴在一阵香水雨中！好棒啊～～\n你发现身边的人也都在羡慕地看着你！\n");
        message("vision",HIC"你觉得一阵异香扑鼻而来，让你如醉如痴！转头一看，" + me->name() + "明眸皓齿，如花似玉，\n你发现从来没有遇到过象" + me->name() + "这么美的姑娘！\n",environment(me),({me}));
        return 0;
}

