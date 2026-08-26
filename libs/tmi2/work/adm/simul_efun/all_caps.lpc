// File:		all_caps.c (simul_efun)
// Author:	Bub@Tabor
// Created:	??
// Purpose:	Turn a string to all caps.
//


// Optimized all_caps by Beek
string all_caps( string str ) {
  if (!str) return "";
  return implode(map(explode(str, ""), (: capitalize :)), "");
}

/*
string all_caps( string str )
{
  int i;
  string ret;

  if( !str || str == "" ) return "";
  ret = "";
  for( i = 0; i <strlen( str ); i++ )
    ret += capitalize( extract( str, i, i ) );
  return ret;
}

 */
// This simul_efun caps each word in a string.  Inspiral@Tabor
string cap_words( string str ) {
  int loop, size;
  mixed *group;

  if( !str || str == "" ) return "";

   group = explode( str, " " );
  size = sizeof( group );

  for( loop = 0; loop < size; loop++ )  
	  group[loop] = capitalize( group[loop] );

  return implode( group, " " );
}
