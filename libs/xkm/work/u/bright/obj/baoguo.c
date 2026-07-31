//write by bright
//ftb cike have baoguo
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"包裹"NOR, ({ "bao guo", "baoguo", "bao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个神秘的包裹,不知道里面有什么,你可以打开(open)看看。\n");
                set("value", 50);
        }
        setup();
}

void init()
{
        add_action("do_open", "dakai");
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object ob, me=this_player();

        if ( !arg || arg == "" ) {
        write("你要打开什么?");
        return 1;
        }
        if ( arg == "baoguo" || arg == "bao guo"|| arg == "bao" ) 
        {
          if(random(8)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/quest/feizei/lingzhi");
           ob->move(me);
           write(HIY"你打开包裹一看,是一枚"+RED"千年灵芝"NOR+","+HIY"急忙将它放在怀里! \n"NOR);
           CHANNEL_D->do_channel(this_object(), "rumor",
               me->query("name")+"得到"HIR"千年灵芝"NOR+HIM"啦！\n");
           destruct(this_object());
           return 1;
          }
          if(random(5)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/clone/money/gold");
           ob->move(me);
           write(HIY"你打开包裹一看,只有一两黄金,你暗骂穷鬼! \n"NOR);
           destruct(this_object());
           return 1;
          }
          if(random(6)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/clone/money/yuanbao");
           ob->move(me);
           write(HIW"你打开包裹一看,是一定"+HIY"金元宝"NOR+","+HIW"急忙将它放在怀里! \n"NOR);
            CHANNEL_D->do_channel(this_object(), "rumor",
               me->query("name")+"得到"HIR"金元宝"NOR+HIM"啦！\n");
           destruct(this_object());
           return 1;
          }
          if(random(30)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/u/xkxmud/obj/putizi");
           ob->move(me);
           write(HIY"你打开包裹一看,是一粒"+HIW"菩提子"NOR+","+HIY"急忙将它放在怀里! \n"NOR);
            CHANNEL_D->do_channel(this_object(), "rumor",
               me->query("name")+"得到"HIR"菩提子"NOR+HIM"啦！\n");
           destruct(this_object());
           return 1;
          }
          if(random(35)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/u/xkxmud/obj/shelizi");
           ob->move(me);
           write(HIY"你打开包裹一看,是一粒"+HIW"舍利子"NOR+","+HIY"急忙将它放在怀里! \n"NOR);
            CHANNEL_D->do_channel(this_object(), "rumor",
               me->query("name")+"得到"HIR"舍利子"NOR+HIM"啦！\n");
               destruct(this_object());
           return 1;
          }
          if(random(80)==1)
          {
           write(HIW"你小心打开包裹! \n"NOR);
           ob = new("/u/xkxmud/obj/qqtang");
           ob->move(me);
           write(HIY"你打开包裹一看,是一粒"+HIW"QQ糖"NOR+","+HIY"急忙将它放在怀里! \n"NOR);
           
            CHANNEL_D->do_channel(this_object(), "rumor",
               me->query("name")+"得到"HIR"QQ糖"NOR+HIM"啦！\n");
               destruct(this_object());
           return 1;
          }
         else
         write(RED"你打开包裹一看,什么也没有! \n"NOR);
         destruct(this_object());
         return 1;
        }
}
