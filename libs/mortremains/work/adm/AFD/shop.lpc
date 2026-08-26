// shop.c
// A basic shop with a basic storeroom.
// Written by Mobydick@TMI-2, 8-25-92
// Heavily modified by Chronos@DarkTowers, 5/95.
// Chronos wrecked the shop again, 8-29-95.
//  -- Removed stupid money functions, uses credit() and debit() now.
//  -- 1 coin system implemented.

// The shop commands are now as follows: 
//  list - Lists all objects in store.
//  list all <item> - Lists all items matching string.
//  value <item> - Values an item.
//  value all - Values everything in your inventory.
//  sell <item> - Sells an item.
//  sell all unused - Sells all items that are not worn or wielded
//  sell all <item> - Sells all of <item> type.
//  buy <item> - Buys an item.
//  buy <item> <#> - Buys 'sword 3' (for example).. it buys the
//                   sword you designate, eliminating the problem
//                   of players have to buy all the swords to get
//                   to the ones on the bottom of the list.
// browse <item> - Allows exa'ing of items before buying.
// browse <item> <#> - Allows exa'ing of specific items in the shop.
// (02-23-95) Chronos bug fixed so listing the inventory of the store
//            when it has no inventory won't produce an error. :)
// (04-48-96) Chronos tackles the shop again, fearlessly.  Adds a debugging
//            feature, and adds the debug() function to aid his cause.
//            Chronos added the "silent_business" property in case people
//            get tired of watching each other buy and sell things. x
//            Chronos added the stock() function to make life easier
//            for people coding.
//            Fixed more bugs - storerooms weren't loading, items weren't
//            being stocked properly, central storage had an error in it.
//            Added a "more" function to the listing items output.
//            Known bugs: won't condense items any more.  ie- 50 lines of the
//            same item, rather than "50 inflatable woman dolls"  *sigh*
//            Try to "list all sword" when there are no swords there.

#include <move.h>
#include <mudlib.h>
#include <money.h> // do we need this, really?

int buy_item(object ob) ;
int value_item(object ob) ;
mapping get_price_mapping(mixed *arr) ;
int sell_item(object ob) ;
int debug(string msg);

#define DEBUG 1;

inherit ROOM ;

object storeroom ;
object ob,ob2 ;
int no_warehouse;

int debug(string msg) {
  if (!wizardp(TP)) return 0;
  write(msg+"\n");
  return 1;
}

void create() {
  seteuid(getuid()) ;
  set("short", "Tsk tsk!  This is to be inherited!\n");
  set("long", "Tsk tsk!  This is to be inherited, bozo!\n");
  ::create() ;
  // If we need a warehouse, make sure it is loaded.
  if(!query("no_warehouse") ) CENTSTORE->frog() ;
  storeroom = clone_object(STORAGE);
}

void init() {
  add_action("help", "help");
  add_action("stock_it", "stock");
  add_action("browse", "browse");
  add_action("list", "list") ;
  add_action("value", "value") ;
  add_action("buy", "buy") ;
  add_action("sell", "sell") ;
  add_action("enter_storeroom", "storeroom") ;
}

int stock_it(string str) {
  if (!wizardp(TP)) return 0;
  if (!str) { 
    write("Stock what?\n");
    return 1;
  }
  if ((int)this_object()->stock(str) == -1 ) {
    write("Couldn't stock that.\n");
    return 1;
  }
  write("Item stocked.\n");
  return 1;
}


int stock(mixed obj) {
  object ob;
   if (stringp(obj)) ob = clone_object(obj) ;
  if (objectp(obj)) ob = obj;
   if (!ob) return -1;
  if (!query("no_warehouse")) ob->move(CENTSTORE);
    else ob->move(storeroom) ;
  return 1;
 }

int list(string item) {
  int i, flag;
  mixed *ninv ;
  mapping price, match ;
  object *items, *final ; 
  string tmp, ret ;

  if ((int)TP->query("rest")==2) {
   write("You must wake up first.\n") ;
  return 1;
}
  if (item) {
    flag = sscanf(item, "all %s", item) ;
  if (!flag) {
    write("Usage: list all <item>\n") ;
   return 1;
  }
  }
  write(@ENDLONG
The following items are for sale:
-------------------------------------------------------------------------
ENDLONG
  );

// Get the items first.. 
  if (storeroom)
    items = all_inventory(storeroom); 
    if(!(query("no_warehouse"))) 
      items+=all_inventory(find_object_or_load(CENTSTORE)) ;

// Do we have anything to sell yet ?
   if (!items || !sizeof(items) || sizeof(items) == 0) {
      write("There are no items for sale in the shop.\n");
      return 1;
    }

// Okay, first.. build the array of objects so we can parse it and
// shit in a couple seconds.
  if (flag) {   // Do we have a selective list here ?
// If we do have a selctive list, we need to loop through and
// pick out all the items we are looking for.  Otherwise..
// just use the array as it is.
   final = ({ }) ;
    for(i=0;i<sizeof(items);i++) 
       if (items[i]->id(item))  // id match.
         final += ({ items[i] }) ;  // add em.
 }  // we're done building the selective list.. 
  else final = items ; // not selective, take all items.
   
// Remove all objects with no short desc or command initiator
   final = filter_array (final, "clean_objects", this_object());
   
// Compile list of objects with matching short descriptions
  match = unique_mapping(final, "query", "short");
  price = get_price_mapping(final);
  ninv = keys (match);
   
//Loop through object contents and place them into a display string
   
  flag = sizeof (ninv);  
  ret = "" ;
  while (flag--) {
    i = sizeof (match[ninv[flag]]);
   tmp = sprintf("%s (%d)", ninv[flag], i ) ;
   ret += sprintf("%-60s %d coins.\n", tmp,
  price[ninv[flag]]) ;
  }
  write(ret) ;
  return 1;
 }

// This code is supposed to build a mapping contain the prices
// that correspond to the short descriptions of items.  :)
 
mapping get_price_mapping(mixed *arr) {
  mapping tmp;
  mixed res;
  int i;

  seteuid(0);
  if(!arr || !pointerp(arr))  return 0;

  for (i=0, tmp = ([]); i<sizeof(arr);i++) {
    if (!objectp(arr[i])) continue; /* ignore things that aren't objects. */
    res=arr[i]->query("short") ;
  tmp[res] = arr[i]->query("value") ;
 }
  return tmp;
 }

// Remove all invisible objects from the shop..
// Remove all items worth 0 and without a short too.  yah.
int clean_objects (object what) {
  if (!visible(TP, what))
    return 0;
 if (what->query("prevent_drop") || what->query("prevent_sell")) return 0 ;
  return (((string)what->query("short") && what->query("value")) ? 1: 0 ) ;
 }

// Compare each object's short desc with processing short desc
string content_match (object what) {
  return (string)what->query("short");
 }

int buy(string str) {
  string item, *arr;
  int number, i, ii, match;
  object ob, *all_items;

  if ((int)TP->query("rest") == 2) {
  write("You must wake up first.\n") ;
  return 1;
 }
// You need an argument for this function.
  if (!str) {
    write("What would you like to buy?\n");
    return 1;
  }
// Okay, we know they entered SOMETHING now.
// Was it a "item #" format?
  if (sscanf(str, "%s %d", item, number) == 2) {
// If so... 
// Check central storage, if it don't exist, try the storeroom.
   all_items = all_inventory(storeroom);
   if (!query("no_warehouse")) 
     all_items+=all_inventory(find_object(CENTSTORE));
   else all_items = all_inventory(storeroom);
// Reset the match variable.
   match = 0;
// Do this loop for every item in the shop.
   for(i=0;i<sizeof(all_items);i++) {
// Put all the words in the item's short into an array.
   arr = explode((string)all_items[i]->query("short"), " ");
// Begin the loop to compare each word to the item requested.
   for(ii=0;ii<sizeof(arr);ii++) 
     if (lower_case(item) == lower_case(arr[ii])) {
// It matches, increment the match variable.
        match++;
// If we've hit the correct item, make ob point to the current item.
        if (match == number) ob = all_items[i];  
      }
    }
// If match still = 0, we didn't find one.
    if (match == 0) {
      write("We don't have any '" + str + "' for sale.\n");
      return 1;
    }
// If match is less than the number requested, we didn't find a sword 3.    
    if (match < number) {
      write("We don't have a '"+str+"' for sale.\n");
      return 1;
    }
  } else {
// If we get here, they didn't use the "item #" format.
// Is the object in the storeroom?
    if(!query("no_warehouse") ) ob = present(str,find_object(CENTSTORE)) ;
    if (!ob) ob = present (str,storeroom) ;
    if (!ob) {
  // Guess we don't have one of those.
       write("We don't have one of those for sale.\n");
      return 1 ;
    }
  }
  // This is just a catch-all added by Chronos to make him feel better.
  if (!ob) {
    write("We don't have one of those for sale.\n");
    return 1;
  } // This could very well be redundant and may need to be taken out.
  // We should have found an item to sell them if we got to this point.
  buy_item(ob);
  return 1;
}

int browse(string str) {
  string item, *arr;
  int number, i, ii, match;
  object ob, *all_items;

  if ((int)TP->query("rest")==2) {
  write("You must wake up first.\n") ;
  return 1;
  }
  // Check to see if they just typed 'browse'.
  if (!str) {
    write("What would you like to browse?\n");
    return 1;
  }
  // Okay, we know they entered SOMETHING now.
  // Was it a "item #" format?
  if (sscanf(str, "%s %d", item, number) == 2) {
  // If so... 
  // Check central storage, if it don't exist, when the storeroom.
   all_items = all_inventory(storeroom);
   if (!query("no_warehouse")) all_items+=all_inventory(find_object(CENTSTORE));
    else all_items = all_inventory(storeroom);
  // Reset the match variable.
    match = 0;
  // Do this loop for every item in the shop.
    for(i=0;i<sizeof(all_items);i++) {
  // Put all the words in the item's short into an array.
      arr = explode((string)all_items[i]->query("short"), " ");
  // Begin the loop to compare each word to the item requested.
      for(ii=0;ii<sizeof(arr);ii++) 
      if (lower_case(item) == lower_case(arr[ii])) {
  // It matches, increment the match variable.
        match++;
  // If we've hit the correct item, make ob point to the current item.
        if (match == number) ob = all_items[i];  
      }
    }
  // If match still = 0, we didn't find one.
    if (match == 0) {
      write("We don't have a '" + str + "' for sale.\n");
      return 1;
    }
  // If match is less than the number requested, we didn't find a sword 3.    
    if (match < number) {
      write("We don't have a '"+str+"' for sale.\n");
      return 1;
    }
  } else {
  // If we get here, they didn't use the "item #" format.
  // Is the object in the storeroom?
    if(!query("no_warehouse") ) ob = present(str,find_object(CENTSTORE)) ;
    if (!ob) ob = present (str,storeroom) ;
    if (!ob) {
  // Guess we don't have one of those.
       write("We don't have one of those for sale.\n");
      return 1 ;
    }
  }
  // We should have found an item if we got to this point.
  write("The shopkeeper hands you "+ob->query("short")+ 
    " for your inspection.\n");
  write("Looking closely, you see:\n"+(string)ob->query("long"));
  if (!this_object()->query("silent_business")) 
  say("The shopkeeper hands "+ob->query("short")+" to " +
       TPN+" for " + possessive(TP->query("gender")) + " inspection.\n");
  return 1;
}

int buy_item(object ob) {
  int value, res;

// Added by Chronos to make sure items that shouldn't be in the shop
// are removed when found.  :)
  if (ob->query("destruct_when_sold")) {
    write("That item should not have been in the shop.\n");
    ob->remove();
    return 1;
  }
  value = ob->query("value") ;
  
// Objects with no value have no business being in the shop.

  if (!value) {
    write("That item should not have been in the shop.\n");
    ob->remove() ;
    return 1 ;
  }
  if (value<1) {
    write("That item should not have been in the shop.\n");
    ob->remove() ;
    return 1 ;
  }
  if (!TP->debit(value)) {
    write("You don't have enough money for that!\n");
    return 1;
  }
// See if the player can carry the object.
    res = ob->move(TP) ;
    if (res==MOVE_OK) {
  write("You buy "+(string)ob->query("short")+
    " for " + ob->query("value") + " coins.\n");
      if (!this_object()->query("silent_business")) 
      say (TP->query("cap_name")+" buys "+ob->query("short")+".\n") ;
      return 1 ;
    } else {
// Give him his money back.
    TP->credit(value, 1) ;
      write ("You cannot carry that object.\n") ;
      return 1 ;
    }
    write("The shopkeeper tells you: The shop is broke!  Tell an admin!\n");
    return 1; // If we got here, something is broke.
}

int value(string str) {
  int i;
  object *ob, obj ;

  if ((int)TP->query("rest")==2) { 
  write("You must wake up first.\n") ;
  return 1;
  }
  if (!str) {
    write("Value what?\n");
    return 1;
  }
  if (str == "all") {
    ob = all_inventory(TP) ;
    if (!ob) {
      write("You don't have any belongings.\n");
      return 1 ;
    }
    for (i=0;i<sizeof(ob);i++) value_item(ob[i]);
    return 1 ;
  }
  obj = present(str,TP) ;
  if (!obj) {
    notify_fail ("You don't have a "+str+".\n") ;
    return 0 ;
  }
  value_item(obj);
  return 1 ;
}

int value_item(object ob) {
  int value;
  string word;
  if (!ob->query("short")) return 0 ;
  value = ob->query("value");
  printf("%-28s: ", ob->query("short"));
  if (!value) {
    write("That item has no value.\n");
    return 1;
  }
  if (value<1) {
    write("That item has no value.\n");
    return 1;
  }
  if (ob->query("prevent_drop")) {
    write("The shop cannot buy that item.\n");
    return 1 ;
  }
  value = value*SHOP_SALES_FRAC ; 
  if (value==1) word="coin" ; else word="coins" ;
  write("Worth "+value+" "+word+".\n");
  return 1;
}

int sell(string str) {
  string work;
  string *arr;
  int i, ii, match;
  object ob ;
  object *obs ;

  if ((int)TP->query("rest")==2) {
   write("You must wake up first.\n") ;
   return 1;
  }
  if (!str) {
    write("Sell what?\n");
    return 1 ;
  }
  
  if (sscanf(str, "all %s", work) == 1) {
    if (work == "unused") {
      obs = all_inventory(TP) ;
      for (i=0;i<sizeof(obs);i++) {
        if (obs[i]->query("worn")) continue;
        if (obs[i]->query("wielded")) continue;
        sell_item(obs[i]);
      }
      return 1;
    }
    obs = all_inventory(TP) ;
    for (i=0;i<sizeof(obs);i++) {
      arr = explode((string)obs[i]->query("short"), " ");
      match = 0;
   for (ii=0;ii<sizeof(arr);ii++) 
       if (lower_case(work) == lower_case(arr[ii])) match = 1;
      if (!match) continue;
      sell_item(obs[i]);
    }
  }
  if (str=="all") {
    obs = all_inventory(TP);
    for (i=0;i<sizeof(obs);i++) sell_item(obs[i]);
    return 1;
  }
  ob = present(str,TP) ;
  if (!ob) {
    notify_fail("You don't have one to sell!\n") ;
   return 0;
  }
  sell_item(ob);
  return 1 ;
}

int sell_item(object ob) {
  int value, capacity, res;
  string word;
  if (!ob->query("short")) return 0 ;
  value = ob->query("value") ;
  printf("%-28s: ", ob->query("short"));
  if (ob->query("keep")) {
    write("You are keeping that item.\n") ;
    return 1;
  }
  if (!value) {
    write("That item has no value.\n");
    return 1 ;
  }
  if (value<1) {
    write("That item has no value.\n");
    return 1 ;
  }
  if (ob->query("prevent_sell")) {
    write("The shop cannot buy that item.\n");
    return 1 ;
  }
  if (ob->query("prevent_drop")) {
    write("The shop cannot buy that item.\n");
    return 1 ;
  }
  res = ob->move(storeroom) ;
  if (res != MOVE_OK) {
    write("The shop cannot buy that item.\n");
    return 1 ;
  }
  value = value*SHOP_SALES_FRAC ;
  if (value==1) word="coin" ; else word="coins" ;
  write("Sold for "+value+" "+word+".\n");
  TP->credit(value,1) ;
  // Added by Chronos to make the shop hide items when they have the
  // "destruct_when_sold" property.
  if ((int)ob->query("destruct_when_sold") == 2) 
      write("The shopkeeper hides the valuable item in the back room.\n");
  if (ob->query("destruct_when_sold")) 
      ob->remove();
  return 1;
}

int enter_storeroom() {
  if (!wizardp(TP)) return 0 ;
  if (!storeroom) {
    write("There is no storeroom.\n");
    return 1;
  }
  write("The shopkeeper leads you to the storeroom.\n");
  TP->move_player(storeroom, "SNEAK") ;
  return 1 ;
}

int help(string str) {
  if (str != "shop") return 0;
  write(@ENDHELP
The shop commands are now as follows: 
  
  list                          - Lists all objects in store.
  list all <item>               - Lists all items matching string.
  value <item>                  - Values an item.
  value all                     - Values everything in your inventory.
  sell <item>                   - Sells an item.
  sell all unused               - Sells all items that are not worn 
                                  or wielded
ENDHELP
  );     // Broke it up to avoid recursion errors.  That sucked. :D
  write(@ENDHELP
  sell all <item>               - Sells all of <item> type.
  buy <item>                    - Buys an item.
  buy <item> <#>                - Buys 'sword 3' (for example).. it buys 
                                  the sword you designate, eliminating 
                                  the problem of having to buy all of
                                  the swords to get to the ones on the 
                                  bottom of the list.
 browse <item>                  - Allows exa'ing of items before buying.
 browse <item> <#>              - Allows exa'ing of specific item in shop.

 If you have ANY problems with the new shop, contact Chronos!
ENDHELP
  );
  return 1;
} 
