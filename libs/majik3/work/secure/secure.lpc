#include <security.h>

int
valid_save_binary ()
{
  return 1;
}

int
valid_shadow (object ob)
{
  return 1;
}

int
valid_author (string name)
{
  return 1;
}

int
valid_override (string file, string name)
{
  return 1;
}

int
valid_seteuid (object ob, string str)
{
  return 1;
}

int
valid_domain (string domain)
{
  return 1;
}

int
valid_socket (object eff_user, string fun, mixed * info)
{
  return 1;
}

int
valid_compile_to_c()
{
  return 1;
}

int valid_write (string, mixed, string);

int
valid_read (string file, mixed user, string func)
{
	int i;

	if (func == "file_size" ||
		func == "restore_object" ||
		func == "stat")
		return 1;
	
//	i = call_other("/daemon/security", "query_valid", file, 0);
//	if (i == 0)
//		write("Permission denied.\n");

//	return i;
	return 1;
}

int
valid_write (string file, mixed user, string func)
{
	string s2, s3;
	int i;

  if (objectp(user) && user->query_security() > 50)
    return 1;

  if (objectp(user) && file_name(user)[0..6] == "/secure")
    return 1;

  if (func == "file_size" || func == "stat")// || func == "save_object")
    return 1;

  if (file[0..4] == "/data")
    return 1;

  if (file[0..8] == "/binaries")
    return 1;

  if (file[0..4] == "/open")
    return 1;

  if (file == "/CHANGES")
    return 1;

  if (file[0..3] == "/log")
    return 1;

  if (file[0..3] == "/www")
    return 1;

  if (file[0..4] == "/home")
    {
      if (sscanf (file, "/home/%s", s2) == 1)
        {
          if (s2[<1] == '/')
            s2 = s2[0..<2];

          if (objectp(user) && s2 == user->query_true_name())
            return 1;

          if (user->query_security() > 30)
            return 1;
        }

      if (sscanf (file, "/home/%s/%s", s2, s3) == 2)
        {
          if (objectp(user) && s2 == user->query_true_name())
            return 1;

          if (user->query_security() > 30)
            return 1;
        }
    }
return 1;
/*
  write ("Unable to access "+file+": Permission denied.\n");
  write ("func: "+func+"\n");
  write ("user: ");
  write (user);
  write ("\n");*/

//	i = call_other("/daemon/security", "query_valid", file, 1);
//	if (i == 0)
//		write("Permission denied.\n");

//	return i;
 
}
