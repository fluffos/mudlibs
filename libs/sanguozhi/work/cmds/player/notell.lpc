// notell.c
/* Do not remove the headers from this file! see /USAGE for more info. */
// 加减不能用 tell 和你联系的玩家 id, 或设置你对方试图 tell 时看到的信息
// by xiaobai, Sep. 2001

#include <mudlib.h>
#include <commands.h>

inherit CMD;
inherit M_GRAMMAR;
inherit M_COMPLETE;
inherit M_ANSI;

#define MAX_NOTELL  10

//! check whether an id is a player
private int is_player( string par_strId );

//! show the help and the current settings
private void show_message();

void create()
{
    ::create();
    no_redirection();
}

private void main( string arg )
{
    string strSetting;
    string* strNotellIds;
    string strMessage = "";
    int nTest = 0;
    
    if( !arg || arg == "" )
    {
        show_message();                
        return;
    }
    
    strMessage = this_body()->query_notell();

    // want to change ids    
    if ( arg[0] == '+' || arg[0] == '-' )
    {
        strSetting = trim_spaces( arg[1..<1] );
        // the old settings
        strNotellIds = this_body()->query("notell_ids");
        
        if ( !strNotellIds )
            strNotellIds = ({});
                
        if ( arg[0] == '+' )
        {
            nTest = is_player( strSetting );
            
            if ( !nTest )
                return;            
            // add id to the notell string
            else 
            {
                if ( sizeof( strNotellIds ) >= MAX_NOTELL )
                {
                    outf( "最多只能设置%d个玩家。\n", MAX_NOTELL );
                }
                else if ( member_array( strSetting, strNotellIds ) != -1 )
                {
                    outf( "玩家%s已经在名单里了。\n", strSetting );
                }                
                else
                {
                    // add an id to the list
                    strNotellIds += ({strSetting});
                    out( "完成。\n" );
                }               
            }
        }
        else if ( arg[0] == '-' )
        {
            if ( lower_case( strSetting ) == "$all" )
            // clear the id list
            {
                strNotellIds = ({});
            }
            else
            {
                nTest = is_player( strSetting );
                if ( !nTest )
                    return;
                else
                // remove an id from the id list
                {
                    strNotellIds -= ({strSetting});
                    out( "完成。\n" );                    
                }
            }
        }
        
        // save the notell id list
        this_body()->set( "notell_ids", strNotellIds );

    }
    else
    {
        strMessage = arg;    
        this_body()->set_notell( strMessage );
        out( "完成。\n" );
    }
    
    if ( !strMessage || strMessage == "" )
    // if the notell message is not set, set a default message
    {
        strMessage = "对方不想理你。\n";
        this_body()->set_notell( strMessage );
    }
    
    show_message();
            
}

private void show_message()
{
    string strIds = "";
    string* strArr = ({});
    
    out("notell 的用法: \n\t当你不愿再听到某人咯嗦你：notell +<user>\n");
    out("\t当你想念一个曾经令你觉得很烦的人：notell -<user>\n");
    out("\t当你重新觉得所有人都有些可爱：notell -$all\n");
    out("\t当你想换一种拒绝人的借口：notell <message>\n");
    out("\t例如：notell 小白现在没有空\n");

    // 显示当前的设置
    out( "\n" );
    out( "目前的 notell 口信：\n" );
    outf( "\t%s\n", this_body()->query_notell() );
    out( "目前你不想理会的人 ：\n" );
    // 融合所有 id 为一个字符串
    strArr = this_body()->query("notell_ids");
    if ( !strArr )
        strArr = ({});
    strIds = implode( strArr, "," );
    outf( "\t%s", strIds  );
    
}  // end show_message

// check whether an id is a player
private int is_player( string par_strId )
{
/* 这个方法不好 
    object obj = find_body( par_strId );
        
    if ( !obj )
    {
        write( sprintf( "%s不是在线玩家，不可能骚扰你。\n", par_strId ) );
        show_message();
        return 0;
    }    
*/
    return 1;

}  // end is_player

///////////////////// EOF ////////////////////////////////
