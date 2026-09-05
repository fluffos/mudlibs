// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void setup()
{
	seteuid(getuid());
    call_out("floatation",1);
}

int floatation()
{
    object ob=this_object();
    int old_value,max_value,min_value,value;
    if (!ob->query("float"))
    {
        old_value=ob->query("value");
        max_value=old_value*6/5;
        min_value=old_value*4/5;
        ob->set("old_value",old_value);
        ob->set("max_value",max_value);
        ob->set("min_value",min_value);
        ob->set("float",1);    
    }
    value=ob->query("value")*(120-random(41))/100;
    if (value>ob->query("max_value")||value<ob->query("min_value"))
    {
        value=ob->query("old_value")*(120-random(41))/100;
    }
    ob->set("value",value);
    remove_call_out("floatation");
    call_out("floatation",3600+random(500));
    return 1;
}
