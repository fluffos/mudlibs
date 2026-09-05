int do_bros() {
  object *members;
  int i,max;
  max=(int) MASTER->query_num_members();
  members=allocate(max);
  max=sizeof(members);
  members=(object *) MASTER->query_members();
  write(
LINE+
"Name                    Where\n"+
LINE
);
  for(i=0;i<max;i++) {
    write(pad((string)members[i]->query_name(),16));
    write("\t");
    if(!members[i]->query_invis())
      write(environment(members[i])->short());
    write("\n");
  }
  write(
LINE
  );
  return 1;
}
