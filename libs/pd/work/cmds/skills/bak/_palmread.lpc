// palmread, lets a gypsy tell the fortune of a player
// also checks for items in inventory with
//   set_property("scrying tool",10);
//   so crystal balls, amulets, etc can be made if wanted
// Kaknal 4-15-02
#include <daemons.h>
inherit DAEMON;
string msg;
int abil();
void fingers4(object tp, int str, int wis);
void fingers5(object tp, int str, int wis);
void fingers6(object tp, int str, int wis);
void finish_palm(object tp, int age, int deaths, int marriages,
                 int kills, int quests, int str, int wis);
int cmd_palmread(string who) {
  object tp=this_player();
  object tgt;  
  object *inv;
  int skill, i;
  int deaths, age, marriages;
  int kills, quests, str, wis;
  if (!abil()) {
    message("info","What?",tp);
    return 1;
  }
  if (!who) {
    message("info","Read whose palm?",tp);
    return 1;
  }
  if (tp->query_mp() < 30) {
    message("info","Not enough magic.",tp);
    return 1;
  }
  
  if (tp->query_disable()) {
    message("info","You are busy.",tp);
    return 1;
  }
  if (tp->query_current_attacker()) {
    message("info","You are too busy fighting.",tp);
    return 1;
  }
  
  tgt=present(who,environment(tp));
  if (!tgt) {
    message("info","You don't see "+who+" here.",tp);
    return 1;
  }
  if (!userp(tgt)) {
    message("info","You cannot read the palm of "+tgt->query_cap_name()+".",
      tp);
    return 1;
  }
  if (tgt->query_current_attacker()) {
    message("info",nominative(tgt)+" is too caught up in battle to show "
      "you "+possessive(tgt)+" palm.",tp);
    return 1;
  }
  // these races either don't have hands, or have some kind of hand
  //   without normal skin on it
  if (tgt->query_race() == "dragon" ||
      tgt->query_race() == "lich" ||
      tgt->query_race() == "raknid") {
    
    message("info","That creature does not have a palm.",tp);
    return 1;
  }
  
  // if their hands are both severed we can't read them very well..
  if (member_array("right hand",tgt->query_limbs()) == -1 &&
      member_array("left hand",tgt->query_limbs()) == -1) {
    message("info",nominative(tgt)+" has only stumps where "+possessive(tgt)+
      " hands should be.",tp);
    return 1;
  }
  if (tgt == tp) {
    message("info","You look over your own palm...\n",tp);
    message("info",tp->query_cap_name()+" examines "+possessive(tp)+" palm.",
      environment(tp), tp);
  }
  else {
    message("info","You look over "+tgt->query_cap_name()+"'s palm...\n",tp);
    message("info",tp->query_cap_name()+" examines the palm of your hand.",tgt);
    message("info",tp->query_cap_name()+" examines the palm of "+
      tgt->query_cap_name()+"'s hand.", environment(tp), ({ tgt, tp }) );
  }
  tp->set_disable();
  tp->add_mp(-(95+random(30)));  
  // a little roleplaying spice
  if (tgt->query_race() == "archangel") {
    message("info","The archangel's palm is completely perfect, "
      "no lines can be seen.",tp);
    return 1;
  }
  if (tgt->query_race() == "demon") {
    message("info","The demon's palm is infinitely scarred and "
      "you are unable to read it.",tp);
    return 1;
  }
  skill=tp->query_skill("clairvoyance");
  skill+= random(20);
  
  // this lets you create items that aid in fortune telling,
  //   same as lockpicks aid in lockpicking
  // property should range from 5 to about 30 depending on item
  inv=all_inventory(tp);
  for (i=0; i<sizeof(inv); i++) {
    if (inv[i]->query_property("scrying tool"))
      skill+= inv[i]->query_property("scrying tool");
  }
  if (skill < 1) skill=1;
  // all these variables start from 0
  // number of seconds since creation
  age= tgt->query_age();
  // 4838400 == 56 real life days (2 lunar months)
  age= age/4838400;
  if (random(2))
    age+= random(60/skill);
  else
    age-= random(60/skill);
  if (age < 0) age=0;
  if (age > 4) age=4;
  deaths= sizeof(tgt->query_deaths());
  switch (deaths) {
    case 0:
      deaths=0; break;
    case 1: case 2: case 3:
      deaths=1; break;
    case 4: case 5: case 6: case 7: case 8:
      deaths=2; break;
    default:
      deaths=3;
  }
  if (random(2))
    deaths+= random(50/skill);
  else
    deaths-= random(50/skill);
  if (deaths < 0) deaths=0;
  if (deaths > 3) deaths=3;
  if (deaths > 1 && age == 1) age=2;
  marriages= sizeof(tgt->query_divorced())+sizeof(tgt->query_married());
  switch (marriages) {
    case 0:
      marriages=0; break;
    case 1:
      marriages=1; break;
    case 2: case 3: case 4:
      marriages=2; break;
    default:
      marriages=3;
  }
  if (random(2))
    marriages+= random(40/skill);
  else
    marriages-= random(40/skill);
  if (marriages < 0) marriages=0;
  if (marriages > 3) marriages=3;
  kills= sizeof(tgt->query_kills());
  kills= kills/200;
  if (random(2))
    kills+= random(45/skill);
  else
    kills-= random(45/skill);
  if (kills < 0) kills=0;
  if (kills > 5) kills=5;
  
  quests= sizeof(tgt->query_quests()) + sizeof(tgt->query_mini_quests())/2;
  quests= quests/6;
  if (random(2))
    quests+= random(65/skill);
  else
    quests-= random(65/skill);
  if (quests < 0) quests=0;
  if (quests > 5) quests=5;
  str= tgt->query_base_stats("strength")+tgt->query_base_stats("constitution");
  str+= tgt->query_physical()*4;
  str= str/25;
  switch (str) {
    case 0:
      str=0; break;
    case 1: case 2:
      str=1; break;
    case 3: case 4: case 5:
      str=2; break;
    case 6: case 7: case 8:
      str=3; break;
    default:
      str=4;
  }
  if (random(2))
    str+= random(55/skill);
  else
    str-= random(55/skill);
  if (str < 0) str=0;
  if (str > 4) str=4;
  wis= tgt->query_base_stats("wisdom")+tgt->query_base_stats("intelligence");
  wis+= tgt->query_spiritual()*4;
  wis= wis/30;
  switch (wis) {
    case 0:
      wis=0; break;
    case 1: case 2: case 3:
      wis=1; break;
    case 4: case 5: case 6: case 7:
      wis=2; break;
    default:
      wis=3;
  }
  if (random(2))
    wis+= random(70/skill);
  else
    wis-= random(70/skill);
  if (wis < 0) wis=0;
  if (wis > 3) wis=3;
  // if a new race is added with <4 or >6 fingers this will need 
  //   to be changed (and a new ascii pic made *groan*)
  // note that raknids (2 fingers) and dragons (3) don't have palms
  switch(tgt->query_fingers()) {
    case 4:
      fingers4(tgt, str, wis);
      break;
    case 5:
      fingers5(tgt, str, wis);
      break;
    case 6:      
      fingers6(tgt, str, wis);
      break;
    default:
      message("info","If you see this, there's a bug, "
        "report it to the immortals.",tp);
  }
  finish_palm(tp, age, deaths, marriages, kills, quests, str, wis);
  tp->add_skill_points("clairvoyance",10+random(5));
  return 1;
}
int abil() {
  
  object tp=this_player();
  
  if (tp &&
      tp->query_subclass() == "gypsy" &&
      tp->query_skill("clairvoyance") >= 18)
    return 1;
  
  return 0;
  
}
// these functions just display the top part of each
//   hand, since below the fingers they're all the same
// all " and \ characters need to be escaped with a \ in front of them
void fingers4(object tp, int str, int wis) {
  msg=
    "        /\"\"\"\\\n"
    "       |     |/\"\"\\\n"
    "   /\"\"\\|     |    |\n"
    "  |    |     |    |\n"
    "  |    | ~~~ | ~~ |\n"
    "  | ~~ |     |    |/\"T\\\n"
    "  |    |     |    |  \\|\n";
  
  if (wis == 3) {
    msg+="  |    | ~~~%^BLUE%^.%^RESET%^  ~~ |   |\n";
    msg+="  | ~~   %^BLUE%^._/'%^RESET%^";
  }
  else {
    msg+="  |    | ~~~   ~~ |   |\n";
    if (wis == 2)
      msg+="  | ~~   %^BLUE%^.%^RESET%^   ";
    else
      msg+="  | ~~       ";
  }
  if (str >= 2)
    msg+="%^RED%^..%^RESET%^";
  else if (str == 1)
    msg+=" %^RED%^.%^RESET%^";
  else
    msg+="  ";
  
  msg+="   |   >\n";
  
}
void fingers5(object tp, int str, int wis) {
  msg=
    "           /\"\\\n"
    "       /\"\\|   |/\"\\\n"
    "      |   |   |   |\n"
    "      |   |   |   |\n"
    "   /\"\\|   | ~ |   |\n"
    "  |   | ~ |   | ~ |\n"
    "  |   |   |   |   |/\"T\\\n"
    "  |   |   | ~ |   |  \\|\n";
  
  if (wis == 3) {
    msg+="  |   | ~   %^BLUE%^.%^RESET%^   ~ |   |\n";
    msg+="  | ~    %^BLUE%^._/'%^RESET%^";
  }
  else {
    msg+="  |   | ~       ~ |   |\n";
    if (wis == 2)
      msg+="  | ~    %^BLUE%^.%^RESET%^   ";
    else
      msg+="  | ~        ";
  }
  if (str >= 2)
    msg+="%^RED%^..%^RESET%^";
  else if (str == 1)
    msg+=" %^RED%^.%^RESET%^";
  else
    msg+="  ";
  
  msg+="   |   >\n";
}
void fingers6(object tp, int str, int wis) {
  msg=
    "         /\\ /\\\n"
    "      /\\|  |  |/^\\\n"
    "     |  |  |  |   |\n"
    "   /\\|  |  |  |   |\n"
    "  |  |  | ~| ~|   |\n"
    "  |  | ~|  |  | ~ |/Y\\\n"
    "  | ~|  |  |  |   |  \\|\n"
    "  |  |  |  |  |   |   |\n";
  
  if (wis == 3) {
    msg+="  |  | ~  ~ %^BLUE%^.%^RESET%^~  ~ |   |\n";
    msg+="  | ~    %^BLUE%^._/'%^RESET%^";
  }
  else {
    msg+="  |  | ~  ~  ~  ~ |   |\n";
    if (wis == 2)
      msg+="  | ~    %^BLUE%^.%^RESET%^   ";
    else
      msg+="  | ~        ";
  }
  if (str >= 2)
    msg+="%^RED%^..%^RESET%^";
  else if (str == 1)
    msg+=" %^RED%^.%^RESET%^";
  else
    msg+="  ";
  
  msg+="   |   >\n";
  
}
// this is a very long and boring function that puts together
//   the rest of the ascii dependant on a lot of variables
// don't forget to escape the " and \ chars
void finish_palm(object tp, int age, int deaths, int marriages,
                 int kills, int quests, int str, int wis) {
  if (wis >= 2)
      msg+="  |   %^BLUE%^._/'%^RESET%^";
  else if (wis == 1)
      msg+="  |   %^BLUE%^.%^RESET%^   ";
  else
      msg+="  |       ";
  
  switch (str) {
    case 4:
      msg+="%^RED%^.. ``%^RESET%^"; break;
    case 3:
      msg+=" %^RED%^. ``%^RESET%^"; break;
    case 2:
      msg+="   %^RED%^``%^RESET%^"; break;
    case 1:
      msg+="    %^RED%^`%^RESET%^"; break;
    default:
      msg+="     ";
  }
  
  if (age == 4)
    msg+=" %^BOLD%^%^WHITE%^_%^RESET%^ `   |\n";
  else
    msg+="   `   |\n";
  
  if (wis >= 1)
    msg+="  | %^BLUE%^_/'%^RESET%^   ";
  else
    msg+="  |       ";
    
  if (str == 4)
    msg+="%^RED%^``%^RESET%^ ";
  else if (str == 3)
    msg+=" %^RED%^`%^RESET%^ ";
  else
    msg+="   ";
  
  if (age == 4)
    msg+="%^BOLD%^%^WHITE%^__/`%^RESET%^ ";
  else if (age == 3)
    msg+="%^BOLD%^%^WHITE%^__%^RESET%^   ";
  else
    msg+="     ";
  
  if (marriages == 3)
    msg+="%^BOLD%^%^MAGENTA%^._%^RESET%^  |";
  else
    msg+="    |";
  msg+="   %^BOLD%^%^WHITE%^Life      %^MAGENTA%^Love%^RESET%^\n";
  
  msg+="  |   %^BOLD%^%^WHITE%^_%^RESET%^";
  
  if (deaths >= 1)
    msg+="%^MAGENTA%^v%^RESET%^";
  else if (age >= 2)
    msg+="%^BOLD%^%^WHITE%^_%^RESET%^";
  else
    msg+=" ";
  
  if (age >= 2)
    msg+="%^BOLD%^%^WHITE%^_%^RESET%^";
  else
    msg+=" ";
  
  if (deaths >= 2)
    msg+="%^MAGENTA%^v%^RESET%^";
  else if (age >= 2)
    msg+="%^BOLD%^%^WHITE%^_%^RESET%^";
  else
    msg+=" ";
  
  if (age >= 2)
    msg+="%^BOLD%^%^WHITE%^_%^RESET%^";
  else
    msg+=" ";
  
  if (deaths == 3)
    msg+="%^MAGENTA%^v%^RESET%^";
  else if (age >= 2)
    msg+="%^BOLD%^%^WHITE%^_%^RESET%^";
  else
    msg+=" ";
  
  if (age >= 3)
    msg+="%^BOLD%^%^WHITE%^/`%^RESET%^  ";
  else
    msg+="    ";
  
  if (marriages == 3)
    msg+="%^BOLD%^%^MAGENTA%^._I'%^RESET%^  /\n";
  else if (marriages == 2)
    msg+="%^BOLD%^%^MAGENTA%^._%^RESET%^    /\n";
  else
    msg+="      /\n";
  
  msg+="   \\ %^BOLD%^%^WHITE%^/`%^RESET%^";
  
  if (deaths == 3)
    msg+="%^MAGENTA%^^ ^ ^%^RESET%^  ";
  else if (deaths == 2)
    msg+="%^MAGENTA%^^ ^%^RESET%^    ";
  else if (deaths == 1)
    msg+="%^MAGENTA%^^%^RESET%^      ";
  else
    msg+="       ";
  
  if (marriages >= 2)
    msg+="%^BOLD%^%^MAGENTA%^._I'%^RESET%^   /";
  else if (marriages == 1)
    msg+="%^BOLD%^%^MAGENTA%^._%^RESET%^     /";
  else
    msg+="       /";
  
  msg+="    %^YELLOW%^Success%^RESET%^   %^MAGENTA%^Failure%^RESET%^\n";
  msg+="    \\  ";
  
  switch (age) {
    case 5:
      msg+="%^YELLOW%^,,,,,%^RESET%^"; break;
    case 4:
      msg+="%^YELLOW%^,,,,%^RESET%^ "; break;
    case 3:
      msg+="%^YELLOW%^,,,%^RESET%^  "; break;
    case 2:
      msg+="%^YELLOW%^,,%^RESET%^   "; break;
    case 1:
      msg+="%^YELLOW%^,%^RESET%^    "; break;
    default:
      msg+="     ";
  }
  
  if (marriages >= 1)
    msg+="  %^BOLD%^%^MAGENTA%^I'%^RESET%^    /\n";
  else
    msg+="        /\n";
  
  msg+="     \\ ";
  
  switch(quests) {
    case 5:
      msg+="%^YELLOW%^\"\"\"\"\"%^RESET%^"; break;
    case 4:
      msg+="%^YELLOW%^\"\"\"\"%^RESET%^ "; break;
    case 3:
      msg+="%^YELLOW%^\"\"\"%^RESET%^  "; break;
    case 2:
      msg+="%^YELLOW%^\"\"%^RESET%^   "; break;
    case 1:
      msg+="%^YELLOW%^\"%^RESET%^    "; break;
    default:
      msg+="     ";
  }
  
  msg+="      ./      %^RED%^Strength  %^BLUE%^Wisdom%^RESET%^\n";
  msg+="      |          |\n";
  msg+="      |          |\n";
  
  message("magic",msg,tp);
}
void help() {
  message("help","palmread <player>\n\nAn experienced gypsy can use "
    "his skills to read the palm of another player.",this_player());
}
/* Below this line I'm including the full ascii just in case
   it's needed at some point in the future. All the marks inside
   the hand outline except for ~ represent something and are
   variable depending on the caster and target.
   There's also a sort of key but I'm only including that once.
   
      /"""\
     |     |/""\
 /""\|     |    |
|    |     |    |
|    | ~~~ | ~~ |
| ~~ |     |    |/"T\
|    |     |    |  \|
|    | ~~~.  ~~ |   |
| ~~   ._/'..   |   >
|   ._/'.. `` _ `   |
| _/'   `` __/` ._  |   Life      Love
|   _v_v_v/`  ._I'  /
 \ /`^ ^ ^  ._I'   /    Success   Failure
  \  ,,,,,  I'    /
   \ """""      ./      Strength  Wisdom
    |          |
    |          |
         /"\
     /"\|   |/"\
    |   |   |   |
    |   |   |   |
 /"\|   | ~ |   |
|   | ~ |   | ~ |
|   |   |   |   |/"T\
|   |   | ~ |   |  \|
|   | ~   .   ~ |   |
| ~    ._/'..   |   >
|   ._/'.. `` _ `   |
| _/'   `` __/` ._  |
|   _v_v_v/`  ._I'  /
 \ /`^ ^ ^  ._I'   /
  \  ,,,,,  I'    /
   \ """""      ./
    |          |
    |          |
       /\ /\
    /\|  |  |/^\
   |  |  |  |   |
 /\|  |  |  |   |
|  |  | ~| ~|   |
|  | ~|  |  | ~ |/Y\
| ~|  |  |  |   |  \|
|  |  |  |  |   |   |
|  | ~  ~ .~  ~ |   |
| ~    ._/'..   |   >
|   ._/'.. `` _  `  |
| _/'   `` __/` ._  |
|   _v_v_v/`  ._I'  /
 \ /`^ ^ ^  ._I'   /
  \  ,,,,,  I'    /
   \ """""      ./
    |          |
    |          |
*/
