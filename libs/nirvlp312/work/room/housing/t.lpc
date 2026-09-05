void reset(status arg) {
  int *nums;
  int i, siz, count;
  object *obs;
int count2;

  if (arg) return;
  obs = users();
  count = 0;
  i = sizeof(obs);
  while(i--) if (obs[i]->query_invis()) count++;
  write("First time through: "+count+"\n");
  obs = (object *)users()->query_invis();
  i = sizeof(obs);
  write(obs[i]+"\n");
}
