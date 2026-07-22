// m_sword.c
#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON;
int do_rename2(string arg);
void init()
{
   if (!mapp(this_player()->query("weapon2"))){
     this_object()->owner_is_killed();
     return;
   }

     if (this_player()!=environment()) return;
        add_action("do_duanlian2","duanlian2");
    add_action("do_hui2","hui2");
    add_action("do_rename2","rename2");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    int w_lv;
    me = this_player();
//读入数据
//自制武器被他人得到后有bug，加入以下语句可以解决。
        if (!(me->query("weapon2/name")))
{
                remove_call_out("destrory");
                call_out("destrory",1,me);
                return;
}
    w_name=me->query("weapon2/name");
    w_id = me->query("weapon2/id");
    w_or = me->query("weapon2/or");
    w_lv = me->query("weapon2/lv");
    set_name(w_name, ({w_id,"staff"}));
        set("owner_id",me->query("id"));
    set("unit", "柄");   
    set("no_get",1);
    set("no_drop",1);
    set_desc(w_lv,w_or,w_name);
    switch(w_or)
        {
        case "千年神木" :
            set_weight(6000+w_lv*500);
            set("material", "iron");
            break;
        case "海底金母" :
            set_weight(8000+w_lv*500);
            set("material", "steel");
            break;
        case "寒丝羽竹" :
            set_weight(4000+w_lv*500);
            set("material", "bamboo");
            break;
        default :
        } 
    set("wield_msg", "$N往背后一摸，掏出了一把"+w_name+"\n");
    set("unwield_msg", "$N手中"+w_name+"一挥，眨眼间已然不见影踪。\n");
    init_staff(w_lv * 10,1);
    setup();
}   
int do_duanlian2(string arg)
{
    object me,weapon;
    int w_zhi, w_level;
    string w_or;
    me=this_player();
    if( !arg || !id(arg) )
        return notify_fail("你要锻炼什么?\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力不够，无法锻炼杖体！\n");
    if( (int)me->query("qi") < 150 )
        return notify_fail("你的气不够，无法锻炼杖体！\n");
    if( (int)me->query("eff_qi") < 50 )
        return notify_fail("你现在的体力太弱，无法锻炼杖体！\n");
    if( (int)me->query("eff_jing") < 50 )
        return notify_fail("你现在的精力无法集中，不能锻炼杖体！\n");
    if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
        return notify_fail("你的潜能不够，无法锻炼杖体！\n");
    message_vision(HIR "$N手握杖端，一股内力丝丝的传了进去。\n" NOR, me);
    me->add("max_neili",-10);
    me->set("neili", (int)me->query("max_neili"));
    me->add("qi",-150);
    me->add("eff_qi",-30);
    me->add("eff_jing",-30);
    me->add("learned_points", 2);
    w_zhi = (int)me->query("weapon2/value");
    w_zhi++;
    me->set("weapon2/value", w_zhi);
    w_or = (string)me->query("weapon2/or");
    w_level = (int)me->query("weapon2/lv");
    if( w_zhi >= ((w_level + 1) * (w_level + 1)))
    {
        w_level++;
        me->set("weapon2/lv", w_level);
        message_vision(HIY "杖身忽的一亮，一道金光隐入$N的杖体，不见了！\n" NOR,me);
        message_vision(HIG "$N的杖的等级提高了！\n" NOR, me);
        weapon=this_object();
        if(weapon->query("equipped") ) 
            weapon->unequip();
        reload_object( weapon );
        me->set("weapon2/value",0);
        return 1;
    }
    message_vision(RED "$N的杖的硬度提高了!\n" NOR, me);
    return 1;
}
int do_hui2(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon2/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR "你大喝一声，一掌擎杖，一掌猛力击下。结果轰隆一声巨响"
            +this_object()->name()+HIR+"断为两截!\n" NOR,me);
    me->delete("weapon2");
    
    me->save();
    destruct( this_object() );
    return 1;
}
int do_rename2(string arg)
{
    object me;
    me=this_player();
    if( !arg )
        return notify_fail("你改什么的名字?\n");
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);
    me->set("weapon2/name",arg+NOR);
    set("name",arg+NOR);
    write("ok!\n");
    this_object()->create();
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       object weapon;
       int w_lv,w_val,dam;
       int level;

       dam = this_object()->query("weapon_prop/damage");
       level=random(dam/60);

       if( query("equipped") && level)
       {
        if( level==1 )
        {
         message_vision(HIY"$N一阵手忙脚乱，不知道如何应对是好！\n"NOR,victim);
         if( !victim->is_busy() )
         victim->start_busy(random(3)+1);
        } else       
        if( level==2 )
        {
         message_vision(HIR"$N只觉得一阵透骨的杀气从"NOR+query("name")
         +HIR"上涌来，“扑哧”一声，杀气透体而入，\n激起阵阵血雾！\n"NOR,victim);
         victim->receive_damage("qi",dam/2+random(dam/2),me);
         victim->receive_wound("qi",dam/3+random(dam/3),me); 
        } else
        if( level==3 )
        {
         message_vision(HIB"$N只觉得一阵铺天盖地的寒意从"NOR+query("name")
         +HIB"迎面逼了过来，顷刻间已透彻胸肺！\n"NOR,victim);
         victim->receive_damage("jing",dam/3+random(dam/3),me);
         victim->receive_wound("jing",dam/4+random(dam/4),me); 
        } else
        {
         message_vision(HIC"$N"NOR+query("name")+HIC"未至，杀意已至，手中"NOR
         +query("name")+HIC"竟激起一阵阵嗡鸣，\n"
         +"片刻间漫天杀意已将$n席卷在内！\n"NOR,me,victim);
         victim->receive_damage("qi",dam/2+random(dam/2),me);
         victim->receive_wound("qi",dam/3+random(dam/3),me); 
         victim->receive_damage("jing",dam/3+random(dam/3),me);
         victim->receive_wound("jing",dam/4+random(dam/4),me); 
        }
       }
 
       if(objectp(weapon=me->query_temp("weapon"))
           && me->query("weapon2/make")
           && me->query("weapon2/id") == weapon->query("id")    
           && me->query("weapon2/lv") > 12
           && me->query("weapon2/lv") < 50
           && random( (int)victim->query("combat_exp")) > (int)me->query("combat_exp") )
            {
             w_lv= me->query("weapon2/lv");
             w_val=me->query("weapon2/value");
             w_val++;
             me->set("weapon2/value",w_val);
            if( w_val >= (w_lv+1)*(w_lv+1))
            {
       message_vision(HIY"$N手中"NOR+weapon->query("name")
            +HIY"忽的一亮，一道金光飞跃而起，转眼又不见了！\n" NOR,me);

       w_lv++;
       me->set("weapon2/lv",w_lv);
       if(weapon->query("equipped") )
       weapon->unequip();
       reload_object( weapon );
       me->set("weapon2/value",0);
       return 1;
            } else
            {
       message_vision(HIR"$N的"NOR+weapon->query("name")
            +HIR"在战斗中等级提升了！\n" NOR, me);
           return 0;
           }
          }
          return 0;
}

void destrory(object ob)
{
        destruct(ob);
}
