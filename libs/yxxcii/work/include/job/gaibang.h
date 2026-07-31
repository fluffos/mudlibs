#include <ansi.h>

void init()
{
        add_action("do_ba", "ba");
}

int do_ba(string arg)
{
        object ob, me;
        int i, kar, cps, str, dex;
        me = this_player();

        if( (!arg) || !((arg == "草") ))
                return notify_fail("你要做什么？\n");

        if(me->is_busy())
                return notify_fail("你不累吗？休息一下再找吧！\n");
	if(me->query_temp("unconcious"))
		return notify_fail("什么？\n");

        if((me->query("qi")<10) || (me->query("jing")<10))
                 return notify_fail("你想不要命啦？还不去休息一下。\n");
        if(me->is_fighting())
        	return notify_fail("一心不能二用！\n");
        
        me->start_busy(3);
        message_vision("$N轻手轻脚地扒开旁边的一堆乱草一看.....\n", me);

        kar = me->query("kar");
        cps = me->query("cps");
        str = me->query("str");
        dex = me->query("dex");
        if ((random(kar+cps)>((kar+cps)/5)*5) && (me->query("combat_exp") >= 500000 )){
                switch (random(3)){   
                case 0:
                message_vision("原来草丛中藏着一条"HIW"千年冰蚕"NOR"。\n", me);
                ob=new("/d/npc/bingcan.lpc");
                ob->move(environment(me));
                break;
                case 1:
                message_vision("从草丛中跳出来一只"HIR"莽牯朱蛤"NOR"。\n",me);
                ob=new("/d/npc/zhuha.lpc");
                ob->move(environment(me));   
                break;
                case 2:
                message_vision("原来里面躲着一条"HIY"巨蟒"NOR"。\n",me);
                ob=new("/d/npc/jumang.lpc");
                ob->move(environment(me));
                break;            
                }
           }
 else {
        if ((random(str+dex)>((str+dex)/20)*9) && (me->query("combat_exp") >= 10000 )) {
                switch (random(8)){  
                case 0:
                message_vision("原来草丛中藏着几条"HIW+BLK"毒蛇。\n"NOR, me);
                ob=new("/d/npc/dushe.lpc");
                ob->move(environment(me));
                break;
                case 1:
                message_vision("原来草丛中藏着一窝"HIY"五步蛇"NOR"。\n",me);
                ob=new("/d/npc/wubu.lpc");
                ob->move(environment(me));
                break;
                case 2:
                message_vision("原来这里是个"HIR"毒蝎"NOR"窝。\n",me);
                ob=new("/d/npc/xie.lpc");
                ob->move(environment(me));
                break;
                case 3:
                message_vision("原来有几条"HIR"蜈蚣"NOR"在吃一只死山鸡。\n",me);
                ob=new("/d/npc/wugong.lpc");
                ob->move(environment(me));
                break;   
                case 4:
                message_vision("原来有几条"HIW"银环蛇"NOR"在打斗。\n",me);
                ob=new("/d/npc/yinshe.lpc");
                ob->move(environment(me));
                break;  
                case 5:
                message_vision("原来有几条"CYN"大蟒蛇"NOR"在打斗。\n",me);
                ob=new("/d/npc/mang.lpc");
                ob->move(environment(me));
                break;                             
                case 6:
                message_vision("原来有几条腹蛇在打斗。\n",me);
                ob=new("/d/shenlong/npc/fushe.lpc");
                ob->move(environment(me));
                break;                             
                case 7:
                message_vision("原来有几条金环蛇在打斗。\n",me);
                ob=new("/d/shenlong/npc/jinshe.lpc");
                ob->move(environment(me));
                break;                                                        
                }
          }
          else {
                message_vision("原来里面什么都没有，看来$N是虚惊一场了。\n",me);
                return 1;
                }
          }
          me->receive_damage("qi", 10); 
          return 1;
}