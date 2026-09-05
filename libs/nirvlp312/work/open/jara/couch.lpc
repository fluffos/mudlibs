#define tp this_player()->query_name()
inherit "obj/treasure";
object SIT;

reset(arg)  {
  if(arg) return;

  set_id("sofa");
  set_short("A comfortable sofa");
  set_long("The wide sofa has luxurious plush cushions and thickly padded pillows.\n");
   set_weight(10000);
   set_value(0);
}

init(){
    ::init();
  add_action("sit","sit");
  add_action("stand","stand");
}
sit(arg){
  /* If someone is on the couch */
   if(SIT) {
             notify_fail((SIT==this_player()?"You are":SIT->query_name()+" is")+" already on the sofa.\n");
return 0; }   /* Do not let them sit */

  if(arg == "sofa" || arg ==  "on sofa"){
    write("You sit on the sofa.\n");  
    say(tp+" sits on the sofa.\n");
SIT =this_player(); /* Make someone sit on the couch */
return 1; }
notify_fail("Sit on what?\n"); /* If they do not give the right arg */
return 0; }

stand(arg){ 
   if(SIT != this_player()) { /* if you're not on the couch */
    notify_fail("You're not on the sofa.\n");
return 0; } /* Do not let them stand */
  if(arg == "up"){  /* Stand up is the cmd to get off */
    write("You get up from the sofa.\n");
    say(tp+" stands up from the sofa.\n");
SIT =0; /* Make the couch sittable again */
return 1; }
    notify_fail("Stand up off the sofa.\n"); /* Tell them how to get off */
return 0; }

