// Made by goodtaste
//modified by advent
#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit BLADE;
int return_normal(object ppl,object ob);
void create()
{
        set_name(HIB"屠龍刀"NOR, ({ "tulong dao","dao" }));
        set_weight(8000);
        set("value",0);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIW+"宝刀屠龙，武林称雄。倚天不出，谁与争锋。但见此刀乌沉沉的，非金非铁，不知是何物所制！\n"+NOR);
                set("value", 0);
                set("no_drop",this_object()->query("name")+HIR"是武林至宝，多少人为它丢掉了性命，你竟然舍得把他扔掉？\n"NOR);
                set("no_give",this_object()->query("name")+HIR"是武林至宝，多少人为它丢掉了性命，你竟然舍得把他送给别人？\n"NOR);
                set("no_steal",1);
                set("no_store",1);
                set("no_pawn",1);
                set("no_sell",1);
                set("unique",1);
                set("material", "steel");
                set("weapon_prop/strength", 5);
                set("weapon_prop/dexerity",-2);
                set("weapon_prop/intelligence",2);
                set("wield_msg", HIR"$N从身后拔出一柄乌沉沉的宝刀，霎时间，如雪的刀光映在$N脸上。\n$N手持宝刀，纵声狂笑：\n"HIR
                        +"武林至尊....................\n"
                        +"宝刀屠龙....................\n"
                        +"号令天下....................\n"
                        +"莫敢不从....................\n"+NOR);
                set("unwield_msg", "寒光一闪，$N已把"+query("name")+"插回鞘中。\n");
                set("preorder",0);
                set("robinterval",7200);  
        }
        init_blade(300);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
         object weapon,ob,ob2;
//        me->add_temp("apply/attack",30);
//        me->add_temp("apply/dodge", 30);
//        me->add_temp("apply/damage",30);
        if(!objectp(weapon=victim->query_temp("weapon")))
                message_vision(MAG"\n刀光一闪，$N眼看刀锋便要扫到自己身上，却避无可避。"NOR,victim);
        else if(weapon->query("id")=="yitian jian")
                {
        message_vision(HIG"\n$N的"+this_object()->query("name")+HIW+
                                                "与$n手中的"+weapon->query("name")+HIW+
                                                "相击，刀剑俱成两截。"NOR,me,victim); 
        message( "channel:" + "rumor",HIM+ "【谣言】"+me->query("name")+HIM"发现了屠龙刀与倚天剑中的秘密！\n"NOR,users());
                weapon->unequip();
                weapon->move(environment(victim));
                weapon->set("name", "断掉的" + weapon->query("name"));
                weapon->set("value", 0);
                weapon->set("weapon_prop", 0);

                this_object()->unequip();
                this_object()->move(environment(victim));
                this_object()->set("name", "断掉的" + this_object()->query("name"));
                this_object()->set("value", 0);
                this_object()->set("weapon_prop", 0);
                me->reset_action();
                ob = new(__DIR__"yijinjing");
                ob->move(this_player());
                ob2 = new("/d/reborn/jinyong/obj/yttlj");
                ob2->move(environment(victim));
                message_vision(HIY"$N得到了易筋经！\n"NOR,me);
                message_vision(HIC"“啪”的一声，一本书掉在了地上！\n"NOR,me);
                }                                                                           
        else
        {
                if (random(20)==1)
		{
		message_vision(HIW"\n只听“嚓”的一声，$N手中的$n已被"+
                        this_object()->query("name")+HIW+"斩成两截！"NOR,victim,weapon);
                weapon->unequip();
                weapon->move(environment(victim));
                weapon->set("name", "断掉的" + weapon->query("name"));
                weapon->set("value", 0);
                weapon->set("weapon_prop", 0);
                remove_call_out("remove_broken_weapon");
               call_out("remove_broken_weapon", random(30)+60,weapon);
                me->reset_action();
		}
        }
        call_out("return_normal",60,me,this_object());
        return NOR;
}

int return_normal(object ppl,object ob)
{
//        ppl->add_temp("apply/attack",-30);


//        ppl->add_temp("apply/dodge", -30);
//        ppl->add_temp("apply/damage",-30);
        return 1;
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}

