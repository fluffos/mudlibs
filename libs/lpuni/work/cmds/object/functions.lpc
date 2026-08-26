/*

  functions.c
  Parthenon@LPUniversity
  August 16th, 2006
  command to list functions contained in an object

*/

int main(string arg)
{
    object ob, pager;
    string *funcs, ret;

    if(!arg || arg == "")
    return notify_fail(RED + "Error:" + NOR + " [functions]: SYNTAX: functions <object id>|<filename>.\n");
    ob = present(arg);

    if(!ob)
    ob = present(arg, environment(this_player()));

    if(!ob)
    ob = find_object(arg);

    if(!ob)
    return notify_fail(RED + "Error:" + NOR + " [functions]: Could not find object " + arg + ".\n");

    funcs = functions(ob);
    funcs = sort_array(funcs, 1);

    ret = sprintf("%-#79.3s\n\n", implode(funcs, "\n"));

    pager = clone_object(OBJ_PAGER);

    pager->page(ret);
    return 1;
}

string help()
{
    return
    " SYNTAX: functions <object>\n\n" +
    "This command will show the functions contained in <object>\n" +
    "You may use the id of the object if it is in your\n" +
    "inventory or environment, otherwise you may use the\n" +
    "filename of the object to try and locate it.\n";
} 

