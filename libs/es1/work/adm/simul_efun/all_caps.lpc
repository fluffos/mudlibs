// File:		all_caps.c (simul_efun)
// Author:	Bub@Tabor
// Created:	??
// Purpose:	Turn a string to all caps.
//


string all_caps( string str )
{
	int i;
	string ret;

	if( !str || str == "" ) return "";
	ret = "";
	for( i = 0; i <strlen( str ); i++ )
		ret += capitalize( str[i..i] );
	return ret;
}

// This simul_efun caps each word in a string.	Inspiral@Tabor
string cap_words( string str )
{
	int loop, size;
	mixed *group;

	if( !str || str == "" ) return "";

	 group = explode( str, " " );

	str = "";
	size = sizeof( group );

	for( loop = 0; loop < size; loop++ ) { 
		str += capitalize( group[loop] );
		if( ( loop + 1 ) < size ) str +=" ";
	}
	return str;
}
