inherit ROOM;

void create()
{
set ("short", "冶炼室");
set ("long", @LONG

这里是铁匠铺的冶炼室，屋子的正中摆放着一个巨大的冶炼炉，
里面热气腾腾，炙人颜面。
LONG);
set("exits", ([ 
        "out" : "/d/gao/tiepu",
]));
setup();
}
/*
void dest_me()
{
remove_call_out("dest_me");
if ( query("owner") && present(query("owner"),this_object()) )
         return;
destruct(this_object());
}
        
void init()
{
if ( !query("owner") )
        set("owner",this_player());
}

void reset()
{
if ( clonep(this_object()) )
        {       
        if ( !query("owner") )
                {
                remove_call_out("dest_me");
                call_out("dest_me",3);
                }
        else if ( !present(query("owner"),this_object()) )
                {
                remove_call_out("dest_me");
                call_out("dest_me",3);
                }
        else ::reset();         
        }
else    ::reset();
return;
}       

*/