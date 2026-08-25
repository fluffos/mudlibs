// ev_addloyalty.c
// by fire on July 26, 1998
// the officer and the local char's loyalty 
// will increase yearly
private int times=0;
void addloy(string p_id) {
	string n_id,a_id;
	string a_ld;
	int n_lv,a_lv,loy;
	
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;
	n_id=CHAR_D->get_char(p_id,"nation");
	if(!COUNTRY_D->nation_exist(n_id)) return;
	if(n_id==p_id) return;
	a_id=CHAR_D->get_char(p_id,"area");
	a_ld=AREA_D->get_area(a_id,"leader");
	n_lv=CHAR_D->get_skill(n_id,"sk_meili");

	a_lv=CHAR_D->get_skill(a_ld,"sk_meili");
	n_lv=(a_lv+n_lv)/2;
	n_lv+=10;

	loy=CHAR_D->get_char(p_id,"loyalty");


	if(n_lv>loy) loy+=(random(6)-2);
	else loy-=(random(12)-2);
	loy=bmin(100,loy);
	loy=bmax(1,loy);
	CHAR_D->set_char(p_id,"loyalty",loy);
}
void addloy_all() {
	int i;
	times++;
	remove_call_out("addloy_all");
	if(times>10) return;
	call_out("addloy_all",5);
	for(i=0;i<20;++i)
		addloy(CHAR_D->pick_char());

}
void addloyalty()
{
	times=0;
	call_out("addloy_all",1);
}
