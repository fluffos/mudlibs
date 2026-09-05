inherit "/obj/armor";
#include "/players/jenny/define.h"
int on;
reset(arg) {
 ::reset(arg);

  set_name("shield");          
  set_short("Light Shield");
  set_long(
  "  A small box connected to a leather strap that can fit\n"+
  "neatly around your waist.  As you look closer at it you\n"+
  "notice it's a shield!  All you have to do is type:\n"+
  "'power_on' or 'power_off'.\n");
  set_type("shield");
  set_ac(1);
  set_weight(2);
  set_value(200);
}
do_special(owner)
{
if(on > 1)
  {
tell_object(owner,HIY+"Just for test, so you know if it is working."+NORM+"\n");
return 1;}
return;}

init(){
  ::init();
  add_action("shield","power");
 }

shield(arg) {
if(!arg) { return 0; }
   if(environment() != this_player()) return 0;
if(arg == "on")  {
if(on > 1) {write("The shield is already on.\n");
return 1;}
tell_room(environment(this_player()),
this_player()->query_name()+" turns on the shield.\n");
write(
"Beams of light shoot out of the box to form a\n"+
"translucent barrier around you!\n");
on = 2;
return 1; }
if(arg == "off") {
if(on < 2) {write("The shield is already off.\n");
return 1; }
tell_room(environment(this_player()),
this_player()->query_name()+" shuts off the shield.\n");
write(
"The shield fades from around your body and disappears back\n"+
"into the small box.\n");
on = 1;
 return 1; }}
