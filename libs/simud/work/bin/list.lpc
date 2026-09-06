int main() {
   object ob, shopkeeper, *coins;
   int price;
   string obname;
   string issue;
   mapping buy_list, sell_list, buyavailable, sellavailable, buy_units, sell_units;

   buy_list = ([ ]);
   sell_list = ([ ]);
   buyavailable = ([ ]);
   sellavailable = ([ ]);
   buy_units = ([ ]);
   sell_units = ([ ]);

   shopkeeper = single_present("shopkeeper", environment(this_player()) );

   if (shopkeeper) {
      object ai;

      ai = single_present("_ai_buy", shopkeeper);

      if (ai) {
         issue = ai->query_accepted_currency();
      } else {
         debug("Couldn't get buy ai");
         return notify_fail("Something has gone wrong with this shopkeeper, call a wizard.\n");
      }
   } else {
      return notify_fail("This doesn't look like a shop to me...\n");
   }

   // go through all the price crates and get objects to buy/sell
   foreach( ob : all_inventory(environment(this_player())) ) {
      object cont;

      if( !ob->query_is_buy_box() && !ob->query_is_sell_box() ) continue;

      foreach( cont : all_inventory(ob) ) {
         string name = cont->query_name();
         if( cont->query_container() ) {
            object tmp = first_inventory(cont);
            if (tmp)
               name += " of "+tmp->query_distant();
            else
               name = "empty "+name;
         }
         if( ob->query_price() > 0 ) {
            buy_list += ([ name : ob->query_price() ]);
            if( cont->query_quantity() == 0 )
               buyavailable[name]++;
            else
               buyavailable[name] += cont->query_quantity();
            buy_units[name] = ob->query_units();
         } else {
            sell_list += ([ name : ob->query_price() ]);
            sell_units[name] = ob->query_units();
            if( cont->query_quantity() == 0 )
               sellavailable[name]++;
            else
               sellavailable[name] += cont->query_quantity();
         }
      }
   }
   if( !sizeof(buy_list) && !sizeof(sell_list) )
      return notify_fail( "Nothing to buy or sell here.\n" );

   int sale_printed = 0;

   msg("    ~CLABPrice    ~[060|  ~CLABQty  ~[060| ~CLABItem  ~CTIT");
   foreach( obname : sort_array(m_indices(buy_list), (: buy_list[$1] * buy_units[$2] < buy_list[$2] * buy_units[$1] :)) ) {
      price = buy_list[obname];
      if( price < 0 ) continue;
      if( !sale_printed ) msg("~CTITFor Sale~[060     |       |");
      sale_printed = 1;
      if (buyavailable[obname] > 99999)
         buyavailable[obname] = 99999;
      msg( "~CDEF" + pad("/daemon/currency"->format_currency(price, issue)
         + (buy_units[obname]>1?"/" + buy_units[obname]:""),12,JUST_RIGHT) + " ~[060|~CDEF" +
           pad(buyavailable[obname],6,JUST_RIGHT) + " ~[060|~CDEF " +
           capitalize(obname) + "~CDEF");
   }
   sale_printed = 0;
   foreach( obname : sort_array(m_indices(sell_list), (: sell_list[$1] * sell_units[$2] > sell_list[$2] * sell_units[$1] :)) ) {
      price = sell_list[obname];
      if( price > 0 ) continue;
      if( !sale_printed ) msg("~CTITWe Purchase~[060  |       |");
      sale_printed = 1;
      if (sellavailable[obname] > 99999)
         sellavailable[obname] = 99999;
      msg( "~CDEF" + pad("/daemon/currency"->format_currency(-price, issue) + (sell_units[obname]!=1?"/" + sell_units[obname]:""),12,JUST_RIGHT) + " ~[060|~CDEF" +
           //tab(" ",6) + " ~[060|~CDEF " +
           pad(sellavailable[obname],6,JUST_RIGHT) + " ~[060|~CDEF " +
           capitalize(obname) + "~CDEF");
   }

   coins = filter(all_inventory(shopkeeper), (: $1->query_is_money() && $1->query_issuing_government() == issue :));
   if( sizeof(coins) ) {
      coins = sort_array(coins, "sort_by_value", "/daemon/currency");
      msg("~CTITChange: ~CLAB"+"/daemon/currency"->format_currency(
         "/daemon/currency"->query_total_value(coins), issue)+
         "~CDEF ("+inventory_string(coins)+")", 8
      );
   } else {
      msg("~CTITChange: ~CDEFnone on hand, buy something, will ya?");
   }
   return 1;
}
