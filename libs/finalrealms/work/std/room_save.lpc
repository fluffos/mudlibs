// Taniwha, added checks for OMIQ in progress "/global/omiq"->flag_in_progress(). restore/save disabled during OMIQ's
#define MAXINV 40
// Inherit this to get your rooms to save objects through reboots.
// ANY object, NPCs, weapons, armours ... whatever.  Best example
// would be a dragon hoard.   Original code was done by Taniwha and
// Raisa, January 5, 1996
//
// In your setup(): 
//   set_void(string path);
//     Use this to make a destination for players in case of reboot
//     Generally make it an adjoining room.  Do NOT make the destination
//     a room_save.c as well.  Bad things happen...
//
// Mask the dest_me() if you want to do some house cleaning or personal
// code to the room just before the contents are saved.  Be sure to 
// return ::dest_me(); to the mudlib.
//
// Any immortal using this room needs to have approval beforehand
// by a Demi-god.
//
//Radix, Jan 6, 1996

inherit "/std/room";
inherit "/global/auto_load";

string *auto_load, voidpath;

int query_saveroom() { return(1); }
void set_void(string path) { voidpath = path; }
int maxinv;

void create()
{
    object *olist;
    maxinv = MAXINV;
    ::create();
    auto_load = ({ });
    if(!"/global/omiq"->flag_in_progress())
    {
	seteuid("Root");
	restore_object(file_name(this_object()),1);
	if(sizeof(auto_load))  
	    olist = load_auto_load(auto_load,this_object());
// can't see the purpose of the assignment above, given
// that the var is local -randor
    }
}
int test_add(object ob,int flag)
{
    if(ob && !interactive(ob))
    {
	if(sizeof(all_inventory(TO)) > maxinv) return 0;
    }
    return ::test_add(ob,flag);
}


void dest_me()
{
    int i;
    object dst;
    object *olist = all_inventory(this_object());

    // ugly as hell
    for(i = 0; i < sizeof(olist); i++) 
	if(interactive(olist[i])) 
	{
	    if(!voidpath) olist[i]->move("/room/void");
	    else
	    {
		dst = load_object(voidpath);
		if(!dst || dst->query_saveroom()) 
		    olist[i]->move("/room/void");
		else
		    olist[i]->move(dst);
	    }
	}
    olist = all_inventory(this_object());
    if(sizeof(olist)) 
	auto_load = create_auto_load(olist);
    else auto_load = 0;
    if(!"/global/omiq"->flag_in_progress())
	save_object(file_name(this_object()),1);
    ::dest_me();
}

