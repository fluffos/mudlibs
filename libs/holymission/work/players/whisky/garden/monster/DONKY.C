#define PNAME this_player()->query_name()
#define MAX_RIDE 3
inherit "obj/monster";
object sw,hunt,rucksack;
string hunt_name,say_string,chat_str;
int num_riding;
reset(arg) {
::reset(arg);
chat_str=({ "IAAAAAAAAAH\n"});
if(arg) return;
set_name("A cute little donkey");set_alias("donkey");
set_short("A cute donkey"); set_long("He is friendly looking at you, try a ride\n");
set_race("donkey");set_level(8);set_hp(120);set_ep(80000);
set_wc(4);set_ac(2);set_aggressive(0);num_riding=0;
load_chat(4,chat_str);
this_object()->set_heart_beat(1);
set_move_at_reset();
if (!rucksack) { rucksack=clone_object("players/whisky/garden/obj/rucksack");move_object(rucksack,this_object());}
return 1; }
init() {
add_action("kiss","kiss");add_action("hunt","hunt");
add_action("ride","ride");add_action("leave","leave");
add_action("move","south");add_action("move","north");
add_action("move","east");add_action("move","west");
add_action("move","up");add_action("move","down");
add_action("move","southwest");add_action("move","southeast");
add_action("look","look");
add_action("move","nothwest");add_action("move","notheast");
add_action("mysay","say");
::init();
if (num_riding <= MAX_RIDE) {  /* for lumumba */
if (environment(this_object()) == this_player()) {
num_riding++;
return 1; }
return 0; }
else {
write("More than 3 people are to much for the little donkey.\n");
move_object(this_player(),environment()); 
return 1;
}
}
look(str) {
if (str=="down") {
if (environment(this_player()) !=this_object()) return;
move_object(this_player(),environment());
this_player()->look(0);
move_object(this_player(),this_object());
return 1; }
else return this_player()->look(str);
}
long() {
if(environment(this_player()) == this_object()) {
write("You are sitting on a smart little donkey.\n");
return 1;}
write("The donkey likes you, you should try to kiss him or just tell him to\n"); 
write("hunt <playername>\n");
return 1; }
hunt(str) {
if (!str) { return;}
hunt=find_player(str);
if (!hunt) { write("No such person is playing now.\n"); return; }
hunt_name=str;
move_player("X",environment(hunt));
write("The donkey is now running after "+hunt->query_name()+".\n");
return 1; }
kiss(str) {
if (!id(str)) return;
write("You kissed the little donkey and it gasps in astonishment\n");
write("Suddenly the donkey stares deep in your eyes.\n");
write("Suddenly the donkey gets hot and kisses you softly.\n");
say("IIAAAHHH\n");
this_player()->set_title("kissing donkeys");
return 1; }
ride(str) {
if (!id(str)) return;
if (num_riding==MAX_RIDE) {
if (environment(this_player()) == this_object()) {
write("You are already sitting on the good looking donkey.\n");
}
else {
write("The poor donkey can only manage 3 persons.\n");
return 1; }
}
write("You ride the smart little donkey.\n");
say(PNAME+" comes riding on a good looking donkey.\n",this_player());move_object(this_player(),this_object());
return 1; }
leave(str) {
if (environment(this_player()) == this_object()) {
write("You jump down from the beautiful donkey.\n");
move_object(this_player(),environment());
say(PNAME+ " jumps down from the smart donkey.\n", this_player());
return 1; }
return 0; }
move() {
if (environment(this_player())==this_object())
return command(query_verb(),this_object());
else return 0; }
move_player(dir_dest,optional_dest_ob) {
string dir, dest;
if(!optional_dest_ob) {
if (sscanf(dir_dest, "%s#%s", dir, dest) !=2) {
tell_object(this_object(), "Move to bad dir/dest.\n");
return; }
}
else {
dir= dir_dest;
dest = optional_dest_ob;
}
if (dir=="X") {
move_object(this_object(),dest);
say("A cute little donkey arrives.\n");
}
else {
tell_outer("The noble knight rides "+dir+" on a cute little donkey.\n");
tell_inner("You and your donkey ride " +dir+".\n");
move_object(this_object(),dest);
tell_inner("You arrive at: " +environment()->short()+".\n");
tell_outer("A noble knight hops in riding on a cute little donkey.\n");
}
return 1;
}
tell_outer(say_string) {
tell_room(environment(this_object()),say_string);
}
tell_inner(say_string) {
tell_room(this_object(),say_string); }
mysay(say_string) {
if(present(this_player(),this_object())) {
tell_outer(this_player()->query_name()+" says: "+say_string+".\n");
tell_inner("Ok.\n");
return 1; } }
