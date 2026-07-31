// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>

inherit ROOM;
string *make_msg = ({
    HIG "铜锣三响竹篮缓缓升高\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "竹篮不住上升\n\n" NOR,
    HIG "快到顶了!\n\n" NOR,

});
        


void create()
{
	set("short","平地");
	set("long", @LONG
一小块平地,上面放着一个大竹篮,是用来拉人上黑木崖的
显然是上面有滑轮和绞索要上崖只有出示(chushi)腰牌
LONG
	);

	set("exits", ([
                "south" :__DIR__"shanjiao18",
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
         call_out( "sanya", 2, who, 0 );

         return 1;
         }
         write(HIR "你的腰牌上哪儿去了?\n快去补一块!!\n" NOR);
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
        who->move("/d/heimuya/dingfeng1");
          tell_object(who,YEL "黑木崖到了!\n" NOR);
    return;
}
 

