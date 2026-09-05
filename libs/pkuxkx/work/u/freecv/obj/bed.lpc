// bed.c freecv的king size 水床
// by freecv
// 2005.1.19

#include <ansi.h>
inherit ITEM;

int do_tuo(string);
int do_chuan(string);
int do_unfold(string);
int do_fold(string);
int do_sleep(string);
int do_love(string);

void setup()
{}

void create()
{             
        set_name(HIC"freecv king size 水床"NOR,({"water bed","bed"}));
        set_weight(999999);
        set("no_get",1);
        set_max_encumbrance(999999);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit","张");
                set("long",HIG"freecv的一张豪华舒适的king size水床,正面对着迎着阳光的落地百叶窗。\n它似乎可以用来(tuo,chuan,fold,unflod,sleep,love)"NOR);
                set("up",3);
                set("down",3);
        }

}

void init()
{
        add_action("do_tuo","remove");
        add_action("do_chuan","wear");
        add_action("do_unfold","unfold");
        add_action("do_fold","fold");
        add_action("do_sleep","sleep");
        add_action("do_love","love");
}

int do_tuo(string arg)
{
  object bed = this_object();
  if (!arg ) return notify_fail("你要脱什么? \n");
  if (arg == "clothes")
    switch (bed->query("up"))
    {
      case 3:
              message_vision("$N进步靠上床来,随手轻扬,将外衣挂在床梢.\n",this_player());
              bed->add("up",-1);
              break;
      case 2:
              message_vision("突然$N眉若柳梢,款手轻解,将中衣徐徐退下，室内顿时一片春意...\n",this_player());
              bed->add("up",-1);
              break;
      case 1:
              message_vision("$N只觉羞不可言,衣衫刚一离身，立刻以手掩胸,寻找背角,口里念念有词,不好啦,偶还是比较喜欢拉拉啦....\n",this_player());
              bed->add("up",-1);
              break;
      default:
              message_vision("wofaint,到底有没有怜香惜玉啊,这么BT想拔人皮的话自己实验去好了,kick~~~~fly.\n",this_player());
              break;
    }
  return 1;
}
