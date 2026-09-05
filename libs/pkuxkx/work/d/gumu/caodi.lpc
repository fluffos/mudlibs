// Room: /d/gumu/caodi.c 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "草地");
set("outdoors","gumu");
        set("long", @LONG
    这是一终南山山后中的一片草地，地上长着绿油油
的小草，走在上面感到很舒服，草间夹杂着许多野花，不时
散发出阵阵幽香. 

LONG
        );
       set("exits", ([  
  "north" : __DIR__"caodi2",
  "westup" : __DIR__"xiaodao4",
]));
	  set("valid_startroom", 1);
  set("objects", ([
                
CLASS_D("gumu")+"/yangnu" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
}

void init()
{
    object yetu;
    object me=this_player();
    if (me->query_temp("gmnewbiejob/yetu"))
    {
        if (time()-me->query_temp("gmnewbiejob/yetutime")<120)
        {
            if (!me->query_temp("gmnewbiejob/yetuappear")&&random(10)>6)
            {
                yetu=new(__DIR__"npc/yetu");
                yetu->set("owner",me->query("id"));
                yetu->move(this_object());
                me->set_temp("gmnewbiejob/yetuappear",1);
                message_vision("一只$N跳了出来，警惕的看着周围。\n",yetu);
            }
            return;
        }
        else
        {
            tell_object(me,"你出墓很久了，先回去看看小龙女有没有别的什么事吧。\n");
            return;
        }
    }
}