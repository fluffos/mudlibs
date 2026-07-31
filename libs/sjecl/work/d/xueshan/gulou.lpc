 // gulou.c 鼓楼
// by dubei
 

inherit ROOM;
string gu(object);
string chui(object);
void create()
{
        set("short","鼓楼");
        set("long",@LONG
这里是大轮寺鼓楼，每逢早、中、晚，或者要召集众喇嘛的时候，都要和
钟楼同时敲响。鼓楼内架着一面大鼓(gu)，用厚厚的牦牛皮包裹着侧面用几百
枚金钉钉牢。旁边悬挂一个鼓槌(chui)。
LONG);
        set("exits",([
                "west": __DIR__"huilang2"
        ]));

        setup();
}
string gu(object me)
{
     return "这是一面大鼓，用厚厚的牦牛皮包裹着，侧面用几百枚金钉钉牢。\n";
 }
string chui(object me)
{
     return "这是一个甚是巨大的木槌，长约两尺，碗口粗细。\n";
 }
void init()
{
     add_action("do_strike", "qiao"); 
}
int do_strike(string arg)
{
            object me = this_player();

                if (!living(me)) return 0;
                if (arg != "dagu" && arg != "gu")
           return notify_fail("你要敲击什麽？\n");

                if ( (int)me->query_str() < 20 )
	  return notify_fail("你试着想举起鼓槌，太沉了，还是放弃吧。\n");

	  if ( (int)me->query_skill("longxiang-boruo", 1) < 41 )
	  return notify_fail("大鼓发出咚的一声巨响，震得你头晕耳鸣，你内功修为尚浅，还是快走吧。\n");
                
                if ( (int)me->query_skill("hammer", 1) > 61 )
	  return notify_fail("你轻轻挥动鼓槌敲击大鼓，但觉轻松自如，鼓声响彻四周。\n");

                if ( ((int)me->query("jingli") < 40 ) ||  ((int)me->query("qi") < 40 ) )
	  return notify_fail("你感觉已经无力再去敲鼓了。\n");

	        me->add("qi", -20);
               me->add("jingli", -20);
              message_vision("$N挥动鼓槌，向大鼓打去，顿时鼓声咚咚传向四周。\n", me);
              me->improve_skill("hammer",me->query_int());
	  return 1;
}