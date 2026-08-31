
#include <std.h>

inherit OBJECT;

object owner, room;
int dis;
int x,y;
object *per=({}), *ply=({});

void create() {
    ::create();
    set_name("range object");
    set_id(({ "range" }));
    set_short("");
    set_long("an orb for ranges.");
    set_weight(0);
    set_curr_value("", 0);
    dis = 5;
    x = 0;
    y = 0;
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
    if((!owner) && (environment(this_object())->is_living()))
        owner = environment(this_object());
       
    if(!environment(owner)) return;
        room = environment(owner);
        per = all_inventory(room);
    owner->set("Px", 5);
    
    if (!ply) // this will make sure the mapping wont reset ever rounf
    {
       owner->set("Px", 5);
       owner->set("Px", 5);
        for(x = 0; x < sizeof(per); x++)
        {
            if( per[x]->is_living() && per[x]!= owner && 
                !wizardp(per[x]) && !per[x]->query_ghost() && !per[x]->is_monster())
            {
                ply = ply + ({ per[x] });
            }
        }
        for(x = 0; x < sizeof(ply); x++)
        {
            if(!ply[x]) continue;
            ply[x]->set("Px", random(12));
            ply[x]->set("Py", random(12));
        }
        
    }
    else
    {
    }
}
