#include <std.h>


void set_initial_position();
void map();
void remove_fromroom();
void main_combat();
void aggressive(object);
void defensive(object);
void passive(object);
int get_movement(object);
int get_distance(object, object);
int abs(int);

object dcombat_owner, dcombat_room;
object *per=({}), *ply=({}), *akrs=({});

/*
void heart_beat()
{
    if(!this_object()) return;
    if(!environment(this_object())) return;
    
    dcombat_room = environment(this_object());
    per = all_inventory(dcombat_room);
    
    //message("ob", "BUMP BUMP BUMP", find_player("daboura"));
    
    set_initial_position(); // sets the x,y position of the player and monster
    remove_fromroom(); 
    //map();   
    main_combat();
}
*/

void map()
{
    int mobed = 0;
    string field = "";
    if(!sizeof(ply)) return;
    for(int y = 11; y > 0; y--)
    {
        for(int x = 1; x < 12; x++)
        {
           for(int p = 0; p < sizeof(ply); p++)
           {
                if(ply[p]->query("Px") == x && ply[p]->query("Py") == y)
                {   
                    if(ply[p]->is_player())
                        field = field + "P";
                    else
                        field = field + "M";
                    mobed = 1;    
                }   
           }
            if(mobed == 0)
                field = field + "%^GREEN%^%^BOLD%^+%^RESET%^";
            mobed = 0;
        }
        field = field + "\n";
    }
    message("ob", ""+field, this_player());
    return;
}

void main_combat(object active)
{
    //they are moving around too much, add a random to slow them down      
            //remove_fromroom(); 
                if(!sizeof(active->query_attackers())) return;
                if(active->is_player())
                {
                    passive(active);  
                }
                else
                {
                    if(active->query("behavior") == 3)
                    {
                        defensive(active);
                        return;
                    }
                    if(active->query("behavior") == 2)
                    {
                        passive(active);
                        return;
                    } 
                    if(active->query("behavior") == 1)
                    {
                        aggressive(active);
                        return;
                    } 
                    if(active->query("aggressive") <= 10)
                        defensive(active);   
                    else if(active->query("aggressive") >= 35)
                        aggressive(active);
                    else
                        passive(active);
                        
                }      
    return;
}

void passive(object active)
{
    int dis = 0, d, Mx, My, Ax, Ay;
    object closer;
    
    if(sizeof(active->query_attackers()))
    {
        akrs=active->query_attackers();
        if(sizeof(akrs))
        {
            dis = get_distance(active, akrs[0]);
            closer = akrs[0];   
                       
            for(int x = 0; x < sizeof(akrs); x++) //this finds out who is the closest of enemies
            {
                if(get_distance(active, akrs[x]) < dis)
                {
                    dis = get_distance(active, akrs[x]);
                    closer = akrs[x]; 
                }
                    //message("ob", ""+active->query_name()+" is "+dis+" units from "+akrs[x]->query_name(), environment(active));
            }
            //message("ob", "targer is "+closer->query_name()+", range "+dis+" units", environment(active));
            if(dis > 7)
            {
                aggressive(active);
            }
            else if(dis < 4)
            {
                defensive(active);
            }
            else
            {
                
                                if(random(2) == 1)
                                {
                                    if(random(2) == 1)
                                    {
                                        if((Mx + d) > 11)
                                        {
                                            Mx = Mx - 1;
                                        }
                                        else
                                            Mx = Mx + 1;
                                    }
                                    else
                                    {
                                        if((Mx - d) < 1)
                                        {
                                            Mx = Mx + 1;
                                        }
                                        else
                                        {
                                            Mx = Mx - 1;
                                        }
                                    }
                                    active->set("Px", Mx);   
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        if((My + d) > 11)
                                        {
                                            My = My - 1;
                                        }
                                        else
                                            My = My + 1;
                                    }
                                    else
                                    {
                                        if((My - d) < 1)
                                        {
                                            My = My + 1;
                                        }
                                        else
                                        {
                                            My = My - 1;
                                        }
                                    }
                                    active->set("Py", My);
                                }                                
            }
            
            
        }
    }
    return;
}

void aggressive(object active)
{
    int dis = 0, d, Mx, My, Ax, Ay;
    object closer;
    
    if(sizeof(active->query_attackers()))
               {
                    akrs=active->query_attackers();
                    if(sizeof(akrs))
                    {
                        dis = get_distance(active, akrs[0]);
                        closer = akrs[0];   
                        
                        for(int x = 0; x < sizeof(akrs); x++) //this finds out who is the closest of enemies
                        {
                            if(get_distance(active, akrs[x]) < dis)
                            {
                                dis = get_distance(active, akrs[x]);
                                closer = akrs[x]; 
                            }
                            //message("ob", ""+active->query_name()+" is "+dis+" units from "+akrs[x]->query_name(), environment(active));
                        }
                        d = get_movement(active);
                        Mx = active->query("Px");
                        My = active->query("Py");
                        Ax = closer->query("Px");
                        Ay = closer->query("Py");
                        
                        if(dis <= d && d > 0)
                        {   //if the target is within moving distance, just put them right on top of eachother
                            active->set("Px", Ax);
                            active->set("Py", Ay);  
                            return;  
                        }                        
                        if(Ax > Mx && Ay > My)
                        {     // moves the character upper right
                            active->set("Px", Mx+d);
                            active->set("Py", My+d);
                            if(active->query("Px") > 11) active->set("Px", 11);
                            if(active->query("Py") > 11) active->set("Py", 11);
                        }
                        if(Ax > Mx && Ay < My)
                        {   // moves the character lower right
                            active->set("Px", Mx+d);
                            active->set("Py", My-d);
                            if(active->query("Px") > 11) active->set("Px", 11);
                            if(active->query("Py") < 1) active->set("Py", 1);
                        }
                        if(Ax < Mx && Ay < My)
                        {   //moves character lower left
                            active->set("Px", Mx-d);
                            active->set("Py", My-d);
                            if(active->query("Px") < 1) active->set("Px", 1);
                            if(active->query("Py") < 1) active->set("Py", 1);
                        }
                        if(Ax < Mx && Ay > My)
                        {   // moves the character upper left                          
                            active->set("Px", Mx-d);
                            active->set("Py", My+d);
                            if(active->query("Px") < 1) active->set("Px", 1);
                            if(active->query("Py") > 11) active->set("Py", 11);                           
                        }
                        //if the axis' are equal
                        if(Ax < Mx && Ay == My)
                        {  
                            active->set("Px", Mx-d);
                            if(active->query("Px") < 1) active->set("Px", 1);
                        }
                        if(Ax > Mx && Ay == My)
                        {   //moves the character to the 
                            active->set("Px", Mx+d);
                            if(active->query("Px") > 11) active->set("Px", 11);
                        }
                        if(Ax == Mx && Ay < My)
                        {   //moves the character to the 
                            active->set("Py", My-d);
                            if(active->query("Py") < 1) active->set("Py", 1);
                        }
                        if(Ax == Mx && Ay > My)
                        {   //moves the character to the 
                            active->set("Py", My+d);
                            if(active->query("Py") > 11) active->set("Py", 11);
                        }
                        if(Ax == Mx && Ay == My)
                            {
                                if(random(2) == 1)
                                {
                                    if(random(2) == 1)
                                    {
                                        if(Mx + d > 11)
                                        {
                                            Mx = Mx - d/2;
                                        }
                                        else
                                            Mx = Mx + d/2;
                                    }
                                    else
                                    {
                                        if(Mx - d < 1)
                                        {
                                            Mx = Mx + d/2;
                                        }
                                        else
                                        {
                                            Mx = Mx - d/2;
                                        }
                                    }
                                    active->set("Px", Mx);   
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        if(My + d > 11)
                                        {
                                            My = My - d/2;
                                        }
                                        else
                                            My = My + d/2;
                                    }
                                    else
                                    {
                                        if(My - d < 1)
                                        {
                                            My = My + d/2;
                                        }
                                        else
                                        {
                                            My = My - d/2;
                                        }
                                    }
                                    active->set("Py", My);
                                }
                        }
        }                                      
    } 
    return;                                  
}

void defensive(object active)
{   //this huge function governs the behavior of any mob classified as "defensive"
    int dis = 0, d, Mx, My, Ax, Ay;
    object closer;
    if(sizeof(active->query_attackers()))
               {
                    akrs=active->query_attackers();
                    if(sizeof(akrs))
                    {
                        dis = get_distance(active, akrs[0]);
                        closer = akrs[0];   
                        
                        for(int x = 0; x < sizeof(akrs); x++) //this finds out who is the closest of enemies
                        {
                            if(get_distance(active, akrs[x]) < dis)
                            {
                                dis = get_distance(active, akrs[x]);
                                closer = akrs[x]; 
                            }
                            //message("ob", ""+active->query_name()+" is "+dis+" units from "+akrs[x]->query_name(), environment(active));
                        }
                        d = get_movement(active);
                        Mx = active->query("Px");
                        My = active->query("Py");
                        Ax = closer->query("Px");
                        Ay = closer->query("Py");
                        if(Ax > Mx && Ay > My) //moves the character to the lower left
                        {   //checks to see if the mob is in the corner, and then moves them out of it
                            if(Mx == 1 && My == 1)
                            {
                                if(Ax - Mx > Ay - My)
                                {
                                    active->set("Py", My+d);    
                                }
                                else if(Ay - My > Ax - Mx)
                                {
                                    active->set("Px", Mx+d);    
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        active->set("Py", My+d);  
                                    }
                                    else
                                    {
                                        active->set("Px", Mx+d); 
                                    }
                                }
                            }
                            else
                            {
                                active->set("Px", Mx-d);
                                active->set("Py", My-d);
                                if(active->query("Px") < 1) active->set("Px", 1);
                                if(active->query("Py") < 1) active->set("Py", 1);
                            }
                        }
                        if(Ax > Mx && Ay < My)
                        {   //moves the character to the upper left
                            if(Mx == 1 && My == 11)
                            {
                                if(Ax - Mx > My - Ay)
                                {
                                    active->set("Py", My-d);    
                                }
                                else if(My - Ay > Ax - Mx)
                                {
                                    active->set("Px", Mx+d);    
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        active->set("Py", My-d);  
                                    }
                                    else
                                    {
                                        active->set("Px", Mx+d); 
                                    }
                                }
                            }
                            else
                            {
                                active->set("Px", Mx-d);
                                active->set("Py", My+d);
                                if(active->query("Px") < 1) active->set("Px", 1);
                                if(active->query("Py") > 11) active->set("Py", 11);
                            }
                        }
                        if(Ax < Mx && Ay < My)
                        {   //moves the character to the upper right
                            if(Mx == 11 && My == 11)
                            {
                                if(Mx - Ax > My - Ay)
                                {
                                    active->set("Py", My-d);    
                                }
                                else if(My - Ay > Mx - Ax)
                                {
                                    active->set("Px", Mx-d);    
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        active->set("Py", My-d);  
                                    }
                                    else
                                    {
                                        active->set("Px", Mx-d); 
                                    }
                                }
                            }
                            else
                            {
                                active->set("Px", Mx+d);
                                active->set("Py", My+d);
                                if(active->query("Px") > 11) active->set("Px", 11);
                                if(active->query("Py") > 11) active->set("Py", 11);
                            }
                        }
                        if(Ax < Mx && Ay > My)
                        {   //moves the character to the lower right
                            if(Mx == 11 && My == 1)
                            {
                                if(Mx - Ax > Ay - My)
                                {
                                    active->set("Py", My+d);    
                                }
                                else if(Ay - My > Mx - Ax)
                                {
                                    active->set("Px", Mx-d);    
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        active->set("Py", My+d);  
                                    }
                                    else
                                    {
                                        active->set("Px", Mx-d); 
                                    }
                                }
                            }
                            else
                            {
                                active->set("Px", Mx+d);
                                active->set("Py", My-d);
                                if(active->query("Px") > 11) active->set("Px", 11);
                                if(active->query("Py") < 1) active->set("Py", 1);
                            }
                            
                        }
                        //These below move the character randomly away from the attacker if one of the axis' is the same
                        if(Ax < Mx && Ay == My)
                        {  
                            active->set("Px", Mx+d);
                            if(active->query("Px") > 11) active->set("Px", 11);
                            if (random(2) == 1)
                            {   
                                if(My == 1)
                                    active->set("Py", My+1);
                                else if(My == 11) 
                                    active->set("Py", My-1);  
                                else
                                    active->set("Py", My+1);              
                            }
                            else
                            {
                                if(My == 11) 
                                    active->set("Py", My-1);
                                else if(My == 1)
                                    active->set("Py", My+1);     
                                else
                                    active->set("Py", My-1); 
                            }
    
                        }
                        if(Ax > Mx && Ay == My)
                        {   //moves the character to the 
                        
                            active->set("Px", Mx-d);
                            if(active->query("Px") < 1) active->set("Px", 1);
                            if (random(2) == 1)
                            {   
                                if(My == 1) 
                                    active->set("Py", My+1);
                                else if(My == 11) 
                                    active->set("Py", My-1);  
                                else
                                    active->set("Py", My+1);                   
                            }
                            else
                            {
                                if(My == 11) 
                                    active->set("Py", My-1);
                                else if(My == 1)
                                    active->set("Py", My+1);     
                                else
                                    active->set("Py", My-1);     
                            }
    
                        }
                        if(Ax == Mx && Ay < My)
                        {   //moves the character to the 
                            active->set("Py", My+d);
                            if(active->query("Py") > 11) active->set("Py", 11);
                            if (random(2) == 1)
                            {   
                                if(Mx == 1) 
                                    active->set("Px", Mx+1);
                                else if(Mx == 11)
                                    active->set("Px", Mx-1);                 
                                else
                                    active->set("Px", Mx+1);
                            }
                            else
                            {
                                if(Mx == 11) 
                                    active->set("Px", Mx-1);
                                else if(Mx == 1)
                                    active->set("Px", Mx+1);     
                                else
                                    active->set("Px", Mx-1);
                            }
    
                        }
                        if(Ax == Mx && Ay > My)
                        {   //moves the character to the 
                            active->set("Py", My-d);
                            if(active->query("Py") < 1) active->set("Py", 1);
                            if (random(2) == 1)
                            {   
                                if(Mx == 1) 
                                    active->set("Px", Mx+1);
                                else if(Mx == 11)
                                    active->set("Px", Mx-1);                 
                                else
                                    active->set("Px", Mx+1);                
                            }
                            else
                            {
                                if(Mx == 11) 
                                    active->set("Px", Mx-1);
                                else if(Mx == 1)
                                    active->set("Px", Mx+1);     
                                else
                                    active->set("Px", Mx-1);    
                            }
                        }
                            if(Ax == Mx && Ay == My)
                            {
                                if(random(2) == 1)
                                {
                                    if(random(2) == 1)
                                    {
                                        if(Mx + d > 11)
                                        {
                                            Mx = Mx - d;
                                        }
                                        else
                                            Mx = Mx + d;
                                    }
                                    else
                                    {
                                        if(Mx - d < 1)
                                        {
                                            Mx = Mx + d;
                                        }
                                        else
                                        {
                                            Mx = Mx - d;
                                        }
                                    }
                                    active->set("Px", Mx);   
                                }
                                else
                                {
                                    if(random(2) == 1)
                                    {
                                        if(My + d > 11)
                                        {
                                            My = My - d;
                                        }
                                        else
                                            My = My + d;
                                    }
                                    else
                                    {
                                        if(My - d < 1)
                                        {
                                            My = My + d;
                                        }
                                        else
                                        {
                                            My = My - d;
                                        }
                                    }
                                    active->set("Py", My);
                                }
                            }
                    }
                    
               }
}

int get_movement(object m)
{
    return 2;
}

int get_distance(object mover, object attacker)
{
    int Mx, My, Ax, Ay, d;
    
    Mx = mover->query("Px");
    My = mover->query("Py");
    Ax = attacker->query("Px");
    Ay = attacker->query("Py");
    
    if((Mx == Ax) && (My == Ay)) return 0;
    if(Mx == Ax) return abs(My - Ay);
    if(My == Ay) return abs(Mx - Ax);
    d = sqrt((abs(My - Ay)*abs(My - Ay)) 
                    + (abs(Mx - Ax)*abs(Mx - Ax)));   
    return d; 
    return 1;
}

//this sets the initial position of every living thing in the room
void set_initial_position(object room)
{
    //if(!this_object()) return;
    //if(!environment(this_object())) return;
    int lt = 0;
    per = all_inventory(room);
    for(int x = 0; x < sizeof(per); x++)
        {//!wizardp(per[x]) &&
            if( per[x]->is_living() && 
                 !per[x]->query_ghost() && !wizardp(per[x]))
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

//This removes any living thing that leaves the room
void remove_fromroom(object active)
{
        if(sizeof(ply))
        {
            for(int i = 0; i < sizeof(ply); i++)
            {   
                if(ply[i] == active)
                {
                 ply = ply - ({ ply[i] });
                 active->set("Px", 0);
                 active->set("Py", 0);
                 continue;
                 }
            }    
        }
        return;
}

int abs(int x) {
    if(x>-1) return x;
    else return -x;
}
