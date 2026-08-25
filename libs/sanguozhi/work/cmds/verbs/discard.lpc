/*
** discard.c by fire on Jan 15
**
*/
#include <mudlib.h>
#include <setbit.h>
#include <classes.h>
#include <edit.h>
inherit M_INPUT;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_NEWSMSG;
inherit VERB_OB;
string ngroup;
int p_id=0;

private nomask int filter_removed(int elem) {
    class news_msg msg = NEWS_D->get_message(ngroup, elem);
    
    if (!msg || !msg->body)
        return 0;
    return 1;
}
private nomask void receive_remove_verify(string str)
{
    if ( str[0] != 'y' && str[0] != 'Y' )
    {
        write("放弃删除。\n");
        return;
    }
    NEWS_D->remove_post(ngroup, p_id);
    write ("删除完毕。\n");
}
void do_discard_str(string st)
{
    class news_msg msg;
    int id;
    int * ids;
    object o;

//        ngroup=environment(this_body())->query_board();
//  write("this my discard.c\n");
	o=present("news board",this_body()->query_room());

	if (!objectp(o))
        {
              printf("这儿没有留言可删除呀。\n");
              return;
        }
	ngroup=o->query_group();
        if (sscanf(st, "%d", id) != 1)
        {
		write( "你要删除第几条留言？\n");
		return;
	}
	ids = sort_array(filter_array(NEWS_D->get_messages(ngroup),(: filter_removed :)), 1);
        if (id <= 0 || id > sizeof(ids))
        {
            printf("留言板上没有这条留言。\n");
	    return;
	}
	p_id=ids[id-1];
	msg=NEWS_D->get_message(ngroup, p_id);
 if(msg->userid != this_user()->query_userid() &&
 !(ngroup[0..5]=="nation" && ngroup[7..]==this_user()->query_userid())
           //above added by suicide for emperor to delete the useless title
           //in their own country board 2000/03/19
          )
        {
    	    write("你只能删除自己写的留言。\n");
            return;
        }
if ( (msg->userid!=this_user()->query_userid()) && ngroup[0..5]=="nation" && ngroup[7..]==this_user()->query_userid() )
           if ( (time()-msg->time)<86400)
              {
    	        write("这个留言还没过一天的时限，你暂时无法删除。\n");
                return;
              }

	NEWS_D->remove_post(ngroup, p_id);
    	write ("删除完毕。\n");

//        printf( "确定删除吗？[yn] > ");
//        modal_simple((: receive_remove_verify :));
}
mixed * query_verb_info()
{
    return ({ ({ "STR" }) });
}
