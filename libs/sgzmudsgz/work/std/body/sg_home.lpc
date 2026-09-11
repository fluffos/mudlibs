// sanguo home
private mapping sg_home=([]);
mixed get_sg_home(string r_id,string para){
	if(r_id=="list") return keys(sg_home);
	if(r_id=="all") return sg_home;
	if(!sg_home[r_id]) return 0;
	if(!para||(para=="")) return sg_home[r_id];
	return sg_home[r_id][para];
}
mixed add_sg_home(string r_id) {
	if(mapp(sg_home[r_id])) return "room alread exit";
	sg_home[r_id]=([]);
}
mixed set_sg_home(string r_id,string para,mixed val) {
	if(!mapp(sg_home[r_id])) return "no such room";
	sg_home[r_id][para]=val;
	if(val==0)
		map_delete(sg_home[r_id],para);
	return sg_home[r_id];
}
mixed remove_sg_home(string r_id) {
	if(!mapp(sg_home[r_id])) return "no such room";
	map_delete(sg_home,r_id);
	return sg_home;
}
