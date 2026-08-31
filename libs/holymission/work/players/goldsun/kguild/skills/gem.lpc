
/* Guild EMote */

#define GUILD this_player()->query_guild() 

int gem(string arg)
{
    "/sys/chatd"->do_chat(GUILD,"*"+this_player()->query_name()+" "+arg+".\n");
    return 1;
}
