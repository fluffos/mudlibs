//负责存放各门派之间的“友好度”。
//Qyz
#include <ansi.h>

inherit F_SAVE;

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

mapping ALL_FAMILYS=(["方寸山三星洞":1,
                 "南海普陀山":1,
                 "五庄观":1,
                 "阎罗地府":-1,
                 "月宫":1,
                 "东海龙宫":1,
                 "大雪山":-1,
                 "陷空山无底洞":-1,
                 "盘丝洞":-1,
                 "将军府":1,
                 "三界散仙":-1,
                 "昆仑山玉虚洞":1,
                 "火云洞":-1,
                 "蜀山派":1,
                
]);

mapping MASTERS=(["方寸山三星洞":"菩提老祖",
                 "南海普陀山":"观音菩萨",
                 "五庄观":"镇元大仙",
                 "阎罗地府":"阎罗王",
                 "月宫":"嫦娥",
                 "东海龙宫":"傲广",
                 "大雪山":"大鹏明王",
                 "陷空山无底洞":"玉鼠精",
                 "盘丝洞":"紫霞仙子",
                 "将军府":"白发老人",
                 "三界散仙":"中山夫子",
                 "昆仑山玉虚洞":"姜子牙",
                 "火云洞":"红孩儿",
                 "蜀山派":"李逍遥",
]);

mapping family;

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(family) ){
        family = ([]);
    }
}

int remove()
{
    save();
    return 1;
}

int family_relation(string your_fam,string my_fam )
{
        return ALL_FAMILYS[your_fam]*ALL_FAMILYS[my_fam];
}

string query_save_file() { return DATA_DIR + "familyd"; }

int set_relation(string my_fam, mapping relation)
{
    family[my_fam] = relation;
    save();
    return 1;
}

int add_family_enemy( string my_fam, string name, int score )
{
    if( undefinedp( family[my_fam] ) )
        family[my_fam] = ([ name : score ]);
    if( !undefinedp(family[my_fam][name] ) )
        family[my_fam][name] += score;
    else family[my_fam] += ([ name : score ]);
    save();
    return 1;
}

int remove_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] ) ) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
    {
        map_delete(family[my_fam] , name);
        save();
            return 1;
    }
    else return 0;
}

int is_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name])&&family[my_fam][name]>100)
        return 1;
    else return 0;
}

int query_enemy_quantity( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
        return family[my_fam][name];
    else return 0;
}
        
mapping query_relation(string my_fam)
{
    if ( !undefinedp(family[my_fam]) )
        return family[my_fam];
    else
        return ([]);
}

int deal_family_relation( object victim, object killer )
{
    mapping my_family, your_family;
    int c_score, y_relation, m_relation; 
    string my_fam, your_fam, my_id, your_id, declare;

    string* sname;
    int i;

    your_id = killer->query("id");
    if( your_family = killer->query("family") )
    {
        your_fam = your_family["family_name"];
        my_id = victim->query("id");    
        if( !undefinedp(family[your_fam]) &&
        !undefinedp(family[your_fam][my_id]) )
        {
            killer->add("faith" , family[your_fam][my_id]/100 );
            {
                declare = sprintf("[1;37m纵声长啸:[33m%s[1;37m杀死本门仇敌[32m%s[1;37m，真乃大快人心。\n",
                                killer->name(1), victim->name(1) );
                message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());
            }
            map_delete(family[your_fam] , my_id );
            return 1;
        }

        if( my_family = victim->query("family") )
        {
            my_fam = my_family["family_name"];
            c_score = victim->query("faith");
            if( my_fam == your_fam )
            {
                killer->add("faith", -( c_score/100 + 1 ) );
                if(c_score > 30 )  
                {
                    declare = sprintf("[1;37m纵声长啸:[32m%s[1;37m不可再屠戮本门师兄弟，切不可同门相残！。\n", killer->name(1) );
                    message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());                    
                }     
                return 1;                                             
            }
            else
            {    
                if( userp( killer ) )
                    add_family_enemy( my_fam, your_id, c_score );
                if( y_relation = family_relation( your_fam, my_fam ) )
                {                                           
                    if( y_relation == FAMILY_ENEMY )
                    {
                        killer->add("faith" , c_score/100 );
                        killer->add("relation/"+my_fam,c_score/100);
                        sname=keys(ALL_FAMILYS);
                        if(c_score > 30 )
                        {
                            declare = sprintf("[1;37m纵声长啸:[32m%s[1;37m吃掉了本门对头[33m%s[1;37m的[35m%s，[1;37m功德无量也！\n",
                                    killer->name(1), my_fam, victim->name(1) );
                            message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());                            
                        }
                    }
                    else if( y_relation == FAMILY_FRIEND )
                    {
                        killer->add("faith" , -c_score/100 );
                        killer->add("relation/"+my_fam,-c_score/100);       
                        if(c_score > 30 )
                        {
                            declare = sprintf("[1;37m纵声长啸:本门弟子应该与[33m%s[1;37m的弟子和睦相处，不应互相杀戮。\n",
                                        my_fam );
                            message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());
                        }
                    }
                }
                if( m_relation = family_relation( my_fam, your_fam ))
                {
                    if( m_relation == FAMILY_ENEMY )
                    declare = sprintf("[1;37m纵声长啸:本门与[32m%s[m势不两立，弟子们要切记仇恨啊！\n",
                                        your_fam );
                    else
                    declare = sprintf("[1;37m纵声长啸:本门[31m%s[1;37m被[33m%s[1;37m的[32m%s[1;37m吃掉了，同门弟子皆应以报仇为己任！\n",
                                    victim->name(1), your_fam, killer->name(1) );
           
                    message("channel:chat",HIR+MASTERS[my_fam]+declare+NOR,users());
                }
                return 1;                                              
            }             
        }
        else return 0;
    }
    else if( my_family = victim->query("family") )                   
    {
        my_fam = my_family["family_name"];
        c_score = victim->query("faith");
        if( userp(killer) )
            add_family_enemy( my_fam, your_id, c_score );
       killer->add("relation/"+my_fam,c_score/100);
        {
            declare = sprintf("[1;37m纵声长啸:本门弟子被[32m%s[1;37m杀害了。\n", killer->name(1) );
            message("channel:chat",HIR+MASTERS[my_fam]+declare+NOR,users());
        }
        return 1;
    }
    else return 0;
}

void clear_all_family_relation( string id )
{
    int i;
    string *familys = keys(ALL_FAMILYS);
    for( i = 0; i<sizeof(familys); i++ )
    {
        if( undefinedp( family[familys[i]] ) ||
            undefinedp( family[familys[i]][id] ) )
        continue;
        map_delete( family[familys[i]], id );
    }
}
