/*
 * The standard language unit.
 */

string long() {
  return 
"This is a language that makes no sense.\n";
}

#define DICT "/w/chrisy/lang/words.txt"
#define WNUM 5029

string last_string, last_garbled;

string garble(string str)
{
  string s1, s2;
  int i, j;

  seteuid(getuid());

  if(!last_string || !stringp(last_string))
  {
    last_string = "";
    last_garbled = "";
  }
  if(last_string == str) return last_garbled;


  i = sizeof(explode(str, " "));
  s1 = "";

  while(i)
  {
    j = random(WNUM);
    s2 = read_file(DICT, j, j);
    s1 += explode(s2, "\n")[0];
    i--;
    if(i) s1 += " ";
  }

  last_string = str;
  last_garbled = s1;
  return s1;
}

mixed garble_tell(string start, string mess) {
  mess = garble(mess);
  return ({ start, mess });
}

mixed garble_shout(string start, string mess) {
  mess = garble(mess);
  return ({ start, mess });
}

mixed garble_say(string start, string mess) {
  mess = garble(mess);
  return ({ start, mess });
}
