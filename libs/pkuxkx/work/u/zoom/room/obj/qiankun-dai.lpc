// 乾坤袋 by freecv @ 2004.4.13

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
int checkzoom();
int do_esc();
int do_ji();
int do_show();

void init()
{
    object me = find_player("zoom");
    add_action("do_esc","esc");
    add_action("do_ji","ji");
    add_action("do_show","show");
//    call_out(checkzoom(),1,me);
}


void create()
{
    set_name(HIY+"乾坤袋"+NOR,({"qiankun dai","dai"}));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit","件");
        set("long",HIB+"这是一件zoom专用宝物:"+HIY+" 乾坤袋"+NOR+"\n");
        set("material","gold");
        set("armor_prop/armor",8888);
        set("value",1);
        set("no_drop","宝贝你也想扔，白痴啊!\n");
        set("no_steal",1);
        set("no_get",1);
    }

    setup();
}


int do_ji()
{
    object *ob;
    object obj;  //ob == player , obj == place
    int i;
    object me = find_player("zoom");


    ob = all_inventory(environment(me));
    if (sizeof(ob)<1)
        return 1;
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]==me)
            continue;
    tell_object(ob[i],"你觉得两眼一黑，似乎来到了另一个世界~\n");
    ob[i]->set_temp("qiankundai",environment(ob[i]));
    ob[i]->move("/u/zoom/room/newworld");
    }
    message_vision(HIR"只见$N念念有词，手中飞出一个越来越大金光闪闪的乾坤袋。\n"NOR,me);
    me->set_temp("qiakunplace",environment(ob[1]));
    return 1;
}


int do_show()
{
    int i;
    object *ob;
    object obj;
    object me = find_player("zoom");

    ob = all_inventory(me->query_temp("qiakunplace"));
    
    for (i=0;i<sizeof(ob);i++)
    {
    tell_object(ob[i],HIR"只见zoom念念有词，你眼前顿时金光缭绕. \n"NOR);
    ob[i]->move(ob[i]->query_temp("qiankundai"));
    ob[i]->delete_temp("qiankundai");
    }

//    message_vision(HIY"只听得$N纵声长啸，眼前顿时一片飞沙走石.\n"NOR,me);$$
    me->delete_temp("qiakunplace");
    return 1;
}
int move(object ob)
{
    object me = find_player("zoom");
    object amror = me->query_temp("armor/cloth");
    if (!me)
        return 1;
    ob = me;
    ::move(ob);
    if (amror)
        amror->unequip();
    ::wear(); 
    return 1;
} 
int do_esc()
{
    object me = this_player();
    me->move("/u/zoom/wizard_room_zoom2");
    return 1;
}
int checkzoom()
{
    object me = find_player("zoom");
    object ob;
    int i;
    int count = 0;
    object *item;

    item = all_inventory(me);
    for (i=0;i<sizeof(ob);i++)
    {
        if (item[i]->query("id")=="qiankun dai")
            count++;
    }

    if (count==0)
    {
        ob = new("/u/freecv/entertain/npc/obj/qiankun-dai");
        ob->move(me);
        message_vision(HIY"忽然半空中一片祥云缭绕，只见一片金光围绕在$N身上。\n"NOR,me);
    }

    call_out(checkzoom(),1,me);
    return 1;
}
