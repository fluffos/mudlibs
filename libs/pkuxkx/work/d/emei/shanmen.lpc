// Room: /u/cuer/emei/shanmen.c
//cuer

inherit ROOM;

void create()
{
	set("short", "山门");
set("outdoors","emei");
	set("long", @LONG
这里是峨嵋山的山门，迎面一座高大的汉白玉山门。
石阶从山门下穿过，山门的后面是一座雄伟的大殿，那
就是峨嵋的山门殿。山门旁有一群峨嵋派的守山弟子在
检查过往行人，不是峨嵋派的不让上山。还有一个慈祥
的中年尼姑在接待想加入峨嵋派的朋友。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shmdian",
  "westdown" : __DIR__"yunvchi",
]));
	set("no_clean_up", 0);
        set("objects",([
               __DIR__"npc/wenxu" : 1, 
               __DIR__"npc/shoushan" : 4,  
            "/clone/npc/camel1": 0,
            ]));         
	setup();
}


int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability"))
        return ::valid_leave(me, dir);  
    if( dir != "north" || (string)me->query("family/family_name") == "峨嵋派" )
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shoushan dizi")
            return notify_fail("守山弟子说: 非我派弟子不许上峨嵋山。\n");
    }
    return ::valid_leave(me, dir);
}
