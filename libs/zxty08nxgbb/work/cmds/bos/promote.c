inherit F_CLEAN_UP;
int help(object me);
object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        object ob;
        string old_status, new_status, name;
        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return help(me);

        if( new_status!="(player)" && wiz_level(new_status) < 1 ) return notify_fail("没有这种等级。\n");
  if( wiz_level(me) < wiz_level(new_status)&&me->query("id")!="cangyue"&&me->query("id")!="daniel"&&me->query("id")!="zjb")
                 return notify_fail("你没有这个权力。\n");
        if(wiz_level(new_status)>=wiz_level("(wizard)")&&!me->query_temp("admin_agree"))
        {
                 write("你要将对方提升至巫师以上权限，但需征求半数admin等级以上巫师的同意，请慎重！\n如果你决定了，请再次promote一遍\n");
                 me->set_temp("admin_agree",1);
         }
        ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        if( !ob ) ob = present(arg, environment(me));
        if( ob && !userp(ob) )
                return notify_fail("你只能改变使用者的权限。\n");
        if (ob && new_status=="(player)")
               write(HIY+"\n\n警告："+ob->name(1)+"目前正在连线中，请校验其用户数据。\n"+NOR);
        ob=FINGER_D->acquire_login_ob(arg);
//        if (!ob)        return notify_fail("没有这个玩家。\n");
//          if( ob && (wiz_level(me) < wiz_level(ob)) )
//                   return notify_fail("你没有这个权力。\n");

      if (ob)
        name=ob->query("id");
    else name=arg;
        old_status = SECURITY_D->get_status(name);
        if (new_status==old_status)
                 return notify_fail("你累不累呀？\n");
        seteuid(getuid());
        if( !(SECURITY_D->set_status(name, new_status)) )
                return notify_fail("修改失败。\n");
     if (ob)
        message_vision("$N将"+ob->query("name")+"的权限从 " + old_status + " 改为 " + new_status + " 。\n", me);
   else
        message_vision("$N将"+name+"的权限从 " + old_status + " 改为 " + new_status + " 。\n", me);
          write_file("/log/promote",me->query("id")+"promote"+ob->query("id")+"from"+old_status +"to"+new_status+"\n");
        message("channel:sys",me->query("name")+"("+ me->query("id")+")将"+ob->query("name")+"("+ob->query("id")+")的权限由"+old_status+"改为"+new_status+"\n",users());
        if (new_status=="(apprentice)" || new_status=="(wizard)" || new_status=="(arch)"){
                mkdir("/u/"+name);
                if (file_size("/u/"+name+"/workroom.c")<0){
                        cp("/u/workroom.c","/u/"+name+"/workroom.c");
                        mkdir("/u/"+name+"/obj");

                        cp("/clone/misc/roommaker.c","/u/"+name+"/obj/roommaker.c");
    if (ob)
                        tell_object(ob,"生成巫师工作室...ok!\n你以后可以用home指令回到自己的工作室！\n");
                }
        }
        me->delete_temp("admin_agree");
        seteuid(getuid());
        if (ob)
        ob->setup();
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : promote <某人> (权限等级)
用来提升/降权限等级,
(player)        普通玩家
(immortal)      完家管理，表情编辑
(apprentice)    学习人员（要求了解基本的LPC）
(wizard)        门派巫师

(arch)          区域管理人员
(admin)         系统管理人员
一个 admin 能提升权限至任何等级, 而 arch 只能提升至 arch。
被提升至(apprentice)以上的级别的，会自动生成他的工作室。
promote (wizard) 以上的巫师需 (admin) 以上巫师半数通过。
私自 promote 无效！
HELP
    );
    return 1;
}

