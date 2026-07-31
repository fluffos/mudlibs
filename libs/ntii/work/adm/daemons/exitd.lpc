// written by super@pkuxkx

#define MAX 40
private object* find_path(object ob,object* rooms);
void clean_path(object* rooms);

mixed search_for_path(object ob,string name)
{
        object env,*temp,*temp1,*bak_room,*temp2;
        mapping exits;
        mixed n;
        int a = 0;
        env = environment(ob);
        temp = ({env});
        temp1 = ({});
        exits = env->query("exits");
        bak_room = ({env});
        
        while (a < MAX) 
        // We use Breadth_first search for Traversing graph.
        {
                reset_eval_cost();
                temp2 = copy(temp);
                temp = ({});
                
                foreach(object room in temp2)
                {
                        int size;
                        exits = room->query("exits");
                        
                        foreach(string key in keys(exits))
                        {
                                object _temp;
                                _temp = find_object(exits[key])?
                                        find_object(exits[key]):
                                        load_object(exits[key]);
                                
                                if (_temp->query("short") == name)
                                {
                                        _temp->set_temp("father",room);
                                        n = allocate(2);
                                        n[1] = allocate(sizeof(bak_room));
                                        n[0] = _temp;
                                        n[1] = find_path(n[0],bak_room);
                                        return n;
                                }
                                temp1 += ({ _temp });
                        }
                        size = sizeof(temp1);
                        for(int i=0;i<size;i++)
                        {       
                                object* new_temp = copy(temp1[i]);
                                if ( sizeof(({new_temp}) & bak_room) ) {
                                        temp1[i] = 0;
                                }
                        }
                        temp1 = filter(temp1,(: $1 != 0 :));
                        foreach(object _ob in temp1) _ob->set_temp("father",room);
                        
                        bak_room += temp1;
                        temp += temp1;
                        temp1 = ({});
                } // end of foreach(temp2)
                a++;
        } // end of while
        return 0;
}

private object* find_path(object ob,object* rooms)
{
        object *temp1;
        object temp = copy(ob);
        temp1 = ({});
        
        while(temp)
        {
                object _temp;
                temp1 += ({temp});
                _temp = temp;
                temp = temp->query_temp("father");
                _temp->delete_temp("father");
        }
        
        clean_path(rooms);
        return temp1;
}

void clean_path(object* rooms)
{
        foreach(object room in rooms)
                room->delete_temp("father");
}

