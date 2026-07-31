inherit ROOM;

void create()
{
set("short",HIC "牛郎居"NOR);


        set("long",@LONG
这里是江湖号称午夜牛郎.星空的家,不要在这里
乱转或者乱说话，小心星空PK你。
LONG );
        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang", 
                                     "zhuwu":"/u/zhuwu/workroom",    
                     "cangyue":"/u/cangyue/workroom",   
        "yao":"/u/yao/workroom",   
        "lpc":"/u/zjb/room/xuexi", 
  "daniel":"/u/daniel/workroom",   
                 "dashu":"/d/city/chatroom",              
               "down":"/d/wizard/wizard_room" ]));
  
        set("objects", ([
]));

        set("valid_startroom", 1);
        set("no_suck", "1");
    set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
      call_other("/u/zjb/obj/board", "???");
}

