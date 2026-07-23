// flower.c 情花
// By River 99/05/20
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
       set_name(HIM"情花" NOR, ({"qing hua", "flower", "hua"}));
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
       else {
             set("long", "这是一朵极为鲜艳的情花。\n"+
                         "花瓣的颜色娇艳无比，似芙蓉而更香，如山茶而增艳。\n");
             set("unit", "朵");
             set("no_drop", 1);
             set("no_get", 1);
             set("no_give",1);    
             set("drug", 1);
             set("material", "plant");
             set("wear_msg", "$N将$n插在发髻上。\n");
             set("remove_msg", "$N从发髻上摘下了$n。\n");
             set("armor_prop/armor", 1);
       }
       setup();
}

void init()
{
     add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit, improve;
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");

        if(!id(arg)) return notify_fail("你要吃什么？\n");

        message_vision(HIY"$N将"HIM"情花"HIY"一瓣瓣的摘下送入口中，入口香甜，芳甘似蜜，更微有醺醺然的酒气。\n"NOR,me);

        if(me->query_condition("medicine")){
            me->add("max_neili", -10);
            tell_object(me,HIY"你正感心神俱畅，但嚼了几下，却有一股苦涩的味道直冲心头。\n"NOR);
            log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力十点。\n",
              ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));
            me->unconcious();
            destruct(this_object());
            return 1;
        }
        
if( random(3)!= 0 )
{
 tell_object(me,HIY"你正感心神俱畅，却忽然觉得心中难过无比，想要呕吐，却又吐不出来。\n"NOR);
me->apply_condition("qinghua_poison",60);
me->apply_condition("medicine",60);
log_file("quest/neili",sprintf("%s %s(%s)吃情花中毒。\n",
ctime(time())[4..19],me->name(1),capitalize(me->query("id"))));
destruct(this_object());
return 1;
}
        message_vision(HIY"虽略感苦味，要待吐出，似觉不舍，要吞入肚内，又有点难以下咽。\n"NOR,me);
        improve = 1 + random(2);
        if(!me->query("marry") || neili_limit > force_limit)
            me->set("food",me->max_food_capacity());
        else {
            me->add("max_neili",improve);
            me->set("food",me->max_food_capacity());
            log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
              ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
            me->apply_condition("medicine", 60);
        }
        destruct(this_object());
	return 1;
}
