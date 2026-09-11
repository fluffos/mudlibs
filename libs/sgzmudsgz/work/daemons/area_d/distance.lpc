// distance for area_d.c
// by fire on Nov 1998
int get_distance(string sor,string tar)
{
   string *explored_area;
   string *leave;
   string *neighbor;
   string cen;
   int i,tmp;
   mixed dist=([]);
   int t_find=0;
   int n_area=1;
   if((!AREA_D->area_exist(sor))||(!AREA_D->area_exist(tar)))
     return -1; // one area is not exist
   if(sor==tar) return 0;
   explored_area=({sor});
   dist[sor]=0;
   leave=({sor});
   while((sizeof(leave))&&(!t_find))
   {  cen=leave[0];
      neighbor=AREA_D->get_area(cen,"neighbor");
      if(sizeof(neighbor))
      neighbor-=explored_area;
      if(sizeof(neighbor))
      {
         tmp=dist[cen]+1;
         for(i=0;i<sizeof(neighbor);++i)
         {
            dist[neighbor[i]]=tmp;
            if(neighbor[i]==tar)
                t_find=1;
         }
         explored_area+=neighbor;
         leave+=neighbor;
       }  
       leave-=({cen});
   }
   if(dist[tar]) return dist[tar];
   return 100; // not connected
}
mixed get_all_distance(string sor)
{
   string *explored_area;
   string *leave;
   string *neighbor;
   string cen;
   int i,tmp;
   mixed dist=([]);
   if(!AREA_D->area_exist(sor))
     return -1; // the area not exist
   explored_area=({sor});
   dist[sor]=0;
   leave=({sor});
   while((sizeof(leave)))
   {  cen=leave[0];
      neighbor=AREA_D->get_area(cen,"neighbor");
      neighbor-=explored_area;
      if(sizeof(neighbor))
      {
         tmp=dist[cen]+1;
         for(i=0;i<sizeof(neighbor);++i)
         {
            dist[neighbor[i]]=tmp;
         }
         explored_area+=neighbor;
         leave+=neighbor;
       }  
       leave-=({cen});
   }
   return dist;
}
