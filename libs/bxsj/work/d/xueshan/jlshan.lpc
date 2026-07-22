 //      积雷洞入口

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"积雷山"NOR);
        set("long",@LONG 
顺着溪涧走了有两三里路，转过一个溪湾，那溪面竟是越到后面越宽，快
到尽头，忽听涛声聒耳。往前一看，迎面飞起一座山崖，壁立峭拔，其高何止
千寻。半崖凹处，稀稀地挂起百十条细瀑，下面一个方潭，大约数十亩。潭心
有一座小孤峰，高才二十来丈，方圆数亩，上面怪石嗟峨，玲珑剔透。峰腰半
上层，有一个高有丈许的石洞(dong)，洞前还有一根丈许高的平顶石柱。这峰
孤峙水中，四面都是清波索绕，无所攀附，越显得幽奇无比。        
LONG);
        set("exits",([
                "southdown" : __DIR__"tianxi",
 
        ]));
set("outdoors", "雪山");
        setup();
//        replace_program(ROOM);
}
void init()
{
add_action("do_jump", ({"jump","tiao" }));
}
int do_jump(string arg)
{
    object me = this_player();
    if (arg!="dong")
    return notify_fail("你要去哪里？\n");
   if(me->query_skill("force",1)<=200)
   return notify_fail("你刚要举步，忽然觉得心胆俱寒，急忙退了回来。\n");
   if (me->query_skill("dodge",1)<200)
   return notify_fail("你强要向峰间小洞纵去，耐何身法太弱，掉到水里可不是玩的。\n");
   message_vision(HIY"$N 提起一口真气将身形一纵，一式登萍渡水，将身子轻飘飘落在洞口。\n"NOR,me);
   me->move("jldong");
   return 1;
   }     
   		    