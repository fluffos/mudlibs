#include <ansi.h>
#include "/obj/lib/living/settings.h"

#define TP this_player()
#define COL1_SIZE 31


string
add_zero(mixed str) {
  str = "" + str;
  if (strlen(str) == 1)
    str = "0" + str;
  return str;
}

int cmd_score()
{
  int intox_level;
  string tmp;
  int tmpp, ex_lv, plev, pqp;
  int infuse, level;
  int tkill;
  mixed *top_kill;
    
  if (this_player()->query_ghost())
  {
    write("You are in an immaterial state with no scores.\n");
	  return 1;
  }
  this_player()->transfer_extra_eq();
  write("\n");
  
  write(TP->short()+"\n");
  level = (int)TP->query_level();
  ex_lv=(int)TP->query_extra_level();
  plev = (int) TP->query_prestige_level();
  write("Level: "+level+(ex_lv ? "+"+add_zero(ex_lv) : "")+(plev ? HIG+"{"+plev+"}"+NORM : "")+
   (ex_lv ? (" ("+TP->query_total_level()+")\n") : "\n"));
 
  write("Score: "+comma_number((int) TP->query_prestige_score()) +"\n");
  write(pad("Coins: "+comma_number((int)TP->query_money()),COL1_SIZE)
  +"Experience: "+comma_number((int)TP->query_exp())+"\n");
  
  write(pad("Hit points: "+(int)TP->query_hp()+"/"+(int)TP->query_mhp(),COL1_SIZE)+
            "Spell points: "+(int)TP->query_sp()+"/"+(int)TP->query_msp()+"\n");
  pqp = (int)this_player()->query_prestige_qp();
  write(pad("Quest points: "+(int)TP->query_quest_point(),COL1_SIZE)+
       (pqp ? "Prestige Quest Points: "+ pqp : "")+"\n");
  
  top_kill = (mixed *) TP->query_top_kill();
  if( top_kill )
    tkill = top_kill[0];
  else
    tkill = 0;
  
  write( pad("Top Kill: " +comma_number(tkill), COL1_SIZE ));
  write( "Top Boot Exp: " +comma_number(TP->query_top_boot_xp()) +"\n");
  
  infuse = (int)TP->query_infuse();
  
  if(infuse > 0)
    write("Infused: "+(2*infuse/3)+"/"+(2*(INFUSE_LIMIT)/3)+"\n");
  if (((int)TP->query_level() > 19) || (TP->is_testchar()))
    if ((int)TP->query_bank_balance())
      write("Bank Balance: " + comma_number(TP->query_bank_balance()) + "\n");
  TP->show_age();
  
  if(TP->query_tellblock_index(0) && 
     (string)TP->query_tellblock_index(0) != "off") write("Tellblock is ON.\n");
     
  if(TP->query_pregnancy())
  {
    tmpp=(int)TP->query_age()-(int)TP->query_pregnancy();
    if(tmpp > 4000) 
      write("You are Pregnant ("+tmpp+" / 16200)\n");
  }
  
  if(TP->query_hunter() && TP->query_hunter()->query_name())
    write("You are hunted by "+(string)TP->query_hunter()->query_name()+ ".\n");
    
  if (!TP->query_intoxination())
    write("You are sober.\n");
  else
  {
    intox_level=level+4;
    intox_level/=(int)TP->query_intoxination();
    if (intox_level == 0)
      write("You are in a drunken stupor.\n");
    else if (intox_level == 1)
      write("You are roaring drunk.\n");
    else if (intox_level == 2)
      write("You are somewhat drunk.\n");
    else if (intox_level == 3)
      write("You are quite tipsy.\n");
    else
      write("You are slightly tipsy.\n");
  }
  if (TP->query_stuffed() || TP->query_soaked()) {
	  write("You are ");
    if (TP->query_stuffed())
      write("satiated"+(TP->query_soaked() ? " and " : ".\n"));
	  if (TP->query_soaked()) write("not thirsty.\n");
  }

  if (TP->query_whimpy())
	  write("Wimpy mode.\n");
	  
	if(TP->check_fight_area()) write("You are in a "+HIR+"PK"+NORM+" zone.\n");
  write("Carrying "+(int)TP->query_pct_weight()+"% of maximum capacity.\n");
  if((int)"/room/post"->query_mail(1) == 2) write("You have unread mail in the post office.\n");
  write("\nCurrent Area Creator: ");
  if(creator(environment(TP))) write(capitalize(creator(environment(TP))));
  else write("None");
  write(".\n\n");
  return 1;
}
