do_fog_history() {
  int i;
  write("F.O.G. History: \n");
  for(i=0; i < sizeof(history); i++)
    write(history[i]+"\n");
  return 1;
}
