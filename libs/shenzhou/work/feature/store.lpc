 mapping *storeage;

void add_store(mapping info)
{
        if(sizeof(storeage) == 0)
                storeage = ({info});
        else storeage += ({info});
}

void del_store(int i)
{
        mapping info;
        info = storeage[i];
        storeage -= ({info});
}

string *store_list()
{
        string *list = ({});
        int number = sizeof(storeage);
        for(int i = 0; i< number; i++) 
                list += ({storeage[i]["name"] + "(" + storeage[i]["id"] + ")"});
        return list;
}

mapping store_info(int i)
{
        return storeage[i];
}
