// banghuid.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping banghuis;
mapping menpais;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(banghuis) )
		banghuis= ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "banghuid"; }

int add_banghui(string name, mapping info)
{
	banghuis[name] = info;
	save();
	return 1;
}

int delete_banghui(string name)
{
	map_delete(banghuis, name);
	save();
	return 1;
}

string *query_names()
{
	return keys(banghuis);
}

mixed set_banghui(string prop, mixed data)
{
	if( !mapp(banghuis ) ) banghuis = ([]);

	if( strsrch(prop, '/')!=-1 )
	{
		_set( banghuis , explode(prop, "/"), data );
		save();
		return 1;
	}
	banghuis[prop] = data;
	save();
	return 1;
}

mixed query_banghui(string prop)
{
	mixed data;

	if( !mapp(banghuis) ) return 0;

	if( undefinedp(banghuis[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(banghuis, explode(prop, "/"));
	else
		data = banghuis[prop];

	return data;
}

int update_blv(string name)
{
	if(query_banghui(name))
	{
		set_banghui(name+"/level",to_int(pow(to_float(query_banghui(name+"/exp"))/10000,1.0/3.0))+1);
		if(query_banghui(name+"/level")>=6) set_banghui(name+"/level",6);
		save();
	}
	return 1;
}
