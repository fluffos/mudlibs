/*
 * the following allows things to interact with mysql
*/

int valid_connector()
{
    int handle_num;
    string calling_from, tmp, my_row;
    mixed *full_rs;

    full_rs = ({ });
    calling_from = file_name(previous_object());
    if(sscanf(calling_from,"%s#%s",calling_from,tmp));

    handle_num = efun::db_connect("mud_data_base");

    efun::db_exec(handle_num,"select * from valid_list where path='" + calling_from + "'");
    while(sizeof(my_row = db_fetch(handle_num)))
      full_rs += ({ my_row });
    efun::db_close(handle_num);

    handle_num = sizeof(full_rs);
    return handle_num;
}

int db_connect()
{
    int handle_num;

    handle_num = 0;
    if(valid_connector())
        handle_num = efun::db_connect("mud_data_base");

    return handle_num;

}

int db_exec(int db_handle, mixed command)
{

    int handle_return;

    if(!db_handle || !command) return 0;
    handle_return = 0;

    if(valid_connector())
        handle_return = efun::db_exec(db_handle,command);

    return handle_return;
}

int db_close(int db_handle)
{
    int handle_return;

    handle_return = 0;
    if(!db_handle) return 0;

    if(valid_connector())
        handle_return = efun::db_close(db_handle);

    return handle_return;
}

string db_fetch(int db_handle)
{
    string my_value;

    if(valid_connector() && db_handle)
        my_value = efun::db_fetch(db_handle);

    return my_value;
}


int db_affected_rows(int db_handle)
{
    int num_rows;

    if(!db_handle) return 0;

    if(valid_connector())
        num_rows = efun::db_affected_rows(db_handle);

    return num_rows;
}

string *db_coldefs(int db_handle)
{

    string *col_info;

    if(valid_connector() && db_handle)
        col_info = efun::db_coldefs(db_handle);

    return col_info;
}

string db_error(int db_handle)
{
    string what_error;

    if(valid_connector() && db_handle)
        what_error = efun::db_error(db_handle);

    return what_error;
}

int *db_handles()
{
    int *open_handles;

    if(valid_connector())
        open_handles = efun::db_handles();

    return open_handles;
}

int db_insert_id(int handle)
{
    int auto_value;

    if(!handle) return 0;

    if(valid_connector())
        auto_value = efun::db_insert_id(handle);

    return auto_value;
}

mixed *db_get_rs(string my_query)
{
    int handle;
    string my_row;
    mixed *full_rs;
    handle = db_connect();
    full_rs = ({ });
    db_exec(handle,my_query);
    if(handle && my_query)
    {
        while(sizeof(my_row = db_fetch(handle)))
            full_rs += ({ my_row });
        db_close(handle);
    }
    return full_rs;
}
