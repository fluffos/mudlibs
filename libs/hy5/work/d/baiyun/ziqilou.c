 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "紫气东来楼");
        set("long", @LONG 
此间是白云城招待贵宾的楼宇，一栋红木雕刻的花轩，朱栏回廊，建筑得极华美
精致。楼内雕梁画栋，金壁辉煌，但凡贵宾至此，无不心醉其间，远在千里外的紫禁
城大概也不过如此。而楼内摆设的奇珍异宝，海外诸国的古玩佳肴更是琳琅满目。
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"skystreet",
       "up" : __DIR__"ziqilou2",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/yexingshi" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",5); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
//        replace_program(ROOM); 
}  
int valid_leave(object me,string dir) { 
        object ye;
        ye=present("ye xingshi",this_object());
        if (dir=="up" && ye)
        if (!userp(ye)) {
                message_vision(ye->name()+"拱了拱手，皮笑肉不笑地挡在$N身前的楼梯口。\n",me);
                return notify_fail("");
        }
        return 1;
        
}
