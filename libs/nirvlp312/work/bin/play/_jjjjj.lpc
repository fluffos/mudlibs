#include <ansi.h>
#include "/obj/lib/living/settings.h"

#define TP this_player()

int cmd_score(string str)
{
  int intox_level;
  string tmp;
  int tmpp, ex_lv;
  int infuse, level;
  object bbb; 
  
  if (this_player()->query_ghost())
  {
    write("You are in an immaterial state with no scores.\n");
	  return 1;
  }
  write("\n");

  bbb = TP;
  if(str){
    if((int)TP->query_level()<50) str=(string)TP->query_real_name();
    if(!(bbb=find_player(str))) {
      write(str+" is not online.\n");
      return 1;
    }
  }  

  write(bbb->short()+"\n");
  ex_lv=(int)bbb->query_extra_level();
  write("Level: "+(int)bbb->query_level()+" "+
   (ex_lv ? 
    (ex_lv+" ("+bbb->query_total_level()+")\n") : "\n"));
 
  write("Coins: "+(int)bbb->query_money()
  +"          \t\tExperience: "+(int)bbb->query_exp()+"\n");
  
  write("Hit points: "+(int)bbb->query_hp()+"/"+(int)bbb->query_mhp()+"     ");
  write("\t");
  write("Spell points: "+(int)bbb->query_sp()+"/"+(int)bbb->query_msp()+"\n");
  write("Quest points: "+(int)bbb->query_quest_point()+"\t\t");
  
  infuse = (int)bbb->query_infuse();
  level = (int)bbb->query_level();
  
  if(infuse > 0)
    write("Infused: "+(2*infuse/3)+"/"+(2*(INFUSE_LIMIT)/3)+"\n");
  else write("\n");
  
  TP->show_age();
  
  if(bbb->query_tellblock_index(0) && 
     (string)bbb->query_tellblock_index(0) != "off") write("Tellblock is ON.\n");
     
  if(bbb->query_pregnancy())
  {
    tmpp=(int)bbb->query_age()-(int)bbb->query_pregnancy();
    if(tmpp > 4000) 
      write("You are Pregnant ("+tmpp+" / 16200)\n");
  }
  
  if(bbb->query_hunter() && bbb->query_hunter()->query_name())
    write("You are hunted by "+(string)bbb->query_hunter()->query_name()+ ".\n");
    
  if (!bbb->query_intoxination())
    write("You are sober.\n");
  else
  {
    intox_level=level+4;
    intox_level/=(int)bbb->query_intoxination();
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
  if (bbb->query_stuffed() || bbb->query_soaked()) {
	  write("You are ");
    if (bbb->query_stuffed())
      write("satiated"+(TP->query_soaked() ? " and " : ".\n"));
	  if (bbb->query_soaked()) write("not thirsty.\n");
  }

  if (bbb->query_whimpy())
	  write("Wimpy mode.\n");
	  
	if(TP->check_fight_area()) write("You are in a "+HIR+"PK"+NORM+" zone.\n");
  write("Carrying "+(int)bbb->query_pct_weight()+"% of maximum capacity.\n");
  write("\n");
  return 1;
}
