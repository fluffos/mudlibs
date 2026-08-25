/* The new, dis-improved, slightly wibbled but hopefully working judge
   command, scrapped and completely re-written by Timion.
   Only works if your level is less than 99,999, otherwise gives you
   a cruel message.  Also, "judge all" now works. */
#include "/std/commands/tweaks.h"
 
 
 
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

int munge_value(int dmg, object me)
{
  int flag;
  flag = 0;
  switch(me->query_level())
  {
    case 0..6:
      switch(dmg)
      {
        case 0..2: flag =1; break;
        case 3..14: flag = 5; break;
        default: flag = 8; break;
      }
      break;
    case 7..13 :
      switch(dmg)
      {
        case 0..3 : flag = 1; break;
        case 4..7 : flag = 3; break;
        case 8..10 : flag = 5; break;
        case 11..13 : flag = 8; break;
        case 14..99 : flag = 9; break;
      }
      break;
    case 14..20 :
      switch(dmg)
      {
        case 0..2 : flag = 1; break;
        case 3..4 : flag = 2; break;
        case 5..8 : flag = 3; break;
        case 9..11 : flag = 5; break;
        case 12: flag = 7; break;
        case 13: flag = 8; break;
        case 14..19: flag = 9; break;
        case 20..99: flag = 11; break;
      }
      break;
    case 21..99999 :
      switch(dmg)
      {
        case 0..2 : flag = 1; break;
        case 3..4 : flag = 2; break;
        case 5: flag = 3; break;
        case 6..7: flag = 4; break;
        case 8..9: flag = 5; break;
        case 10..11: flag = 6; break;
        case 12: flag = 7; break;
        case 13: flag = 8; break;
        case 14..17: flag = 9; break;
        case 18..19 : flag = 10; break;
        case 20: flag = 11; break;
        default: flag = 12; break;
     }
  }
  return flag;
}

//Added by rift to eliminate the variation in
//reports that judge gave on weapons

int query_max_weapon_damage(object ob)
{
int r1,r2,r3;
r1=ob->query_damage_vals()[0];
r2=ob->query_damage_vals()[1];
r3=ob->query_damage_vals()[2];
return((r1*r2)+r3);
}


 
int judge_weapon(object ob, object me)
{
  int dmg;
  int flag;
  
  dmg=query_max_weapon_damage(ob);
  flag = munge_value(dmg, me);

  if(!flag)
    tell_object(me,"You can't quite figure out "+ob->query_short()+".\n");
  else
    tell_object(me,"Your "+ob->query_short()+" is "+query_judge_mess(flag)+
      " at doing damage.\n");

   return(1);
}

void judge_armour(object ob, object me)
{
  int dmg;
  int flag;
 
  // Taniwha 1995. To compensate for a.c. changes (divide by 5)
  dmg = (int)ob->query_ac()/5;
  flag = munge_value(dmg, me);
  if(!flag)
    tell_object(me,"You can't quite figure out "+ob->query_short()+".\n");
  else
    tell_object(me,"Your "+ob->query_short()+" is "+query_judge_mess(flag)+
      " protection.\n");
  return;
}
 
int judge(string str, object who)
{
  object *ob;
  int i;
  object me;
 
  me = ( who ? who : this_player() );
 
  if(!str)
  {
    tell_object(me,"Syntax: judge <object>\n");
    return 1;
  }
 
  if( (str=="all") || (str=="ALL") || (str=="All") )
str="0";
    ob=find_match(str,me);

  if(!sizeof(ob))
  {
    tell_object(me,"You are not carrying "+str+".\n");
    return 1;
  }

  for(i=0;i<sizeof(ob);i++)
  {
    if(ob[i]->query_weapon())
      judge_weapon(ob[i],me);
    else if(ob[i]->query_armour())
      judge_armour(ob[i],me);
    else if(ob[i]->query_short())
      tell_object(me,ob[i]->query_short()+" looks pretty useless to you.\n");
  }

  return 1;
}

