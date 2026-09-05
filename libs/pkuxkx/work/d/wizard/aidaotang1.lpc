// Room: /u/haiv/aidaotang.c
// hubo 2008/5/20


inherit ROOM;
#include <ansi.h>
int block_cmd();

void create()
{
        set("short", HIW"哀悼堂"NOR);
        set("long", HIW@LONG
这里是为了纪念四川汶川大地震遇难同胞而设立的北侠哀悼堂，
从北国林海到南疆渔村，从天山牧场到江南水乡，辽阔的中华大地，
都沉浸在无比悲痛之中。请各位来宾脱帽，行礼，默哀（moai）三
分钟。

    这是一个充满爱的民族 

　　我们拥有着同一个世界 

　　拥有着最朴实、最善良的人民 

　　拥有的一切都足以让我们有信心相信未来会更美好！ 

　　我们会让爱传递在我们的身边、我们的周围


LONG
NOR);
        set("exits", ([
                "east" : "/d/city/wumiao",
       
]));
        
        set("max_user",3);
          
   setup();
}
void init()
{
        add_action("do_moai", "moai");
       if (!wizardp(this_player()))
          add_action("block_cmd","",1);  
}
int do_moai(string arg)
{
        object me;
        me = this_player();
        
        if (me->is_busy())
                      return notify_fail("你正在默哀中。\n");
        
        me->start_busy(180);
        call_out("end_moai", 180, me);
        write(HIW"你默默悼念，在四川汶川大地震遇难同胞们，安息吧！\n"NOR);
        shout(HIW + me->query("name") + "在哀悼堂向四川汶川大地震遇难同胞默哀！！！\n"NOR);
          
   return 1;
}

void end_moai(object me)
{
    if (!me) return;
    me->start_busy(1);
    write(HIW"默哀结束，有您的支持，我们一定会战胜任何困难。\n"NOR); 
}


int block_cmd()
{        
       string verb = query_verb();  
       if (verb=="say") return 0; //allow say     
       if (verb=="quit") return 0;                                                         
       if (verb=="moai") return 0;                                                         
       if (verb=="look") return 0;                
       if (verb=="go") return 0;                
       if (verb=="east") return 0; 
       if (verb=="e") return 0; 
       return 1;                                  
}                                                 

