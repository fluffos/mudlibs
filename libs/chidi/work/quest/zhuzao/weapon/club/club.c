#include <ansi.h>  
#include <weapon.h>
inherit CLUB;
mapping *weapon=({
([
  "name":           HIY"熟铜棍"NOR,
  "id":             "shutong gun",
  "long":           "这是一柄用精铜打造的熟铜棍。\n",
  "value":          8000,
  "material":       "copper",
  "damage":         50,
  "wield_neili":    100,
  "wield_maxneili": 300,
  "wield_str":      18,
]),
([
  "name":           HIB"夺命棍"NOR,
  "id":             "duoming gun",
  "long":           "这是一柄用精钢打造夺命棍，鬼里鬼气的。\n",
  "value":          12000,
  "material":       "iron",
  "damage":         100,
  "wield_neili":    200,
  "wield_maxneili": 400,
  "wield_str":      20,
]),
([
  "name":           HIW"亮银棍"NOR,
  "id":             "liangyin gun",
  "long":           "这是一柄用纯银打造连接的亮银棍，精光闪闪煞是好看。\n",
  "value":          30000,
  "material":       "silver",
  "damage":         150,
  "wield_neili":    400,
  "wield_maxneili": 600,
  "wield_str":      22,
]),
([
  "name":           HIY"紫金棍"NOR,
  "id":             "zijin gun",
  "long":       "这是一柄用野金打造连接的紫金棍，夺目灿烂的光芒尽显华丽。\n",
  "value":          50000,
  "material":       "gold",
  "damage":         200,
  "wield_neili":    400,
  "wield_maxneili": 800,
  "wield_str":      22,
]),
([
  "name":           BLK"玄铁棍"NOR,
  "id":             "xuantie gun",
  "long":           "这是一柄用玄铁打造连接的玄铁棍，握在手中异常沉重。\n",
  "value":          80000,
  "material":       "crystal",
  "damage":         300,
  "wield_neili":    400,
  "wield_maxneili": 800,
  "wield_str":      23,
]),
([
  "name":           HIG"寒玉棍"NOR,
  "id":             "hanyu gun",
  "long":       "这是一柄用千年寒铁打造的寒玉棍，虽取自寒铁，然晶莹如玉。\n",
  "value":          80000,
  "material":       "crystal",
  "damage":         400,
  "wield_neili":    400,
  "wield_maxneili": 1000,
  "wield_str":      24,
]),
});

mapping zhuzao_level(object me)
{

        int skill,level,corn;
        object mine;      
 
        if(mine=present("tong kuang", me)) corn=0;
        else
           if(mine=present("tie kuang", me)) corn=1;
        else
           if(mine=present("ying kuang", me)) corn=2;
        else
           if(mine=present("jing kuang", me)) corn=3;
        else
           if(mine=present("xuantie kuang", me)) corn=4;
        else  
           if(mine=present("han tie", me)) corn=5;
        else corn=0;

        skill=me->query("work/zhuzhang")/100;

        if(skill>corn) level=corn;
           else level=skill;

        return weapon[level];
} 

void create()
{
        mapping prop;
        object me;
        me=this_player();

        prop=zhuzao_level(me);

        set_name(prop["name"], ({ prop["id"], "gun" }));
        init_club(prop["damage"]);  
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", prop["long"]);
                set("value", prop["value"]);   
                set("material", prop["material"]);
                set("wield_neili", prop["wield_neili"]);
                set("wield_maxneili", prop["wield_maxneili"]);
                set("wield_str", prop["wield_str"]);
                set("wield_msg", "$N「唰」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n收了起来。\n");
        }
        setup();
}

