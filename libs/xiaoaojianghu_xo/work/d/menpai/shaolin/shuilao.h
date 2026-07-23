// shuilao.h 
// By lala June 29, 1997
int do_zhua(string arg);

void init()
{
        add_action("do_zhua", "zhua");
}

int do_zhua(string arg)
{
        object me;
        int max, now;
        
        me = this_player();
        if ( !arg || (arg != "bug" && arg != "虫子" && arg != "chongzi" && arg != "chong"))
        {
                write("你要抓什么？\n");
                return 1;
        }
        max = me->max_food_capacity();
        now = me->query("food");
        if ( now <= max/3 )
        {
                message_vision(
"$N从墙上抓了几只"BLU"虫子"NOR"塞进嘴里，一边咀嚼，一边发出满意的哼声。\n", me);
                me->add("food", random(5)+15);
                return 1;
        }
        write("喂，有点吃就得了，这虫子就那么好吃？\n");
        return 1;
}

