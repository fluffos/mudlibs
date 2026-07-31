// Room: /d/sandboy/cook 
inherit ROOM; 
 
void create ()
{
  set ("short", "厨房");
  set ("long", @LONG
茅屋北面的一口大灶上煮着什么东西,热气腾腾的,散发出一股香味,旁边
的桌子上摆着些碗勺,一只小饭桶就摆在桌子旁边.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sansao.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuanzi",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob,npc;
  ob=present("mantou",me);
  npc=present("sansao",this_object());
 if (npc&&dir=="west"&&ob)    {
   return notify_fail("张三嫂对"+me->query("name")+"道:这馒头你还是吃完再出去,让人看到了不好.\n");
       }
else return ::valid_leave(me,dir);
}
 
         
           