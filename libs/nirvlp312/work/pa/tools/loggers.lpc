string *nms;

void reset(int arg) {
  if(arg) return;
  tell_object(find_player("vertebraker"), "reset\n");
  nms=({});
  call_out("restore_data", 1);
  call_out("autosave", 1800 + random(1800));
}

void restore_data()
{
  tell_object(find_player("vertebraker"), "loading textfile\n");
  tell_object(find_player("vertebraker"), "file_size: "+file_size("/pa/log/Data.txt"));
  nms = explode(read_file("/pa/log/Data.txt"), "\n");
  tell_object(find_player("vertebraker"), "sizeof nms: "+sizeof(nms)+"\n");
}

void save_me() {
  int s;
  rm("/pa/log/Data.txt");
  s=sizeof(nms);
  while(s--)
  write_file("/pa/log/Data.txt", nms[s]+"\n");
}

void add_name(string nm){
  if(!nms) nms=({});
  if(member_array(nm,nms) == -1) {
    nms += ({nm});
  }
}

void delete_name(string nm){
  if(!nms) nms=({});
  if(member_array(nm,nms) > -1) {
    nms -= ({nm});
  }
}

string * query_names() {
  return nms;
}

status query_name(string nm) {
  if(!nms) nms=({});
  return member_array(nm,nms) > -1;
}

int query_prevent_shadow() { return 1; 
}

void autosave() {
  save_me();
  call_out("autosave", 1800 + random(1800));
}
