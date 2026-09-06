// an example for items - who could be 'installed' in player houses
// made by magictcs - 07.02.97
// these items must not bought via OEFC catalogue
// you can simple get them somewhere and then 'install' it in your house

#include <moving.h>
#include <properties.h>
#define LOG "magictcs/picture.log"

inherit "/std/thing";
int can_install;

string get_help_msg() {
  if (can_install)
    return "Just 'install picture'!\n";
  else
    return "Look at the picture.\n"; 
}

create()
{
  (::create());
  seteuid(getuid());
  if(member(object_name(), '#') == -1) return;
  SetShort("a simple picture");
  SetLong(
  "You can steal this picture of a nice wizard and you can 'install' it in "
  "your player house (if you have one).\n");
  AddId("picture");
  AddAdjective("simple");
  SetWeight(300);
  SetValue(10);
  SetProp(P_HELP_MSG,#'get_help_msg);
  // set the item to noget if it is cloned in a player house!!
  can_install=0;   // no install command yet
  call_out("check_noget",1);
}

// don't put this check into create! (environment is unstable there)
// all player houses have a "Homedir" string
void check_noget() {
  if (environment()->QueryHomedir()!=0) {   // yes it should be a player house
    Set(P_NOGET,1);
    SetLong("A beautiful picture of a nice wizard called 'Magictcs'.\n");
  }
  else
    // prevent the item from cloning itself many times
  can_install=1;
}

init() {
  ::init();
  add_action("install","install");
}

// change for your own items only notify_fail
install(string str)
{
  object env;
  if (can_install==0) return 0;
  notify_fail(
    "Please try 'install picture' somewhere in your player-house!\n");
  if(!str || !id(str))
    return 0;
  if(!(env = environment(this_player()))
     ->QueryIsOwner(getuid(this_player()))) {
    notify_fail(
    "You can't install "+QueryShort()+" in this room. It's not your own.\n");
    return 0;
  }
  env->AddItem(explode(object_name(this_object()),"#")[0]);
  env->update_file();
  log_file(LOG,this_player()->QueryRealName()+
    " installs the picture.\n");
  remove();
  return 1;
}
