/* cominfo.c
 * Externalized by Baldrick dec '97
 * Originally by Dyraen@RoD
 */

#include <standard.h>
#include <cmd.h>
#include <commands.h>
#define C_NAME 0
#define C_DATA 1
#define C_OBJ 2
#define C_FUNC 3

#define SOUL_OBJECT "/obj/handlers/soul"

inherit CMD_BASE;

void setup(){

position = 1;
}

protected string do_find_comm(string func, object ob) {
  string s, ping;
  object fish;
  s = "";
  if(ping = function_exists(func, ob))
      s += " found in " + ping;
    else
      s += " not found";
  fish = ob;
  while(fish = shadow(fish, 0))
    if(function_exists(func, fish))
      s += " shadowed by " + file_name(fish);
  s += ".\n";
  return s;
} /* do_find_comm() */


protected int cmd(string str, object me) 
  {
  object on;
  string *comms, xtra, s1, s2, found_cmd;
  int i;

  if (str) {
    sscanf(str,"%s %s",s1,s2);
    if (s2) {
      s2 = me->expand_nickname(s2);
      on = find_player(s2);
      str = s1;
    }
  }
  if (on)
    comms = on->query_commands();
  else
    comms = me->query_commands();

  write("Searching "+sizeof(comms)+" commands..\n");

  if (!str || str == "0")
    for(i=0;i<sizeof(comms);i++)
      {
    // See below, wonderflug
      //if ((string)comms[i][C_NAME..C_NAME] == "") comms[i][C_NAME..C_NAME] = "*";
      xtra = do_find_comm((string)comms[i][C_FUNC],(object)comms[i][C_OBJ]);
      write(i+". "+comms[i][C_NAME]+"["+comms[i][C_DATA]+"] "+
            file_name((object)comms[i][C_OBJ])+"->"+comms[i][C_FUNC]+"()"+
            xtra);
     }
    else
     {
     for(i=0;i<sizeof(comms);i++)
       {
       //We don't match '*', and besides this buggers it somehow.
       // Wonderflug
       //if ((string)comms[i][C_NAME] == "") (string)comms[i][C_NAME..C_NAME] = "*";
       if (str ==(string) comms[i][C_NAME])
         {
         xtra = do_find_comm((string)comms[i][C_FUNC],(object)comms[i][C_OBJ]);
         write(comms[i][C_NAME]+"["+comms[i][C_DATA]+"] "+
            file_name((object)comms[i][C_OBJ])+"->"+comms[i][C_FUNC]+"()"+
            xtra);
        }
      }
    found_cmd = CMD_HANDLER->find_cmd(str);
    if (found_cmd)
      write (found_cmd + "\n");
    }
    if ( SOUL_OBJECT->query_soul_command_exist(str) )
      write (str + " found in the soul object\n");
  this_object()->set_trivial_action();
  return 1;
}
