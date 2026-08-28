/*
 * command                       /command/immortal/more.c
 * description                   the tool for viewing files
 * coder                         dazzt
 * */

#define MORE_OBJ "/obj/more"

main(string args)
{
	object ob;
	
    if (!args)
    {        
		notify_fail("usage: more <file>\n");
		return 0;
    }

/*
    if (!absolute_path(args))
		args = THIS->query_cwd() + args;

    args = resolve_path(args);
*/
    args = true_path(args);

    if (file_size(args) < 0)
    {
		notify_fail(args + ": file not found.\n");
		return 0;
    }

	ob = clone_object(MORE_OBJ);
    ob->more(args);
    return 1;
}

int
main_string (string str)
{
  object ob;

  ob = clone_object(MORE_OBJ);
  ob->more_string (str);
  return 1;
}
