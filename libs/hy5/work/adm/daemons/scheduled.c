// Rewritten by Lonely@nitan3

#include <ansi.h>

#define EVENT_LOOP              0
#define EVENT_EUID              1
#define EVENT_CUR_TIME          2
#define EVENT_MAX_TIME          3
#define EVENT_OBJECT            4
#define EVENT_FUNCTION          5
#define EVENT_ARGUMENT          6
#ifdef DEBUG
#define monitor(x)              CHANNEL_D->do_channel(this_object(), "sys", x)
#else
#define monitor(x)
#endif

inherit F_DBASE;

static int last_update_time;
static int handle_id;
static mapping events = allocate_mapping(0);

int clean_up() { return 1; } 

void remove(string euid)
{
        if( !this_player() )
                return;

        if( sizeof(events) > 0 )
                error("排程精灵：目前正在执行排程系统，你不能摧毁排程精灵。\n");
}

int mapping_eqv(mapping m1, mapping m2);
int array_eqv(mixed arr1, mixed arr2)
{
        int s_arr = sizeof(arr1);
        if( s_arr != sizeof(arr2) ) return 0;
        if( s_arr < 1 ) return 1;
        for(int i=0; i<sizeof(arr1); i++)
        {
                if( arrayp(arr1[i]) && arrayp(arr2[i]) )
                {
                        if( !array_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( mapp(arr1[i]) && mapp(arr2[i]) )
                {
                        if( !mapping_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( arr1[i] != arr2[i] ) return 0;
        }
        return 1;
}

int mapping_eqv(mapping map1, mapping map2)
{
        int m_arr = sizeof(map1);
        mixed m_keys1, m_keys2;

        if( m_arr != sizeof(map2) ) return 0;
        if( m_arr < 1 ) return 1;
        m_keys1 = keys(map1);
        m_keys2 = keys(map2);

        for(int i=0; i<sizeof(m_keys1); i++)
        {
                if( mapp(m_keys1[i]) && mapp(m_keys1[i]) )
                {
                        if( !mapping_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( arrayp(m_keys1[i]) && arrayp(m_keys2[i]) )
                {
                        if( !array_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( m_keys1[i] != m_keys2[i] )
                {
                        return 0;
                }
                
                // Value check
                if( mapp(map1[m_keys1[i]]) && mapp(map2[m_keys2[i]]) )
                {
                        if( !mapping_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( arrayp(map1[m_keys1[i]]) && arrayp(map1[m_keys1[i]]) )
                {
                        if( !array_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( map1[m_keys1[i]] != map2[m_keys2[i]] ) return 0;
        }
        return 1;
}
int evaluate_event(int id)
{
        mixed event;

        if( undefinedp(event = events[id]) ) return 0;
        if( !event[EVENT_OBJECT] ) return 0;
        if( !event[EVENT_EUID] ) return 0;

        seteuid(event[EVENT_EUID]);

        if( functionp(event[EVENT_OBJECT]) )
        {
                monitor(sprintf("执行函数 %O", event[EVENT_OBJECT]));
                evaluate(event[EVENT_OBJECT]);
        }
        else
        {
                mixed args = ({ event[EVENT_FUNCTION] }) + event[EVENT_ARGUMENT..sizeof(event)-1];
                monitor(sprintf("执行 %O->%s", event[EVENT_OBJECT], event[EVENT_FUNCTION]));
                // monitor(sprintf("call_other(%O, %O)", event[EVENT_OBJECT], args));
                call_other(event[EVENT_OBJECT], args);
        }

        seteuid(ROOT_UID);
        return 1;
}

mixed query_events()
{
        return events;
}

varargs int set_event(mixed time, int loop, mixed ob, mixed func, mixed args...)
{
        mixed event;

        if( !ob ) error("参数过少");
        if( functionp(ob) )
                event = ({ loop, geteuid(previous_object()), 0, time, ob });
        else
                event = ({ loop, geteuid(previous_object()), 0, time, ob, func }) + args;

        // Added by Lonely
        foreach( int id, mixed et in events )
                if( et[EVENT_LOOP] == event[EVENT_LOOP] &&
                    et[EVENT_EUID] == event[EVENT_EUID] &&
                    array_eqv(et[EVENT_MAX_TIME..sizeof(event)-1],
                    event[EVENT_MAX_TIME..sizeof(event)-1]) )
                        map_delete(events, id);

        events[handle_id] = event;

        // if( event[EVENT_LOOP] ) evaluate_event(handle_id);
        return handle_id++;
}

void delete_event(int handle)
{
        if( !undefinedp(events[handle]) )
                map_delete(events, handle);
}

void delete_events()
{
        events = allocate_mapping(0);
}

void check_event()
{
        foreach(int id, mixed event in events)
                if( !event[EVENT_OBJECT] )
                        // 删除已遗失物件或函式指标的事件
                        map_delete(events, id);
}

mixed query_event(int handle)
{
        return events[handle];
}

void heart_beat()
{
        int i;

        if( !sizeof(events) ) return;
        if( !last_update_time ) last_update_time = time();

        i = time() - last_update_time;  // 记算每次心跳之时间差
        last_update_time = time();      // 记录最后一次心跳时间

        foreach(int id, mixed event in events)
        {
                if( undefinedp(events[id]) ) continue; 
                if( !event[EVENT_OBJECT] )
                {       // 删除已遗失物件或函式指标的事件
                        map_delete(events, id);
                        continue;
                }
                if( event[EVENT_CUR_TIME] < event[EVENT_MAX_TIME] )
                {       // 未超过事件循环时间
                        event[EVENT_CUR_TIME] += i;
                }
                else
                {       // 已超过事件循环时间
                        evaluate_event(id);
                        event[EVENT_CUR_TIME] = 0;
                        if( !event[EVENT_LOOP] ) map_delete(events, id); // 执行后删除
                }
        }
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "排程精灵");
        monitor("排程系统已经启动。");
        // CHANNEL_D->do_channel(this_object(), "sys", "排程系统已经启动。");

        set_heart_beat(1);
}

void start_events()
{
        if (! query_heart_beat())
                set_heart_beat(1); 
}
