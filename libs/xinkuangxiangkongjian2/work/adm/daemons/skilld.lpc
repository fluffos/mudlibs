// skill_d.c   written by fund


#define DICTIONARY DATA_DIR + "skill"

inherit F_SAVE;

mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
	seteuid(geteuid());
	restore();
}

// void remove() { save(); }


string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun

void remove_translate( string key )
{
  map_delete( dict, key );
  save();

}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save();
}

mapping query_translate()
{
  if( !undefinedp( dict )) return dict;
  else return ([]);
}

int query_skill(string skill)
{
  return !undefinedp(dict[skill]);
}
