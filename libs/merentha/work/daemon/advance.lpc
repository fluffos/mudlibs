// Petrarch 
// Merentha Lib 1.0
// advance daemon

#include <std.h>

inherit DAEMON;

int query_needed_exp(int l) {
float a,b,c=2140000000;
int x;
  if(l<1) return 1;
  x=(l*33.0)/25;
  l=(l+6)*1.5;
  a=(-1.0/(((1.0*l/4)+69)-101));
  b=a*a*a*100000;
  b=b*b;
  b=b*b*(x);
  return to_int(b);
}

int get_exp(object ob) {
  if(!ob) return 0;
  return (ob->query_level()+1)*100;
}
