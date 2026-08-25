// this will be used to handle all the area rooms
// by fire on July 17, 1999
object virtual_create(string c_id)
{
	object o_char;
	mixed c;
	string m_body;
    	c=CHAR_D->get_char(c_id,"");
	if(!mapp(c)) return 0;
    	m_body=CHAR_D->get_char(c_id,"body");
    	if(!stringp(m_body))
       		o_char=new(PMODULES+"m_charnpc");
    	else
       		o_char=new(PMODULES+"m_charnpc/"+m_body);

	if(CHAR_D->get_char(c_id,"no_extra"))
		return o_char; // so don't need extra initinal

	o_char->npc_char_set_name(c_id,c["name"],c["zi"]);
	o_char->set_gender(c["gender"]);
	o_char->set_age(c["age"]);

	if((!c["is_tmp"])||(c["is_robber"]))
   	{      
      		o_char->npc_char_set_gift(c["gift"],c["skills"]);
      		HP_D->set_max_hp(o_char);
   	}
   	else 
   	{
      		if(c["gift"]) CHAR_D->set_char(c_id,"gift",0);
      		if(c["skills"]) CHAR_D->set_char(c_id,"skills",0);
   	}
   	o_char->extra_init(); // this is after all the initiate
   	return o_char;
}
// Disappear if no longer needed
protected void clean_up() {
	return 0; // don't want it is destroyed
}

