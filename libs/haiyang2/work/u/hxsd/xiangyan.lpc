#include <ansi.h>

inherit ITEM;

void create()
{
        string *order = ({HIR "中华" NOR,HIY "555" NOR, YEL "阿诗玛" NOR, HIW "红塔山" NOR, HIC "万宝路" NOR, HIG "希尔顿" NOR,HIW "玉溪" NOR,HIM "芙蓉王" NOR});
        set_name( (order[random(8)]), ({ "cigarette" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盒香烟，可以(xiyan)。\n");
                set("unit", "盒");
                set("count",6);
        }
}

void init()
{
        add_action("do_smoke", "xiyan");
}

int do_smoke()
{
        object me = this_player();
        object obj = this_object();

        if(environment(me)->query("no_smoke"))
                return notify_fail("这里不准抽烟！\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢，没空抽烟！。\n");

        if(query("count") == 6)
                message_vision("$N抽出一支$n，点着了火，美滋滋地吸了起来。\n", me, this_object());
        else if (query("count") == 1 ) {
                message_vision("$N猛吸了一口剩下的烟屁股，两个手不由自主地又去模口袋。\n", me);
                call_out("destrory",1,obj);

                return notify_fail("");
        }
        else
        switch(random(4)) {

                case 0: message_vision("$N吐出一串烟圈，看着它悠闲的散开。\n", me);
                        break;
                case 1: message_vision("$N狠狠的吸了一口$n，大概是吸得太猛了，一张脸涨的通红。\n", me, obj);
                        break;
                case 2: message_vision("$N吸了一口$n，摇头晃脑地说道：“饭后一支烟，赛过活神仙。”\n", me, obj );
                        break;
                case 3: message_vision("$N翘起二郎腿，眯上眼睛，猛吸了一口$n，自言自语道：“这东西\n害人又害己，为啥我还那么喜欢？”\n", me, obj);
                        break;
                default:
                        break;
        }
        add("count",-1);
        return notify_fail("");
}


void destrory(object ob)
{
        destruct(ob);
}
