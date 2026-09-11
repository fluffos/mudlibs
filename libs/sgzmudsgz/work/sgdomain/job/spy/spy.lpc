// the job of spy certain area
// by fire on March 1999
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string m_nation=CHAR_D->get_char(officer_id,"nation");

   string *mlist,target,*tmp,st;
   mapping a_d;
   string p_path;

   object o=find_body(m_id);
   object env,*obs;
   if(!objectp(o)) return 0;

   mlist=AREA_D->list_areas();
   mlist=filter_array(mlist,(:AREA_D->get_area($1,"nation")
	   !=$(m_nation):));


   if(!sizeof(mlist)){
   		o->add_job("spy");
	   o->finish_job("spy");
		return "$N对$T道：现在没什么地方好侦察呀。\n";
   }
   a_d=AREA_D->get_all_distance(m_area);
   mlist=sort_array(mlist,(: $(a_d)[$1] > $(a_d)[$2] ? 1 : -1 :));

   if((sizeof(mlist)>5)&&random(2)) 
	target=mlist[random(5)];
   else
        target=mlist[random(sizeof(mlist))];

   p_path=AREA_D->get_area(target,"path");
   mlist=AREA(target)->get_room("list");

   o->add_job("spy");
   o->set_job("spy","status","begin");
   o->set_job("spy","spied",({}));

   o->set_job("spy","area",target);
   
   o->set_job("spy","path",p_path);
/*   tmp=({});
   foreach(string p in mlist)
   {
		st=p_path+p[0..<3];
		tmp+=({st});
   } */
   o->set_job("spy","size",sizeof(mlist));
  
   o->set_job("spy","memo","侦察"+AREA_D->get_area(target,"name"));
   
   return "$N对$T道：那就麻烦$R去帮侦察一下"+
	   AREA_D->get_area(target,"name")+
	   "，\n有困难就用 help spy。\n";
}
