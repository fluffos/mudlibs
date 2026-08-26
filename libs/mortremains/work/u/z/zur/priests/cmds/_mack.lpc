#include "../pr.h"
int cmd_mack()
{
  string *sp;
  int i, col;
  string s;
  sp = get_dir("/u/z/zur/priests/spells");
  i = sizeof(sp);
  load_object(REL_D);
  printf("%s%d\n", sp[0], i);
  while(i--)
  {
    if(col > 2)
    {
      col = 0;
      write("\n");
    }
    if(REL_D->check_spheres(this_player(), sp[i]->query_spheres(), sp[i]->query_level()))
    {
      if(REL_D->level_check(
          (wizardp(this_player())) ? -1 : this_player()->query_level(),
          sp[i]->query_level()))
        {
          s += sp[i];
         }
    }
    printf("%s    ", capitalize(s));
    col++;
   }
   return 1;
 }
