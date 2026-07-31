inherit ROOM;

void create()
{
  set("short","大殿");
  set("long",@LONG
 这里是小寺庙的大殿。殿内香烟燎绕，幔角叮咚。香火旺盛的。
正前方供着个大肚子，似乎永远都笑咪咪的弥勒佛。四大天王分
列两旁，分执“风调雨顺”。两侧香桌上摆满了四季果蔬，弥勒
的身后站立的是韦驮。只见他金盔金甲，年轻英俊，威风凛凛，
双手合十，金刚杵横放腕上。左右两边各有一间偏殿
LONG);
  set("outdoors","yinju");
set("exits",([
   "south"  : __DIR__"shimiao",
  "east"  : __DIR__"hetang",
        ]));
  setup();
}