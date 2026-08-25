/*** A Be'lal thingy ***/

#include "skills.h"
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup() { position = 0; }
string query_usage() { return "view <living>\n"; }
string query_short_help() { return "List Skills\n"; }

string rec_list(mixed *arr, string path, int all, int lvl, object ob)
{
  int i, sk;
  string str, tp;

  str = "";
  for (i=0;i<sizeof(arr);i+=SKILL_ARR_SIZE) {
    str += sprintf("%*'| 's%*'.'-s %4d %4d\n", (lvl-1)*2, "", 20-((lvl-1)*2),
                                             arr[i],
                  
  (sk=(int)ob->query_skill((tp=(path+"."+arr[i])))),
                   (int)ob->query_skill_bonus(tp));
    if (sizeof(arr[i+SKILL_BIT]) && (all || sk > 5*lvl))
      str += rec_list(arr[i+SKILL_BIT], path+"."+arr[i], all, lvl+1,ob);
  }
  return str;
}
 
int cmd(string obj, object ob) 
{
  string *bits;
  mixed *arr;
  object targ;

  if (!obj || obj == "" || obj == " ")
    return notify_fail("Usage: view <living>\n");
  obj = ob->expand_nickname(obj);
  if(!(targ = find_player(obj)))
  {
     if (!(targ = find_living(obj)))
     {
        notify_fail("You must specify a person.\n");
        return 0;
     }
  }
        
  bits = ({ });

  arr = (mixed *)SKILL_OB->query_skills();
  printf("%'='*-s\n", ob->query_cols(),
         "=======SKILLS=======Level/Bonus");
  printf("%#*-s\n", ob->query_cols(), rec_list(
                  arr, "", (member_array("all", bits) != -1), 1, targ));
  return 1;
}
