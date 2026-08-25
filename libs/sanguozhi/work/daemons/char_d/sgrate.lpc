// sgrate.c to calculate player's sgrate
int get_sgrate(string p_id) {
	int lit,natcon,ju,rep,xiyan,bas_skil,ext_skil;
	int ret;
	mapping skills;

	skills=CHAR_D->get_char(p_id,"skills");

	if(!mapp(skills)) skills=([]);
	bas_skil=skills["sk_wuli"]+skills["sk_meili"]+skills["sk_zhimou"];

	ext_skil=0;
	if(sizeof(skills)) {
		foreach(string s,int r in skills)
			ext_skil+=r;
	}

	ret+=bas_skil*20+ext_skil*10; // because the base part calculate twice so 
									// it is multi 20+10=30
	ret+=CHAR_D->get_char(p_id,"reputation")/100;
	ret+=CHAR_D->get_char(p_id,"literate")*2;
	ret+=CHAR_D->get_char(p_id,"ju")*1000;
	ret+=CHAR_D->get_char(p_id,"nationcontribution")/10;
	
	return ret;

}
