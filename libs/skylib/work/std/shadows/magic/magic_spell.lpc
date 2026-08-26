/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: magic_spell.c,v 1.1 1998/01/06 04:37:11 ceres Exp $
 * $Log: magic_spell.c,v $
 * Revision 1.1  1998/01/06 04:37:11  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

int query_casting_spell() { return 1; }

int queue_commands() { return 1; }

void interrupt_spell() {
   mixed *args;
   args = arg();
   args[ 0 ] = -1 - args[ 0 ];
   args[ 2 ] = ({ });
   set_arg( args );
   remove_this_effect();
} /* interrupt_spell() */
