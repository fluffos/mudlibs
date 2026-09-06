#include <battle.h>
#include <titles.h>

//#define US_WEIGHT(x) (x/100) * 22/100;
int US_WEIGHT(int x) {
   return (int) (x * 0.0022);
}

string make_stat( object ob, string stat_name ) {
   int val_real, val_base, i;
   string ret;

   val_base = call_other(ob, "query_"+stat_name);
   val_real = call_other(ob, "query_real_"+stat_name);

   ret = "";

   if ( val_base < val_real )
      ret += "~[090";
   else if (val_base > val_real )
      ret += "~CBRT";
   else
      ret += "~CSC3";
   ret += sprintf("%2d~CSC4/~CSC3%-2d ",val_base,val_real);

   return ret;
}

string meter( object ob, string which) {
  int x, percent, value, max;
  string buf, color;
  if (which == "food") {
    value = ob->query_food();
    max = ob->query_food_capacity();
    percent = ob->query_food_percent();
  } else {
    value = ob->query_drink();
    max = ob->query_drink_capacity();
    percent = ob->query_drink_percent();
  }
  if (percent > 50)
    color = "~[120";
  else
    color = "~[030";
  if ((percent >= 30) && (percent <= 70)) {
    buf = "~CSC2("+color;
    for (x = 15; x < 35; x++)
      if ((percent/2) > x)
        buf += "=";
      else if ((percent/2) == x)
        buf += "~CSC2-";
      else
        buf += "-";
    buf += "~CSC2)";
  } else if (percent > 70) switch (which) {
    case "food":  buf = "~CSC3(--------FULL--------)"; break;
    case "drink": buf = "~CSC3(--------FULL--------)"; break;
  } else if (percent > 0) switch (which) {
    case "food":  buf = "~[030(-------Hungry-------)"; break;
    case "drink": buf = "~[030(------Thirsty-------)"; break;
  } else switch (which) {
    case "food":  buf = "~[090(------STARVING------)"; break;
    case "drink": buf = "~[090(-----DEHYDRATED-----)"; break;
  }
  if (this_player()->query_level() >= WIZLEVEL)
    buf += "~CSC4 ("+value+"/"+max+"/"+percent+"%)";
  return buf;
}

string carry_string( object ob ) {
   string buf;
   int held = ob->query_held_weight();
   int cap = ob->query_weight_capacity();

   buf = US_WEIGHT(held) + "/" + US_WEIGHT(cap) + " lbs";
   if (this_player()->query_level() >= WIZLEVEL)
      buf += " ~CSC2(" + held + "/" + cap + " grams)";
   else
      buf += " ~CSC2(" + (held/1000) + "/" + (cap/1000) + " kg)";
   buf += " ~CSC3(" + (held*100/cap) + "%)";

   return buf;
}

string ac_string(object ob) {
  string buf;
  int x = ob->query_average_ac();

  if (x >= 95)
    buf = "Invincibly Buff";
  else if (x >= 85)
    buf = "Fortified";
  else if (x >= 75)
    buf = "Very Heavily Protected";
  else if (x >= 60)
    buf = "Heavily Protected";
  else if (x >= 45)
    buf = "Protected";
  else if (x >= 30)
    buf = "Lightly Protected";
  else if (x >= 15)
    buf = "Barely Protected";
  else if (x == 0)
    buf = "Unprotected";
  else
    buf = "Especially Vulnerable";

  if (this_player()->query_level() >= WIZLEVEL)
    buf += "~CSC2 ("+x+")";

  return buf;
}

string gender_string(int x) {
  switch (x) {
    case 1: return "Male";
    case 2: return "Female";
  }
  return "N/A";
}

string pronoun_string(object ob) {
   // a little pronoun parsing for wizards
   if ( ob != this_player() ) {
      // set_target(ob) didn't work for some reason
      switch ( ob->query_gender() ) {
         case 1: return "He is ";
         case 2: return "She is ";
         default: return "It is ";
      }
   }
   return "You are ";
}

int main(string dest) {
   object ob,item;
   string buf;
   int age,x,ac,width;

   ob = this_player();

   if( dest && this_player()->query_level() >= WIZLEVEL ) {
      ob = find_player(dest);
      if( !ob ) ob = find_living( dest );
	  if( !ob ) {
         ob = single_present( dest, environment(this_player()) );
		 if( ob && !ob->query_is_living() )
            ob = 0;
	  }
      if (!ob) {
         msg(capitalize(dest)+" was not found.");
         return 1;
      }
   }

   age = ob->query_age()-ob->query_last_login();
   if( age ) age += time();
   width = this_player()->query_term_width();

   buf = "~CSC2"+tab("-",width-3)+"\n";
   buf += pad("~CSC3"+ob->query_pretitle()+"~CSC4 "+capitalize(""+ob->query_name())+" ~CSC3"+ob->query_title(),width+12,2)+"\n";
   buf += "~CSC2"+tab("-",width-3)+"\n";
   buf += "~CSC4Level: ~CSC3"+query_personal_title(ob);
   if (this_player()->query_level() >= WIZLEVEL)
     buf += " ("+(string)ob->query_level()+")";

   buf +=  "\n~CSC4Str: " + make_stat(ob, "strength");
   buf +=  "~CSC4Dex: " + make_stat(ob, "dexterity");
   buf +=  "~CSC4Con: " + make_stat(ob, "constitution");
   buf +=  "~CSC4Spd: " + make_stat(ob, "speed") + "\n";

   buf +=  "~CSC4Wil: " + make_stat(ob, "will");
   buf +=  "~CSC4Int: " + make_stat(ob, "intelligence");
   buf +=  "~CSC4Emp: " + make_stat(ob, "empathy");
   buf +=  "~CSC4Cha: " + make_stat(ob, "charm") + "\n";

   buf += "~CSC4Alignment: ~CSC3"+ob->query_alignment_string();
   if (this_player()->query_level() >= WIZLEVEL)
     buf += "~CSC2 (lawful: "+ob->query_lawful_alignment()+", good: "+ob->query_good_alignment()+")\n";
   else
     buf += "\n";

   if( age != 0 )
      buf += "~CSC4Age:    ~CSC3"+int_to_time(age)+"\n";
   buf += pad("~CSC4Sex:    ~CSC3"+gender_string(ob->query_gender()), 32, 0);
   buf += pad(" ~CSC4Race: ~CSC3"+capitalize(ob->query_race()), 31, 0);
   buf += " ~CSC4Deaths: ~CSC3"+ob->query_deaths()+"\n";
   buf += "~CSC4Weight: ~CSC3"+ob->query_us_weight()+" lbs";
   if (this_player()->query_level() >= WIZLEVEL)
     buf += "~CSC2 ("+ob->query_weight()+" grams)\n";
   else
     buf += "~CSC2 ("+(ob->query_weight()/1000)+" kg)\n";

   buf += "~CSC4Carried:  ~CSC3" + carry_string(ob) + "\n";

   buf += "/bin/hp"->hp_string(ob)+"\n";

   buf += "~CSC2Food:   " + meter( ob, "food" ) + "\n";
   buf += "~CSC2Water:  " + meter( ob, "drink" ) + "\n";

   buf += "~CSC4Defense: ~CSC3" + ac_string(ob) + "\n";
   buf += pad("~CSC4Form:    ~CSC3" + capitalize(ob->query_form()),32,0);

   if (ob->query_skill("other.endurance"))
     buf += pad(" ~CSC4Soak: ~CSC3" + (ob->query_soak()?"on":"off"),32,0);
   buf += "~CSC4Wimpy: ~CSC3" + (ob->query_wimpy()?ob->query_wimpy()+"%":"off") + "\n";

   if( find_objectref(ob->query_env_var("home")) ) {
       object home_room = find_objectref(ob->query_env_var("home"));
       object home_bldg = environment(home_room);
       object home_zone;
	   buf += "~CSC4Home:    ~CSC3"+home_room->query_short();
       if( home_bldg ) {
          home_zone = environment(home_bldg);
		  string owner;
          if( home_bldg->query_owner() )
            owner = capitalize(home_bldg->query_owner())+"'s";
          else
            owner = "An unowned";
          buf += ", "+owner+" "+home_bldg->query_name()+", "+home_zone->query_short();
       }
       buf += "\n";
   }

   // stance
   buf += "~CSC3"+pronoun_string(ob);
   switch (ob->query_stance()) {
     case ST_STANDING: buf += "standing up."; break;
     case ST_SITTING: buf += "sitting down."; break;
     case ST_LYING: buf += "lying down."; break;
     case ST_CROUCHING: buf += "crouching."; break;
     case ST_JUMPING: buf += "jumping."; break;
     case ST_FALLING: buf += "falling."; break;
	 case ST_FLYING: buf += "flying."; break;
     case ST_UNBALANCED: buf += "unbalanced."; break;
     default: buf += "tilted at some obnoxiously uncomfortable angle."; break;
   }

   // party
   if( ob->query_env_var("party") ) {
     string party = ob->query_env_var("party");
     string pupil = ob->query_env_var("mentoring");
     string leader = PARTY_DAEMON->query_party_leader(party);
     buf += "\n~CSC3" + pronoun_string(ob) +
            (leader == ob->query_name() ? "the leader" : "a member") +
            " of the party ~CSC2" + capitalize(party) + "~CSC3";
     if( pupil )
       buf += ", and are mentoring ~CSC2" + capitalize(pupil) + "~CSC3.";
     else if( pupil = PARTY_DAEMON->query_mentor(ob->query_name()) ) {
       buf += ", " + (ob==this_player()?"and":"is") +
			  " are being mentored by ~CSC2" + capitalize(pupil) + "~CSC3.";
	 } else
       buf += ".";
   }

   buf += "\n~CSC2"+tab("-",width-3);

   msg(buf+"~CDEF");
   return 1;
}
