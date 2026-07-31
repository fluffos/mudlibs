// punlishd.c written by fund


#define DICTIONARY DATA_DIR + "punlish"

inherit F_SAVE;

mapping dict = ([]);

void add_translate( string,string,mixed );
void remove_translate(string);

void create()
{
	seteuid(geteuid());
	restore();
}

// void remove() { save(); }


string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun

void remove_translate( string id )
{
  map_delete( dict,id );
  save();

}

void add_translate( string id,string punlish_type, mixed power )
{
	mapping temp=([]);
	if(dict[id]) temp=dict[id];
	temp[punlish_type]=power;
	dict[id]=temp;

	save();
}

mapping query_translate()
{
  if( !undefinedp( dict )) return dict;
  else return ([]);
}

