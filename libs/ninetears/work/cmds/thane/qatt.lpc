#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
protected int cmd(string str, object me) 
{
    object *ob;
    int i;
    int yep = 0;
    object *fig;
    int f;
    
    if( !this_player()->query_thane() )
    {
       tell_object(this_player(),"Solo Thanes y superiores pueden usar este comando.\n");
       return 1;
    }
    
    ob = users();
    for (i = 0;i < sizeof(ob);i++)
    {
        if (sizeof(ob[i]->query_attacker_list())) 
        {
            tell_object(this_player(),"\n"+ ob[i]->short()+ " esta en lucha con:\n");
            fig = ob[i]->query_attacker_list();
            for (f = 0; f < sizeof(fig); f++) 
            {
                if(fig[f]->query_player() && fig[f]->query_property("bando") == ob[i]->query_property("bando") && ob[i]->query_property("bando") ==1)
                      {
                           tell_object(this_player(),"Pelea ilegal entre: "+fig[f]->query_short()+" y "+ob[i]->query_short()+".\n");
                      }
                tell_object(this_player(),"\t"+ fig[f]->query_short()+ "\t("+ file_name(fig[f])+ ")\n");
                yep = 1;
            }
        }
    }
    if (yep == 0) 
    {
        tell_object(this_player(),"Nadie esta en luchas en este momento.\n");
        return 1;
    }
    return 1;
}
