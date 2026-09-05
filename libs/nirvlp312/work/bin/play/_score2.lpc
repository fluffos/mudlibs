#include <security.h>

#include "/obj/player/prestige.h"                      

#include "/obj/player/nrpoints.h"

void print_rewards( string header );

void print_rewards( string header ) {
  int week_start, req_exp, weekly_exp, weekly_streak, weekly_streak_max, lr_flag, max_exp;
  int diff, hours, mins, days;

  week_start = (int) this_player()->query_lr_period_start();
  req_exp   = (int) this_player()->query_lr_required_exp();
  weekly_exp = (int) this_player()->query_lr_exp();
  weekly_streak = (int) this_player()->query_lr_streak();
  weekly_streak_max = (int) this_player()->query_lr_top_streak();
  lr_flag = (int) this_player()->query_lr_flag();
  max_exp = (int) this_player()->query_lr_top_exp();
  
  write("Login weekly rewards start: " + ctime(week_start) + "\n" );

  diff = week_start + WEEK - time();
  days = diff / DAY;
  diff -= days * DAY;
  hours = diff / HOUR;
  diff -= hours * HOUR;
  mins = diff / MIN;
  diff -= mins * MIN;
  write( "You have " +( days ? days+" days, " : "") + ( hours ? hours+" hours, " : "") + 
                      ( mins ? mins+ " minutes, " : "") +
                      diff+" seconds before the current week ends.\n\n");
  
  diff = req_exp - weekly_exp;
  if( diff < 0 )
    diff = 0;
    
  write( "\tWeekly Exp required : " + pad( comma_number( req_exp ), -12) + "\n" );
  write( "\t  Weekly Exp Earned : " + pad( comma_number( weekly_exp ), -12) + "\n" );
  write( "\t   Exp Still Needed : " + ( lr_flag ? "Login Reward Earned!" : pad(comma_number( diff ), -12)) + "\n");
  write( "\t     Max Weekly Exp : " + pad( comma_number( max_exp ),  -12 ) + "\n\n");
  
  write( "Avail Points: " + pad(comma_number( this_player()->query_nrpoints() ), -9) + 
    pad( "Current Streak: ",-35 ) + weekly_streak + "\n" );
  write( "Total Points: " + pad(comma_number( this_player()->query_totalpoints() ), -9) + 
     pad( "Longest Streak: ",-35 ) + weekly_streak_max + "\n\n" );

   write("Your Nirvana Birthday is: "+(string) MISCD->display_date( this_player()->query_nbday() )+".\n");
   write( header );
}

int cmd_score2(string str) {
  string header;
  object who;
  who = this_player();
  header = implode(explode(pad("",40,'='),""),"-")+"\n";
  if(str) who = find_player(str);
      write( header );
      if(!str)
      write("Your attributes are:\n");
      if(str)
      write(capitalize(str)+"'s attributes are:\n");
      write("Charisma:       "+(int)who->query_attrib("cha")+"\t");
      write("Dexterity:      "+(int)who->query_attrib("dex")+"\n");
      write("Intelligence:   "+(int)who->query_attrib("int")+"\t");
      write("Luck:           "+(int)who->query_attrib("luc")+"\n");
      write("Magic Aptitude: "+(int)who->query_attrib("mag")+"\t");
      write("Piety:          "+(int)who->query_attrib("pie")+"\n");
      write("Stamina:        "+(int)who->query_attrib("sta")+"\t");
      write("Stealth:        "+(int)who->query_attrib("ste")+"\n");
      write("Strength:       "+(int)who->query_attrib("str")+"\t");
      write("Will Power:     "+(int)who->query_attrib("wil")+"\n");

      write( header );
      if( who->query_prestige_level() ) {
        int i;
        write("Prestige Skill Points: "+ who->query_prestige_skillpt()+"\n");
        for( i=0; i < sizeof(PRES_SKILL_DESC); i++ ) {
          write("   "+pad(PRES_SKILL_DESC[i]+":", 17) + who->query_prestige_skill( VALID_PRES_SKILL[i] ) );
          if( i%3 == 2 )
            write( "\n" );
          else
            write( "\t" );
        }
        write( header );
      }
      if( this_player()->query_lr_period_start() )
        print_rewards( header );

  return 1;
}
