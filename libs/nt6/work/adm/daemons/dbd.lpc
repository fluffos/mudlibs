#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;


void create()
{
        seteuid(getuid());
        restore();
}

public string query_save_file() { return DATA_DIR "dbd"; }

int set_data(string prop, mixed data)
{
        set(prop, data);
        save();
        return 1;
} 

mixed query_data(string arg)
{
        if (query(arg)) return query(arg);

        return 0;               
}

mixed add_data(string prop, mixed data)
{
        mixed old;
        
        if( !(old = query_data(prop)) ) 
                return set_data(prop, data); 

        return set(prop, old + data); 
}

int delete_data(string str)
{
        delete(str);
        save();

        return 1;
}

void remove()
{
        save();
}
