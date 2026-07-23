#include <room.h>

nosave mapping doors;

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
        if( !mapp(doors) || undefinedp(doors[dir]) )
                return "你要看什么？\n";
        if( doors[dir]["status"] & DOOR_CLOSED )
                return "这个" + doors[dir]["name"] + "是关着的。\n";
        else
                return "这个" + doors[dir]["name"] + "是开着的。\n";
}

varargs int open_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("这个方向没有门。\n");

        if( !(doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "已经是开着的了。\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: open_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
                message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
        else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
        }

        doors[dir]["status"] &= (!DOOR_CLOSED);
        return 1;
}

varargs int close_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("这个方向没有门。\n");

        if( (doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "已经是关着的了。\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: close_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
                message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
        else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
        }

        doors[dir]["status"] |= DOOR_CLOSED;
        return 1;
}

int check_door(string dir, mapping door)
{
        // If we have no responding door, assume it is correct.
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

        door["status"] = doors[dir]["status"];
        return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
        mapping d, exits, item_desc;
        object ob;

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: create_door: attempt to create a door without exit.\n");

        // Compact mode.
        if( stringp(data) ) {
                d = allocate_mapping(4);
                d["name"] = data;
                d["id"] = ({ dir, data, "door" });
                d["other_side_dir"] = other_side_dir;
                d["status"] = status;
        } else if( mapp(data) )
                d = data;
        else
                error("Create_door: Invalid door data, string or mapping expected.\n");

        set("item_desc/" + dir, (: look_door, dir :) );

        if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->check_door(other_side_dir, d) )
                        return;
        }

        if( !mapp(doors) ) doors = ([ dir: d ]);
        else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
        else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
        if( mapp(doors) && !undefinedp(doors[dir]) ) {
                if( doors[dir]["status"] & DOOR_CLOSED ) {
                    if(!userp(me)) {// allow npc to open doors.
                                    // mon 1/21/99
                        me->command("open "+
                                doors[dir]["name"]);
                        if(!(doors[dir]["status"] & DOOR_CLOSED))
                            return 1;
                    }

                    return notify_fail(
                            "你必须先把" + doors[dir]["name"] + "打开！\n");
                }
                // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
        }
        return 1;
}

