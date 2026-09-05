/*
 *      File:                   /obj/simul_efun/secure/file_handling.c
 *      Function:               Efun overrides for filehandling functions
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  
 *      Change History:
 */

#include <security.h>
#define LIB_PASSWORD "VEINC8wKJd/wY"

/* Global Variables */
status  password_given;
mapping reserved_privileges;

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
 
nomask status check_password(string pass)
{
  password_given = (crypt(pass, LIB_PASSWORD[0..1]) == LIB_PASSWORD ? 1 : 0);
#ifdef DEBUG
if (password_given)
write("PASSWORD GIVEN: THE MONKEY HAS LEFT THE BUILDING AND THE NACHOS ARE IN THE HAMPER.\n");
#endif
  return password_given;
}

nomask status check_password_given() 
{ 
  return password_given;
}

nomask mixed file_arg_check(string arg)
{
  string arg1, arg2, arg3;
  int i;
  status flag;

  flag = 0;
    
  if (!arg || arg == "")
    ;
  else if (sscanf(arg, "%s %s", arg1, arg2) != 2)
  {
    if (check_password(arg))
    {
      flag = 1;
      arg = 0;
    }
  }
  else if (sscanf(arg2, "%s %s", arg2, arg3) != 2)
  {
    if (check_password(arg1))
    {
      flag = 1;
      arg = arg2;
    }
    else if (check_password(arg2))
    {
      flag = 1;
      arg = arg1;
    }
  }
  else
  {
    if (check_password(arg1))
    {
      flag = 1;
      arg = sprintf("%s %s", arg2, arg3);
    }
    else if (check_password(arg2))
    {
      flag = 1;
      arg = sprintf("%s %s", arg1, arg3);
    }
    else if (check_password(arg3))
    {
      flag = 1;
      arg = sprintf("%s %s", arg1, arg2);
    }
  }
  
  password_given = flag;
  return arg;
}

nomask void reserve_ed_privileges(object ob, string arg)
{
  if (!arg)
    return;
    
  if (!reserved_privileges)
    reserved_privileges = ([ ob : arg ]);
  else reserved_privileges[ob] = arg;
}

nomask status query_reserved_ed_privileges(object ob, string arg)
{
  status flag;
  
  if (!reserved_privileges || member(reserved_privileges, ob) < 0)
    return 0;
   
  flag = reserved_privileges[ob] == arg;
  reserved_privileges[ob] = 0;
  return flag;
}

nomask status privileged_object(object ob, string fun_name, string arg)
{
  string what_to_log,
         ob_name,
         ob_dir,
         arg_dir,
         orig_arg,
         junk1, junk2;
         
  if (ob)
    ob_name = object_name(ob);
    
  orig_arg = arg;
  sscanf(arg, "%s %s", junk1, arg);
  
  /* Files within player dirs have full access within their own dirs */
  if (sscanf(arg,     "/players/%s/%s", arg_dir, junk1) == 2
  &&  sscanf(ob_name,  "players/%s/%s", ob_dir,  junk2) == 2
  && arg_dir == ob_dir)
    return 1;

  /* See if it's a privileged object */    
  if (ob_name && 
  (   strstr(ob_name, "bin/wiz/"     ) == 0
  ||  strstr(ob_name, "secure/master") == 0
  ||  strstr(ob_name, "obj/autoshut" ) == 0
  ||  strstr(ob_name, "obj/shut"     ) == 0
  ||  strstr(ob_name, "obj/player"   ) == 0 ))
    return 1;
    
  /* Log it so potential issues and illegal access attempts can be identified */
  what_to_log = sprintf("%s: %s (%s) called by %s.\n", ctime(), fun_name,
  (arg ? arg : "unknown"), sprintf("%s(%s)", object_name(ob), 
  (ob && living(ob) ? (string)ob->query_real_name() : "")));
write(what_to_log);
  printf("Error: %s must be called from the wizard commands or be privileged.\n", fun_name);
  write_file("/log/SFUNS", what_to_log);
  return 0;
}

/*
 * Overrides on the efuns themselves.
 */
nomask int copy_file(string from, string to)
{
  if (privileged_object(previous_object(), "copy_file", sprintf("%s %s", from, to)))
    return efun::copy_file(from, to);
    
  return 1;
}

nomask int rename(string from, string to)
{
  if (privileged_object(previous_object(), "rename", sprintf("%s %s", from, to)))
    return efun::rename(from, to);
    
  return 1;
}

nomask int rm(string file)
{
  if (privileged_object(previous_object(), "rm", file))
    return efun::rm(file);
    
  return 1;
}

nomask int rmdir(string file)
{
  if (privileged_object(previous_object(), "rmdir", file))
    return efun::rmdir(file);
    
  return 1;
}

nomask int mkdir(string file)
{
  if (privileged_object(previous_object(), "mkdir", file))
    return efun::mkdir(file);
    
  return 1;
}
