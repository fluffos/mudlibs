int t_s_num,t_n_num,t_o_num;
string dis_area(string a) {
	string ret="";
	string *rms;
	object o_rm,*obs;
	int m_num=0,o_num=0;
	
	ret+=sprintf("%-14s%-8s",a,AREA_D->get_area(a,"name"));
	rms=AREA(a)->get_room("list");
	foreach(string rm in rms) {
		o_rm=find_object("/a/"+a+"/"+rm);
		if(!objectp(o_rm)) continue;
		m_num++;
		obs=deep_inventory(o_rm);
		o_num+=sizeof(obs);
	}
	ret+=sprintf("%5d   %5d   %5d\n",sizeof(rms),m_num,o_num);
	t_s_num+=sizeof(rms);
	t_n_num+=m_num;
	t_o_num+=o_num;
	return ret;
	
}
string dis_all() {
	string *as;
	string dis="";
	t_s_num=0;
	t_n_num=0;
	t_o_num=0;
	dis+=sprintf("%-14s%-8s","地区ID","名称");
	dis+=sprintf("房间数，加载数，物品数。\n");
	as=AREA_D->list_areas();
	foreach(string a in as) {
		dis+=dis_area(a);
	}
	dis+=sprintf("%-22s","合计：");
	dis+=sprintf("%5d   %5d   %5d\n",t_s_num,t_n_num,t_o_num);
	return dis;
}