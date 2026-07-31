// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
        set("short", "渡船");
        set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公
手持长竹篙，正在船尾吃力地撑着船。
LONG
        );
      set("outdoors","nanyang");
        setup();
}
int do_check()
{
    object *obj;
    int i;
    obj=all_inventory(this_object());
    if (!sizeof(obj))   return 1;
    for (i=0;i<sizeof(obj);i++)
        if (userp(obj[i]))  return 0;
    return 1;
}
