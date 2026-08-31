#ifndef __STRING_H__
#define __STRING_H__

string trim_spaces( string s ){
  int i, j;
  string *whitespace = ({" ","\t","\n","\r"});
  j = strlen(s) - 1;
  if ( j < 0 )
      return "";
  while( i <= j && member_array(s[i], whitespace) != -1 ) i++;
  while( i <= j && member_array(s[j], whitespace) != -1 ) j--;
  return s[i..j];
}

#endif
