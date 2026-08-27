/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : _clean_up.c
 * Author : Clode@RevivalWorld
 * Date   : 2001-10-10
 * Note   : clean_up
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define NEVER_AGAIN	0
#define	AGAIN		1

int clean_up( int inherited )
{
	if( environment() )
		return AGAIN;

	if( inherited || !clonep() ||
		this_object()->is_module_room() ||
		this_object()->is_module_object() ||
		this_object()->is_module_npc() ||
		this_object()->is_board()
		)
		return NEVER_AGAIN;

	foreach(object inv in all_inventory())
		if( userp(inv) ) return AGAIN;
		
	destruct(this_object());

	return NEVER_AGAIN;
}
