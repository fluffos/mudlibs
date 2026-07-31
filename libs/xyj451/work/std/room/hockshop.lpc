// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hockshop.c
// modified by mon 2/28/98

inherit ROOM;

string *sell_msg = ({
     "破破烂烂，一文不值",
     "质地低劣，难看之极",
     "又脏又破，臭气熏天",
});

object shop_box;

int query_max_items() {return 50;}
string get_name(string str);

void init()
{
   add_action("do_value", "value");
   add_action("do_pawn", "pawn");
   add_action("do_sell", "sell");
   add_action("do_retrieve", "retrieve");
   add_action("do_buy", "buy");
   add_action("do_list", "list");
   add_action("do_quit", "quit");

   set("no_clean_up", 1);
}

// find the shopbox object for this shop to hold sold items.
object findbox()
{
    if(shop_box && environment(shop_box)==this_object()) 
      return shop_box;

    shop_box=new(__DIR__"shopbox");
    shop_box->move(this_object());
    return shop_box;
}

string value_string(int value)
{
   if( value < 1 ) value = 1;
   else if( value < 100 )
     return chinese_number(value) + "文钱";
   else
     return chinese_number(value/100) + "两白银"
        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)
{
   object ob;

   if( amount < 1 ) amount = 1;
   if( amount/100 ) {
     ob = new(SILVER_OB);
     ob->set_amount(amount/100);
     if(!ob->move(who))
       ob->move(environment(who));
     amount %= 100;
   }
   if( amount ) {
     ob = new(COIN_OB);
     ob->set_amount(amount);
     if(!ob->move(who))
       ob->move(environment(who));
   }
}

int do_value(string arg)
{
   object ob;
   int value, sale;

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要拿什么物品给当铺估价？\n");

   if( ob->query("money_id") )
     return notify_fail("这是「钱」，你没见过吗？\n");

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value) printf("%s一文不值。\n", ob->query("name"));
   else 
     printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s及一张当票。\n如果卖断(sell)，可以拿到%s。\n",
        ob->query("name"), value_string(value),
        value_string(value * 60 / 100), value_string(value * 80 / 100));

   return 1;
}

int do_pawn(string arg)
{
   object ob, stamp_ob;
   int value, sale;
   string obj_file;
   int  i;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要典当什么物品？\n");

   if( ob->query("money_id") )   return notify_fail("你要当「钱」？\n");

   if( ob->query("material") == "ice" )
     return notify_fail("掌柜的说：冰的东西我们这里没法存放。\n");
   //cuz ice melts, will cause problem, so disabled...weiqi, 970930.

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value || value < 10) return notify_fail("这样东西不值钱。\n");
        if(ob->query("no_sell"))
      return notify_fail("这样东西不能买卖。\n");

   write("掌柜的唱道："+ sell_msg[random(sizeof(sell_msg))] +
     ob->query("name") + "一" + ob->query("unit") + "，押"+
      value_string(value*60/100)+ "。\n");
   message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
     + value_string(value * 60 / 100) + "。\n", this_player());

        stamp_ob = new("/obj/stamps");

   stamp_ob->set_temp("file", ob);
   stamp_ob->set_temp("value", value*70/100);
   stamp_ob->set_temp("player", this_player()->query("id"));
   stamp_ob->set_temp("long_1", this_player()->name()+"典当" +
      ob->query("name") + "一" + ob->query("unit") +
      "讫，破烂缺损不堪。");
        stamp_ob->set_temp("long_2", "赎回应付"+
     value_string(value*70/100)+"整，一手交钱，一手交货。");

   this_player()->start_busy(1);
   pay_player(this_player(), value * 60 / 100);
   stamp_ob->move(this_player());

   //destruct(ob);
   ob->move(findbox());

   return 1;
}

int do_sell(string arg)
{
   object ob;
   int value, sale;
   string obj_file;
   int i, oldnum;
   string index;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要卖断什么物品？\n");

   if( ob->query("money_id") )   return notify_fail("你要卖「钱」？\n");
   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;
   if( !value ) return notify_fail("这样东西不值钱。\n");
        if(ob->query("no_sell"))
      return notify_fail("这样东西不能买卖。\n");

   if( ob->query("material") == "ice" )
     return notify_fail("掌柜的说：冰的东西我们这里没法存放。\n");
   //cuz ice melts, will cause problem, so disabled...weiqi, 970930.

   write("掌柜的唱道："+ sell_msg[random(sizeof(sell_msg))] +
     ob->query("name") + "一" + ob->query("unit") + "，当"+
      value_string(value*80/100)+ "。\n");
   message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
     this_player());

        index=ob->query("name")+"("+ob->query("id")+")";

   if(!findbox()->query_temp("goods/"+index) ){
           findbox()->set_temp("goods/"+index, ob);
      findbox()->set_temp("numbers/"+index, 1);
      ob->move(findbox());
   }
   else {
      oldnum = findbox()->query_temp("numbers/"+index);
           findbox()->set_temp("numbers/"+index, oldnum+1);
      destruct(ob);
   }

   this_player()->start_busy(1);
   pay_player(this_player(), value * 80 / 100);

   return 1;
}

int do_retrieve(string arg)
{
   object ob;
   int value, afford;
   object pawn_ob;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要赎回什么物品。\n");

   if( ob->query("id") != "pawn stamp")
      return notify_fail("你要用当票才能赎回物品。\n");

   value = ob->query_temp("value");
   if(!value) 
      return notify_fail("用空白当票来赎物，光天化日之下想打劫不成！\n");

   if( !(afford = this_player()->can_afford(value)) )  {
      return notify_fail("你没有足够的钱来赎回。\n");
   }
   else if( afford == 2 )
       return notify_fail("你没有足够的零钱，而银票又没人找得开。\n");

   if( ob->query_temp("player") != this_player()->query("id"))
      return notify_fail("又不是你当的，想趁火打劫啊！\n");

   pawn_ob = ob->query_temp("file");
   if(!pawn_ob) {
     destruct(ob);
     return notify_fail
       ("掌柜的惊道：糟糕！你要的东西找不着了。\n");
        }

   if(!pawn_ob->move(this_player())) return 0;
   destruct(ob);

   write("掌柜的唱道："+ sell_msg[random(sizeof(sell_msg))] +
     pawn_ob->query("name") + "一" + pawn_ob->query("unit") + "，赎银"+
      value_string(value)+ "。\n");
   message_vision("$N用当票赎回一"+pawn_ob->query("unit")+
      pawn_ob->query("name")+"。\n", this_player());

        this_player()->start_busy(1);
   this_player()->pay_money(value);
   this_player()->save();

    return 1;
}


int do_list(string arg)
{
   mapping goods;
   string list, *name;
   int i;
   string tlist;
   object me=this_player();

   if( !mapp(goods = findbox()->query_temp("goods")) )
     return notify_fail("当铺目前没有任何货物可卖。\n");
   name = keys(goods);
   if(!sizeof(goods)) 
     return notify_fail("当铺目前没有任何货物可卖。\n");

   if( !arg )   {
      list = "你可以购买下列这些东西：\n";
      write(list);
      i=sizeof(goods);
      while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
        //mon 2/4/98 because some items may destruct themselves
        //after being sold.

        tlist = get_name(name[i]);
        list = sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
          value_string(goods[name[i]]->query("value")),
          chinese_number(findbox()->query_temp("numbers/"+name[i])),
          goods[name[i]]->query("unit") );
              write(list);
      }
   }
   else if( arg == "book" )  {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }

           if( mapp(goods[name[i]]->query("skill")) )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "drug" )  {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("drug_type") )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "axe" || arg == "blade" || arg == "dagger" || 
   arg == "fork" || arg == "hammer" || arg == "spear" || arg == "mace" || arg == "rake" ||
   arg == "staff" || arg == "stick" || arg == "sword" || arg == "whip" ||
   arg == "throwing" )  {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }

      if( goods[name[i]]->query("skill_type") == arg )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "archery" )  {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("apply/skill_type") == arg )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "armor" || arg == "boots" || arg == "cloth" ||
    arg == "finger" || arg == "hands" || arg == "head" || arg == "neck" ||
    arg == "shield" || arg == "surcoat" || arg == "waist" ||
    arg == "wrists" )   {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("armor_type") == arg )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }
   else   {
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( member_array(arg, goods[name[i]]->parse_command_id_list()) != -1 )   {
           tlist = get_name(name[i]);
           list += sprintf("%-30s：%-20s：还剩%s%s\n", tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("当铺目前没有这种货品．\n");
      else {
   list = "你可以购买下列这些东西：\n"+list;
   me->start_more(list);
      }
   }

   return 1;
}


int do_buy(string arg)
{
   mapping goods;
   string *name;
   string fname;
   object obj_file, ob;
   int value, oldnum, afford, order;
   int i, j;
   object* inv;
   string arg1, arg2;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg )  {
      write("指令格式：buy <某物>\n");
      return 1;
   }

   // players are used to the "buy sth from sb" format.
   if( sscanf(arg, "%s from %s", arg1, arg2) == 2 )   {
     arg = arg1;
   }

   if( sscanf(arg, "%s %d", fname, order) != 2 )   {
     fname = arg;
     order = 1;
   }

   if( !mapp(goods = findbox()->query_temp("goods")) )
     return notify_fail("当铺目前没有任何货物可卖。\n");
   name = keys(goods);
   if(!sizeof(goods)) 
     return notify_fail("当铺目前没有任何货物可卖。\n");

   j = 0;
   i=sizeof(name);
   while(i--) {
          if(!goods[name[i]]) continue;
     if( member_array(fname, 
         goods[name[i]]->parse_command_id_list()) != -1 )  {
        j++;    
     }
     if( j == order )   {
       obj_file = goods[name[i]];
          value = obj_file->query("value"); 
          if( !(afford=this_player()->can_afford(value)) )  {
             write("你没有足够的钱。\n");
             return 1; 
          }
          else if( afford == 2 )  {
              write("你没有足够的零钱，而银票又没人找得开。\n");
             return 1;
          }

       ob = new( base_name( obj_file ) ); 
       ob->set_name(obj_file->query("name"),
         obj_file->parse_command_id_list());
         //so that the bought item would be the
         //same as the one on sale.

          if(!ob->move(this_player()))
         return 0;

          this_player()->start_busy(1);

       arg = obj_file->query("name")+
         "("+obj_file->query("id")+")";
          oldnum = findbox()->query_temp("numbers/"+arg);
          if(oldnum == 1)  {
              destruct(obj_file);
           findbox()->delete_temp("numbers/"+arg);
           findbox()->delete_temp("goods/"+arg);
          }
          else    {
           findbox()->set_temp("numbers/"+arg, oldnum-1); 
       }

          this_player()->pay_money(value);
     
          message_vision("$N向当铺买下一" +
        ob->query("unit") + ob->query("name") + "。\n", this_player() );

       this_player()->save();
       return 1;
     }
   }

   write("当铺里没有这种货品。\n");

   return 1;
}

int do_quit()
{
   this_player()->move("/cmds/std/quitroom");
   return 1;
}

// no clean up at hockshop to prevent items lose.
int clean_up()  
{
      return 0;
}

// strip away ansi color code.
// mon 5/7/98
string get_name(string str)
{
    string str1, str2;

    while(sscanf(str,"%s%*sm%s",str1,str2)==3)
   str=str1+str2;
    return str;
}
