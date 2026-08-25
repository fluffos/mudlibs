// soldiernumber.c
// this filed is inherited by area_d.c
// it will keep a record of the soldier numbers
// so if crash during the train, we know how many soldiers
// before the crash. hope so
int store_soldiers(string a_id) {
	mapping ssoldiers;
	mapping tmp=([]);
	mapping ttp=([]);
	ssoldiers=AREA_D->get_area(a_id,"ssoldiers");
	if(!mapp(ssoldiers))
		ssoldiers=([]);
	if(mapp(ssoldiers["new"])) {
		ssoldiers["old"]=ssoldiers["new"];
	}
	tmp["time"]=time();
	tmp["morale"]=AREA_D->get_area(a_id,"morale");
	tmp["train"]=AREA_D->get_area(a_id,"train");
	ttp=AREA_D->get_area(a_id,"troop");
	tmp["troop"]=([]);
	if(sizeof(ttp)) { // this way is safe to save a mapping :)
		foreach(string t,int v in ttp) 
			tmp["troop"][t]=v;
	}

	ssoldiers["new"]=tmp;
	AREA_D->set_area(a_id,"ssoldiers",ssoldiers);
	return 1;

}