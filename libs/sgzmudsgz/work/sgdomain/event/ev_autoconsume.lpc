// ev_auto consume is used to automacally consume the stuff
// for each area. now the consume rate is 1% each year
// this can provide the quantity of stuff grow too much
// by fire on March, 17, 2000

void area_consume(int a_index) {
	mapping st;
	int tmp;
	string p_id;
	p_id=AREA_D->list_areas_id(a_index);
	if(!stringp(p_id)) return;	
	a_index++;
	call_out("area_consume",3,a_index);

	st=AREA_D->get_area(p_id,"st");
	if(sizeof(st)) {

		foreach(string p in keys(st)) {
			tmp=st[p]["num"]/100;
			tmp=st[p]["num"]-tmp;
			st[p]["num"]=tmp;
		}
		AREA_D->set_area(p_id,"st",st);
	}
}
void auto_consume()
{
	area_consume(0);
}
