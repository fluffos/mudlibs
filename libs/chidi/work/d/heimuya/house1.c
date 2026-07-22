//room: 
inherit ROOM;
void create()
{
  set("short","内室");
  set("long",@LONG
这是一个精雅的小舍,一进门便可闻到一阵浓冽的花香.房中挂着一幅五女向凤图,
图中绘着五个宫装美女,美目盼兮,艳丽脱俗.屋里还有一张茶几,几张椅子,椅子上
铺着绣花锦垫，西面有一扇洞形门通向后厅.
LONG 
     );
  set("exits",([
      "west"      : __DIR__"huoting",
      ]));
  
 set("objects", ([
		__DIR__"npc/xifang" : 1,
           ]));                                                    
        set("no_magic", 1);
 setup();
}
void init ()
{
    if (userp(this_player()))
     this_player()->set("startroom","/d/city/wumiao");
}
