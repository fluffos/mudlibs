// attack_enter
// this means the attack part enter the battle field
// so the war can not aborted anymore
void attack_enter(int task_id)
{
    int* att_army;
    string att_name;
    string def_area,def_name;
    string att_leader,att_leadername;
    string disp;
    int p_num;
    int i,troop_num;
    att_name=TASK_D->get_task(task_id,"att_name");
    att_army=TASK_D->get_task(task_id,"att_army");
    att_leader=TASK_D->get_task(task_id,"att_leader");
    att_leadername=CHAR_D->get_char(att_leader,"name");
    troop_num=sizeof(att_army);
    p_num=0;
    for(i=0;i<troop_num;++i)
    {
	p_num+=TROOP_D->get_troops(att_army[i],"total_num");
    }
    def_area=TASK_D->get_task(task_id,"def_area");
    def_name=AREA_D->get_area(def_area,"name");
    disp=att_leadername+"领"+att_name+"兵士"+
    CHINESE_D->chinese_number(p_num)+"人向"+def_name+"攻来。";
    CHANNEL_D->deliver_tell("rumor","system",disp);
    call_out("final_decision",1,task_id);
}
