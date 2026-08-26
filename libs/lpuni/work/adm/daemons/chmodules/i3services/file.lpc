 /* file.c

 Tricky @ LPUniversity
 25-AUG-2006
 Intermud3 file service

 */

string fix_path(string path)
{

    if(path == "/") path = I3_FILE_DIR;
    else
    {
        string *parts = explode(path, "/") - ({ "", "." });

        for(int i = 0; i < sizeof(parts); )
        {

            if(parts[i] == "..")
            {

                if(i)
                {
                    parts[i - 1..i] = ({ });
                    --i;
                }
                else parts[i..i] = ({ });

            }

            ++i;
        }

        path = I3_FILE_DIR;

        if(sizeof(parts)) path += "/" + implode(parts, "/");

    }

    return path;
}

void oob_file_list_req(mixed *packet)
{
    mixed  *dir_list;
    string  err;
    string  dir = packet[3];

    if(!sizeof(dir) || !stringp(dir))
    {
        oob_send_error(
          "bad-proto",
          "bad directory specified",
          packet
        );

        return;
    }

    dir = fix_path(dir);
    err = catch(dir_list = get_dir(dir + "/*", -1));

    if(err)
    {
        oob_send_error(
          "bad-directory",
          err,
          0
        );

        return;
    }

    oob_send_packet( ({ "file-list-reply", packet[2], dir_list }) );
}
