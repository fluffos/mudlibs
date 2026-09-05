int print_name(object* obs,int index)
{
    write(obs[index]->query("name")+" " +obs[index]->query("id")+"\n");
    if(index < sizeof(obs) - 1)
    {
        call_out("print_name",5,obs,index+1);
    }
    return 1;
}
int main(object me, string arg)
{
    object* obs;
    object room ;
    if(!arg) return 1;
  /*  room = load_object(arg);
    if(objectp(room))
    {
        obs = all_inventory(room);
        for(int i=0;i<sizeof(obs);i++)
        {
            write(obs[i]->query("id")+"\n");
        }
    }
    else*/
    {
        room = find_player(arg);
        if(objectp(room))
            {
                for(int i=0;i<sizeof(obs);i++)
                {
                    write(obs[i]->query("id")+"\n");
                }                
                        obs = all_inventory(room);
                    call_out("print_name",5,obs,0);
            }
    }
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: dumproom path
 
枚举房间中的物品id
 
HELP
);
        return 1;
}