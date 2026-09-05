// cunkou.c 村口
// seagate@pkuxkx 2010/10/30

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
沿着一条长满杂草的小路，两边一片荒凉的景象，前面就是
双井子，以前这里是大家上武当山的必经之路，曾经繁荣了好一
阵子，自从附近来了一股无恶不作的匪徒，慢慢的来往客商也就
不走这条道了。
LONG
	);
  set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"wdroad8",
		"southeast" : __DIR__"xiaolu"
	]));
	setup();
}

void init()
{
  object me,ob;
  me=this_player();
  if(userp(me)&&
  	 me->query("combat_exp")<=100000&&random(100)<10) {
  	me->start_busy(1);
  	ob=new(__DIR__"npc/tufei1");
  	ob->move(this_object());
  	ob->kill_ob(me);
  	me->kill_ob(ob);
  	tell_room(this_object(),"土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n");
  }
}

int valid_leave(object me, string dir)
{
  if(me->is_fighting()&&
  	 objectp(present("tufei", environment(me))))
  	return notify_fail("土匪拦住你：留下携带的财务再走不迟！\n");
  else
  	return ::valid_leave(me, dir);
}
