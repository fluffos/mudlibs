// cake.c 
// idea from xo lib 
// rewritten by mudring Sep/18/2002 
// Modified by kuku@sjsh 2003.09.10 
       
#include <ansi.h> 
#include <localtime.h> 
#define REMON 8  // 月份，实际月份等于这个数字加1 
#define REDAY 24 // 日期 从20到24为止 
#define REEXP 200000 // 获得一般奖励最小需要的exp 
inherit ITEM; 

string *GetName = ({ 
        "豆沙月饼", 
        "莲蓉月饼", 
        "椰蓉月饼", 
        "火腿月饼", 
        "芝麻月饼", 
        "桂花月饼", 
        "素月饼", 
        "冰皮月饼", 
        "果蔬月饼", 
        "海味月饼", 
        "蛋黄月饼", 
        "椰奶月饼", 
        "甜玉米月饼", 
        "改良月饼", 
        "五仁月饼", 
        "枣泥月饼", 
        "百果月饼",
        "水果月饼",
}); 

varargs string GetColor(int flag) 
{ 
        string color; 
        if (flag) 
                color = COLOR_D->random_color(4); 
        else { 
                if (random(2)) 
                        color = COLOR_D->random_color(4); 
                else 
                        color = COLOR_D->random_color(3); 
        } 
        return color; 
} 

string SetName() 
{ 
        int i = random(sizeof(GetName)); 
        return (GetColor() + GetName[i] + NOR); 
} 

void create() 
{ 
        string myName; 
        myName=SetName(); 
        set_name( myName, ({ "cake"}) ); 
        set("long","一个小小的" + myName + "，香喷喷的，刚出炉，还是热的呢！\n"); 
        set_weight(50); // 一两 
        if( clonep() )  
                set_default_object(__FILE__); 
        else { 
                set("unit", "个"); 
                set("value", 5000); // 50 silver one 
                set("no_sell","穷到这份上了？月饼也要卖？\n"); 
                set("no_get","捡月饼吃？\n"); 
                set("no_put","想收藏啊？\n"); 
                set("no_drop","嘿嘿......！\n"); 
                set("no_give","自己留着吧！\n"); 
        } 
        set("is_monitored",1); 
        setup(); 
} 

void init() 
{ 
        add_action("do_eat", "eat"); 
} 


int do_eat(string arg) 
{ 
        object me, what; 
        me = this_player(); 
        what = this_object(); 

        if (me->is_busy()) return notify_fail("你现在正忙着呢！\n"); 
        
        if (arg != "cake") 
                return notify_fail("你想吃什么？cake？？？\n"); 
                
        if ( this_object()->query("owner") != me->query("id")){
                message_vision(HIR"\n偷吃礼物，打入天牢。\n"NOR,me);
                me->move("/d/wiz/jail");
                destruct(this_object());
                return 1;
        }
 
        tell_object(me, MAG"这是三界神话送给大家的中秋月饼，吃了它可以得到武学、道行、潜能或者黄金\n
前三项奖励点数总和为800000，黄金奖励数目由0两-500两随机。你可以自己分\n
配（fenpei）你想得到的点数(黄金除外)。指令格式：fenpei <个人参数>\n"NOR); 
        return 1; 
} 
