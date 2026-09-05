//cnamed.c
//Made by jason@indeed for vworld
//2001.3.16

inherit F_SAVE;
inherit F_DBASE;

mapping cname_list=([]);

int check_legal_name(string name)
{
	int i;

	i = strwidth(name);
	
	if( (strwidth(name) < 1) || (strwidth(name) > 7) ) return 0;
	
	while(i--) {
		if( name[i]<=' ' ) return 0;
		if( !is_chinese(name[i..<0]) )  return 0;
	}
	return 1;
}

string query_save_file()
{
	return "/data/cname_list";
}
void create()
{
	seteuid(getuid());
	if(!restore())
	{
		set("channel_id","中文名数据库");
	}
}

int add_cname(string cname,string id)
{
	if(!check_legal_name(cname)) return 0;
	if(!undefinedp(cname_list[cname])) return 0;
	cname_list[cname]=id;
	save();
	return 1;
}

int remove_cname(string id)
{
	string *key,*value;
	int i;
	if(!mapp(cname_list)||sizeof(cname_list)==0) return 0;
	key=keys(cname_list);
	value=values(cname_list);
	if((i=member_array(id,value))==-1) return 0;
	map_delete(cname_list,key[i]);	
	save();
	return 1;
}

int query_cname(string cname)
{
	if(undefinedp(cname_list[cname])) return 0;
        write(cname_list[cname]+"\n");
	return 1;
}

