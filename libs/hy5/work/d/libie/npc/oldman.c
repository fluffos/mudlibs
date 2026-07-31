#include <ansi.h>
inherit NPC;
int weapon();
void create()
{
        set_name("磨刀老人", ({ "old man","man" }) );
        set("long",
"一头乱发，衰老而略有些瘸脚的磨刀老人。他的一双手十分稳定，每当他看到
一把好刀剑的时候，总不由自主发出连连赞叹。据说他曾经是一个有名的铸造
兵器的大师，却不知为何抛弃了家业来到了这个小镇，据说是为了要寻找铸剑
的灵石。\n"); 
    set("attitude", "friendly"); 
    set("age",72); 
    set("str", 80);
    set("cor", 110);
    set("agi", 50); 
    set("combat_exp", 500000);
        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set("inquiry", ([
                "weapon" : (: weapon :),
                "兵器" : (: weapon :),
                "bingqi" : (: weapon :),
        ]));
    set("chat_chance", 1);
    set("chat_msg", ({
"磨刀老人仰面向天怔怔道：有生之日但能得见那神兵『离别钩』便也算不
枉此生了。\n",
"磨刀老人长叹一声：象樊夫人那样的知己，天下有几个啊。。。\n",
//              (: random_move :)
    }) );
        set("arrive_msg", "一瘸一拐的走了过来。");
        set("leave_msg", "一瘸一拐的离去。");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
void init(){
        ::init();
    add_action("do_give","give");
   add_action("do_qian", "qian");
} 
int weapon(){
        object me;
        me = this_player();
        message_vision("$N长叹一声：“兵器是有灵性的，有灵性的物品又可以增加武器\n", this_object());
        message_vision("的灵性，但着灵物难求呀。”\n", this_object()); 
        return 1;
} 
int do_qian(string arg){
        object me, weapon, stone;
        string obj, item, prop;
        me = this_player();
        if(!arg) {
                return notify_fail("你要嵌什么东西。\n");
        }
        if(!sscanf(arg, "%s with %s", obj, item)) {
                return notify_fail("你要ｑｉａｎ什么东西ｗｉｔｈ什么东西？\n");
        }
        weapon = present(obj, me);
        stone = present(item, me);
        if(!objectp(weapon) || !objectp(stone)){
                return notify_fail("你没有这些东西。\n");
        }
        if(weapon->query("owner") != me->query("id") || !weapon->query("owner")) {
                return notify_fail("你不可以镶嵌这个东西。\n");
        }
        if(!stone->query("imbue")){
                return notify_fail("这个东西不可以用来镶嵌。\n");
        }
        if (stone->name()==HIR"蛰龙赤丹"NOR && !me->query("m_success/蛰龙赤丹")) {
                message_vision(YEL"$N叹了口气：“可惜，你配不上它。”\n"NOR,this_object());
                return 1;
        }
        message_vision("$N拿起" + stone->name() + "和"+weapon->name()+"。\n", this_object());
        weapon->unequip();
        if(weapon->query("weapon_prop")) {
                prop="weapon_prop/";
        }
        if(stone->query("id") == "topaz") {
           if(me->query("imbue/ystone")) {
                        return notify_fail("你已经不可一再镶嵌这个东西了。\n");
                }
                message_vision(HIY"\n凝露黄石发出明亮的黄色光芒.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
                                this_object());
                weapon->add(prop+"flexibility", 5);
                me->set("imbue/ystone", 1);
        } else if(stone->query("id") == "diamond") {
                if(me->query("imbue/bstone")) {
                        return notify_fail("你已经不可一再镶嵌这个东西了。\n");
                }
                message_vision(HIC"碧海蓝心发出莹莹的蓝色光芒.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
                                this_object());
                weapon->add(prop+"spirituality", 5);
                me->set("imbue/bstone", 1);
        } else if(stone->query("id") == "ruby"){
                if(me->query("imbue/rstone")) {
                        return notify_fail("你已经不可一再镶嵌这个东西了。\n");
                }
                message_vision(HIR"蛰龙赤丹发出炎炎的红光.... 一缕缕流火飞入"NOR + weapon->name()+"。\n",
                                this_object());
                weapon->add(prop+"damage", 15);
                weapon->add("base_damage",15);
                me->set("imbue/rstone", 1);
        } else if(stone->query("id") == "amethist") {
                if(me->query("imbue/pstone")) {
                        return notify_fail("你已经不可一再镶嵌这个东西了。\n");
                }
                message_vision(HIM"幽冥紫晶发出幽幽的紫色光芒.... 一缕缕流霞飞入"NOR + weapon->name()+"。\n",
                                this_object());
                weapon->add(prop+"personality", 5);
                me->set("imbue/pstone", 1);
        } else if(stone->query("id") == "jade") {
                if(me->query("imbue/gstone")) {
                        return notify_fail("你已经不可一再镶嵌这个东西了。\n");
                }
                if(!me->query("宿命B/桃源_核桃"))
                        return notify_fail("这枚天灵翡翠与你的武器灵气相冲，无法镶嵌在你的武器上。\n");
                message_vision(HIG"天灵翡翠发出的澄碧的绿光.... 一缕缕流光飞入"NOR + weapon->name()+"。\n",
                                this_object());
           weapon->add(prop+"intelligence", 2);
                me->set("imbue/gstone", 1);
        }
        destruct(stone);
        weapon->save();
        return 1;
} 
int accept_object(object me, object obj){
        object weapon;
        mixed *inv;
        int i, j;
        inv = all_inventory(me);
        j = 0;
        if(obj->query("imbue")) {
                message_vision(YEL"\n$N仔细看了看$n手中的"NOR+obj->name()+YEL"点头道：“好！好！此等灵物，\n可遇而不可求。”\n"NOR,
                                this_object(), me);
                if (obj->name()==HIR"蛰龙赤丹"NOR && !me->query("m_success/蛰龙赤丹")) {
                        message_vision(YEL"$N叹了口气：“可惜，你配不上它。”\n"NOR,this_object());
                        return 0;
                }
                for(i=0; i<sizeof(inv); i++){
                        if(inv[i]->query("owner") == me->query("id") && inv[i]->query("weapon_prop")) {
                                weapon = inv[i];
                                j++;
                        }
                }
                if(!weapon) {
                        message_vision(YEL"\n$N又抬头看了看$n道：“灵石还需灵器配，这位" + RANK_D->query_respect(me) + "还是去配把有\n灵气的兵刃吧。”\n"NOR,
                                        this_object(), me);
                        return 0;
                }
                message_vision(YEL"$N又抬头看了看$n道：“既是有缘，你可愿我帮你把它铸嵌在武器上？”\n"NOR,
                                this_object(), me);
                message_vision("（ｑｉａｎ）\n", this_object());
        }
        return notify_fail("");
} 
int do_give(string arg) {
        string objectname, acceptor;
        object ob,who; 
   if( sscanf(arg, "%s to %s", objectname, acceptor)==2 )
        { 
        if(acceptor!="磨刀老人"&&acceptor!="old man"&&acceptor!="man")
                return 0;
        if(objectname!=MAG"离别钩"NOR&&objectname!="leave hook")
                {command("shake");
                return 0;
                }
        who=this_player();
        ob=present(objectname,who);
        if (ob->query("value")==0)      {
                        command("shake");
                        return 0;
                        }
        if(!objectp(ob)) return 0;
    message_vision(GRN "$N恭恭敬敬地将离别钩递给磨刀老人。\n"NOR,who); 
        if(!who->query("libie/磨刀老人"))
        {
                who->add("score",200);
                who->add("potential",0);
                who->set("libie/磨刀老人",1);
        }
        if(!who->query("libie/离别钩二"))
        {
                ob->unequip();
                ob->set("weapon_prop",0);
                ob->set("name",MAG"断掉的离别钩"NOR);
                ob->set("value",0);
                ob->set("long","一把奇形怪状的兵刃,但是已经断掉了。\n");
        message_vision(YEL "磨刀老人小心翼翼地轻抚着离别钩，痴痴地看着，过了半晌，缓缓道：
此物大凶，其必祸主，还是不要留在人间的好。
\n说罢，磨刀老人弹指一击，离别钩竟“铛”的一声断为两截。\n"NOR,who);
                return 1;
        }
        else
        {
                if (who->query_temp("libie/离别钩_磨刀老人"))
                        {
            message_vision(YEL "磨刀老人并不理睬$N，继续埋头磨刀。\n"NOR,who);
                        return 1;
                   }
                who->set_temp("libie/离别钩_磨刀老人",1);
                message_vision(HIB"磨刀老人望着$N，衰老的脸上会露出种虔诚迷惘的神情，仰面向天喃喃道：
天意如刀，难道是天意？用半本残谱换取的纸刀传人终是死在了残谱练就
的离别钩下？
\n磨刀老人叹了口气，将离别钩轻轻递给$N，埋头继续“哧哧”地磨起刀来。\n"NOR,who);
        return 1; 
        } 
        }
}   
