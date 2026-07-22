inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "龙潭");
        set("long", HIR @LONG   
这里就是龙潭，一只巨龙盘踞在这里，看见有人进来，发出一声
震天巨吼，然后便发起了攻击。听说它守护着精灵王留下来的宝藏。
有空的话，搜索(search)一下或许会有收获。
LONG);
        set("exits", ([ 
//               "south" : "/d/tulong/spirit6", 
           ]));
        set("objects", ([ 
//             "/quest/tulong/npc/dragon" : 1,
          ]));
        set("book_count", 7);
//         set("no_fly",1); 
        setup();
} 

void init()
{
  add_action ("do_search","search"); 
  add_action ("do_quit","train");}

int do_quit(string arg){
        write(this_player()->query("name")+"，龙也是可以驯的么？！\n");
        return 1;
} 
int do_search (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object dragon;

  if (who->query("tulong/dragon")) 
	{
	 message_vision (HIB + "赶紧逃命吧！亲........\n",who,dragon); 
	 return 1;
	}
	
  if (random(10))
  {
    message_vision ("$N四处搜索了一番，什么也没有找到。\n",who);  
  }
  else
  {
    dragon = new ("/quest/tulong/npc/dragon.c");
	dragon->move(environment(this_player()));
    who->set("tulong/dragon",1);	
    message_vision (HIB + "你发觉有些不对劲........\n",who,dragon); 
	message_vision (HIR + "热浪一阵阵袭来..........越来越不对劲了..........\n",who,dragon); 
	message_vision (HIB + "突然黑暗中一条"+HIR"烈火孽龙"HIB+"窜了出来！\n",who,dragon); 
	message_vision (HIR + "烈火孽龙"+HIY"仰天大吼一声，便杀向了发呆的你！\n",who,dragon); 
	dragon->kill_ob(who);
	who->kill_ob(dragon);
  }
  return 1;
}

