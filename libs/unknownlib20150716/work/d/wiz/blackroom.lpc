inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short", "黑屋");
  set ("long", @LONG

黑漆漆的一间小屋，好象没有出口的样子，不过你好象感觉这个屋子里还另外
有人！
LONG);

  set("exits", ([ /* sizeof() == 2 */
]));
  setup();
}

void init()
{   
        if(!wizardp(this_player()))
        {
		add_action("block_cmd","",1);   
		CHANNEL_D->do_channel(this_object(),"rumor","听说"HIW+this_player()->name(1)+HIM"被关进了"HIR"小黑屋"HIM"！"NOR);
	}	
}

int block_cmd()
{
       string verb = query_verb();
       if (verb=="say") return 0; //allow say
       if (verb=="look") return 0;
       write("安心思过，争取早日释放！\n");
       return 1;
}

