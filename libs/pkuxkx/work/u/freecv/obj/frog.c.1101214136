//专用青蛙皮
#include <combat.h>
#include <weapon.h>
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

int do_tou(string arg);
int do_show(string arg);
int do_joke(string arg);
int move(object ob);
int do_flee();
int do_jie(string arg);
int do_ding(string arg);

void create()
{
set_name(HIY"青蛙皮"NOR,({"qingwa pi","frog"}));
if(clonep())
set_default_object(__FILE__);
else
{
set("long",HIC"听说自从freecv被逼成僧后为了躲避众mm的仰慕，特地修炼了这件青蛙皮\n"NOR);
set("material","cloth");
set("unit","件");
set("value",9999999);
set("wear_msg",HIG"$N一见众mm奔来，慌忙之间匆匆套上青蛙皮，开始扮青蛙\n"NOR);
set("remove_msg",HIC"$N见mm们走了，忙将$n脱了下来，长出一口气，抖了抖身上的灰尘.\n"NOR);
set("armor_prop/armor",6666);
}
setup();
}

int move(object ob)
{
object me = find_player("freecv");
object amr = me->query_temp("armor/cloth");
if (!me) return 1;
ob = me;
::move(ob);
if ( amr ) amr->unequip();
::wear();
return 1;
}

void init()
{
add_action("do_tou","tou");
add_action("do_show","show");
add_action("do_joke","joke");
add_action("do_flee","flee");
add_action("do_jie","jie");
add_action("do_ding","ding");
}


int do_flee()
{
object me = this_player();
message_vision(HIG"只见$N突然越来越小，仿佛真正的frog一样轻轻一跳消失在空气中\n"NOR,me);
me->move("/u/freecv/wizard_room_freecv");
me->start_busy(0);
return 1;
}



int do_ding(string arg)
{
    object* ob;
    object me = this_player();
    object room = environment(me);
    int i;
    int flag = 4;

    if (!arg) flag = 1;
    if (arg=="wu pin") flag = 2;
    if (arg == "huo ren") flag = 3;

    ob = all_inventory(room);
    for (i=0;i<sizeof(ob);i++)
    {
        if (flag == 4 && ob[i]->query("id")==arg)
        {
            ob[i]->start_busy(6666);
        tell_object(ob[i],HIY"只见freecv青蛙眼一张，作势要向你扑来，你心中一慌，脚竟然就这样软了\n"NOR);
        }
        if (flag == 3 && userp(ob[i]) && ob[i]->query("id")!="freecv")
        {
            ob[i]->start_busy(6666);
        tell_object(ob[i],HIY"只见freecv青蛙眼一张，作势要向你扑来，你心中一慌，脚竟然就这样软了\n"NOR);
        }
        if (flag == 2 && objectp(ob[i]) && !userp(ob[i]))
        {
            ob[i]->start_busy(6666);
        tell_object(ob[i],HIY"只见freecv青蛙眼一张，作势要向你扑来，你心中一慌，脚竟然就这样软了\n"NOR);
        }
        if (flag == 1 && objectp(ob[i]) && ob[i]->query("id")!="freecv")
        {
            ob[i]->start_busy(6666);
        tell_object(ob[i],HIY"只见freecv青蛙眼一张，作势要向你扑来，你心中一慌，脚竟然就这样软了\n"NOR);
        }
    }
    return 1;
}

int do_jie(string arg)
{
    object* ob;
    object me = this_player();
    object room = environment(me);
    int i;
    int flag = 5;
    if (!arg) flag = 1;
    if (arg=="wu pin") flag = 2;
    if (arg == "huo ren") flag = 3;
    if (arg == "all") flag = 4;

    ob = all_inventory(room);
    for (i=0;i<sizeof(ob);i++)
    {
        if (flag == 5 && ob[i]->query("id")==arg)
        {
            ob[i]->start_busy(0);
        tell_object(ob[i],HIC"freecv见你瑟瑟发抖的样子于心不忍眼一闭，收起周围的威势，你感觉似乎身体又能动了\n"NOR);
        }
        if (flag == 3 && userp(ob[i]))
        {
            ob[i]->start_busy(0);
        tell_object(ob[i],HIY"只见freecv青蛙眼一张，作势要向你扑来，你心中一慌，脚竟然就这样软了\n"NOR);
        }
        if (flag == 2 && objectp(ob[i]) && !userp(ob[i]))
        {
            ob[i]->start_busy(0);
        tell_object(ob[i],HIC"freecv见你瑟瑟发抖的样子于心不忍眼一闭，收起周围的威势，你感觉似乎身体又能动了\n"NOR);
        }
        if (flag == 4 && objectp(ob[i]))
        {
            ob[i]->start_busy(0);
        tell_object(ob[i],HIC"freecv见你瑟瑟发抖的样子于心不忍眼一闭，收起周围的威势，你感觉似乎身体又能动了\n"NOR);
        }
    }
        if (flag ==1){
        me->clear_condition();     
        me->start_busy(0);     
        tell_object(me,HIB"呵呵，你又能动了\n"NOR);  
        }
        return 1;
}

int do_tou(string arg)
{
    string err;
    object ob;
    object me = this_player();

    err = catch(ob=new(arg));
    if (err)
        return notify_fail("只见freecv蹑手蹑脚走进一个人，忽然那人一转身，freecv掉头就跑.\n");
    ob->move(me);
    message_vision(HIG"只见$N偷偷摸摸走家窜户，呼的撒丫子就跑，怀里鼓鼓的不知揣了什么\n"NOR,me);
    return 1;
}


int do_joke(string arg)
{
    string flag;
    string content;
    
    if (!arg||sscanf(arg,"%s %s",flag,content)!=2)
        return notify_fail("不知为什么，似乎freecv这个青蛙越来越像王子了。\n");
    if (flag=="chat")
    {
    message( "channel:" + "new",HIY + "【闲聊】" + content + "\n"NOR,users());
    }
    else
        message( "channel:" + "new",HIY + "【谣言】" + content + "\n"NOR,users());
    return 1;
}

int do_show(string arg)
{
    int ap,dp,pp;
    object *ob;
    int i;
    string obname,skill;
    if (!arg||sscanf(arg,"%s %s",skill,obname)!=2)
        return notify_fail("你想看谁的什么功夫的数据？\n");

    ob = all_inventory(environment(this_player()));
    for (i=0;i<sizeof(ob);i++)
    {
    if (ob[i]->query("id")==obname)
{
    ap = COMBAT_D->skill_power(this_player(), skill, SKILL_USAGE_ATTACK);    
    dp = COMBAT_D->skill_power(ob[i], "dodge", SKILL_USAGE_DEFENSE);    
    pp = COMBAT_D->skill_power(ob[i], "parry", SKILL_USAGE_DEFENSE);    

    tell_object(this_player(),HIY"你的ap是 : "+ap+" \n"+NOR);
    tell_object(this_player(),HIY+ob[i]->query("name")+"的dp是 : "+dp+" \n"+NOR);
    tell_object(this_player(),HIY+ob[i]->query("name")+"的pp是 : "+pp+" \n"+NOR);
    }
    }

    return 1;
}
