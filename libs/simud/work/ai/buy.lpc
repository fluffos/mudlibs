inherit "/ai/module";

string accepted_issue;

string query_accepted_currency() {
   if (accepted_issue == 0) {
      return "united states";
   }
   return accepted_issue;
}

string query_module_name() {
   return "buy";
}

void on_buy( string item, object buyer ) {
   object *boxlist;
   object box;
   object *goods;
   object ob;
   object player_ob;
   object *buyer_coin;
   int    price, units, buyer_value;
   string cost = " costs ";

   boxlist = filter( all_inventory(environment(environment())), (: $1->query_is_buy_box() :) );
   foreach( ob : boxlist ) {
      goods = all_present( item, ob );
      if( goods ) {
         box = ob;
         break;
      }
   }
   if( box ) {
      int quantity;

      foreach( ob : goods ) {
         if( ob->query_quantity() )
            quantity += ob->query_quantity();
         else
            quantity++;
      }

      price = box->query_price();
      units = box->query_units();
      if( units > 1 && quantity % units != 0 ) {
         command( "say to " + buyer->query_name() +  " Sorry, I only sell that " + units + " at a time.", environment() );
         return;
      }
      if( units <= 0 ) units = 1;
      if( quantity > 1 ) {
         price = quantity * price / units;
         cost  = " cost ";
      }
      command( "say to " + buyer->query_name() +  " " +
         capitalize(inventory_string(goods)) + " cost "+
         "/daemon/currency"->format_currency(
            price,query_accepted_currency()
         ) + ".", environment()
      );

      buyer_coin = filter( all_inventory(buyer), (: $1->query_is_money() && $1->query_issuing_government() == query_accepted_currency() :) );
      buyer_value = "/daemon/currency"->query_total_value(buyer_coin);
      // player has EXACTLY enough money to buy the item
      if( buyer_value == price ) {
         buyer->msg_local("~CACT~Name ~verbhand over ~poss last penny in exchange for "+
                          inventory_string(goods) + ".~CDEF");
         foreach( ob : buyer_coin )
            ob->move(environment());
         foreach( ob : goods )
            ob->move(buyer);
         return;
      } else
      // player has more money than needed, therefore we had better get some change
      if( buyer_value > price ) {
         // give all of the player's money to the shopkeeper ;)
         foreach( ob : buyer_coin )
            ob->move(environment());
         // calculate change from the shopkeeper's total cash
         buyer_coin = "/daemon/currency"->make_change( buyer_value - price,
                                                       query_accepted_currency(),
                                                       all_inventory(environment()) );
         if( pointerp(buyer_coin) ) {
            set_target(environment());
            buyer->msg_local("~CACT~Name and ~targ exchange coins and "+
                          inventory_string(goods) + ".~CDEF");
            foreach( ob : buyer_coin + goods )
               ob->move( buyer );
         } else {
            set_target(buyer);
            environment()->msg_local("~CACT~Name ~verbblush furiously as ~pron ~verbrealize that "+
                                     "~pron ~verbis unable to make change for ~npot purchase.~CDEF");
            buyer_coin = "/daemon/currency"->make_change( buyer_value, query_accepted_currency(),
                                                          all_inventory(environment()) );
            foreach( ob : buyer_coin )
               ob->move( buyer );
         }
         return;
      } // end: player has more than enough money
      /**
       * Old way of handling money assumes that all coins are the same value
       *
      foreach( player_ob : all_inventory(buyer) ) {
         if( player_ob->query_is_money() && player_ob->query_value() >= price ) {
            buyer->msg_local("~CACT~Name ~verbhand over the coins in exchange for " +
                             inventory_string(goods) + ".~CDEF");

            player_ob->split_quantity(price);
            player_ob->move(environment());
            foreach( ob : goods )
               ob->move(buyer);
            return;
         }
      }
      */
      buyer->msg_local("~CACT~Name ~verbrummage through ~npos pockets " +
                       "for the coins, but ~verbcome up short.~CDEF");
      set_target(buyer);
      environment()->msg_local("~CACT~Name ~verbglare at ~targ and ~verbturn away.~CDEF");
   }
   else {
      command( "say to " + buyer->query_name() + " I'm afraid we don't have that for sale here.", environment() );
   }
}

void on_sell( string item, object seller ) {
   object *boxlist;
   object box;
   object good;
   object ob;
   object money_ob;
   object *buyer_coin;
   int    price, units, buyer_value;

   good = single_present( item, seller );

   if( !good ) {
      command( "say to " + seller->query_name() + " You don't seem to have that on you. You can't sell what you don't have!", environment() );
      return;
   }

   boxlist = filter( all_inventory(environment(environment())), (: $1->query_is_sell_box() :) );
   box = 0;
   foreach( ob : boxlist ) {
      object istuff;
      foreach( istuff: all_inventory(ob) )
      if( load_name(istuff) == load_name(good) ) {
         box = ob;
         break;
      }
      if( box ) break;
   }
   if( box ) {
      price = -box->query_price();
      units = box->query_units();

      if( units > 1 && good->query_quantity() % units != 0 ) {
         command( "say to " + seller->query_name() +  " Sorry, I only buy that " + units + " at a time.", environment() );
         return;
      }

      if( units <= 0 ) units = 1;
      if( good->query_quantity() > 1 ) {
         price = good->query_quantity() * price / units;
      }

      command( "say to " + seller->query_name() +  " I'll buy " +
         good->query_specific() + " for " +

      "/daemon/currency"->format_currency(price,query_accepted_currency()) + ".", environment() );

      buyer_coin = filter(
         all_inventory(environment()), (: $1->query_is_money() &&
         $1->query_issuing_government() == query_accepted_currency() :)
      );

      buyer_value = "/daemon/currency"->query_total_value( buyer_coin );
      debug( "shopkeeper has " + buyer_value + " worth of money", "ai" );

      if (buyer_value >= price) {
         buyer_coin = "/daemon/currency"->make_change(price, query_accepted_currency(), buyer_coin);

         if (buyer_coin) {
            command( "say to " + seller->query_name() + " Pleasure doing business with you.", environment() );

            foreach( object coin : buyer_coin ) {
               coin->move( seller );
            }
            good->move( box );
            return;
         }
      }
      command( "say to " + seller->query_name() + " Oh, I'm short on cash! Try again later.", environment() );
   }
   else {
      command( "say to " + seller->query_name() + " I'm afraid we don't buy those from you here.", environment() );
   }
}

int is_owner() {
}

int trusts(object actor) {
   return environment()->query_trust(lower_case(actor->query_name()));
}

void on_talk( string text, object actor, object target ) {
   if( target != environment() ) return;
   if( strstr(text, "payout") >= 0 ) {
      if( actor->query_name() == environment(environment(environment()))->query_owner()
         || trusts(actor)
      ) {
         object *money;
         money = filter( all_inventory(environment()), (: $1->query_is_money() :) );
         if( sizeof(money) ) {
            object ob;
            foreach( ob : money )
               ob->move(actor);
            set_target( actor );
            environment()->msg_local("~CACT~Name ~verbgive ~targ " + inventory_string(money) + ".~CDEF" );
         }
         else {
            command( "say to " + actor->query_name() + " Sorry, haven't got anything to give you.", environment() );
         }
      }
      else command( "say to " + actor->query_name() + " You're not the owner of this shop.", environment() );
   }
   if( strstr(text, "help") >= 0) {
      if( actor->query_name() == environment(environment(environment()))->query_owner()
         || trusts(actor)
      ) {
         command( "say to " + actor->query_name() + " You can tell me to 'payout' any money I have, 'accept' a currency type, or you can 'give' me coins.", environment() );
      } else {
         command( "say to " + actor->query_name() + " Use money to buy stuff, get money by selling stuff.  Simple, no?  See 'help money' for more information.", environment() );
      }
   }
   if( strstr(text, "accept") >= 0 ) {
      if( actor->query_name() == environment(environment(environment()))->query_owner()) {
         string issue;

         if (sscanf(text, "accept %s", issue)) {
            int ok;
            switch(lower_case(issue)) {
            case "us":
            case "dollar":
            case "dollars":
            case "united states":
               issue = "united states";
               ok = 1;
               break;
            case "default":
               issue = 0;
               ok = 1;
               break;
            default:
               ok = 0;
            }

            if (ok) {
               accepted_issue = issue;
               switch(issue) {
               case "united states":
                  issue = "United States Dollars ($)";
                  break;
               }
               command( "say to " + actor->query_name() + " Ok, I'll now accept " + issue, environment() );
            } else {
               command( "say to " + actor->query_name() + " I've never even heard of those", environment() );
            }
         }
         else command( "say to " + actor->query_name() + " Huh?", environment() );
      }
      else command( "say to " + actor->query_name() + " you're not the owner of this shop.", environment() );
   }
}

void on_offer( object *offer, object giver ) {
   if( giver->query_name() != environment(environment(environment()))->query_owner() ) {
      command( "reject", environment() );
      return;
   }
   if( sizeof(offer) == 1 && offer[0]->query_is_money() ) {
      command( "accept", environment() );
      return;
   }
   command( "reject", environment() );
}
