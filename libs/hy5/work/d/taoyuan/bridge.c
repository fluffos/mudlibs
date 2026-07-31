 inherit __DIR__"no_killing_place";
void create()
{
    
        set("short", "小桥");
    
        set("long", @LONG
汉白玉雕成的小桥通体洁白。水流轻快的从桥下流过，河水清澈见底，站在桥
上你可以清楚地看到鹅卵石铺成的河床，不时游过的鱼儿在鹅卵石上投下了淡淡的
阴影。东岸连绵不断的山峦环绕着一块绿色的盆地，盆地中依山傍河坐落着几个精
致的小宅院，四周花草扶疏。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"riverbank",    
                "east" : __DIR__"riverbanke",
        ]));
    
        set("no_magic", 1);
        set("outdoors","taoyuan");
    set("coor/x",250);
        set("coor/y",-40);
        set("coor/z",0);
    
        setup();
    
        
}   
int valid_leave(object who,string dir)
{
        if(dir=="east"){
                message("vision",who->name() + "往东离去，只听铛的一声，" 
                                + who->name() + "揉着鼻子，一屁股坐在了地上。\n", this_object(), who);
                return notify_fail("铛。。的一声，你撞在一堵无形的墙上，被弹了回来，坐到了地上。\n");
                }
        return ::valid_leave(who, dir);
}
