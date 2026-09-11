/* base_d.c by fire on 30/01/00
** modified by suicide on 12/03/01
** This is used to handle the base (factory, farm and so on)
*/
#include <security.h>
#define SAVE_FILE "/data/daemons/base"

inherit M_ACCESS;
inherit __DIR__+"base_d/stat_me";
private mapping bases;
private mapping stuffs;
private mapping price=([]);
void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}
/*
void init_stuff() {
	stuffs=(EV_MERCHANT)->query_goods("");
	save_data();
}
*/
string add_stuff(string p_id)
{   
    	if( !stuffs[p_id] ){   
		stuffs[p_id] = ([]);
        	save_data();
        	return "new stuff type added\n";
    	} else return "stuff already exist\n";
}
string remove_stuff(string p_id) 
{  
	if ( !stuffs[p_id] ) return "no such stuff\n";
   	map_delete(stuffs, p_id);
   	save_data();
   	return "stuff removed\n";
}
string set_stuff(string p_id,string para_name,mixed para_value)
{   
    	string p_ret;

    	if( !stuffs[p_id] ) return "no such stuff\n";
    	if( intp(para_value)&&(para_value<0) ) para_value=0;

//    	switch (para_name){
//    		default:
   		if(para_value==0) map_delete(stuffs[p_id],para_name);
   		else stuffs[p_id][para_name]=para_value;
//      	 		break;
//    	}

    	save_data();
    	return "parameter setted\n";
}
mixed get_stuff(string p_id,string para_name)
{
   	if( p_id=="list" ) return keys(stuffs);
   	if( (!p_id)||(p_id=="") ) return stuffs; 
   	if( !stuffs[p_id] ) return 0;
   	if( (!para_name)||(para_name=="") ) return stuffs[p_id];

   	switch(para_name) {
		case "all" : return stuffs[p_id];
     		default:
           		return stuffs[p_id][para_name];
    	}
}
int stuff_exist(string f_id) {
	if(!mapp(stuffs[f_id])) return 0;
	return 1;
}

int get_stf_real_work(string stf,int val) {
	int work,qty,real_work;
	
	if(!mapp(stuffs[stf])) return 0;
	qty=stuffs[stf]["quantity"];
	work=stuffs[stf]["work"];
	if(qty==0) return 0;
	real_work=(val*work)/qty;
	if(!mapp(stuffs[stf]["consume"]))
		return real_work;
	foreach(string s,int v in stuffs[stf]["consume"]) {
		real_work+=get_stf_real_work(s,val*v/qty);
	}
	return real_work;
}


void init_real_work() {
	string *list;
	list=keys(stuffs);
	foreach(string l in list) {
		stuffs[l]["real_work"]=get_stf_real_work(l,stuffs[l]["quantity"]);
	}
	return;
}

void init_stf_base() {
	string *list,stf;
	list=keys(stuffs);
	foreach(string l in list) {
		stuffs[l]["base"]=([]);
	}
	list=keys(bases);
	foreach(string bl in list) {
		stf=bases[bl]["defproduct"];
		if(mapp(stuffs[stf]))
			stuffs[stf]["base"][bl]=1;
		if(mapp(bases[bl]["products"])) {
			foreach(string p,int l in bases[bl]["products"])
				stuffs[p]["base"][bl]=l;
		}
	}
	return;
}

void init_src_stuff() { // src is the inverse of consume
	string *list,stf;
	list=keys(stuffs);
	foreach(string l in list) {
		stuffs[l]["src"]=({});
	}

	foreach(string l in list) {
		if((mapp(stuffs[l]["consume"]))&&(sizeof(stuffs[l]["consume"]))) {
			foreach(string cl in keys(stuffs[l]["consume"])) {
				stuffs[cl]["src"]+=({l});
			}
		}
	}
	return;

}

// following base ---------------------------------------------
void create()
{
   	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	call_out("init_src_stuff",1);
	call_out("init_real_work",2);
	call_out("init_stf_base",3);
   	return;
}
string add_base(string p_id)
{   
    	if( !sizeof(bases) ) bases=([]);
    	if( !bases[p_id] ){   
		bases[p_id] = ([]);
        	save_data();
        	return "new base type added\n";
    	} else return "base already exist\n";
}
string remove_base(string p_id) 
{  
	if ( !bases[p_id] ) return "no such base\n";
   	map_delete(bases, p_id);
   	save_data();
   	return "base removed\n";
}
string add_base_area(string p_id, string p_area) 
{
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ({});
    	if( !AREA_D->area_exist(p_area) ) return "no such area exits\n";
	if( member_array(p_area,bases[p_id]["area"])!=-1 ) return "base already exits in that area\n";
    	bases[p_id]["area"]+=({p_area});
	save_data();
    	return "OK, added\n";
}
string sub_base_area(string p_id,string p_area) 
{
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ({});
	bases[p_id]["area"]-=({p_area});
	save_data();
    	return "OK, deleted\n";
}
string set_base(string p_id,string para_name,mixed para_value)
{   
    	string p_ret;

    	if( !bases[p_id] ) return "no such base\n";
    	if( intp(para_value)&&(para_value<0) ) para_value=0;

    	switch (para_name){
    		case "add_area":
         		add_base_area(p_id,para_value);
         		break;
   	 	case "sub_area":
         		sub_base_area(p_id,para_value);
         		break;
    		default:
           		if(para_value==0) map_delete(bases[p_id],para_name);
           		else bases[p_id][para_name]=para_value;
      	 		break;
    	}

    	save_data();
    	return "parameter setted\n";
}
mixed get_base(string p_id,string para_name)
{
   	if( p_id=="list" ) return keys(bases);
   	if( (!p_id)||(p_id=="") ) return bases; 
   	if( !bases[p_id] ) return "no such type of base\n";
   	if( (!para_name)||(para_name=="") ) return bases[p_id];

   	switch(para_name) {
		case "all" : return bases[p_id];
     		default:
           		return bases[p_id][para_name];
    	}
}
int base_exist(string f_id) {
	if(!mapp(bases[f_id])) return 0;
	return 1;
}
// some base can only build in certain areas
int can_build_in_this_area(string f_id,string area) {
	string *areas;
	areas=get_base(f_id,"area");
	if(!sizeof(areas)) return 1;
	if(member_array(area,areas)!=-1) return 1;
	return 0;
}
mixed can_build(string p_area,string f_id) {
	int lev,bslev=0;
	string nam,*rs;
	string *bases;
	object bs;
	bs=SGBASE(p_area,f_id);
	if(objectp(bs)) {
		bslev=bs->get_level();
	}
	if(bslev==4) return "基地已经不能再升级了。\n";
	lev=AREA_D->get_area(p_area,"level");
	if(lev==1) return "关口不能建设生产基地。";
	if(!base_exist(f_id)) 
		return "没有"+f_id+"这类生产基地。";
	nam=get_base(f_id,"name");
	if(!can_build_in_this_area(f_id,p_area))
		return "本地区不适宜建设"+nam+"这类生产基地。";
	if(AREA_D->get_area(p_area,"safe")<
		(get_base(f_id,"safe")+bslev*20))
		return "本地区安定不够。";
	if(AREA_D->get_area(p_area,"population")<
		get_base(f_id,"pop")*(bslev+1))
		return "本地区人口不够。";

	if(AREA_D->get_area(p_area,"gold")<
		get_base(f_id,"gold"))
		return "本地区金不够。";
	bases=AREA_D->get_area(p_area,"base");
	if(bslev==0) return 1;
	if((bs->get_room("size")-1)<bslev*2)
		return "本地区"+nam+"还可以再增加新的"+get_base(f_id,"roomname")+
			"，所以不能升级。";
	rs=bs->get_room("list");
	foreach(string r in rs) {
		if(bs->can_have_more_ppl(r)==1)
			return "本地区"+nam+"有些"+get_base(f_id,"roomname")+
			"的"+get_base(f_id,"workername")+"还没满员，不能升级。";
	}
		return 2; // update
}

// this function check if one base can produce one stuff or not
// the return value is the level required to prduce this stuff
// 1 means the default product. bigger means the minimum level
// required to produce this stuff. 0 means this base can't produce
// this product.
int get_product_level(string bs,string stf) {
	if(!base_exist(bs)) return 0;
	if(!stuff_exist(stf)) return 0;
	if(stf==bases[bs]["defproduct"])
		return 1;
	if(!mapp(bases[bs]["products"])) return 0;
	return bases[bs]["products"][stf];
}

mixed cal_avg_price(string st,int num,int cost)
{int total;
if (!price[st]) price[st]=([]);
total = price[st]["sum"]*price[st]["price"]+price[st]["left"]+cost;
price[st]["price"] = total/(price[st]["sum"]+num);
price[st]["left"]  = total%(price[st]["sum"]+num);
price[st]["sum"] += num;
save_data();
return price[st];                     
}

mixed get_avg_price(string st,string para)
{
if (!price[st]) return 0;
if (!para||para=="") return price[st]["price"];
if (para=="all") return price[st];
return price[st][para];
}