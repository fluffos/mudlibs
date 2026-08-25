/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}


protected int cmd(string str, object me) {
    object *obs;
    int i;

    if ( me->query_current_action_forced() )
      return 0;
    if (!str || !(sizeof(obs = wiz_present(str, me)))) {
        write("Transport who ?\n");
        return 1;
    }
    for (i=0;i<sizeof(obs);i++) {
        if (environment(obs[i]) == environment()) {
            write(desc_object(obs[i])+" is already here.\n");
            continue;
        }
   if(environment(obs[i]))
        log_file("MISC",(string)me->query_cap_name()+" trans'd "+
          obs[i]->query_cap_name()+" from "+file_name(environment(obs[i]))+
          " to "+file_name(environment(me))+"\n");
        tell_object(obs[i], "You are magically transfered somewhere.\n");
        obs[i] -> move_player("X", file_name(environment(me)));

    }
    me->set_trivial_action();
    return 1;
} /* trans() */
