inherit ROOM;


void create()
{
   set("short","乐山");
   set("long",@LONG
乐山地处岷江与大渡河交汇之处，青山依依，绿水悠悠，水天一色之中更有
著名的乐山大佛石像，“佛即是山，山即是佛”，真是怡情旷目的好去处。西去
就是峨嵋山了。近年来山上佛寺日渐增多，香火渐盛；经常有进香客来拜佛。南
边是大渡河。
LONG);
   set("exits",([
      "north"   : __DIR__"pingyuan8",
      "northwest"    : "/d/emei/caopeng",
      "southwest"  : __DIR__"dadu_hebian",
   ]));
   set("outdoors","xinan");
   
   setup();
}
