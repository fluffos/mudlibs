/* stuff_d.c by fire on 19/06/99
** This is used to handle the base (factory, farm and so on)
*/
#include <mudlib.h>
#include <security.h>
#define SAVE_FILE "/data/daemons/stuffs"

inherit M_ACCESS;

private mapping bases;

/* Data structure
**	bases = ([ "farm" : 
**			([ "area":(["changan":1, "luoyang":2]),
**			   "level1":(["safe":100,"gold":1000,]),
**			   "pro1":(["food":100]);
**			   "con1":(["gold":30]);
**			   "level2":(["safe":200,"gold":10000,]),
**			])
**		])	
*/

void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{
   	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
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
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ([]);
    	if( !AREA_D->area_exist(p_area) ) return "no such area exits\n";
	if( member_array(p_area,keys(bases[p_id]["area"]))!=-1 ) return "base already exits\n";
    	bases[p_id]["area"][p_area] = 1;
	CHANNEL_D->deliver_tell("rumor","system",AREA_D->get_area(p_area,"name")+"发现了新的"+bases[p_id]["name"]+"。");
	save_data();
    	return "OK, added\n";
}
string sub_base_area(string p_id,string p_area) 
{
    	if( !sizeof(bases[p_id]["area"]) ) bases[p_id]["area"] = ([]);
	if( member_array(p_area,keys(bases[p_id]["area"]))==-1 ) return "no such area\n";
    	map_delete(bases[p_id]["area"], p_area);
    	if( !sizeof(bases[p_id]["area"]) ) map_delete(bases[p_id],"area");
	CHANNEL_D->deliver_tell("rumor","system","因为经营不善，"+AREA_D->get_area(p_area,"name")+"的"+bases[p_id]["name"]+"废弃了。");
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

   	return bases[p_id][para_name];
}
string stat_me_base(string p_id)
{
   	string p_ret="";
   	mixed c;
   	mixed * ks;
   	int i;

   	if( (!p_id)||(p_id=="") ) p_id="list";
   	if(p_id=="list") {
      		p_ret= "生产基地清单：\n";
      		p_ret+="─────────────────────────────────────\n";
      		c=keys(bases);
      		ks=({});
      		for(i=0;i<sizeof(c);++i) ks+=({bases[c[i]]["name"]+"("+c[i]+")"});
      		p_ret+=sprintf("%-#79s\n", implode(ks, "\n"));
   	} else {
       		if( !mapp(bases[p_id]) ){
          		p_ret="没有这种生产基地。\n";
       		} else {
          		p_ret="基地ID："+p_id+"   基地名称："+bases[p_id]["name"]+"\n";
			p_ret+="建造条件：城市安定度："+bases[p_id]["level1"]["safe"]+"    黄金："+bases[p_id]["level1"]["gold"]+"    粮食："+bases[p_id]["level1"]["food"]+"\n";
			p_ret+="可生产物资："+bases[p_id]["c_name"]+"\n";
			p_ret+="每月消耗：黄金："+bases[p_id]["level1"]["gold"]+"    粮食："+bases[p_id]["level1"]["food"]+"\n";

			p_ret+="升二级条件：：城市安定度："+bases[p_id]["level2"]["safe"]+"    黄金："+bases[p_id]["level2"]["gold"]+"    粮食："+bases[p_id]["level2"]["food"]+"\n";
			p_ret+="可生产物资："+bases[p_id]["c_name"]+"\n";
			p_ret+="每月消耗：黄金："+bases[p_id]["level2"]["gold"]+"    粮食："+bases[p_id]["level2"]["food"]+"\n";

			p_ret+="升三级条件：：城市安定度："+bases[p_id]["level3"]["safe"]+"    黄金："+bases[p_id]["level3"]["gold"]+"    粮食："+bases[p_id]["level3"]["food"]+"\n";
			p_ret+="可生产物资："+bases[p_id]["c_name"]+"\n";
			p_ret+="每月消耗：黄金："+bases[p_id]["level3"]["gold"]+"    粮食："+bases[p_id]["level3"]["food"]+"\n";
       		}
   	}
   	
	return p_ret;
}
