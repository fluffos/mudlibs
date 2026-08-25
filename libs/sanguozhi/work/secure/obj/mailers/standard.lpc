// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** standard.c
**
** The standard "mail" command.  This is a standard modal mailer, compared
** to the Mh-style mailer.
**
** Created 31-OCT-94, Deathblade.
*/

#include <playerflags.h>
#include <mudlib.h>
#include <daemons.h>

inherit MAILER;


private nomask string query_prompt()
{
    return sprintf(//"[%d of %d] mail: ",
                   "[%d of %d] 信件：",
      mailbox_ob->query_message_index() + 1,
      mailbox_ob->query_message_count());
}

private void stdmail_cmd_replyall(mixed cmd_args)
{
    if ( cmd_args && !(cmd_args = to_int(cmd_args)) )
    {
    //write("Usage: R #\n");
    write("用法：R <number>\n");
    return;
    }

    cmd_reply(cmd_args, 1);
}

private void stdmail_cmd_reply(mixed cmd_args)
{
    if ( cmd_args && !(cmd_args = to_int(cmd_args)) )
    {
    //write("Usage: r #\n");
    write("用法：r <number>\n");
    return;
    }

    cmd_reply(cmd_args, 0);
}

private void stdmail_cmd_help()
{
    string output;

    output =
    //"?                  This help screen\n"
    "\n"
    "?                              本说明屏幕\n"
    //"m <name1> [name2] [name3]...       Send mail.\n"
    "m <name1> [name2] [name3]...   寄信。\n"
    //"h [# or range (1-4,6 for example)] Show the headers for the specified\n"
    //"                   range of messages, or all messages\n"
    //"                   if no range is specified.\n"
    "h [# or 范围 (比如 1-4,6)]     显示指定的或全部信件的开头。\n"
    //"#                  Read a message.\n"
    "#                              读取信件。\n"
    //"r #                    Reply to message\n"
    "r #                            回复信件。\n"
    //"R #                    Reply to message, all\n"
    //"                   originial recipients receive the mail\n"
    "R #                            回复信件给所有寄信人。\n"
    //"f #                    Forward message\n"
    "f #                            转寄信件。\n"
    //"d # or range               Delete message(s)\n"
    "d # or 范围                    删除信件。\n"
    //"$                  Show the number of messages in your box.\n"
    "$                              显示信件总数。\n"
    //"= [#]                  Set current message if # is provided\n"
    //"                   else shows the current message #\n"
    "= [#]                          显示现在信件的号码。如果有参数 # ，\n"
    "                               则设定读取信件的号码\n"
    //"+                  increment the current message number\n"
    "+                              读取信件的号码加一，并不显示。\n"
    //"                   but do not read.\n"
    //"-                  decrement the current message number\n"
    "-                              读取信件的号码减一，并不显示。\n"
    //"                   but do not read.\n"
    //"n                  read the next message.\n"
    "n                              显示下一封信件。\n"
    ;

    if( wizardp(this_user()) )
    output +=
    //"s [#] <filename>           Save message w/ header intact to file.\n"
    //"w [#] <filename>           Save message but no header to file.\n";
    "s [#] <filename>               将信件头以及信件内容存档。\n"
    "w [#] <filename>               将信件内容存档，不包括信件头。\n";

   output +=
    "\n"
    //"All numbers default to the currently referenced message, which is shown by =\n"
    //"\n"
    //"Groups may also be mailed to, see help for groups on how to set them\n"
    //"up.... you can mail to them by enclosing "
    //"The group in ().  Eg, Mm (admin) rust  will mail all the admins and rust.\n";
    "可以寄信给一组人，比如 m (admin) rust 会寄给所有 admins 和 rust。\n";
    more(output);
}

private void stdmail_cmd_forward(string cmd_args)
{
    mixed   newto;
    int     num;

    if(!cmd_args || (sscanf(cmd_args,"%d %s",num,newto)!=2&&
    (sscanf(cmd_args,"%s",newto)!=1)))
    {
    //write("Usage: f # <name1> [name2] ...\n");
    write("用法：f # <name1> [name2] ...\n");
    return;
    }

    cmd_forward(num, newto);
}

private void stdmail_cmd_save(string cmd_args)
{
    int num;
    string fname;

    if(!cmd_args || (sscanf(cmd_args,"%d %s",num,fname)!=2&&
    sscanf(cmd_args,"%s",fname)!=1))
    {
    //write("Usage: s # <filename>\n");
    write("用法：s # <filename>\n");
    return;
    }

    cmd_read(num, fname, 0);
}

private void stdmail_cmd_write(string cmd_args)
{
    int num;
    string fname;

    if(!cmd_args || (sscanf(cmd_args,"%d %s",num,fname)!=2&&
    sscanf(cmd_args,"%s",fname)!=1))
    {
    //write("Usage: w # <filename>\n");
    write("用法：w # <filename>\n");
    return;
    }

    cmd_read(num, fname, 1);
}

private nomask void mail_prompt(string input)
{
    string cmd_args;

    input = trim_spaces(input);
    if ( sizeof(input) >= 3 && input[1] == ' ' )
    cmd_args = input[2..];

    if(!sizeof(input))
    {
    int idx;
    idx = mailbox_ob->first_unread_message() + 1;
    if( !idx )
    {
        modal_pop();
        destruct( this_object());
        return;
    }
    else
        cmd_read( idx, 0, 0);
    return;
    }

    switch ( input[0] )
    {
    case 'q':
    modal_pop();
    destruct(this_object());
    break;
    case 'h':
    cmd_headers(cmd_args);
    break;
    case 'm':
    cmd_mail(cmd_args);
    break;
    case 'R':
    stdmail_cmd_replyall(cmd_args);
    break;
    case 'r':
    stdmail_cmd_reply(cmd_args);
    break;
    case '?':
    stdmail_cmd_help();
    break;
    case 'd':
    cmd_delete(cmd_args);
    break;
    case 'f':
    stdmail_cmd_forward(cmd_args);
    break;
    case 's':
    stdmail_cmd_save(cmd_args);
    break;
    case '=':
    cmd_setcurrent(cmd_args);
    break;
    case 'w':
    stdmail_cmd_write(cmd_args);
    break;
    case 'n':
    {
        int idx;

        idx = mailbox_ob->first_unread_message() + 1;
        if ( !idx )
        //printf("No more messages.\n");
        printf("没有更多的信件了。\n");
        else
        cmd_read(idx, 0, 0);
        break;
    }
    case '+':
    cmd_setcurrent(mailbox_ob->query_message_index()+2 );
    break;
    case '-':
    cmd_setcurrent(mailbox_ob->query_message_index() );
    break;
    case '$':
    printf(//"You have %d messages.\n",
           "你共有 %d 封信件。\n",
            mailbox_ob->query_message_count());
    break;
    default:
    if ( to_int(input) > 0 )
        cmd_read(to_int(input), 0, 0);
    else
        //write("Type ? for help\n");
        write("用 ? 来显示辅助说明\n");
    break;
    }
}

nomask void begin_mail(string arg)
{
    int idx;

    if ( arg && trim_spaces(arg) != "" )
    {
    cmd_mail(arg);
    return;
    }

    modal_push((: mail_prompt :), (: query_prompt :));
    idx = mailbox_ob->first_unread_message() + 1;
    if (!idx)
    {
    //write( "No Unread Messages.\n" );
        write("没有未读的信件。\n");
        write( "(h for old headers)\n" );
    }
    else
    {
    write("\n--- LimaLib Mailer ---\nCurrent headers:\n");
        cmd_headers( idx + "-" + mailbox_ob->query_message_count());
    }
}
