// this will be used to handle all the area rooms
// by fire on July 17, 1999
mixed virtual_create(string inp)
{
	string p_us,p_npc,*ags;
	object o_h;

	object o_char;
	mixed c;
	string m_body;


	ags=explode(inp,"/");
	if(sizeof(ags)!=2) return 0;
	p_us=ags[0]; // the player's id
	p_npc=ags[1]; // the npc's id

	o_h=SGHOME(p_us);
	if(!objectp(o_h)) return 0;

	c=o_h->get_npc(p_npc);
	if(!mapp(c)) return 0;

	if(!c["pos"])
		m_body="/sgdomain/home/npc/free";
	else
		m_body="/sgdomain/home/npc/"+c["pos"];

	o_char=new(m_body,p_us,p_npc);
   	return o_char;
}
// Disappear if no longer needed
protected void clean_up() {
	return 0; // don't want it is destroyed
}

