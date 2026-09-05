//kickout all the users in specified room

#include <command.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i;
    object* invs;
    object room = load_object(arg);
    
    int count = 0;
    if(objectp(room))
    {
        invs = all_inventory(room);
        for(i=0;i<sizeof(invs);i++)
        {
            if(userp(invs[i]) && !wizardp(invs[i]))
            {                
                seteuid(ROOT_UID);
                invs[i]->save();
                destruct(invs[i]);
                count++;
                seteuid(getuid());        
            }
        }
    }
    printf("kick out:%d\n",count);
    return 1;
}