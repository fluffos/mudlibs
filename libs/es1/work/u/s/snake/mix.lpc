// This is the mix daemon which controls mixtures of herbs.
// Created by Annihilator 09/26/94

#include "healer.h"


mapping mixture;

int num;

void create()
{
	string *info, mix, result;
	int i, difficulty,number;

	seteuid(getuid());
	mixture = ([]);
	info = explode( read_file("/d/healer/mixture"), "\n" );
	for(i=0; i<sizeof(info); i++ ) {
		// Skip comments
		if( info[i][0]=='#' ) continue;
		if( sscanf(info[i], "[%d][%d]%s==%s", difficulty,number, mix, result)==4 ) {
			mixture[mix] = ({ result, difficulty,number });
		}
	}
}

string mix(object bowl)
{
	object *inv, ppl;
	int i, skill;
	string mix;

	inv = all_inventory(bowl);
	if( !sizeof(inv) ) return 0;
	if( !ppl = environment(bowl) ) return 0;
	skill = ppl->query_skill("medical");
	
	inv = sort_array(inv, "sort_herb", this_object());
	if ( inv[0]->query("ident") ) mix = inv[0]->query("ident");
	for(i=1; i<sizeof(inv); i++)
	  if ( inv[i]->query("ident") ) mix += "/" + inv[i]->query("ident");
	
	if( !undefinedp(mixture[mix]) ) {
		if( skill/2 + random(skill/2) < mixture[mix][1] ) {
			return 0;
		}
		num = mixture[mix][2];
		return (mixture[mix][0]);
	}
	return 0;
}

int potion_amount ()
{
  return num;
}  

int sort_herb(object herb1, object herb2)
{
        if ( herb1->query("ident") && herb2->query("ident") )
	return strcmp(herb1->query("ident"), herb2->query("ident"));
        return 0;
}
