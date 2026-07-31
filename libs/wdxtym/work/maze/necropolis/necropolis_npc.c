#include <ansi.h>
inherit NPC;

int is_undead() {
        return 1;
}

void die() {
        object killer,*inv,item,mazeobj;
        int count,finished;
        string name;
        //death_msg
        if(query("death_msg"))
                        message_vision(query("death_msg"),this_object());
        else
                        message_vision("\n$NËÀÁË¡£\n\n",this_object());
        //check quest
        killer = query_last_damage_from();

        if(killer && userp(killer)) {
                mazeobj = FUBEN_D->query_maze_mainobj(this_object());
                if(!mazeobj) mazeobj = FUBEN_D->query_maze_mainobj(killer);
                if(query("quest/to_kill/"+name(), mazeobj)) { 
                        count = query("quest/to_kill/"+name(), mazeobj); 
                        finished = query("quest/killed/"+name(), mazeobj); 
                        finished++;
                        if(finished>count)
                                        finished = count;
                        set("quest/killed/"+name(), finished, mazeobj);
                        tell_object(killer,HIW"É±ËÀ "+name()+": "+finished+"/"+count+"¡£\n"NOR);
                }
                //µÚ6¸öÈÎÎñ£¬ÊØÎÀ¶¡Ò»£¬É±¶þÊ®¸öÍöÁé
                if( query("quest/quest_index", mazeobj) == 6 && is_undead() && 
                   environment() && query("short", environment()) == HIY"¾ÛÁé·¨Õó"NOR){
                                count=query("quest/to_kill/ÍöÁé", mazeobj);
                                if(count>0) {
                                        finished=query("quest/killed/ÍöÁé", mazeobj);
                                        finished++;
                                        if(finished>count)
                                                finished = count;
                                        set("quest/killed/ÍöÁé", finished, mazeobj);
                                        tell_object(killer,HIW"³¬¶È ÍöÁé: "+finished+"/"+count+" ¡£\n"NOR);
                                }
                }
        }
        //put all thing to ground
        inv = all_inventory(this_object());
        foreach(item in inv) {
                if(item)
                        item->move(environment());
        }
        ::die();
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env; 
        string userid;
        int x,y;
         
        if( !mapp(exits=query("exits", environment())))return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place=query("exits/"+direction, env);
        my_birth_place = file_name(this_object());
        
        //ccommand("say "+to_go_place);
        if(sscanf(to_go_place,"/f/necropolis/%s/maze/%d/%d",userid,x,y)!=3)
                        return 1;
        command("go " + direction);
        addn_temp("random_move",1);
        return 1;
}   
