/* rmarea.c by fire on 16/06/98
this cmd is used to remove an area
in the sg system, this cmmond should
set some priviliage in case careless
wiz may delete data just by testing
usage: rmarea <area_id>
example: rmarea luoyang
*/
// last modified by xiaobai at Oct. 22, 2001
//      这个命令有点危险，为了防止误操作，做了些改动
//          1。admin 才有执行权限
//          2。经过确认才执行
//

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

//! 提醒使用者确定，只有输入 "y" 时， 才执行操作
private int confirm( string par_strId, string par_strInput );
//! 经确认后，执行操作
private void execute( string par_strCityId );
//！终止操作
private void abort();

nomask private void main(string str)
{
	string p_id=str;
    string extra = 0;
    
    if ( !adminp(this_body()) )
    // 只有 admin 才有权限
    {
        write( "抱歉，只有 admin 才有权执行这个命令。\n" );
        return;
    }
 
    if (!str)
    {
        write("用法：rmarea <area_id>\n");
        return;
    }
    
    sscanf(p_id, "%s %s", p_id, extra);
    
    if ( extra )
    {
        write("地区名之间不得有空格．\n");
		return;
	}

    write( "\n这个命令用于删除某一个三国城市，命令执行后，该城市的所有数据将会丢失。\n\n" );
    
    this_body()->modal_push((: confirm, p_id :),"要继续的话，请输入 “y”；否则，请输入“n”：");
    call_out( "abort", 60 );

}

//! 提醒使用者确定，只有输入 "y" 时， 才执行操作
private int confirm( string par_strId, string par_strInput )
{
    if ( par_strInput == "y" )
    {
        this_body()->modal_pop();
        execute( par_strId );        
    }
    else
        abort();
    
}

//! 经确认后，执行操作
private void execute( string par_strCityId )
{
    string extra = 0;
	
	write( "命令被执行。\n" );
//	extra=AREA_D->remove_area( par_strCityId );
//	write( extra );
}

//！终止操作
private void abort()
{
    remove_call_out("abort");
    write( "命令终止。小心谨慎是一个良好的习惯。\n" );
    this_body()->modal_pop();
}
