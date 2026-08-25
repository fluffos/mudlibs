#include "move_failures.h"
#include "money.h"
inherit "/std/basic/light";
inherit "/std/basic/move";
/* this will also handle value... */

nosave int weight;
int value;
int resale_value; /* Hamlet */
int stolen_modifier; /* Hamlet */

void create() {
}

/* integer exponential function added by dank Feb 23, 93 */
int exp(int x, int y) {
  int i, ret;
  if (y < 0) {
    notify_fail("exp(x,y) where y<0 is a fraction; no fractions allowed!\n");
    return 0;
  }
  ret = 1;
  for (i=0; i<y; i++)
    ret *= x;
  return ret;
}

// fixed these so there are no negative weights... Anirudh
void adjust_weight(int w) {
  if (weight+w < 0) w = -weight;
  if (environment())
    environment()->add_weight(w);
  weight += w;
}

void set_weight(int w) {
  if (w < 0) w = 0;
  if (environment())
    environment()->add_weight(w-weight);
  weight = w;
}

int query_weight() {
  if (weight < 0) weight = 0;
  return weight;
}

varargs int adjust_money(mixed amt, string type) {

  if (pointerp(amt)) {
    value += (int)MONEY_HAND->query_total_value(amt);
    if (value < 0)
      value = 0;
    return value;
  }
  amt = (int)MONEY_HAND->query_total_value( ({ type, amt }) );
  value += amt;
  if (value < 0)
    value = 0;
  return value;
}

int adjust_value(int i) { return (value += i); }

mixed *query_money_array() { 
  return (mixed *)MONEY_HAND->create_money_array(value);
}

int query_money(string type) { 
  int i;
  mixed *m_a;

  m_a = (mixed *)MONEY_HAND->create_money_array(value); 
  if ((i=member_array(type, m_a)) == -1)
    return 0;
  return m_a[i+1];
}

void set_value(int i) { value = i; }
int query_value() { return value; }

varargs int move(mixed dest, mixed messout, mixed messin) {
  int i;
  object from;

   if(!dest)
   {
// Taniwha 1995, maybe log this ?
      return 0;
   }
  from = environment();
// put parentheses around stuff after !... Anirudh
  if (!(dest->add_weight(weight)))
    return MOVE_TOO_HEAVY;
  i = ::move(dest, messout, messin);
  if (i == MOVE_OK) {
    if (from) {
      from->add_weight(-weight);
      from->adjust_light(-query_light());
    }
      if(environment())
    environment()->adjust_light(query_light());
  } else
    dest->add_weight(-weight);
  return i;
}

void dest_me() {
   object *olist;
   int i;
  if (environment()) {
    environment()->add_weight(-weight);
    set_light(0);
  }
   olist = all_inventory(this_object());
   for(i = 0; i < sizeof(olist); i++)
   {
      if(olist[i]) olist[i]->dest_me();
   }
  ::dest_me();
}

/* resale value functions by Hamlet, August 1995 */
/* These are the price a shop will offer for an object. */

void set_resale_value(int i) { resale_value = i; }
int adjust_resale_value(int i) { return( resale_value += i); }
int query_resale_value() { return resale_value; }

void prevent_resale() {  resale_value = -1;  }
void allow_resale() {  resale_value = 0;  }

/* These are for how much the shop will offer for the item if it has
   been stolen. -- Hamlet
*/

int set_stolen_modifier(int i) {
  if(i > 100)   i = 100;
  if(i < -1)    i = -1;

  stolen_modifier = i;
  return i;
}
int query_stolen_modifier() { return stolen_modifier; }
void no_sell_if_stolen() { stolen_modifier = -1; }
