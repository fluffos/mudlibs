// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Modified by iszt@pkuxkx, 2007-03-24, adjusted ansi align
// Modified by iszt@pkuxkx, 2007-05-03, do_buy() shows names in ob_file
// Modified by whuan@pkuxkx, 2007-08-26 , special "sociability" have 20% discount to buy everything
#include <dbase.h>

string is_vendor_good(string arg)
{
        string *goods;
        object ob;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg))
                                return goods[i];
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要估什么的价？\n");

        if (ob->query("money_id"))
                return notify_fail("你没用过钱啊？\n");

        if ( ob->query_amount()>0 )
          value = ob->query("value")*ob->query_amount();
        else
          value = ob->query("value");
        if (value < 1)
                write(ob->query("name") + "一文不值！\n");
        else
                write(ob->query("name") + "值" + 
                MONEY_D->price_str(value * 70 / 100) + "。\n");
        return 1;
}

int do_list()
{
        string *goods;
        object *inv;
        int i;
        int len;
        string name;

        inv = all_inventory(this_object());

        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("目前没有可以卖的东西。\n");

        printf("你可以向%s购买下列物品：\n", query("name"));
        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                {
                        if ( goods[i]->query_amount()>0 )
                          name = goods[i]->name() + "(" + capitalize(goods[i]->mask_id()) + ")";
                        else
                          name = goods[i]->short();
                        len = 30 + COLOR_D->color_len(name);
                        if ( goods[i]->query_amount()>0 )
                          printf("%"+len+"-s：%s\n", name,
                                  (goods[i]->price(this_player()))?MONEY_D->price_str(goods[i]->price(this_player())):MONEY_D->price_str(goods[i]->query("value")*goods[i]->query_amount()));
                        else
                          printf("%"+len+"-s：%s\n", name,
                                  (goods[i]->price(this_player()))?MONEY_D->price_str(goods[i]->price(this_player())):MONEY_D->price_str(goods[i]->query("value")));
                }
        return 1;
}

int do_buy(string arg)
{
        int value, val_factor, i, rt;
        string ob_file;
        string obj, obj2;
        object ob;
        int num;
       
        if (!arg)
                return notify_fail("你想买什么？ \n");

        if (sscanf(arg, "%s %d",obj, num) != 2)
        {
        	if ( sscanf(arg, "%s %s %d",obj,obj2,num) != 3 )
        	{
                obj = arg;
                num = 1;
          }
          else
          	obj=sprintf("%s %s",obj,obj2);
        }

                if ((ob_file = is_vendor_good(obj)) == "")
                        return notify_fail("你想买什么？ \n");
        if (num>100) 
                return notify_fail("太多了，你拿得了吗？\n");

        if (num<1) 
                return notify_fail("你到底想不想买啊？打定主意再说！\n");
        if (!ob) {
                ob = new(ob_file);
                val_factor = 10;
                if (this_player()->query("special_skill/sociability"))
                val_factor = 8 ;
        }
        else {
                if (ob->query("equipped"))
                        return notify_fail("你想买什么？ \n");
                if (num > 1) 
                        return notify_fail("对不起，这东西一次只卖一个。\n");
                val_factor = 12;
                if (this_player()->query("special_skill/sociability"))
                val_factor = 10 ;
        }

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
        
        if ( ob->query_amount()>0 )
          rt=MONEY_D->player_pay(this_player(), ((ob->price(this_player()))?ob->price(this_player()):ob->query("value")*ob->query_amount()) *  val_factor * num / 10);
        else
          rt=MONEY_D->player_pay(this_player(), ((ob->price(this_player()))?ob->price(this_player()):ob->query("value")) *  val_factor * num / 10);
        switch (rt) {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                set_temp("busy", 1);
                for (i=1;i<=num;i++)
                {
                        if (i!=1)
                                ob = new(ob_file);
                        ob->set_temp("from_dealer",1);
						if (ob->npc_only())
						ob->set_temp("buyer",this_player());
                        ob->move(this_player());
                }
                if (this_player()->query("special_skill/sociability"))
                message_vision("$N巧舌如簧，从$n那里获得了八折的优惠！\n", this_player(), this_object());	
                message_vision("$N从$n那里买下了" + CHINESE_D->chinese_number(num) + ob_file->query("unit") + 
                ob_file->query("name") + "。\n", this_player(), this_object());

        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

