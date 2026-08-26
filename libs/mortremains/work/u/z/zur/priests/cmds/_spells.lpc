#include "../pr.h"
int cmd_spells()
{
  string *dir;
  int i, col;
  string s;
  dir = get_dir(SPELLS);
  i = sizeof(dir);
  load_object(REL_D);
  while(i--)
  {
    if(col > 2) write("\n");
    if(REL_D->check_spheres(this_player(), dir[i]->query_spheres(), dir[i]->query_level()))
    {
      if(REL_D->level_check(
          (wizardp(this_player())) ? -1 : this_player()->query_level(),
          dir[i]->query_level()))
        {
          s += dir[i];
         }
    }
    printf("%s", capitalize(s));
    col++;
   }
   return 1;
 }
