#include "armor.h"
#include "weapon.h"
#include "ansi.h"
inherit CLOTH;
void create()
{
        set_name(HIY"黄金圣衣"NOR,({"huangjin shengyi","shengyi","yi"}));
set_weight(1);
if(clonep())
        set_default_object(__FILE__);
else {
         set("unit","件");
                set("material", "cloth");

         set("no_get","1");
         set("no_drop","1");
         set("no_steal","1");
         set("value","6000");
        set("wear_msg",HIY"你取出一件黄金圣衣穿在身上,刹那间，天云变色，$N被一片金光包了起来。\n"NOR);
        set("armor_prop/armor",500);

     }
      setup();
}
void init()
{
add_action("do_room","bk");//回/u/hehe/room.c
      add_action("do_yz","yz");
add_action("do_qz","qz");
add_action("do_jx","jx");
add_action("do_px","px");
add_action("do_xy","xy");
add_action("do_bj","bj");
add_action("do_ts","ts");
add_action("do_xkd","xkd");
add_action("do_xkds","xkds");
add_action("do_xkx","xkx");
add_action("do_gb","gb");
add_action("do_qzj","qzj");
add_action("do_sl","sl");
add_action("do_hs","hs");
add_action("do_qz","qz");
add_action("do_wds","wds");
add_action("do_tl","tl");
add_action("do_em","em");
add_action("do_mj","mj");
add_action("do_xx","xx");
add_action("do_ry","ry");
add_action("do_lj","lj");
add_action("do_dl","dl");
}
int do_yz()
{
this_player()->move("/d/city/guangchang");
return 1;
}
int do_room()
{
this_player()->move("/u/hehe/room");
return 1;
}
int do_qz()
{
this_player()->move("/d/quanzhou/zhongxin");
return 1;
}
int do_jx()
{
this_player()->move("/d/quanzhou/nanhu");;return 1;
}
int do_px()
{
this_player()->move("/d/pingxiwangfu/shu_fang");
return 1;
}
int do_xy()
{
this_player()->move("/d/xiangyang/xycenter");
return 1;
}
int do_bj()
{
this_player()->move("/d/xingxiu/beijiang");
return 1;
}
int do_ts()
{
this_player()->move("/d/taishan/yuhuang");
return 1;
}
int do_xkd()
{
this_player()->move("/d/xiakedao/shatan1");
return 1;
}
int do_xkds()
{
this_player()->move("/d/xiakedao/shishi1");
return 1;
}
int do_xkx()
{
this_player()->move("/d/xiakedao/study_room");
return 1;
}
int do_gb()
{
this_player()->move("/d/city/gbxiaowu");
return 1;
}
int do_hs()
{
this_player()->move("/d/huashan/shufang");
return 1;
}
int do_qzj()
{
this_player()->move("/d/quanzhen/gongmen");
return 1;
}
int do_wds()
{
this_player()->move("/d/wudang2/sanqing");
return 1;
}
int do_tl()
{
this_player()->move("/d/dali/dadian");
return 1;
}
int do_em()
{
this_player()->move("/d/emei/qingyin");
return 1;
}
int do_mj()
{
this_player()->move("/d/mingjiao/dadian");
return 1;
}
int do_xx()
{
this_player()->move("/d/xingxiu/xxh2");
return 1;
}
int do_ry()
{
this_player()->move("/d/riyuejiao/rukou");
return 1;
}
int do_lj()
{
this_player()->move("/d/lingjiu/zhengting");
return 1;
}
int do_sl()
{
this_player()->move("/d/shaolin/guangchang1");
return 1;
}
