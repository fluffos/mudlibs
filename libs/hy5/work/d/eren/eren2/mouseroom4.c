#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "正室");
        set("long", @LONG
石门後竟是一间六角形的石室，再也没有别的门户。嵌在石墙中的十
来盏铜灯燃得通明。石室中央有一口很大的石棺，还有许多石像。这些石
像竟全都雕成移花宫主姊妹和魏无牙的模样，而且都和真人差不多大小，
自成一组，每一个的姿态都不同。每一个石像都雕得活灵活现，纤毫毕露。
使人忍不住想摸上一下以辨真伪。
LONG
        );
        set("exits", ([ 
            "south" : __DIR__"mouseroom3",
                ]));
        set("item_desc", ([
                "石像": "移花宫主姊妹趴在地上，魏无牙就踏着她们的背脊，手还举个杯子在喝酒。\n",
                "statue": "移花宫主姊妹趴在地上，魏无牙就踏着她们的背脊，手还举个杯子在喝酒。\n",
                "shixiang": "移花宫主姊妹趴在地上，魏无牙就踏着她们的背脊，手还举个杯子在喝酒。\n",
        ]) );
        
        set("objects", ([
                __DIR__"npc/wuya" : 1,
                __DIR__"npc/mice5" : 1,
                __DIR__"npc/mice6" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()
{
        add_action("do_touch", "touch"); 
}  
int closepath()
{
        if( !query("exits/up") ) return 1;
        message("vision","洞顶上的小门又无声无息的合上了。\n",this_object());
             delete("exits/up");
        return 1;
}  
int do_touch(string arg)
{
        object guard;
        if(!arg || (arg != "石像" && arg != "statue" && arg!="shixiang")) {
                return 0;
        }
        if (guard=present("wei wuya",this_object()))
        if (guard) {
                message("vision","魏无牙瞪了你一眼。\n",this_object());
                return 1;
                }
        if (this_player()->is_busy())
               {
                tell_object(this_player(),"你现在正忙。\n");
                return 1;
                }       
        add("num",1);
        this_player()->start_busy(1);
        switch (query("num"))   {
                case 1: message_vision(CYN"移花宫主的石像晃了晃，似乎在哀哀地哭泣。\n"NOR,this_player());
                        break;
                case 2: message_vision(CYN"移花宫主石像的头碰碰地在地上磕了几下。\n"NOR,this_player());
                        break;
                case 3: message_vision(CYN"移花宫主石像的头咯咯吱吱地抬起来，飞了几个吻。\n"NOR,this_player());
                        break;
                case 4: message_vision(CYN"移花宫主石像的手往上一指，＂嗑碴＂一声，洞顶上裂出了一个暗门。\n"NOR,this_player());
                        if (!query("exits/up")) {
                                set("exits/up",__DIR__"tunnel1");
                                call_out("closepath",10);
                                }
                        set("num",0);
                        break;
                default: break;
        }               
        return 1;
} 
void reset()
{
::reset();
delete("num");
}  
