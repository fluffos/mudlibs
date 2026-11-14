#ifndef NAME_MAKER_H
#define NAME_MAKER_H

string make_name(string str) {
  int i;
  string tmp;

  if(!str) str = "zilanthius";
  while(sscanf(str,"%s %s", str, tmp)) str += tmp;
  if(this_player()) str += (string)this_player()->query_name(1);
  str = crypt(str,0);
  str = lower_case(str);
  for(i = 0; i < strlen(str); i++) {
    if(str[i] < 'a' || str[i] > 'z') {
      str = str[0..(i-1)] + str[(i+1)..(strlen(str)-1)];
      i -= 1;
    }
  }
  if(strlen(str) > 4) str = str[0..3];
  return str;
}

#endif
