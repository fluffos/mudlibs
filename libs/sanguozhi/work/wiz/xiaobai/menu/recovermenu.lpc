
#include <menu.h>
#include <mudlib.h>
#include <verb.h>

#define _DEBUG_ID   "xiaobai"

#define MAIN_TITLE       "\n恢复jianxu国的某些数据："

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;

private MENU p_mnMain;
private MENU_ITEM p_quit_item;
private MENU_ITEM p_seperator;

private void confirm( string par_strPara );
private void action( string par_strPara );
private void action_taishou();
private void action_char();

private void quit()
{
    quit_menu_application();    
             
}  // end quit

void start_menu()
{
    init_menu_application( p_mnMain );
}

void create()
{
    set_privilege(1);

    p_mnMain = new_menu( MAIN_TITLE );

    p_quit_item = new_menu_item( "退出", (: quit :), "q" );
    p_seperator = new_seperator("-------------------------------------------------------------------------");
    add_menu_item( p_mnMain, p_seperator);
    add_menu_item( p_mnMain, new_menu_item("恢复角色(char)", (: confirm, "c" :) ,"c"));
    add_menu_item( p_mnMain, new_menu_item("自选太守(taishou)", (: confirm, "t" :) ,"t"));
    add_menu_item( p_mnMain, p_quit_item);
   
    set_menu_prompt ( p_mnMain, "输入指令[cq]: ");
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, "exiting create()" );
#endif  // _DEBUG_ID
    
}  // end create

private void confirm( string par_strPara )
{
    switch ( par_strPara )
    {
    case "c":
        write( "将所有在野角色提为当地的闲职。\n" );
        break;
    case "t":
        write( "给所有没有太守的城市自动选太守。\n" );
        break;            
    default:
        break;
        
    }  // end switch

    get_input_then_call( (: action, par_strPara :), "确定吗？( yES / nO ): " );
}
private void action( string par_strPara, string par_strFlag )
{
    if ( par_strFlag != "y" )
    {
        write( "取消操作\n" );
        return;
    }
    
    switch ( par_strPara )
    {
    case "c":
        action_char();
        break;
    case "t":
        action_taishou();
        break;
            
    default:
        break;
        
    }  // end switch
    
}

private void action_char()
{
    string * citylist = AREA_D->list_areas();
    int nCityNum = sizeof( citylist );
    int i = 0;
    string * strCharArr;
    string strChar;
    string strCity;
    string strNation;
           
    write( "执行命令\n" );
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "got %d cities", nCityNum ) );
#endif  // _DEBUG_ID

    // loop for the cities
    for ( i = 0; i < nCityNum; i++ )
    {
        strCity = citylist[i];
                
        strNation = AREA_D->get_area( strCity, "nation" );

        if ( strNation != "jianxu" )
        {
            continue;
        }
            
        write( strCity + " of " + strNation + "...\n" );
        
        // get all user char of the city
        strCharArr = CHAR_D->check_char_area( "is_tmp", 0, strCity);
        strCharArr = filter_array( strCharArr, (:( CHAR_D->get_char( $1, "nation" ) == 0 ) :) );
//        strCharArr = filter_array( strCharArr, (:(chars[$1][$(para_name)]==$(para_value)) :));

#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "%s 有 %d 个在野玩家", strCity, sizeof(strCharArr) ) );
#endif  // _DEBUG_ID

        // 所有在野的 char 当上闲职
        foreach ( strChar in strCharArr )
        {
            write( strChar + "," );
//            CHAR_D->set_char( strChar, "nation", strNation );
//            CHAR_D->set_char( strChar, "ranklocal", 1000 );
            
        }
        
        write( "\n" );

    }
    
    prompt_then_return();
}

private void action_taishou()
{
    string * citylist = AREA_D->list_areas();
    int nCityNum = sizeof( citylist );
    int i = 0;
    string strCity;
    string strNation;
           
    write( "执行命令\n" );
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "got %d cities", nCityNum ) );
#endif  // _DEBUG_ID

    // loop for the cities
    for ( i = 0; i < nCityNum; i++ )
    {
        strCity = citylist[i];
                
        strNation = AREA_D->get_area( strCity, "nation" );

        if ( strNation != "jianxu" )
        {
            continue;
        }
            
        write( strCity + " of " + strNation + "...\n" );
        
        AREA_D->auto_head( strCity );
    }
    
    prompt_then_return();
}
