//#pragma save_binary
#pragma save_types

//  File:    /std/body/wild_card.c
//  Creator: unknown; this "cool" file originated from Portals
//
//  This file is inherited by /std/body, and performs wild card
//  expansion of filenames.

varargs string *wild_card(string str, int keepdots)
{
	int i, limit;
	string work, *tmp, *pf;

	work = resolv_path((string)this_object()->query("cwd"), str);
	if( work == "/" ) return ({ "/" }); /* Special case! Yuck! */

	pf = path_file(work);
	if( pf[0] == "/" ) pf[0] = ""; /* yuck! yet another special case! */
	tmp = get_dir(work);
	if(!tmp) tmp = ({});
	tmp -= ({ "." });
	tmp -= ({ ".." });
	if( !keepdots && (!str || str[0] != '.') )
		tmp = filter_array(tmp, "remove_dots", this_object());

	for( i=0, limit=sizeof(tmp); i<limit; i++ ) {
		if( file_size(sprintf("%s/%s", pf[0], pf[1])) == -2 ) tmp[i] = pf[0];
		else tmp[i] = sprintf("%s/%s", pf[0], tmp[i]);
	}
	return tmp;
}

int remove_dots(string tmp)
{
	if( tmp[0] == '.' ) return 0;
	return 1;
}
