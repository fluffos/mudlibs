#pragma strict_types
// Apr 17, 1996 Hazard      Added event inform
// Apr 21, 1996 Hazard      Changed creator informs to call get_cre_list
//                          in user_handler instead of users()
// 1996 May 03 Laggard      new log_file_time().
//                          cleaned up code somewhat.

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
 
void setup()
{
    position = 1;
}

protected int cmd(string str, object me)
{
    string *filenames, dest, *fnames;
    int loop, fs;
 
    if (this_player(1) != this_player())
    {
        return 0;
    }
 
    if(!str)
    {
        notify_fail("Usage : mv file [file|dir...]\n");
        return 0;
    }

    fnames = explode(str, " ");
    filenames = this_player()->get_files(implode(fnames[0..sizeof(fnames)-2], " "));

    if(!sizeof(filenames))
    {
        notify_fail("Usage : mv file [file|dir...]\n");
        return 0;
    }
    dest = fnames[sizeof(fnames) - 1];
    dest = this_player()->get_path(dest);
    if(!dest)
    {
        write("No destination\n");
        return 1;
    }
    for(loop = 0; loop < sizeof(filenames); loop++)
    {
        str = filenames[loop];
        if(file_size(str) == -1)
        {
            write("No such file : " + str + "\n");
            continue;
        }
        fs = file_size(dest);
        if(fs == -2)
        {
            string *names;

            names = explode(str, "/");
            fs = file_size(dest + "/" + names[sizeof(names) - 1]);
            if(fs != -1)
            {
                write("file exists " + dest + "/" + names[sizeof(names) - 1] + "\n");
                continue;
            }

            rename(str, dest + "/" + names[sizeof(names) - 1]);
            /*
            log_file_time( LOG, sprintf("%s moved to %s by %s\n",
                                str,
                                dest, 
                                capitalize(this_player()->query_name()) ) );
            event(CREINFO, "inform", this_player()->query_cap_name()
                                    +" moves "+str+" to "+dest+"", "file" );
            */
        }
        else
        {
            if(fs != -1)
            {
                write("File exists : " + dest + "\n");
                continue;
            }
            rename(str, dest);
            /*
            log_file_time( LOG, sprintf( "%s moved %s to %s\n",
                            capitalize(this_player()->query_name()),
                            str, dest ));
            event(CREINFO, "inform", this_player()->query_cap_name()
                                    +" moves "+str+" to "+dest+"", "file");
            */
        }
    }
    write("Ok.\n");
    return 1;
} /* mv_file() */
