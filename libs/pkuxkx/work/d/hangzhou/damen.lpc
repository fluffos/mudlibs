// Room: /hangzhou/hhdamen.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
        set("short", "院门");
        set("long", @LONG
    这里是一户庄园，红漆大门，大门两侧贴着对联，门口有两个家丁
警惕的盯着过往的路人。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "south" : __DIR__"hubian",       
]));
     
     set("objects", ([
                __DIR__"npc/jiading" : 2,
        ]));     
   setup();
}

void init()
{
        add_action("do_say", "say");
}

int do_say(string arg)
{

        if( !arg || arg=="" ) return 0;

//        if( arg=="红花老祖本姓朱，为救苍生下凡来" ) 
        if(strsrch(arg, "红花老祖本姓朱") >=0 && strsrch(arg, "为救苍生下凡来") >=0)         
        {
                message("vision","你大声的喊了一句："+arg+"!\n", this_player());
                write("家丁惊讶的叫了一声：居然知道本帮切口，里边请！\n");
                //added by whuan,开了门就不必再开了
                if(!query("open"))
                {
                message("vision", "家丁上前把院门打开。\n", this_player());
                set("exits/enter", __DIR__"xiaoyuan");
                set("open",1); 
                remove_call_out("close");
                call_out("close", 5, this_object());
                }  
                return 1;
        }
        return 0;
}

void close(object room)
{
        message("vision","家丁迅速的把门关上。\n", room);
        room->delete("exits/enter");
        room->delete("open");
}
