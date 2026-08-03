/* shamo.h
 * from XO Lib
 * an include file ,define some function for all rooms of this desert
 * created by hydra 19980328
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */
//Modified Hydra 1998/10/03  给高级玩家增加可以通过看太阳判断方向。。。

#include <ansi.h>
#include <localtime.h>
#include <command.h>

inherit ROOM;

#define MORNING     1
#define NOON        2
#define AFTERNOON   3
#define EVENING     4
#define NIGHT       5     

void rescue( object me );

//返回ppl所在room的所有出口。
mapping query_exit()
{
    return environment( this_player() )->query( "exits" );
}


//这两个函数返回通过query_exit()得到的mapping的key&value
string *query_value()
{
    return values( query_exit() );
}

string *query_key()
{
    return keys( query_exit() );
}

//定出ppl所在room的代表south的出口,调用上面三个函数
string query_south( int flag )
{
    string *value,*key;
    
    value = query_value();
    key = query_key();
//flag=0 用compass判断，定出南方，但受磁场的影响
//flag=1 看太阳来判断，定出南方
//flag=2 看星星来判断，定出北方
    switch ( flag )
    {
        case 0:
            if( !environment( this_player() )->query( "磁场" ) )
                switch ( key[ member_array( DIR,value ) ] )
                {
                    case "forward":
                        return "left";
                        break;
                    case "right":
                        return "forward";
                        break;
                    case "backward":
                        return "right";
                        break;
                    case "left":
                        return "backward";
                        break;
                }
            else
                return key[ random( 4 ) ];
            break;
        case 1:
            switch ( NATURE_D->Time( NATURE_D->QueryShiChen() ) )
            {
                case MORNING:
                    switch ( key[ member_array( DIR,value ) ] )
                    {
                        case "forward":
                            return "backward";
                            break;
                        case "right":
                            return "left";
                            break;
                        case "backward":
                            return "forward";
                            break;
                        case "left":
                            return "right";
                            break;
                    }
                break;
                case NOON:
                    switch ( key[ member_array( DIR,value ) ] )
                    {
                        case "forward":
                            return "left";
                            break;
                        case "right":
                            return "forward";
                            break;
                        case "backward":
                            return "right";
                            break;
                        case "left":
                            return "backward";
                            break;
                    }
                break;                
                case AFTERNOON:
                    switch ( key[ member_array( DIR,value ) ] )
                    {
                        case "forward":
                            return "forward";
                            break;
                        case "right":
                            return "right";
                            break;
                        case "backward":
                            return "backward";
                            break;
                        case "left":
                            return "left";
                            break;
                    }
                break;                
            }
            break;
        case 2:
            switch ( key[ member_array( DIR,value ) ] )
            {
                case "forward":
                    return "right";
                    break;
                case "right":
                    return "backward";
                    break;
                case "backward":
                    return "left";
                    break;
                case "left":
                    return "forward";
                    break;
            }
            break;
    }
}


/* the following are some functions for action "look" to call
 * do_look()   action of look
 * change_exit()  change exits after 5 second if you found a real lvzhou
 */
int do_look( string dir )
{
    object me;
    string old_dir;
    me = this_player();

//arg 为方向(right、left)时有可能产生海市蜃楼，如果实战经验高的话，看
//到的情形是真的概率也高
    if( dir == "forward" || dir == "backward" || dir == "left" || dir == "right" )
    {
        switch ( random( 5 ) )
        {
            case 0:
                write( "你放眼望去，只见" + dir + "方向，十几里外，一片湖泊在阳光下波光\n" );
                write( "粼粼，湖边一片树林，林间空地上露出一幢幢象是房屋，又似蒙古\n" );
                write( "包的灰白色影迹。\n" );
//看到的情形为真的几率为 combat_exp <10 k 时1% ,combat_exp >1M 是 100%
                if( !random( 1000000/( (int)me->query( "combat_exp" )+10000 ) ) ) 
                {
                    old_dir = environment( me )->query( "exits/"+dir );
                    environment( me )->set( "exits/"+dir,__DIR__"lvzhou" );
                    call_out( "change_exit",5,environment( me ),old_dir,dir );
                }
                break;
            default:
                write( "你极目远眺，所见之处，除了黄沙漫漫，别无一物。\n" );
                break;
        }
        return 1;
    }

//等级因子超过5000的可以通过看太阳，星星过沙漠
//Hydra added 1998/10/13

//白天看太阳判断方向。
    if ( dir == "sun" )
    {
        if ( NATURE_D->AtNight() )
        {
            write( "晚上你到哪里去看太阳啊？\n" );
            return 1;
        }
        if ( NATURE_D->GetWeather( "XIYU",NATURE_D->GetSeason() ) != 1 
             && NATURE_D->GetWeather( "XIYU",NATURE_D->GetSeason() ) != 2   )
//         if ( NATURE_D->GetWeather( "XIYU",NATURE_D->GetSeason() ) != 0 )
        {
            write( "现在天气不好，天空中看不见太阳。\n");
            return 1;
        }
        message_vision( "$N抬头看了一下太阳。\n",me );
        if ( XPLOR_CMD->QueryLevel(me) < 5000 )
        {
            write( "只觉得太阳在空中晃着，你还是没有办法分清方向。\n" );
            return 1;
        }
        write( "现在太阳正在你的" + query_south( 1 ) + "侧。\n" );
        return 1;
    }

//晚上看星星判断方向 
    if ( dir == "star" )
    {
        if ( !NATURE_D->AtNight() )
        {
            write( "大白天的看什么星星啊。\n" );
            return 1;
        }
        if ( NATURE_D->GetWeather( "XIYU",NATURE_D->GetSeason() ) != 1 
            && NATURE_D->GetWeather( "XIYU",NATURE_D->GetSeason() ) != 2)
        {
            write( "空中乌云密布，看不见一颗星星。\n");
            return 1;
        }        
        message_vision( "$N抬头看了一下星星。\n",me );
        if ( XPLOR_CMD->QueryLevel(me) < 5000 )
        {
            write( "只发现天空星星闪烁，刺得你眼花。\n" );
            return 1;
        }
        write( "现在北极星正在你的" + query_south( 2 ) + "侧。\n" );
        return 1;
    }


    return 0;
}

void change_exit( object room,string exit,string dir )
{
    room->set( "exits/"+dir,exit );
}

// the following are funtion to set a long description of room
// the long description changes per 60 seconds
void SetLong()
{

    string long;
    long = "这里是一片茫茫沙漠，一望无际，只有一些隆起的沙丘，不见半个人影，即\n";
    long += "使偶尔有些骆驼的枯骨，他那微小的白光也早溶如了周围的苍茫；又是那样的";
    long += "寂\n静，似乎只有热空气在作哄哄的火响。不时刮起一阵旋风，把黄沙卷起，象";
    long += "是平\n地冒器的青烟，打着转在沙漠上飞跑。";
    if( NATURE_D->Time( NATURE_D->QueryShiChen() ) == NOON )
    {
        long += "正午的阳光直射下来，那单纯而强烈的反\n光使你的眼睛很不舒服,你感觉";
        long += "到你体内的水分好象要被抽干了似的。\n";
    }
    else if( NATURE_D->AtNight() )
    {
        long += "天渐渐黑了下来，四周一片漆黑，丝毫没\n有物影。\n";
    }
    else
    {
        long += "天空中几只秃鹫在盘旋着，它们在寻找死\n在沙漠中的骆驼或人，那是它们";
        long += "的猎物。\n";
    }
    set( "long",long );
}

//the following are functions to decrease water when walking in the desert
// and the event whick will happen when one's water equals to 0.
int valid_leave( object me,string dir )
{
    int current_water;
    
    me = this_player();
    current_water = me->query( "water" );
    if( current_water == 0 ) 
    {
        return notify_fail( "你由于缺水严重，再也迈不动步子了。\n" );
    }
    if( current_water <= 20 )
    {
        write( RED"由于水分的过度蒸发，你感到快要虚脱了。\n"NOR );
        me -> set( "water",0 );
        if( random( 5 ) == 0 )
        {
            write( RED"你只觉得眼前一阵天旋地转。。。\n"NOR );
            call_out( "die",1,me );
            return 1;
        }
    }
    else
    {
        me->delete("env/lead_newbie");  //沙漠里不允许lead newbie
    //骑上骆驼的时候水的消耗减少。
        if ( !me->query_temp_marks( "is_riding" ) )  
            me -> add( "water",-20 );
        else
            me -> add( "water",-10 );
    }
    
    //For 海市蜃楼 Hydra 1998/5/24
    if ( dir == me->query_temp("hydra/desert/lvzhou_dir") )
    {
        me->add_temp("hydra/desert/lvzhou_step",1);
        me->delete_temp("hydra/desert/lvzhou_dir");
        if(me->query_temp("hydra/desert/lvzhou_step") >=3)
        {
            me->move(__DIR__"lvzhou");
            me->delete_temp("hydra/desert/lvzhou_step");
            return notify_fail(YEL"你历经艰辛，终于到达了一片绿洲！\n"NOR);
        }
    }
    else
    {
        me->delete_temp("hydra/desert/lvzhou_dir");
        me->delete_temp("hydra/desert/lvzhou_step");
    }
        
    return ::valid_leave( me,dir );
}

void die( object me )
{
    me -> die();
}

//the following function decrease water of players who are in the desert
// by 20 per localtime hours .
void DecWater( object me,int time )
{
    int current_time,current_water;

    current_time = time();
    current_water = me->query( "water" );
    if( environment( me )->query( "outdoors" ) == "desert" )
    {
        if( current_water == 0 ) 
        {
            write( RED"你由于严重缺水，眼前一黑。 \n"NOR );
            me -> die();
            return;
        }
        if( current_water <= 20 )
        {
            write( RED"由于在沙漠中呆的时间太长，水分的过度蒸发，你感到快要虚脱了。\n"NOR );
            me -> set( "water",0 );
            if( random( 5 ) == 0 )
            {
                write( RED"你只觉得眼前一阵天旋地转。。。\n"NOR );
                me -> die();
            }
            else
                call_out( "DecWater",60,me,current_time );
        }
        else
        {
            call_out( "DecWater",60,me,current_time );
            if ( !me->query_temp_marks( "is_riding" ) )
                me -> add( "water",-20 );
            else
                me -> add( "water",-10 );
        }
    }
}

//清除room里的非生物物品，在init里调用。
void eventClear( object env )
{
    object * inv;
    int i;
    inv = all_inventory( env );

    for ( i=0;i<sizeof( inv );i++ )
        if( !inv[i]->is_character() )
            destruct( inv[i] );
}

void greet_me( object me )
{
    string *exits = ({ "forward","backward","right","left", });
    string dir;
    dir = exits[random(sizeof(exits))];
    if ( !random(3) ) return;
    if ( environment(me) != this_object() ) return;
    write( GRN"你依稀看到"+dir+"方向，一片青绿，一个不小的湖泊，周围长着几棵柳树。\n"NOR);
    me -> set_temp("hydra/desert/lvzhou_dir",dir);
}