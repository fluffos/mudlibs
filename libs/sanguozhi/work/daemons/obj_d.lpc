/* obj_d.c by fire on 18/03/99
this is used to handle the direct control of objects
include npc and players
*/
#include <security.h>
#include <ansi.h>
#include <obj.h>
inherit M_ACCESS;
private mapping objs;
nosave private string *ks; // this is key
#define SAVE_FILE "/data/daemons/obj"
nosave private int m_modified;
nosave private mapping mks=([]); //the makers
void set_obj_modified(){  
	m_modified=1;
}
void save_data(){
	call_out("save_data",10);
    if(m_modified) {
       unguarded(1, (: save_object, SAVE_FILE :));
       m_modified=0;
    }
}
void create(){
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if(!objs) objs=([]);
	ks=keys(objs);
	remove_call_out("save_data");
	call_out("save_data",10);
    return;
}
// this is just suitable for add npc obj s manuly
string add_obj(string p_id,string p_type)
{
	string *list;
	mixed tmp;
//    if(!objs) objs=([]);

    if(!objs[p_id])
    {
		if((!p_type)||(p_type==""))
			return "must give type\n";
		list=filter_array(ks, (:(objs[$1]["type"]==$(p_type)) && (objs[$1]["is_master"]==1 ) :));
		if(!sizeof(list)){ // a master piece
			if(!adminp(this_user()))
				return "only admin can add new type";
			objs[p_id]=([]);
			if(objs["master"])
				objs[p_id]=objs["master"];
	        unguarded(1, (: save_object, SAVE_FILE :));

			unguarded(1, (: restore_object, SAVE_FILE, 1 :));
//			m_modified=1;

			objs[p_id]["is_master"]=1;
			objs[p_id]["type"]=p_type;

			ks=keys(objs);

			return "new master obj added \n";
		}
		tmp=objs[list[0]];
		objs[p_id]=tmp;
	    unguarded(1, (: save_object, SAVE_FILE :));

		unguarded(1, (: restore_object, SAVE_FILE, 1 :));

		map_delete(objs[p_id],"is_master");
//		m_modified=1;
		ks=keys(objs);
        return "new object added\n";
    }
    else
    {  return "this object exits already．\n";
    }
}

// this function should be just used in the early develop 
// time. later to use it may cause other conflict
string remove_obj(string p_id) 
{
	string *list;
	string p_type;
	if (!objs[p_id]) 
      return "no such objects\n";
    if(objs[p_id]["is_master"]){
		p_type=objs[p_id]["type"];
		list=filter_array(ks, (:(objs[$1]["type"]==$(p_type)):));
		if(sizeof(list)>1)
			return "this is a master record, you can't delete it until all item belong this type removed.\n";
		if(!adminp(this_user()))
			return "only admin can delete master object\n";
	}

   map_delete(objs, p_id);
   m_modified=1;
   ks=keys(objs);
   return "object record removed!\n";
}
string set_obj(string p_id,string para_name,mixed para_value)
{
        string p_ret;
        if(!objs[p_id])
                return "don't exits this obj record\n";
		if((para_name=="type")||(para_name=="is_master"))
			return "type and is_master can't be seted.\n";
        objs[p_id][para_name]=para_value;
        if(para_value==0)  // used to remove useless record
			map_delete(objs[p_id],para_name); //becare ful

	if (para_name=="new_id") {
		mixed tmp;
		if(!para_value) para_value="";
		if(para_value=="") return "must have a new id\n";
		if(mapp(objs[para_value])) 
			return "obj "+para_value+" exist already\n";
		
		tmp=objs[p_id];
		objs[para_value]=tmp;
		map_delete(objs,p_id);
	        unguarded(1, (: save_object, SAVE_FILE :));
		unguarded(1, (: restore_object, SAVE_FILE, 1 :));

	} 
        p_ret="parameter set ok.\n";
        m_modified=1;
        return p_ret;
}
mixed get_obj(string p_id,string para_name){
	if((!p_id)||(p_id=="")) return objs;
	if(p_id=="list") return ks;
    if (!objs[p_id])   return 0;
    if((!para_name)||(para_name=="")) return objs[p_id];
    return objs[p_id][para_name];      
}
string* check_obj(string para_name,mixed para_value) {
	string* ret;
    ret=filter_array(ks, (:objs[$1][$(para_name)]==$(para_value):));
    return ret;
}
string* check_obj_type(string para_name,mixed para_value,string p_type)
{
	string *ret;
    ret=filter_array(ks, (:(objs[$1][$(para_name)]==$(para_value))
       && (objs[$1]["type"]==$(p_type) ) :));
    return ret;
}
int obj_exist(string p_id)
{   if(objs[p_id])
         return 1;
    return 0;
}
mixed clone_obj(string p_id)
{
	object o;
	if(!objs[p_id]) return "we don't have this kind of object\n";
	if(!objs[p_id]["file_name"]) return "this object don't have object file\n";
	if(objs[p_id]["is_unique"]){
		object *obs;
		string unique_id=p_id+" obj";
		obs = objects( (: $1->id($(unique_id)) :));
		if(sizeof(obs)) return "this is a unique item and there exit one copy already.\n";
	}

	o=new(objs[p_id]["file_name"]);
	if(!objectp(o)) return "this object files is an illegual file\n";
	o->init_obj(p_id);
	return o;
}


string type_name(string s)
{
	switch(s)
	{
	case "food": return "食物";
	case "drink": return "饮品";
	case "weapon": return "武器";
	case "blade": return "刀类";
	case "ji": return "戟类";
	case "sword": return "剑类";
	case "hammer": return "锤类";
	case "spear": return "枪类";
	case "axe": return "斧类";
	case "cloth": return "衣服铠甲";


	case "armors": return "铠甲";
	case "brest": return "胸饰";
	case "torso": return "外衣";
	case "head": return "头盔";
	case "legs": return "下装";
	case "hands": return "手饰";
	case "arms": return "碗饰";
	case "feet": return "鞋";
	case "book": return "书简";
	case "horse": return "马匹";
	default : return "不详";
	}
}
mixed find_obj(string s)
{
	mixed ret;
	string p_id=s+" obj";
	ret=objects((:$1->id($(p_id)):));
	return ret;
}
mixed find_my_obj(string p_id,string s){
	mixed obs;
	mixed ob;
	object o;
	obs=find_obj(s);
	if(!sizeof(obs)) return 0;
	ob=filter_array(obs,(: $1->query_owner() == $(p_id) :));
	if(sizeof(ob)) return ob[0];
	o=CHAR_D->find_char(p_id);
	return present(s+" obj",o);
}
mixed get_obj_maker(string str) {
     string *makers,*ls,*ret;
     if(arrayp(mks[str])) return mks[str];
     makers=CHAR_D->check_char("is_maker",1);
     ret=({});
     foreach(string mk in makers){
         ls=CHAR_D->get_char(mk,"goods");
         if(!ls) ls=({});
         if(member_array(str,ls)!=-1) {
           ret+=({mk});
         }
     }
     mks[str]=ret;
     return ret;
}
int clean_up() {
   return 0; // means never_again
}
