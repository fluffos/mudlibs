mixed cmd_where(int i) {
  object *all;
  all = users();
  write("\n** This is where people are!\n\n");
  for (i=0;i<sizeof(all);i++) {
    write(sprintf("%-15s %s\n",capitalize(all[i]->query_name(1)), file_name(environment(all[i])) ) );
  }
}
