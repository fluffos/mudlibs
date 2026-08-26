//rm.c

//Tacitus @ LPUniversity
//07-APR-05
//File system management

//Last edited on August 18th, 2006 by Parthenon

string *dir_tree;
string dir;

void start_delete();
void handle_delete(string contents);

int main(string str)
{
    dir_tree = ({});
    
    if (!str)
       return notify_fail("Syntax: rm [-r] <file name>\n");
    
    if(sscanf(str, "-r %s", dir) == 1)
    {
        dir = resolve_path(this_player()->query("cwd"), dir) + "/";
        
        if(!directory_exists(dir))
            return notify_fail(RED + "Error:" + NOR + " [rm]: " + str + " is not a directory.\n");
        
        if(!(int)master()->valid_write(dir, this_player(), "rmdir"))
        {
            write(RED + "Error" + NOR + " [rm]: Permission denied.\n");
            return 1;
        }
        
        dir_tree += ({ dir });
        
        write("Are you sure you about that? ");   
        input_to("i_Confirm");
        return 1;
    }
    
    str = resolve_path(this_player()->query("cwd"), str);
    
    if(directory_exists(str) || !file_exists(str))
        return notify_fail(RED + "Error" + NOR + " [rm]: " + str + " is not a file.\n");
     
    if(!(int)master()->valid_write(str, this_player(), "rm"))
    {
        write(RED + "Error" + NOR + " [rm]: Permission denied.\n");
        return 1;
    }
     
    write(rm(str) ? HIG + "Success" + NOR + " [rm]: File removed.\n" : RED + "Error" + NOR + " [rm]: Could not remove file.\n");
    return 1;
}

void i_Confirm(string arg)
{
    if(!arg || arg == "" || member_array(lower_case(arg), ({ "y", "yes"})) == -1)
    {
        write("Deletion cancelled.\n");
        return;
    }
    
    start_delete();

    return;
}

void start_delete()
{
    mixed *contents;

    do
    {
        contents = get_dir(dir);
        
        if(sizeof(contents) > 0)
            handle_delete(contents[0]);
            
    } while(sizeof(contents) > 0);
    
    write(rmdir(dir) ? HIG + "Success:" + NOR + " [rm]: All files and folders deleted successfully.\n" :
        RED + "Error:" + NOR + " [rm]: All files and folders could not be deleted.\n");
    
    return;
}

void handle_delete(string contents)
{
    if(file_size(implode(dir_tree, "") + contents) == -2)
    {
        dir_tree += ({ contents + "/" });
    
        if(sizeof(get_dir(implode(dir_tree, ""))) == 0)
        {
            if(rmdir(implode(dir_tree, "")))
            {
                dir_tree -= ({ contents + "/" });
                return;
            }
        }
        else
        {
            handle_delete(get_dir(implode(dir_tree, ""))[0]);
            dir_tree -= ({ contents + "/" });
            return;
        }
    }
    else if(file_size(implode(dir_tree, "") + contents) == -1)
    {
        dir_tree -= ({ contents + "/" });
    }
    else
        rm(implode(dir_tree, "") + contents);
}

string help() {
    return (HIW + " SYNTAX: " + NOR + "rm <file name | -r dir name>" + "\n\n" + 
    "This command permanantly removes a file. Please note that there is no\n" +
    "'Recycle Bin'. You must be extra careful when dealing with important files.\n" +
    "You may also use the -r option to recursively remove all files and folders\n" +
    "within <dir name>. It will ask you for a confirmation just to be safe.\n");
}

