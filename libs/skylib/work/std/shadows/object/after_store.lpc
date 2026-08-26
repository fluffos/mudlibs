/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: after_store.c,v 1.1 1998/01/06 04:40:23 ceres Exp $
 * $Log: after_store.c,v $
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
/* This shadow is for keeping the do_use function defined in an
 * object that used to have the store_ritual effect, and therefore has
 * an add_action/add_command that would otherwise give errors.
 */
int setup_shadow( object ob ) {
   shadow( ob );
} 

int query_do_use_save() {
   return 1;
}

int remove_do_use_save() {
   destruct( this_object() );
   return 1;
}

int do_use( string words ) {
   return 0;
} /* do_use */

