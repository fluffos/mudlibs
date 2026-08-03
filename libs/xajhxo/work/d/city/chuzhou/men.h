// men.h 每个城门可以include
//by trill
//友情编辑 nerd :-)

#include <ansi.h>
string look_bangwen();
string crime_price( int );
string crime_short( object );

string look_bangwen()
{
    object crime ;
    mapping crime_name;
    string *crime_id, msg, space, space2, temp, temp_msg, arg;
    object player;
    int i, number = 0, bonus, length;

    arg = "yangzhou";
    msg = @TEXT
     ┌────────────────────────────┐
     │                                                        │
     │                        榜  文                          │
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
                    temp = crime_price(bonus) + "   │";
                    if ( bonus > 1000 )
                        msg = sprintf("%s     │       %-24s    %s %34s\n", msg, 
                         crime_short( player ), "赏格", temp);
                    else
                        msg = sprintf("%s     │       %-24s    %s %32s\n", msg, 
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
     │                                ┌──┐                │
     │                                │权  │                │
     │                                │知楚│  ┌──┐      │
     │                                │州州│  │刑提│      │
     │                                │事  │  │狱点│      │
     │                                └──┘  └──┘      │
     │                                                        │ 
     └────────────────────────────┘
TEXT ;
    return msg;
}
string crime_price(int v)
{
    if ( !v ) return "";
    if ( v / 10000000) 
        return chinese_number( v / 10000000 * 10000 ) + "两"+HIY "银子" NOR;
    if ( v / 1000000) 
        return chinese_number( v / 1000000 * 1000 ) + "两"+HIY "银子" NOR;
    if ( v / 100000) 
        return chinese_number( v / 100000 * 100 ) + "两"+HIY "银子" NOR;
    if ( v / 10000) 
        return chinese_number( v / 10000 * 10 ) + "两"+HIY "银子" NOR;
    if ( v / 1000 )
        return chinese_number( v / 1000 ) + "两"+HIY "银子" NOR;
    if ( v )
        return chinese_number(v)+"文"+YEL "铜钱" NOR;
    return "";
}

string crime_short(object player)
{
        return player->name(1) + "(" + capitalize(player->query("id")) + ")";
}
