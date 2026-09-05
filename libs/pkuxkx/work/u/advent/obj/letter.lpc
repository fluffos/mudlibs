//buy advent
//for hubiao test
inherit ITEM;
void create()
{
        set_name("接头信函", ({"dart letter", "letter"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
"这是交付红货时伙计给护镖者的信函，凭此信函中的内容向林大镖头领取奖励。\n"
"你可以拆（chai）开看看写了些什么。\n");
                set("material", "paper");
        }
}
string do_chai()
{
  int dart_pw

  int ob

  ob=this_player()

     if(!ob->query_temp("yunbiao/dart_pw")) 
     {
      return "Ae悴鹂豢矗⑾Oe里面礎e文字龙飞凤舞的，Ae愀静恢浪戳诵词裁矗n"

     }
     else
     {
     dart_pw=ob->query_temp("yunbiao/dart_pw")

     write("Ae悴鹂豢矗⑾Oe里面写着几竜e大字：\n")

     write(dart_pw+"\n")

     }

