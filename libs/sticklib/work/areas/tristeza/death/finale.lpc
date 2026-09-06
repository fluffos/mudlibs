/* The finale : Death has summoned the players */
#include <room.h>
#include <areas.h>
#define CHURCH	"/room/church"
#define VOID	"/room/void"

void
create_room()
{
    set_short("Swirling Chaos");
    set_long("You are floating in the Swirling Chaos of the Abyss,\
 hopelessly lost.");
    set(ROOM_WD,WD_NONE);
    set(PREVENT_TELEPORT);
    call_out("check_this_out",5);
}

check_this_out()
{
    object *inv,*inv2;
    int i,j;

    inv = all_inventory(this_object());

    for(i=0;i<sizeof(inv);i++)
	if(living(inv[i]))
	{
	    if(!present("deaths_item",inv[i]))
	    {
		inv[i]->tell_me(
		  "Death arrives.\nDeath looks at you and laughs.");
		inv[i]->tell_me("You are teleported.");
		move_object(inv[i],CHURCH);
	    }
	    else
	    {
		inv[i]->tell_me(
		  "Death arrives.\nDeath says: SO YOU ARE THE THIEF! GIVE ME THOSE!");
		inv2 = deep_inventory(inv[i]);
		for(j=0;j<sizeof(inv2);j++)
		    if(inv2[j]->id("deaths_item"))
		    {
			inv[i]->tell_me("Death takes "+inv2[j]->short()+".");
			transfer(inv2[j],VOID);
			destruct(inv2[j]);
		    }
		inv[i]->tell_me(
		  "Death says: LET THAT BE THE LAST TIME YOU DO THAT");
		inv[i]->tell_me("You are teleported.");
		move_object(inv[i],CHURCH);
		(AREA_TRISTEZA+"death/death_room")->new_death(); /* Refresh death */
	    }
	} 
    call_out("check_this_out",5);
}
