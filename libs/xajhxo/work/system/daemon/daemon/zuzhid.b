//  groupd.c (?) or orgd.c or zuzhid.c 
//  first edit at 97-08-14 00:41
//  by Lin
//  说明：
//    每个组织有一个自己的文件"zuzhi".c，放在/system/feature/zuzhi/下面，
//  用来记载每个组织的一些数据库和单独的函数。每个人应该允许参加多个组织
//  正因为如此，一般上不应该让别人看到这个人的组织归属情况。
//  现在最大的问题就是：组织应该是可以重叠参与的，所以，怎么决定表现出来的是哪个
//  组织的数据呢？
//      首先，可以是最后进入的组织。
//  现在还是决定不让其它人看到组织属性，如果另一个人是你所在的组织中的上级，那么
//  他可以看到你是这个组织的什么人。（这个交给look.c去完成）
//  由于有TRILL 原来用的"zuzhi"数据存在，现在的组织数据改用"group"这个mapping.
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

void SetupZuzhi( object who, string zuzhiname, string touxian, string zhiwu );
  //  初始化
void IncreaseStep( object who, string zuzhiname, int step );//  现在没有97-8-27 
  //  在组织中的级别升级
void DeleteZuzhi( object who, string zuzhiname );
  //  离开组织的数据删除工作
  //  同时应该另置标以记录曾经参加过的组织情况。
void IncreaseTouxian( object who, string zuzhiname, int step );
  //  升级

////////////////////////////////////////////////////////////////////////////////
mapping ToId = ([
    "一品堂"       : "yipin",
    "大宋禁军"     : "jinjun",
    "丐帮"         : "gaibang",
    "禁军"         : "jinjun",
    "西夏一品堂"   : "yipin",
]);

void create()
{
    seteuid( ROOT_UID );
    set("name", "组织精灵");
    set("id", "groupd");
}

void SetupZuzhi( object who, string zuzhiname, string touxian, string zhiwu )
{
    mapping zuzhi,this_zuzhi;
    string *all_touxian, *all_zhiwu, f_zuzhi;
   
    tell_object( who, "daemon ok1\n");
    if ( ToId[ zuzhiname ] )
        zuzhiname = ToId[ zuzhiname ];
        //ToId是汉字的转换mapping，有了它就可以随便用英文或中文给zuzhiname赋值了。
    f_zuzhi = ZUZHI_DIR + zuzhiname;// .c?
/*
    if ( f_zuzhi->RecruitMember( who, touxian, zhiwu, this_zuzhi[ "entertime" ] ) )
        return;
         给f_zuzhi一个记录的机会。 
         应该是用来将这个成员的信息记录在一个.o文件中以便作全局设定。  
         但是返回1等于是接管了SetupZuzhi这个函数的功能，（重载） 
     这个以后再说吧，先不给这个接口。 
*/
    tell_object( who,"daemon ok2\n");
    if ( file_size( f_zuzhi + ".c" ) < 0 )
        return notify_fail( "<<Error>>: zuzhiname wrong!\n" );
    tell_object( who,"daemon ok3\n");
    zuzhi = who->query( "group" );
    if ( !mapp( zuzhi ) )
        zuzhi = ([]);
    this_zuzhi = ([]);
    this_zuzhi[ "name" ] = f_zuzhi->QueryName( who );
    this_zuzhi[ "id" ] = f_zuzhi->QueryId( who );
    all_touxian = f_zuzhi->QueryTouxian( who );
    all_zhiwu = f_zuzhi->QueryZhiwu( who );
    this_zuzhi[ "entertime" ] = who->query( "mud_age" );
    if ( !this_zuzhi[ "touxian" ] = touxian ) 
        this_zuzhi[ "touxian" ] = all_touxian[ 0 ];
    if ( !this_zuzhi[ "zhiwu" ] = zhiwu )
        this_zuzhi[ "zhiwu" ] = all_zhiwu[ 0 ];
    this_zuzhi[ "lastcontacttime" ] = who->query( "mud_age" );
    this_zuzhi[ "score" ] = 0;
    //  组织信任度清零。
    zuzhi[ zuzhiname ] = this_zuzhi;
    tell_object( who,"daemon ok4\n");
    who->set( "group" , zuzhi );
    LOG_D->do_log( who, sprintf( "你加入%s，成为一名%s。", this_zuzhi[ "name" ],
                  this_zuzhi[ "touxian" ] ) );
    //f_zuzhi->RecruitMember( who, touxian, zhiwu, this_zuzhi[ "entertime" ] )；
    // 给f_zuzhi一个记录的机会。 
    // 应该是用来将这个成员的信息记录在一个.o文件中以便作全局设定。  
    // zuzhid.c也应该自己有一个存盘文件
    return;
}
void DeleteZuzhi( object who ,string zuzhiname )
{
    string f_zuzhi = ZUZHI_DIR + zuzhiname;
    if ( ToId[ zuzhiname ] )
        zuzhiname = ToId[ zuzhiname ];
    if ( !who->GetZuzhi( zuzhiname ) )
        return notify_fail("wrong: no such zuzhi in this account!!\n" );
    LOG_D->do_log( who, sprintf( "你退出了%s.", who->ZuzhiName( zuzhiname ) ) );
    if ( !f_zuzhi->FireMember( who ) )
        who->delete( "group/" + zuzhiname );
    //  一般FireMember()和RecruitMember()都不返回1.
    //  接口以便zuzhi进行什么追杀啦，通缉啦。。。。。。
    if ( who->IsMemberOf( zuzhiname ) )
        who->set( "group/" + zuzhiname + "/deleted" , 1 );
    return;
}
int SetScore( object who, string zuzhiname, int score )
{
    mapping tmp;
    if ( !who->IsMemberOf( zuzhiname ) )
        return 0;
    tmp = who->GetZuzhi( zuzhiname );
    tmp[ "score" ] = score;
    who->set( "group/" + zuzhiname , tmp );
    return 1;
}
int AddScore( object who, string zuzhiname, int score )
{
    mapping tmp;
    if ( !who->IsMemberOf( zuzhiname ) )
        return 0;
    tmp = who->GetZuzhi( zuzhiname );
    tmp[ "score" ] += score;
    who->set( "group/" + zuzhiname, tmp );
    return 1;
}
void IncreaseTouxian( object who, string zuzhiname, int step )
{
    string * all_touxian;
    string touxian;
    int i,jibie;
  
    all_touxian = ( ZUZHI_DIR + zuzhiname )->QueryTouxian( who );
    jibie = who->ZuzhiTouxianJibie( zuzhiname );
    who->set("group/" + zuzhiname + "/touxian", all_touxian[ jibie + 1 ] );
    return;
}
