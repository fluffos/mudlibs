
// blacksmith.c 修理师傅
#include <ansi.h>
inherit NPC;

int check_money(object me, int amount);
void pay_him( object me, int amount);

void create()
{
            set_name("铁匠", ({ "blacksmith" }) );
            set("long","修破烂的。如果你的道具破损了。那么就尽管来找他吧。\n");

                set("age", 14);
                set("attitude", "friendly");

                set("max_gin", 2000);
                set("max_kee", 3000);
                set("max_sen", 1000);

                set("str", 110);
                set("cor", 40);
                set("spi", 40);
                set("int", 60);

        set("force",800);
        set("max_force",800);

                set("combat_exp", 1000);
          
                setup();
                carry_object("/clone/misc/cloth");
                       
}
void init()
{       
                object me;
                me=this_player();
if(interactive(me)&&!this_object()->is_fighting())      
                call_out("greeting",1,me);
                add_action("do_repair","repair");
}

void greeting(object me)
{
                command("say 想修理武器吗？来找我好了，包准修的就象新的一样！！！");
                command("say 修理费用很便宜的哟(repair)。。。。。。");
}

int do_repair(string arg)
{
        int item_value,now_damage,cost,remain_money,lost_prop;
                object me,item;
                me=this_player();
if(!arg)
                return notify_fail("你想要修理什么啊？\n");
                item=present(arg,me);
if(!item)
                return notify_fail("你没有这样东西啊？\n");
if(item->type()!="weapon")
                return notify_fail("对不起。。。我只会干我的老本行---修理武器！\n");
                now_damage=item->query("weapon_prop/damage");
                lost_prop=item->query("lost_prop");
if(lost_prop<=0)
                return notify_fail("你的"+item->name()+"好好的，修什么修啊？\n");
                item_value=item->query("value");
if(item_value<=100)
                return notify_fail("这东西不值钱，我不修.\n");                 

                cost=item_value/(lost_prop+now_damage)*lost_prop*3/4;

                write("修理费用费用是"+cost+" coin\n",me);

if((remain_money=check_money(me,cost))<=0)

                return notify_fail("你没有这么多钱");

else    
                pay_him(me,remain_money);

                item->unequip();
                item->set("weapon_prop/damage",lost_prop+now_damage);
                item->delete("lost_prop");
            return 1;                   
}


void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


        if( amount < 1 ) amount = 1;
        if( amount/100000 ) {
                ob = new("/obj/money/thousand-cash");
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int check_money(object me, int amount)
{
        int remain,total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total-amount;
}


