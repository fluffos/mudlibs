// save.c
int save()
{
    string file;
    if( stringp(file = this_object()->query_save_file()) ) {
        assure_file(file+ __SAVE_EXTENSION__);
    if (catch(save_object(file)))    return 0;
else    return 1;
    }
    return 0;
}
int restore()
{
    string file;
    if( stringp(file = this_object()->query_save_file()) )
    if (catch(restore_object(file)))  return 0;
    else return 1;
    return 0;
}
