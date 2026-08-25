/* Titan made this mess */
inherit "/std/potion";
#include "o_resistance.h"

#define MAX_TOHIT 10
#define MAX_DAMAGE 3
#define MAX_STAT 5
#define MAX_RESISTANCE 40
#define RESISTANCE_DURATION 400
#define DRUGGED 3 /* max amount a stat can be without having a negative side effect */

string p_type, drink_mess, fail_mess, room_mess, color;
int bonus;

/* amount stat/resistance is to be adjusted */
void set_enchant(int i) { bonus = i; }

/* type of potion - "cha","int","wis","str","dex","con"
 "tohit", "damage" or any resistance */
void set_type(string str) { p_type = str; }

/* Message you get when you drink the potion */
void set_drink_message(string str) { drink_mess = str;}

/* Message everyone else gets when the player drinks the potion */
void set_room_message(string str) { room_mess = str; } 

/* Message the player gets after he drinks the potion but it
   has no effect(stat is already boosted) */
void set_failure_message(string str) { fail_mess = str; } 
 
void setup_potion_color() { color = match_color_to(p_type); }

int type_adjustment(string p_type)
{
    switch(p_type)
    {
    case "fire":
    case "cold":
    case "magical":
    case "electrical":
    case "air":
    case "acid":
    case "stone":
    case "poison":
    case "psionic":
    case "mirror":
        if(bonus > MAX_RESISTANCE) bonus = MAX_RESISTANCE;
        if(bonus < -MAX_RESISTANCE) bonus = -MAX_RESISTANCE;
        if(TP->query_property(p_type) < bonus)
        {     
            TP->add_timed_property(p_type,bonus,RESISTANCE_DURATION);
            TP->add_timed_property(query_opposite(p_type),-bonus,RESISTANCE_DURATION);
            return 1;
        }
        else return 0;
        break;
    case "tohit":
        if(TP->query_tmp_tohit_bon() < 1)
        {
            if(bonus > MAX_TOHIT) bonus = MAX_TOHIT;
            if(bonus < -MAX_TOHIT) bonus = -MAX_TOHIT;
            TP->adjust_tmp_tohit_bon(bonus);
            return 1;
        }
        else return 0;
        break;
    case "damage":
        if(bonus > MAX_DAMAGE) bonus = MAX_DAMAGE;
        if(bonus < -MAX_DAMAGE) bonus = -MAX_DAMAGE;
        if(TP->query_tmp_damage_bon() < 1)
        {
            TP->adjust_tmp_damage_bon(bonus);
            return 1;
        }
        else return 0;
        break;
    case "str":
        if(TP->query_tmp_str() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_str(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_tohit(-bonus);
            return 1;
        }
        else return 0;
        break;
    case "dex":
        if(TP->query_tmp_dex() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_dex(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_int(-1);
            return 1;
        }
        else return 0;
        break;
    case "int":
        if(TP->query_tmp_int() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_int(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_dex(-1);
            return 1;
        }
        else return 0;
        break;
    case "con":
        if(TP->query_tmp_con() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_con(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_wis(-1);
            return 1;
        }
        else return 0;
        break;
    case "wis":
        if(TP->query_tmp_wis() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_wis(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_con(-1);
            return 1;
        }
        else return 0;
        break;
    case "cha":
        if(TP->query_tmp_cha() < 1)
        {
            if(bonus > MAX_STAT) bonus = MAX_STAT;
            if(bonus < -MAX_STAT) bonus = -MAX_STAT;
            TP->adjust_tmp_cha(bonus);
            if(bonus > DRUGGED) TP->adjust_tmp_str(-1);
            return 1;
        }
        else return 0;
        break;
    default:
        return 0;
    }
}

void init() 
{
    ::init();
    add_action("do_drink", "drink");
}

int do_drink(string str)
{
    object ob;
    ob=environment(this_player());

    if(str == this_object()->query_short() || 
      str == this_object()->query_name() ||
      str == "potion")
    {
        if(!drink_mess)
            drink_mess = "You guzzle the foul smelling liquid... your eyes "
            "roll back in your head as you strain to swallow the "
            "rest.  As the liquid settles in your stomach, you feel "
            "as if you are going to pass out.\n"; 

        if(!room_mess)
            room_mess = this_player()->query_cap_name()+" raises a "
            "tinted potion to "+this_player()->query_possessive()+
            " mouth.  With a horrible look of agony, "+
            this_player()->query_pronoun()+" finishes the last "
            "of the liquid.\n"; 

        if(!fail_mess)
            fail_mess = "Strange, nothing seems to have happened.  Wonder why?\n";

        write(drink_mess);
        tell_room(ob,room_mess,this_player());

        if(!type_adjustment(p_type))
            write(fail_mess);

        call_out("dest_me",0);
        return 1;
    }
}

string query_type() { return p_type; }
int query_enchant() { return bonus; }
string query_drink_message() { return drink_mess; }
string query_room_message() { return room_mess; }
string query_color() { return color; }
