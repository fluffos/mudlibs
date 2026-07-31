// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <dbase.h>
#include <skill.h>

int query_str()
{
        int improve;

        if ( query_skill("strike",1)
          || query_skill("finger",1)
          || query_skill("cuff",1)
          || query_skill("hand",1)
          || query_skill("claw",1)
          || query_skill("leg",1))
        {
                if ( query_skill("cuff", 1) >= improve * 10)
                        improve = (int)query_skill("cuff", 1) / 10;
                if ( query_skill("claw", 1) >= improve * 10)
                        improve = (int)query_skill("claw", 1) / 10;
                if ( query_skill("finger", 1) >= improve * 10)
                        improve = (int)query_skill("finger", 1) / 10;
                if ( query_skill("hand", 1) >= improve * 10)
                        improve = (int)query_skill("hand", 1) / 10;
                if ( query_skill("strike", 1) >= improve * 10)
                        improve = (int)query_skill("strike", 1) / 10;
                if ( query_skill("leg", 1) >= improve * 10)
                        improve = (int)query_skill("leg", 1) / 10;
        }

return (int)query("str") + query_temp("str") + improve
;
}

int query_int()
{
        return (int)query("int") + query_temp("int") +
                (int)query_skill("literate", 1) / 10;
}

int query_con()
{
        return (int)query("con") + query_temp("con") +
                (int)query_skill("force", 1) / 10;
}

int query_dex()
{
        return (int)query("dex") + query_temp("dex") +
                (int)query_skill("dodge", 1) / 10;
}

int query_kar()
{
        return (int)query("kar");
}

int query_bac()
{
        int improve = query_skill("tao", 1) / 20;

        if ( query_skill("buddha",1)
          || query_skill("confu", 1))
        {
                if ( query_skill("buddha", 1) >= improve * 15 )
                        improve = (int)query_skill("buddha", 1) / 10;
                if ( query_skill("confu", 1) >= improve * 10)
                        improve = (int)query_skill("confu", 1) / 10;
        }

        return (int)query("bac") + improve;
}

int query_poi()
{
        return (int)query("poi");
}

int query_per()
{
        return (int)query("per");
}

