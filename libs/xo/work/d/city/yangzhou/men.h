// men.h 每个城门可以include
//by trill
//友情编辑 nerd :-)

#include <ansi.h>
string look_bangwen();
string crime_price( int );
string crime_short( object );

string look_bangwen()
{
    mapping crime_name;
    string *crime_id, msg, temp, arg;
    object player;
    int i, number = 0, bonus;

    arg = query("bangwen");
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
            if ( player = find_player( crime_id[ i ] ) )
                if ( CRIME_D->is_crime( player, arg ) )
                {
                    number ++;
                    if ( number == 1)
                    {
                        msg = msg + 
                        "     │        本城现通缉如下人犯：                            │\n";
                        msg = msg +
                        "     │                                                        │\n";
                    }
                    bonus = crime_name[ crime_id[ i ] ];
//                    temp = TrueString( crime_price(bonus) );
                    if ( bonus > 1000 )
                        msg = sprintf("%s     │   %-22s%s %24s  │\n", msg, 
                         crime_short( player ), "赏格", temp);
                    else
                        msg = sprintf("%s     │   %-22s%s %22s  │\n", msg, 
                         crime_short( player ), "赏格", temp);
                }
        }
        if ( !number )
	        msg = msg + "     │           本城治安良好。                               │\n";
	}
    else
    {
        msg = msg + "     │           本城治安良好。                               │\n";
    }
    msg += @TEXT
     │                                                        │
     │                                                        │
     │                                [31m┌──┐[2;37;0m                │
     │                                [31m│权  │[2;37;0m                │
     │                                [31m│知扬│[2;37;0m  [41;37m┌──┐[2;37;0m      │
     │                                [31m│州州│[2;37;0m  [41;37m│修欧│[2;37;0m      │
     │                                [31m│事  │[2;37;0m  [41;37m│印阳│[2;37;0m      │
     │                                [31m└──┘[2;37;0m  [41;37m└──┘[2;37;0m      │
     │                                                        │ 
     └────────────────────────────┘
TEXT ;
    return msg;
}
string crime_price(int v)
{
    if ( v < 1000 ) return "";
    return PriceString( v / 1000 * 36500  );
}

string crime_short(object player)
{
	return player->name(1) + "(" + capitalize(player->query("id")) + ")";
}
