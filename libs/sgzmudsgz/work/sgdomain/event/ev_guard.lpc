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
   object o,o_room;
   p_id=p_area+" guard";

   p_room=AREA_D->get_area(p_area,"path")+
     AREA_D->get_area(p_area,"go");
   if(!stringp(p_room)) return;
   o_room=load_object(p_room);
   if(!objectp(o_room)) {return;}
   o=present(p_id,o_room);
   if(objectp(o)) return; // has already
   CHAR_D->add_char(p_id);
CHAR_D->set_char(p_id,"my_type","p_type");
   CHAR_D->set_char(p_id,"my_area",p_area);
   CHAR_D->set_char(p_id,"name",""HIC"司隶校尉"NOR"");
   CHAR_D->set_char(p_id,"is_tmp",1);
   CHAR_D->set_char(p_id,"is_guard",1);
   CHAR_D->set_char(p_id,"body","guard");
   CHAR_D->appear(p_id,p_area,AREA_D->get_area(p_area,"go"),"一名$N盛气凌人地走了过来。\n");
   o=CHAR_D->find_char(p_id);
   o->set_area(p_area);
   CHAR_D->remove_char_d(p_id);
}
void aut_appear()
{
   
   string *area;
   int i;
   area=AREA_D->list_areas();
   foreach(string p_area in area)
   create_guard(p_area);
}
