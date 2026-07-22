inherit ROOM;

void create()
{
        set("short", "演武堂");
        set("long", @LONG
这是一间偏殿，地上零乱摆着一些，石锁，木桩等练功工具。几位僧侣正在
扎马练功，地上凹凸不平，似是大力僧侣踏出的痕迹，里面就是少林名震当世的
武僧练功的所在。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"luohan5",
            "west" : __DIR__"wstang1",
]));
        set("objects", ([
                CLASS_D("shaolin") + "/xuan-can":1 ]) );
        set("valid_startroom", 1);
        set("coor/x",-20);
  set("coor/y",280);
   set("coor/z",120);
   setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
	object *obj;

	if (me->query("family/family_name") != "少林派" &&dir=="west"){
         if (present("xuancan dashi", environment(me)))
             return notify_fail("玄惭大师拦住你说到，武僧堂是少林重地，外派弟子不可擅入。\n");
         else
             return notify_fail("一位武僧忽然从边上钻了出来，拦住了你说道：武僧堂是少林重地，外派弟子不可擅入。\n看你停步不动了，那位武僧一拱手，又退回了隐身处。\n");
}
 obj = filter_array(deep_inventory(me),(:get_object:));
      if( sizeof(obj) && dir=="west" ) {
        tell_object(me,"你一不小心，被门槛绊倒了。\n");
        obj[0]->move(environment(me));
        me->unconcious();
return 0;
    }
if(me->query("family/family_name")=="少林派"&&me->query("family/generation")>37&&dir=="west"&&!wizardp(me))
return notify_fail("一位武僧忽然从边上钻了出来，拦住了你说道：武僧堂是少林重地，低代弟子不可擅入。\n");
return ::valid_leave(me, dir);
}
