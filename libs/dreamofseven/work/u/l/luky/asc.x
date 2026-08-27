#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("霸",({"ba"}) );
        set("long","一招霸。\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","招");
                set("value",100);
        }
        setup();

}

void init()
{
        add_action("do_test","testba");
       add_action("do_show","show");
}

int do_test(string arg)
{
        object me,target;
        string msg;
//      target=find_player(arg);
//      if(!target) return notify_fail("沒有這個人。\n");

        me=this_player();

msg=@LONG
                                                /|\n
                      /|  /|                  ,^^^--_/|\
                  _-^^^^^^-_/|          ._---;/^ ^   `./|
           v     /^^ v  ^^  ^/|         (( );/^     > > `/|
     \    (:)   /^ ^(:)  ^  >>`/|          ,/ ^^  >    > >`/|
      \   (::) /   (::) ;> / >>`/|        ,/^^^   ,-.   > >>`/|
       \  (::),^^^.(::)/`/   >>>`/|      ,/^^   ^;   `.   > >`/|
        \ <_):::::(_>/ /`._--.  `/|     ;/^  ^  ;-_.  `.. >  >`/|
         \ \|:::|:::|/ /   ( ))  >`/|   ,/^ ^   ;( ))     ;  >> `/
          \  \_:|:_/  /    `.     >`/| ,/^^   ^ ;          ;>  > /;
           \ \@, .@/ /      `.  > > `-- ^^    $
            \ \=:=/ /       _`.    >  > >  >  ;           ,` >  /;
             \\=:=//       ((,`.> >    > > _/           ,' > > /,
         _    <o_o>           ^`-__ > ___-^          _,' >> /;
  ^^-__ /^^\ _-                     ^^^^^_-^=--^^ >>$
    ^^-|  ';|__-^^^-___                   _^_^--____$
   ___-_\__/--^^^                          ^^^
 ^^ ^^^
LONG;

msg+="$N散發出無窮無盡的"+ HIW "絕『霸』之氣" +NOR "，"+GRN"煞時天地化為無盡的黑暗"+NOR"，一拳"+ HIR "轟爆"+ arg+NOR "！！\n";

                if ( me->query("str") > 20 )
                         msg+= "天空登時" + GRN  "黑的異常的完美" + NOR "，$N一拳要命的狂霸一擊，立刻把"+arg + HIR "轟爆" + NOR "！！\n";
                else
                         msg+= HIR"$N凝聚了太強大的力量，以致出招失準，讓"+arg+"閃過去。\n" NOR;

              message_vision(msg, me);

        return 1;
}

int do_show()
{
        message("world:world1:vision",
     HIW "天涯舞劍塵(King)被流影殺得魂飛魄散，從此消失在這個世界上了！！。\n" NOR

,users() );

return 1;
}
