// loyalty.c
#include <char.h>
mixed get_char(string p_id, string what);
void set_char_loyalty(string char_id,string nation_id,int p_value)
{  mixed lo;
   string *k;   
   if(nation_id=="") {
 	nation_id=AREA_D->get_area(get_char(char_id,"area"),"nation");
   }

   if(!char_exist(char_id)) return;
   lo=get_char(char_id,"lo");
   if(!lo) lo=([]);
   if(sizeof(lo)) {
      k=keys(lo);
      foreach(string na in k) {
         if(!COUNTRY_D->nation_exist(na))
           map_delete(lo,na);
      }
   }
   if(!(COUNTRY_D->nation_exist(nation_id)))
       return;
   p_value=bmax(p_value,1);
   p_value=bmin(p_value,100);
   lo[nation_id]=p_value;
   set_char(char_id,"lo",lo);
   return;
}
int get_char_loyalty(string char_id,string nation_id)
{ 
   mixed lo;
   int ret;
   if(nation_id=="") {
 	nation_id=AREA_D->get_area(get_char(char_id,"area"),"nation");
   }
   if(nation_id==char_id)
      return 100;
   if(CHAR_D->get_char(char_id,"is_tmp")) {
      CHAR_D->set_char(char_id,"lo",0); return 0;
   }
   lo=get_char(char_id,"lo");
   if(!lo) lo=([]);
   if(!lo[nation_id])
   {  
      if(get_char(char_id,"nation")==nation_id)
          ret=random(50)+50;
      else 
          ret=random(50)+10;
      set_char_loyalty(char_id,nation_id,ret);
      set_char_modified();
      return ret;
   }
   return lo[nation_id];
}
