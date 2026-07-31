// 和平客栈 kuku@sjsh 2003.8.25

inherit FANGZHU_ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short","和平客栈");
  set ("long", @LONG

这家客栈位于荒无人烟的放逐岛上，因为很久没人来，
已经破败不堪了。偶尔有罪大恶极的被朝廷放逐到这
里的钦犯才有可能光顾这间小店。二楼上是雅厅，后
面是客房。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sleep",
  "west" : __DIR__"fangzhudao1",
  "up": __DIR__"yazuo",
]));

  set("objects", ([ /* sizeof() == 2 */
  ]));

   set("no_time",1);
   set("no_fight", 1);
   set("no_magic", 1);

  set("valid_startroom", 1);
  setup();
//  call_other("/obj/board/nancheng_b", "???");
}

void init()
{
        object who = this_player();
    remove_call_out ("checking"); 
    call_out ("checking",2,who); 
}

void checking(object who)
{
        int i,j;
        object ob1,*obs;
        obs = all_inventory (who); 
        i = sizeof(obs); 
        if(who->query("fangzhu")){ 
                for(j=0;j<i;j++){ 
                        ob1 = obs[j]; 
                        message_vision ("$N身上的$n被没收！\n",who,ob1);              
                        if (! interactive(ob1)) 
                                destruct (ob1); 
                        else 
                                ob1->move(environment(who)); 
                }                       
        } 
}
