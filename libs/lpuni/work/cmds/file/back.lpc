/*

  bk.c
  Parthenon@LPUniversity
  August 19th, 2006
  Command to backup a file

*/

int main(string arg)
{
    if(!arg || arg == "")
    return notify_fail(RED + "Error" + NOR + " [back]: Syntax: back <file name>.\n");

    arg = resolve_path(this_player()->query("cwd"), arg);

    if(!file_exists(arg))
    return notify_fail(RED + "Error" + NOR + " [back]: That file does not exist.\n");

    if(!(int)master()->valid_write(arg, this_player(), "cp"))
    return notify_fail(RED + "Error" + NOR + " [back]: Permission denied.\n");

    write(cp(arg, arg + ".bak") ? HIG + "Success" + NOR + " [back]: File successfully backed up.\n" :
      RED + "Error" + NOR + " [back]: File could not be backed up.\n");

    return 1;
}

string help()
{
    return
    HIW + " SYNTAX:" + NOR + " back <filename>\n\n" +
    "This command allows you to create a backup copy of a file.\n" +
    "It will create a copy with the <filename> of '<filename>.back.\n";
}


