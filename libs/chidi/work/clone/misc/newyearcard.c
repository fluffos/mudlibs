// card.c
#include <ansi.h>;
#include <command.h>;
inherit ITEM;

void create()
{
        set_name(HIR"新春贺卡"NOR, ({"Chinese New Year card", "card"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
set("no_give", 1);
set("no_drop", 1);
set("no_get", 1);
                set("long",
"这是一张"HIR"新春贺卡"NOR"，送给每位在春节进入江湖
的玩家。你可以打开(dakai)来看看，也可以拆开(chaikai)来领取礼品。\n");
                set("value", 0);
                set_weight(10);
        }
        setup();
}
void init()
{
        add_action("do_dakai", "dakai");
        add_action("do_chaikai", "chaikai");
}
int do_dakai(string arg)
{
        object me = this_player();
        string message;
        int col;
        if (arg == "card")
        {
                tell_object(me,
HIW"\n"+
"     ┏━━━━━━━━ "HIR"春节快乐"HIW" ━━━━━━━━┓\n"+
"     ┃  ┌──── Happy    NewYear ────┐  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │                                  │  ┃\n");
                if(strlen(me->query("name")) == 2) tell_object(me,
HIW"     ┃  │  亲爱的"+me->query("name")+"：                      │  ┃\n");
                if(strlen(me->query("name")) == 4) tell_object(me,
HIW"     ┃  │  亲爱的"+me->query("name")+"：                    │  ┃\n");
                if(strlen(me->query("name")) == 6) tell_object(me,
HIW"     ┃  │  亲爱的"+me->query("name")+"：                  │  ┃\n");
                if(strlen(me->query("name")) == 8) tell_object(me,
HIW"     ┃  │  亲爱的"+me->query("name")+"：                │  ┃\n");
                if(strlen(me->query("name")) == 10) tell_object(me,
HIW"     ┃  │  亲爱的"+me->query("name")+"：              │  ┃\n");
        tell_object(me,
HIW"     ┃  │      祝您和您的家人在新春佳节    │  ┃\n"+
"     ┃  │  里，快乐、平安！                │  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │             *  *"HIR"r"HIW"*  *            │  ┃\n"+
"     ┃  │          * *"HIR"a"HIW"* "HIG"^"HIY"Y"HIG"^"HIW" *"HIR"i"HIW"* *         │  ┃\n"+
"     ┃  │         *"HIM"m"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"HIG"^\\^"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"RED"s"HIW"*        │  ┃\n"+
"     ┃  │         "HIG"^"HIY"Y"HIG"^"HIW"*"HIG"\\"HIW"*"RED"e"HIW"*"HIG"/"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"        │  ┃\n"+
"     ┃  │         *"HIG"\\"HIW"*"CYN"t"HIW"*"HIG"|"HIY"Y"HIG"^\\^"HIY"Y"HIG"|"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*        │  ┃\n"+
"     ┃  │        *"MAG"s"HIW"*"HIG"|"HIY"Y"HIG"^\\\\^/^//^"HIY"Y"HIG"|"HIW"*"HIR"a"HIW"*       │  ┃\n"+
"     ┃  │        "GRN"^"YEL"Y"GRN"^\\\\_^\\\\\\//^_//^"YEL"Y"GRN"^"HIW"       │  ┃\n"+
"     ┃  │        "GRN"^\\_^\\_\\_\\//_/_/^_/^"HIW"       │  ┃\n"+
"     ┃  │         "GRN"^^\\_^\\_\\\\/_/^_/^^"HIW"        │  ┃\n"+
"     ┃  │           "GRN"^^\\_ \\// _/^^"HIW"          │  ┃\n"+
"     ┃  │               "GRN"\\_\\_/"HIW"              │  ┃\n"+
"     ┃  │                "GRN"/|\\"HIW"               │  ┃\n"+
"     ┃  │               "GRN"/\\\\/\\"HIW"              │  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │                    "RED"江湖恭贺"HIW"  │  ┃\n"+
HIW"     ┃  └─────────────────┘  ┃\n"+
"     ┗━━━━━━━━━━━━━━━━━━━━━┛\n"+
"\n"HIY+"         卡编号："+me->query("giftcard")+
"\n"NOR);
        }
        return 1;
}

int do_chaikai(string arg)
{
        object box, obj0, obj1, obj2, obj3, obj4, obj5, obj6,obj7,obj8,obj9;
        object me = this_player();
        int col;
        if( !arg ) return notify_fail("你要拆开什么东西？\n");
        if (arg == "card")
        {       
        if ((int) me->query("xinchun"))
               return notify_fail("你已经领取了新春奖励，还要拆开新春卡想作弊啊？\n");

                message_vision(HIB"$N充满憧憬地拆开了新春贺卡，突然如魔术般，出现一个礼品盒！\n"NOR, me);
                box = new(__DIR__"giftbox");               
                               
                if (me->query("weapon/lv") >= 100)
                {
                        me->add("weapon/lv",15);
message_vision(MAG"突然一道金光打在$N身上，$N的第一把武器得到了150点攻击提升！\n"NOR, me);

                }
else

               {
                        me->add("weapon/lv",30);
message_vision(MAG"突然一道金光打在$N身上，$N的第一把武器得到了300点攻击提升！\n"NOR, me);


                }
                if (me->query("weapon2/lv") >= 100)

                {
                      me->add("weapon2/lv",15);
message_vision(MAG"突然一道金光打在$N身上，$N的第二把武器得到了150点攻击提升！\n"NOR, me);


                }
               else

                {
                        me->add("weapon2/lv",30);
message_vision(MAG"突然一道金光打在$N身上，$N的第二把武器得到了300点攻击提升！\n"NOR, me);


                }              
                      
                        
               
                if (me->query("max_neili") >= 10000000)
                {
                        me->add("max_neili",1000000);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了一百万最大内力！\n"NOR, me);
                }
             else 
                 {
me->add("max_neili",2000000);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了二百万最大内力！\n"NOR, me);

}
 if (me->query("max_jingli") >= 3000000)
                {
                        me->add("max_jingli",300000);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了三十万最大精力！\n"NOR, me);
                }
             else 
                 {
me->add("max_jingli",500000);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了五十万最大精力！\n"NOR, me);

}
                
obj0 = new("/clone/gift/gift/karwan");
obj1 = new("/clone/gift/gift/neili");
obj2 = new("/clone/gift/gift/pantao");
obj3 = new("/clone/gift/gift/perwan");
obj4 = new("/d/gaochang/obj/youtan2");
obj5 = new("/clone/gift/gift/shenliwan");
obj6 = new("/clone/money/diamond");
obj7 = new("/clone/money/diamond");
obj8 = new("/clone/money/thousand-gold");
obj9 = new("/clone/money/thousand-gold");
obj0->move(me);
obj1->move(me);
obj2->move(me);
obj3->move(me);
obj4->move(me);
obj5->move(me);
obj6->move(box);
obj7->move(box);
obj8->move(box);
obj9->move(box);
                box->move(me);
                me->set("xinchun",1);
me->add("combat_exp",5000000);
me->add("potential",1000000);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了五百万点经验！\n"NOR, me);
message_vision(MAG"突然一道金光打在$N身上，$N的得到了一百万点潜能！\n"NOR, me);

                destruct(this_object());
        }
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
string query_autoload()
{ return 1 + ""; }
