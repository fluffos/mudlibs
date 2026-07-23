/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : _keep.c
 * Author : Clode@RevivalWorld
 * Date   : 2006-01-21
 * Note   :
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

int is_keeping()
{
	return query_temp("keep");
}

varargs void set_keep(int level)
{
	if( !undefinedp(level) )
		set_temp("keep", level);
	else
		set_temp("keep", 1);
}

void delete_keep()
{
	delete_temp("keep");
}

