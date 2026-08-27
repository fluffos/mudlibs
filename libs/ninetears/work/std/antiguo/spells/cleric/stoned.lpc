
#include "tweaks.h"
inherit "/std/object";
#define STONE_SH SPELLS+"stone_sh"
int query_spell() { return 1; }

void setup() {
   set_name("stoned");
   set_short("A layer of stone");
   set_long("A layer of stone covering one of the most lifelike statues you've ever seen.\n");
   set_weight(0);
   set_value(0);
   reset_drop();
}
init() {
   object ob;
   ::init();
   add_action("bingle_tell","t*ell",30000);
   add_action("bingle_shout","sh*out");
   add_action("bingle_shout","shout!");
   add_action("bingle_say","sa*y");
   add_action("bingle_say","'*");
   add_action("bingle_loud_say","lsay");
   add_action("bingle_loud_say","\"*");
   add_action("bingle_whisper","whi*sper");
   if(environment(this_object()) == this_player() )
   {
        setup_shadow(this_player());
   }
}
void setup_shadow(object victim)
{
    object ob;
   if(!victim->query_property("stoned")) return;
    if(!victim->query_stone_shadow())
    {
        ob = clone_object(STONE_SH);
        ob->setup_shadow(victim);
    }
}
string *wibbles = ({ "gr","th","ng","kt","wt","gd","mn","vb" });

string wibble_speech(string str)
{
 string *cow;
 int i;
 
  if(!str || str == "") return "grpmph";
  cow=explode(str," ");
  for(i=0;i<sizeof(cow);i++)
    cow[i]= wibbles[i&7]+cow[i]+wibbles[(i+1)&7];
  str=implode(cow," ");
  return str;
}
 
 
void bingle_loud_say(string arg)
{
 int x;
 
 arg=(string)wibble_speech(arg);
 x=this_player()->do_loud_say(arg);
 return x;
}
 
void bingle_say(string arg)
{
 int x;
   arg=(string)wibble_speech(arg);
   x=this_player()->do_say(arg);
 return x;
}
 
void bingle_tell(string arg)
{
 int x;
  arg=(string)wibble_speech(arg);
  x=this_player()->do_tell(arg);
 return x;
}
 
void bingle_shout(string arg)
{
 int x;
  arg=(string)wibble_speech(arg);
  x=this_player()->do_shout(arg);
 return x;
}
 
void bingle_whisper(string arg)
{
 int x;
   arg=(string)wibble_speech(arg);
  x=this_player()->do_whisper(arg);
 return x;
}


