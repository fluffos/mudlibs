#define MAX_TRIGGERS 20 
 
mapping trigger; 
nosave int      allow_trigger; 
 
int set_trigger(string verb, string replace) 
{ 
        if( !replace ) { 
                if( mapp(trigger) ) map_delete(trigger, verb); 
                return 1; 
        } else { 
                if( !mapp(trigger) ) trigger = ([ verb:replace ]); 
                else if( sizeof(trigger) > MAX_TRIGGERS ) 
                        return notify_fail("您设定的 trigger 太多了，请先删掉一些不常用的。\n"); 
                else trigger[verb] = replace; 
                return 1; 
        } 
} 
 
mapping query_all_trigger() 
{ 
        return trigger; 
} 
 
void disable_trigger() 
{ 
        allow_trigger = 0; 
} 
 
void enable_trigger() 
{ 
        allow_trigger = 1; 
} 
 
int query_trigger_enabled() 
{ 
        return allow_trigger; 
} 
 
int fire_trigger(string pattern) 
{ 
        string cmd,*patterns; 
        int i,s; 
        object me; 
         
        if( !allow_trigger ) return 0; 
        me = this_object(); 
        if( me->query_temp("parseing") ) return 0; 
        if( !mapp(trigger) ) return 0; 
        pattern = replace_string(pattern,"> ",""); 
         
        patterns = keys(trigger); 
        s = sizeof(patterns); 
        for(i=0;i < s;i++) 
        { 
         
                if( strsrch(pattern,patterns[i]) != -1 || regexp(pattern,patterns[i]) ) 
                { 
                        cmd = trigger[patterns[i]];              
                        if( stringp(cmd) ) 
                        { 
                                if( cmd == "$gag" ) return -999; 
                                //防止有人用quit来避免死亡 
                                me->check_status(); 
                                me->set_temp("parseing",1);              
                                tell_object(me,"触发指令："+cmd+"\n");                   
                                command( me->process_input(cmd) ); 
                                me->delete_temp("parseing"); 
                                return 1; 
                        }        
                } 
        } 
        return 0; 
 
} 
