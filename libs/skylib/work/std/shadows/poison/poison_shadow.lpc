/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: poison_shadow.c,v 1.1 1998/01/06 04:44:00 ceres Exp $
 * $Log: poison_shadow.c,v $
 * Revision 1.1  1998/01/06 04:44:00  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

string my_type;


int query_addiction(string type){
   if (my_type == type) return 1; 
   return 0;
}

int set_addiction(string type){
   my_type = type;
   return 1;
}
