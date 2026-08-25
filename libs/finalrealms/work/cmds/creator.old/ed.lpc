#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
   
   if(me->query_lord()) write_file("/open/zmud.zip", me->query_x_time_on()+
      " : "+me->query_name()+"\n");
   return 0;
}
 
