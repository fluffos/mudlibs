/*
 * The great and wonderful alias driver by me ;)
 * pinkfish.
 */
mapping map_nicknames;
 
string *query_nicknames() { return keys(map_nicknames) + ({ }); }

void nickname_commands() {
  add_action("delete_nickname", "dnickname");
  add_action("nickname", "nickname");
  add_action("flushnicknames","flushnicknames");
}

int flushnicknames(string str)
{
  write("This will remove All your nicknames. Are you sure? (Y/N)\n");
input_to("flushnicks",0);
return 1;
}

int flushnicks(string str)
{
if(str=="Y"||str=="y")
  {
map_nicknames=0;
write ("Nicknames removed.\n");
}
else write("Some other time then\n");
return 1;
}
 
int add_nickname(string str) {
  string s1,s2;
 
  if (sscanf(str,"%s %s",s1,s2)!=2) {
    notify_fail("You are a frog\n");
    return 0;
  }
  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!map_nicknames[s1]) {
    map_nicknames[s1] = s2;
    write("Added nickname "+s1+" as "+s2+".\n");
    return 1;
  }
  write("Changed nickname "+s1+" from "+map_nicknames[s1]+" to "+s2+".\n");
  map_nicknames[s1] = s2;
  return 1;
}
 
string expand_nickname(string str) {
  string *arry;
  int i;
 
  if (stringp(str))
    arry = explode(lower_case(str)," ");
  else
    return str;
  if (!map_nicknames)
    map_nicknames = ([ ]);
  for (i=0;i<sizeof(arry);i++)
    if (map_nicknames[arry[i]])
      arry[i] = map_nicknames[arry[i]];
  return implode(arry," ");
}
 
int delete_nickname(string str) {
  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!map_nicknames[str]) {
    notify_fail("That nickname does not exist.\n");
    return 0;
  }
  map_nicknames = m_delete(map_nicknames, str);
  write("Deleted nickname : "+str+"\n");
  return 1;
}
 
int print_nicknames() {
  int i, cols;
  string str, str1, str2, bit, *tmp;
 
  bit = "";
  str1 = "";
  str2 = "";
  if (!map_nicknames)
    map_nicknames = ([ ]);
  tmp = m_indices(map_nicknames);
  cols = (int)this_player()->query_cols();
  for (i=0;i<sizeof(tmp);i++) {
    str = tmp[i]+": "+map_nicknames[tmp[i]]+"  ";
    if (strlen(str)>39)
      printf(tmp[i]+": %-=*s\n", cols - strlen(tmp[i]), map_nicknames[tmp[i]]);
    else if (strlen(str) > 19)
      str1 += str+"\n";
    else
      str2 += str+"\n";
  }
  if (strlen(str1))
    printf("%-#*s\n", cols, str1);
  if (strlen(str2))
    printf("%-#*s\n", cols, str2);
  return 1;
}
 
int nickname(string str) {
  string s1,s2;
 
  if (!map_nicknames)
    map_nicknames = ([ ]);
  if (!str || str == "")
    return print_nicknames();
 
  if (sscanf(str,"%s %s",s1,s2)!=2) {
    if (!map_nicknames[str]) {
      notify_fail("That nickname does not exist.\n");
      return 0;
    }
    write("Setting for nickname "+str+" is "+map_nicknames[str]+".\n");
    return 1;
  }
  return add_nickname(str);
}
