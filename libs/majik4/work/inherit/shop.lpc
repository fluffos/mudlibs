/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <list.h>

inherit LIVING;

nosave float sell_percent = 1.5, buy_percent = 0.5;
nosave int max_value, discount;
mapping object_list;
nosave string *produce, *object_index;
int bargain_num_buy;
int bargain_num_sell;
string owner = "null";

#define zap(val) ((val) < 1000000 ? (val) + "" : ((val)/1000) + "k")

void keeper(string);

string
convert_money (int i)
{
   return "" + i;
}

int
do_sort (mixed a, mixed b)
{
   return strcmp(a, b);
}

varargs void
add_object_list (mapping m, int no_sort)
{
   if (object_list [m ["short_desc"]] == 0)
	 {
		object_list [m ["short_desc"]] = ([ ]);
		
		if (!no_sort)
		  object_index = sort_array (keys (object_list), "do_sort");
	 }
   
   object_list [m ["short_desc"]][m ["item_id"]] = m; 
}

void
sort_object_list ()
{
   object_index = sort_array (keys (object_list), "do_sort");
}

int
query_amount (string s)
{
   int i;
   
   if (s == "*")
	 {
		foreach (s in object_index)
		  i += sizeof (object_list [s]);
		
		return i;
	 }
   else if (object_list [s] != 0)
	 return sizeof (object_list [s]);
}

void
remove_object_list (string s, string sid)
{
   if (object_list [s] == 0)
	 return;
   
   if (sid == "*")
	 {
		map_delete (object_list, s);
		object_index = sort_array (keys (object_list), "do_sort");
		return;
	 }
   
   map_delete (object_list [s], sid);
   
   if (sizeof (object_list [s]) == 0)
	 {
		map_delete (object_list, s);
		object_index = sort_array (keys (object_list), "do_sort");
	 }
}

int
match_item (string s, mapping m)
{
   return m ["alias"][s] || m ["file_name"] || m ["short_desc"] == s;
}

int
ambiguous_match_item (string *x, mapping m)
{
   string s;
   
   foreach (s in x)
	 if (m ["alias"][s] || strsrch (lower_case(m ["short_desc"]), s) != -1)
	   return 1;
}

mapping
find_object_list_by_index (int indx)
{
   string *s;
   
   s = object_index;
   
   if (indx < 0 || indx >= sizeof (s))
	 return 0;
   
   return object_list [s [indx]][keys (object_list [s [indx]]) [0]];
}

mapping
find_object_list_by_name_and_index (string s, int indx)
{
   int cnt, found, dnt;
   string *x, *y;
   
   x = object_index;
   
   for (cnt = 0; cnt < sizeof (x); cnt++)
	 {
		y = keys (object_list [x [cnt]]);
		dnt = sizeof (y);
		
		while (dnt-- > 0)
		  if (match_item (s, object_list [x [cnt]][y [dnt]]) == 1 &&
			  ++found == indx)
			return object_list [x [cnt]][y [dnt]];
	 }
}

mapping
find_object_list_by_name (string s)
{
   string *x,*y;
   int cnt, dnt;
   
   x = object_index;
   
   for (cnt = 0; cnt < sizeof (x); cnt++)
	 {
		y = keys (object_list [x [cnt]]);
		dnt = sizeof (y);
		
		while (dnt-- > 0)
		  if (match_item (s, object_list [x [cnt]][y [dnt]]) == 1)
			return object_list [x [cnt]][y [dnt]];
	 }
}

mapping
find_object_list (string s)
{
   int     indx, num;
   string  id;
   /* string *ind;*/
   mapping m;
   
   if (sscanf (s, "%s:%d", s, num) == 2 && num < 1)
	 num = 0;
   
   if (sscanf (s, "%d", indx) == 1)
	 m = find_object_list_by_index (--indx);
   
   else if (sscanf (s, "%s %d", id, indx) == 2)
	 m = find_object_list_by_name_and_index (id, indx);
   else
	 m = find_object_list_by_name (s);
   
   if (!m || !num)
	 return m;
   
   if (--num >= sizeof (object_list [m ["short_desc"]]))
	 return 0;
   
   return (object_list [m ["short_desc"]]
		   [keys (object_list [m ["short_desc"]]) [num]]);
}    

mapping
query_object_list ()
{     
   return object_list;
}

int
set_max_value (int i)
{
   return max_value = i;
}

int
is_legal_item (object o)
{
   return 1;
}

float
set_buy_percent (float i)
{
   return buy_percent = i;
}

float
set_sell_percent (float i)
{
   return sell_percent = i;
}

void send_item_to_store (object o)
{
   add_object_list (THOB->get_mapping (o));
   destruct (o);
}

string *
set_produce (string *str)
{
   return produce = str;
}

int
sold_value (int i)
{
   int val;
   
   val = to_float(i * sell_percent);
   
   if (discount)
	 val = to_float(discount * val / 100.0);
   
   return to_int(val);
}

string
list_item (mapping m, int cnt, int amount)
{
   int val;
   string sh;
   
   val = sold_value (m["c_value"]);
   
   if (strlen (m["short_desc"]) > 30)
	 sh = m["short_desc"][0..29];
   else
	 sh = m["short_desc"];
   
   return sprintf ("%-30s | %6s gp %3d qnt %4.1f kg;",
				   sh, convert_money(val), amount,
				   to_float(m["weight"]/1000.0));
}

int
do_list (string s)
{
   string *x, str, tmp, *match;
   int i, scnt, cnt, max_price, siz;
   mixed m;
   
   if (object_list && sizeof(object_list))
	 object_index = sort_array(keys(object_list), "do_sort");
      
   if (!sizeof(object_index))
	 {
		keeper (({ "Unfortunately we have nothing in stock at this time.",
		   "Sorry, we are completely out of wares.",
		   "The shop is empty, don't you see?" })[random(3)]);
		return 1;
	 }
   
   x = object_index;
   
   str = "";
   
   if (!s)
	 s = "";
   
   if (sscanf (s, "max %d", max_price))
	 s = 0;
   else if (sscanf (s, "%s max %d", tmp, max_price) == 2)
	 s = tmp;
   
   if (s == "")
	 s = 0;
   
   if (s && (i = sizeof ((match = explode (s, ",")))) > 9)
	 {
		message (CMD_MSG, 0,0,0, "Too many (" + i + ", max 9) identifiers.",
				 THIS);
		
		return 1; 
	 }
   
   for (i = 0; i < sizeof (x); i++)
	 {
		m = object_list [x [i]][keys (object_list [x [i]]) [0]];
		
		if ((s == 0 || ambiguous_match_item (match, m) == 1) &&
			(!max_price || sold_value (m ["c_value"]) <= max_price))
		  {
			 siz  = sizeof (object_list [x [i]]);
			 str += list_item (m, i + 1, siz);
			 scnt++;
			 cnt += siz;
		  }
	 }
   
   if (!scnt)
	 keeper (({ "Didn't find what you were looking for, hmm?",
		"I'm sorry you didn't find what you wanted, "+
		  ({ "sir", "sir", "madam" })[THIS->query_gender()]})[random(2)]);
   else   
	 {	
		message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(),
				 VISIBLE_RADIUS/2, "$N1 {show} $s1 items to $n2.", ENV(THOB),
				 ({ THOB, THIS }));
		
		open_window (THIS, 0, 0, 0, 0, LTYPE_TEXT, "Items available:",
					 "noop", str);
		
		/*
		THIS->more_string
		  (str + "^c1" + scnt + "^c0 items shown" +
		   (scnt == cnt ? ".\n" : " (^c1" + scnt + "^c0 unique, total ^c1" + cnt+
			"^c0 in store).\n"));*/
	 }
   return 1;
}

int
do_buy (string str)
{  
   object o;
   mapping m;
   int c;
   string *x;
   
   if (object_list && sizeof(object_list))
	 object_index = sort_array(keys(object_list), "do_sort");
   
   if (!sizeof(object_index))
	 {
		keeper (({ "Unfortunately we have nothing in stock at this time.",
		   "Sorry, we are completely out of wares.",
		   "The shop is empty, don't you see?" 
		})[random(3)]);
		return 1;
	 }
   
   x = object_index;
   
   if (!str)
	 {
		str = "";
		
		for (int i = 0; i < sizeof (x); i++)
		  {
			 m = object_list [x [i]][keys (object_list [x [i]]) [0]];
			 str += m["short_desc"] + ";";
		  }
		
		keeper (({
		   "What would you like to purchase?",
		   "Please tell me what you would like to buy.",
		   "What would you be looking for? Feel free to browse." })[random(3)]);
		
		open_window (THIS, 0,0,0,0, LTYPE_SELECT, "Buy which item?", "chat buy", str);
		return 1;
	 }
   
   
   for (int i = 0; i < sizeof (x); i++)
	 {
		m = object_list [x [i]][keys (object_list [x [i]]) [0]];
		
		if (m["short_desc"] == str)
		  break;
	 }
      
   if (!m)
	 {
		keeper (({ 
		   "I don't quite seem to have such things in stock.",
		   "I'm sorry, but we do not have such items for sale.",
		   "I can't seem to find that - could you be more specific?" })[random(3)]);
		
		return 1;
	 }

   c = sell_percent*m["c_value"];

   if (discount && discount >= 50)
	 c = c * discount / 100;

   if (THIS->query_money() < c)
	 {
		keeper (({
		   "It would cost you "+c+" coins, I really can't give you a discount.",
		   "It would cost you "+c+" coins, "+({ "sir", "sir", "madam" })[THIS->query_gender()]})[random(2)]);
		
		return 1;
	 }
   
   if ((m["weight"] + THIS->query_carried_weight()) > THIS->query_max_carry())
	 {
		keeper (({
		   "I'm afraid it is a little bit too heavy for you to carry.",
		   "It seems to be a bit too heavy for you.",
		   "It seems to be a bit heavy - maybe you should choose something lighter?" })[random(3)]);
		
		return 1;
	 }

   o = clone_object (m["file_name"]);
   o->restore_map (m["saved_map"]);
   o->create_item();

   if (produce && sizeof(produce))
	 {
		if (member_array("" + m["file_name"], produce) == -1)
		  remove_object_list (m["short_desc"], m["item_id"]);
	 }
   else
	 remove_object_list (m["short_desc"], m["item_id"]);
   
   message (CMD_SEE, THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS/2,
			"$N1 bought $p2 from $n3.",
			MAPENV(THIS), ({ THIS, o, THOB }), THIS);
   
   message (CMD_SEE, THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS/2,
			"$N1 bought $p2 from $n3 for money worth "+c+" copper pieces in total.",
			THIS, ({ THIS, o, THOB }));
      
   /* bargain_num_buy = random(100);
    *
    * if (THIS->query_skill_chance("bargain") < bargain_num_buy)
	* {
	*  if(THIS->query_cap_name() == owner)
	*	 {
	*		tell_object (THIS, "Hello "+owner+"! I will mark down your discount "
	*					 + "as we agreed to on the contract.\n");
	*		c = (c*0.7);
	*	 }
	*   tell_object (THIS, "You bought "+o->short()+" from "
	*				+THOB->query_cap_name()+" for money worth "
	*				+c+" copper pieces in total.\n");
	*   
	*   THOB->add_money(c);
	*   THIS->add_money(-c);
	* }
	* if (THIS->query_skill_chance("bargain") > (bargain_num_buy + 1))
	* {  
	*   if(THIS->query_cap_name() == owner)
	*	 {
	*		tell_object (THIS, "Hello "+owner+"! I will mark down your discount "
	*					 + "as we agreed to on the contract.\n");
	*		c = (c*0.7);
	*	 }
	*   c = (c*0.9);
	*   to_int(c);
	*   tell_object (THIS, "You manage to convince the shopkeeper to "
    *					+ "lower the price a bit.\n");
	*   tell_object (THIS, "You bought "+o->short()+" from "
	*				+THOB->query_cap_name()+" for money worth "
	*				+(c)+" copper pieces in total.\n");
	*   
	*   THOB->add_money(c);
	*   THIS->add_money(-c);
	* }
	*/
   
   THIS->add_money (-c);
   THOB->add_money (c);
   o->move (THIS, -1, -1);
   THIS->update_inv();
   
   save_object (base_name(THOB));
   return 1;
}

mapping
convert_id (string *x)
{
   mapping m;
   string  s;
   
   m = ([ ]);
   
   if (!pointerp (x))
	 return ([ ]);
   
   foreach (s in x)
	 m [s] = 1;
   
   return m;
}

mapping
get_mapping (object o)
{
   return ([  "saved_map" : o->save_map (),
"c_value" : o->query_value (),
"file_name" : base_name (o),
"short_desc" : o->query_short(),
"alias" : convert_id (o->query_name()),
"item_id" : time(),
"weight" : o->query_weight(),
"condition" : o->query_condition()
]);
}
 
int
do_sell (string str)
{
   object o, *all;
   /* int i, cnt */
   int c;
   mapping m;
      
   if (!str)
	 {
		keeper (({ "What would you like to sell?",
		   "Please do show me what are you going to sell." })[random(2)]);
		
		str = "";
		all = all_inventory (THIS);
		
		foreach (o in all)
		  str += o->query_short() + ";";
		  
		open_window (THIS, 0,0,0,0, LTYPE_SELECT, "Sell which item?", "chat sell", str);
		return 1;
    }

	o = present(THIS, str);
   
   if (!o)
	 {
		message (CMD_MSG, 0,0,0, "You have nothing which matches '"+str+"'.", THIS);
		return 1;
	 }
   
   if (!is_legal_item(o) || o->is_money() || o->query_no_autoload())
	 {
		message (CMD_MSG, 0,0,0, "$P1 cannot be sold here.", THIS, o);
		return 1;
	 }
   
   if (sizeof(all_inventory(o)))
	 {
		message (CMD_MSG, 0,0,0, "$P1 has something in it.", THIS, o);
		return 1;
	 }
   
   c = buy_percent*o->query_value();
   
   if (!c)
	 {
		c = 1;
		keeper ("That item is quite worthless crap, but i'll give 1 gp for it anyways.");
	 }

   m = get_mapping (o);

   switch (query_amount (m["short_desc"]))
	 {
	  case 15..35:
		keeper ("I've got enough of those, I'll pay half the price.");
		c = c / 2;
		break;
	  case 36..999999:
		keeper ("Oh, not one of those again? That'll go for LOW price.");
		c = c / 4;
		break;
	 }
   
   if (!c)
	 {
		keeper ("Sorry but,.. I WILL NOT BUY THOSE ANYMORE!");
		return 1;
	 }
   
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS/2,
			"$N1 {sell} $p2 to $n3.", MAPENV(THIS), ({ THIS, o, THOB }));
   
   /*
	* bargain_num_sell = random(100);
	* 
	* if(THIS->query_skill_chance("bargain") < bargain_num_sell)
	* {
	*   if(THIS->query_cap_name() == owner)
	*	 {
	*		tell_object (THIS, "Hello "+owner+"! I will mark down your discount.\n");
	*		c = (c*1.3);
	*	 }
	*   tell_object (THIS, "You sold "+o->short()+" to "
	*				+THOB->query_cap_name()+" and receive money worth "
	*				+c+" copper pieces in total.\n");
	*   
	*   THIS->add_money(c);
	*   THOB->add_money(-c);
	* }
	* if(THIS->query_skill_chance("bargain") > (bargain_num_sell + 1))
	* {
	*   if(THIS->query_cap_name() == owner)
    * {
	*  tell_object (THIS, "Hello "+owner+"! I will mark down your discount "
	*			   + "as we agreed to on the contract.\n");
	*  c = (c*1.3);
    * }
	*   c = (c*1.1);
	*   to_int(c);
	*   tell_object (THIS, "You talk the shopkeeper into paying a bit "
    *					+ "more for the item.\n");
	*   tell_object (THIS, "You sold "+o->short()+" to "
	*				+THOB->query_cap_name()+" and receive money worth "
	*				+(c)+" copper pieces in total.\n");
	*   
	*   THIS->add_money(c);
	*   THOB->add_money(-c);
	* }
	*/
   
   THIS->add_money (c);
   THOB->add_money (-c);
   
   o->move (THOB, -1, -1);
   THOB->update_inv();
   THIS->update_inv();
   
   THIS->save_me();
   THOB->save_me();
   
   add_object_list (m, 1);
   destruct (o);
   save_object (base_name(THOB));

   return 1;
}

void
keeper (string str)
{
  "/command/mortal/say"->main(str);
}

void
end_discount ()
{
   "/command/mortal/shout"->main("The discount is over for now!");
   discount = 0;
}

void
set_discount (int i)
{
   THOB->make_discount(i);
}

void
make_discount (int i)
{
   /*string s;*/
   
   if (i < 60)
	 i = 60;
   else if (i > 90)
	 i = 90;
   
   discount = i;
   
   call_out ("end_discount", 600);
   
   "/command/mortal/shout"->main("I am now selling my wares at only "+discount+"% of their normal price!");
}

void
dump_items (int t)
{
   int    z;
   
   if (t < 1)
	 return;
   
   while (t > 0 && (z = sizeof (object_index)))
	 {      
		t -= sizeof (object_list [object_index [(z = random (z))]]);
		remove_object_list (object_index [z], "*");
	 }
   
   message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS,
			"$N1 {organize} $s1 wares.", ENV(THOB), THOB);
}

void
reset_shop ()
{
   int t;
   
   if ((t = query_amount ("*")) > 100)
	 {
		if (t > 175)
		  {
			 dump_items (t-100-random(50));
		  }
		
		if (query_amount ("*") > 50)
		  make_discount (60+random(20)+random(20));
     }
   else
     {
		message (CMD_HEAR, THOB->query_gridx(), THOB->query_gridy(),
				 VISIBLE_RADIUS + 5 + random(20), ({
					"You hear someone counting money.",
					"You hear the chime of a tiny bell."
				 })[random(2)], ENV(THOB));
		
		/*
		 tell_room (ENV(THOB),
					({ "You see "+THOB->query_cap_the_name()+" counting money.\n",
					   "You see "+THOB->query_cap_the_name()+" ringing a tiny bell.\n"
					})[random(2)]);
		 */
     }

   save_object (base_name(THOB));
   call_out ("reset_shop", (10+random(20))*60);
}

void
create ()
{
  string s;

  ::create();
   
   if (file_size (base_name(THOB) + ".o") > 300000 ||
	   !restore_object (base_name (THOB)) || !object_list)
	 object_list = ([ ]);
   
   object_index = sort_array(keys(object_list), "do_sort");
   
   THOB->create_shop();
   THOB->set_no_clean_up(1);
   
   foreach (s in object_index)
	 if (sizeof(object_list[s]) > 5)
	   remove_object_list (s, "*");
   
   if (clonep(THOB))
	 call_out ("reset_shop", (10+random(20))*60);
   
  if (file_name(THOB) != "/inherit/shop")
	 save_object (base_name(THOB));
   
   THOB->add_command ("list", file_name(THOB) + "->do_list");
   THOB->add_command ("sell", file_name(THOB) + "->do_sell");
   THOB->add_command ("buy", file_name(THOB) + "->do_buy");
}

void
init_monster ()
{
   THOB->init_shop();
}

/*
 *  Contract code for merchants
 *    ++ Pook
 */

/* Commented out until those merchant skills are re-implemented.
 *    += Namhas                                         
 *
int forgetime;
int endtime;

init()
{
  ::init();
  add_action("do_propose","propose");
  add_action("do_forge","forge");
  add_action("do_check","check");
  
  restore_object (base_name (THOB));
  if (time() >= endtime)
    {owner = "null";}
}

do_propose(string what)
{
  if(what == "contract" && owner == "null")
    {
      keeper ("I will sign a contract with you, "+THIS->query_cap_name()+", for a price "
      + "of 10 gold florins.  Then, I will give you a considerable discount here for "
      + "the length of the contract. In return, I expect you to promote this shop and "
      + "bring in some business. It will last for a few weeks. If you agree to this, "
      + "type 'forge contract'.");
      return 1;
    }
  if(what == "contract" && owner != "null")
    {
     keeper ("I have already signed a contract with "+owner+".");
     return 1;
    }
}

do_forge(string what)
{
  if((THIS->query_skill_chance("shopkeeping") > 25) &&
     (THIS->query_skill_chance("bookkeeping") > 15) &&
     (THIS->query_skill_chance("salesmanship") > 15) &&
     (THIS->query_skill_chance("accounting") > 15) &&
     (THIS->query_skill_chance("currency") > 15))
  {
    if(what == "contract" && owner != "null")
      {
        keeper ("No "+THIS->query_cap_name()+", I already have a "
         + "contract with "+owner+".");
        return 1;
      } 
    if(THIS->query_money() < 1000)
      {
       keeper ("A contract with me costs 10 gold "
       + "florins "+THIS->query_cap_name()+", which you do not have.");
       return 1;
      }
    if(what == "contract" && owner == "null" && THIS->query_money() >= 1000)
      {
        keeper("Great "+THIS->query_cap_name()+"! We have signed a "
         + "contract which will last for a few weeks.");
        owner = THIS->query_cap_name();
        THIS->add_money(-1000);
        forgetime = time();
        endtime = (forgetime + 432000);
        save_object (base_name(THOB));
        return 1;
      }
  }
  else
  {
    keeper ("Sorry "+THIS->query_cap_name()+", I need someone who knows "
     + "a bit more about running a shop.");
    return 1;
  }
}

do_check(string what)
{ 
  restore_object (base_name(THOB));
  if(what == "contract" && owner != "null")
   {
    switch (432000-(time()-forgetime))
    {
      case 0..100000:
        keeper ("My contract with "+owner+" is almost up!.");
        break;
      case 100001..200000:
        keeper ("The contract I signed with "+owner+" will still be "
         + "valid for a little while.");
        break;
      case 200001..300000:
        keeper ("It will be quite a while before my contract "
         + "with "+owner+" is over.");
        break;
      case 300001..500000:
        keeper ("It has only been a short time since "+owner+" and "
         + "I forged the agreement.");
        break;
    }
    return 1;
   }
  if(what == "contract" && owner == "null")
   {
    keeper ("I do not have a contract with anyone at this "
     + "time "+THIS->query_cap_name()+".");
    return 1;
   }
  else
   {
    keeper ("You want to check what "+THIS->query_cap_name()+"?");
    return 1;
   }
}
*/
