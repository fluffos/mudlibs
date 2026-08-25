// the job ask obj from certain maker
// by fire on July 1999
mixed job(string m_id,string officer_id)
{
   string *mlist,maker_id,obj_id;
   string *oblist;
   string p_area;
   object o=find_body(m_id),o_maker;

   if(!objectp(o)) return 0; // strange
   
   mlist=CHAR_D->check_char("is_maker",1);
   maker_id=mlist[random(sizeof(mlist))];
   oblist=CHAR_D->get_char(maker_id,"goods");
  
   while(!sizeof(oblist)) {
      maker_id=mlist[random(sizeof(mlist))];
      oblist=CHAR_D->get_char(maker_id,"goods");

   }
   obj_id=oblist[random(sizeof(oblist))];

   o_maker=CHAR_D->find_char(maker_id);

   if (o_maker == 0) {
	load_object(CHAR_D->get_char(maker_id,"shd_room"));
	o_maker=CHAR_D->find_char(maker_id);
	if(o_maker==0) return "$N道："+maker_id+"有BUG，告诉WIZ\n";
   }
	
   p_area=o_maker->query_room()->get_area();

   o->set_asklist("kick","target",maker_id);
   o->set_asklist("kick","filename",PJOB+"askobj/askobj");
   o->set_asklist("kick","funname","ask_kick");


  o->add_job("askobj");
  o->set_job("askobj","status","begin");
  o->set_job("askobj","obj_id",obj_id);
  o->set_job("askobj","memo","找"+AREA_D->get_area(p_area,"name")+
       "的"+CHAR_D->get_char(maker_id,"name")+"催"+OBJ_D->get_obj(obj_id,"name"));
   
   return "$N对$T道：那就麻烦$R到"+AREA_D->get_area(p_area,"name")+"找"+
	   CHAR_D->get_char(maker_id,"name")+"催一下我定的"+OBJ_D->get_obj(obj_id,"name")+
            "，\n见面就说ask "+maker_id+" about kick 。\n";
}
void finish(string m_id) {
	tell_user(m_id,"%^H_GREEN%^任务完成，快去太守处领赏吧。\n%^RESET%^");
}
void ask_kick(object me, object target)
{
	string m_id;
	m_id=me->query_primary_id();
	me->targetted_action(
           "$N一脚踢到$T的屁股上道：我们太守要的"+
           OBJ_D->get_obj(me->query_job("askobj","obj_id"),"name")+
           "怎么还没送到？\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N对$T点头赔笑道：$s该死，这就搞好送去。\n",1);
	DELAY_D->delay_targetted_action(
		me,target,"$N对$T道：再不快点，小心你的脑袋。\n",2);

	me->clear_asklist("kick");
	me->set_job("askobj","status","done");
	call_out("finish",3,m_id);
	return;
}
