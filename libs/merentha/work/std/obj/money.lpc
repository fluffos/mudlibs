// Petrarch
// Merentha Lib 1.0
// money object

#include <std.h>
#include <money.h>
inherit OBJECT;

mapping money=([]);

string query_long() {
string *types=__CURRENCY_TYPES;
string ret="There are some coins here:";
int i=sizeof(types);
  while (i--) if(money[types[i]]) ret+="\n"+right_align(""+money[types[i]],5)+" "+types[i];
  return ret;
}

void add_money(string type, int amt) {
  if(member_array(type, __CURRENCY_TYPES)==-1) return;
  if(!money[type]) money[type]=0;
  money[type]=money[type]+amt;
}

void create() {
::create();
  set_name("money");
  set_short("a pile of coins");
  set_id(({"coins", "coin", "money"}));
  set_mass(0);
  set_value(0);
}

void post_move() {
  if(environment()) if(living(environment())) call_out("remove",0,environment());
}

void remove(object env) {
string *types=__CURRENCY_TYPES;
string ret="The coins contain:";
int i=sizeof(types);
  if(env) {
    while (i--) 
      if(money[types[i]]) {
        ret+="\n"+right_align(""+money[types[i]],5)+" "+types[i];
        env->add_money(types[i],money[types[i]]);
      }
    message("money", ret, env);
  }
  ::remove();
}
