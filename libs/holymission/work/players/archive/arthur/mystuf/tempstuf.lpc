/*Code by Arthur for Holy Mission - 140.78.3.1 Date Done 11.4.94 */
inherit "obj/treasure";
#define DIR "/players/arthur/mystuf"

reset (arg) {
if (arg) return;
   set_id(A Toy");
   set_short("A hazardous toy");
   set_alias("toy");
   set_long("Slimy Egg Yolk that makes it very hard to see.\n");
   set_value(0);
   set_weight(0);
}
init() {
     add_action("no_see", "look");
     add_action("no_see", "l");
     add_action("wf","wipe");
     ::init();
}
no_see() {
  write("You try to look around, but alas you are blinded by slimy egg\n"+
  "yolk. Maybe you should try wiping your face to remove the egg yolk.\n");
  return 1;}

wf(str) {

  if(!str) return 0;
  
  if(str !="face") return 0;
  
  write("You wipe your face clean.\n");
  destruct(this_object()); return 1;
  }
