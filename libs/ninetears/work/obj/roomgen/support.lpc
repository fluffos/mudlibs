
nosave string dir_path;
nosave string func;
 
 
void get_key(string str) {
  write("Press return to continue");
  func = str;
  input_to("get_key2");
}
 
void get_key2(string str) {
  call_other(this_object(), func);
}
 
void output(string str) {
  write(str);
}
 
void set_path(string str) {
  dir_path = str;
}

string get_dir_path() {
  return dir_path;
}
