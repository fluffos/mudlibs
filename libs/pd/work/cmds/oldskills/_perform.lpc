// dance, an ability for gypsies
// to add a dance, put the name and file in the mapping
//   below and add an object that has:
// int can_dance(object tp)
//   for level/skill req, do NOT send messages in this function
// void start_dance()
//   checks for mp/no attack/other specifics and starts the dance
//   by setting dancerounds and starting heartbeat
// void heart_beat()
//   every round this gets called once, do the main part here
// void end_dance()
//   heart_beat() calls this when the dance is over (dancerounds < 1)
// credit goes to whoever made the song system for Primal Darkness II,
//   since I used it to help make this more modular
// Kaknal 4-16-02
#include <std.h>
#define DANCEDIR "/cmds/dances/"
inherit DAEMON;
object dance;
mapping dances = ([
  "dance of the wind"          : DANCEDIR"wind",
  "fire dance"                 : DANCEDIR"fire",
  "dance of the blue oasis"    : DANCEDIR"oasis",
  "dance of a thousand nights" : DANCEDIR"nights",
  "dance of the fang"          : DANCEDIR"sword",
  "veil dance"                 : DANCEDIR"veil",
  "dance in the shadows"       : DANCEDIR"shadow"
]);
string find_dance(string str) {
  if (!dances[str]) return 0;
  return dances[str];
}
int abil();
void list_dances();
int cmd_perform(string str) {
  string dance;
  object tp=this_player();
  
  if (!abil()) {
    message("info","What?",tp);
    return 1;
  }
  if (!str) {
    list_dances();
    return 1;
  }
  if (tp->query_disable()) {
    message("info","You are too busy to dance.",tp);
    return 1;
  }
  if (tp->query_rest_type()) {
    message("info","You cannot dance unless you are standing up.",tp);
    return 1;
  }
  if (present("gypsy_dance_obj",tp)) {
    message("info","You are already dancing!",tp);
    return 1;
  }
  if (find_dance(str))
    dance=find_dance(str);
  else {
    if (dance) dance->remove();
    message("info","You don't know that dance.",tp);
    return 1;
  }
  if (!dance->can_dance(tp)) {
    if (dance) dance->remove();
    message("info","You don't know that dance.",tp);
    return 1;
  }
  if (tp->query_sp() < 60) {
    if (dance) dance->remove();
    message("info","You are too tired to dance.",tp);
    return 1;
  }  
  dance->move(tp);
  dance->start_dance();
  return 1;
}
// this should check for the lowest level dance, since it
//   determines if perform shows up on abilities
int abil() {
  object tp=this_player();
  
  if (tp &&
      tp->query_level() >= 5 &&
      tp->query_subclass() == "gypsy") return 1;
  
  return 0;
}
void list_dances() {
  object tp=this_player();
  object d;
  string *temp;
  int i, x;
  
  temp= keys(dances);
  temp= sort_array(keys(dances),1);
  
  message("info",
    "%^BLUE%^+=+=%^BOLD%^(%^RESET%^%^BOLD%^ Perform %^BLUE%^)%^RESET%^%^BLUE%^"
    "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n",
    tp);
  for (i=0, x=0; i<sizeof(temp); i++) {
    d=dances[temp[i]];
    if (d->can_dance(tp)) {
      message("info","  "+temp[i],tp);
      x++;
    }
  }
  if (!x)
    message("info","%^RED%^You don't know any dances.%^RESET%^",tp);
}
void help() {
  message("help","<perform [dance]>\nThis is the ability to perform "
    "wonderous and mystic dances. There are several dances to choose "
    "from each having their own special effects. Help dances for more info.",this_player());
}
