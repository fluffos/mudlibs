inherit INDOOR_ROOM;
inherit __DIR__+"base";
string get_long();
void base_init() {
    object o_h=get_master();
	object o_head;
	mapping m_head;
    set_brief(AREA_D->get_area(p_area,"name")+BASE_D->get_base(f_id,"roomname"));
    set_long(get_long());
    set_area(p_area);

	m_head=o_h->get_room(r_id,"head");
	if(mapp(m_head)) {
		o_head=new(PBASE+"npc/head",p_area,f_id,r_id);
		if(objectp(o_head))
			o_head->move(this_object());
	}
}
string get_long() {
        object oh;
        int sz;
        oh=get_master();

		return "I really need some funcy desc here\n";
}

