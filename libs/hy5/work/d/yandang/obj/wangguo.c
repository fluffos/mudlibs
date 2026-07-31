inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG "忘魂果" NOR,({"wangguo","DEADLY poison"}));
  set("long", HIG
      "这是一颗人们在求生无望，为了减轻死前的痛苦\n"
      "用来解脱（ｄｉｅ）的毒果．如果你中了剧毒，这果子刚好．\n" NOR);
  set("value",10000);
  set("no_pawn",1);
  set("unit","棵");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","die");
}

int do_cure()
{
	object me;
	me = this_player();
	if( !living(me))	return 0;
	message_vision("$N把忘魂果一口吞了下去！\n",me);
       if (!me->query_condition("killer") && !me->query_condition("psgc") )
        {
me->clear_condition("anqi_poison");
me->clear_condition("baituo_poison");
me->clear_condition("bat");
me->clear_condition("bing_poison");
me->clear_condition("binghuo");
me->clear_condition("black_poison");
me->clear_condition("broken_arm");
me->clear_condition("canxia");
me->clear_condition("chanchu_poison");
me->clear_condition("chilian_poison");
me->clear_condition("cold_poison");
me->clear_condition("corpse_poison");
me->clear_condition("cuixin_zhang");
me->clear_condition("dashouyin");
me->clear_condition("dragon_poison");
me->clear_condition("emerald_poison");
me->clear_condition("fire_poison");
me->clear_condition("flower_poison");
me->clear_condition("green_blood");
me->clear_condition("hehe");
me->clear_condition("hot_poison");
me->clear_condition("huanyin_poison");
me->clear_condition("ice_poison");
me->clear_condition("iceshock");
me->clear_condition("ill_dongshang");
me->clear_condition("ill_fashao");
me->clear_condition("ill_keshou");
me->clear_condition("ill_kesou");
me->clear_condition("ill_shanghan");
me->clear_condition("ill_zhongshu");
me->clear_condition("insect_poison");
me->clear_condition("juehu_hurt");
me->clear_condition("jy-poison");
me->clear_condition("jy_poison");
me->clear_condition("libie");
me->clear_condition("new_poison1");
me->clear_condition("new_poison2");
me->clear_condition("new_poison3");
me->clear_condition("new_poison4");
me->clear_condition("new_poison5");
me->clear_condition("new_poison6");
me->clear_condition("new_poison7");
me->clear_condition("new_poison8");
me->clear_condition("no_shadow");
me->clear_condition("nx_poison");
me->clear_condition("poison");
me->clear_condition("poison_sandu");
me->clear_condition("qiankun_wound");
me->clear_condition("qiankunyibang");
me->clear_condition("qinghua_poison");
me->clear_condition("qishang_poison");
me->clear_condition("qx_snake_poison");
me->clear_condition("rose_poison");
me->clear_condition("sanpoison");
me->clear_condition("sanxiao_poison");
me->clear_condition("scorpion_poison");
me->clear_condition("shenlong_poison");
me->clear_condition("shenzhao");
me->clear_condition("sl_poison");
me->clear_condition("snake_poison");
me->clear_condition("ss_poison");
me->clear_condition("tiezhang_yang");
me->clear_condition("tiezhang_yin");
me->clear_condition("tmpili_poison");
me->clear_condition("tmqidu_poison");
me->clear_condition("tmzhuihun_poison");
me->clear_condition("unknown");
me->clear_condition("wudoumi-fanshi");
me->clear_condition("wugong_poison");
me->clear_condition("wuhudu_poison");
me->clear_condition("wuxing_poison");
me->clear_condition("x2_poison");
me->clear_condition("x2_sandu");
me->clear_condition("xiezi_poison");
me->clear_condition("xscold_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuantian_han");
me->clear_condition("xx_condition");
me->clear_condition("xx_liandu");
me->clear_condition("xx_poison");
me->clear_condition("xx_sandu");
me->clear_condition("yf_poison");
me->clear_condition("yufeng_poison");
me->clear_condition("yyz_damage");
me->clear_condition("zhizhu_poison");
me->clear_condition("zhua_poison");
me->clear_condition("zimu-zhen");
me->clear_condition("zm_poison");
me->clear_condition("zmqidu_poison");
      }
	me->unconcious();
	destruct(this_object());
	me->unconcious();
  return 1;
}
