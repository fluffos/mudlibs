/* command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

int print_nicknames(mapping map_nicknames);
int add_nickname(string str, mapping map_nicknames);

int print_single_nickname(string str) {
  mapping map_nicknames;

  map_nicknames = previous_object()->query_nicknames();
  if (!map_nicknames) {
    map_nicknames = ([ ]);
  }

  str = lower_case(str);
  if(!map_nicknames[str]) {
    add_failed_mess("That nickname does not exist.\n");
    return 0;
  }
  write("Setting for nickname "+str+" is "+map_nicknames[str]+".\n");
  return 1;
} /* print_single_nickname() */
 
int print_nicknames(int sorted) {
  int i;
  int cols;
  string str;
  string str_long;
  string str_middle;
  string str_small;
  string bit;
  string *tmp;
  mapping map_nicknames;
  
  map_nicknames = previous_object()->query_nicknames();
  bit = "";
  str_long = "";
  str_middle = "";
  str_small = "";
  if (!map_nicknames) {
    map_nicknames = ([ ]);
  }
  tmp = sort_array(keys(map_nicknames), 1);
  cols = (int)this_player()->query_cols();
  for (i=0;i<sizeof(tmp);i++) {
    str = tmp[i]+": "+map_nicknames[tmp[i]]+"  ";
    if (strlen(str) > 39 || sorted) {
      str_long += sprintf(tmp[i]+": %-=*s\n", cols - strlen(tmp[i]), map_nicknames[tmp[i]]);
    } else if (strlen(str) > 19) {
      str_middle += str+"\n";
    } else {
      str_small += str+"\n";
    }
  }
  if (strlen(str_middle)) {
    str_long += sprintf("%-#*s\n", cols, str_middle);
  }
  if (strlen(str_small)) {
    str_long += sprintf("%-#*s\n", cols, str_small);
  }
  this_player()->more_string(str_long, "Nicknames");
  return 1;
} /* print_nicknames() */
 
int add_nickname(string s1, string s2) {
  mapping map_nicknames;

  map_nicknames = previous_object()->query_nicknames();
  if (!map_nicknames) {
    map_nicknames = ([ ]);
  }
  if (!map_nicknames[s1]) {
    map_nicknames[s1] = s2;
    write("Added nickname "+s1+" as "+s2+".\n");
    return 1;
  }
  write("Changed nickname "+s1+" from "+map_nicknames[s1]+" to "+s2+".\n");
  map_nicknames[s1] = s2;

  this_player()->set_nicknames(map_nicknames);
  return 1;
} /* add_nickname() */

mixed* query_patterns() {
   return ({ "", (: print_nicknames(0) :),
             "sorted", (: print_nicknames(1) :),
             "<string'nickname'>", (: print_single_nickname($4[0]) :),
             "<string'nickname'> <string'realname'>", (: add_nickname($4[0], $4[1]) :)
           });
} /* query_patterns() */ 
