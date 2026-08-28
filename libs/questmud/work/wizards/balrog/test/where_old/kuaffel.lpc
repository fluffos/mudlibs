#include <ansi.h>
mixed cmd_where() {
  object *all;        
  string *whoa; 
  string *tmp;
  int i;           

  all = users();                                          
  whoa = ({ });

  write("\nPlayers\t\tLocation\n\n");                     

  for (i=0;i<sizeof(all);i++) {                           
    whoa += ({ capitalize(all[i]->query_name()), file_name(environment(all[i])) });
  }                                             

  sort_array(whoa, #'>);

  for (i=0;i<sizeof(whoa);i++) {
    write(sprintf("%s%s%-15s %s%s%s\n",BOLD,BLUE_F,whoa[i][0], CYAN_F, whoa[i][1], OFF ) );    
  }

}
