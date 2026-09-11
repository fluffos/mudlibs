// id.c  
// created by tset 1/16/98
// last updated by tset 11/30/98

#include <mudlib.h>
inherit CMD;

private void main(string arg)
{
    int i;
    object *inv;
     
    if (!arg)
    {
        inv =  all_inventory(this_body());
        if( !sizeof(inv) ) {
            write("你（"+implode(this_body()->query_id(), ", ")+"）身上没有任何东西。\n");
            return;
        }
         
        printf("你（"+implode(this_body()->query_id(), ", ")+"）身上携带物品的别称如下 :\n");
        for( i=0; i < sizeof(inv); i++)
        {
            if( !this_body()->is_visible(inv[i]) ) continue;
            printf("%s\n", implode(inv[i]->query_id(), ", ") );
        }
    }
    else if(arg == "here")
    {
        inv =  all_inventory(environment(this_body()));
	/* does this case ever happen? */
        if( !sizeof(inv) ) {
	    write("这里（"+implode(environment(this_body())->query_id(),", ")+"）没有任何东西。\n");
            return;
        }
        write("在这个房间中（"+implode(environment(this_body())->query_id(),", ")+"）, \n生物及物品的名称如下 :\n");
        for( i=0; i < sizeof(inv); i++)
        {
            if( !this_body()->is_visible(inv[i]) ) continue;
            printf("%s\n", implode(inv[i]->query_id(), ", ") );
        }
    }
    else
        printf("用法: id, id here\n");

    return;
}           
            
