//use mysql to interactive with web

mixed handle;

void create()
{
    mixed rows;
    int i;
    string *res;

    handle = db_connect("127.0.0.1","pkuxkx","pkuxkx");
    if(stringp(handle))
    {
        write(handle+"\n");
        return ;
    }
    if(handle < 1)
    {
        write("fail to open db\n");
        return;
    }


    rows=db_exec(handle,"drop table chat");

    if(stringp(rows))
    {
        write(rows+"\n");
    }

    //create the table
    rows=db_exec(handle,"create table chat (id INTEGER PRIMARY KEY AUTO_INCREMENT, channel varchar(16) , userid varchar(32),msg varchar(256),index (channel)) CHARACTER SET gbk");
    if(stringp(rows))
    {
        write(rows+"\n");
        return ;
    }
}


void update_chat_table(string userid,string channel,string message)
{
    mixed rows;
    if(!handle) return;
    rows = db_exec(handle,"insert into chat (userid,channel,msg) values ('"+userid+"','"+channel+"','"+message+"')");
    if(stringp(rows)) write(rows+"\n");
}

void pre_destruct()
{
    //if(intp(handle)) db_close(handle);
}