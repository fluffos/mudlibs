#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(HIW"神奇泥巴"NOR, ({ "niba" }));
     set_weight(1000);
     if( clonep() )
            set_default_object(__FILE__);
     else {
            set("long", HIY"这就是泥潭中最伟大的东西：泥巴！有了它！你可以变（bian）成任何东西。"NOR);
            set("unit", "支");
            set("value", 1);
            set("no_pawn", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_get_from", 1);
            set("material", "steel");
          }
     setup();
}

void init()
{
        add_action("do_bian", "bian");
        add_action("do_da","da");
}

int do_da(string target)
{
       object me, ob, conc;
       ob = this_object();
       me = this_player();

	if(!wizardp(me) || wiz_level(me) < 1 )
		return notify_fail(HIR"这不是你能使用的东西，快上交wiz！\n"NOR);

       if( !target )
                return notify_fail("你要向谁打出"HIW"神奇泥巴"NOR"?！\n");

       if(!(conc = find_player(target)))       
             if(!(conc = find_living(target))) 
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }

       if (target=="lywin" && userp(conc))
            conc = this_player();

       message_vision(HIR"$N伸手从摸出一块"HIW"神奇泥巴"HIR"打向$n"HIR"。\n" NOR, me, conc);

       message_vision(HIR"只见一道"HIW"白色的光芒"HIR"射向$n"HIR"，把$p的身体分子结构重新调整了一遍。\n" NOR, me, conc);

       CHANNEL_D->do_channel(this_object(), "rumor", sprintf("%s被"HIW"神奇泥巴"HIM"打出了原形。", conc->name(1)));

       conc->set("invisibility",10);  
       conc->set("env/invisibility",0);    
       find_player(target)->move("/clone/misc/void"); 
       find_player(target)->delete_temp("apply/name"); 
       find_player(target)->delete_temp("apply/id"); 
       find_player(target)->delete_temp("apply/short"); 
       find_player(target)->delete_temp("apply/long"); 
       return 1;
}

int do_bian(string arg)
{
      object me, who;
      me = this_player();

      if(!wizardp(me) || wiz_level(me) < 1 )
		return notify_fail(HIR"这不是你能使用的东西，快上交wiz！\n"NOR);

      if (!arg || arg=="me" || arg=="none" ) {
          if( me->query("bianshen/BIAN") < 1) 
              return notify_fail("这已经是你的真身了。\n");
         
          me->delete_temp("spellslevel");
          me->delete_temp("apply/name");
          me->delete_temp("apply/id");
          me->delete_temp("apply/short");
          me->delete_temp("apply/long");
          me->delete("bianshen/BIAN"); 
          while( environment(me)->is_character() )
          me->move(environment(environment(me)));
          message_vision(HIY "$N口念咒语，身形一晃，现了真身。\n"NOR,me);
          return 1;
          }
  
      if(!objectp(who=present(arg,environment(me)))) 
          return notify_fail(HIB"你想变成谁？\n"NOR);

      if ((wizardp(who) && !wizardp(me)) || wiz_level(me) < wiz_level(who))
                return notify_fail(HIW"神奇泥巴"NOR"不能让你变成比你高级的巫师。\n");
   
       message_vision(HIY "$N手拿"HIW"神奇泥巴"HIY"向身上一贴，摇身一变，变得和$n一模一样"HIY"！\n" NOR,me,who);
       me->set_temp("apply/name",({who->name()}));
       me->set_temp("apply/id",who->parse_command_id_list());
       me->set_temp("apply/short", ({who->short()}));
       me->set_temp("apply/long", ({who->long()}));
       me->set_temp("is_character",who->is_character());
       me->set_temp("is_living",living(who));
       me->set_temp("gender",who->query("gender"));
       me->set_temp("age",who->query("age"));
       me->set_temp("race",who->query("race"));
       me->set_temp("family",who->query("family"));
       me->set_temp("unit",who->query("unit"));
       me->set("bianshen/BIAN", 1);
       return 1;
}
