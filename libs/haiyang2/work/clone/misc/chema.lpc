// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
          add_action ("do_fly","chema");
}

void create()
{
	set_name(YEL"武林车马票"NOR, ({"chema piao", "piao"}));
        set("unit", "张");
set("long", YEL"为了方便大家。开通车马(chema)服务！\n
 目前你可以去的地方有如下:
北京(tam)   大理(dl)   泉州(qz) 扬州(gc)  塘沽(tg)   归云庄(gyz)
襄阳(xy)    武功镇(wg) 长安(ca) 兰州(laz)  关外(gw)   景德镇(jdz)
永登城(yd)  伊犁镇(yl) 佛山(fs) 扬州(yz)  延平(yp)   江陵(jl)
成都城(cd)  无锡城(wx) 灵州(lz) 金陵(jinl)苏州城(sz) 杭州城(hz)
福州城(fz)  沧州(cz)   盛京(yj) 昆明(km)  荆州(jz)   洛阳(ly)
岳阳(yy)    宜兴(yx)   
\n"NOR      
);

             set("value", 800);
             set("material", "steel");
        setup();
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("你精神不够旺盛，没力气做车马！\n");
if( me->query_temp("pending/team"))
               return notify_fail("你正和别人组队呢！\n");				

if( !environment(me)->query("no_fight") && me->query("combat_exp") > 800000)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("只有在安全区域才能找到马车!!!\n"
                 ,me);
      	return 1;
}


    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

          if (!arg)
              return notify_fail("你想去哪里？\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("这么危险，那还有时间去坐马车?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("先离开拱猪桌才能行动。\n");
          if( environment(me)->query("light_up"))
               return notify_fail("赌场里不能坐马车!!\n");


          else {
          message_vision(HIY
"$N叫了个马夫，并把手中的武林车马票交给马夫，马夫牵来了马车。\n"+
"$N坐上马车，大喝一声“走喽”，只见马夫飞奔而去。。。\n\n"NOR, me);
}
           if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
else if(arg=="yd") pla = "/d/huanghe/yongdeng";
	else if(arg=="yl") pla = "/d/xingxiu/majiu";
else if(arg=="fs") pla = "/d/foshan/northgate";		
else if(arg=="yz") pla = "/d/city/guangchang";			
else if(arg=="yp") pla = "/d/yanping/majiu";			
else if(arg=="jl") pla = "/d/jiangling/beimen";				
else if(arg=="cd") pla = "/d/chengdu/majiu";					
else if(arg=="wx") pla = "/d/wuxi/majiu";						
else if(arg=="lz") pla = "/d/lingzhou/majiu";						
else if(arg=="jinl") pla = "/d/jinling/nanmen";						
else if(arg=="sz") pla = "/d/suzhou/majiu";						
else if(arg=="hz") pla = "/d/hangzhou/majiu";							
else if(arg=="fz") pla = "/d/fuzhou/majiu";							
else if(arg=="dl") pla = "/d/dali/majiu";								
else if(arg=="yj") pla = "/d/yanjing/street4";								
else if(arg=="km") pla = "/d/kunming/dongmen";								
else if(arg=="jz") pla = "/d/jingzhou/majiu";								
else if(arg=="ly") pla = "/d/luoyang/center";									
else if(arg=="yy") pla = "/d/yueyang/guangchang";									
else if(arg=="yx") pla = "/d/yixing/yixing";									
else if(arg=="cz") pla = "/d/cangzhou/beimen";									
else if(arg=="tg") pla = "/d/tanggu/beimen";									
else if(arg=="wg") pla = "/d/quanzhen/guchang";									
else if(arg=="ca") pla = "/d/city4/eastgate";									
else if(arg=="laz") pla = "/d/lanzhou/ximen";									
else if(arg=="gw") pla = "/d/guanwai/nancheng";									
else if(arg=="jdz") pla = "/d/jindezheng/center";		
               else {
               message_vision(HIR
"马车跑了半天，才发觉$N要去的地方根本没那个站。\n结果$N被马夫扔了下来，摔得鼻青脸肿！\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(YEL"\n到了！马车稳稳地停到地下，$N跳下了马车。对车夫挥了挥手。\n"NOR,me);
   me->add("jing",-30);
}
	destruct(this_object());
     return 1;
}