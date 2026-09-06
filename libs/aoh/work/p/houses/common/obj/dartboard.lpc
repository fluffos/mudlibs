/*  Dartboard by Johanne. Adapted to Nightfall II by Sique.  */

#include <properties.h>
inherit "/std/thing";
/*  Completed: April '91  */

string player1,player2,currplayer;
int points1,points2;
int dartcount,bet,dblout1,dblout2;
int skill,skill1,skill2;
int strngth,intel,dex,con,lev;
int multi;
int chance;
int try_hit,luck,luck_hit;
int num_hit,zone_hit;
int miss,number;
int *layout,*posn;
string *betting, *target;
string game;

int new_game(string str);
int start_game(string str);

void reset(int arg) {
  player1="No player";player2="No player";currplayer="No player";
  points1=301;points2=301;
  if (bet > 0) {
    tell_room(environment(this_object()),
            "The dartboard hides the bet from the last game!\n");
  }
  bet=0;
  dblout1=0;dblout2=0;
  dartcount=3;
  betting=allocate(2);
  target=allocate(2);
  layout=allocate(21);
    layout[0] = 0;
    layout[1] = 20;
    layout[2] = 1;
    layout[3] = 18;
    layout[4] = 4;
    layout[5] = 13;
    layout[6] = 6;
    layout[7] = 10;
    layout[8] = 15;
    layout[9] = 2;
    layout[10] = 17;
    layout[11] = 3;
    layout[12] = 19;
    layout[13] = 7;
    layout[14] = 16;
    layout[15] = 8;
    layout[16] = 11;
    layout[17] = 14;
    layout[18] = 9;
    layout[19] = 12;
    layout[20] = 5;
  posn=allocate(21);
    posn[0] = 0;
    posn[1] = 2;
    posn[2] = 9;
    posn[3] = 11;
    posn[4] = 4;
    posn[5] = 20;
    posn[6] = 6;
    posn[7] = 13;
    posn[8] = 15;
    posn[9] = 18;
    posn[10] = 7;
    posn[11] = 16;
    posn[12] = 19;
    posn[13] = 5;
    posn[14] = 17;
    posn[15] = 8;
    posn[16] = 14;
    posn[17] = 10;
    posn[18] = 3;
    posn[19] = 12;
    posn[20] = 1;
}

void init() {
  add_action("read_sign","read");
  add_action("read_sign","look");
  add_action("read_sign","exa");
  add_action("new_game","newgame");
  add_action("start_game","play");
  add_action("gamble","bet");
  add_action("points_game","points");
  add_action("throw_dart","throw");
  add_action("throw_dart","t");
}

varargs void create()
{
  ::create();
  SetShort("a classic dart board");
  SetIds(({"dart","board","dartboard"}));
  SetLong("This is a beautifully hand-crafted dart board, "
"complete with an automatic points keeper. "
"The numbers on the boad appear like this:\n\n\
         20\n\
      5      1\n\
   12          18\n\
  9              4\n\
 14              13  To aim for the bull's-eye do:\n\
 11      ()       6    throw d 0 - double bull\n\
  8              10    throw s 0 - single bull\n\
  16            15\n\
    7          2\n\
      19    17\n\
          3\n\n\
Above it, is a sign titled 'Rules'. You might want to read them.\n");
  Set(P_NOGET,"You can't take the dartboard, it is mounted to the wall.\n");
  new_game("The point keeper");
  SetValue(233);
}

int read_sign(string str) {
  if (str == "rules" || (query_verb() == "look" && str == "at rules")) {
    write("Both players start off with 301 points.  The object is to\n" +
       "reach zero (0) by subtracting the amount landed after each\n" +
       "turn (a turn is over after throwing three darts).\n" +
       "The first player to reach zero exactly wins the game.\n\n" +
       "Commands available are:\n" +
       "  'newgame'                 resets the game\n" +
       "  'play <opponent>'         starts a game with <opponent>\n" +
       "  'bet <opponent> <amount>  plays a gambling game with <opponent>\n" +
       "  'points'                  shows the points for the current game\n" +
       "  'throw <zone> <number>'   throws a dart toward the area of the\n" +
       "   or 't <zone> <number>'      zone and number.\n\n" +
       "Valid zones are:          's'(single), 'd'(double), 't'(triple)\n\n" +
       "Note:  Wizards must double out to win.\n");
    say(capitalize(({string})this_player()->QueryRealName()) + " reads the dart rules.\n");
    return 1;
  }
  return 0;
}

int new_game(string str) {
  reset(1);
  if(!environment()) return 0;
  if (!str) {
    tell_room(environment(this_object()),
      capitalize(({string})this_player()->QueryRealName()) + " resets the dart board.\n");
  }
  else
    tell_room(environment(this_object()),str+" resets the dart board.\n");
  return 1;
}

int valid_bet(string str) {
  sscanf(str,"%d",bet);
  return (bet >= 1);
}

int gamble(string str) {
  if (!str)
    return 0;
  betting=explode(str," ");
  if (present(str,environment(this_object()))) {
    notify_fail("You don't want to bet any coins?  Try 'play <opponent>'\n");
    return 0;
  }
  if (!present(betting[0],environment(this_object()))) {
    notify_fail("Your opponent is not here.\n");
    return 0;
  }
  if (find_player(betting[0]) == this_player()) {
    notify_fail("Betting against yourself is useless.\n");
    return 0;
  }
  if (!valid_bet(betting[1])) {
    notify_fail("You don't want to bet any coins?  Try 'play <opponent>'\n");
    return 0;
  }
  if(({int})"/lib/money"->QuerySomeonesValue(this_player()) < bet) {
    notify_fail("You don't have enough money!\n");
    bet=0;
    return 0;
  }
  if(({int})"/lib/money"->QuerySomeonesValue(find_player(betting[0])) < bet) {
    notify_fail("Your opponent doesn't have enough money!\n");
    bet=0;
    return 0;
  }
  if (player1!="No player") {
    notify_fail("A game is currently set up for " +player1+ " and " +player2+ ".\n");
    return 0;
  }
  start_game(betting[0]);
  "/lib/money"->PayValue(this_player(),bet);
  tell_room(environment(this_object()),player1+" and "+player2+
                               " both put up "+bet+" coins as their bet.\n");
  "/lib/money"->PayValue(find_player(betting[0]),bet);
  tell_room(environment(this_object()),
                             "There's a "+2*bet+" coin bet on the line!\n");
  return 1;
}

int start_game(string str) {
  if (!str)
    return 0;
  if (player1!="No player") {
    notify_fail("A game is currently set up for " +player1+ " and " +player2+ ".\n");
    return 0;
  }
  if (!present(str,environment(this_object()))) {
    notify_fail("Your opponent is not here.\n");
    return 0;
  }
  if (!find_player(str)) {
    notify_fail("You can't play against that!\n");
    return 0;
  }
  write("Ok.\n");
  player1 = capitalize(getuid(this_player()));
  player2 = capitalize(str);
  if (player1 == player2)
    say(player1 + " is starting up a dart game with himself.\n");
  else
    say(player1 + " is starting up a dart game with " + player2 + ".\n");
  strngth = ({int})this_player()->QueryStr();
  intel = ({int})this_player()->QueryInt();
  dex = ({int})this_player()->QueryDex();
  con = ({int})this_player()->QueryCon();
  if(!(lev = query_user_level(this_player())))
    lev = ({int})"/obj/racemaster"->XPtoLevel(({int})this_player()->QueryXP());
  else lev += 20;
  skill1 = 24 - dex;
  if (lev>=20) {
/*
    skill1=2;
*/
    dblout1=1;
  }
  else dblout1 = 0;

/*
  strngth=call_other(find_player(str),"query_str",0);
  intel=call_other(find_player(str),"query_int",0);
*/
  dex = ({int})find_player(str)->QueryDex();
/*
  con=call_other(find_player(str),"query_con",0);
*/
  if(!(lev = query_user_level(find_player(str))))
    lev = ({int})"/obj/racemaster"->XPtoLevel(({int})find_player(str)->QueryXP());
 else lev += 20;
  skill2 = 24 - dex;
  if (lev>=20) {
/*
    skill2=2;
*/
    dblout2=1;
  }
  else dblout2 = 0;

  currplayer = capitalize(getuid(this_player()));
  tell_room(environment(this_object()),currplayer+" will shoot first.\n");
  return 2;
}

int points_game() {
  if ((player1 == "No player") || (player2 == "No player")) {
      notify_fail("No one is playing at the moment.\n");
      return 0;
  }
  if (player1 == player2) {
    write("Current game is being played by " + player1 + " alone.\n" +
        player1 + " has " + points1 + " points    \n");
  }
  else
    write("Current game is between " + player1 + " and " + player2 + ".\n" +
        player1 + " has " + points1 + " points     " +
        player2 + " has " + points2 + " points\n" +
        currplayer+" is still throwing.\n");
  if (bet >= 1) {
    write("The current bet is for "+2*bet+" coins.\n");
  }
  say(capitalize(getuid(this_player())) + " checks the points.\n");
  return 1;
}

int valid_number(string str) {
  return str == "0" || str == "1" || str == "2" || str == "3" || str == "4" ||
   str == "5" || str == "6" || str == "7" || str == "8" || str == "9" ||
   str == "10" || str == "11" || str == "12" || str == "13" || str == "14" ||
   str == "15" || str == "16" || str == "17" || str == "18" || str == "19" ||
   str == "20";
}

int valid_zone(string str) {
  return str =="s" || str=="d" || str=="t";
}

int throw_dart(string str) {
  /* proper syntax -> throw d 20  or  throw s 20 */
  if (!str) {
    notify_fail("Throw to where?\n");
    return 0;
  }
  if ((player1=="No player") || (player2=="No player")) {
     notify_fail("The game has no identified players.  Use 'play <opponent>'\n");
     return 0;
  }
  if(capitalize(getuid(this_player())) != player1) {
    if(capitalize(getuid(this_player())) != player2) {
      notify_fail("The game is already reserved for "+player1+" and "+player2+".\n");
      return 0;
    }
  }
  if(capitalize(getuid(this_player())) != currplayer) {
    notify_fail("It is not your turn!\n");
    return 0;
  }
  target=explode(str," ");
  if (!valid_zone(target[0])) {
    notify_fail("You won't hit the dart board with that!\n");
    return 0;
  }
  if (valid_zone(str)) {
    notify_fail("You won't hit the dart board with that!\n");
    return 0;
  }
  if (!valid_number(target[1])) {
    notify_fail("You won't hit the dart board with that!\n");
    return 0;
  }
  if ((target[0]=="t") && (target[1]=="0")) {
    notify_fail("You won't hit the dart board with that!\n");
    return 0;
  }
  if(capitalize(getuid(this_player())) == player1) {
    skill=skill1;
  } else {
    skill=skill2;
  }
  this_player()->AddXP(1);
  chance= random(skill+2);
  luck= random(4);
  chance= chance+luck;
  sscanf(target[1],"%d",try_hit);
  luck_hit=layout[ (posn[try_hit]+luck) % 20 ];
/*
  write("\nskill:"+skill+"    chance:"+chance);
  write("    luck:"+luck+"    luck_hit:"+luck_hit);
  write("    try_hit:"+try_hit+"\n");
*/
  if (chance <= 2) {
    /* direct hit */
    zone_hit = 1;
    num_hit = 1;
  }
  if ((chance >= 3) && (chance <= 5)) {
    /* number hit, but zone miss */
    zone_hit = 0;
    num_hit = 1;
  }
  if ((chance >= 6) && (chance <= 9)) {
    /* miss on number and zone, but still inbounds */
    zone_hit = 0;
    num_hit = 0;
  }
  if (chance >= 10) {
    /* out of bounds */
    zone_hit = -1;
    num_hit = -1;
  }
  tell_room(environment(this_object()),
          currplayer + " throws ");
  if (num_hit == -1) {
    tell_room(environment(this_object()),"an out of bound shot!\n");
  }
/*
  write("\n    zone_hit:"+zone_hit+"    num_hit:"+num_hit+"    ");
*/
  if ((num_hit != -1) && (zone_hit != -1)) {
    if (zone_hit == 0) {
      zone_hit=1+random(20);
      if (zone_hit >= 19) {
        if (target[1] != "0") {
          target[0]="t";
          multi=3;
        }
        if ((target[1] == "0") && (num_hit == 0)) {
          target[0]="d";
          target[1]="0";
          multi=2;
        }
      }
      if ((zone_hit >= 17) && (zone_hit <= 16)) {
        target[0]="d";
        multi=2;
      }
      if (zone_hit <= 15) {
        target[0]="s";
        multi=1;
      }
    }
    if (target[0]=="t") {
      tell_room(environment(this_object()),"a triple ");
      multi=3;
    }
    if (target[0]=="d") {
      tell_room(environment(this_object()),"a double ");
      multi=2;
    }
    if (target[0]=="s") {
      tell_room(environment(this_object()),"a single ");
      multi=1;
    }
/*
  write("    multi:"+multi+"    ");
*/
  }
  if (num_hit == 1) {
    number = try_hit;
  }
  if (num_hit == 0) {
    number = 1 + try_hit;
    if (skill <= 10) {
      number = 1+random(10);
    }

    miss=random(2) - 1;  /* neg means go left  pos means go right */
    number = miss + number;
    if (number < 0) {
        number = number+20;
    }
    if (number > 20) {
        number = number-20;
    }
/*
    write("\nnumber:"+number+"    miss:"+miss+"\n");
*/
    number=layout[ (posn[number])];
/*
    write("\nnumber:"+number+"    miss:"+miss+"\n");
*/
    if ((number < 0) || (number > 20)) {
      number=2+random(5);
    }
  }
  if (number == 0) {
    number=25;
    if (skill > 2) {
      number= 1+random(10);
    }
  }
/*
  write("number:"+number+"    miss:"+miss+"\n");
*/
  if (num_hit != -1) {
    if (number == 25) {
      tell_room(environment(this_object()),"bulls eye!\n");
    } else {
      tell_room(environment(this_object()),number + ".\n");
    }
  }
  dartcount = dartcount - 1;
  if(num_hit != -1 && currplayer == player1) {
    if((number * multi) > points1) {
      tell_room(environment(this_object()),
        currplayer +
                       " missed the endgame shot for "+points1+ " points.\n");
    }
    else {
      if ((dblout1 == 1) && (number * multi == points1) && (multi != 2)) {
        write("You must double out to win!\n");
        tell_room(environment(this_object()),
          currplayer +
            " missed the double-out endgame shot for "+points1+ " points.\n");
      }
      else {
        if (((points1-(number*multi)) == 1) && (dblout1=1)) {
        tell_room(environment(this_object()),"That throw did not score "+
            currplayer + " any points.\n");
        }
        else
          points1=points1-(number*multi);
      }
    }

    tell_room(environment(this_object()),"Score for " + currplayer +
                                             " is now " + points1 + ".\n");
  }
  if(num_hit != -1 && currplayer == player2 && player1 != player2) {
    if((number * multi) > points2) {
      tell_room(environment(this_object()),
        currplayer + " missed the endgame shot for " + points2 + " points.\n");
    }
    else {
      if ((dblout2 == 1) && (number * multi == points2) && (multi != 2)) {
        write("You must double out to win!\n");
        tell_room(environment(this_object()),
          currplayer + " missed the double-out endgame shot for " + points2 +
          "points.\n");
      }
      else {
        if (((points2-(number*multi)) == 1) && (dblout2=1)) {
        tell_room(environment(this_object()),"That throw did not score "+
            currplayer + " any points.\n");
        }
        else
          points2=points2-(number*multi);
      }
    }

    tell_room(environment(this_object()),"Score for " + currplayer +
                                           " is now " + points2 + ".\n");
  }

  if(!points1 || !points2) {
    if(!points1) {
      tell_room(environment(this_object()),"...and " + player1+" wins ");
      if (bet >= 1) {
        tell_room(environment(this_object()),"the bet and ");
        present("money",find_player(lower_case(player1)))->
        AdjustMoney("/obj/money_demon"->CreateMoney(2*bet));
      }
      this_player()->AddXP(20);
    }
    if ((points2==0) && (player1 != player2)) {
      tell_room(environment(this_object()),"...and " + player2+" wins ");
      if (bet >= 1) {
        tell_room(environment(this_object()),"the bet and ");
        present("money",find_player(lower_case(player2)))->
        AdjustMoney("/obj/money_demon"->CreateMoney(2*bet));
      }
      this_player()->AddXP(20);
    }
    tell_room(environment(this_object()),"the game!\n");
    if (bet >= 1) {
      tell_room(environment(this_object()),
          "The "+2*bet+" coins goes to the winner.\n");
    }
    if (player1 != player2) {
      tell_room(environment(this_object()),
           "Score: "+player1+": "+points1+"   "+player2+": "+points2+"\n\n");
    }
    bet=0;
    new_game("The point keeper automatically");
    tell_room(environment(this_object()),"The dart board is ready for use.\n");
    dartcount=3;
    return 1;
  }
  if (dartcount==0) {
    if(currplayer == player1)
      currplayer=player2;
    else
      currplayer=player1;
    tell_room(environment(this_object()),"Next up: "+currplayer+".\n");
    dartcount=3;
  }
  return 1;
}

