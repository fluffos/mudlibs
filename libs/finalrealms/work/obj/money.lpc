/* Altered August 1995 - January 1996 by Hamlet
   Added weight and shortcut ways to say 'platinum coins'.
   Added the cute little 'look coin' thingy.
  980502 Skullslayer - removed unused variables
*/
inherit "/std/object";
#include "move_failures.h"
#include "money.h"
#define WEIGHTDIV 2

mixed *money_array;
nosave int dont_join;

int query_number_coins();

void create() {
  money_array = ({ });
  ::create();
  set_name("coin");
  add_alias("Some Money For Me");
  add_plural("coins");
  set_main_plural("coins");
  add_property("determinate", "");
  add_property("no one",1);
  add_property("money",1);
}

void init() {
  add_action("do_help", "help");
}

int do_help(string str) {
  mixed *values;
  int i;

  if (!str || str != "money")
    return 0;
  write("Money values.\n");
  values = (mixed *)MONEY_HAND->query_values();
  str = "";
  for (i=0;i<sizeof(values);i+=2)
    str += sprintf("%10-s : %4d %s\n", values[i], values[i+1], values[0]);
  printf("%-*s\n", this_player()->query_cols(), str);
  return 1;
}

varargs int adjust_money(mixed amt, string type) {
  int i, val;
  
  if (pointerp(amt)) {
    for (i=0;i<sizeof(amt);i+=2)
      adjust_money(amt[i+1], amt[i]);
    return 1;
  }
  if (!stringp(type) || !intp(amt))
    return 0;
  /* Let's not allow unknown money types - Hamlet */
  if (member_array(type,(mixed *)MONEY_HAND->query_values()) == -1)
    return 0;
    
  if(environment(this_object()))
    if(interactive(environment(this_object()))) {
      val = (int)MONEY_HAND->query_value(type);
      catch(MONEY_TRACKER->update_statistics(val*amt,
            environment(this_object())));
    }
  if ((i=member_array(type, money_array)) == -1) {
    add_adjective(type);
    add_plural(type+"s");
    add_plural(type[0..0]+"cs");
    add_alias(type);  /* 'give 10 platinum to Hamlet' */
    add_alias(type[0..0]+"c");  /* 'give 10 pc to Hamlet' */
    if(type == "platinum") {
      add_alias("plat");  /* 'give 10 plat to Hamlet' */
      add_plural("plats");
      add_adjective("plat");
    }
/* order - highest value to the left of money_array */
    for(i=0; i<sizeof(money_array); i+=2) {
      val = (int)MONEY_HAND->query_value(money_array[i]);
      if((int)MONEY_HAND->query_value(type) > val) break;
    }
     
    money_array = money_array[0..(i-1)] + ({ type, amt }) +
       money_array[i..sizeof(money_array)];
  } else {
    money_array[i+1] += amt;
    if (money_array[i+1] <= 0) {
      remove_adjective(type);
      /* More Hamlet junk */
      remove_plural(type+"s");
      remove_plural(type[0..0]+"cs");
      remove_alias(type);
      remove_alias(type[0..0]+"c");
      if(type == "platinum") {
        remove_alias("plat");
        remove_plural("plats");
        remove_adjective("plat");
      }
      money_array = delete(money_array,i,2);
      set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
      return 0;
    }
  }

  set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
  return money_array[i+1];
}

mixed *query_money_array() { return money_array; }

void set_money_array(mixed *arr) { 
  int i;
  mixed *newarr = ({ });

  if(stringp(arr))
    return;
      
  for(i=0;i<sizeof(arr);i+=2)
    if (member_array(arr[i],(mixed *)MONEY_HAND->query_values()) != -1)
      newarr += ({ arr[i], arr[i+1] });
        
  money_array = newarr;
  adjectives = ({ }); /* clear them... */
  alias = ({ "Some Money For Me" }); /* clear these too */
  plurals = ({ "coins" }); /* clear these too */
  
  for (i=0;i<sizeof(money_array);i+=2) {
    add_adjective(money_array[i]);
    add_plural(money_array[i]+"s");
    add_plural(money_array[i][0..0]+"cs");
    add_alias(money_array[i]); /* Give 30 platinum to someone - Hamlet */
    add_alias(money_array[i][0..0]+"c"); /* give 30 pc to Hamlet */
    if(money_array[i] == "platinum") {
      add_alias("plat");  /* give 30 plat to Hamlet */
      add_plural("plats");
      add_adjective("plat");
    }
  }
  set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
}

string *half_short() {
  string *retval;
  int i;

  retval = ({ });
  for (i=0;i<sizeof(money_array);i+=2)
    if (money_array[i+1] > 1)
      if (this_player() != environment() && money_array[i+1] > 10)
        retval += ({ "Some "+money_array[i] });
      else
        retval += ({ money_array[i+1]+" "+ 
                           money_array[i] });
    else if (money_array[i+1] == 1)
      retval += ({ "1 "+money_array[i] });
  return retval;
}

string short(int dark) {
  mixed retval;

  retval = half_short();
  if (!sizeof(retval))
    return 0;
  if (sizeof(retval) == 1)
    return retval[0] + " coin"+(retval[0]==1?"":"s");
  return implode(retval[0..sizeof(retval)-2], ", ")+
         " and "+retval[sizeof(retval)-1] + " coin"+
         (retval[sizeof(retval)-1]==1?"":"s");
}
/*
string *pretty_short(int dark) {
  return half_short();
}
*/

string long(string str, int dark) {
  string ret = "You look at the coin and see ";
  
    ret += ({ "the handsome head of Moloch, he seems to be offering you "
              "a lollipop."
            , "the beastial head of Errtu the Nightstalker."
            , "the purple nosed visage of Rage, the drunken sot."
            , "the handsome face of Mirath the Wanderer, Carver of Mountains."
            , "a dark, indistinct form.  Very little can be seen of the face "
              "of Manshoon, betrothed of Cyrcia."
            , "the lopsided smile of that jokester of a lizard-man, "
              "Fengarance."
            , "the sneering maw of Greymist, destroyer of seas."
            , "the evil visage of Bresbane, Bringer of the Night."
				, "The smiling face of Roan, onetime Lord of Banefall."
		      , "The dark beauty of Krelk"
          })[random(10)];
  ret += "\n";
  return ret;
}

object new_money_object(int num, string type) {
  int i;
  object ob;

  if (!sizeof(money_array))
    return 0;
  if (!type)
    i = 0;
  else if ((i = member_array(type, money_array)) == -1)
    return 0;
  if (num > money_array[i+1])
    num = money_array[i+1];
  ob = clone_object(MONEY_OBJECT);
  ob->adjust_money(num, type);
  money_array[i+1] -= num;
  if (money_array[i+1] <= 0)
    money_array = delete(money_array, i, 2);
  
  /* Weight stuff -- Hamlet */
  set_weight(query_number_coins()/WEIGHTDIV);
  
  return ob;
}

varargs int move(mixed dest, mixed messin, mixed messout) {
  int j;
  object ob, mon;
  object from_where;
  from_where = environment();
  if(!from_where) from_where=
        find_player(query_property("clonedin"));

  if(environment() ) environment()->fix_my_loc_weight_later();
  j = (int)::move(dest, messin, messout);
  if (j != MOVE_OK)
    return j;
  if (objectp(dest))
    ob = dest;
  else {
    ob = find_object(dest);
    if (!ob) {
      call_other(ob, "??");
      ob = find_object(dest);
    }
  }
  remove_alias("Some Money For Me");
  remove_call_out("move");
  if (ob && (mon = present("Some Money For Me", ob)) && !dont_join) {
    for (j=0;j<sizeof(money_array);j+=2)
      mon->adjust_money(money_array[j+1], money_array[j]);
    dont_join = 1;
    move("/room/void");
     if(from_where)
      if(interactive(from_where))
      catch(MONEY_TRACKER->update_statistics(-query_value(),
          from_where));
    call_out("dest_me",0);
    return MOVE_OK;	
  }
  add_alias("Some Money For Me");
  if(ob&&interactive(ob)) {
    catch(MONEY_TRACKER->update_statistics(query_value(),ob));
    }
     if(from_where)
      if(!dont_join)
      catch(MONEY_TRACKER->update_statistics(-query_value(),
          from_where));
  set_weight(query_number_coins()/WEIGHTDIV);
  if(environment() ) environment()->fix_my_loc_weight_later();

  return MOVE_OK;
}

object query_parse_id(mixed *arr) {
  int i, j, num, l;
  string s1, *bit;
  int n1;
  object ob;
  string cn1;

  if(this_player() && this_player()->query_name() == "hamlet")
    tell_object(this_player(),sprintf("%O\n",arr));
    
  if (arr[0] == 0) {
    bit = explode(arr[1], " ");
/* Not entirely positive what this did, but changes required its removal.
   I added some of this carp back below.
   - Hamlet
 
    if (bit[sizeof(bit)-1] != "coins")
      if (environment() != this_player())
        return this_object();
      else
        return 0;
    if (sizeof(bit) == 1)
      return this_object();
*/

    if(bit[0] == "coins")
      return this_object();

    if(bit[0] == "all") {
      if(environment(this_object()) != this_player())
        return this_object();
      else
        return 0;
    }
          
    switch(bit[0]) {
      case "plat" : bit[0] = "platinum"; break;
      case "pc"   : bit[0] = "platinum";  break;
      case "gc"   : bit[0] = "gold";  break;
      case "ec"   : bit[0] = "electrum";  break;
      case "sc"   : bit[0] = "silver";  break;
      case "cc"   : bit[0] = "copper";  break;
    }
    
    i = member_array(bit[0], money_array);
    if (i == -1)
      return 0;
    num = money_array[i+1];
    s1 = money_array[i];
    money_array = delete(money_array, i, 2);
    remove_adjective(s1);
    remove_plural(s1+"s");
    remove_plural(s1[0..0]+"cs");
    remove_alias(s1);
    remove_alias(s1[0..0]+"c");
    if(s1 == "platinum") {
      remove_alias("plat");
      remove_plural("plats");
      remove_adjective("plat");
    }
    ob = clone_object(MONEY_OBJECT);
    ob->set_money_array(({ s1, num }));

    
    /* Weight stuff.  -- Hamlet */
    set_weight(query_number_coins()/WEIGHTDIV);
    
        ob->add_property("clonedin",environment()->query_name());
    ob->do_move_call_out(environment());
    return ob;
  }
/* assume if they are after a particular one they are not interested in
 * us... */
  if (arr[0] <= 0 || !sizeof(money_array))
    return 0;
  i = -1;
  
  bit = explode(arr[1]," ");
  for(l=0;l<sizeof(bit);l++) {
    switch(bit[l]) {
      case "plat"  : bit[l] = "platinum"; break;
      case "pc"    : bit[l] = "platinum";  break;
      case "gc"    : bit[l] = "gold";  break;
      case "ec"    : bit[l] = "electrum";  break;
      case "sc"    : bit[l] = "silver";  break;
      case "cc"    : bit[l] = "copper";  break;
      case "plats" : bit[l] = "platinums";  break;
      case "pcs"   : bit[l] = "platinums";  break;
      case "gcs"   : bit[l] = "golds";  break;
      case "ecs"   : bit[l] = "electrums";  break;
      case "scs"   : bit[l] = "silvers";  break;
      case "ccs"   : bit[l] = "coppers";  break;
    }
  }
/*

  if(this_player()->query_name() == "hamlet")
    tell_object(this_player(),sprintf("%O\n",arr));
*/

  arr[1] = implode(bit," ");
     
  for (j=0;j<sizeof(money_array);j+=2)
    /* This next line looks moronic, but trust me, it skirts a known sscanf()
       bug.
    */
    if (sscanf(arr[1], "%s "+money_array[j],cn1)) {
      i = j;
      sscanf(cn1,"%d",n1);
      if(n1 > 0)
        arr[0] = n1;
  }
  
  if(i == -1) {
    for(j=0;j<sizeof(money_array);j+=2)
      if(money_array[j] == arr[1][0..strlen(money_array[j])-1])
        i = j;
  }
      
  if (i == -1) {
    i = member_array("copper",money_array);
    if (i == -1)
      i = 0;
  }
  
  if( (arr[1][strlen(arr[1])-5..strlen(arr[1])-1] == "coins") &&
      (n1 <= 0) )
    arr[0] = money_array[i+1];
    
  if (arr[0] >= money_array[i+1]) {
    num = money_array[i+1];
    remove_plural(money_array[i]+"s");
    remove_plural(money_array[i][0..]+"cs");
    remove_alias(money_array[i]);
    remove_alias(money_array[i][0..0]+"c");
    if(money_array[i] == "platinum") {
      remove_alias("plat");
      remove_plural("plats");
      remove_adjective("plat");
    }
    remove_adjective(money_array[i]);
  }
  else
    num = arr[0];
  money_array[i+1] -= num;
  arr[0] -= num;
  ob = clone_object(MONEY_OBJECT);
  ob->set_money_array( ({ money_array[i], num }) );

  
  /* Weight stuff.  -- Hamlet */
  set_weight(query_number_coins()/WEIGHTDIV);
  
        ob->add_property("clonedin",environment()->query_name());
  ob->do_move_call_out(environment());  
  return ob;
}

/* you cannot sell money... */
int do_not_sell() { return 1; }
void do_move_call_out(object ob) { call_out("move",0,ob); }

int query_value() { return (int)MONEY_HAND->query_total_value(money_array); }

int query_number_coins()
{
  int i, tot;

  if(!sizeof(money_array)) return 0;
  for(i=1;i<sizeof(money_array);i+=2)
    tot += money_array[i];
  return tot;
}
