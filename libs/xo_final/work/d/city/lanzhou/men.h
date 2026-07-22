//  每个城门可以include的men.h  /d/city/lanzhou/men.h
//  By trill
//  友情编辑 nerd :-)
//  Changed by Lala, 1998-03-20

#include <ansi.h>
string look_bangwen();                      //看榜文的函数。
string crime_price( int );                  //计算罪犯通缉的赏格。
string crime_short( object );               //查找罪犯的姓名。

string look_bangwen()
{
//    object crime ;
    mapping crime_name;
    string *crime_id, msg, temp, arg;
    object ppl;
    int i, number = 0, bonus;

    arg = "lanzhou";                        
    msg = @TEXT
     ┌────────────────────────────┐
     │                                                        │
     │                        [30;47m榜    文[2;37;0m                        │
     │                                                        │
TEXT ;
    if ( crime_name = CRIME_D->query_present_crime( arg ) )
    {
        crime_id = keys( crime_name );
        for ( i = 0; i < sizeof( crime_id ); i ++ )
        {
            if ( ppl = find_player( crime_id[ i ] ) )
                if ( CRIME_D->is_crime( ppl, arg ) )
                {
                    number ++;
                    if ( number == 1)
                    {
                        msg += 
        "     │        本城现通缉如下人犯：                            │\n";
                        msg += 
      "     │                                                        │\n"
    + "     │ 西北大盗 夜猫子(Ye maozi)   赏格      二百两" 
    + WHT"银子"NOR + "       │\n";
                    }
                    bonus = crime_name[ crime_id[ i ] ];
                    temp = crime_price(bonus) + "   │";
                    if ( bonus > 1000 )
                        msg = sprintf("%s     │ %-24s    %s %-40s\n", msg, 
                         crime_short( ppl ), "赏格", temp);
                    else
                        msg = sprintf("%s     │       %-24s    %s %-38s\n", msg, 
                         crime_short( ppl ), "赏格", temp);
                }
        }
        if ( !number )
            msg +=  
        "     │        本城现通缉如下人犯：                            │\n";
                        msg +=  
        "     │                                                        │\n"
        + "     │ 西北大盗 夜猫子(Ye maozi)   赏格      二百两" 
        + WHT"银子"NOR + "       │\n";
    }
    else
    {
        msg += 
        "     │        本城现通缉如下人犯：                            │\n";
        msg += 
        "     │                                                        │\n"
        + "     │ 西北大盗 夜猫子(Ye maozi)   赏格      二百两" 
        + WHT"银子"NOR + "       │\n";
    }
    msg += @TEXT
     │                                                        │
     │                                                        │
     │                                [31m┌──┐[2;37;0m                │
     │                                [31m│权  │[2;37;0m                │
     │                                [31m│知兰│[2;37;0m  [41;37m┌──┐[2;37;0m      │
     │                                [31m│州州│[2;37;0m  [41;37m│之种│[2;37;0m      │
     │                                [31m│事  │[2;37;0m  [41;37m│印谊│[2;37;0m      │
     │                                [31m└──┘[2;37;0m  [41;37m└──┘[2;37;0m      │
     │                                                        │ 
     └────────────────────────────┘
TEXT ;
    return msg;
}

string crime_price( int v )
{
    if ( !v ) return "";
    return PriceString( v / 100 * 350 );
}

string crime_short( object ppl )
{
	return ppl->name(1) + "(" + capitalize(ppl->query("id")) + ")";
}

int valid_leave( object npc, string dir )   //这个是用来防NPC到处乱跑的。
{
    if ( npc->query( "CantPass" ) )
        return 0;
    return ::valid_leave( npc, dir );
}