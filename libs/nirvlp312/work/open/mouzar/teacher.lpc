id(str) {return str == "teacher";}
short() {return "Plastic Music Teacher";}
long() {write("Plastic Music Teacher\n"); return;}
get() {return 1;}
string note1, note2, note3;
init() {
  add_action("play","play");
}
play(str) {
  if(!str){
    write("Teacher says: What Note?\n");
    return 1;
  }
  if(!note1) {
  note1 = str;
  write("Note 1 done\n");
  return 1;
  }
  if(!note2) {
    note2 = str;
    write("Note 2 done\n");
    return 1;
  }
  return 1;
}
