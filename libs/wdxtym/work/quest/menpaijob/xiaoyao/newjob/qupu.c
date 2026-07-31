//Cracked by Roath
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
        set_name(YEL "曲谱" NOR, ({ "qu pu", "pu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "册");
                set("long", "
一册裱钉精美的曲谱，你可以唱(chang)里面的曲子：

　《香冢·铭文》(xiangzhong)
　《洞仙歌》(dongxian_ge)
　《迈陂塘·雁丘词》(maipo_tang)
　《波斯小曲》(bosi_xiaoqu)
　《武动仙途》(xiaoao_jianghu)
　《山坡羊》(shanpo_yang)
　《蝶恋花》(dielian_hua)
　《采桑子》(caisang_zi)
　《无俗念》(wusu_nian)
　《洞仙歌》(dongxian_ge)
　《采桑子》(caisang_zi)
  《三台》(san_tai)
  《御街行》(yujie_xing)
  《醉垂鞭》(zuichui_bian)
  《水调歌头》(shuidiao_getou)
  《圆圆曲》(yuanyuan_qu)
  《望海潮》(wanghai_chao)
  《问世间  情为何物》(wenshi_jian)
  《蝶恋花》(dielian_hua)
  《饮马长城窟行》(yinma_changcheng)
  《春江花月夜》(chunjiang_huayueye)
  《将进酒》(jiangjin_jiu)
  《武动仙途》(xiaoao_jianghu)
  《虞美人》(yu_meiren)
  《白雪歌送武判官回京》(baixue_ge)

你如果觉得唱得不好，可以停(ting)下，再回去练练。
\n");
                set("value", 0);
                set("material", "silk");
             }
        setup();
}

void init()
{
        add_action("do_sing", "chang");
        add_action("do_halt", "ting");
}
#include "sing.c";

int do_halt()
{
        if (find_call_out("sing_stage") < 0) return 0;
        message_vision(HIR"\n$N发现大家一脸痛苦的表情，尴尬地咳嗽了两声，停下了噪音。\n"NOR, this_player());
        remove_call_out("sing_stage");
        return 1;
}

int do_sing(string arg)
{
       object me, ob,ob1;
       int i = sizeof(qupu);
       int stage;
        string st1,st2,song;
   mapping myfam, vtfam;
       stage = 0;
       me = this_player();
       ob = this_object();
       if (find_call_out("sing_stage") >= 0) return notify_fail("你能同时唱两首曲子吗？\n");
        if (!arg || arg=="") return notify_fail ("你想为谁唱什么啊？\n");

        if (sscanf( arg,"%s %s",st1,st2)!=2 )
           return notify_fail ("chang <某人> <曲名>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

if (environment(me)->query("sleep_room"))
                return notify_fail("卧室里唱歌，会影响别人休息。\n");

if( environment(me)->query("no_beg") &&
      environment(me)->query("no_fight") &&
       environment(me)->query("no_steal"))
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "逍遥派"))
          return notify_fail("只有逍遥派弟子才有这个资格！\n");
if( !ob1->is_character()
|| !living(ob1))
return notify_fail("只能对正常人弹琴唱歌。\n");

    if (me->query("gender")=="男性" && ob1->query("gender") !="女性" )
          return notify_fail("你一个大男人，为一个大男人弹琴唱歌??\n");
    if (me->query("gender")=="女性" && ob1->query("gender") !="男性" )
          return notify_fail("你一个大姑娘，给别的姑娘弹琴唱歌??\n");

song=st2;
me->set_temp("singn",st1);
       if(!arg) return notify_fail("你想唱什么？\n");
        while (i--) if (song == qupu[i]["name"]) break;
        if (i<0) return notify_fail("曲谱里还没有你想唱的曲子。\n");
        if(me->is_busy())
           return notify_fail("你正忙着呢。\n");
        message_vision(HIG"$N对$n点了点头。\n\n"NOR,me, ob1);
        message_vision(HIG"$N拿起古琴放在怀中慢慢的边弹边唱了起来，琴声清而不淡，响而不俗，令人不觉陶醉其中。\n\n"NOR,me, ob);
if (me->query_temp("singsong"))
{
if (qupu[i]["name"]!=me->query_temp("singsong"))
{
message_vision(HIW"不是叫$N练习"+me->query_temp("singsong")+"的吗?\n"NOR, me);
}
}
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
object ob1;
        int b1,b2;
if (!me)return;
   if(stage < size) {
            tell_object(me,qupu[i]["context"][stage]);
//   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
if (me->query("combat_exp") >1000000)
   call_out("sing_stage", 3, me, ++stage, i, size);
else    call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
         message_vision(HIG"\n过了一会，$N手中琴声渐缓渐轻，似乎流水汩汩远去，终于歌完曲终，寂然无声。\n"NOR, me);
if (!me)return;
if (!environment(me)) return;
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
		message_vision(HIY"听$N歌的人走了，看来$N是白忙了!\n\n"NOR,me);
          //return notify_fail(HIY"听你歌的人走了，看来你是白忙了.\n"NOR);
}
if (qupu[i]["name"]==me->query_temp("singsong"))
{
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
message_vision(HIY"听$N歌的人走了，看来$N是白忙了!\n\n"NOR,me);
         // return notify_fail(HIY"听你歌的人走了，看来你是白忙了.\n"NOR);
}
b1=ob1->query("per");
b2=ob1->query("per")*2/3;
if (!b1) b1=20;
if (!b2) b1=10;
if (b1 >62) b1=62;
if (b2 >50) b2=50;
b1=random(b1);
b2=random(b2);

me->add("combat_exp", 12+b1);
me->add("potential", 8+b2);
message_vision(HIG"$n听了后，心旷神移。对$N微微一笑!\n\n"NOR,me, ob1);
message_vision("$N的修为加了"+chinese_number(12+b1)+"点。\n", me);
message_vision("$N的潜能加了"+chinese_number(8+b2)+"点。\n", me);
me->delete_temp("singsong");
me->delete_temp("singn");
}
    }
}