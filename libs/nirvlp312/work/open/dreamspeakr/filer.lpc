id(str) { return str == "reporter"; }

drop() { return 1;}

long() { write("Usage: file <string>\n"); }

init() {
if(this_player()->query_real_name() != "dreamspeakr") destruct(this_object());
add_action("filer","file");
}

filer(str) {
  if(!str) return 0;
write_file("/players/dreamspeakr/WORKREPORT",ctime(time())+" "+str+"\n");
log_file("DREAMSPEAKR_WORKREPORT",ctime(time())+" "+str+"\n");
write("report done.\n");
return 1;}
