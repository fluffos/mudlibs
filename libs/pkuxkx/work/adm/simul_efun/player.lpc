object find_player(string id)
{
    object* all = users();

    if (!stringp(id)) return 0;
    
    for(int i =0;i<sizeof(all);i++)
    {
        if(objectp(all[i]) && getuid(all[i])==id)
        {
            return all[i];
        }
    }
    return 0;
}

