cmd_att(str)
{
  object *list;
  int ll,hl,age_n,age_n2, i, z, x;
  int id_t,a,t;
   string option,gen;
   list=users();
   t = sizeof(list);
   for(i=0; i<sizeof(list); i++) {
      if(list[i]->query_invis() > 55 && this_player()->query_level() < list[i]->query_level())
         t -=1;
   }
   write("There are now " + t + " players");
   write("\n");
   write("Name\t\t\tAttacking\n");
   write("......................................\n");
i =0;
   while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
         if(list[i]->query_invis() < 55 || (list[i]->query_invis() > 55 && this_player()->query_level() >= list[i]->query_level()))
            {
            sn=capitalize(list[i]->query_real_name());
            plob = find_player(sn);
            sn = capitalize(sn);
            if(list[i]->query_ghost() == 1) {
               sn = "ghost of " + sn;
            }
               obply=list[i]->query_attack();
               if(obply)
               ip=obply->query_name();
               if(!obply) ip="nothing";
                write(sn+"\t\t"+ip+"\t");
              if(obply)
               write(obply);
               write("\n");
         }
   i += 1;
   x = 0;
}
return 1;
}
