// the job of bugao
// by fire on March 1999
#define BUGAO "/sgdomain/obj/other/sdpk"
#include <move.h>
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string m_nation=CHAR_D->get_char(officer_id,"nation");

   string *mlist,target,*tmp,st,rmnam;
   mapping a_d;
   string p_path;

   object o=find_body(m_id);
   object env,*obs,obg;
   if(!objectp(o)) return 0;

   mlist=AREA_D->list_areas();
   mlist=filter_array(mlist,(:AREA_D->get_area($1,"nation")!=$(m_nation):));


   if(!sizeof(mlist)){
	   o->add_job("bugao");
		o->finish_job("bugao");
		return "$N对$T道：现在没什么地方好张贴布告的。\n";
   }
   a_d=AREA_D->get_all_distance(m_area);
   mlist=sort_array(mlist,(: $(a_d)[$1] > $(a_d)[$2] ? 1 : -1 :));

	if((sizeof(mlist)>5)&&random(2)) 
		target=mlist[random(5)];
	else
        target=mlist[random(sizeof(mlist))];

	p_path=AREA_D->get_area(target,"path");
	mlist=AREA(target)->get_room("list");
	tell_user("huaer",sprintf("在布告任务bugao.c中target = %s\n",target));
	//rmnam=AREA(target)->get_room(mlist[random(sizeof(mlist))],"b"); 	为了简化city.o,去掉原代码中"b"字段.
	rmnam=mlist[random(sizeof(mlist))];
	rmnam = (AREA_D->get_area(target,"path") + rmnam)->short();
	tell_user("huaer",sprintf("rmnam = %s\n",rmnam));
   
   obg=new(BUGAO);

   obg->set_area(target);
   obg->set_roomname(rmnam);

   if((obg->move(o))!=MOVE_OK) {
	destruct(obg);
      return "$N对$T道：你身上东西太多了，拿不了这些布告。\n";
   }

   o->add_job("bugao");
   o->set_job("bugao","status","begin");
   o->set_job("bugao","memo",AREA_D->get_area(target,"name")+"的"+rmnam);
   
   return "$N嘿嘿一笑，对$T道：那就麻烦$R把这张布告贴到"+AREA_D->get_area(target,"name")+
	   "的"+rmnam+"。"
	   "\n到那里后用 %^H_BLUE%^drop bugao%^RESET%^就行了。\n";
}

void bugao_catch(string o_id,string p_id,object o_bugao)
{
        object o_o,o_p;
	o_o=CHAR_D->find_char(o_id);
	o_p=CHAR_D->find_char(p_id);
	if((!objectp(o_o))&&(!objectp(o_p)))
		return;

        o_o->targetted_action(
                "$N对$T大喝一声：大胆$r，竟然在此张贴布告，快给我拿下！\n",o_p);
        o_p->simple_action(
                "众官兵一拥而上，把$N捆得结结实实。\n");
        o_o->simple_action(
                "$N一挥手道：给我带走。\n");
        o_p->simple_action(
                "众官兵把$N押了下去。\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "在"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "张贴布告，被正在巡逻的"+CHAR_D->get_char(o_id,"name")+
                "当场抓获。");
        (PCMD+"catch")->catch_award(o_id,p_id);
	if(objectp(o_bugao)) destruct(o_bugao);
}
