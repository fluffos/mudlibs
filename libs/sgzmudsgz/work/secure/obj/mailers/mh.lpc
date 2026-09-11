// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Mh.c
**
** Command-line driven mailer.
**
** Written by Rust at some point in time.
** SEP-NOV '94: Updated/revised by Deathblade (for all kinds of stuff).
*/

//### Needs some work, I think.  Does it still work?

#include <playerflags.h>
#include <mudlib.h>
#include <daemons.h>

inherit MAILER;


private void Mh_cmd_write(string arg)
{
    int num;
    string fname;

    if(!arg || (sscanf(arg,"%d %s",num,fname)!=2&&
    (sscanf(arg,"%s",fname)!=1)))
    {
    //write("Usage: Mw # <filename>\n");
    write("用法：Mw <number> <filename>\n");
    return;
    }

    cmd_read(num, fname, 1);
}


private void Mh_cmd_save(string arg)
{
    int num;
    string fname;

    if(!arg || (sscanf(arg,"%d %s",num,fname)!=2&&
    sscanf(arg,"%s",fname)!=1))
    {
    //write("Usage: Ms # <filename>\n");
    write("用法：Ms <number> <filename>\n");
    return;
    }

    cmd_read(num, fname, 0);
}


private void Mh_cmd_replyall(mixed arg)
{
    if ( arg && !(arg = to_int(arg)) )
    {
    //write("Usage: MR #\n");
    write("用法：MR <number>\n");
    return;
    }

    cmd_reply(arg, 1);
}


private void Mh_cmd_reply(mixed arg)
{
    if ( arg && !(arg = to_int(arg)) )
    {
    //write("Usage: Mr #\n");
    write("用法：Mr <number>\n");
    return;
    }

    cmd_reply(arg, 0);
}


private void Mh_cmd_help()
{
    string* output;

    output = explode(
      //"Help for Mh (Mail handler)  Version 0.9\n"+
      "Mh (Mail handler) 的辅助说明 Version 0.9\n"+
      sprintf("%'-'40s","\n")+
      //"M?                   This help screen\n"
      "M?                               本说明屏幕\n"
      "\n"
      //"Mm <name1> [name2] [name3]...        Send mail.\n"
      "Mm <name1> [name2] [name3]...    寄信。\n"
      //"Mh [# or range (1-4,6 for example)]   Show the headers for the specified\n"
      "Mh [# or 范围 (比如 1-4,6)]      显示指定的或全部信件的开头。\n"
      //"                 range of messages, or all messages\n"
      //"                 if no range is specified.\n"
      //"M# #                 Read a message.\n"
      "M# #                             读取信件。\n"
      //"Mr #                 Reply to message\n"
      "Mr #                             回复信件。\n"
      //"MR #                 Reply to message, all\n"
      "MR #                             回复信件给所有寄信人。\n"
      //"                 originial recipients receive the mail\n"
      //"Mf #                 Forward message\n"
      "Mf #                             转寄信件。\n"
      //"Md # or range                Delete message(s)\n"
      "Md # or 范围                     删除信件。\n"
      //"M$                   Show the number of messages in your box.\n"
      "M$                               显示信件总数。\n"
      //"M= [#]                   Set current message if # is provided\n"
      "M= [#]                           设定读取信件的号码如果有参数 # ，\n"
      "                                 否则显示现在信件。\n"
      //"                 else shows the current message #\n"
      //"M+                   increment the current message number\n"
      "M+                               读取信件的号码加一，并不显示。\n"
      //"                 but do not read.\n"
      //"M-                   decrement the current message number\n"
      "M-                               读取信件的号码减一，并不显示。\n"
      //"                 but do not read.\n"
      //"Mn                   read the next message."
      "Mn                               显示下一封信件。\n"
      ,"\n");
    if( wizardp(this_user()) )
    output += ({
      //"Ms [#] <filename>            Save message w/ header intact to file.",
      //"Mw [#] <filename>            Save message but no header to file." });
      "Ms [#] <filename>                将信件头以及信件内容存档。",
      "Mw [#] <filename>                将信件内容存档，不包括信件头。" });
    output+=({"",
      "All numbers default to the currently referenced message, which is shown",
      "by M=\n",
      "","Groups may also be mailed to, see help for groups on how to set them",
      "up.... you can mail to them like a regular name, or you can enclose",
      "The group in ().  Eg, Mm (admin) rust  will mail all the admins and rust."});
    more(output);
}


private void Mh_cmd_forward(mixed arg)
{
    mixed   newto;
    int     num;

    if(!arg || (sscanf(arg,"%d %s",num,newto)!=2&&
        (sscanf(arg,"%s",newto)!=1)))
    {
    //write("Usage: Mf # <name1> [name2] ...\n");
    write("用法：Mf # <name1> [name2] ...\n");
    return;
    }

    cmd_forward(num, newto);
}


nomask int parse_Mh_cmd(string input)
{
    string  arg;

ZBUG("FOO");
//### we need to validate the caller!

    if( strlen(input) > 2 && input[1] == ' ' )
    arg = input[2..];
    else if( strlen(input) > 2 )
    return 0;

    switch( input[0] )
    {
    case 'h':
    cmd_headers( arg );
    return 1;
    case 'm':
    cmd_mail( arg );
    return 1;
    case 'R':
    Mh_cmd_replyall( arg );
    return 1;
    case 'r':
    Mh_cmd_reply( arg );
    return 1;
    case '?':
    Mh_cmd_help();
    return 1;
    case 'd':
    cmd_delete( arg );
    return 1;
    case 'f':
    Mh_cmd_forward( arg );
    return 1;
    case '#':
    cmd_read(to_int(arg), 0, 0);
    return 1;
    case 's':
    Mh_cmd_save( arg );
    return 1;
    case '=':
    cmd_setcurrent( arg );
    return 1;
    case 'w':
    Mh_cmd_write( arg );
    return 1;
    case 'n':
    {
        int idx;

        idx = mailbox_ob->first_unread_message() + 1;
        if ( !idx )
            //printf("No more messages.\n");
            printf("没有更多的信件了。\n");
        else
            cmd_read(idx, 0, 0);
    return 1;
    }
    case '+':
    cmd_setcurrent(mailbox_ob->query_message_index()+2 );
    return 1;
    case '-':
    cmd_setcurrent(mailbox_ob->query_message_index() );
    return 1;
    case '$':
    printf(//"You have %d messages.\n",
           "你共有 %d 封信件。\n",
            mailbox_ob->query_message_count());
    return 1;
    default:
    return 0;
    }
}

/*
** Compat with the modal-version.  Tell user what is up.
*/
nomask void begin_mail(string arg)
{
    //write("You are set up for Mh, the command-line mail handler.\n"
    //  "Type M? for info.\n");
    write("你已经建立了Mh，命令行邮件处理器。\n用 M? 显示辅助信息。\n");
}
