// by tiantian(www.wangcf.com) 2001.4
// 建立帮派

#include <ansi.h>
#include <group.h>

int check_legal_id(string id);
int check_legal_name(string name);

int main( object me, string arg )
{
    string chinese,english,group,dir;
    object ob;

    seteuid( getuid(me) );

    if( !arg ) return notify_fail("指令格式：gbuild <中文> <英文>\n");

    if( sscanf(arg, "%s %s", chinese, english)!=2 )
        return notify_fail("指令格式：gbuild <中文> <英文>\n");

	if( me->query("group") )
		return notify_fail( "你已经加入一个帮派了。\n" );
	
    if( me->query("combat_exp") < EXP_GROUP_MASTER )
        return notify_fail("以你的江湖阅历和名望，恐怕无力领导一个帮派。\n");

    if(!check_legal_name(chinese))
        return 1;

    dir = resolve_path(GROUP_DIR, english);
	if( ! SECURITY_D->valid_write( dir + "/group.c", me, 0 ) )
		return notify_fail( "帮派目录权限没有正确设置，请通知巫师修改。\n" );
   
if( mkdir(dir) ) {
        write("OK。\n");

    }
    else {
        return notify_fail("此英文名已经被其他帮派使用了。\n");
    }

    mkdir( dir+"/npc" );
    mkdir( dir+"/eq" );
    mkdir( dir+"/obj" );

    cp(GROUP_DIR "group.c", dir + "/group.c");
    if (!(ob = load_object( dir + "/group.c"))) 
        return notify_fail("严重错误，请通知巫师！。\n");

    CHINESE_D->add_translate(english, chinese);

    me->set( "group/level", GROUP_MASTER );
    me->set( "group/group", english );
	me->set( "group/old_title", me->query("title") );
	me->set( "group/title",HIW "［" 
		+ to_chinese( me->query( "group/group" ) ) 
		+ HIW "］" HIC
		+ GROUP_D->query_rank( me )
		+ HIR "" NOR);
	me->set( "title", me->query( "group/title" ) );
  
    me->save();
    message( "channel:chat", HIC "【江湖传闻】："
    	+ me->query("name") + "今日组建［"HIW 
    	+ chinese + HIC"］。"HIG + me->query("name") 
        + HIC"为第一任" + GROUP_D->query_rank(me)
        + "。\n" NOR, users() );
    
	ob->set( "group_name", to_chinese( me->query( "group/group" ) ) );
    ob->set( "master", me->query("id"));
    ob->set( "group", me->query("group/group") );
	ob->set( "short", to_chinese( me->query( "group/group" ) ) + " " + ob->query( "short" ) );
    GROUP_D->save_group( me );
 /*
   me->move( GROUP_D->query_cwd(me) + "group");
*/
    me->setup();

    return 1;
}


int check_legal_name(string name)
{
    int i,j;
	string *group_type;

    i = strlen(name);
        
    if( (strlen(name) < 4) || (strlen(name) > 16 ) ) { 
        write("帮派中文名字必须是 2 到 8 个中文字。\n");
        return 0;
    }

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("请您用「中文」取帮派名字。\n");
			return 0;
		}
	}

	if( GROUP_D->is_banned( name ) ) {
		write( "这个名字会引起其他玩家误会。\n");
		return 0;
	}
	
	
    if( GROUP_D->query_type_index( name ) < 0 ) {
		group_type = GROUP_D->query_all_group_type();
		write( "所建帮派类必须为：" );
		write( group_type[0] );
		for( i = 1; i < sizeof( group_type ); i ++ ) {
			write( "、" );
			write( group_type[i] );
		}
		write( "。\n" );
		return 0;
	}
    
    return 1;
}

int check_legal_id(string id)
{
    int i;

    i = strlen(id);
         
    if( (strlen(id) < 3) || (strlen(id) > 15 ) ) {
        write("帮派英文名字必须是 3 到 15 个英文字母。\n");
        return 0;
    }
    while(i--) {
        if( id[i]<'a' || id[i]>'z' ) {
            write("帮派英文名字只能用小写的英文字母。\n");
            return 0;
        }
    }
    
    return 1;
}

int help(object me)
{
  write(@HELP
----------------------------------------
指令格式 : gbuild <中文名> <英文名>

建立一个帮派。

----------------------------------------
HELP
    );
    return 1;
}
