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
// browse <item> <#> - Allows exa'ing of specific item in shop.

#include <move.h>
#include <mudlib.h>
#include <money.h>

int buy_item(object ob) ;
int value_item(object ob) ;
int sell_item(object ob) ;

inherit ROOM ;

object storeroom ;
object ob,ob2 ;
int no_warehouse;

void create() {
  seteuid(getuid()) ;
  set("short", "Tsk tsk!  This is to be inherited!\n");
  set("long", "Tsk tsk!  This is to be inherited, bozo!\n");
  ::create() ;
  // If we need a warehouse, make sure it is loaded.
  if(!query("no_warehouse") ) CENTSTORE->frog() ;
}

void init() {
  add_action("help", "help");
  add_action("browse", "browse");
  add_action("list", "list") ;
  add_action("value", "value") ;
  add_action("buy", "buy") ;
  add_action("sell", "sell") ;
  add_action("enter_storeroom", "storeroom") ;
}

int list(string arg) {
  int i, value, flag, ii, match;
  object *items ;
  string str, *arr, item;

  if (arg) flag = sscanf(arg, "all %s", item);

  write ("The following objects are for sale:\n") ;
 if (storeroom)
  items = all_inventory(storeroom); 
  if(!(query("no_warehouse"))) 
    items+=all_inventory(find_object_or_load(CENTSTORE)) ;
  for (i=0;i<sizeof(items);i++) {
    str = (string)items[i]->query("short") ;
    if (str[0..1]=="a ") str=str[2..-1] ;
    if (str[0..2]=="an ") str=str[3..-1] ;
    if (str[0..3]=="the ") str=str[4..-1] ;
    
    if (flag) {                                 // using all <item> format.
      arr = explode(str, " "); // Make an array with all the words.
      match = 0;
      
      // This line checks all the words for the one you wanna list.
      // If it finds it, match = 1.. if match isn't found after
      // this line, it moves to the next item. (in the big loop) ;)
      for(ii=0;ii<sizeof(arr);ii++)  
        if (lower_case(item) == lower_case(arr[ii])) match = 1;
      if (!match) continue;
    }

    value = items[i]->query("value") ;   // FInd the value of this item.
    if (!value||value<1) continue ;      // If it has no value, move on.
  printf("%40-s\t\t%d coins.\n",
 (string)items[i]->query("short"),
            value);
  }
  return 1 ;
}

int buy(string str) {
  string item, *arr;
  int number, i, ii, match;
  object ob, *all_items;

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
  // We should have found an item to sell them if we got to this point.
  buy_item(ob);
  return 1;
}

int browse(string str) {
  string item, *arr;
  int number, i, ii, match;
  object ob, *all_items;

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
  say("The shopkeeper hands "+ob->query("short")+" to " +
       TP->query("cap_name")+" for " + 
      possessive(TP->query("gender")) + " inspection.\n");
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
      say (TP->query("cap_name")+" buys "+ob->query("short")+".\n") ;
      return 1 ;
    } else {
// Give him his money back.
      TP->credit(value);
      write ("You cannot carry that object.\n") ;
      return 1 ;
    }
    write("The shopkeeper tells you: The shop is broke!  Tell an admin!\n");
    return 1; // If we got here, something is broke.
}

int value(string str) {
  int i;
  object *ob, obj ;

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
    return 1 ;
  }
  sell_item(ob);
  return 1 ;
}

int sell_item(object ob) {
  int value, capacity, res;
  string word;
  value = ob->query("value") ;
  printf("%-28s: ", ob->query("short"));
  if (!value) {
    write("That item has no value.\n");
    return 1 ;
  }
  if (value<1) {
    write("That item has no value.\n");
    return 1 ;
  }
  if (ob->query("prevent_drop")) {
    write("The shop cannot buy that item.\n");
    return 1 ;
  }
  res = ob->move(storeroom) ;
  if (res != MOVE_OK) {
    write("You cannot sell that!\n");
    return 1 ;
  }
  value = value*SHOP_SALES_FRAC ;
  if (value==1) word="coin" ; else word="coins" ;
  write("Sold for "+value+" "+word+".\n");
  TP->credit(value);
  // Added by Chronos to make the shop hide items when they have the
  // "destruct_when_sold" property.
    if (ob->query("destruct_when_sold")) {
      write("The shopkeeper hides the valuable item in the back room.\n");
      ob->remove();
    }
  return 1;
}

int enter_storeroom() {
  if (!wizardp(TP)) return 0 ;
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
                                  the problem of players have to buy all 
                                  the swords to get to the ones on the 
                                  bottom of the list.
 browse <item>                  - Allows exa'ing of items before buying.
 browse <item> <#>              - Allows exa'ing of specific item in shop.

 If you have ANY problems with the new shop, contact Chronos!
ENDHELP
  );
  return 1;
}
