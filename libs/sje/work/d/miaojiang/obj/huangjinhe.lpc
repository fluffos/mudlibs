
inherit ITEM;

void create()
{
        set_name("黄金盒",({ "huangjin he", "he" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "只");
              set("material", "steel");
              set("treasure",1);
              set("long", "一只由黄金打造的小盒子，里面装着两只花蛛，似乎是修炼极歹毒的邪派功夫而用。\n");
              set("value", 500);
              set("skill", ([
                        "name": "poison",
                        "exp_required": 1000,
                        "jing_cost": 20,
                        "jingli_cost": 20,
                        "neili_cost": 30,
                        "qi_cost": 30,
                        "difficulty": 10,
                        "max_skill": 200,
                ]) );
        }
}

void init()
{
        if( this_player() == environment() )
                add_action("do_suck", "suck");
}

int do_suck(string arg)
{
        object me = this_player();

        if ( arg != "blood" || !living(this_player()))
        return notify_fail("你要吸什么？\n");

        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成, 不能运功练毒。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("千蛛万毒手必须空手练习。\n");
        if ((int)me->query_skill("poison", 1) < 120)
        return notify_fail("你毒技不够，学不了千蛛万毒手。\n");
        if ((int)me->query_skill("qianzhu-wandushou", 1) < 31)
        return notify_fail("你千蛛万毒手的基础不够，无法继续提高。\n");
         if ((int)me->query("max_neili") < 1000)
        return notify_fail("你内力修行太差, 抵抗不了毒质。\n");
        if ( me->is_fighting())
        return notify_fail("你在战斗中不能运功练毒。\n");

   

        if ((int)me->query_skill("poison", 1) <= 200 )
          {
              me->receive_damage("jing", 20);
              me->receive_damage("jingli", 20);
              me->receive_damage("qi", 25);
              me->add("neili", -30);
         

              message_vision("$N满脸庄严肃穆之容，将两根手指伸进盒中，里面的花蛛慢慢爬
近，咬住了$N的食指。$N深深吸口气，两臂轻轻颤抖，潜运内力
和蛛毒向抗。同时眉心和两旁的太阳穴淡淡的罩上了一层黑气，
$N紧咬牙关，竭力忍受痛苦。过了良久，慢慢睁开眼睛，脸上
黑气渐退，重现血色，一口气喷了出来，周围弥漫着一股甜香。\n", me);
              switch(random(2)) {
                     case 0:
                       me->improve_skill("poison", (int)(me->query("int") / 5));
                       write ("你用内力将经脉中的毒质缓缓逼入丹田，只觉浑身一凉。\n" "你对基本毒技的领会又加深了一些! \n");
                       break;
                      case 1:
                       me->improve_skill("chousui-zhang", (int)(me->query("int") / 2));
                       write ("你急速运转手指上血脉，带着花蛛体内的毒液，回入自己血中。\n" "你对千蛛万毒手的领会又加深了一层! \n");
                       break;
                     }
              return 1;
           }

           return 0;
}

