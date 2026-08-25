// guard.c 
// by fire on June, 2000
// This command used to send guard to guard the meeting room
void send_room_guard(string p_area,int task_id,string p_room,string p_dir) {
	string p_id=p_area+" meetingguard "+p_room;
	object o;
	CHAR_D->add_char(p_id);
	CHAR_D->set_char(p_id,"is_tmp",1);
	CHAR_D->set_char(p_id,"is_meetingguard",1);
	CHAR_D->set_char(p_id,"body","meetingguard");
	o=CHAR_D->creat_row_npc_char(p_id);
	if(objectp(o)) {
      o->set_position(p_area,task_id,p_room,p_dir);
	}

	CHAR_D->appear(p_id,p_area,p_room);
   CHAR_D->remove_char_d(p_id);

}

void send_guard(string p_area,int task_id) {
	string p_path,p_room;
	mapping exs,exp;
          this_body()->simple_action("$N大喝一声：卫兵何在？\n");
          DELAY_D->delay_simple_action(this_body(),"几名卫兵应道：在！\n",1);
          DELAY_D->delay_simple_action(this_body(),"$N道：到门外仔细把守，不要放进一个奸细。\n",2);
          DELAY_D->delay_simple_action(this_body(),"众卫兵道：得令！\n几名卫兵走出门外。\n",3);
	p_room=AREA_D->get_area(p_area,"meeting");
	p_path=AREA_D->get_area(p_area,"path");
	exs=AREA(p_area)->get_room(p_room,"e");
	foreach(string s in values(exs)) {
		exp=AREA(p_area)->get_room(s,"e");
		if(!sizeof(exp)) continue;
		foreach(string d,string r in exp) {
			if(r==p_room)
				send_room_guard(p_area,task_id,s,d);
		}
	}

}
void clean_room(string p_area) {
	string p_exit,p_room,p_id,p_nation,p_name;
	object o_room,o_exit;
	object *pps;
          this_body()->simple_action("$N大喝一声：卫兵何在？\n");
          DELAY_D->delay_simple_action(this_body(),"几名卫兵应道：在！\n",1);
          DELAY_D->delay_simple_action(this_body(),"$N道：把屋里这些闲杂人员都哄出去！\n",2);
          DELAY_D->delay_simple_action(this_body(),"众卫兵道：得令！\n",3);
	p_room=AREA_D->get_area(p_area,"meeting");

	p_exit=values(AREA(p_area)->get_room(p_room,"e"))[0];

	o_room=load_object("/a/"+p_area+"/"+p_room);
	o_exit=load_object("/a/"+p_area+"/"+p_exit);

	p_nation=AREA_D->get_area(p_area,"nation");
	pps=all_inventory(o_room);
	if(sizeof (pps)) {
		foreach(object p in pps) {
			if(!p->is_living()) continue;
			p_id=p->query_primary_id();
			if(CHAR_D->get_char(p_id,"nation")!=p_nation) {
				p_name=p->short();
                                  DELAY_D->delay_simple_action(this_body(),"众卫兵连推带拉地将"+p_name+"扔了出去。\n",4);
				p->move(o_exit);
                                  DELAY_D->delay_simple_action(p,"$N被一群卫兵连推带拉地扔了出来。\n",4);
			}
		}
				
	}

}
void start(string arg)
{
    string p_talk;
    int task_id;
    int* my_task;
	string p_id;
	string p_area;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");

	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
                  write("只有在会议之所才可以派卫兵。\n");
		return;
	}

	my_task = TASK_D->get_char_task(p_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {
                    write("只有在举行地区会议时才有必要派卫兵。\n");
                return;
        }
        task_id=my_task[0];
		if(arg=="clean") {
			clean_room(p_area);

			return;
		}
        if(TASK_D->get_task(task_id,"send_guard"))
        {
                  write("卫兵已经派过了。\n");
                return;
        }
		TASK_D->set_task(task_id,"send_guard",1);
		send_guard(p_area,task_id);
}

