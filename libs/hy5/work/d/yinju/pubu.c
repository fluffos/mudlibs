inherit ROOM;

void create()
{
  set("short","大瀑布");
  set("long",@LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的
瀑布。大瀑布（pubu）一泄千里，震撼人心。
LONG);
  set("outdoors","yinju");
  set("objects", ([
    __DIR__"npc/yuren": 1,
]));
set("item_desc", ([
                "pubu" : "大瀑布里好像有鱼在游动可以去捉（zhuo)。\n",
]));

  set("exits",([
   "eastup"  : __DIR__"tiezhou",
   "westdown"  : __DIR__"doulu",
        ]));

  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="eastup")
    {
       if(objectp(present("diancang yuyin", environment(me))) && 
(me->query_temp("give_wawa")!=1))
            return notify_fail("渔人拦住你说：家师不见外人！\n");
    }   
       return ::valid_leave(me, dir);
}void init()
{
        add_action("do_zhuo","zhuo");
}
int do_zhuo(string arg)
{
       object ob;
        object me = this_player();

	if (arg != "pubu")
		return 0;
if (me->query("dex")>20)
{
	message_vision("$N好容易从瀑布中捉到了一条金娃娃。\n", me);
           ob=new("/d/yinju/npc/obj/wawayu");
           ob->move(me);
           me->add("jing",-30);
}
else 
message_vision("$N好容易看到一条金娃娃,但是由于身手不够敏捷给他跑了。\n", me);
return 1;
}