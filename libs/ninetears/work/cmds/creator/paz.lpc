#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
 

int cmd(string str, object me) 
{
    object *ob;
    object *att;
    object *call;
    int i, s;
    ob=all_inventory(environment(this_player()));
    i=0;
    for(i=0; i<sizeof(ob); i++) 
    {
        if(living(ob[i])) 
        {
            att=ob[i]->query_attacker_list();
            call=ob[i]->query_call_outed();
            for(s=0; s<sizeof(att); s++) 
            {
                ob[i]->stop_fight(att[s]);
                att[s]->stop_fight(ob[i]);
            }
            for(s=0; s<sizeof(call); s++) 
            {
                ob[i]->stop_fight(call[s]);
                call[s]->stop_fight(ob[i]);
            }
        }
    }
    write("Levantas tu mano y gritas: "+
          "%^YELLOW%^PARAD DE LUCHAR MORTALES!! %^RESET%^\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
              " levanta su mano y grita: %^YELLOW%^PARAD DE LUCHAR MORTALES!!!
              %^RESET%^\n", ({this_player()}));
    return 1;
}
