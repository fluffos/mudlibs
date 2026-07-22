// marry_ring.c - 结婚戒指

#include <ansi.h>
#include <mudlib.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

varargs mixed do_emote(object me, string verb, string arg,object couple_ob);

object find_player(string target)
{
      int i;
        object *objs;
        objs=users();
        for (i=0;i<sizeof(objs);i++)
                if (objs[i]->query("id")==target && interactive(objs[i]) && environment(objs[i]))
                        return objs[i];
        return 0;
}



void init()
{
        add_action("do_coupletalk_0", "ct");
        add_action("do_coupletalk_1", "ct*");
        add_action("do_coupletalk_2", "ct#");
}

int do_coupletalk_0(string arg) { return do_coupletalk( arg, 0 ); }

int do_coupletalk_1(string arg) { return do_coupletalk( arg, 1 ); }

int do_coupletalk_2(string arg) { return do_coupletalk( arg, 2 ); }

void dest() { destruct(this_object()); }

void owner_is_killed() { call_out("dest",2); }

int do_coupletalk(string arg, int emote)
{
        object me, couple_ob;

        me = this_player();

        if ( !stringp(me->query("marry")) )
                return notify_fail("你没有伴侣。\n");

        couple_ob = find_player( me->query("marry") );
        if( !couple_ob )
                return  notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");

        if ((string)couple_ob->query("gender") == "无性") 
                return  notify_fail("你原来的伴侣已经做了太监，你还是把他忘了吧。\n");

        if ((string)couple_ob->query("class") == "bonze") 
                return  notify_fail("你原来的伴侣已经做了和尚，你还是把他忘了吧。\n");

        if ( !arg || arg=="" || arg==" " ) {
                write( MAG "你又深情地想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN + (string)me->name() + "又在深情地想念自己的"+me->query("couple/couple_gender")
                        + (string)couple_ob->name(1) + "。\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "%s又在深情地想念你了。\n"NOR, couple_ob->query("couple/couple_gender")+me->name(1)  ) ); 

                return 1;
        }
        
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // Support of channel emote
        if( emote ) {
                string vb, emote_arg;

                if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
                        vb = arg;
                        emote_arg = "";
                }

                // If out support of channel emote and still send this message
                if (emote == 2){
                        tell_object( me, MAG + "你" + arg + NOR + "\n");
                        tell_object( couple_ob, MAG + couple_ob->query("couple/couple_gender")+me->name(1)+ arg + NOR +"\n");
                }else{
                        if (arg=="kiss") {
                            write( MAG "你情不自禁地拥住"+me->query("couple/couple_gender")+couple_ob->name(1) +"，深深的一吻，许久...许久...。\n" NOR);
                            tell_object(couple_ob, sprintf(HIM "%s深情地拥住你，深深的一吻，许久...许久...。\n"NOR, couple_ob->query("couple/couple_gender")+me->name(1)  ) ); 
                        }else return do_emote(me,vb,emote_arg,couple_ob);
                }
                return 1;

        }
        else {
                write(sprintf(HIM "你对%s说：%s\n" NOR, me->query("couple/couple_gender")+couple_ob->name(1), arg ));
                tell_object(couple_ob, sprintf(HIM "%s对你说：%s\n" NOR, couple_ob->query("couple/couple_gender")+me->name(1), arg ));
        }

        return 1;
}

void create()
{
        set_name( HIY "结婚戒指" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set( "no_get", 1);
        set( "no_put", 1 );
        set( "no_drop", "你的结婚戒指不能丢弃,只能去红娘庄解除婚约。\n");
        set( "long", MAG+"这是一枚结婚戒指。你可以使用以下命令：\n"+"\tcoupletalk ( ct )       和伴侣对话。\n\n"+"\t支持命令：ct, ct#, ct*\n"+NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "gold");
                set("armor_type", "finger");
                set("armor_prop/armor", 10);
                set("armor_prop/defense", 10);
                set("wear_msg", "$N将$n拿出来小心地戴在手指上。\n");
                set("remove_msg", "$N将$n小心地从手指上摘下来放好。\n");
        }
        call_out("load_ring",1);
}

void load_ring()
{
                object me, couple_ob;
                        me = environment(this_object());
                        if (!me || !userp(me)){
                                call_out("dest",1);
                                return;
                        }
                        if( me->query("marry") ) {
                             couple_ob = new("/clone/misc/player");
                          if (!couple_ob->new_object(me->query("marry") ) ||
                             couple_ob->query("marry")!=me->query("id") ){
                               me->delete("marry");
                               me->delete("couple");
                               tell_object(me,HIY "你的伴侣已经重新投胎了,如果你们有缘...\n"NOR);
                               destruct(couple_ob); 
                               destruct(this_object()); 
                               return;
                            }
                           destruct(couple_ob); 
                         couple_ob = find_player( me->query("marry") );
                         if (couple_ob && environment(couple_ob) ){
                         tell_object(me, HIM "\n你的" + me->query("couple/couple_gender")+couple_ob->name(1) + "也在这里，快去找啦....\n" NOR);
                         tell_object(couple_ob , sprintf( HIM "\n你的%s来啦，快去接呀....\n" NOR, couple_ob->query("couple/couple_gender")+me->name(1) ));
                        }
                         set("name", HIC+me->query("id")+HIY "和" HIC + me->query("marry") + HIY "的结婚戒指" NOR );
                        this_object()->wear();
                        }
}


varargs mixed do_emote(object me, string verb, string arg,object couple_ob)
{
    string str, my_gender, target_gender, msg_postfix;
    string my_name,target_name;
    object target;
    mapping emote;

    if( !environment(me) ) return 0;

    emote=EMOTE_D->query_emote(verb);
    if ( !mapp(emote) || !sizeof(emote) ) return 0;

    my_name=couple_ob->query("couple/couple_gender")+me->name(1);
    if ( stringp(arg) && arg != "" ) {
        target = find_player(arg);

        if(!objectp(target)) {
            target = present(arg, environment(me));
            if( !objectp(target) ) return 0;
        }
        if (target!=couple_ob)        
        if( !target->is_character() || !me->visible(target) )
            return notify_fail("你要对谁做这个动作？\n"); 

        target_gender = target->query("gender");
        target_name=target->name(1);
        if( target==me ) {
            msg_postfix = "_self";
            target = 0;
        }else{
            msg_postfix = "_target";
            if (target==couple_ob)
                target_name=me->query("couple/couple_gender")+target->name(1);
       }
    } else msg_postfix = "";

    my_gender = me->query("gender");

    if( stringp(str = emote["myself" + msg_postfix]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        if( objectp(target) ) {
                    str = replace_string(str, "$C", RANK_D->query_self_close(target));
                    str = replace_string(str, "$c", RANK_D->query_close(target));
                    str = replace_string(str, "$R", RANK_D->query_respect(target));
                    str = replace_string(str, "$r", RANK_D->query_rude(target));
            str = replace_string(str, "$n", target_name);
            str = replace_string(str, "$p", gender_pronoun(target_gender));
        }
        tell_object(me, HIM + str + NOR);
    }
    if( objectp(target) && target==couple_ob && stringp(str = emote["target"]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_pronoun(my_gender));
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$C", RANK_D->query_self_close(target));
        str = replace_string(str, "$c", RANK_D->query_close(target));
        str = replace_string(str, "$R", RANK_D->query_respect(target));
        str = replace_string(str, "$r", RANK_D->query_rude(target));
        str = replace_string(str, "$n", target_name);
        str = replace_string(str, "$p", gender_self(target_gender));
        tell_object(couple_ob, HIM + str + NOR);
        return 1;
    }
    if( stringp(str = emote["others"+msg_postfix]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_pronoun(my_gender));
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        if( objectp(target) ) {
            str = replace_string(str, "$C", RANK_D->query_self_close(target));
            str = replace_string(str, "$c", RANK_D->query_close(target));
            str = replace_string(str, "$R", RANK_D->query_respect(target));
            str = replace_string(str, "$r", RANK_D->query_rude(target));
            str = replace_string(str, "$n", target_name);
            str = replace_string(str, "$p", gender_pronoun(target_gender));
        }
        tell_object(couple_ob, HIM + str + NOR);
    }
    return 1;
}
