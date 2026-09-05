// Room: xiaodao2.c

inherit ROOM;


void create()
{
	  set("short", "小道");
set("outdoors","gumu");
        set("long", @LONG
    这是一终南山山后中的一条小道，婉婉衍衍，伸向远方。
小道旁有许多灌木丛，夹杂着许多野花，不时散发出阵阵幽香.

LONG
        );

	 set("exits", ([  
  "northdown" : __DIR__"xiaodao3",
	"south" :__DIR__"xiaodao",
 
 
]));
 set("no_clean_up", 0);
         set("objects",([__DIR__"npc/maque":6,]));
	
	setup();
}


void init()
{
	add_action("do_wang", "wang");
}

int do_wang(string arg)
{
        object me;


        me = this_player();
 
	if
( !arg || ( arg != "maque" ) )
{write("你要网什麽？\n",me);return 1;}
        if ( (int)me->query_skill("yunu-xinfa", 1) < 20)
	{write( "你玉女心法等级不够，无法通过天罗地网式来涨轻功。\n",me);
	return 1;}
	
 
if ( (int)me->query_skill("xianyun", 1) < 20)
                       {write( "你用双手网了半天，没网到一只麻雀。\n",me);return 1;}
  
if((int)me->query_skill("xianyun",1)>101){
write("这对你来说太简单了！\n",me);return 1;}

	
 if( (int)me->query("qi") > 30 )
 {
        me->add("qi", -10);
        message_vision("$N的双手天罗地网般地网向麻雀，麻雀扑扑通通地飞，但都没飞出你的手掌所能够的范围。\n",me);

if((int)me->query_skill("xianyun",1)*(int)me->query_skill("xianyun",1)*(int)me->query_skill("xianyun",1)/10 > me->query("combat_exp"))
          {
write( "也许是缺乏实战经验，你用双手网了半天，没网到一只麻雀。\n",me);
return 1;}
if((int)me->query_skill("xianyun",1)>101){
write("这对你来说太简单了！\n",me);return 1;}
 
else
        {
              me->improve_skill("xianyun", 30);
                write("你网了半天，似乎觉的轻功有所提高。\n");

 return 1;
        }
 }
 else
                  {write("你现在过于疲倦，无法专心下来网麻雀。\n",me);return 1;}
         } 






