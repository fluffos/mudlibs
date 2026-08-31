inherit "obj/armour";
 
#define guild "guild/master"->query_number("jedi") 

reset(arg) {
::reset(arg);
if (arg) return;
  set_name("jedicloak");
  set_alias("cloak");
  set_short("A Jedi-cloak");
  set_long("This is your Jedi-cloak.\n");
  set_ac(1);
  set_value(0);
  set_weight(1);
  set_type("robe");
}
 
get() { 
  remove_call_out("fade_away");
  return 1; 
}

drop() {
  ::drop();
  call_out("fade_away",30);
  return 0;
}

wear(str) {
  if(!id(str)) return;
  if(this_player()->query_guild()!=guild) {
    write("A strong Force keeps you from wearing this cloak.\n");
    return 1;
  } 
  ::wear(str);
  if(!worn) return;
  write("You feel the Force take control of your mind and body.\n");
  say(this_player()->query_name()+" somehow looks more powerful.\n");
  return 1;
}

fade_away() {
  tell_room(environment(),"The cloak gets indistinct and fades away.\n");
  destruct(this_object());
}
