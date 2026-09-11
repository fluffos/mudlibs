// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  a room.c
// Rust@ZorkMUD,   Jan 12, 1994
// Nevyn@GUE       1-14-94
// Cleave@ZorkMUD 2-25-94 Added long(), long default.
// Beek@ZorkMud   4-6-94  Added the way cool exit code.  Look at the
//      lfun docs.
// Rust wrote in_room stuff to make looking in rooms more interesting
// Beek & Rust have both done a bit of work on this since....
// August 24 - Beek added light
// Satan@ArcadiaF 10-29-95 Added the OBVIOUS_EXITS_BOTTOM, casue I don't like
//      the way the exits look on the top, and Beek didn't want to fix it.
// Satan@ArcadiaF 10-30-95 Added set_hidden_exits(). This makes a list that
//      of exits that are hidden from all in the room.
//      Wizards can see DARK_EXITS as they are denoted with a *name format.
// 951113, Deathblade: removed some obsolete vars; made them all private

#include <setbit.h>
#include <move.h>
#include <hooks.h>

inherit CONTAINER;
inherit M_ITEMS;
inherit M_GETTABLE;
inherit M_MEETPLACE;
inherit __DIR__ "room/exits";
inherit __DIR__ "room/roomdesc";

private nosave string area_name;
private int height = 0;

//:FUNCTION stat_me
//Writes some debugging info about the object.  Shows the container info,
//as well as the short and exits.
int stat_me() {
    printf("房间: %s [ %s ]\n\n",
      short(), implode(query_exit_directions(1), ", "));
    container::stat_me();
    return 1;
}
/*
void create_board()
{
   string p_area,p_room;
   p_area=this_object()->get_area();
   p_room=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"meeting");
   if(p_room==file_name()) 
   {
        string nation;
        nation=AREA_D->get_area(p_area,"nation");
        if(COUNTRY_D->nation_exist(nation))
        {
             NEWS_D->add_nation_group("nation."+nation);
             this_object()->set_objects(([M_BOARD : 
               ({ 1,COUNTRY_D->get_country(nation,"name")+"通告", "nation."+nation })]) );
             return;
        }
   }
   p_room=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"fly");
   if(p_room==file_name()) 
        this_object()->set_objects(([M_BOARD : ({ 1,"三国榜文", "caolu" }) ]) );
}
*/
//:FUNCTION set_brief
//Set the name of the room seen at the top of the description and in brief mode
void set_brief(string str) {
    set_proper_name(str);
}


//:FUNCTION can_hold_water
//Return 1 if the object can hold water.
/* by default, rooms can hold water */
int can_hold_water()
{
    return 1;
}
/* use new system to replace this one
void create_chars()
{
	string m_name;
        mixed list;
	int i;
	m_name=file_name();
	list=CHAR_D->check_char("room",m_name);
	for(i=0;i<sizeof(list);++i)
	{
		CHAR_D->put_char(list[i],m_name);
	}	
	list=TROOP_D->check_troop("room",m_name);
	for(i=0;i<sizeof(list);++i)
		TROOP_D->put_troop(list[i],m_name);
}
*/
void create()
{
    container::create();
    exits::create();

    // cloned rooms will already have this stuff happen... We need this
    // because setup() is the way people configure mudlib objects.
    // Almost always, except in the case of rooms, game objects are clones.
    if( !clonep(this_object()) )
    {
    // initialize the mudlib (default) stuff, then the area coder's
    mudlib_setup();
    this_object()->internal_setup();

    setup();
    }
//    create_chars();
//    create_board();
}

void mudlib_setup()
{
    ::mudlib_setup();
    set_light(DEFAULT_LIGHT_LEVEL);
    set_max_capacity(1000000);
    add_id("environment", "空地");
    //set_getmsg( "A surreal notion.\n");
    set_getmsg( "幻像。\n");
    set_gettable( -1 );
    set_flag( ATTACHED );
}

//:FUNCTION set_area
//Used by weather to know which rooms are the same as this one.
void set_area(string name)
{
    area_name = name;
}
void set_height(int h)
{
  height = h;
}

int query_height()
{
  return height;
}

//:FUNCTION set_area
//Find out what 'area' the room belongs to.  See set_area.
string get_area()
{
    return area_name;
}

string query_name ()
{
    //return "the ground";
    return "地面。\n";
}

// Conflict resolution
string long()
{
    return roomdesc::long();
}

string get_brief()
{
    return short();
}


mixed direct_get_obj( object ob, string name )
{
    if( this_object() == environment( this_body()))
        //return "A surreal idea.\n";
        return "幻像。\n";
    return ::direct_get_obj( ob, name );
}
/*
string query_board()
{
   string p_area,p_room;
   p_area=this_object()->get_area();
   p_room=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"meeting");
   if(p_room==file_name()) 
   {
        string nation;
        nation=AREA_D->get_area(p_area,"nation");
        if(COUNTRY_D->nation_exist(nation))
        return "nation."+nation;
   }
   p_room=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"fly");
   if(p_room==file_name()) 
        return "caolu";
   return "";
}

*/
