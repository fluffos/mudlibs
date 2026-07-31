// m_sword.c
#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON;
int do_hui(object weapon);
int do_rename(string arg);
int do_qie(string arg);
int do_clean(string arg);
int do_xiang(object me,object obj);
void init()
{
   if (!mapp(this_player()->query("weapon"))){
     this_object()->owner_is_killed();
     return;
   }

     if (this_player()!=environment()) return;
        add_action("do_duanlian","duanlian");
    add_action("do_hui","hui");
    add_action("do_rename","rename");
     add_action("do_qie","xiangqian");
    add_action("do_clean","clean");

}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    int w_lv,w_lv2;
    me = this_player();
//读入数据
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    w_lv = me->query("weapon/lv");
    w_lv2 = me->query("weapon/damage");

    set_name(w_name, ({w_id,"whip"}));
    set("unit", "柄");   
    set("zhuren", me->query("id"));
    set("no_get",1);
    set("no_drop",1);
    set("no_give",1);
    set("nopaimai",1);
    if ( me->query("weapon/int") ) 
    set("weapon_prop/intelligence",me->query("weapon/int"));
    if ( me->query("weapon/dex") ) 
    set("weapon_prop/dexerity",me->query("weapon/dex"));
    if ( me->query("weapon/con") ) 
    set("weapon_prop/constitution",me->query("weapon/con"));
    if ( me->query("weapon/str") ) 
    set("weapon_prop/strength",me->query("weapon/str"));
    set_desc(w_lv,w_or,w_name);
    switch(w_or)
        {
        case "千年神木" :
            set_weight(6000+w_lv*450);
            set("material", "iron");
            break;
        case "海底金母" :
            set_weight(8000+w_lv*450);
            set("material", "steel");
            break;
        case "寒丝羽竹" :
            set_weight(4000+w_lv*450);
            set("material", "bamboo");
            break;
        default :
        } 
    set("wield_msg", "$N往腰中一摸，刷的抖出了一把"+w_name+"\n");
    set("unwield_msg", "$N手中"+w_name+"一抖，眨眼间卷回腰间不见了影踪。\n");
    init_whip(w_lv * 10 + w_lv2,2);
    setup();
}   
int do_duanlian(string arg)
{
    object me;
    object weapon;
    string w_name;
    int w_zhi, w_level;
    string w_or;
    me=this_player();
    w_name=me->query("weapon/name");
    if( !arg || !id(arg) )
        return notify_fail("你要锻炼什么?\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力不够，无法锻炼兵器！\n");
    if( (int)me->query("qi") < 150 )
        return notify_fail("你的气不够，无法锻炼兵器！\n");
    if( (int)me->query("eff_qi") < 50 )
        return notify_fail("你现在的体力太弱，无法锻炼兵器！\n");
    if( (int)me->query("eff_jing") < 50 )
        return notify_fail("你现在的精力无法集中，不能锻炼兵器！\n");
    if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
        return notify_fail("你的潜能不够，无法锻炼兵器！\n");
    message_vision(HIR "$N手捏鞭稍，一股内力丝丝的传了进去。\n" NOR, me);
    me->add("max_neili",-10);
    me->set("neili", (int)me->query("max_neili"));
    me->add("qi",-150);
    me->add("eff_qi",-30);
    me->add("eff_jing",-30);
    me->add("learned_points", 2);
    w_zhi = (int)me->query("weapon/value");
    w_zhi++;
    me->set("weapon/value", w_zhi);
    w_or = (string)me->query("weapon/or");
    w_level = (int)me->query("weapon/lv");
    if( w_zhi >= ((w_level + 2) * (w_level + 2)))
    {
        w_level++;
        me->set("weapon/lv", w_level);
        message_vision(HIY "鞭身忽的一亮，一道金光隐入$N的"+w_name+"，不见了！\n" NOR,me);
        message_vision(HIG "$N的"+w_name+"的等级提高了！\n" NOR, me);
        weapon=this_object();
        if(weapon->query("equipped") ) 
            weapon->unequip();
        reload_object( weapon );
        me->set("weapon/value",0);
        return 1;
    }
    message_vision(RED "$N的"+w_name+"的质地改善了!\n" NOR, me);
    return 1;
}
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR "你大喝一声，一手擎鞭，一手猛的一扯。结果啪的一声爆响"
            +this_object()->name()+HIR+"断为两截!\n" NOR,me);
    me->delete("weapon");   
    me->save();
    destruct( this_object() );
    return 1;
}
int do_clean(string arg)
{   
    object me;
    me=this_player();
      if( !arg || arg!="metal")
        return notify_fail("你要干什么?\n");
    message_vision(HIR "你大喝一声，一掌擎剑，一掌猛力击下。只见"
            +this_object()->name()+HIR+"所镶嵌的金属随着一声巨响哐啷掉在地上!\n" NOR,me);

    me->delete("weapon/damage");
    me->delete("weapon/con");
    me->delete("weapon/dex");
    me->delete("weapon/int");
    me->delete("weapon/str");
     me->delete("weapon/qie");

    
    me->save();
    destruct( this_object() );
    return 1;
}
int do_qie(string arg)
{
    object obj;
    object ob;
    object me;
    me=this_player();

    if(!arg) return notify_fail("你要镶锲什么终极金属进去？\n");
 
    if ( me->query("weapon/qie") && me->query("weapon/qie")==me->query("weaponqie")+1 ) 
    return notify_fail("你已经镶锲了终极金属了，需要重新镶嵌请先去除原金属(clean metal)!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

    return do_xiang(me, obj);
}

int do_xiang(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
   
    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhongji_hc")) {
    write("这样东西并不能拿来镶锲!\n");
    return 1;
    }
  
    if ( ob->query("int") )
    me->add("weapon/int",ob->query("int"));
  
    if ( ob->query("str") )  
    me->add("weapon/str",ob->query("str"));    

    if ( ob->query("dex") ) 
    me->add("weapon/dex",ob->query("dex"));
  
    if ( ob->query("con") )
    me->add("weapon/con",ob->query("con"));
 
    if ( ob->query("damage") )
    me->add("weapon/damage",ob->query("damage"));

    me->add("weapon/qie",1);
    write(HIM"你把"+ob->name()+HIM"这样金属镶锲到自铸兵器中!\n"NOR);
    destruct(ob);
     destruct(obj);
    return 1;
    }
}

int do_rename(string arg)
{
    object me;
    me=this_player();
    if( !arg )
        return notify_fail("你改什么的名字?\n");

// 修改抛攻击的Bug  by zjb@TY 
    if( me->query("id") != query("zhuren") )
        return notify_fail("你不是这把自制武器的主人，不能使用该指令!!\n");

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
    me->set("weapon/name",arg+NOR);
    set("name",arg+NOR);
    write("ok!\n");
    this_object()->create();
    return 1;
}
mixed hit_ob(object me, object victim, int damage, int factor)
{
       object weapon;
       int w_lv,w_val,dam;
       int lvl,level,qi,jing,amount;

       //dam = this_object()->query("weapon_prop/damage");
       level=me->query("weapon/rate"); //材料的等级
       lvl = me->query("weapon/lv"); //武器的等级
       
       //write("damage= "+damage+"\n");write("level= "+level+"\n");write("lvl= "+lvl+"\n");

       if( query("equipped") && level)
       {        
        if( level==5 && random(5)==1) { //可以考虑增加一定随机性,以避免每次伤害都有特殊效果
//        	message_vision(HIY"附加特效三！\n"NOR,victim);
        	//吸血特性
        	//吸收的多少 取决于武器的等级高低 
        	qi = (int)(lvl*damage/100)+me->query("int");
        	jing = (int)(lvl*damage/150)+me->query("con");
        	//write("吸收的qi= "+qi+"\n");
         	message_vision(HIG"\n顿听"NOR+query("name")+ HIG "一声龙吟，悠悠不绝，直沁入到$N的心肺中去。\n"NOR,me, victim);
        	tell_object(victim, HIW"\n你发现"NOR+query("name")+ HIG "霎时间光芒四射，如蕴琉璃异彩，逼得你难以目视。\n"NOR);
         	
         	me->add("qi",qi);
         	me->add("eff_qi",qi);  
         	
         	me->add("jing",jing);
         	me->add("eff_jing",jing);
         	//write("吸收的jing= "+me->query("con")+"\n");
         	//防止气上限溢出
         	if(me->query("qi") > me->query("max_qi"))
         		me->set("qi",me->query("max_qi"));
         	if(me->query("eff_qi") > me->query("max_qi"))
         		me->set("eff_qi",me->query("max_qi"));
         	//防止精上限溢出
         	if(me->query("jing") > me->query("max_jing"))
         		me->set("jing",me->query("max_jing"));
         	if(me->query("eff_jing") > me->query("max_jing"))
         		me->set("eff_jing",me->query("max_jing"));
         	        
        }
        if( level>3 && random(4)==1 && !victim->query_temp("temp/weaponeff"))
        {//降低对方临时防御和攻击
         //if ( victim->query_skill("dodge") > 0 )
    			//{ 
    				message_vision(HIM"\n$n脸色发青，动作变得越来越生涩，似乎已然中毒！\n"NOR,me, victim);
         	   
    				tell_object(victim, HIB "\n你觉得对方的兵刃似乎带有奇毒，让你头晕目眩，浑身发麻！\n" NOR );
         		amount = lvl*10; //减少的程度与武器等级直接挂钩
         		victim->add_temp("apply/dodge", - amount);
         		victim->add_temp("apply/attack", - amount);   
         		victim->set_temp("temp/weaponeff",1);   
         		remove_call_out("remove_effect");
            call_out("remove_effect", (lvl+30), victim,amount);
    			//}
        }
        if( level>2) {//最低效果 增加附加伤害 无需随机限制 
        		//伤害程度取决于武器的等级高低 
        		dam = (int)(lvl*damage/200);
	        	message_vision(HIY"\n$N抖动手中的"NOR+query("name")+HIY"幻化成夜空流星，数道"NOR
        		HIM "紫芒" HIY"划破星空袭向$n" HIY "。\n"NOR,me,victim);
         		victim->receive_damage("qi",dam,me);
         		victim->receive_wound("qi",dam,me); 
        }
         //else
        //{
        // message_vision(HIC"$N"NOR+query("name")+HIC"未至，杀意已至，手中"NOR
        // +query("name")+HIC"竟激起一阵阵嗡鸣，\n"
        // +"片刻间漫天杀意已将$n席卷在内！\n"NOR,me,victim);
        // victim->receive_damage("qi",dam/2+random(dam/2),me);
        // victim->receive_wound("qi",dam/3+random(dam/3),me); 
        // victim->receive_damage("jing",dam/2+random(dam),me);
        // victim->receive_wound("jing",dam/2+random(dam),me); 
        //}
       }
       
       return 1; 

}
void destrory(object ob)
{
        destruct(ob);
}

void remove_effect(object target, int amount)
{
   if ( !target ) return;
   	if ( target->query_temp("temp/weaponeff") ) {
        target->add_temp("apply/attack", amount);
        target->add_temp("apply/dodge", amount);
        if (wizardp(target))
        tell_object(target, "你的攻击力与防御力恢复了，终于松了一口气。\n");
	}
}