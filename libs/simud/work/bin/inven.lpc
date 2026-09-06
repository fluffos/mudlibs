int US_WEIGHT(int x) {
   return (int) (x * 0.0022);
}

int main(string arg) {
   object ob, *oblist, *held, *worn, *weaplist, *armlist, *money;
   string istr;
   int weight;

   if (arg && (this_player()->query_level() >= WIZLEVEL)) {
      sscanf(arg,"%s@%s", arg, arg);
      if (!ob = find_player(arg)) {
         msg(capitalize(arg)+" was not found.");
         return 1;
      }
   } else
      ob = this_player();

   oblist = all_inventory(ob);
   weaplist = ({ });
   armlist = ({ });
   held = ({ });
   worn = ({ });
   money = ({ });

   foreach( ob : oblist ) {
      if(!ob->query_gettable()) {
         oblist -= ({ ob }); //Added to remove daemons from inventories.
      }
      weight += ob->query_total_weight();
      if( ob->query_held() ) {
         oblist -= ({ ob });
         held += ({ ob });
      }
      else if( ob->query_worn() ) {
         oblist -= ({ ob });
         worn += ({ ob });
      }
      else if( ob->query_weapon() ) {
         oblist -= ({ ob });
         weaplist += ({ ob });
      }
      else if( ob->query_armour() ) {
         oblist -= ({ ob });
         armlist += ({ ob });
      }
     else if( ob->query_is_money() ) {
         oblist -= ({ ob });
       money += ({ ob });
      }
   }

   if (arg && (this_player()->query_level() >= WIZLEVEL))
      msg("~CTITInventory of " + capitalize(arg) + "~CDEF");
   else
      msg("~CTITInventory~CDEF");

   istr = inventory_string( held );
   if( istr != "" )
      msg("~CBRT Holding~CDEF: " + capitalize(istr), 10);

   istr = inventory_string( worn );
   if( istr != "" )
      msg("~CBRT    Worn~CDEF: " + capitalize(istr), 10);

   istr = inventory_string( weaplist );
   if( istr != "" )
      msg("~CBRT Weapons~CDEF: " + capitalize(istr), 10);

   istr = inventory_string( armlist );
   if( istr != "" )
      msg("~CBRT  Armour~CDEF: " + capitalize(istr), 10);

   istr = inventory_string( oblist );
   if( istr != "" )
      msg("~CBRT   Items~CDEF: " + capitalize(istr), 10);

   istr = inventory_string( money );
   if( istr != "" ) {
      string *issues;
      msg("~CBRT   Money~CDEF: " + capitalize(istr), 10);

      issues = "/daemon/currency"->query_issues();

      foreach( string issue: issues ) {
         object *lmoney = filter( money, (:
            $1->query_issuing_government() == issue :)
         );
         if( sizeof( lmoney ) )
            msg("~CCOM   Value~CDEF: " + "/daemon/currency"->format_currency(
            "/daemon/currency"->query_total_value(lmoney), issue)
         );
      }
   }
   //Added oblist here, in case they're carrying stuff, but not holding
   //Snarky - 1/6/06
   if( !sizeof(oblist+held+worn+weaplist+armlist) && istr == "" )
      msg("You aren't carrying anything at all.");
   else if (weight)
      msg("~CCOM Carried~CDEF: " + US_WEIGHT(weight) + "/" + US_WEIGHT(this_player()->query_weight_capacity()) + " lbs");

   return 1;
}
