object shad1;
int tsaga;
init() {
  if(this_player() == environment(this_object())) { 
    add_action("drink", "drink");
  }
}

query_value() { 
  if (tsaga == 21) { return 10; }
  return 380; 
}

query_weight() { return 10; }

drink(str) {
 if (tsaga == 21) {
 write("The potion is empty, and there is nothing left.\n");
 return 1;
 }
 if (str == "potion") {
  tsaga = random(7) + 1;
  if (tsaga == 1) {
  write("As you drink the potion a stinging pain enters your head.\n");
  say(call_other(this_player(), "query_name", 0) + " drinks a potion, which to seems to contains lethal components.\n");
  this_player()->reduce_hp(200);
  tsaga = 21; 
  return 1;
 }
   if (tsaga == 2) {
   write("You drink the potion and suddenly start feeling ill.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and starts seeming ill.\n"); 
   this_player()->reduce_hp(100);
   tsaga = 21;
   call_out("ill1", 25);
   return 1;
  }
   if (tsaga == 3) {
   write("You drink the potion but nothing seems to happen.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion\n");
   tsaga = 21;
   return 1;
  }
   if (tsaga == 4) {
   write("You drink the potion and feel slightly better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems to feel slightly better.\n");
   this_player()->add_hp(75);
   this_player()->add_sp(120);
   tsaga = 21;
   return 1;
  }
   if (tsaga == 5) {
   write("You drink the potion and feel much better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems much better.\n");
   this_player()->add_hp(120);
   this_player()->add_sp(200);
   tsaga = 21;
   call_out("hiilia", 25);
   return 1;
   }
   if (tsaga == 6) {
   write("You drink the potion and feel a bit weak.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems a bit weak.\n");
   this_player()->set_str(4);
   shad1 = clone_object("/wizards/nalle/potshad1.c");
   shad1->start(this_player());
   tsaga = 21;
   return 1;
   }
   if (tsaga == 7) {
   write("You drink the potion and feel a bit stupid.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems a bit stupid.\n");
   this_player()->set_int(4);
   tsaga = 21;
   call_out("normal", 45);
   return 1;
   }
  }
}

normal() {
   write("You feel like the potion's effect starts wearing off.\n");
   say(call_other(this_player(), "query_name", 0) + " looks more like normal again.\n");
   this_player()->update_stats();
   return 1;
}

hiilia() {
   write("The potion's effect makes you feel better.\n");
   say("The potion's effect makes " + call_other(this_player(), "query_name", 0) + " seem much better.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia2", 25);
   return 1;
}

hiilia2() {
   write("The potion's effect makes you feel better.\n");
   say("The potion's effect makes " + call_other(this_player(), "query_name", 0) + " seem much better.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia3", 25);
   return 1;
}

hiilia3() {
   write("The potion's effect makes you feel better.\n");
   say("The potion's effect makes " + call_other(this_player(), "query_name", 0) + " seem better.\n");
   this_player()->add_hp(45);
   this_player()->add_sp(50);
   call_out("hiilia4", 25);
   return 1;
}

hiilia4() {
   write("The potion's effect makes you feel a bit better.\n");
   say("The potion's effect makes " + call_other(this_player(), "query_name", 0) + " seem a bit better.\n");
   this_player()->add_hp(30);
   this_player()->add_sp(45);
   return 1;
}

ill1() {
  write("You feel like your insides are on fire!\n");
  say(call_other(this_player(), "query_name", 0) + " moans in pain!\n");
  this_player()->reduce_hp(100);
  call_out("ill2", 25);
  return 1;
}

ill2() {
  write("You find it hard to breathe!\n");
  say(call_other(this_player(), "query_name", 0) + " coughs blood!\n");
  this_player()->reduce_hp(75);
  call_out("nomoreill", 25);
  return 1;
}

nomoreill() {
  write("After one final spasm you feel like the poison is dissolving.\n");
  say(call_other(this_player(), "query_name", 0) + " roars one more time and then seems slightly better.\n");
  this_player()->reduce_hp(50);
  return 1;
}


short() { 
if (tsaga != 21) {
   return "A multicoloured potion";
   } else {
   return "An empty potion";
 }                
}

long(str) {
 if (tsaga == 21) {
  write("An empty potion.\n");
  return 1;
  } 
  write("A potion, containing a multicoloured fluid.\n");
}


get() { return 1; }

id(str) {
    return str == "potion";
}



