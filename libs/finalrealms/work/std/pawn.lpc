/* pawn shop to allow people to get money for possessions and get them back
   within a certain period of time. */

inherit "std/room";

#include "money_adjust.h"
#include "shop.h"
#include "money.h"
#include "move_failures.h"
void clean_up(int flag) { }
int clean_up_room(int flag) { return 1; }

#define VALUE query_value() * 2 / 5
#include "timestuff.h"

string *people;
object *objs;
int *times;
string store, shop;
int hold_time;
string *buy_mess, *sell_mess, list_mess, value_mess;
/* price adjustment variables and functions, Anirudh */
mapping market_data, race_prefs;
int last_changed_price,handled_since_last;
int do_weight_min(int amt, int weight, int material, int buysell);
int do_cha_adjust(int amt, int cha, int updown);
int do_race_adjust(int amt, string race, int updown);
int set_race_pref(string race, int race_perc);
void add_bought(object ob);
void add_sold(object ob);
void add_new_item(object ob,string str);
void check_adjust_prices();
void adjust_prices();
void reset_market();
int query_multiplier(object ob);

void create() {
  market_data = ([ ]);
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
  restore_object(file_name(this_object()));
  people = ({ });
  objs = ({ });
  times = ({ });
  store = "/room/pawnstore";
  shop = "/room/storeroom";
  hold_time = 1800;
  set_short("Pawn Shop");
  set_long(
"You are in a Pawn shop.  You can value, leave and reclaim things here.  "
"There is a sign describing how the shop works.\n");
  set_light(60);
  buy_mess = ({ "You reclaim $ob$ for $money$.\n",
                "$client$ reclaims $ob$.\n" });
  sell_mess = ({ "You leave $ob$ for $money$.\n",
                 "$client$ leaves $ob$.\n" });
  list_mess = "$ob$\t\t$money$\n";
  value_mess = "The $ob$ would get you $money$.\n";
  ::create();
}

void set_sell_message(mixed str) { sell_mess = str; }
void set_buy_message(mixed str) { buy_mess = str; }
void set_value_message(mixed str) { value_mess = str; }
void set_list_message(mixed str) { list_mess = str; }

mixed query_sell_mess() { return sell_mess; }
mixed query_list_mess() { return list_mess; }
mixed query_value_mess() { return value_mess; }
mixed query_buy_mess() { return buy_mess; }

void dest_me() {
  int loop;

  if(!people) people = ({ });
  for(loop = 0; loop < sizeof(people); loop++) {
    tell_object(find_living(people[loop]), 
"A little person runs up to you and hands you a note, then vanishes again.\n"
"The note reads:\n"
"Pawnbroker has gone broke.  " + objs[loop]->query_name() + " sold to shop.\n");
    objs[loop]->move(shop);
  }
  ::dest_me();
}

string pawn_parse(string str, object ob, object client, string money,
                         string extra) {
  string s1,s2,s3,rest;

  rest = "";
  while(sscanf(str,"%s$%s$%s", s1, s2, s3) == 3)
    switch (s2) {
      case "ob" :
        str = s1+ob->short()+s3;
        break;
      case "client" :
        str = s1+client->query_name()+s3;
        break;
      case "extra" :
        str = s1+extra+s3;
        break;
      case "money" :
        str = s1+money+s3;
        break;
      default :
        rest = s1+"$"+s2+"$";
        str = s3;
        break;
    }
  return rest+str;
}

void do_parse(mixed arr, object ob, object client, string money,
                         string extra) {
  if (stringp(arr))
    write(pawn_parse(arr, ob, client, money, extra));
  else {
    write(pawn_parse(arr[0], ob, client, money, extra));
    say(pawn_parse(arr[1], ob, client, money, extra));
  }
}

void init() {
  ::init();
  add_action("read", "read");
  add_action("value_item", "value");
  add_action("leave_item", "leave");
  add_action("reclaim_item", "reclaim");
  add_action("list_items", "list");
}

int read(string str) {
  if(str != "sign") {
     notify_fail("The only thing here to read is a sign.\n");
    return 0;
  }
  write("You can leave things here in exchange for cash.  The value of the "
        "item determines the amount of cash you can get for it.  If you do "
        "not return and claim your item within " + 
        (hold_time / 60) +  " minutes, then it "
        "will be sold to a shop to reclaim its worth.\n"
        "You can leave <item>, reclaim <item>, list, and value <item> here.\n"
        "Selling things here gets you less money than the shop, but "
        "reclaiming the item does not cost as much as buying it back from the "
        "shop would.\n");
  return 1;
}

void set_storeroom(string str) {
  store = str;
}

string query_storeroom() {
  return store;
}

void set_shop(string str) {
  shop = str;
}

string query_shop() {
  return shop;
}

void set_hold_time(int time) {
  hold_time = time;
}

int query_hold_time() {
  return hold_time;
}

int set_race_pref(string race, int race_perc) {
  int i;
  if(!m_sizeof(race_prefs)) race_prefs = ([ ]);
  if(race_perc != -1 && race_perc < 100) race_perc = 100;
  if(race == "good") {
    for(i=0;i<sizeof(GOOD_RACES);i++)
      race_prefs[GOOD_RACES[i]] = race_perc;
    return race_perc;
  }
  if(race == "neutral") {
    for(i=0;i<sizeof(NEUTRAL_RACES);i++)
      race_prefs[NEUTRAL_RACES[i]] = race_perc;
    return race_perc;
  }
  if(race == "evil") {
    for(i=0;i<sizeof(EVIL_RACES);i++)
      race_prefs[EVIL_RACES[i]] = race_perc;
    return race_perc;
  }
  race_prefs[race] = race_perc;
  return race_perc;
}

int value_item(string str) {
  object *ob;
  int loop,real_val, mass, material;

  if(!str) {
    notify_fail("Value what?\n");
    return 0;
  }
  ob = find_match(str, this_player());
  if(!sizeof(ob)) {
    notify_fail("You do not have a " + str + ".\n");
    return 0;
  }
  for(loop = 0; loop < sizeof(ob); loop ++) {
    real_val = "/std/shop"->scaled_value((int)ob[loop]->query_value())*4/5;
    real_val=real_val*MONEY_TRACKER->query_adj_fact(SBFLAG)/1000;
    real_val = real_val*query_multiplier(ob[loop])/1000;
        real_val = do_weight_min(real_val,ob[loop]->query_weight(),
                     ob[loop]->query_material(),1);
        real_val = do_cha_adjust(real_val,this_player()->query_cha(),1);
        if((real_val = do_race_adjust(real_val,this_player()->
          query_race(),1)) == -101) {
            notify_fail("This shop refuses to deal with your "+
                        "race.\n");
            return 0;
        }
    do_parse(value_mess, ob[loop], this_player(),
        (string)MONEY_HAND->money_string((mixed *)MONEY_HAND->
            create_money_array(real_val)), "");
  }
  return 1;
}

int leave_item(string str) {
  object *ob;
  mixed *ma;
  string person;
  int loop, money_to_give, the_time, pos, mass, material;

  if(!str) {
    notify_fail("Leave what?\n");
    return 0;
  }
  ob = find_match(str, this_player());
  if(!sizeof(ob)) {
    notify_fail("You do not have a " + str + ".\n");
    return 0;
  }
  person = (string)this_player()->query_name();
  the_time = time();
  for(loop = 0, money_to_give = 0; loop < sizeof(ob); loop++) {
    int temp, loop2;

    temp = (int)"/std/shop"->scaled_value((int)ob[loop]->
           query_value()) * 4 / 5;
    temp=temp*MONEY_TRACKER->query_adj_fact(SBFLAG)/1000;
    temp = temp*query_multiplier(ob[loop])/1000;
    temp = do_weight_min(temp,ob[loop]->query_weight(),
                     ob[loop]->query_material(),1);
    temp = do_cha_adjust(temp,this_player()->query_cha(),1);
    if((temp = do_race_adjust(temp,this_player()->query_race(),1))==
          -101) { notify_fail("This shop refuses to deal with your "+
                        "race.\n");
                  temp = 0;
                  return 0;
    }
    if(temp > MAX_AMOUNT) {
       temp = MAX_AMOUNT;
    }
    if (!this_player()->query_creator())
            add_bought(ob[loop]);
    money_to_give += temp;
    people += ({ person });
    objs += ({ ob[loop] });
    times += ({ the_time });
    ob[loop]->move(store);
    say((string)this_player()->query_cap_name() + " leaves a " + 
        ob[loop]->query_name() + " here.\n");
    call_out("end_hold", hold_time, ob[loop]);
  }
  ma = (mixed *)MONEY_HAND->create_money_array(money_to_give);
  this_player()->adjust_money(ma);
  write("The pawnbroker gives you " +
       MONEY_HAND->money_string(ma) + ".\n");
  return 1;
}

void end_hold(object ob) {
  int pos;

  if(!ob) {
    return;
  }
  pos = member_array(ob, objs);
  ob->move(shop);
  if(pos == -1) {
    return 0;
  }
  tell_object(find_living(people[pos]), "Time limit for " + ob->query_name() + " has expired.\n");
  people = delete(people, pos, 1);
  objs = delete(objs, pos, 1);
  times = delete(times, pos, 1);
}

int reclaim_item(string str) {
  object *ob;
  int loop, money_to_give, mass, material;

  if(!str) {
    notify_fail("reclaim what?\n");
    return 0;
  }
  ob = find_match(str, store);
  if(!sizeof(ob)) {
    notify_fail("There are no " + str + "'s here.\n");
    return 0;
  }
  for(loop = 0; loop < sizeof(ob); loop++) {
    int pos, amt, ob_amt;

    pos = member_array(ob[loop], objs);
    if(pos != -1) {
      amt = (int)this_player()->query_value();
      ob_amt = (int)"/std/shop"->scaled_value((int)ob[loop]->query_value());
    ob_amt=ob_amt*MONEY_TRACKER->query_adj_fact(SSFLAG)/1000;
      ob_amt = ob_amt*query_multiplier(ob[loop])/1000;
      ob_amt = do_weight_min(ob_amt,ob[loop]->query_weight(),
                     ob[loop]->query_material(),0);
      ob_amt = do_cha_adjust(ob_amt,this_player()->query_cha(),0);
      if((ob_amt = do_race_adjust(ob_amt,this_player()->query_race(),0))==
          -101) { notify_fail("This shop refuses to deal with your "+
                        "race.\n");
                   return 0;
      }
    if (ob_amt < 1) ob_amt = 1;
      if (ob_amt < amt) {
        if (!this_player()->query_creator())
            add_sold(ob[loop]);
        amt -= ob_amt;
        money_to_give -= ob_amt;
        do_parse(buy_mess, ob[loop], this_player(),
           (string)MONEY_HAND->money_string((mixed *)MONEY_HAND->
              create_money_array(ob_amt)),"");
        if(ob[loop]->move(this_player()) != MOVE_OK) {
          ob[loop]->move(this_object());
          write("It is too heavy for you and he puts it down in front of you.\n");
        }
        objs = delete(objs, pos, 1);
        people = delete(people, pos, 1);
        times = delete(times, pos, 1);
      }
      else {
        write("You cannot afford to reclaim "+
              (string)objs[pos]->query_name()+".\n");
      }
    }
  }
  write("This is costing you " + money_to_give + "\n");
  this_player()->pay_money(({ "brass", -money_to_give }) );
  return 1;
}

int list_items() {
  int loop, flag,real_val, mass, material;
  string person;

  person = (string)this_player()->query_name();
  for(flag = loop = 0; loop < sizeof(objs); loop++) {
    if(people[loop] == person) {
      flag = 1;
      real_val = (int)"/std/shop"->scaled_value((int)objs[loop]->
                 query_value());
    real_val=real_val*MONEY_TRACKER->query_adj_fact(SSFLAG)/1000;
      real_val = real_val*query_multiplier(objs[loop])/1000;
      real_val = do_weight_min(real_val,objs[loop]->query_weight(),
                     objs[loop]->query_material(),0);
      real_val = do_cha_adjust(real_val,this_player()->query_cha(),0);
      if((real_val = do_race_adjust(real_val,this_player()->
        query_race(),0))==-101) {
          notify_fail("This shop refuses to deal with your "+
                        "race.\n");
                   return 0;
      }
        if (real_val < 1) real_val = 1;
      do_parse(list_mess, objs[loop], this_player(),
         (string)MONEY_HAND->money_string((mixed *)MONEY_HAND->
             create_money_array(real_val)), "");
    }
  }
  if(!flag) {
    write("Nothing left here by you.\n");
  }
  return 1;
}
/* changing price functions, Anirudh */

int do_race_adjust(int amt, string race,int updown) {
  int temp;
  if(!m_sizeof(race_prefs)) race_prefs = ([ ]);
  if(!race_prefs[race]) return amt;
  if(race_prefs[race] == -1) return -101;
  if(updown) {
    temp = amt*100/race_prefs[race]+1;
    if(temp > amt) return amt;
    return temp;
  }
  else {
    temp = amt*race_prefs[race]/100-1;
    if(temp < amt) return amt;
    return temp;
  }
  return amt;
}

int do_weight_min(int amt,int mass, int material, int buysell) {
  if(buysell) {
    if (material == 2 && amt < mass*4/5) amt = mass*4/5;
    else if (material == 1 && amt < mass/5) amt = mass/5;
    else if (material == 3 && amt < mass*4/35) amt = mass*4/35;
    else if (amt < mass*2/25) amt = mass*2/25;
  }
  else {
    if (material == 2 && amt < mass*6/5) amt=mass*6/5;
    else if (material == 1 && amt < mass*3/10 ) amt=mass*3/10;
    else if (material == 3 && amt < mass*6/35) amt=mass*6/35;
    else if (amt < mass*3/25) amt = mass*3/25;
  }
  return amt;
}

int do_cha_adjust(int amt, int cha, int updown) {
  int temp;
  if(!cha) return amt;
  if(cha > 19) cha = 19;
  if(cha > AVG_CHA) {
    temp = 10*(cha - AVG_CHA)*CHA_AD*5/(18-AVG_CHA)/4;
    if(temp > 100 && cha > 11) temp = 100;
    if(updown) {
      temp = amt*(1000+temp)/1000-1;
      if(temp < amt) return amt;
    }
    else {
      temp = amt*1000/(1000+temp)+1;
      if(temp > amt) return amt;
    }
    return temp;
  }
  if(cha < AVG_CHA) {
    temp = 10*(AVG_CHA-cha)*CHA_AD*5/(AVG_CHA-3)/4;
    if(updown) {
      temp = amt*1000/(1000+temp)+1;
      if(temp > amt) return amt;
    }
    else {
      temp = amt*(1000+temp)/1000-1;
      if(temp < amt) return amt;
    }
    return temp;
  }
  return amt;
}

int query_multiplier(object ob) {
    int i;
    string item_path; 
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    item_path = explode(file_name(ob),"#")[0];
    if (market_data[item_path])
          return market_data[item_path][4];
    else 
          return 1000;
} 

/* note:  this is the function when the SHOP buys something */
void add_bought(object ob) {
    int i;
    string item_path;
    if(this_player()->query_creator() ||
      strsrch(this_player()->query_name(),"test") != -1)
      return;
    if (!m_sizeof(market_data)) 
        restore_object(file_name(this_object()),1);
    item_path = explode(file_name(ob),"#")[0];
    if (market_data[item_path])
          market_data[item_path][1]++;
    else {
        add_new_item(ob,item_path);
        if (market_data[item_path])
            market_data[item_path][1]++;
    }
    handled_since_last++;
    check_adjust_prices();
    if (m_sizeof(market_data))
       save_object(file_name(this_object()));
}

/* and this is when the SHOP sells something */
void add_sold(object ob) {
    int i;
    string item_path;
    if(this_player()->query_creator() ||
      strsrch(this_player()->query_name(),"test") != -1)
      return;
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    item_path = explode(file_name(ob),"#")[0];
    if (market_data[item_path])
          market_data[item_path][2]++;
    else {
          add_new_item(ob,item_path);
        if (market_data[item_path])
          market_data[item_path][2]++;
    }
    handled_since_last++;
    check_adjust_prices();
    if (m_sizeof(market_data))
       save_object(file_name(this_object()));
}

void add_new_item(object ob, string item_path) {
    if (!market_data[item_path]) {
          market_data[item_path] = ({ ob->query_value(),0,0,0,1000,0 });
    }
}

void check_adjust_prices() {
    int timelapsed = TIMEKEEPER->query_running_time()-
        last_changed_price;
    if (timelapsed <= 0 || last_changed_price == 0) {
        reset_market();
    }
    else if ( handled_since_last > 300 || timelapsed > BASE_WEEK) {
        adjust_prices();
    }
}

void adjust_prices() {
    string *item_paths,ite;        
    int i,changemult,timelapsed,devisor,goaldif;
    if(!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    timelapsed = TIMEKEEPER->query_running_time()-last_changed_price;
    /* don't want to overflow maxint here (percent of a week here) */
    if (timelapsed < 20000000) {
        timelapsed = timelapsed*100/BASE_WEEK;
    }
    else timelapsed = timelapsed*10/BASE_WEEK*10;
    item_paths = m_indices(market_data);
    for (i=0;i<sizeof(item_paths);i++) {
          ite = item_paths[i];
          if (market_data[ite][5]) {
                market_data[ite][5] = 0;
            market_data[ite][1]=market_data[ite][2]=0;
                continue;
          }
          /* going to deal in 100ths of items... */
        goaldif=market_data[ite][2]-market_data[ite][1]+1;
             goaldif*=100;
          devisor = 2*market_data[ite][2]+market_data[ite][1];
          if (!devisor) devisor = 10;
          changemult = goaldif*goaldif/(100*devisor);
          if (goaldif > 0) {
             market_data[ite][4] = market_data[ite][4]*11/10;
             if (market_data[ite][4] > 1000)
                market_data[ite][4] = 1000;
          }
          if (goaldif < 0) {
             if (changemult > 2000) changemult = 2000;
             market_data[ite][4] = market_data[ite][4]*
                   1000/(1000+changemult);
             if (market_data[ite][4]<10) market_data[ite][4]=10;
          }
          market_data[ite][1]=market_data[ite][2]=0;
          if (market_data[ite][4] == 1000)
             market_data = m_delete(market_data,ite);
    }        
    last_changed_price = (int) TIMEKEEPER->query_running_time();
    handled_since_last = 0;
    if (m_sizeof(market_data))
        save_object(file_name(this_object()));
}
mapping query_market_data() {
    return market_data;
}

void reset_market() {
    string *item_paths,ite;
    int i;
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    item_paths = m_indices(market_data);
    for (i=0;i<sizeof(item_paths);i++) {
          ite = item_paths[i];
          market_data[ite][5] = market_data[ite][1]=
              market_data[ite][2]=0;
    }
    last_changed_price = TIMEKEEPER->query_running_time();
    handled_since_last = 0;
    if (m_sizeof(market_data)) save_object(file_name(this_object()));
}
int set_md_value(string which_item,int which_one,int new_value) {
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    if(market_data[which_item]) {
        market_data[which_item][which_one] = new_value;
    }
    if (m_sizeof(market_data)) save_object(file_name(this_object()));
    if(market_data[which_item])
        return market_data[which_item][which_one];
    else return -101;
}
