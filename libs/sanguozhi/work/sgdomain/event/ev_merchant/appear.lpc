// this is used to handle merchant appear
// appear.c
// by fire on Dec 1998
// modified by suicide on 2000.03.06
mapping query_npc_merchant_goods();

void create_merchant(string p_area,string* lis)
{
   int sum,i;
   string p_room;
   object o;
   mixed * npc_country=keys(query_npc_merchant_goods());
   p_room=AREA_D->get_area(p_area,"path")+
      AREA_D->get_area(p_area,"market");
   lis += npc_country;
   foreach(string n_id in lis)
   {  string pp;
      pp=n_id;
      n_id=n_id+" merchant";
      CHAR_D->add_char(n_id);
      CHAR_D->set_char(n_id,"my_nation",pp);
      CHAR_D->set_char(n_id,"area",p_area);
      CHAR_D->set_char(n_id,"name",
                       COUNTRY_D->get_country(pp,"name")+"商人");
      CHAR_D->set_char(n_id,"is_tmp",1);
      CHAR_D->set_char(n_id,"is_merchant",1);
      CHAR_D->set_char(n_id,"body","merchant");
      CHAR_D->put_char(n_id,p_room);
      o=CHAR_D->find_char(n_id);
      if(objectp(o))
         o->simple_action(COUNTRY_D->get_country(pp,"name")+
             "商队在一片喧闹声中走了过来。\n");
   }
}
