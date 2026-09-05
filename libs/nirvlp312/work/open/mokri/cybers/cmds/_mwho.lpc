#include "/players/mokri/define.h"

main(string str)
{
   
   int x, a;
   object *us;
   string names, *colors, *people;
   colors = ({ HIC,HIY });
   
   if(str)
      {
      people = explode(str,",");
      for(x = 0; x < sizeof(people); x++)
      {
         while(extract(people[x],0,0) == " ")
         people[x] = extract(people[x],1);
         while(extract(people[x],strlen(people[x]) - 1) == " ")
         people[x] = extract(people[x],0,strlen(people[x]) - 2);
      }
   }
   
   us = users();
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" +
      HIY+"Name           HP    SP    Money\n"+NORM+
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   a = 0;
   for(x = 0; x < sizeof(us); x++)
   {
      if(us[x]->query_level() < 20 && !us[x]->is_testchar() && environment(us[x]))
         {
         if(!str || (str && member(people,(string)us[x]->query_real_name()) != -1))
            {
            if(us[x]->query_invis())
               names = "(" + CAP(us[x]->query_real_name()) + ")";
            else
               names = CAP(us[x]->query_real_name());
            write(colors[a % 2] + pad(names,15) + pad((100 * us[x]->query_hp() / us[x]->query_mhp()) + "%",-4) + "  " + pad(( 100 * us[x]->query_sp() / us[x]->query_msp()) + "%",-4) + "  " + pad((int)us[x]->query_money(),8) + "\n" + NORM);
            a++;
         }
         
       }
   }
   
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   return 1;
}
