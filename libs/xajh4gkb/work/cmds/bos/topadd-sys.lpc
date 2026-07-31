
inherit F_CLEAN_UP;

int main(object me)
{
    object *user = children(USER_OB);
    for (int i=0;i<sizeof(user);i++)
    {
		if ( !environment(user[i]) )
			continue;

    	"/adm/daemons/toptend"->topten_checkplayer(user[i]);
    	reset_eval_cost();
    }

    return 1;
 }
 
 
