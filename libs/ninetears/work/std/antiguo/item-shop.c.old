#include "armory.h"
#include "money.h"
inherit "/std/room";

/* Taniwha 1995
 * shop container moved to shop as "list" to prevent problems
 * with dissapearing inventories
 *
 * put-only container shop_con.c used as holder for inventory
 */
object cont;

#define MAX_PROP "max per reset"
#define TYPE "item shop type"
#define NUM_SOLD "number sold this reset"

/* Taniwha 1995 , block clean_up() from removing items 
 * 
 */
int clean_up(int flag) { return 1; }

void make_container()
{
   if(!cont)
   {
      cont = clone_object("/std/shop_con.c");
      cont->set_name("list");
      cont->set_short("list");
      cont->set_long("\n A list of items available here "
         "type \"list\" to get prices.\n");
      cont->move(this_object());
      cont->reset_get();
   }
   cont->reset_prevent_insert(); // taniwha 1996, correct, so we can restock it. Lock it after
}
void reset() {
  object ob;

   make_container();
  ob = first_inventory(cont);
  while (ob) {
    ob->remove_property(NUM_SOLD);
    ob = next_inventory(ob);
  }
   cont->set_prevent_insert(); // Taniwha 1996, lock it
}

/* ps 0, means infinite */
int add_armor(string name, int max_per_reset){
  object ob;

   make_container();
  ob = (object)ARMORY->request_armour(name);

  if (ob) {
    ob->move(cont);
    ob->add_property("armory name", name);
    ob->add_property(MAX_PROP, max_per_reset);
    ob->add_property(TYPE, "armor");
   cont->set_prevent_insert(); // Taniwha 1996, lock it
    return 1;
  }
   cont->set_prevent_insert(); // Taniwha 1996, lock it
  return 0;
}

int add_armour(string name, int max_per_reset){
   return add_armor(name, max_per_reset);
}

int add_weapon(string name, int max_per_reset) {
  object ob;

   make_container();
  ob = (object)ARMORY->request_weapon(name);
  if (ob) {
    ob->move(cont);
    ob->add_property("armory name", name);
    ob->add_property(MAX_PROP, max_per_reset);
    ob->add_property(TYPE, "weapon");
   cont->set_prevent_insert(); // Taniwha 1996, lock it
    return 1;
  }
   cont->set_prevent_insert(); // Taniwha 1996, lock it
  return 0;
}

int add_object(string where, int max) {
  object ob;

   make_container();
  ob = clone_object(where);
  if(ob) {
    ob->add_property(TYPE, "object");
    ob->add_property(MAX_PROP, max);
    ob->add_property("armory name", where);
    ob->move(cont);
    return 1;
   cont->set_prevent_insert(); // Taniwha 1996, lock it
  }
   cont->set_prevent_insert(); // Taniwha 1996, lock it
  return 0;
}


void init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}

int query_cost(object ob) {
  return (int)ob->query_value();
}

int list(string str) {
  int i;
  string weap, arm, obj;
  object ob;

  weap = arm = obj = "";
  ob = first_inventory(cont);
  while(ob) {
    switch (ob->query_property(TYPE)) {
      case "armor" :
        arm += "   "+capitalize((string)ob->short())+" worth "+
           MONEY_HAND->money_value_string(this_object()->query_cost(ob))+".\n";
        break;
      case "weapon" :
        weap += "   "+capitalize((string)ob->short())+" worth "+
           MONEY_HAND->money_value_string(this_object()->query_cost(ob))+".\n";
        break;
      case "object" :
        obj += "   "+capitalize((string)ob->short())+" worth "+
           MONEY_HAND->money_value_string(this_object()->query_cost(ob))+".\n";
        break;
    }
    ob = next_inventory(ob);
  }
  if (arm != "")
    printf("%=-*s", (int)this_player()->query_cols(), "Armors.\n"+arm);
  if (weap != "")
    printf("%=-*s", (int)this_player()->query_cols(), "Weapons.\n"+weap);
  if (obj != "")
    printf("%=-*s", (int)this_player()->query_cols(), "Items.\n"+obj);
  if (obj == "" && arm == "" && weap == "") {
    notify_fail("Nothing here to buy.\n");
    return 0;
  }
  return 1;
}

int buy(string str) {
  object *obs;
  int i, num, max;
  object ob;

  if (!str) {
    notify_fail("You must buy something.\n");
    return 0;
  }
  obs = find_match(str, cont);
  notify_fail("Buy something that is on the menu.\n");
  if (!sizeof(obs))
    return 0;
  for (i=0;i<sizeof(obs);i++) {
    ob = 0;
    if ((num = (int)obs[i]->query_property(NUM_SOLD)) > 
          (max = (int)obs[i]->query_property(MAX_PROP)) && max) {
      write("We are sold out of "+obs[i]->short()+".\n");
      continue;
    }
    obs[i]->add_property(NUM_SOLD, ++num);
    switch (obs[i]->query_property(TYPE)) {
      case "weapon" :
        ob = (object)ARMORY->request_weapon(obs[i]->query_property("armory name"));
        break;
      case "armor" :
        ob = (object)ARMORY->request_armor(obs[i]->query_property("armory name"));
        break;
      case "object" :
        ob = clone_object((string)obs[i]->query_property("armory name"));
        break;
      }
    if (!ob) {
      string tmpstr;

      sscanf(file_name(obs[i]), "%s#", tmpstr);
      ob = clone_object(tmpstr);
    }
    if (this_object()->query_cost(ob) > this_player()->query_value()) {
      write("You cannot afford to buy "+ob->short()+".\n");
      continue;
    }
    if (ob->move(this_player())) {
      write("You cannot pick "+ob->short()+" up.\n");
      ob->dest_me();
      continue;
    }
    this_player()->pay_money(ob->query_money_array());
    write("You buy "+ob->short()+".\n");
    say(this_player()->query_cap_name()+" buys "+ob->short()+".\n");
  }
  return 1;
}

void dest_me() {
  int i;
  object *obs;

  if (cont) {
    obs = all_inventory(cont);
    for (i=0;i<sizeof(obs);i++)
      obs[i]->dest_me();
    cont->dest_me();
  }
  ::dest_me();
}
