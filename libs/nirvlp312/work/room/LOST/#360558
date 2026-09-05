#include "std_old.h"
#include "tune.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
   object ob;
   if (arg)
      return;
/*  commented out by verte .. obsolete obj
   move_object("obj/book", this_object());
*/
   move_object(clone_object("obj/bull_board"), this_object());
    call_other("room/quest_room.c", "short", 0);
    if(!present("orc_slayer", find_object("room/quest_room.c"))) {
   ob = clone_object("obj/quest_obj");
   call_other(ob, "set_name", "orc_slayer");
   call_other(ob, "set_hint",
      "Retrieve the Orc slayer from the evil orc shaman, and give it to Leo.\n");
   move_object(ob, "room/quest_room");
  }
}

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_level"); add_verb("cost");\
add_action("advance"); add_verb("advance");\
add_action("south"); add_verb("south");\
add_action("banish"); add_verb("banish");\
add_action("raise"); add_verb("raise");\
add_action("list_quests"); add_verb("list");

THREE_EXIT("room/vill_road2", "north",
         "open/info/room",  "west",
         "room/exlv_guild", "up",
   "The adventurers guild",
   "You have to come here when you want to advance your level.\n" +
   "You can also buy points for a new level.\n" +
   "Commands: cost, advance, list (number).\n" +
    "raise <str, sta, wil, mag, pie, ste, luc, int>\n" +
    "There are some stairs leading up to the second level.\n" +
   "There is an opening to the south, and some shimmering\n" +
   "blue light in the doorway.\n" +
   "You see a small side area off to the west.\n",
   1)

int next_level;
int valexp;
int next_exp;
int level;
int exp;
string title;         /* now with arrays. :) */
string guname;
object player_ob;
string banished_by;

/* some minor changes by Iggy. */
/* get level asks get_next_exp() and  get_next_title() */

get_level(str)
{
	level = str;
  
	next_exp   = get_next_exp(level);
	next_level = level + 1 ;   
player_ob = this_player();
	title      = get_new_title(level);
}    

string male_title_str, fem_title_str, neut_title_str;
/*xxx  return title */
get_new_title(str)
{
     if(str < 0 || str > 19) return "the wizard";
    if (!male_title_str){
	male_title_str = allocate(20);
	
	male_title_str[19]	="the apprentice Wizard";
	male_title_str[18]	="the grand master sorcerer";
	male_title_str[17]	="the master sorcerer";
	male_title_str[16]	="the apprentice sorcerer";
	male_title_str[15]	="the warlock";
	male_title_str[14]	="the enchanter";
	male_title_str[13]	="the magician";
	male_title_str[12]	="the apprentice magician";
	male_title_str[11]	="the conjurer";
	male_title_str[10]	="the champion";
	male_title_str[9]	="the warrior";
	male_title_str[8]	="the great adventurer";
	male_title_str[7]	="the experienced adventurer";
	male_title_str[6]	="the small adventurer";
	male_title_str[5]	="the experienced fighter";
	male_title_str[4]	="the small fighter";
	male_title_str[3]	="the master ranger";
	male_title_str[2]	="the lowrank ranger";
	male_title_str[1]	="the simple wanderer";
	male_title_str[0]	="the utter novice";

	fem_title_str = allocate(20);

	fem_title_str[19]	="the apprentice Wizard";
	fem_title_str[18]	="the grand master sorceress";
	fem_title_str[17]	="the master sorceress";
	fem_title_str[16]	="the apprentice sorceress";
	fem_title_str[15]	="the witch";
	fem_title_str[14]	="the enchantress";
	fem_title_str[13]	="the magicienne";
	fem_title_str[12]	="the apprentice magicienne";
	fem_title_str[11]	="the conjuress";
	fem_title_str[10]	="the deadly amazon";
	fem_title_str[9]	="the amazon";
	fem_title_str[8]	="the great adventuress";
	fem_title_str[7]	="the experienced adventuress";
	fem_title_str[6]	="the small adventuress";
	fem_title_str[5]	="the charming siren";
	fem_title_str[4]	="the siren";
	fem_title_str[3]	="the master ranger";
	fem_title_str[2]	="the lowrank ranger";
	fem_title_str[1]	="the simple wanderer";
	fem_title_str[0]	="the utter novice";

	neut_title_str = allocate(20);

	neut_title_str[19]	="the apprentice Wizard";
	neut_title_str[18]	="the ferocious tyrannosaur";
	neut_title_str[17]	="the small tyrannosaur";
	neut_title_str[16]	="the vicious dragon";
	neut_title_str[15]	="the devious dragon";
	neut_title_str[14]	="the small dragon";
	neut_title_str[13]	="the powerful demon";
	neut_title_str[12]	="the small demon";
	neut_title_str[11]	="the beholder";
	neut_title_str[10]	="the great monster";
	neut_title_str[9]	="the experienced monster";
	neut_title_str[8]	="the medium monster";
	neut_title_str[7]	="the small monster";
	neut_title_str[6]	="the threatening shadow";
	neut_title_str[5]	="the shadow";
	neut_title_str[4]	="the wraith";
	neut_title_str[3]	="the bugbear";
	neut_title_str[2]	="the furry creature";
	neut_title_str[1]	="the simple creature";
	neut_title_str[0]	="the utter creature";
    }
    if (!player_ob || player_ob->query_gender() == "creature")
	return neut_title_str[str];
    else if (player_ob->query_gender() == "male")
	return male_title_str[str];
    else
	return fem_title_str[str];
}


int exp_str;

/*  returns the next_exp. */
get_next_exp(str) {
    if(!exp_str){
	exp_str = allocate(20);
	
	exp_str[19]	= 6900000;
	exp_str[18]	=  2000000; 
	exp_str[17]	=  1367106;
	exp_str[16]	=  1040028;
	exp_str[15]	=  820028;
	exp_str[14]	=  620026;
	exp_str[13]	=   492294;
	exp_str[12]	=   295592;
	exp_str[11]	=   195591;
	exp_str[10]	=   134998;
	exp_str[9]	=   90000;
	exp_str[8]	=   59995;
	exp_str[7]	=   39993;
	exp_str[6]	=    26662;
	exp_str[5]	=    12812;
	exp_str[4]	=    5885;
	exp_str[3]	=    2332;
	exp_str[2]	=    1771;
	exp_str[1]	=    1014;
	exp_str[0]	=       0;
    }
    if((str >= 0) && (str < 20)) return exp_str[str];
    else return 0; /* patch by verte */
}

/*
 * This routine is called by monster, to calculate how much they are worth.
 * This value should not depend on the tuning.
 */
query_cost(l) {
    player_ob = this_player();
    level = l;
    if (level >= 20)
	return 2000000;
    get_level(level);
    valexp = 12*next_exp/30;
    if (level < 6) valexp = next_exp;
    return valexp;
/*
    return next_exp;
*/
}

/*
 * Special function for other guilds to call. Arguments are current level
 * and experience points.
 */
query_cost_for_level(l, e) {
    level = l;
    exp = e;
    get_level();
    if (next_exp <= exp)
	return 0;
    return (next_exp - exp) * 1000 / EXP_COST;
}

cost_for_level() {
    player_ob = this_player();
    level = call_other(player_ob, "query_level", 0);
    if (level >= 20) {
	write("You will have to seek other ways.\n");
	return 1;
    }
    exp = call_other(player_ob, "query_exp", 0);
    get_level(level);
    if (next_exp <= exp) {
	write("It will cost you nothing to be promoted.\n");
	return 1;
    }
    if ((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
     write("You must be closer to the next level before buying experience.\n");
    return 1;
   }
    write("It will cost you "); write((next_exp - exp) * 1000 / EXP_COST);
    write(" gold coins to advance to level "); write(next_level);
    write(".\n");
    return 1;
}

advance() {
    string name_of_player;
    int cost;
    player_ob = this_player();
    guname=player_ob->query_guild_name();
    if (guname=="paladin") {
        write("You must advance at your guild hall.");
       write("\n");
        return 1;
     }
    name_of_player = call_other(player_ob, "query_name", 0);
    level = call_other(player_ob, "query_level", 0);
    if (level == -1)
	level = 0;
    exp = call_other(player_ob, "query_exp", 0);
    title = call_other(player_ob, "query_title", 0);
    if (level >= 20) {
	write("You are still "); write(title); write("\n");
	return 1;
    }
    get_level(level);
    if(this_player()->query_extra_level() > 15 && next_level == 20 && this_player()->query_quest_point() < NEEDED_QP) {
      write("You have "+this_player()->query_quest_point() + " quest points"
          + " and you need "+NEEDED_QP + " of "+TOTAL_QP+" to become wizard.\n");
	return 1;
      }
    if(next_level == 20 &&this_player()->query_aprv() < 3 && this_player()->query_extra_level() > 15) {
      write("You need the approval of three senior wizards to advance to apprentice wizard.\n");
      write("You have "+this_player()->query_aprv()+" approvals.\n");
      return 1;
     }
    if(this_player()->query_extra_level() < 16 && next_level == 20) {
       write("You must go upstairs to advance your level.\n");
       return 1;
       }
    cost = (next_exp - exp) * 1000 / EXP_COST;
    if (next_exp > exp) {
	if (call_other(player_ob, "query_money", 0) < cost) {
	    write("You don't have enough gold coins.\n");
	    return 1;
	}
      if((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
    write("You must be closer to the next level before buying experience.\n");
    return 1;
    }
	call_other(player_ob, "add_money", - cost);
    }
    if(next_level != 20)
    say(call_other(player_ob, "query_name", 0) + " is now level " +
	next_level + ".\n");
    else
    say(call_other(player_ob, "query_name", 0) + " is now level " +
         "20.\n");
    call_other(player_ob, "set_level", next_level);
    call_other(player_ob, "set_title", title);
    if (exp < next_exp)
        call_other(player_ob, "add_exp", next_exp - exp);
    if(player_ob->query_guild_name() == "shardak" && present("shardak_mark", player_ob))
    {
      present("shardak_mark", player_ob)->BaseXp(next_exp);
      present("shardak_mark", player_ob)->save_me();
    }
    if (next_level < 7) {
        write("\nYou are now " + name_of_player + " " + title +
	      " (level " + next_level + ").\n");
	return 1;
    }
    if (next_level < 14) {
	write("Well done, " + name_of_player + " " + title +
	      " (level " + next_level + ").\n");
	return 1;
    }
    if (next_level < 20) {
	write("Welcome to your new class, mighty one.\n" +
	      "You are now " + title + " (level " + next_level + ").\n");
    }
    if (next_level == 20) {
	write("A new Wizard has been born.\n");
	shout("A new Wizard has been born.\n");
	write("If you want a castle of your own, seek out Leo the archwizard,\n");
	write("and ask him.\n");
	return 1;
    }
    return 1;
}

/*
 * Banish a monster name from being used.
 */
banish(who) {
    level = call_other(this_player(), "query_level");
    if (level < 21)
	return 0;
     write ("Please clone and use /obj/banish.c -Thank You-\n");
      return 1;
    if (!who) {
	write("Who ?\n");
	return 1;
    }
    if (!call_other(this_player(), "valid_name", who))
	return 1;
    if (restore_object("players/" + who)) {
	write("That name is already used.\n");
	return 1;
    }
    if (restore_object("banish/" + who)) {
	write("That name is already banished.\n");
	return 1;
    }
    banished_by = call_other(this_player(), "query_name");
    title = call_other(this_player(), "query_title");
    if (banished_by == "Someone") {
	write("You must not be invisible!\n");
	return 1;
    }
    save_object("banish/" + who);
    return 1;
}

south() {
    if (call_other(this_player(), "query_level", 0) < 20) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
	    " tries to go through the field, but fails.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "south#room/adv_inner");
    return 1;
}

list_quests(num)
{
    int qnumber;
   if (num == "all") {
   call_other("room/quest_room", "list_all");
   return 1;
   }
    if (num && (sscanf(num, "%d", qnumber) == 1))
	call_other("room/quest_room", "list", qnumber);
    else
	call_other("room/quest_room", "count", 0);
    return 1;
}

query_drop_castle() {
    return 1;
}
correct_level(player)
{
    level = call_other(player, "query_level", 0);
    exp = call_other(player, "query_exp", 0);
    /* Shouldn't "correct" wizards. */
    if (level >= 20)
	return;
   if (level < 2) return;
    get_level(level);
    while (exp < next_exp) {
	level -= 1;
        get_level(level);
    }
    if (next_level == 20 && call_other("room/quest_room", "count", 0))
    get_level(18);
    call_other(player, "set_level", next_level);
    call_other(player, "set_title", title);
}
raise(str) {
    string attrib,raise,thing;
    int new,expcost,current,minexp;
  if (str !="str" && str !="sta" && str != "wil" && str != "mag" && str !="pie" && str != "ste" && str != "luc" && str != "int")
     {
       write ("Raise what?\n");
       return 1;
     }
   if(this_player()->query_guild_name() == "paladin") {
     write("You must raise your attributes at your guild hall.\n");
     return 1;
   }

  if((this_player()->query_guild_name() == "Knights Templar") && !present("warrior_gob", this_player())) {
    if(str == "mag" && this_player()->query_attrib("mag") > 11) {
      write("Knights Templar may not raise their magical aptitude above 12\n");
      return 1;
    }
    if(str == "ste" && this_player()->query_attrib("ste") > 9) {
      write("Knights Templar may not raise their stealth above 10\n");
      return 1;
    }
  }
    if (call_other(this_player(), "query_level", 0) > 19) {
           write("wizards cannot advance attributes.\n");
           return 1;
         }
   if (str == "str") {
      attrib = "strength";
    }
   if (str == "sta"){
    attrib = "stamina";
    }
   if (str == "wil") attrib = "will_power";
   if (str == "mag") attrib = "magic_aptitude";
   if (str == "pie") attrib = "piety";
   if (str == "ste") attrib = "stealth";
   if (str == "luc") attrib = "luck";
   if (str == "int") attrib = "intelligence";
     raise = "raise_" + attrib;
     current = call_other(this_player(), "query_attrib", str);
     new = current + 1;
/*
     log_file("ATTRIB", this_player()->query_real_name() + " Raised " + attrib +" from " + current + " to " + new + "\n");
*/
     if (current < 11) expcost = -ATTRIB_COST;
     if (current < 12 && current > 10) expcost = -3*ATTRIB_COST/2;
     if (current < 14 && current > 11) expcost = -ATTRIB_COST_TWO;
     if (current < 16 && current > 13) expcost = -4*ATTRIB_COST_TWO/3;
     if (current < 18 && current > 15) expcost = -ATTRIB_COST_THREE;
     if (current < 21 && current > 17) expcost = -4*ATTRIB_COST_THREE/3;
     if (current > 19) {
            write (attrib + " is at highest possible value.\n");
            return 1;
            }
if(this_player()->query_extra_level() < 1)
    minexp = this_player()->query_exp() - get_next_exp(this_player()->query_level()-1);
if(this_player()->query_extra_level() > 0)
minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
    if (expcost < -minexp) {
        write ("You don't have enough experience available to raise an attribute.\n");
    return 1;
    }
     call_other(this_player(), raise, 1);
     call_other(this_player(), "add_exp", expcost);
    return 1;
}
check_level(arg) {
   int a1,a2,a3;
   a2 = arg - 1;
   a1=get_next_exp(a2);
   return a1;
}
check_exp(arg,argb) {
  get_level(19);
  if(arg < 0) return;
  while (arg < next_exp) {
    level -= 1;
        get_level(level);
    }
    if(level+argb > 0)
      get_level(level+argb);
    else
      get_level(0);
   return next_exp;
}
query_limited_shadow() { return 1; }
