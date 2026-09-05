
 
//  by  icer
//  pretending.c

inherit  F_CLEAN_UP;

mixed  main(object  me)
{
        object  *ulist;
        int  i;

        ulist  =  users();
        i  =  sizeof(ulist);
        while  (i--)  {
                if ( ulist[i]->query_temp("apply/name") )
                        write( ulist[i]->query("name") + "(" + ulist[i]->query("id") + ")正在假扮" + 
                                ulist[i]->query_temp("apply/name")[0] + "(" + ulist[i]->query_temp("apply/id")[0] + ")。\n");
        }
        return  1;
}

int  help  (object  me)
{
                write(@HELP
指令格式  :  pretending
  
可列出目前正在pretend的玩家。
  
  
HELP
);
                return  1;
}

