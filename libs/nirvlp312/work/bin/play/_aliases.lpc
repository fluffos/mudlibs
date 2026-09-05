int
cmd_aliases(string arg)
{
     object      me;
     mapping     aliases;
     string      *ks, p;
     int         i, s;

     
     me = this_player();
     aliases = (mapping)me->query_aliaii();

#ifndef __LDMUD__
     if(!aliases || !mapp(aliases) || !sizeof(aliases))
#else
     if(!aliases || !mappingp(aliases) || !sizeof(aliases))
#endif
       return (write("You don't have any aliases currently defined.\n"), 1);

     s = sizeof(ks = keys(aliases));

     write("\n\t\tAliases\n");
     write("------------------------------------------------\n");
     for(i = 0; i < s; i ++)
       write("  " + pad((p=ks[i]), 20) + "  " + aliases[p] + "\n");
     write("\n");
     return 1;
}
