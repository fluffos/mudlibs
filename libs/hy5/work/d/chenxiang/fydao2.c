 inherit ROOM;
void create()
{
        set("short", "风云道"); 
        set("long", @LONG
“一入风云岁月催”，这便是江湖中有名的风云道，暗褐色的道路，从这里开始
婉蜒伸展，穿过翠绿的树林，沿着湛蓝的湖水，伸展向闹市。远山在阴瞑的天色中
看来，仿佛在雾中，更加美丽神秘。这里距离市镇并不远，但这一泓湖水，一带绿
林。却似已将红尘隔绝在山外。                                  
LONG); 
        set("type","road");
        set("exits",([
        "northwest":__DIR__"fydao1",
        "southeast":__DIR__"fydao3",
                ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-470);
        set("coor/y",-550);
        set("coor/z",0);
        setup();
}
int valid_leave(object who,string dir)
{
        if(userp(who) && random(5))
          {
           who->move(this_object());
           return notify_fail("");
         }
        return 1;
}  
