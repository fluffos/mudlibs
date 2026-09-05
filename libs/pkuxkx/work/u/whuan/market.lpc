
#include <ansi.h>
inherit "/u/whuan/std/hockshop";


void create ()
{
  set ("short", "跳蚤市场");
  set ("long", @LONG

这儿是长安的二手市场，市民们可以来这儿拍卖(sellgoods)自己
的物品，或是购买(buygoods)他人的拍卖物品，如果你不想继续
拍卖，可以取回(pickback)它，用list看拍卖中的物品。
注意：这里结算都是以xlqy中最小结算单位即coin进行。
LONG);

  set("exits", ([ 
       "up" : __DIR__"droproom",
]));

  set("objects", ([ 
]));
  set("no_fight",1);
  setup();
}

void init()
{
	add_action("do_sell", "sellgoods");
	add_action("do_pickback", "pickback");
	add_action("do_buy", "buygoods");
	add_action("do_list", "list");
       add_action("block_cmd","",1);
	set("no_clean_up", 1);

}

int do_sell(string arg)
{
       object *goods;
       int number, i;
       object ob;
       string item;
	int price;
	int dest;
	int destroy_after_sell;

  if( !arg || sscanf(arg, "%s at %d", item, price)!=2 )
                return notify_fail
("指令格式：sellgoods <物品id> at <价格>\n");

       if( !(ob = present( item, this_player())) )
		return notify_fail("你要拍卖什么物品？\n");

	if( this_player()->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");

       goods = all_inventory(findbox());
       number = sizeof(goods);

       while(number--){
              if(goods[number]->query("deal_owner")==this_player()->query("id"))
              i++;
       }
      
       if( i >=5)
              return notify_fail("小狗狗说：每个玩家最多只能拍卖五件物品！\n");

       if( ob->is_character() )
                return notify_fail("你怎么能把活物卖来卖去的？\n");
       if( ob->is_corpse()|| ob->query("is_skeleton"))
                return notify_fail("连尸体都卖，没人性啊！\n");

 	if( ob->query("no_give") )
		return notify_fail("这种东西不能拍卖！\n");

	if( ob->query("material") == "ice" )
		return notify_fail("小狗狗说：冰的东西我们这里没法存放。\n");
       if( price > 3000000)
              return notify_fail("小狗狗说：卖那么贵，你太黑心了！\n");

	destroy_after_sell=ob->query_temp("destroy_after_sell");

	if(destroy_after_sell) {
	    ob->move(findbox());
	    dest=1;
	} else {
          ob->set("deal_owner",this_player()->query("id"));
          ob->set("deal_price",price);
	   ob->move(findbox());
        }

	write("小狗狗说：知道了，你的"+ob->query("name")+"卖"+value_string(price)+"！\n");

	if(dest) {
          write("小狗狗说：我怀疑这个东西是易燃易爆品，没收了！\n");
	   destruct(ob);
      }
	this_player()->start_busy(1);
	return 1;
}



int do_list(string arg)
{
   object* goods;
   string list, tlist;
   int i, number;
   object me=this_player();

   goods = all_inventory(findbox());
   number = sizeof(goods);

   //消灭无主物
   for(i=0; i<number;i++){
              if(!goods[i]->query("deal_owner")) { 
                     destruct(goods[i]);
              }
   }

   goods = all_inventory(findbox());
   number = sizeof(goods);

   if(!number) 
       return notify_fail("跳蚤市场目前没有在拍卖任何物品。\n");
   
   list = "你可以购买下列这些东西：\n";
   for(i=0; i<number; i++)  {
              goods[i]->set_temp("index",i);
		tlist = sprintf("%d  %s(%s)", i, goods[i]->query("name"), goods[i]->query("id"));
		tlist = sprintf("%-30s：%s", tlist,
			value_string(goods[i]->query("deal_price")));
		list += sprintf("%-60s：%s\n", tlist,
			goods[i]->query("deal_owner"));
   }
   write(list);
   return 1;	
}


int do_buy(string arg)
{
   object* goods;
   int afford, i, number, price;
   object who, ob;
   string owner;
   string item;

  if( this_player()->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

  if( !arg || sscanf(arg, "%d %s from boss", i, item)!=2 )
                return notify_fail
("指令格式：buygoods <序号> <物品id> from boss\n");

   goods = all_inventory(findbox());
   number = sizeof(goods);

   if( !number ){
	  return notify_fail("跳蚤市场目前没有任何物品可卖。\n");
   }

   if( i >= number||i<0)
         return notify_fail("你输入的序号不正确，请重新list看一下序号！\n");

   ob = goods[i];
   if(ob->query("id")!=item)
         return notify_fail("你输入的序号与对应的物品不符，请重新list看一下！\n");

   price = ob->query("deal_price"); 
   if( !(afford=this_player()->can_afford(price)) )  {
	          write("你没有足够的钱。\n");
	          return 1; 
   }
   else if( afford == 2 )  {
              write("你没有足够的零钱，而银票又没人找得开。\n");
	          return 1;
   }

    owner = ob->query("deal_owner");
    who = find_player(owner);
    if( !who )       who = find_living(owner);
   if(who) {
   	this_player()->pay_money(price);
       who->add("balance",price);
       tell_object(who,"你在跳蚤市场的"+ob->query("name")+"卖了"+value_string(price)+"，所得存入了你的钱庄帐户中！\n");
   }
   ob->move( this_player() );
   message_vision("$N向小狗狗买下一" +
          ob->query("unit") + ob->query("name") + "。\n", this_player() );
   if(!who)
          message_vision("小狗狗对$N说：主人失踪了，这件商品的钱你就不用付了！\n",this_player() );

   this_player()->save();

   if(ob){
   	ob->delete("deal_owner");
   	ob->delete("deal_price");
   	ob->delete_temp("index");
   }
   return 1;
}


int do_pickback(string arg)
{
   object* goods;
   int afford, i, number, price;
   object who, ob;
   string owner;

  if( this_player()->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

   if( !arg )  {
	   write("指令格式：pickback <序号>\n");
	   return 1;
   }

   goods = all_inventory(findbox());
   number = sizeof(goods);

   if( !number ){
	  return notify_fail("跳蚤市场目前没有任何物品。\n");
   }
   i = to_int(arg);

   if(i==0&&arg!="0"){
    write("指令格式：pickback <序号>\n");
	   return 1;
   }

   if( i >= number|| i<0)
         return notify_fail("你输入的序号不正确，请重新list看一下序号！\n");

   ob = goods[i];
   if(ob->query("deal_owner")!=this_player()->query("id"))
         return notify_fail("那件不是你的物品！\n");

   ob->move( this_player() );
   message_vision("$N向小狗狗取回了一" +
          ob->query("unit") + ob->query("name") + "。\n", this_player() );
   this_player()->save();

   if(ob){
   	ob->delete("deal_owner");
   	ob->delete("deal_price");
   	ob->delete_temp("index");
   }
   return 1;
}

int block_cmd()
{
        string verb = query_verb(); 
        if (verb=="exert") return 1;
        if (verb=="bian") return 1;
        if (verb=="cast") return 1;
        if (verb=="drop") return 1;
        if (verb=="scan") return 1;
        if (verb=="sell") return 1;
        if (verb=="buy") return 1;
        if (verb=="retrieve") return 1;
        if (verb=="pawn") return 1;
        return 0;
}

