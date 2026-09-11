// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// _snoopable.c
// this space intentionally left blank
// Megaboz@ZorkMUD added header and help

#include <playerflags.h>
#include <mudlib.h>

inherit CMD;

private void main(string arg){
  if(!arg || arg == ""){
    if(this_body()->test_flag(F_SNOOPABLE) )
                out("巫师目前能够监听你。\n");
        else out( "巫师目前不能监听你。\n");
    return;
  }
  switch(arg){
    case "on":  this_body()->set_flag(F_SNOOPABLE);
                break;
    case "off": this_body()->clear_flag(F_SNOOPABLE);
                break;
    default:    out("用法：snoopable (on|off)\n");
                return;
  }
  out("完成。\n");
  return;
}
