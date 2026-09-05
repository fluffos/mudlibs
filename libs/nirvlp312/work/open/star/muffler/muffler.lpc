/*
 *      File:                 /players/star/cal/obj/diaper.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/10/2006
 *      Notes:
 *      Change History:
*/

int time_started;
#define MUFFLE_TIME 180
#define BASE_DIR "/open/star/muffler"
inherit "obj/treasure";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name ("muffler");
  set_long("There is no muffler here.\n");
  set_weight(0);
  set_value(0);
}

int restore_me()
{
  string tmp, tmp2, saveFile;
  int timeSave;
  object me;
  
  me = environment(this_object());
  
  if(!me || !me->is_player())
    return -1;
    
  if(file_size(BASE_DIR + "/muffled/" + me->query_real_name()) < 1)
    return 0;
    
  saveFile = read_file(BASE_DIR + "/muffled/" + me->query_real_name());
  if(sscanf(saveFile,"started: %d\n",timeSave));
  
  return timeSave;
}

int save_me()
{
  object me;
  
  me = environment(this_object());
  
  if(!me || !me->is_player())
    return 0;

  if(file_size(BASE_DIR + "/muffled/" + me->query_real_name()) > 0)
    rm(BASE_DIR + "/muffled/" + me->query_real_name());
    
  write_file(BASE_DIR + "/muffled/" + me->query_real_name(),"started: " + time_started + "\n");
  
  return 1;
}

void timeCheck()
{
  object obj;

  if(time_started + MUFFLE_TIME <= time())
  {
    obj = environment(this_object());
    if(obj && obj->is_player())
      tell_object(obj,"You can talk now.\n");
    destruct(this_object());
    rm(BASE_DIR + "/muffled/" + obj->query_real_name());
      return;
  }
    
  call_out("timeCheck",2);
   
return;
}

init()
{
  int restoreTime;
  object me;

  ::init();
  
  me = environment(this_object());

  if(me && me->is_player())
  {
    restoreTime = restore_me(BASE_DIR + "/muffled/" +this_player()->query_real_name());

    if(restoreTime < 1)
    {
      time_started = time();
      save_me(BASE_DIR + "/muffled/" +this_player()->query_real_name());
    }
    else
      time_started = restoreTime;

    timeCheck();
  
    add_action("block", "gossip");
    add_action("block", "star");
    add_action("block", "shout");
    add_action("block", "babble");
    add_action("block", "risque");
  }
}

int block(string str)
{
  object me;
  
  me = environment(this_object());
  if(restore_me() > 0 && me && me->is_player())
  {
    tell_object(me,"You cant do that. You can talk again at " + ctime(time_started + MUFFLE_TIME) + ".\n");
    return 1;
  }
  
  return 0;
}

drop() { return 1; }
query_auto_load() { return BASE_DIR + "/muffler.c:"; }
