
#include <std.h>

inherit OBJECT;

void set_initial_position();
void remove_fromroom();

object owner, room;
int dis;

object *per=({}), *ply=({});

void create() {
    ::create();
    set_name("range pedestal");
    set_id(({ "range" }));
    set_short("pedestal");
    set_long("a pedestal for ranges.");
    set_weight(0);
    set_curr_value("", 0);
    dis = 5;
    set_heart_beat(1);
    set_prevent_get( "Not gonna happen." );
}



void init()
{
    ::init();
    //add_action("", ""); // function, command
}

void heart_beat()
{
    if(!this_object()) return;
    if(!environment(this_object())) return;
    //if((!owner) && (environment(this_object())->is_living()) && (environment(this_object())->is_monster()))
    //    owner = environment(this_object());
    //if(!owner) return;
    
    room = environment(this_object());
    per = all_inventory(room);
    
    //message("ob", "BUMP BUMP BUMP", find_player("daboura"));
    
    set_initial_position(); // sets the x,y position of the player and monster
    remove_fromroom();

        //messgae to let me know who is in the ply mapping
        if(sizeof(ply))
        {
            for(int i = 0; i < sizeof(ply); i++)
            {   
                if(!ply[i]) continue;
                
               
                    message("ob", ""+ply[i]->query_name(), find_player("daboura"));
                   
                       
            }    
        }
        
       // foreach (mixed key, mixed value in blah) { if (value ==
//thethingyouknow) map_delete(blah, key); }
}


void set_initial_position()
{
    //if(!this_object()) return;
    //if(!environment(this_object())) return;
    int lt = 0;

    for(int x = 0; x < sizeof(per); x++)
        {
            if( per[x]->is_living() && 
                !wizardp(per[x]) && !per[x]->query_ghost())
            {
                if(sizeof(ply))
                {
                    for(int i = 0; i < sizeof(ply); i++)
                    {
                           
                        if(ply[i] == per[x])
                            lt = 1;           
                    }
                    if(lt == 0)
                    {
                        ply = ply + ({ per[x] });
                        per[x]->set("Px", 1+random(11));
                        per[x]->set("Py", 1+random(11));
                    }
                    lt = 0;
                }
                else
                {
                    ply = ply + ({ per[x] });
                    per[x]->set("Px", 1+random(11));
                    per[x]->set("Py", 1+random(11));
                }
            }
        }
    return;
}

void remove_fromroom()
{
        if(sizeof(ply))
        {
            for(int i = 0; i < sizeof(ply); i++)
            {   
                if(!ply[i]) continue;
                if(environment(ply[i]) != room || !environment(ply[i]))
                {
                    ply[i]->set("Px", 0);
                    ply[i]->set("Py", 0);
                    ply = ply - ({ ply[i] });
                }          
            }    
        }
        return;
}
