#pragma strong_types

#include <kernel.h>
#include <describe.h>
#include <prop/player.h> // Chameloid, 14-Feb-97
#include <wizlevels.h>
#include <libs.h>        // Coogan, 06-Jul-98
#include <published/peerage.h>  // Coogan, 02-Mar-01
#include <names.h>       // Coogan, 26-Mar-2011

#define ROOM_PATH_WIDTH 26 // Chameloid, 14-Feb-97

inherit "basic/time";

//////////////////////////////////////////////////////////////////////////
// mode 0, taken from /obj/player/shell
//////////////////////////////////////////////////////////////////////////

status compare_aux(mixed *a, mixed *b)
{
  return stringp(a[1]) && stringp(b[1]) && a[1] > b[1];
}

object *sorted_users()
{
    mixed *p;
    p = users();
    p = transpose_array( ({ p, map_objects(p, "query_vis_name") }) );
    p = sort_array(p, #'compare_aux);
    return transpose_array(p)[0];
}

private string map_people(object ob) 
{
    int age;
    string unit;
    string flags;
    string room;
    string name;

    name = ob -> query_vis_name();
    if (!ob->short())
      name = "["+name+"]";
    age = ob -> query_age();
    age /= 30;
    unit = "m";
    if (age >= 60) {
        age /= 60;
        unit = "h";
        if (age >= 24) {
          age /= 24;
          unit = "D";
          if (age > 999) {  // added this part, Coogan, 06-May-99
            age /= 365;
            unit = "Y";
          }
        }
    }
    if (environment(ob)) {
        room = object_name(environment(ob));
        if (room[0..6] == "players")
            room = "~"+extract(room, 8);
        else if (room[0..6] == "domains")
            room = "~"+capitalize(extract(room, 8));
        else
            room = "/"+room; }
    else
        room = "<logging on>";
    flags = (query_idle(ob) > 300) ? "I" : "";
    flags += (query_editing(ob) || query_input_pending(ob)) ? "B" : "";
    return
        sprintf("%13-s%4d %24.24-s %3d %s %2.2-s %s\n",
            name,
            ob->query_level(),
            query_ip_name(ob),
            age, unit,
            environment(ob) ? flags : "",
            room);
}

status list_peoples() 
{
    object *list;
    string file, out;
    int i, a;
    
    list = users();
    out = "There are now "+sizeof(list)+" players";
    for (i=0, a=0; i < sizeof(list); i++)
        if (query_idle(list[i]) >= 5 * 60)
            a++;
    if (a)
        out += " ("+(sizeof(list)-a)+" active)";
    out += ". "+query_load_average()+"\n";
    out += implode(
            map(
                sorted_users(),
                #'map_people,
                this_object()),
            "");
    this_player()->tell_more(out);
    return 1;
}


/////////////////////////////////////////////////////////////////////////
// mode 1, written by Carador
/////////////////////////////////////////////////////////////////////////

mapping iptable;
string *arches;

private string mode_1_make_room_name(object who) 
{
   string *wo;
   string str;
   if (!environment(who)) return "<logging on>";

   str = object_name(environment(who));
   switch(str[0..6]) {
      case "players" :
         str = "~"+extract(str,8);
         break;

      case "domains" :
         str = "~"+capitalize(extract(str,8));
         break;
      
      default :
         str = "/"+str;
         break;
   }
   if (strlen(str) <= ROOM_PATH_WIDTH) return str;
   wo = explode(str[1..], "/");
   return str[0..0] + wo[0] + "/.../" + wo[<1];
}


// This functions is very specifically for Tubmud, you have to trick here
// when you export our Mudlib to another mud.

private string mode_1_make_town(object ob) {
  return LIB_INTERNET->player2town(ob);
}

status mode_1_before(object ob1, object ob2) {
  string n1, n2;
  int p1, p2;

  n1 = ob1->query_real_name();
  n2 = ob2->query_real_name();

  if (n1 == GOD) return 1;
  if (n2 == GOD) return 0;

  p1 = SECURITY->query_is_wizard(n1);
  if (p1) {
    if (p1 == 2 && member(arches, n1) > -1)
      p1++;
    p1 += 100000;
  }
  else
    p1 = ob1->query_level();
  p2 = SECURITY->query_is_wizard(n2);
  if (p2) {
    if (p2 == 2 && member(arches, n2) > -1)
      p2++;
    p2 += 100000;
  }
  else
    p2 = ob2->query_level();

  if (p1 != p2)
    return p1 > p2;
#ifndef NEW_LEVELS
  return n1 > n2;
#else
  if (p1 >= WL_APPRENTICE)
    return n1 > n2;
  return LIB_ADVANCE->query_promille_sum(ob1) >
         LIB_ADVANCE->query_promille_sum(ob2);
#endif
}

status people_mode_1() {
   int i;
   string output;
   string peer;
   object *list, peer_control;
   mixed tmp;
   int t1, t2;

   if (!iptable) {
     iptable = ([ 
       "139.30.12.1" : "Rostock",
       "143.93.160.3" : "Worms",
       "192.109.89.38" : "Bochum",
       "130.149.19.19" : "Berlin",
       "132.180.136.1" : "Bayreuth",
       "148.202.30.72" : "[Mexico]",
       "148.202.30.71" : "[Mexico]",
       "194.77.84.2" : "Frankfurt",
       "141.44.30.42" : "Magdeburg"
    ]);

    arches =
      ("/room/mailing_lists"->query_mailing_list("arches") || ({})) -
       ({ "demos", "macbeth" });
   }

   tmp = ctime(time());
   tmp = tmp[8..9]+"-"+tmp[4..6]+"-"+tmp[22..23]+" "+tmp[11..15];
   list = sort_array(users(), #'mode_1_before);

   i = sizeof(filter(list, lambda(({ 'x }),
     ({ #'<, ({ #'query_idle, 'x }), 300 }))));

   output = "-- Players: "+sizeof(list)+" (" + i + " active) -- "+
            "Time: "+tmp+" -- Load: " + 
	    explode(query_load_average(), ", ")[0] + " --\n\
Name           Level             Room            Age G E Idle     Town, Country\n\
-------------------------------------------------------------------------------\n\
";
   if (sizeof(list)) 
     t1 = SECURITY->query_is_wizard(list[0]->query_real_name());
   for (i=0;i<sizeof(list);i++) {
      t2 = SECURITY->query_is_wizard(list[i]->query_real_name());
      if (t2 != t1) {
        t1 = t2;
	output += "\
-------------------------------------------------------------------------------\n";
      }
      if (!list[i]->query_vis_name()) continue;
#ifdef PEERAGE
        if ((tmp = PEERAGE_CLAN(list[i]))) {  // added "P" for wiz_clan,
                                              // Coogan, 10-Aug-98
        peer = "" + (tmp == "wiz_clan" ? "P" : capitalize(tmp[0..0])) +
               (((tmp = PEERAGE_RANK(list[i])) && tmp > 0) ? tmp : "");
      } else
#endif
         if (
#ifdef TUBMUD
             list[i]->test_flag(96) ||
#endif
             list[i]->query_property(P_TESTPLAYER))
        peer = "T";
      else
        peer = "";

      if (!list[i]->short())
        tmp = "[" + list[i]->query_vis_name() + "]";
      else if (list[i]->query_away())
        tmp = list[i]->query_vis_name() + " (absent)";  // Coogan, 06-Jul-98
      else if (list[i]->query_frog())
        tmp = list[i]->query_vis_name() + " (frog)";
      else if (list[i]->query_ghost())
        tmp = list[i]->query_vis_name() + " (ghost)";
      else if (list[i]->query_vis_name() != list[i]->query_name())
        tmp = list[i]->query_vis_name() + " (" + 
	   describe(list[i], ARTICLE_NONE) + ")";
      else tmp = list[i]->query_vis_name();
      output += sprintf("%:-14s %:|2s %:-2s %:-"+ROOM_PATH_WIDTH+
                        "s %:4s %:-3s %3s %:18s\n",
	  tmp,
	  (list[i]->query_level() < 1000 ? ""+list[i]->query_level() : "1k"),
	  peer,
	  mode_1_make_room_name(list[i]),
	  heart_short(list[i]->query_age()),
	    ({ ".", "N", "M", "F", "P" }) [(int) list[i]->query_gender() + 1] +
	    " " +
	    ({ ".","I","E","B" }) [ !!query_input_pending(list[i]) + 
				    !!query_editing(list[i]) * 2 ],
	  time_short(query_idle(list[i])),
	  mode_1_make_town(list[i])
	);
   }
   output += "\
-------------------------------------------------------------------------------\n";
#if 0
   this_player()->view_text(output, "people");
   this_player()->start_view();
#else
   this_player()->tell_more(output);
#endif
   return 1;
}



////////////////////////////////////////////////////////////////////////
// global section, add further modes here
////////////////////////////////////////////////////////////////////////

status do_people(string str) {
  if (!str)
    str = "default";

  switch(str) {
  case "mode 1":
#ifdef TUBMUD
  case "default":
#endif
    return people_mode_1();

  case "mode 0":
#ifndef TUBMUD
  case "default":
#endif
    return list_peoples();

  default :
    write("This mode does not exist. There's only 'mode 0' and 'mode 1'.\n");
    return 1;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

