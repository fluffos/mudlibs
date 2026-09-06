string *query_issues() {
   return ({ "united states" });
}

/**
 * Sum the values of objects listed.
 */
int query_total_value(object *list) {
   int total = 0;
   object ob;
   foreach( ob : list ) {
      total += ob->query_value();
   }
   return total;
}

/**
 * Used to sort arrays into descending order by individual value of
 * its elements.
 */
int sort_by_value(object a, object b) {
   return (a->query_value() / max(a->query_quantity(),1)) <
         (b->query_value() / max(b->query_quantity(),1));
}

/**
 * This function returns correct change generated out of the listed objects,
 * if possible. If not, then it will return null. Either way, this method is
 * heinously expensive and slow and stuff, so be careful, ne? :)
 *
 * If it becomes too much of a problem, we might have to move it elsewhere...
 *
 * For example:
 *   make_change(73, "united states", ({a whole bunch of money}) )
 * might return:
 *   ({ 2 quarters, 2 dimes, 3 pennies })
 *
 * \param amt integer value amount desired
 * \param issue string describing currency type
 * \param list list of coins to choose from
 */
object *make_change(int amt, string issue, object *list) {
   object ob, coin, *change = ({ });
   mapping values = ([]);
   int sum = 0;
   list = filter( list, (: $1->query_is_money() && $1->query_issuing_government() == issue :) );
   if( !sizeof(list) )
      return 0;
   list = sort_array(list, "sort_by_value");
   // populate value table for a really minor efficiency boost
   foreach( ob : list )
      values[ob] = ob->query_value() / max(ob->query_quantity(),1);
   // enter the evil loop
   while( sum != amt ) {
      coin = 0;
      // find biggest remaining coin
      foreach( ob : list ) {
         if( values[ob] <= amt - sum ) {
            int qty = (amt - sum) / values[ob];
            values -= ([ ob ]);
            list -= ({ ob });
            ob->split_quantity( qty );
            ob->set_player_lock(this_player());
            change += ({ ob });
            sum += ob->query_value();
            coin = ob;
            break;
         } else {
            // ignore things we can't use ;)
            list -= ({ ob });
         }
      }
      // if we didn't find anything...
      if( !coin ) {
         debug("make_change was unable to find a solution");
         return 0;
      }
   }
   return change;
}

string sprint_value(int units, string issue)
{
   debug("Fix " + object_name(previous_object()));

   return units + " coins";
}

string format_currency(int units, string issue) {
   switch(issue) {
   case 0:
      return units + " coins";

   case "united states":
      {
         int dollars;
         int cents;

         dollars = units / 100;
         cents = units % 100;

         if (dollars) {
            return sprintf("$%d.%02d", dollars, cents);
         } else {
            return cents + " cents";
         }
      }

   default:
      debug("Unknown issue: " + issue);
      return units + " " + issue + " coins.";
   }
   return "flibertigibbet";
}
