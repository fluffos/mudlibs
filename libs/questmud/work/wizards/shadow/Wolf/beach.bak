inherit "room/room";
int vene;


object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/shadow/Wolf/monsters/fisherman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","out: 73 57");
  short_desc = "A rocky beach by the sea";
  long_desc =
"You have arrived to a rocky beach, at a beautiful location by\n" +
"the sea. A brisk ocean breeze tempts you to fill your lungs with\n" +
"this salt-scented air. Besides an old rowing boat that rests on the\n" +
"outer extremity of the beach, there is nothing but seashells,\n" +
"and seaweed anywhere to be seen on this beach.\n";
}

init() {
    ::init();
   add_action("enter", "enter");
   add_action("look", "look");
   if (vene == 1) {
  long_desc =
 "You have arrived to a rocky beach, at a beautiful location by\n" +
 "the sea. A brisk ocean breeze tempts you to fill your lungs with\n" +
 "this salt-scented air. You examine the beach for any objects\n" +
 "that could be of use but, there are nothing but seashells,\n" +
 "and seaweed anywhere to be seen on this beach.\n";
 }
}

look(str) {
  if((str) == "at boat") {
  if (vene == 1) {
  write("You see nothing special.\n");
  return 1;
  }
  write("A nice little rowing-boat.\n");
  return 1;
  }
}

enter(str) {
  if ((str) == "boat") {
  if (vene == 1) {
  write("The boat is not here at the moment.\n");
  return 1;
  }
  vene = 1;
  long_desc =
  "You have arrived to a rocky beach, at a beautiful location by\n" +
  "the sea. A brisk ocean breeze tempts you to fill your lungs with\n" +
  "this salt-scented air. You examine the beach for any objects\n" +
  "that could be of use but, there are nothing but seashells,\n" +
  "and seaweed anywhere to be seen on this beach.\n";  
  say(this_player()->query_name()+" enters the boat and takes off.\n");
  write("You walk to the rowing-boat and promptly jump on board.\n");
  move_object(this_player(),"/wizards/shadow/Wolf/boat2.c");
  say(this_player()->query_name()+" enters the boat.\n");
  write("You push the boat off the rocks.\n");
  say(this_player()->query_name()+" pushes the boat off the rocks.\n");
  call_out("current1", 10);
  return 1; 
  }
 }
current1() {
  write("The currents carry the boat along.\n");
  call_out("current2", 10);
  return 1;
 }
current2() {
  write("The boat starts moving amazingly rapidly.\n");
  call_out("current3", 10);
  return 1;
 }
current3() {
  write("As you spot dry land, the boat slows down.\n");
  call_out("land", 10);
  return 1; 
 }
land() {
  vene = 0;
  long_desc =
  "You have arrived to a rocky beach, at a beautiful location by\n" +
  "the sea. A brisk ocean breeze tempts you to fill your lungs with\n" +
  "this salt-scented air. Besides an old rowing boat that rests on the\n" +
  "outer extremity of the beach, there is nothing but seashells,\n" +
  "and seaweed anywhere to be seen on this beach.\n";
  write("The boat reaches an icy harbor, and you quickly jump off.\n");
  move_object(this_player(),"/wizards/shadow/Wolf/wolfent.c");
  tell_room("wizards/shadow/Wolf/beach","The boat returns, as if it was enchanted.\n");
  say(this_player()->query_name()+" arrives on a small rowing-boat.\n");    
  return 1; 
}
