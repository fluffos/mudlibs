// slaughter.c --> to purge someone's pet
//
// by meteor

int main(object me, string arg)
{
        object pet;
        
        if( !me->query("created_pet") )
                return notify_fail("你还没有宠物呢！\n");

        if( !(pet = me->query_temp("created_pet")) || !present(pet, environment(me)) )
                return notify_fail("你的宠物现在不在这里。\n");

        if( !arg || (arg != pet->query("id")) )
                return notify_fail("你想杀掉哪个宠物？\n");
        
        write(pet->name() + "的双眼充满泪水，无辜地望着你，好可怜啊！\n你真的想杀掉它吗？(y/n) ");
        input_to("get_confirm", me, pet);
        return 1;
}

void get_confirm(string text, object me, object pet)
{
        if( text == "" ) {
                write("你真的想杀掉它吗？(y/n) ");
                input_to("get_confirm", me, pet);
                return;
        }
        if( capitalize(text) != "Y" ) return;
        write("\n为了保险起见，请输入你的密码：");
        input_to("get_password", 1, me, pet);
        return;
}

void get_password(string text, object me, object pet)
{
        object ob;
        string pass, name = pet->name();
        
        if( !(ob = me->query_temp("link_ob")) ) {
                write("你的人物出了问题，请与巫师联系。\n");
                return;
        }
        
        pass = ob->query("password");
        
        if( crypt(text, pass) != pass ) {
                write("密码错误！\n");
                return;
        }
        write("你手持屠刀，目露凶光，一步步地逼向" + name + "……\n\n");
        write(name + "惊惶失措，眼中露出恐惧的目光，到处躲藏，想要逃过你的毒手。\n\n");
        write("眼见" + name + "已无路可逃，突然一道耀眼的白芒闪过，你眼前已经失去了它的踪影。\n");
        seteuid(ROOT_UID);
        rm(pet->query_save_file() + ".o");
        seteuid(getuid());
        destruct(pet);
        me->delete("created_pet");
        me->save();
        return;
}
int help(object me)
{
        write(@HELP
指令格式: slaughter
 
这个指令可以让杀死你的宠物，可是不能再复活的，想清楚哦。
 
HELP
    );
    return 1;
}