#include <ansi.h>
#define CAP         capitalize

int cmd_plevels(string str) {
    string tmp1, tmp2, color, *rs;
    int x, y, x1, y1, a;
    mixed *tmp;

#ifdef __LDMUD__
    if(!str)
    {
      write("Use: plevels <x> [<y>].\n");
      return 1;
    }

    if(!sscanf(str,"%s %s",tmp1,tmp2))
      tmp1 = str;
    if(tmp1 && sscanf(tmp1,"%d+%d",x,x1) == 0)
    {
        x = (int)"/object/mysql/player"->get_player_info(tmp1,"level");
        x1 = (int)"/object/mysql/player"->get_player_info(tmp1,"xlevel");
        if(x && sscanf(x,"%d",x));
        if(x1 && sscanf(x1,"%d",x1));
        
    }

    if(tmp2 && sscanf(tmp2,"%d+%d",y,y1) == 0)
    {
        y = (int)"/object/mysql/player"->get_player_info(tmp2,"level");
        y1 = (int)"/object/mysql/player"->get_player_info(tmp2,"xlevel");
        if(y && sscanf(y,"%d",y));
        if(y1 && sscanf(y1,"%d",y1));
    }

    if(!x) {
        write("Use: plevels <x> [<y>].\n");
        return 1; }

    if(!y) y = x;
    if(!y1 && x1) y1 = x1;
    if(x > y)
    {
        a = y;
        y = x;
        x = a;
    }

    if(x != 19) x1 = 0;
    if(y != 19) y1 = 100000;

    if(x == y && x == 19 && x1 > y1)
    {
       a = y1;
       y1 = x1;
       x1 = a;
    }

    tmp = db_get_rs("select name,level,xlevel from players where level >= " + x + " and level <= " + y + " and xlevel >= " + x1 + " and xlevel <= " + y1 + " order by level,xlevel,name");
    if(!sizeof(tmp))
    {
        write("No one in specified level rage.\n");
        return 1;
    }

    write("    Name             Level\n"+
      "--------------------------\n");
    for(x = 0; x < sizeof(tmp); x++)
    {
        if(!(x % 2)) color = HIC;
        if((x % 2)) color = NORM;
        rs = tmp[x];
        tmp1 = rs[1];
        if((int)rs[2] > 0 && tmp1 == "19") tmp1 += "+" + rs[2];
        printf(color + "%-3s %-16s %-3s\n",(x+1) + ".",CAP(rs[0]),tmp1);
    }
    write(NORM);
    return 1;
#endif
    write("LD only command.\n");
    return 1;
 }
