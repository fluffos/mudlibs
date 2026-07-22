// guild_d.c written by fund


#define DICTIONARY DATA_DIR + "guild"

inherit F_SAVE;

mapping dict = ([]);

void add_translate( string guild, string key, string chinz );
void remove_translate( string guild, string key );

void create()
{
	seteuid(geteuid());
	restore();
}

// void remove() { save(); }


string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun

void remove_translate( string guild, string key )
{
  mapping temp=dict[guild];
  map_delete(temp,key);
  dict[guild]=temp;
  save();

}
void remove_class(string guild)
{
  map_delete( dict,guild );
  save();
}

void add_translate( string guild, string key, string chinz )
{
	mapping temp=([]);
	if(dict[guild]) temp=dict[guild];
	temp[key]=chinz;
	dict[guild]=temp;

	save();
}

mapping query_translate()
{
    if( mapp( dict )) return dict;
  else return ([]);
}

