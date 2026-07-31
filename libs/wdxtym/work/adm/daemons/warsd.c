// warsd.c
//帮会、阵营、门派战争类活动数据

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping wdata;

void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(wdata) )
		wdata = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "warsd"; }

void clean_data(string key)
{
	if(!key)
		wdata = ([]);
	else
		wdata[key] = ([]);
	save();
}

mixed set_data(string prop, mixed data)
{
	if( !mapp(wdata ) ) wdata = ([]);

	if( strsrch(prop, '/')!=-1 )
	{
		_set( wdata , explode(prop, "/"), data );
		save();
		return 1;
	}
	wdata[prop] = data;
	save();
	return 1;
}

mixed query_data(string prop)
{
	mixed data;

	if( !mapp(wdata) ) return 0;

	if( undefinedp(wdata[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(wdata, explode(prop, "/"));
	else
		data = wdata[prop];

	return data;
}

