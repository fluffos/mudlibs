int
cmd_nicknames(string arg)
{
     object      me;
     mapping     nicknames;
     string      *ks, p;
     int         i, s;

     
     me = this_player();
     nicknames = (mapping)me->query_nicknames();

     if(!nicknames || !mapp(nicknames) || !sizeof(nicknames))
       return (write("You don't have any nicknames currently defined.\n"), 1);

     s = sizeof(ks = keys(nicknames));

     write("\n\t\tNicknames\n");
     write("------------------------------------------------\n");
     for(i = 0; i < s; i ++)
       write("  " + pad((p=ks[i]), 20) + "  " + nicknames[p] + "\n");
     write("\n");
     return 1;
}
