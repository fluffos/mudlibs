/* ev_informsb.c
   by fire on Aug,27,1998
   this is used to inform player char some information */
void inform_sb(string p_id,string p_mess)
{
	string p_soldier;
	string p_room;
       object env;
	object o_id,o_soldier;
	o_id=CHAR_D->find_char(p_id);
	if(!objectp(o_id))
		return;
       env=o_id->query_room();
       if(!objectp(env)) {SGSYS(p_id + "has no room ?"); return ;}
        p_room=file_name(env);
        p_soldier=p_id+" bing";
        CHAR_D->add_char(p_soldier);
        CHAR_D->set_char(p_soldier,"name","传令兵");
	CHAR_D->set_char(p_soldier,"is_tmp",1);
        CHAR_D->put_char(p_soldier,p_room);
        o_soldier=CHAR_D->find_char(p_soldier);
        if(objectp(o_soldier))
                o_soldier->simple_action("$N闪身进入。\n");
	if(p_mess[<1]!='\n')
		p_mess+="\n";
        if(objectp(o_id)&&objectp(o_soldier))
                o_soldier->targetted_action("$N对$T道："+p_mess,o_id);
        if(objectp(o_soldier))
        {
                o_soldier->simple_action("$N转身退出了。\n");
        }
        CHAR_D->remove_npc_char(p_soldier);
        CHAR_D->remove_char(p_soldier);
	return;
}
