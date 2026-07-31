// topten.c
// 1998/12/17 Modified by Winder

#include <ansi.h>

inherit ITEM;

mapping *exp_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *richman_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *oldman_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *force_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
/*
mapping *pks_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
*/
mapping *literate_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
mapping *unarmed_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
mapping *dodge_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
mapping *thief_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *axe_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *blade_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *throwing_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *fork_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *hammer_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),
});
mapping *staff_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *sword_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
mapping *whip_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
/*
mapping *club_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
*/
string *whichpart =
({
        HIY"第一榜    十大高手排行榜  --------------------  B1"NOR,
        HIY"第二榜    十大财主排行榜  --------------------  B2"NOR,
        HIY"第三榜    十大寿星排行榜  --------------------  B3"NOR,
        HIY"第四榜    五大内功高手  ----------------------  B4"NOR,
        HIY"第五榜    五大博学鸿儒  ----------------------  B5"NOR,
        HIY"第六榜    江湖五大杀手  ----------------------  B6"NOR,
        HIY"第七榜    天下三大神偷  ----------------------  B7"NOR,
        HIY"第八榜    天下三剑客  ------------------------  B8"NOR,
        HIY"第九榜    海内三刀客  ------------------------  B9"NOR,
        HIY"第十榜    神拳无敌镇五岳  --------------------  B10"NOR,
        HIY"第十一榜  踏雪无痕跨五湖  --------------------  B11"NOR,
        HIY"第十二榜  环宇三飞星--------------------------  B14"NOR,
        HIY"第十三榜  八方三神鞭  ------------------------  B15"NOR,
        HIY"第十四榜  中原八大锤  ------------------------  B16"NOR,
        HIY"第十五榜  神州三大杖客  ----------------------  B12"NOR,
//        HIY"第十六榜  武林三大棍王  ----------------------  B13"NOR,
});
string printdate = NATURE_D->game_time();

void create()
{
        string id;
        int i,exp;

        set_name(HIY"海洋II英雄榜"NOR, ({ "hero board", "board","hero" }));
        set_weight(800);
        set("unit", "本");
        set("long","这是记载海洋II英雄座次排行情况的金榜。你可以用(READ)来查阅。\n");
        set("value", 1600);
        set("no_get", 1);
        set("no_steal", 1);
        set("no_put", 1);
        set("no_beg", 1);
        set("material", "paper");
}

void init()
{
        object ob,me=this_object();

        seteuid(getuid());
        if( ob = new("/clone/topten/magic-rice") )
                if( (exp_topten=ob->query( "exp_topten" ))
                        &&(richman_topten=ob->query("richman_topten"))
                        &&(oldman_topten=ob->query("oldman_topten"))
                        &&(force_topten=ob->query("force_topten"))
//                        &&(pks_topten=ob->query("pks_topten"))
                        &&(unarmed_topten=ob->query("unarmed_topten"))
                        &&(dodge_topten=ob->query("dodge_topten"))
                        &&(literate_topten=ob->query("literate_topten"))
                        &&(thief_topten=ob->query("thief_topten"))
                        &&(axe_topten=ob->query("axe_topten"))
                        &&(blade_topten=ob->query("blade_topten"))
                        &&(throwing_topten=ob->query("throwing_topten"))
                        &&(fork_topten=ob->query("fork_topten"))
                        &&(hammer_topten=ob->query("hammer_topten"))
                        &&(staff_topten=ob->query("staff_topten"))
                        &&(sword_topten=ob->query("sword_topten"))
//                        &&(club_topten=ob->query("club_topten"))
                        &&(whip_topten=ob->query("whip_topten")) )
                        destruct( ob );
                else
                        write(CYN"\n江湖排行榜出现问题！请通知江湖执法。\n\n"NOR);
        else
                write(CYN"\n江湖排行榜出现问题！请通知江湖执法。\n\n"NOR);

        add_action("do_read", "read");
}

int do_read( string arg )
{
        int i;
        string si;
        string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});

        switch( arg )
        {
                case "hero board":
                case "board":
                case "hero":
                case "b":
                case "海洋II英雄榜":
                        write( "你阅读《海洋II英雄榜》，只见上面写着：\n" );
                        write( "--------------------------------------------------------\n" );
                        for( i = 0; i < sizeof(whichpart); i++ )
                                write( "    "+whichpart[i]+"\n" );
                        write( "--------------------------------------------------------\n" );

                        write( "                          ----"+printdate+"公告\n" );
                        write( "你要阅读第几榜？\n" );
                        break;
                case "B1":
                case "b1":
                case "第一榜":
                case "十大高手排行榜":
                        write( "                    『"+HIC"十大高手排行榜"NOR+"』\n" );
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
                case "B2":
                case "b2":
                case "第二榜":
                case "十大财主排行榜":
                        write( "                    『"+HIC"十大财主排行榜"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( richman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B3":
                case "b3":
                case "第三榜":
                case "十大寿星排行榜":
                        write( "                    『"+HIC"十大寿星排行榜"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( oldman_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B4":
                case "b4":
                case "第四榜":
                case "五大内功高手":
                        write( "                    『"+HIC"五大内功高手"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( force_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B5":
                case "b5":
                case "第五榜":
                case "五大博学鸿儒":
                        write( "                    『"+HIC"五大博学鸿儒"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( literate_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B6":
                case "b6":
                case "第六榜":
                case "江湖五大杀手":
                        write( "                    『"+HIC"江湖五大杀手"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
/*
                        si = "名次";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( pks_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
*/
                        write( "    暂时保密  \n" );
                        write( "========================================================\n" );
                        break;
                case "B7":
                case "b7":
                case "第七榜":
                case "天下三大神偷":
                        write( "                    『"+HIC"天下三大神偷"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( thief_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );

                        }
                        write( "========================================================\n" );
                        break;
                case "B8":
                case "b8":
                case "第八榜":
                case "天下三剑客":
                        write( "                    『"+HIC"天下三剑客"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( sword_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B9":
                case "b9":
                case "第九榜":
                case "海内三刀客":
                        write( "                    『"+HIC"海内三刀客"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( blade_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B10":
                case "b10":
                case "第十榜":
                case "神拳无敌镇五岳":
                        write( "                    『"+HIC"神拳无敌镇五岳"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( unarmed_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B11":
                case "b11":
                case "第十一榜":
                case "踏雪无痕跨五湖":
                        write( "                    『"+HIC"踏雪无痕跨五湖"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 5; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( dodge_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B12":
                case "b12":
                case "第十二榜":
                case "四极三飞星":
                        write( "                    『"+HIC"四极三飞星"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( throwing_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B13":
                case "b13":
                case "第十三榜":
                case "八方三神鞭":
                        write( "                    『"+HIC"八方三神鞭"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( whip_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B14":
                case "b14":
                case "第十四榜":
                case "中原八大锤":
                        write( "                    『"+HIC"中原八大锤"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 8; i++ )

                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( hammer_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
                case "B15":
                case "b15":
                case "第十五榜":
                case "神州三大杖客":
                        write( "                    『"+HIC"神州三大杖客"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( staff_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
/*
                case "B16":
                case "b16":
                case "第十六榜":
                case "武林三大棍王":
                        write( "                    『"+HIC"武林三大棍王"NOR+"』\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "名次";
                        for ( i = 0; i < 3; i++ )
                        {
                                si = sprintf( "第%d名",i+1 );
                                sscanf( club_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"第"+chinese_number(i+1)+"名  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;
*/
                   default:
                        return 0;
        }
        return 1;
}
