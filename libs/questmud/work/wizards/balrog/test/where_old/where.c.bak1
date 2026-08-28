mixed cmd_where() {
  string *whoa;
  object *all;
  string tmp;
  mapping who;
  int i;
  int x;

  who = ([ "Players": "Location" ]);
  all = users();

  write("\nPlayers\t\tLocation\n\n");
  for (i=0;i<sizeof(all);i++) {
    who += ([ capitalize(all[i]->query_name(1)): file_name(environment(all[i])) ]);
  }
  for (i=0;i<sizeof(who);i++) {
    whoa = m_indices(who);
      tmp = who[whoa[i]];
    x = i+1;
    write(sprintf("%-15s %s\n",whoa[i], who[whoa[i]]) );
    while(x<sizeof(who)) {
      if (tmp == who[whoa[x]]) {
        write(sprintf("%-15s %s\n",whoa[x], who[whoa[x]]) );
        m_delete(who, whoa[x]);
        --x;
      }
      ++x;
    }
  }
}

