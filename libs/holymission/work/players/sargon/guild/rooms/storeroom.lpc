/* ############################ STORE (c) Rudi ############################# */
/* ############################ as GenObj (c) Rudy ######################### */

#define TO              (this_object())
#define TP              (this_player())
#define TPN             (TP->query_name())
#define TPM             (TP->query_money())
#define MAX_SELL_VALUE  (1300)

/*#define min( a, b )     ( a < b ) ? ( (a) : (b) )*/

inherit "room/room";

string trader;
string info;

object sortedInv;                                   /* needed to sort */

clean_up() {}

reset( arg )
{
   ::reset( arg );
   short_desc="Generic Storeroom";
   long_desc="This is the"+short_desc;
}

#if 0
init( arg )
{
   ::init( arg );
   
}
#endif

/* ##################################  sort ######################################### */

holy_sort()
{   
   int    i, j, mark;
   object swap;
   object *temp;
  
#if 0 
   sortedInv = all_inventory(TO);
   
   i = 0;
   while ( i < sizeof( sortedInv ) - 1 ) {
      j = i + 1;
      mark = i;
      while ( j < sizeof( sortedInv ) ) {
         if ( sortedInv[j]->short() < sortedInv[mark]->short() )
            mark = j;
         j++;
      }
      if ( mark != i ) {
         swap = sortedInv[mark];
         sortedInv[mark] = sortedInv[i];
         sortedInv[i] = swap;
      }
      i++;
   }
  
#else 
#if 1
   temp=all_inventory(TO);
   sortedInv = sort_array( temp, "less", TO );
#else
  sortedInv=all_inventory(TO);
#endif
#endif
   
}

int less(object obj1, object obj2)
{
   if ( !(obj1->short()) || !(obj2->short()) ) {
      log_file( "sargon.rep", "ERROR IN THE LESS-FUN, NO SHORT !!!\n" );
      return 0;
   }

  return ((string)(obj1->short()) < (string)(obj2->short()));

}

/* ##################### lister ######################################## */
    
         
         
read(arg)
{
  object item;
  int i,j,num,pieces;
  
  holy_sort();

  num = 0; j = 0;
  
  if ( !arg )
     return;
     
  if ( arg == "sign" || arg == "the sign" ) {
     if ( !sortedInv || !sizeof(sortedInv) ) {
        printf("Sorry, but the store is empty at this time.\n");
        return 1;
      }

      write("\nNr:   " + listing( info()+":", 31 ) + " Trade-Base: Stock:\n");
      write("------------------------------------------------------------------------\n");
      i = 0;  
      while ( i < sizeof( sortedInv ) ){
         pieces=1;
         num++;
         j=i+1;
         while (j< sizeof(sortedInv) && sortedInv[i]->short() == sortedInv[j]->short()) {
            pieces++;
            j++;
         }
                         
         write("\n"+listing((num),4)+"  "+listing(sortedInv[i]->short(),30)+"  "+
         listing((sortedInv[i]->query_value()*2)+" coins",10)+"  "+
         listing(numb_desc(pieces),20)+" ");  
          
         i=j;
      }
      
      write("\n\n");
      write( "Type 'help shop' for further informations.\n\n" );      
      return ( 1 );
   }
}

/* ##################################### help ######################################## */

help( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "shop" ) {
      write( trader() + " says: You can say 'price <item>', and I'll tell you the price, \n" +
             "you have to pay, or say 'value <item>', and I'll tell you the amount, I'll \n" +
             "give you for the item.\n" );
      return( 1 );
   }
}

/* ##################################### value ####################################### */

value( item )
{
   object ob;
   int    coins;
   
   if ( !item )
      return;
      
   ob = present( item, TP );
   if ( ob ) {
      if ( ob->query_value() < 200 )
         write( trader() + " says: I won't value that cheap items.\n" );
      else {
         coins = formula_sell( ob->query_value() );
         if ( (random(2)) )
            coins += ( (coins * random(10)) / 100 );
         else
            coins -= ( (coins * random(10)) / 100 );
            
         write( trader() + " says: Well, I'll give you about " + coins + " coins.\n" );
     }
   }
   else
      write( trader() + " says: I won't value items, you don't have.\n" );
      
   return( 1 );
}

/* ##################################### price ####################################### */

price( item )
{
   object ob;
   int    coins, no;
   
   if ( !item )
      return;
      
   if ( sscanf(item, "%d", no) == 1 && no > 0 ) {
      item = get_obj( no );
      if ( !item )  {
         write( trader() + " says: I can't tell you the price, coz i don't have this item.\n" );
         return( 1 );
      }
   }

   ob = present( item, TO );
   if ( ob ) {
      coins = formula_buy( ob->query_value() );
      if ( (random(2)) )
         coins += ( (coins * random(10)) / 100 );
      else
         coins += ( (coins * random(10)) / 100 );
         
      write( trader() + " says: Well, you have to pay about " + coins + " coins.\n" );
   }
   else
      write( trader() + " says: I can't tell you the price, coz i don't have this item.\n" );
      
   return( 1 );
}

/* ##################################### format ###################################### */
  
 listing(arg,n) { return extract(arg+"                              ",0,n-1); }
 
/* #################################### buy ########################################## */
 
 
buy(arg)
{
   object ob;
   int no, toPay;   
   
   if (!arg) {
       write( "Buy what?\n" );
       return( 1 );
   }
       
   if ( sscanf(arg, "%d", no) == 1 && no > 0 ) {
      arg = get_obj( no );
      if ( !arg ) {
         write(trader()+" says: We don't have this item.\n");
         return( 1 );
      }
   }

 /*  if ( sscanf(arg, "%s %d", no) == 2 && no > 0 )
      write( "NO" );*/

   if (present(arg,TO)) {
       ob=present(arg,TO);
       }
   else {
      write(trader()+" says: We don't have this item.\n");
      return 1;
    }    
       
   toPay = formula_buy( ob->query_value() );
   
   if ( !ob )
      write( trader()+" says: Sorry we don't have "+arg+".\n" );
   else if (TP->query_ghost())
       write(trader()+" says: Sorry I don't sell anything to ghosts.\n");
   else if ( TPM < toPay )
       write(trader()+" says: Sorry, but that would cost you "+
             toPay + " coins.\n");
   else {
      if ( transfer( ob, TP ) )
         write( trader()+" says: Sorry, but you can't carry that much.\n" );
      else {
         write("You start to trade with "+trader()+".\n");
         say(TPN+" starts to trade with "+trader()+".\n");      
         write(trader()+" gives you "+ob->short()+" for "+toPay+" gold coins.\n");
         say(TPN+" buys "+ob->short()+".\n");
         TP->add_money(-toPay);
      }
   }
       
  return 1;
}
  
/* #################################### sell ########################################## */

sell(arg)
{
   object ob;
   int    weight, getCoins;
   
   if ( !arg ) {
      write( "Sell what?\n" );
      return( 1 );
   }
   
   ob=present(arg,TP);
   
   if (ob)
      getCoins = formula_sell( ob->query_value() );
       
   if (arg=="all") {
       write(trader()+" says: Sorry thats too much for me !\n");
       return 1;
      }
      
     else if (!ob)
        write(trader()+" says: You don't have that object.\n");
     else if (getCoins<1)
        write(trader()+"  says: We don't buy worthless items.\n");
     else if ( check_allow(ob) == 0 )
        write(trader()+" says: I don't buy that.\n");
     else {
        if ( ob->query_weapon() && ob->query_wielded() )
           write( trader() + " says: Do you really want to sell a wielded weapon?\n" );
        else if ( ob->query_armour() && ob->query_worn() )
           write( trader() + " says: Do you really want to sell a worn armour?\n" );
        else if ( transfer( ob, TO ) )
           write( trader() + " says: Sorry, i can't get your stuff.\n" );
        else {
           write("You start to trade with "+trader()+".\n");
           say(TPN+" starts to trade with "+trader()+".\n");
           write(trader()+" buys your "+arg+" for "+getCoins+" coins.\n");
           say(TPN+" sells "+arg+".\n");
           TP->add_money( getCoins );
        }
     }
       
    return 1;
}
    
get_obj( no )
{
   object ob;
   int    i,j, num;
      
   holy_sort();

   i = 0; num = 0;
     
    while ( i < sizeof( sortedInv ) ) {
       num++;
       if ( num == no )
          return( sortedInv[i]->query_name() );
             
       j = i + 1;
       while ( j< sizeof(sortedInv) && sortedInv[i]->short() == sortedInv[j]->short() )
          j++;
                         
       i = j;
    }
   
    return( 0 );
}
     
check_allow( ob )
{
   return( 0 );
}
    
trader()
{
   if ( trader )
      return( trader );
   else
      return( "The shopkeeper" );
}      

set_trader( t )
{
   if ( t )
      trader = t;
}
    
info( )
{
   if ( info )
      return( info );
   else
      return( "Item" );
}

set_info( i )
{
   if ( i )
      info = i;
}

max( a, b )
{
   if ( a > b )
      return( a );
   return( b );
}

min( a, b )
{
   if ( a < b )
      return( a );
   return( b );
}

formula_buy( value )
{
   int v;

   if ( TP->query_chr() >= 10 )
      v = value*2 - (value*TP->query_chr())/80;
   else
      v = value*2;
   
   return( max(v,value*16/10) );
}

formula_sell( value )
{
   int v;

   if ( TP->query_chr() >= 10 )
      v = value + (value*TP->query_chr())/80;
   else
      v = value;
 
   v = min( v, value*14/10 );
   return( min( MAX_SELL_VALUE, v ) );
}

numb_desc( arg )
{
    switch( arg ) {
       case 0:      return( "out of stock" );
       case 1:      return( "very few in stock" );
       case 2..3:   return( "few in stock" );
       case 4..7:   return( "some in stock" );
       case 8..10:  return( "plenty in stock" );
       default:     return( "too much in stock" ); 
    }
}
