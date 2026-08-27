/* The new, dis-improved, slightly wibbled but hopefully working judge
   command, scrapped and completely re-written by Timion.
   Only works if your level is less than 99,999, otherwise gives you
   a cruel message.  Also, "judge all" now works. */
#include "tweaks.h"
 
 
 
string query_judge_mess(int flag)
{
 switch(flag)
 {
  case 1 : return "Worthless";
  case 2 : return "Awful";
  case 3 : return "Poor";
  case 4 : return "Below Average";
  case 5 : return "Average";
  case 6 : return "Above Average";
  case 7 : return "Good";
  case 8 : return "Great";
  case 9 : return "Wonderful";
  case 10 : return "Incredible";
  case 11 : return "Unbelievable";
  case 12 : return "The BEST";
 }
 return "Unknown";
}
int munge_value(int dmg)
{
  int flag;
  flag = 0;
  switch(this_player()->query_level())
  {
   case 0..6:
   {
       switch(dmg)
       {
       case 0..2:
          flag =1;
       break;
       case 3..14:
          flag = 5;
       break;
       default:
          flag = 8;
       break;
      }
   }
   case 7..13 :
   {
       switch(dmg)
       {
        case 0..3 :
           flag = 1;
        break;
        case 4..7 :
           flag = 3;
        break;
        case 8..10 :
           flag = 5;
        break;
        case 11..13 :
           flag = 8;
        break;
        case 14..99 :
           flag = 9;
        break;
       }
   }
   case 14..20 :
   {
      switch(dmg)
      {
      case 0..2 :
        flag = 1;
      break;
      case 3..4 :
        flag = 2;
      break;
      case 5..8 :
        flag = 3;
      break;
      case 9..11 :
        flag = 5;
      break;
      case 12:
        flag = 7;
      break;
      case 13:
        flag = 8;
      break;
      case 14..19:
        flag = 9;
      break;
      case 20..99:
         flag = 11;
      break;
      }
   }
   case 21..99999 :
      switch(dmg)
      {
      case 0..2 :
         flag = 1;
      break;
      case 3..4 :
         flag = 2;
     break;
     case 5:
        flag = 3;
     break;
     case 6..7:
        flag = 4;
     break;
     case 8..9:
        flag = 5;
     break;
     case 10..11:
        flag = 6;
     break;
     case 12:
        flag = 7;
     break;
     case 13:
        flag = 8;
     break;
     case 14..17:
        flag = 9;
     break;
     case 18..19 :
        flag = 10;
     break;
     case 20:
        flag = 11;
     break;
     default:
        flag = 12;
     break;
     }
  }
  return flag;
}



 
judge_weapon(object ob, object ME)
{
 int dmg;
   int flag;
 
 
 if(this_player()->query_level()>99999)
  {
   write("Set your level to something more realistic and try again you jerk.\n");
   return 1;
  }
  dmg=ob->query_damage_roll();
  flag = munge_value(dmg);

  if(!flag)
   tell_object(ME,"You can't quite figure out "+ob->query_short()+".\n");
  else
   tell_object(ME,"Your "+ob->query_short()+" is "+query_judge_mess(flag)+
               " at doing damage.\n");
  return;
}

judge_armour(object ob, object ME)
{
 int dmg;
   int flag;
 
 
 if(this_player()->query_level()>99999)
  {
   write("Set your level to something more realistic and try again you jerk.\n");
   return 1;
  }
   dmg = 2*(ob->query_ac());
  flag = munge_value(dmg);
  if(!flag)
   tell_object(ME,"You can't quite figure out "+ob->query_short()+".\n");
  else
   tell_object(ME,"Your "+ob->query_short()+" is "+query_judge_mess(flag)+
               " protection.\n");
 return;
}
 
void judge(string str)
{
 object *ob;
 int i;
 object ME;
 
 if(!this_player())
   ME=this_object();
 else
   ME=this_player();
 
 if(!str)
  {
   tell_object(ME,"Syntax: judge <object>\n");
   return 1;
  }
 
 if( (str=="all") || (str=="ALL") || (str=="All") )
  {
   ob=ME->all_inventory();
  }
 else
  {
   ob=find_match(str,ME);
  }
 if(!ob)
  {
   tell_object(ME,"You are not carrying "+str+".\n");
   return 1;
  }
 for(i=0;i<sizeof(ob);i++)
 {
  if(ob[i]->query_weapon())
      judge_weapon(ob[i],ME);
  if(ob[i]->query_armour())
     judge_armour(ob[i],ME);
  if(!(ob[i]->query_weapon()) && !(ob[i]->query_armour()) )
   {
    if(ob[i]->query_short())
     tell_object(ME,ob[i]->query_short()+" looks pretty useless to you.\n");
   }
 }
 return 1;
}


