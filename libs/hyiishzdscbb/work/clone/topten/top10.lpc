// 1998/11/21 created by lanxin

#include <ansi.h>

inherit ITEM;

mapping *exp_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});

string printdate = NATURE_D->game_time();

void create()
{
        string id;
        int i,exp;

        set_name(HIY"侠客行英雄榜"NOR, ({ "hero board", "board" }));
        set_weight(800);
        set("unit", "架");
        set("long","这是记载侠客行英雄座次的留言版。你可以用(READ)来查阅。\n");
        set("value", 1600);
        set("material", "paper");
        set("no_get",1);
}

void init()
{
        object ob,me=this_object();

        seteuid(getuid());
        if( ob = new("/clone/topten/magic-rice") )
                if( (exp_topten=ob->query( "exp_topten" ))
                        )
                        destruct( ob );
                else
                        write(CYN"\n侠客行英雄榜被风刮倒了！请通知天神。\n\n"NOR);
        else
                write(CYN"\n侠客行英雄榜被风刮倒了！请通知天神。\n\n"NOR);


        add_action("do_read", "read");
}

int do_read( string arg )
{
        int i;
        string si;
        string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});

        switch( arg )
        {
                case "topten":
                        write( HIC+"十大高手排行榜"+NOR+"\n" );
                        write( "当今武林十大高手排名如下：\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( exp_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;

                   default:
                        return 0;
        }
        return 1;
}
