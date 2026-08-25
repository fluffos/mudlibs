// head.c by fire on Dec 1998
void auto_head(string p_id)
{
   string* list_char;
   int max_nationlevel=0,max_locallevel=0,max_meili=0;
   int p_nationlevel,p_locallevel,p_meili;
   int title,i;
   string recorder_holder="";
   string my_nation,my_id;
   mixed m_tmp;

   my_nation=AREA_D->get_area(p_id,"nation");
    list_char=CHAR_D->check_char_area("nation",my_nation,p_id);
    if(sizeof(list_char)) {
	list_char=filter_array(list_char, (:CHAR_D->get_char($1,"type") == TYPE_NPC :) );
    }
   if(!sizeof(list_char)) {
      list_char=CHAR_D->check_char("nation",my_nation);
	if(sizeof(list_char))
      list_char=filter_array(list_char,(:CHAR_D->get_char($1,"type")==TYPE_NPC:));
      list_char-=({my_nation}); //2001.4.13
   }
	m_tmp=OFFICER_D->query_area_officer_title(AREA_D->get_area(p_id,"level"),0,0);
	title=m_tmp[0];
	tell_user("huaer",sprintf("在自动选太守函数中head.c /auto_head(%s)\n",p_id));
	tell_user("huaer",sprintf("太守官职信息是 %O\n",m_tmp));
	for(i=0;i<sizeof(list_char);i++)
	{
		my_id=list_char[i];
		//tell_user("huaer",sprintf("武将名字是%s\n",my_id));
//	if(my_id==my_nation) continue; // the leader
		if(CHAR_D->get_char(my_id,"task")) continue;
		if(AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"leader")==my_id) 
			continue; // other leader
		p_nationlevel=OFFICER_D->query_level(CHAR_D->get_char(my_id,"ranknation"));
        p_locallevel=OFFICER_D->query_level(CHAR_D->get_char(my_id,"ranklocal"));
        m_tmp=CHAR_D->get_char(my_id,"skills");
		
        p_meili=m_tmp["sk_meili"];
        if(p_nationlevel>max_nationlevel)
        {   max_nationlevel=p_nationlevel;
            recorder_holder=my_id;
        }
        else
        {   if((!max_nationlevel)&&
               (p_locallevel>max_locallevel))
            {  max_locallevel=p_locallevel;
               recorder_holder=my_id;
            }
            else
            {   if((!max_nationlevel)&&(!max_locallevel)&&
                   (p_meili>max_meili))
                {  max_meili=p_meili;
                   recorder_holder=my_id;
                }
            }
         }
    }
   if(recorder_holder=="")
   {
     CHANNEL_D->deliver_emote("gossip","",
         sprintf("%s没有%s，当地居民感到不满．",
           AREA_D->get_area(p_id,"name"),
           OFFICER_D->query_rank_name(title)));
       AREA_D->set_area(p_id,"safe",
         AREA_D->get_area(p_id,"safe")-5);
       AREA_D->set_area(p_id,"status",ST_NOOFFICER);
       return;
   }
   AREA_D->set_area(p_id,"status",ST_NORMAL);

    if(max_nationlevel||max_locallevel) // easy
    {  CHAR_D->set_char(recorder_holder,"ranklocal",title);
	 CHAR_D->set_char(recorder_holder,"area",p_id);

       CHANNEL_D->deliver_emote("gossip","",sprintf(
           "受当地官员推举，%s成为%s的%s",
          CHAR_D->get_char(recorder_holder,"name"),
          AREA_D->get_area(p_id,"name"),
          OFFICER_D->query_rank_name(title)));
       return;
     }
     else
     {
	 CHAR_D->set_char(recorder_holder,"area",p_id);
         CHAR_D->set_char(recorder_holder,"ranklocal",title);
      CHAR_D->set_char(recorder_holder,"grant",0);
         CHAR_D->set_char(recorder_holder,"nation",
         AREA_D->get_area(p_id,"nation"));
         CHANNEL_D->deliver_emote("gossip","",sprintf(
            "受当地百姓推举，%s成为%s的%s",
         CHAR_D->get_char(recorder_holder,"name"),
         AREA_D->get_area(p_id,"name"),
         OFFICER_D->query_rank_name(title)));
         return;
     }
}
