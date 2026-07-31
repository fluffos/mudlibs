 inherit ROOM;
void create()
{
        set("short", "泥沼边缘"); 
        set("long", @LONG
出了泥沼，是一个群山合抱下的小山坡，四季常春，象是上天特意要在这穷山
恶水中留下一片乐土。在别的地方早已凋零枯萎的草木，在这里却正欣欣向荣，在
别的地方难以久长的奇花异草，在这里却满目皆是。就连那一道自半山流下来的泉
水。都比别的地方分外清冽甜美。远处泉水旁的一片不知名的花树丛中，还有间小
小的木屋，一丛浅紫色的花，从屋顶上长了出来。
LONG);
       set("outdoors", "wolfmount"); 
        set("type","grassland");
        set("exits",([
        "enter":__DIR__"xiaohome",
        ]) );
        set("coor/x",-580);
        set("coor/y",-700);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}      
