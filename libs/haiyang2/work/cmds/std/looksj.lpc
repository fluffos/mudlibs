// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int look_room(object me, object env, int night);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object obj);
string tough_level(int power, int hide_level);
string gettof(object obj);
string getdam(object obj);
string getatt(object obj);
string getdef(object obj);
string getdog(object obj);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;
if (me)
return notify_fail("这个指令只能由系统执行。\n");
        if( !arg ) result = look_room(me, environment(me), NATURE_D->is_night());
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env, int night)
{
        int i;
        object *inv;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("你的四周灰蒙蒙地一片，什么也没有。\n");
                return 1;
        }
        
        str = env->query("long");
        // night ^_^ , added by snowman@SJ
        
        if(env->query("no_light")
           && !env->query_night_light()
           && random(me->query_con()) < 35){
                if(env->query("night_long")) str = env->query("night_long");
                else str = "这里一片漆黑，你虽然睁大了眼睛仔细观看，可还是看不清楚周围的\n"+ 
                           "事物。一切都被笼罩在黑暗之中，伸手不见五指... \n";
                }
                
        else if(env->query("outdoors") && night 
           && !env->query_night_light()
           && random(me->query_con()) < 35){
                if(env->query("night_long")) str = env->query("night_long");
                else str = "夜晚了，你虽然睁大了眼睛仔细观看，可还是看不清楚周围的事物。\n"+
                           "一切都被夜色所笼罩，连脚下的道路都模糊不清了... \n";
                }      
                     
        str = sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                str,
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = sort_array(keys(exits), 1);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                        
                // night ^_^ , added by snowman@SJ
                else if((env->query("outdoors") || env->query("no_light")) 
                        && night && !env->query_night_light()
                        && random(me->query_con()) < 35){
                        i = random(sizeof(dirs));
                        if( random(me->query_con()) < 10) i = 0;
                        else if( random(me->query_con()) < 20) i = 1;
                        if( i <= 0 )
                                str += "    这里看不见任何明显的出路。\n";
                        else if( i == 1 )
                                str += "    这里看得见的唯一出口是 " + BOLD + dirs[i-1] + NOR + "。\n";
                        else str += sprintf("    这里看得清的出口是 " + BOLD + "%s" + NOR + "。\n", implode(dirs[1..i], "、"));
                        }
                // hehehe.....
                
                else if( sizeof(dirs)==1 )
                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                        
                else    str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
                        
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                
                // night.
                if((env->query("outdoors") || env->query("no_light")) 
                   && night 
                   && !env->query_night_light() 
                   && random(me->query_con()) < 35 
                   && !inv[i]->is_character()) continue;   
                // hehehehehehe.....   
                str += "  " + inv[i]->short() + "\n";
        }

        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
        string prep;

        write(obj->long());
        inv = all_inventory(obj);
        if( !obj->is_closed() && sizeof(inv)) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "上";
                                break;
                        case "under":
                                prep = "下";
                                break;
                        case "behind":
                                prep = "后";
                                break;
                        case "inside":
                                prep = "里";
                                break;
                        default:
                                prep = "里";
                                break;
                        }
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("%s面有：\n  %s\n", prep,
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

string getper(object obj)
{
        int per, age;

        string str;

        per = obj->query_per();
        age = obj->query("age");
        
        if ((string) obj->query("gender") == "女性"){
            if (per >= 40) str = "超凡脱俗，娇艳绝伦，貌如西子胜三分！\n";
            else if (per >= 37){
                      if(obj->max_food_capacity() > 320)
                           str = "驻唇不涂一点红，回眸一笑百媚生！\n";
                      else str = "清丽绝俗，冰清玉洁，有如画中天仙！\n";
                      }
            else if (per >= 33){
                      if(obj->max_food_capacity() > 320)
                           str = "容貌丰美，气质高雅，堪称人间仙子！\n";
                      else str = "容貌娇美，姣花照水，堪称人间仙子！\n";
                      }
            else if (per >= 30){
                      if(obj->max_food_capacity() > 320)
                           str = "脸若银盆，眼如水杏，相貌绝美！\n";
                      else str = "美奂绝伦，一笑倾城，再笑倾国！\n";
                      }
            else if (per >= 27) str = "羞花闭月，宛若天仙！\n";
            else if (per >= 24) str = "花颜月貌，柔媚娇俏！\n";
            else if (per >= 20) str = "楚楚动人，有几分姿色！\n";
            else if (per >= 17) str = "相貌平庸，很是一般。\n";
            else if (per >= 14) str = "五官挪位，貌似无盐。\n";
            else str = "一塌糊涂，不是人样！\n";
        } else {
            if (per >= 40) str = "英姿勃发，一表人才，称为古往今来第一人！\n";
            else if (per >= 37) str = "玉树临风，风流倜傥，堪称绝世美男！\n";
            else if (per >= 33) str = "清秀俊雅，相貌非凡，真是人中龙凤！\n";
            else if (per >= 30){
                      if(obj->max_food_capacity() < 160)
                             str = "貌似美女，脸若冠玉，弱不禁风！\n";
                      else  str = "貌似潘安，容比宋玉，仪表堂堂！\n";
                      }
            else if (per >= 27) str = "相貌出众，堪称美男！\n";
            else if (per >= 24) str = "英俊潇洒，气质非凡。\n";
            else if (per >= 20) str = "五官端正，相貌平平。\n";
            else if (per >= 17) str = "五官不正，满脸麻子。\n";
            else if (per >= 14) str = "牛眼驴唇，面目狰狞。\n";
            else str = "有如雷公下凡，八戒返魂！\n";
        }
        return "长得" + str;
}

string gettof(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/100, hide_level);
        return tough_level(attack_points/100, 0);
}

string getatt(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);         
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}

string getdef(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE); 
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}
string getdog(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE); 
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}
int look_living(object me, object obj)
{
        int age;
        string str, pro;
        mixed *inv;
        mapping my_fam, fam;

        if( me!=obj && obj->visible(me))
                message("vision", me->name() + "正盯着你看，不知道打些什么主意。\n", obj);

        inv = explode(obj->long(), "\n");
        str = implode(inv[0..20], "\n")+"\n";
        if (sizeof(inv) > 21) str += "此处删去"+chinese_number(sizeof(inv)-21)+"行。\n";

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if (!obj->query_temp("apply/long")) {
                if( (string)obj->query("race")=="人类"
                        && intp(age = obj->query("age")) ) {
                        if (obj->query_skill("beauty") > 30) age -= (obj->query_skill("beauty")-30)/5;
                        if (age < 10)
                                str += sprintf("%s看起来不到十岁，", pro);
                        else
                                str += sprintf("%s看起来约%s多岁，", pro, chinese_number(age / 10 * 10));
                        if (wizardp(me) || obj->query("age") >= 16) str +=getper(obj);
/*
                                                //暂时取消了巫师级别限制。玩家反映太大。
                        if (wizardp(me)) {
*/
                                str +=sprintf("%s的武艺看上去", pro);
                                str +=gettof(obj);
                                str +="，";
                                str +=sprintf("出手似乎");
                                str +=getdam(obj);
                                str += sprintf("。\n");
                        /*}*/
                }
                // If we both has family, check if we have any relations.
                if( obj!=me
                &&      mapp(fam = obj->query("family"))
                &&      mapp(my_fam = me->query("family")) 
                &&      fam["family_name"] == my_fam["family_name"] ) {
                
                        if( fam["generation"]==my_fam["generation"] ) {
                                if( (string)obj->query("gender") == "女性")
                                        str += sprintf( pro + "是你的%s%s。\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                                my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                                else
                                        str += sprintf( pro + "是你的%s%s。\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                                my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        } else if( fam["generation"] < my_fam["generation"] ) {
                                if( my_fam["master_id"] == obj->query("id") )
                                        str += pro + "是你的师父。\n";
                                else if( my_fam["generation"] - fam["generation"] > 1 )
                                        str += pro + "是你的同门长辈。\n";
                                else if( fam["enter_time"] < my_fam["enter_time"] )
                                        str += pro + "是你的师伯。\n";
                                else
                                        str += pro + "是你的师叔。\n";
                        } else {
                                if( fam["generation"] - my_fam["generation"] > 1 )
                                        str += pro + "是你的同门晚辈。\n";
                                else if( fam["master_id"] == me->query("id") )
                                        str += pro + "是你的弟子。\n";
                                else
                                        str += pro + "是你的师侄。\n";
                        }
                }
        
                if (userp(obj) && obj->query("id") == me->query("marry/id"))
                        str += pro + "是你的"
                                + (obj->query("gender") == "女性"?"妻子":"丈夫")
                                + "。\n";
                if (obj->query_temp("marry") == me)
                        str += pro + "是你的未婚"
                        + (obj->query("gender") == "女性"?"妻":"夫") + "。\n";
        }

        if( obj->query("max_qi") )
                        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上穿戴着：\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="人类")
                str += pro + "身上没有任何穿戴。\n";
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), 1, 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( "%s身上装备着：\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="人类")
                str += pro + "身上没有任何装备。\n";

        message("vision", str, me);

        if( obj!=me && obj->visible(me)
        &&      userp(me)
        &&      living(obj)
        &&      (int)obj->query("shen") < -(int)me->query_int() * 100 ) {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag, int equip)
{
        string str;

        reset_eval_cost();
        if( obj->query("equipped")) {
                if (!flag || (!equip && obj->query("armor_type"))
                || (equip && obj->query("weapon_prop")))
                    str = HIC "  □" NOR + obj->short();
                else return 0;
        }
    else if( obj->query("embedded") && flag && !equip)  str = HIR "  ☆" NOR + obj->short();
        else if( !flag )
                str = "    " + obj->short();
        else return 0;
        return str;
}


int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = load_object(exits[arg])) )
                        look_room(me, env, NATURE_D->is_night());
                else return notify_fail("这个方向无法看清，请报告巫师。\n");
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

string *tough_level_desc = ({
BLU"不堪一击"NOR,BLU"毫不足虑"NOR,BLU"不知所以"NOR,BLU"新学乍练"NOR,BLU"勉勉强强"NOR,
BLU"初窥门径"NOR,BLU"初出茅庐"NOR,BLU"略知一二"NOR,BLU"普普通通"NOR,BLU"平平淡淡"NOR,

HIB"平淡无奇"NOR,HIB"粗通皮毛"NOR,HIB"半生不熟"NOR,HIB"马马虎虎"NOR,HIB"略有小成"NOR,
HIB"已有小成"NOR,HIB"渐入佳境"NOR,HIB"登堂入室"NOR,HIB"挥洒自如"NOR,HIB"融会贯通"NOR, 

CYN"心领神会"NOR,CYN"炉火纯青"NOR,CYN"了然於胸"NOR,CYN"略有大成"NOR,CYN"已有大成"NOR,
CYN"豁然贯通"NOR,CYN"出类拔萃"NOR,CYN"无可匹敌"NOR,CYN"技冠群雄"NOR,CYN"神乎其技"NOR,

HIC"出神入化"NOR,HIC"非同凡响"NOR,HIC"傲视群雄"NOR,HIC"登峰造极"NOR,HIC"无与伦比"NOR,
HIC"所向披靡"NOR,HIC"一代宗师"NOR,HIC"精深奥妙"NOR,HIC"神功盖世"NOR,HIC"举世无双"NOR,

HIR"惊世骇俗"NOR,HIR"撼天动地"NOR,HIR"震古铄今"NOR,HIR"超凡入圣"NOR,HIR"威镇寰宇"NOR,
HIR"空前绝后"NOR,HIR"天人合一"NOR,HIR"深藏不露"NOR,HIR"横扫江湖"NOR,HIR"深不可测"NOR,

HIY"威不可挡"NOR,HIY"技惊四座"NOR,HIR"强绝天下"NOR,HIY"威镇武林"NOR,HIR"前无古人"NOR,
HIY"返璞归真"NOR,HIY"独步天下"NOR,HIY"旷古绝伦"NOR,HIY"天下无敌"NOR,HIY"天下第一"NOR,
});
/*
BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,HIB "初窥门径" NOR,
HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,HIB "平淡无奇" NOR,HIB "粗通皮毛" NOR,
HIB "半生不熟" NOR,HIB "马马虎虎" NOR,HIB "略有小成" NOR,HIB "已有小成" NOR,HIB "驾轻就熟" NOR,
CYN "心领神会" NOR,CYN "了然於胸" NOR,CYN "略有大成" NOR,CYN "已有大成" NOR,CYN "豁然贯通" NOR,
CYN "出类拔萃" NOR,CYN "无可匹敌" NOR,CYN "技冠群雄" NOR,CYN "神乎其技" NOR,CYN "出神入化" NOR,
CYN "傲视群雄" NOR,HIC "登峰造极" NOR,HIC "所向披靡" NOR,HIC "一代宗师" NOR,HIC "神功盖世" NOR,
HIC "举世无双" NOR,HIC "惊世骇俗" NOR,HIC "震古铄今" NOR,HIC "深藏不露" NOR,HIR "深不可测" NOR
*/

string tough_level(int power, int hide_level)
{
/*        int lvl, rawlvl;

        if(power<0) power=0;
        rawlvl = (int) pow( (float) 1.0 * power, 0.3);
        lvl = to_int(rawlvl);
        
        if(hide_level)
            lvl = hide_level;
        if( lvl >= sizeof(tough_level_desc) )
            lvl = sizeof(tough_level_desc)-1;
        
        return tough_level_desc[lvl];
*/
	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];

}

string getdam(object obj)
{

        int level;
        string *heavy_level_desc= ({"极轻","很轻","不重","不轻","很重","极重",});
        
        level = obj->query("jiali");
        if(obj->query_temp("apply/damage") > 0)
            level += obj->query_temp("apply/damage")/3;  // weapon 加力效果等于 unarmed / 3
            
        level /= 30;
        if( level >= sizeof(heavy_level_desc) )
            level = sizeof(heavy_level_desc)-1;
        return heavy_level_desc[((int)level)];
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
        return 1;
}

