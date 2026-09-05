void reset(status arg) {
  int i;
  string str;
  mixed *obs;

  write(sizeof(call_out_info())+"\n");
  obs = call_out_info();
  i = sizeof(obs);

  while(i--)
    if (sizeof(obs[i]) && objectp(obs[i][0])) {
      str = catch(obs[i][0]->clean_up());
      if (str) write(str+"\n");
    }

  write(sizeof(call_out_info())+"\n");
/*
  destruct(this_object());
*/
}
