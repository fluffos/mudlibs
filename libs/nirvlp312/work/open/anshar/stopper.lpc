#define TO this_object()
#define ENV environment
 
id(str) { return str == "stopper"; }
 
get() { return 1; }
drop() { return 1; }
 
string meatname;
set_meatname(str) { meatname = str; }
query_meatname() { return meatname; }
 
init() {
  if( !ENV(TO) ||
      !living(ENV(TO)) ||
      !ENV(TO)->id() == "azelane" ) destruct(TO);
}
 
reset(arg) {
  if(!arg) call_out("chewing",5);
  return 1;
}
 
chewing() {
  object dude, chewer, root;
  if(ENV(TO) && living(ENV(TO))) dude = ENV(TO)->query_attack();
  if(meatname) chewer = find_player(meatname);
  if(!dude || !meatname) { dest_me(); return 1; }
  if(dude->query_real_name() != meatname) { dest_me(); return 1; }
  root = present("root", chewer);
  if(!root) { dest_me(); return 1; }
  call_out("chewing",5);
  return 1;
}
 
dest_me() {
  if(ENV(TO) && living(ENV(TO))) ENV(TO)->set_chance(40);
 destruct(this_object());
 return 1;
}
 
