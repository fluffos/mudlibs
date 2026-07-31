 inherit ITEM;
void create()
{
        set_name("月黄色砚台", ({ "yellow yantai", "月黄色砚台", "yantai" }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一方罕见的月黄色砚台。
砚体温润莹洁，边上按照石头的纹理色泽雕刻了一幅流泉图，好像在哪里见过似的。\n");
                set("value", 1000);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
        }
        
} 
void init() {
        add_action("do_look", "look");
} 
int do_look(string arg) {
        object me;
        
        me = this_player();
        if (!arg || (arg != "yantai" && arg != "yellow yantai")) {
                return 0;
        }
        if (environment(me)->query("mingxuan")) {
                if (NATURE_D->is_day_time()) {
                        tell_object(me, "\n你吃了一惊：砚台上雕刻的流泉图竟然跟眼前景色完全相合。\n");
                        tell_object(me, "只是砚台上画的琴岩似乎比泉水冲击下的琴岩多了旁边的一个棱角。\n");
                        me->set("marks/黄山鸣弦泉", 1); 
                } else {
                        tell_object(me, "\n你觉得流泉图跟四周景色有些相似，可是黑暗之中看不清楚。\n");
                }
        }
        return 0;
}    
