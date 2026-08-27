//#pragma save_binary
#pragma save_types

// alias.c
// storage and retrieval of aliases
// Author: Wayfarer (Some of my code may still exist here. :))
// Zak found a couple of bugs which were screwing up global aliases for
// people who didn't have any personal ones set. Mobydick installed his
// patches on 2-26-93
// Inspiral reported a bug with xverbs.  Guile fixed this but on 7-20-93
// and removed a few unnecessary if() statements while at it.

#include <uid.h>
#include <alias.h>

 mapping alias;
 mapping xverb;

void add_alias(string verb, string cmd);

int init_aliases()
{
	if( !alias ) alias = allocate_mapping(10);
	if( !xverb ) xverb = allocate_mapping(10);
	return 1;
}

mapping query_nalias()
{
	if( !alias ) init_aliases();
	return alias;
}

mapping query_xalias()
{
	if( !xverb ) init_aliases();
	return xverb;
}

mapping query_aliases()
{ 
	if( !alias || !xverb ) init_aliases();
	return ( alias + xverb ); 
}

string query_alias(string str)
{
	string ret;

	if( !alias ) init_aliases();
	ret = alias[str];
	if( !ret ) {
		if( !xverb ) init_aliases();
		ret = xverb[str];
	}
	return ret;
}

// this should have been here so buddha added it.
void clear_aliases()
{ 
	if( geteuid(previous_object()) != ROOT_UID &&
		file_name(previous_object()) != ALIAS_CMD ) return;
	init_aliases();
}

void add_alias(string verb, string cmd)
{
	if( geteuid(previous_object()) != ROOT_UID &&
		file_name(previous_object()) != ALIAS_CMD ) return;
	if( verb[0] == '$' && strlen(verb) > 1 ) {
		if( !xverb ) init_aliases();
		verb = verb[1 .. (strlen(verb)-1)];
		xverb[verb] = cmd;
	} else alias[verb] = cmd;
}

void remove_alias(string verb)
{
	if( alias[verb] ) map_delete(alias, verb);
	else if( xverb[verb] ) map_delete(xverb, verb);
}

string replace_words(string orig, string *words)
{
	string ret, tmp, *parts;
	int i, num, max;

	parts = explode(orig+"$", "$");
	ret = orig;
	for( i=0, max=sizeof(parts); i<max; i++ ) {
		if( parts[i][0] == '*' )
			ret = replace_string(orig, "$*", implode(words," "));
		else {
			if( sscanf(parts[i], "%d%*s", num) == 0 )
				if( sscanf(parts[i], "%d", num) == 0 ) continue;
			if( num > 0 && num <= sizeof(words) ) {
				tmp = sprintf("$%d", num);
				ret = replace_string(ret, tmp, words[num-1]);
			}
		}
	}
	return ret;
}

string do_xverb(string str)
{
	string *xv, ret, tmp, *words;
	int i, lenxv, max;
	mapping tmpxv;

	if( !xverb ) init_aliases();
 	tmpxv = (mapping)GA_SERVER->query_global_xaliases() + xverb;
	xv = keys(tmpxv);
	for( i=0, max = sizeof(xv); i<max; i++ ) {
		lenxv = strlen(xv[i]);
		if( str[0..(lenxv-1)] == xv[i] ) {
			if( strlen(str) > lenxv ) str = str[lenxv..strlen(str)-1];
			else str = "";
			words = explode(sprintf("%s ", str), " ");
			ret = replace_words(tmpxv[xv[i]],words);
			return ret;
		}
	}
	return 0;
}

string do_alias(string str)
{
	string *words, tmp, ret;

	if( !str || str == "" ) return "";
	tmp = do_xverb(str);
	if( tmp ) return tmp;
	if( !alias ) init_aliases();
	tmp = str;
	words = explode(str+" ", " ");
	if( !words || !sizeof(words) ) words = ({ tmp });
	if( !(tmp = alias[words[0]]) )
		tmp = (mixed)GA_SERVER->do_global_alias(words[0]);
	if( tmp ) {
		ret = replace_words(tmp, words[1..(sizeof(words)+1)]);
		return ret;
	}
	return implode(words, " ");
}
