// Room: /d/yandang/guanyin1.c

inherit ROOM;

void create()
{
	set("short", "第二层");
	set("long", @LONG
第二层是天王殿,供奉的是'风,调,雨,顺'四大天王.你依次看过来,
只决得正是栩栩如生,据说这四天王又称护法神四大金刚,其正名为持
国天王,增长天王,广目天王,多闻天王.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang1" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin2",
  "down" : __DIR__"guanyin",
]));

	setup();
}
int valid_leave(object me,string dir)
{
  object ob;
 ob=present("hua yan",this_object());
if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
    return notify_fail("华严拦住你:你非我本帮弟兄,我为何让你过去!\n");
       }
return ::valid_leave(me,dir);
}