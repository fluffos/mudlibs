// gaoshou.c
#include <ansi.h>
#include <login.h>
inherit ITEM;
//inherit F_AUTOLOAD;
inherit F_AUTOLOAD;
void create()
{
        set_name(HIR"高手排行榜"NOR, ({ "stone" }) );
        set("long","排行榜\n");
        set("unit", "本");
        set("value",4000);
}

//int query_autoload() { return 1; }//autoload必须
int query_autoload() { return 1; }//autoload必须

void init()
{
        add_action("do_cha", "chabang");
}
int do_cha(string arg)
{
        string* gaoshoulist;
        gaoshoulist = explode(read_file(GAOSHOU), "\n");
//for(int i=0; i<sizeof(gaoshoulist); i++)
        for(int i=0; i<sizeof(gaoshoulist); i++)

                printf(gaoshoulist);
                printf(gaoshoulist, '\n');

        write("\n");
        return 1;
}
