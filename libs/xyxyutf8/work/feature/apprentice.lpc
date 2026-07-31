// apprentice.c
#include <dbase.h>

int is_apprentice_of(object ob)
{
	mapping family;
	
	if( !mapp(family = query("family")) ) 
		return 0;
	if( family["master_id"] == (string)ob->query("id")
	 && family["master_name"] == (string)ob->query("name") 
	 && family["family_name"] == (string)ob->query("family/family_name") )
		return 1;
	return 0;	
}

int is_group_of(object ob)
{
	mapping group;
	if( !is_apprentice_of(ob) )
		return 0;
	if( !mapp(group = query("group")) ) 
		return 0;
	if( group["group_name"] == (string)ob->query("group/group_name") )
		return 1;
	return 0;	
}

varargs void assign_apprentice(string title, int privs)
{
	string t;
	mapping family,group;
	if( !mapp(family = query("family")) ) 
		return;
	if( title && stringp(title) && strlen(title)>2 )
		family["title"] = title;
	family["privs"] = privs;

	if( stringp(t = this_object()->query_temp_title()) )
	{
		if( stringp(t = TITLE_D->is_title(t)) )
			t = COLOR_D->replace_color(t,1);
		else	t = query("title");
	}
	if( userp(this_object()) || !t || !stringp(t) ) 
	{
		if( family["generation"]==1 )
			set("title", family["family_name"] + "开山祖师");
		else if( undefinedp(family["title"]) )
		{
			if( !mapp(group = query("group"))
			 || undefinedp(group["group_name"]) ) 
			{
				if( undefinedp(family["neimen"])
			 	 || family["neimen"]!=0 )
					set("title", sprintf("%s第%s代%s", family["family_name"],chinese_number(family["generation"]),"外门弟子"));
				else	set("title", sprintf("%s第%s代%s", family["family_name"],chinese_number(family["generation"]),"内门弟子"));	
			}
			else
			{
				if( undefinedp(group["title"]) )
					set("title", sprintf("%s%s弟子",family["family_name"],group["group_name"]));
				else	set("title", sprintf("%s%s%s",family["family_name"],group["group_name"],group["title"]));
			}	
		}
		else	set("title", sprintf("%s%s", family["family_name"],family["title"]));
	}
}

varargs void create_family(string family_name, int generation, string title)
{
	mapping family;
	if( !family_name || !generation )
		return;
	family = allocate_mapping(6);
	family["family_name"] = family_name;
	family["generation"] = generation;
	set("family", family);
	assign_apprentice( title, -1 );
}

varargs void create_family2(string family_name, string group_name,int generation, string title)
{
	mapping group;
	if( !family_name || !generation )
		return;
	if( !group_name )
	{
		create_family(family_name,generation,title);
		return;
	}
	group = allocate_mapping(6);
	group["group_name"] = group_name; 
	if( title && stringp(title) && strlen(title)>3 )
		group["title"] = title;
	set("group",group);
	create_family(family_name,generation);
}

int recruit_apprentice(object ob)
{
	mapping my_family, family,group,my_group;

	if( ob->is_apprentice_of( this_object() ) )	
		return 0;
	if( !mapp(my_family = query("family")) ) 
		return 0;
	family = allocate_mapping(sizeof(my_family));
	family["master_id"] = query("id");
	family["master_name"] = query("name");
	family["family_name"] = my_family["family_name"];
	family["generation"] = my_family["generation"] + 1;
	family["enter_time"] = time();
	ob->set("family", family);
	ob->assign_apprentice("弟子", 0);
	
	if( mapp(my_group=query("group")) )
	{
		if( ob->is_group_of(this_object()) )
			return 1;
		group = ([]);	
		group["group_name"] = my_group["group_name"];
		group["enter_time"] = time();	
		ob->set("group",group);
	}
	
	return 1;
}