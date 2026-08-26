//rmdir.c

//Tacitus @ LPUniversity
//07-APR-05
//File system management

int main(string str)
{
    if(!str) return notify_fail("Syntax: rmdir <directory name>\n");
    str = resolve_path(this_player()->query("cwd"), str);
    if(!directory_exists(str) || file_exists(str)) return notify_fail("Error [rmdir]: " + str + " is not a directory.\n");
    if (sizeof( get_dir(str + "/") )) return notify_fail("Error [rmdir]: " + str + " is not empty.\n");
    if(!(int)master()->valid_write(str, this_player(), "rmdir"))
    {
    write("Error [rmdir]: Permission denied.\n");
    return 1;
    }
    write(rmdir(str) ? "Successful [rmdir]: Directory removed.\n" : "Error [rmdir]: Could not remove directory.\n");
    return 1;
}

string help() {
    return (HIW + " SYNTAX: " + NOR + "rmdir <directory name>" + "\n\n" +
      "This command permanantly removes a specified directory. It will not\n"
      "currently delete a directory that has content (ie. The directory\n"
      "you wish to remove must be empty before it can be deleted.)\n");
}
