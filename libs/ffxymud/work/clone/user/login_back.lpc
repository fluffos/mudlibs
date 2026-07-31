#include <login.h>
#include <dbase.h>
inherit F_DBASE;
inherit F_SAVE;

string back_data="/backdata/back0";

string query_save_file()
{
        string id;
        id = query("id", 1);
        if( !stringp(id) ) return 0;
        return sprintf(back_data+"/login/%c/%s", id[0], id);
        
}

string set_backdata_path(string path)
{
    if (!path || !stringp(path))  return 0;
    back_data=path;
    return back_data;
}

