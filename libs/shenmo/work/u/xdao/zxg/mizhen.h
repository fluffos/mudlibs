inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "混沌中");
         set ("long", @LONG
此处上不着天、下不着地，乃盘古未开混沌所在，远处太古神雷轰轰作响。
不时灵光一闪便是一大片虚空塌陷，实在是穷凶极恶之绝境。
LONG);
if(random(3)==1) set("exits/north", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/east", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/west", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/south", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/up", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/down", __DIR__"z"+sprintf("%d", random(48)));
if(!query("exits")) set("exits/out", __DIR__"z0");      
  set("xukong",1);
if(random(4)==1) set("xianjin",1);
 setup();
}

int reset()
{
::reset();
if(random(3)==1) set("exits/north", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/east", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/west", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/south", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/up", __DIR__"z"+sprintf("%d", random(48)));
if(random(3)==1) set("exits/down", __DIR__"z"+sprintf("%d", random(48)));
if(!query("exits")) set("exits/out", __DIR__"z0");
if(query("xianjin")) delete("xianjin");
if(random(4)==1) set("xianjin",1);
}

void init()
{
object me = this_player();
object ob = this_object();
object yao;
int i, j;
if(!userp(me)) return 0;

if(ob->query("xianjin")) {
        message_vision(HIR"混沌中一道太古神雷劈向$N，$N躲闪不及顿时被炸的神魂震荡，体魄不全。\n"NOR, me);
        me->add("kee",-(int)me->query("max_kee")/4);
        me->add("eff_kee",-(int)me->query("max_kee")/4);
         }
 if (me && interactive(me)) 
   {
	if( ! present ("tian mo 5",ob ) )
	{
          for(i=0;i<1+random(2);i++)
          {
             yao = new("/u/xdao/zxg/npc/tianmo"); 
                  if(yao->move(ob))
                         {
    message_vision (HIM"无数的混沌之气聚成一尊$N"+HIM+"浮现在虚空之中。\n",yao);
		yao->releave(); 
                         } 
                    else {destruct (yao);}
            }
           
      }  
   }     
}
