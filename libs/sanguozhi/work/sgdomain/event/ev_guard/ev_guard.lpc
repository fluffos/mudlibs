// this is used to handle guard appear
// appear.c
// by row on May 1999
#include <ansi.h>
void create_guard(string p_area);

void create_guard(string p_area)
{
   int sum,i;
   string p_room;
   string p_id; 
   object o;
   p_id=p_area+" guard";
   if(!CHAR_D->char_exist(p_id))
   {
      CHAR_D->add_char(p_id);
//      CHAR_D->set_char(p_id,"my_type",p_type);
      CHAR_D->set_char(p_id,"my_area",p_area);
      CHAR_D->set_char(p_id,"name",""HIC"司隶校尉"NOR"");
      CHAR_D->set_char(p_id,"is_tmp",1);
      CHAR_D->set_char(p_id,"is_guard",1);
      CHAR_D->set_char(p_id,"body","guard");
   }
   o=CHAR_D->find_char(p_id);
   if(!objectp(o))
   
   CHAR_D->appear(p_id,p_area,AREA_D->get_area(p_area,"go"),"一名$N盛气凌人地走了过来。\n");
}
void aut_appear()
{
   
   string *area;
   int i;
   area=AREA_D->list_areas();
   foreach(string p_area in area)
   create_guard(p_area);
}