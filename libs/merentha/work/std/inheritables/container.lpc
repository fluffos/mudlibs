// Petrarch
// Merentha Lib 1.0
// container.c

#include <std.h>
#include "container.h"

inherit OBJECT;

int __MaxCarryItems, __MaxCarryWeight;

void create() {
  ::create();
  __MaxCarryItems=0;
  __MaxCarryWeight=0;
}

void set_max_mass (int i) { __MaxCarryWeight=i; }
int query_max_mass () { return __MaxCarryWeight; }

void set_max_items (int i) { __MaxCarryItems=i; }
int query_max_items () { return __MaxCarryItems; }

int query_holding_mass() {
 object *inv;
 int j,i;
 i=sizeof(inv=all_inventory(this_object()));
 while(i--) j+=inv[i]->query_mass();
  return j;
}

string receive_object(object ob) {
  if(!ob) return 0;
  if(living(ob) && living(this_object())) return "You can not carry a living being.";
  if(__MaxCarryWeight && __MaxCarryWeight<query_holding_mass()+ob->query_mass())
    return (this_player()==this_object()?"You":query_cap_name(this_object()))+" can not hold the weight of "+ob->query_short()+".";
  if(__MaxCarryItems && __MaxCarryItems<=sizeof(all_inventory(this_object())))
    return (this_player()==this_object()?"You":query_cap_name(this_object()))+" can not hold any more items.";
  return 0;
}
    
string get_living_contents() {
string tmp="", tmp2, *k;
mapping shorts=([]);
object *obs=all_inventory(this_object());
int i;
if(this_player()) obs-=({this_player()});
i=sizeof(obs);
while (i--)
  if(living(obs[i])) {
    tmp2=(obs[i]->query_short()?obs[i]->query_short():obs[i]->query_name());
    if(!shorts[tmp2]) shorts[tmp2]=1;
    else shorts[tmp2]=shorts[tmp2]+1;
  }
i=sizeof(k=keys(shorts));
if(!i) return "";
while(i--)
  tmp+=capitalize(consolidate(shorts[k[i]], k[i])+"\n");
return tmp;
}

string get_nonliving_contents() {
string tmp="", tmp2, *k;
mapping shorts=([]);
object *obs=all_inventory(this_object());
int i, j, x;
if(this_player()) obs-=({this_player()});
i=sizeof(obs);
while (i--)
  if(!living(obs[i])) {
    tmp2=(obs[i]->query_short()?obs[i]->query_short():obs[i]->query_name());
    if(!shorts[tmp2]) shorts[tmp2]=1;
    else shorts[tmp2]=shorts[tmp2]+1;
    x++;
  }
i=sizeof(k=keys(shorts));
if(!i) return "";
j=i;
while(i--) {
  tmp+=consolidate(shorts[k[i]], k[i]);
  if(j>1) {
    if(i>1) tmp+=", ";
    if(i==1) tmp+=" and ";
  }
}
if(j>1 || x >1) tmp+=" are here.\n";
if(j==1 && x <=1) tmp+=" is here.\n";
return capitalize(tmp);
}

int is_container() { return 1; }
