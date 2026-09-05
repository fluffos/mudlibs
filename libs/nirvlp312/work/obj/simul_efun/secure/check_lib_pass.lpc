/*
 *      File:                   /obj/simul_efun/secure/check_lib_pass.c
 *      Function:               Simul efun for checking password for editing lib files
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/24/06
 *      Notes:                  
 *      Change History:
 */

#define LIB_PASSWORD "VEINC8wKJd/wY"

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

nomask 
status check_lib_pass(string arg)
{
  return arg == LIB_PASSWORD;
}

nomask
varargs mixed unguarded(closure arg, mixed arg2, mixed arg3)
{
  if (arg && arg2 && arg3) return apply(arg, arg2, arg3);
  if (arg && arg2) return apply(arg, arg2);
  if (arg) return apply(arg);
  return 0;
}
