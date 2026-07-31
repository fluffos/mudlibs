//Room: hcahoudian.c 华藏庵后殿
//Date: Oct. 2 1997 by That
#include <ansi.h>

inherit ROOM;
void do_chat();

void create()
{
      set("short","华藏庵后殿");
      set("long",@LONG
这是峨嵋山华藏庵的后殿。是峨嵋派掌门人传教弟子功夫的地方。这里供
有一尊普贤菩萨像。两旁靠墙放着几张太师椅，地上放着几个蒲团。掌门人正
在向几个女弟子传授武功。
LONG);
      set("objects", ([
           "quest/menpaijob/emei/miejue" : 1,
      ]));

	set("roomif","$botten#除妖任务|完成任务:ask shitai about job|give <物品> to shitai$#");	      
      set("no_get_from", 1);
      set("no_get", 1);
      set("no_steal", 1);
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "north"   : __DIR__"hcadadian", 
      ]));
      setup();
//      replace_program(ROOM);
}

void init()
{
    add_action("do_swear",  ({ "qishi", "fashi" }));
    add_action("do_huzhuo",  ({ "huzhuo" }));
    add_action("do_nod",  ({ "nod" }));
}

int do_swear()
{
    object ob, me = this_player();
    object where = environment(me);
    if( !(ob = present("miejue shitai", where) ) )
        return 0;
    if( me->query_temp("jiuyin/emei") < 5 )
        return 0;
    if( me->query("gender") == "女性" )
        message_vision("$N说道：小女子" + me->query("name") + "对天盟誓，日后我若对魔教教主张无忌这淫徒心存爱慕，
倘若和他结成夫妇，我亲身父母死在地下，尸骨不得安稳；我师父灭绝师太必成厉鬼，
令我一生日夜不安，我若和他生下儿女，男子代代为奴，女子世世为娼。\n", me);
    else
        tell_room(where, me->query("name")+"说道：不才" + me->query("name") + "一定要实现师太的两大愿望，逐走鞑子，
光复汉家山河；率领峨嵋派领袖群伦，盖过少林、武当，成为中原武林中的第一门派。
有违誓言者天打雷劈，万剑穿身，死无葬身之地。\n");
    tell_room(where, "灭绝师太脸上露出一丝笑容。\n");
    me->set_temp("jiuyin/emei", 6);
    tell_room(where, "灭绝师太说道：黄女侠在铸刀铸剑之前，和郭大侠两人穷一月心力，缮写了兵法和武功的
精要，分别藏在刀剑之中。屠龙刀中藏的乃是兵法，此刀名为‘屠龙’，意为日后有人得
到刀中兵书，当可驱除鞑子，杀了鞑子皇帝。倚天剑中藏的则是武学秘笈，其中最为宝贵
的，乃是一部‘九阴真经’，一部‘降龙十八掌掌法精义’，盼望后人习得剑中武功，替
天行道，为民除害。\n");
    tell_room(where, "灭绝师太说道：你取到屠龙刀和倚天剑后，来到我这里，一手执刀，一手持剑，运起内力，
以刀剑互斫(huzhuo)，宝刀宝剑便即同时断折，即可取出藏在刀身和剑刃中的秘笈。这是
取出秘笈的唯一法门，那宝刀宝剑可也从此毁了。你记住了么？\n");
    return 1;    
}

int do_nod()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") != 6 )
        return 0;
    me->set_temp("jiuyin/emei", 7);
    message_vision("$N只听得浑身热血沸腾，一股浩然的正气充满胸襟。\n", me);
    me->set("shen", me->query("combat_exp"));
    return 0;
}

int do_huzhuo()
{
    object ob, me=this_player();
    object ob0, ob1, ob2, where = environment(me);
    if( me->query_temp("jiuyin/emei") < 6 )
        return 0;
    if( !(ob1 = present("sky sword", me)) )
        return notify_fail("你身上没有峨嵋附近出现的真倚天剑！\n");
    if( !(ob2 = present("tulong dao", me)) )
{
if (me->query("blade_get"))
{
me->delete("blade_get");
}

        return notify_fail("你身上没有灵蛇岛附近出现的真屠龙刀！\n");
}
    if( !ob1->query_autoload() )
return notify_fail("这把剑不是真品!真品在峨嵋山附近！\n");
    if( !ob2->query_autoload() )
{
if (me->query("blade_get"))
{
me->delete("blade_get");
}
return notify_fail("这把刀不是真品!真品在灵蛇岛附近！\n");
}

    if( me->query_temp("jiuyin/emei") != 7 )
        return notify_fail("你答应了灭绝师太的要求了吗？\n");
    if (this_object()->query("alrea"))
    return notify_fail("已经有人把书拿走了!\n");
    if( !(ob = present("miejue shitai", where) ) )
        return notify_fail("灭绝师太不在这里，你最好先别这样做。\n");
    message_vision("只见$N一手执刀，一手持剑，运起内力，刀剑互斫。
只听见‘哧’的一声轻响，这两把举世无双的屠龙刀和倚天剑就此消失了。\n", me);
    destruct(ob1);
    destruct(ob2);
    me->delete("blade_get");
    message_vision("灭绝师太从断刀断剑中取出了几张帛卷，看了几眼，拿出一张帛卷交给了$N。\n", me);
    if( me->query_skill("xianglong-zhang", 1) > 0)
        tell_room(where, "灭绝师太说道：降龙十八掌你已经学了，这卷九阴速成篇你就拿去学吧。\n");
    else
        tell_room(where, "灭绝师太说道：你的武学路子与降龙十八掌的刚阳劲力不符，这本九阴速成篇你就拿去学吧。\n");
    tell_room(where, "灭绝师太说道：待我觅得一个心地仁善、赤诚为国的志士，将兵书传授于他，要他立誓驱除胡虏。\n");
    me->delete_temp("jiuyin/emei");
    me->set("jiuyin/emei", 1);
    ob0 = new("/clone/book/jiuyin-sucheng");
    ob0->move(me);
    this_object()->set("alrea",1);
    message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到九阴速成篇啦。\n"NOR, users());
    return 1;
}
