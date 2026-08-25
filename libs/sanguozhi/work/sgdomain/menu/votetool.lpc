/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** votetool.c
**
** 20000409, suicide@sgz
*/
#include <mudlib.h>
#include <classes.h>
#include <edit.h>
inherit M_INPUT;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_NEWSMSG;
#define VOTE_GROUP      "vote"
#define STANDARD_WRAP_WIDTH     68
#define FOLLOWUP_WRAP_WIDTH     76
nomask void receive_top_cmd(string cmd);
nomask void receive_grp_cmd(string cmd);
nomask void receive_msg_cmd(string cmd);
private nosave string* vote_memo;
private nosave int item_count=1;
private nosave string vote_subject;
private string* items=({});
private nosave int vote_count,readright,writeright;
private nomask void init_static_var()
{
vote_memo=({});
item_count=1;
vote_subject="";
items=({});
readright=1;
writeright =1;
}
private nomask void quit_vote()
{
    /* save the player's news reading state */
    this_body()->save_me();
    modal_pop();
    destruct();
}
varargs private nomask int get_current_id(string group_name)
{
    if ( !group_name )
        group_name = VOTE_GROUP;
    /*
    ** -1 to get the "current" message.  The body records the _next_
    ** message to read.
    */
    return this_body()->get_news_group_id(group_name)-1 ;
}
private int count_unread_messages(string group, int all_messages)
{
    int * ids = NEWS_D->get_messages(group);
    int id;
    class news_msg msg;
    int count = 0;
    int read_thru_id;
    read_thru_id = get_current_id( group );
    if ( !all_messages )
    {
        ids = filter_array(ids, (: $1 > $(read_thru_id):));
    }
    foreach ( id in ids )
    {
        msg = NEWS_D->get_message(group, id);
        if ( msg->body )
        {
            count++;
        }
    }
    return count;
}
private nomask string format_group_line(string group)
{
    int last_id;
    int unread = count_unread_messages(VOTE_GROUP, 1);
    last_id = NEWS_D->get_group_last_id(VOTE_GROUP);
    return sprintf("  %-40s (%d 条表决, %d 条未读)",
      "表决投票",
      unread,
      count_unread_messages(VOTE_GROUP, 0));
}
private nomask string msg_cmd_prompt()
{
    return sprintf("(%s:%d条) %d 条未读 [q?lLpvMD] > ",
      "投票表决",
      get_current_id(VOTE_GROUP),
      count_unread_messages(VOTE_GROUP, 0)
    );
    
}
private nomask void switch_to_message()
{
    modal_func((: receive_msg_cmd :), (: msg_cmd_prompt :));
}
private nomask varargs
string format_message_line(int short_fmt, int id, int noremoved)
{
    class news_msg msg;
    string subject;
    msg = NEWS_D->get_message(VOTE_GROUP, id);
    if (!msg || ! msg->body) {
        if (noremoved)
            return 0;
        else
            subject = sprintf(short_fmt ? "%d. %s" : "%4d. %-35s", id, " (已删除)");
    } else
        subject = msg->subject;                                                         
                               
    return sprintf(short_fmt ? "%d. %s  [%s on %s]" :
      "%4d. %-35s [%-10s on %s]",
      id,
      subject[0..34],
      msg->poster,
      intp(msg->time) ? ctime(msg->time)[4..9] : msg->time);
}
private nomask void display_messages(int display_all)
{
    int *       ids;
    string *    lines;
    ids = NEWS_D->get_messages(VOTE_GROUP);
    if ( !display_all )
    {
        int read_thru_id;
        read_thru_id = get_current_id();
        ids = filter_array(ids, (: $1 > $(read_thru_id) :) );
    }
    lines = map_array(sort_array(ids, 1), (: format_message_line(0, $1, 1) :)) - ({ 0 });
    lines = ({(display_all?"所有的表决有:":"未读的表决有:")}) + lines + ({""});
    more(lines);
}
nomask void wrap_post(string * text)
{
    int i = sizeof(text);
    while ( i-- )
    {
        /* only wrap really long lines */
        if ( sizeof(text[i]) > 78 )
        {
            /* wrap to different widths, based on the text */
            int width = text[i][0]=='>' ? FOLLOWUP_WRAP_WIDTH : STANDARD_WRAP_WIDTH;
            if ( sizeof(text[i]) > width )
                text[i] = wrap(text[i], width);
        }
    }
}
private nomask void receive_vote_writeright(string str)
{int sel,id;
 if (str=="") 
    { write("选择错误，重新选择:");
      modal_simple((: receive_vote_writeright:));
    }
 else{
      sscanf(str,"%d",sel);
      if (sel<1||sel>5) 
         { write("选择错误，重新选择:");
          modal_simple((: receive_vote_writeright:));
         }
      else
         {writeright = sel;
          //vote_memo += items;
          id = NEWS_D->post(VOTE_GROUP, vote_subject, implode(vote_memo, "\n") + "\n");
          VOTE_D->add_selectitem(id,items,readright,writeright);
          write("成功加入表决: " + format_message_line(1, id) + "\n");
         }     
    }
}
private nomask void receive_vote_readright(string str)
{int sel;
 if (str=="") 
    { write("选择错误，重新选择:");
      modal_simple((: receive_vote_readright:));
    }
 else{
      sscanf(str,"%d",sel);
      if (sel<1||sel>5) 
         { write("选择错误，重新选择:");
          modal_simple((: receive_vote_readright:));
         }
      else
         {readright = sel;
          write("投票权利: (1-全体玩家角色 2-本国玩家角色 3-本国官员 4-所有官员 5-巫师)\n");
          write("请选择本表决的投票权利:");
          modal_simple((: receive_vote_writeright :)); 
         }     
    }
}
private nomask void receive_vote_selectitem(string selectitem);
private nomask void receive_selectitem_verify(string str)
{   //int id;
    if ( str[0] == 'n' || str[0] == 'N' )
    {
        write("放弃前面设定，重新添加新的表决选项\n");
        item_count=1;
        items=({});
        write(sprintf("设定表决选项(%d)：",item_count));
        modal_simple((: receive_vote_selectitem :));
        
    }
    else if ( str[0] == 'y' || str[0] == 'Y' )
    {write("%^RED%^表决选项输入完成!%^RESET%^\n");
     write("读权利: (1-全体玩家角色 2-本国玩家角色 3-本国官员 4-所有官员 5-巫师)\n");
     write("请选择本表决的读权利:");
     modal_simple((: receive_vote_readright :));      
    	/*vote_memo += items;
        id = NEWS_D->post(VOTE_GROUP, vote_subject, implode(vote_memo, "\n") + "\n");
        VOTE_D->add_selectitem(id,items);
        write("成功加入表决: " + format_message_line(1, id) + "\n");*/
     }
    else
    { write("选择错误，重新选择 [yn] > ");
      modal_simple((: receive_selectitem_verify:));
    }
    
    
}
private nomask void receive_vote_selectitem(string selectitem)
{ //int id;
  //printf("selectitem = %s\n",selectitem); 
  if ( selectitem == "" )
    {
        //write("Post aborted.\n");
        if (item_count==1)
           write("放弃添加新的表决。\n");
        else
           {
            write("表决选项添加完毕，你确定吗？[yn] > ");
            modal_simple((: receive_selectitem_verify:));	
            /*vote_memo += items;
            id = NEWS_D->post(VOTE_GROUP, vote_subject, implode(vote_memo, "\n") + "\n");
            VOTE_D->add_selectitem(id,items);
            write("成功加入表决: " + format_message_line(1, id) + "\n");*/
           }
        return;
    } 
 items += ({sprintf("(%d) %s",item_count,selectitem)});
 item_count++;
 write(sprintf("设定表决选项(%d)：",item_count));
 modal_simple((: receive_vote_selectitem :));
}  
private nomask void receive_post_text(string subject, string * text)
{
    //int id;
    if ( !text )
    {
        write("Post aborted.\n");
        write("放弃张贴新闻。\n");
        return;
    }
    wrap_post(text);
    vote_subject = subject;
    vote_memo = text;
    write(sprintf("设定表决选项(%d)：",item_count));
    modal_simple((: receive_vote_selectitem :));
    //id = NEWS_D->post(VOTE_GROUP, subject, implode(text, "\n") + "\n");
    //write("Posted:  " + format_message_line(1, id) + "\n");
}
private nomask void receive_post_subject(mixed subject)
{
    if ( subject == -1 )
        destruct(this_object());
    if ( subject == "" )
    {
        //write("Post aborted.\n");
        write("放弃张贴新闻。\n");
        return;
    }
    new(EDIT_OB, EDIT_TEXT, 0, (: receive_post_text, subject :));
}
private nomask void post_message()
{   int ret;
    //write("Subject: ");
    ret = VOTE_D->can_post(this_user());
    if (stringp(ret))
      {write(ret);
       return;
      }
    init_static_var();   
    write("表决题目：");
    modal_simple((: receive_post_subject :));
}
private nomask class news_msg get_current_message()
{
    class news_msg msg;
    msg = NEWS_D->get_message(VOTE_GROUP, get_current_id());
    if ( !msg || !msg->body )
        return 0;
    return msg;
}
private nomask int read_next_message(int skip_allowed)
{
    int msg_id;
    int skipped;
    class news_msg msg;
    string post,ret;
    int last = NEWS_D->get_group_last_id(VOTE_GROUP);
    //item_count = 1;
    //items = ({});
    
    msg_id = get_current_id() + 1;
    do
    {        
        if ( msg_id > last )
        {
            /*
            ** Do a bit of extra work when messages have been skipped.
            */
            if ( skipped )
            {
                printf(//"Skipped %d removed messages.\n",
                       "跳过 %d 封已删除的表决。\n",
                  msg_id - (get_current_id() + 1));
                /*
                ** Update the body's current message number (to mark all
                ** as read).
                */
                this_body()->set_news_group_id(VOTE_GROUP, msg_id);
            }
            //write("No more messages.\n");
            write("没有新的表决了。\n");
            return 1;
        }
        msg = NEWS_D->get_message(VOTE_GROUP, msg_id);
        
        if ( msg && msg->body )
        {
            /* don't loop any more... take this message */
            skip_allowed = 0;
        }
        else if ( skip_allowed )
        {
            /* mark we have skipped at least one... move ahead for more */
            skipped = 1;
            ++msg_id;
        }
    } while ( skip_allowed );
    if ( skipped )
    {
        printf(//"Skipped %d removed messages.\n",
               "跳过 %d 封已删除的留言。\n",
          msg_id - (get_current_id() + 1));
    }
    /*
    ** Set the next-to-read id.  Always move to the message prompt.
    */
    this_body()->set_news_group_id(VOTE_GROUP, msg_id + 1);
    switch_to_message();
   ret=VOTE_D->can_read(msg_id,this_user()->query_userid());
   if (stringp(ret))
    {
    write(ret);
    return 0;
    }
    if ( msg ) {
        post = sprintf("时间:  %-40sPost-id: %d (%d Last)\n"
                "作者:  %s\n"
                "题目:  %s\n"
                "----------------------------------------------------------------------\n"
                "%s",
                intp(msg->time) ? ctime(msg->time) : msg->time,
                msg_id,
                NEWS_D->get_group_last_id(VOTE_GROUP),
                msg->poster,
                msg->subject,
                msg->body ? msg->body : "*** 已删除 ***");
       
    }
    else {
        post = sprintf("Post-id: %d (%d Last)\n\n*** 已删除 ***",
                       msg_id, NEWS_D->get_group_last_id(VOTE_GROUP));
    }
    more(post);
    VOTE_D->show_vote_result(get_current_id());
    return 0;
}
varargs nomask void begin_reading(string arg);
private nomask void global_commands(string cmd)
{
    if( cmd == "q" )
    {
        quit_vote();
    }
    else 
    {
        write("无此命令，用 ? 来获取帮助信息。\n"); 
        //"Unknown command. Type ? for help.\n");
    }
}
private nomask void group_commands(string cmd)
{
    int id;
    if ( cmd == "l" || cmd == "L" )
    {
        display_messages(cmd == "L");
    }
    else if ( cmd == "p" )
    {
        post_message();
    }
    else if ( cmd == "" )
    {
        read_next_message(1);
    }
    else if( id = to_int(trim_spaces(cmd)) )
    {
        if ( id < 1 )
            id = 1;
        else if ( id > NEWS_D->get_group_last_id(VOTE_GROUP) )
            id = NEWS_D->get_group_last_id(VOTE_GROUP);
        this_body()->set_news_group_id(VOTE_GROUP, id);
        read_next_message(0);
    }
    else
    {
        global_commands(cmd);
    }
}
private nomask void receive_remove_verify(string str)
{   int cur_id = get_current_id();
    if ( str[0] != 'y' && str[0] != 'Y' )
    {
        //write("Removal aborted.\n");
        write("放弃删除。\n");
        return;
    }
    NEWS_D->remove_post(VOTE_GROUP, cur_id);
    VOTE_D->remove_vote(cur_id);
}
private nomask void remove_message()
{
    class news_msg msg = get_current_message();
    if ( !msg )
    {
        //write("This post has already been removed.\n");
        write("这个贴子已经被删除了。\n");
        return;
    }
    if ( !adminp(this_user()) &&
      msg->userid != this_user()->query_userid() )
    {
        //write("You are not allowed to remove that post.\n");
        write("你无权删除那张帖子。\n");
        return;
    }
    printf(//"Removing: %s\nAre you sure? [yn] > ",
           "准备删除：%s\n你确定吗？[yn] > ",
      format_message_line(1, get_current_id()));
    modal_simple((: receive_remove_verify :));
}
private nomask void receive_vote_select(string sel)
{int sel_id;
 if (sel == "")
    {
    write("%^YELLOW%^你突然决定暂时先不参加这次表决. %^RESET%^\n");
    return;
    }
 sscanf(sel,"%d",sel_id); 
 if ((sel_id<1) || (sel_id>vote_count))
    {
     write("%^YELLOW%^没有此对应的选择项，无效选择，请重选!%^RESET%^\n请输入你赞同的选择: ");
     modal_simple((: receive_vote_select :));
    }
 else
    VOTE_D->set_vote(get_current_id(VOTE_GROUP),sel_id,this_user()->query_userid());
 vote_count = 0;
} 
private nomask void do_vote()
{mapping items;
 mixed ret;
 int vote_id = get_current_id(VOTE_GROUP); 
 ret=VOTE_D->can_vote(vote_id,this_user()->query_userid());
 if (stringp(ret))
    {
    write(ret);
    return;
    }
 items = VOTE_D->get_selectitems(vote_id);
 if (!items)
    {write("%^RED%^不知什么原因这项表决的信息丢失了，无法进行表决!%^RESET%^\n");
     return;
    }
 vote_count = sizeof(keys(items));
 for (int i=1;i<=vote_count;i++)
     printf("%%^RED%%^(%d) %s%%^RESET%%^\n",i,items[i]);
 write("请输入你赞同的选择: ");
 modal_simple((: receive_vote_select :));
}
private nomask void receive_msg_cmd(mixed cmd)
{   if (cmd == -1) {
        destruct(this_object());
        return;
    }
    cmd = trim_spaces(cmd);
    if ( cmd == "?" )
    {
        write("\n这是投票表决的命令选单：\n"
              "     q           - 退出表决\n"
              "     ?           - 本帮助\n"
              "     l           - 列出未读的表决\n"
              "     L           - 列出所有的表决\n"
              "     p           - 添加新的表决\n"
              "     v           - 参加表决\n"
              "     M           - 发布表决结果[自己/大神]\n"
              "     D           - 删除正在阅读的表决\n"
              "   <回车>        - 读取下一条表决\n"
              "\n"
              "键入命令然后回车就行了。\n");
    }
    else if (cmd == "D" )
    {
        remove_message();
    }
    else if (cmd == "v" )
    {
    	do_vote();
    }
    else if ( cmd == "M" )
    {
        write( "发布表决结果？[y/N]");
    }
    else
    {
        group_commands(cmd);
    }
}
void begin_reading()
{
    if (member_array(VOTE_GROUP,NEWS_D->get_groups())==-1)
    {
        printf( //"%s has no newsgroups right now.\n"
                "%s目前尚未开放表决新闻组。\n", mud_name());
        destruct();
        return;
    }
    display_messages(1);
    modal_push( (: receive_msg_cmd :), (:msg_cmd_prompt :));
   
}
