// sanpo1.c
// 山坡1
inherit ROOM;

int do_hit(string arg);

void create()
{
	set("short","山坡");
	set("long",@long
这里是一块不小的平坡，山路到了这里转了个方向继续往上延伸。在
山坡的中央有一个石桌，桌旁是四只石凳，做工都很是粗糙，只不过将就
地可以用而已。
long);
	set("exits",([
	    "eastup" : __DIR__"sanroad5",
          "down" : __DIR__"sanroad2",
          "north" : __DIR__"sanroad6",
]));
	set("item_desc",([
        "石桌" : "桌面上有许多被击打(hit)出来的印迹。\n",
]));
	set("outdoors", "神龙岛");
        set("coor/x",490);
  set("coor/y",420);
   set("coor/z",30);
   setup();
}

void init()
{
	add_action("do_hit","hit");
}	    	

int do_hit(string arg)
{
	object weapon;
	object me=this_player();
        int lev;

	if(!arg || arg=="" || arg==" " || arg!="石桌")
		return 0;
	if(me->query("jingli")<50)
	{
		tell_object(me,"你现在太疲倦了，先休息一下吧。\n");
		return 1;
	}
	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "whip")
	{
		tell_object(me,"你狠狠地拍击了一下石桌，扬起满天灰尘。\n");
                me->add("jingli",-50);
		return 1;
	}
	lev=me->query_skill("whip", 1);
	if(lev<50 || lev>=100)
	{
		tell_object(me,"你狠狠地拍击了一下石桌，扬起满天灰尘。\n");
                me->add("jingli",-50);
		return 1;
	}
	if( (string)SKILL_D("whip")->type()=="martial" &&
          lev * lev * lev / 10 > (int)me->query("combat_exp") ) 
        {
		tell_object(me,"你狠狠地拍击了一下石桌，扬起满天灰尘。\n");
                me->add("jingli",-50);
		return 1;           
        } 
	if( !SKILL_D("whip")->valid_learn(me) )
	{
		tell_object(me,"你狠狠地拍击了一下石桌，扬起满天灰尘。\n");
                me->add("jingli",-50);
		return 1;           
        } 
	tell_object(me,"你狠狠地拍击了一下石桌，扬起满天灰尘。\n");
        me->add("jingli",-50);
	me->improve_skill("whip",lev/5+1,0);
	return 1;
}