#include <std.h>

inherit OBJECT;

int tug_me(string);
mixed* query_array();
string query_val();

mixed* arr;

void create() {
    ::create();
    set_name("doll");
    set_id(({ "doll", "test doll" }));
    set_short("a test doll");
    set_long("A doll that is used to perform various tests." +
        "It has a pullstring on the back. Perhaps you could " +
        "<tug> the string?");
    set_weight(60);
    set_curr_value("gold", 100 + random(51));
    arr = ({});
}

void init()
{
    ::init();
    add_action("tug_me", "tug");
}

int tug_me(string str)
{
    string* sars = ({});
    
    if( !str )
        return notify_fail("Hey!\n");
    
    if( member_array(',', str) != -1 )
    {
        sars = explode(str, ",");
        arr += ({ sars });
    }
    else
    {
        arr += ({ str });
    }
    
    return 1;
}

mixed* query_array()
{
    return arr;
}

string query_val()
{
    int tmp = sizeof(arr);
    string ret = "";
    
    for(int i = 0; i < tmp; i++)
    {
        if( arrayp(arr[i]) )
            ret += implode(arr[i], ",");
        else
            ret += arr[i];
    }
    
    return ret;
}

