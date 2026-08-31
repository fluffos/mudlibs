#include <std.h>
#include <arlon.h>
#include <council.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);
int moveWarrior();
int movePaladin();
int moveRanger();
int moveAntipaladin();
int choose(string what);
int inf(string where);
int moveKnight();
int moveSoldier();

void create() {
  object ob;

  ::create();
  set_property("no attack", 1);
  set_property("no castle", 1);
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no magic", 1);
  set_property("no attack", 1);
  set_property("no teleport", 1);
  set_property("no bump", 1);
  set("short", "The inner sanctum of the Hall of Fighters");
  set("long",
      "Welcome to the inner sanctum of the Hall of Fighters!\n"
      "Fighters gather here to advance in the art of combat and in life.  "
      "In this hall, a fighter may <advance>, <cost>, <list (number)>, "
      "<improve stat>, <train skill amount>, and <roll stats>.  Down "
      "through a stairway guarded by a shimmering %^BLUE%^blue%^RESET%^ "
      "light is the entrance to the hall. You can choose a subclass here.");
   set_exits(([
      "down" : ROOMS"fighter_join",
      "east" : ROOMS"fgtrvote",
      "warrior" : ROOMS"fighter/warrio",
      "paladin" : ROOMS"fighter/paladin",
      "antipaladin" : ROOMS"fighter/antipaladin",
      "knight" : ROOMS"fighter/knight",
      "soldier" : ROOMS"fighter/soldier",
      "ranger" : ROOMS"fighter/ranger"]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "glory board" }) );
    ob->set_board_id("fighter_board");
    ob->set_edit_ok(FIGHTER_COUNCIL);
    ob->set_max_posts(50);
    ob->set_location(ROOMS"fighter_hall");
    ob->set("short", "Glory Board of Fighters");
    ob->set("long",
	"The Fighters of our reality post tales of their glorious "
	"adventures here, as well as info on the dangers out there.\n");
}
int moveSoldier() {
/* if (this_player()->query_subclass()=="none") {
    this_player()->set_subclass("warrior");
 CHAT_D->do_raw_chat("soldier", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+this_player()->query_cap_name()+" becomes an soldier!");
   }*/
 if (this_player()->query_subclass()!="soldier") {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   } this_player()->move_player(ROOMS"fighter/soldier", "soldier");
 return 1;
}
int moveKnight() {
/* if (this_player()->query_subclass()=="none") {
    this_player()->set_subclass("knight");
 CHAT_D->do_raw_chat("fighter", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+this_player()->query_cap_name()+" becomes an knight!");
   }*/
 if (this_player()->query_subclass()!="knight") {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   } this_player()->move_player(ROOMS"fighter/knight", "knight");
 return 1;
}
int moveAntipaladin() {
/* if (this_player()->query_subclass()=="none") {
    this_player()->set_subclass("antipaladin");
    CHAT_D->do_raw_chat("fighter", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+this_player()->query_cap_name()+" becomes an antipaladin!");
   }*/
 if (this_player()->query_subclass()!="antipaladin") {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   } this_player()->move_player(ROOMS"fighter/antipaladin", "antipaladin");
 return 1;
}
int moveWarrior() {
/* if (this_player()->query_subclass()=="none") { 
    this_player()->set_subclass("warrior");
    CHAT_D->do_raw_chat("fighter", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+(string)this_player()->query_cap_name()+" becomes a Warrior!");
   }*/
 if (this_player()->query_subclass()!="warrior") {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   }
 this_player()->move_player(ROOMS"fighter/warrior", "warrior");
 return 1;
}

int movePaladin()
{
/* if (this_player()->query_subclass()=="none")
   {
    this_player()->set_subclass("paladin");
    CHAT_D->do_raw_chat("fighter", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+(string)this_player()->query_cap_name()+" becomes a Paladin!");
 }*/
 if (this_player()->query_subclass()!="paladin")
   {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   }
 this_player()->move_player(ROOMS"fighter/paladin", "paladin");
 return 1;
}

int moveRanger()
{
/* if (this_player()->query_subclass()=="none")
   {
    this_player()->set_subclass("ranger");
    CHAT_D->do_raw_chat("fighter", "%^WHITE%^%^BOLD%^A wild cheer is let out as "+(string)this_player()->query_cap_name()+" becomes a Ranger!");
 }*/
 if (this_player()->query_subclass()!="ranger")
   {
    write("A magical force holds you back.\n");
    say((string)this_player()->query_cap_name()+ " twitches.\n");
    return 1;
   }
 this_player()->move_player(ROOMS"fighter/ranger", "ranger");
 return 1;
}
void init() {
    ::init();
    add_action("cmd_start", "start");
 /*   add_action("cost","cost"); */
    add_action("choose", "choose");
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("inf", "go");
    add_action("advance","advance");
    add_action("list","list");
    add_action("moveWarrior",    "warrior");
    add_action("moveSoldier",    "soldier");
    add_action("moveKnight",     "knight");
    add_action("moveAntipaladin", "antipaladin");
    add_action("movePaladin",    "paladin");
    add_action("moveRanger",     "ranger");
  }

int inf(string what) {
   if (!what) return 0;
   switch (what) {
      case "warrior":
         return moveWarrior();
      case "soldier":
         return moveSoldier();
      case "knight":
         return moveKnight();
      case "antipaladin":
         return moveAntipaladin();
      case "paladin":
         return movePaladin();
      case "ranger":
         return moveRanger();
      default:
         return 0;
   }
}

int roll(string str) {
    if(str != "stats") return 0;
    ROOM_SETTER->do_rolls();
    return 1;
}

string get_new_title(object tp)
{
    int lev;
    string gen, title;

    lev = (int)this_player()->query_level();
    gen = (string)this_player()->query_gender();
    if(this_player()->query_guild()) {
	if(present((string)tp->query_guild()+"_ob", tp)) {
	    if(lev > 19) title = "High mortal";
	    else title = (string)present((string)tp->query_guild()+"_ob", tp)->query_title(tp);
	    title += " $N";
	}
	else {
	    if(lev > 19) title = "High mortal $N";
	    else title = "$N";
	}
    }
    else {
	if(lev > 20) title = "High mortal $N";
	else title = "$N";
    }
    if(lev > 20) title += previous_title(tp);
    else if(gen == "male") title += " "+get_male(lev);
    else title += " "+get_female(lev);
    return title;
}

string get_male(int lev) {
    string *male_title_str;

    if(!male_title_str) male_title_str = allocate(20);
	male_title_str[19]      ="the legend";
	male_title_str[18]      ="the wise old master of combat";
	male_title_str[17]      ="the old veteran";
	male_title_str[16]      ="the battle hardened veteran";
	male_title_str[15]      ="is death incarnate";
	male_title_str[14]      ="the war-monger";
	male_title_str[13]     = "the great gladiator";
	male_title_str[12]      ="the experienced gladiator";
	male_title_str[11]      ="the gladiator";
	male_title_str[10]      ="the great champion";
	male_title_str[9]       ="the champion";
	male_title_str[8]       ="the experienced fighter";
	male_title_str[7]       ="the employed fighter";
	male_title_str[6]       ="the fighter for hire";
	male_title_str[5]       ="the rookie fighter";
	male_title_str[4]       ="the amateur fighter";
	male_title_str[3]       ="the experienced squire";
	male_title_str[2]       ="the gung-ho squire";
	male_title_str[1]       ="the timid squire";
	male_title_str[0]       ="the page";
    return male_title_str[lev-1];
}

string get_female(int lev) {
    return get_male(lev);
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(!str) {
	notify_fail("Correct syntax: <train skill amount>\n");
	return 0;
    }
    if(sscanf(str, "%s %s %d", which, which_tmp, amount) == 3) which = which+ " "+ which_tmp;
    else if(sscanf(str, "%s %d", which, amount) !=2) {
	notify_fail("Correct syntax: <train skill amount>\n");
	return 0;
    }
    which = lower_case(which);
    if(!this_player()->skill_exists(which)) {
	notify_fail("No such skill.\n");
	return 0;
    }
    return (int)ADVANCE_D->train_player(this_player(), which, amount);
}

int improve(string str) {
    string *stats;
    string adj;
    int stat_cost;

    if (!str)
      {
       notify_fail("Improve what?\n");
       return 0;
      }
    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
	notify_fail("You have no such stat.\n");
	return 0;
    }
    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str)+1);
    if( (int)this_player()->query_exp()-stat_cost < 0 ) {
	notify_fail("You are not experienced enough to improve yourself in that way.\n");
	return 0;
    }
    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    adj = (str == "strength" ? "stronger" : (str == "intelligence" ? "more intelligent" :
      (str == "wisdom" ? "wiser" : (str == "dexterity" ? "more nimble" :
      (str == "constitution" ? "sturdier" : "more attractive")))));
    message("my_action", sprintf("You look %s.", adj), this_player());
    message("other_action", sprintf("%s looks much %s",
      (string)this_player()->query_cap_name(), adj), environment(this_player()),
      ({ this_player() }));
    return 1;
}

int get_cost(string stat, int lev) {
    switch(stat) {
	case "strength": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
    }
}

int cost(string str) {
    int bing;
 
    write("Costs for advancement, training, and improvement:\n");
    bing = (int)ADVANCE_D->get_exp( (int)this_player()->query_level() + 1 );
    if(bing < 1) write("level:\t\tIt will cost you nothing to advance.");
    else write("level:\t\t"+bing+"\n");
    write("skills: You train by spending the amount of experience you
desire.");
    write("strength:\t\t" + get_cost("strength",
(int)this_player()->query_base_stats("strength")) +
"\t\tconstitution:\t\t" + get_cost("constitution",
(int)this_player()->query_base_stats("constitution")) );
    write("intelligence:\t\t" + get_cost("intelligence",
(int)this_player()->query_base_stats("intelligence")) +
"\t\tdexterity:\t\t" + get_cost("dexterity",
(int)this_player()->query_base_stats("dexterity")) );
    write("wisdom:\t\t" + get_cost("wisdom",
(int)this_player()->query_base_stats("wisdom")) +
"\t\tcharisma:\t\t" + get_cost("charisma",
(int)this_player()->query_base_stats("charisma")) );
    return 1;
}

int list(string str) {
  int x;
  
  if(!str) "/d/standard/quest_room"->list_quests(this_player(), 0);
  else {
    if(sscanf(str, "%d", x) != 1) {
    notify_fail("You must give the number of the quest you want listed.\n");
  return 0;
  }
  if(x<1) {
    notify_fail("No such quest.\n");
  return 0;
  }
  "/d/standard/quest_room"->list_quests(this_player(), x);
  }
  return 1;
}

int cmd_start(string str)
{
 if (!str || str=="")
   {
    notify_fail("Start where?\n");
    return 0;
   }

 if (str!="here")
   {
    notify_fail("You cant start there.\n");
    return 0;
   }

 this_player()->set_primary_start(ROOMS"fighter_hall");

 write("You are now set to start here.");
 return 1;
}

int choose(string what) {
   if (this_player()->query_subclass() != "none") {
      notify_fail("You cannot do that.\n");
      return 0;
   }
   if (!what) {
      notify_fail("Choose what?\n");
      return 0;
   }
   if (what != "paladin" && what != "antipaladin" && what != "knight" &&
       what != "soldier" && what != "ranger" && what != "warrior") {
      notify_fail("You cannot choose that!\n");
      return 0;
   }
   this_player()->set_subclass(what);
   CHAT_D->do_raw_chat("fighter", "%^WHITE%^"+this_player()->query_cap_name()+
      " has become a %^BLUE%^"+what+".%^RESET%^");
  if (what == "antipaladin")
   write("%^WHITE%^You become an%^BLUE%^ antipaladin.");
  else
   write("%^WHITE%^You become a%^BLUE%^ "+what+".");
   if (what == "paladin")
     this_player()->set_alignment(2500);
   if (what == "antipaladin")
     this_player()->set_alignment(-2500);
   return 1;
}
