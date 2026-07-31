// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>
inherit ROOM;
string *make_msg = ({
    HIG "铜锣三响竹篮缓缓下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "竹篮不住下降\n\n" NOR,
    HIG "快到底了\n\n" NOR,

});
        


void create()
{
	set("short","平地");
	set("long", @LONG
一小块平地,上面放着滑轮和绞索还有一个大竹篮,是用来下黑木崖的
要下崖只有出示(chushi)腰牌
LONG
	);

	set("exits", ([
                "north" :__DIR__"dingfeng2",
	]));


        set("objects",([
                __DIR__"npc/jiao_zhong" : 4,
        ]));
	
	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_chushi", "chushi");
}

          
int do_chushi()
{
        object who,*inv;
        int i;          
         
         who=this_player();
         inv = all_inventory(who);
         for(i=0; i<sizeof(inv); i++)
         {
         if(strsrch(inv[i]->query("name"),"腰牌")==-1)continue;
         write(HIR "抓紧了别掉下来!!.\n" NOR);
	 who->move(__DIR__"zhulan");
         call_out( "sanya", 3, who, 0 );

         return 1;
         }
         write(HIR "你的腰牌上哪儿去了?\n快去补一块!!\n" NOR);
who->move("/d/heimuya/kezhan");
         return 1;
}

void sanya(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     	
     if( ++stage < sizeof(make_msg) ) {
	 
         call_out( "sanya", 2, who, stage );
         return;
     } else
        who->move("/d/heimuya/shanjiao19");
          tell_object(who,YEL "到底了!\n" NOR);
    return;
}
 

