#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("milton");
 set_level(30);
 set_short("Milton, the healer");
 set_long("He's hard at work making oils.");
 set_race("raknid");
 set_gender("male");
 set_id( ({ "milton", "healer" }) );
}
void init()
{
 ::init();
 add_action("fBuy", "buy");
 add_action("fRead", "read");
// set_heart_beat(10);
}
int fRead(string str)
{
 if (!str || str!="sign")
   return notify_fail("Read what?\n");
 say (this_player()->query_cap_name()+" reads over the sign.");
 write("The sign reads:
-----------------------------------------
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     together to make a healing oil. ( 20 gold pieces )
     You can <buy '#' oil> to buy a specific number of oils.
-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  int numba;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="stone" || str=="magical stone") {
    this_object()->force_me("say What are stones?  I've "
      "never heard of them.");
    return 1;
  }
  if(str=="oil") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Milton hands you a vial of healing oil.");
    say("Milton hands "+this_player()->query_cap_name()+" a vial of healing
oil.");
    new("/std/obj/oil")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "oil") {
    write("Buy what?\n");
    return 1;
  }
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write("Milton hands you "+(string)numba+" vials of healing oil.");
  say("Milton hands "+this_player()->query_cap_name()+" "+(string)numba+"
vials of healing oil.");
  while(numba--)
    new("/std/obj/oil")->move(this_player());
  return 1;
}
/* void heart_beat()
{
 if (random(50) > 25)
  {
 this_object()->force_me("say if you want to buy some healing oil type,
<buy oil>");
}
*/
