// ev_npc_move this is used to handle the movement of npc chars
void npc_move(string c_id)
{
	object p_o;
        string p_curarea,p_desarea,*p_a;
	// this is a officer
	if(COUNTRY_D->nation_exist(CHAR_D->get_char(c_id,"nation"))) return;
	if(CHAR_D->get_char(c_id,"type")==TYPE_PLAYER)
		return;
	if(CHAR_D->get_char(c_id,"is_tmp")) return;
        p_curarea=CHAR_D->get_char(c_id,"area");
        p_a=AREA_D->get_area(p_curarea,"neighbor");
        if(!sizeof(p_a))
                return;
        p_desarea=p_a[random(sizeof(p_a))];
	p_o=CHAR_D->find_char(c_id);
        if(objectp(p_o))
        {
                p_o->simple_action("$N叹了口气，道：看来此处非我发展之地。\n");
                p_o->simple_action("$N匆匆离开了。\n");
        }
	CHAR_D->set_char(c_id,"area",p_desarea);
	CHAR_D->appear(c_id,p_desarea);
        CHANNEL_D->deliver_tell("rumor","system",
                sprintf("%s投奔%s去了。",CHAR_D->get_char(c_id,"name"),
                        AREA_D->get_area(p_desarea,"name")));

}
