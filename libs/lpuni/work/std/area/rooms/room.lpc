/*
    /std/room.c
    Tacitus@TLPUniversity
    Standard room inheritable
    * Special thanks to Icoz@LPUniversity
*/

// Last edited by Tacitus on May 3rd, 2006

#include <config.h>

inherit OBJECT;

mapping exits = ([]), items = ([]);
int light = 1;

int set_exits(mapping exit);
int remove_exit(string id);
int add_exit(string id, string path);
int set_light(int level);
int set_items(mapping itemData);
int remove_item(string id);
int add_item(mixed id, string desc);
int valid_exit(string exit);
int query_light();
int setup();
int query_roomType();
string query_short();
string query_long();
string query_item(string id);
string query_exit(string id);
mapping query_items();
mapping query_exits();

void create()
{
    setup();
}

int setup()
{
    return 1;
}

int query_roomType()
{
    return 1;
}

int set_exits(mapping exit)
{
    exits = exit;
    set("exits", exit);
    return 1;
}

mapping query_exits()
{
     mapping copy;
     copy = exits;
     return copy;
}

string query_exit(string id)
{
     if(sizeof(exits) < 1) return 0;
     if(exits[id]) return exits[id];
}

int valid_exit(string exit)
{
    if(sizeof(exits) < 1) return 0;
    if(exits[exit]) return 1;
    return 0;
}

int remove_exit(string id)
{
    if(sizeof(exits) < 1) return 0;
    if(!exits[id]) return 1;
    else map_delete(exits, id);
    set("exits", exits);
    return 1;
}

int add_exit(string id, string path)
{
     if(exits[id]) map_delete(exits, id);
     exits += ([id : path]);
     set("exits", exits);
     return 1;
}

int set_items(mapping itemData)
{
    mixed id;
    string key;
    mapping item = ([]);

    foreach(id, key in itemData)
    {
        if(arrayp(id))
        {
            int i;
            for(i = 0; i < sizeof(id); i++)
                item += ([id[i] : key]);
        }
        else item += ([id : key]);
    }

    items = item;
    set("items", item);
    return 1;
}

mapping query_items()
{
    mapping copy;
    copy = items;
    return copy;
}

string query_item(string id)
{
    if(items[id])
    {
          if(items[id][0..1] == "@@") return( call_other(this_object(), items[id][2..(strlen(items[id])-1)]));
          else return items[id];
    }
}


int remove_item(string id)
{
     if(!items[id]) return 1;
     map_delete(items, id);
     set("items", items);
     return 1;
}

int add_item(mixed id, string desc)
{

     if(arrayp(id))
     {
         int i;

         for(i = 0; i < sizeof(id); i++)
         {
             if(items[id[i]]) map_delete(items, id);
             items += ([id[i] : desc]);
         }
         set("items", items);
     }
     else
     {
         if(items[id]) map_delete(items, id);
        items += ([id : desc]);
        set("items", items);
     }
     return 1;
}

int set_light(int level)
{
    light = level;
    set("light", level);
    return 1;
}

int query_light()
{
    if(!light) return query("light");
    return light;
}

string query_short()
{
    if(::query_short()) return ::query_short();
    else return query("short");
}

string query_long()
{
    if(::query_long()) return ::query_long();
    else return query("long");
}

int receive_object(object ob)
{
     return 1;
}

int release_object(object ob)
{
     return 1;
}
