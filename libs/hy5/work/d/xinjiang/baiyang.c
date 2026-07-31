 /*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "白杨沟");
        set("long", @LONG
白杨沟位于天山支脉喀拉乌成山北麓中底山过渡带，沟中古树葱郁，
长满高大挺拔的榆树、杨树、槐树及说不出名字的灌木、鲜花。就是在
阳下，这里还是清凉无比，令人感到无限舒畅。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"chairong",
  "south" : __DIR__"bingchuan",
  "east" :  __DIR__"goudi",
])); 
   set("item_desc", ([
      "灌木": "一从不知名的灌木，长的正茂密。\n",
      "guanmu": "一从不知名的灌木，长的正茂密。\n",
      "杨树": "灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有
的似在哭．．其中的一个，目光似乎正落在一丛灌木上。\n",
      "yangshu":"灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有
的似在哭．．其中的一个，目光似乎正落在一丛灌木上。\n",
   ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1110);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_look", "look");
} 
int do_look(string arg)
{
   object me; 
   me = this_player(); 
   if (!arg || (arg != "杨树" && arg != "yangshu")) return 0;
   tell_object(me, "灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有
的似在哭．．其中的一个，目光似乎正落在一丛灌木上。\n");
//   me->set_temp("marks/foundjade", 1);
   return 1; 
} 
void dig_notify()
{
   object me, box;
   int llvl;
    if(query("already")) return 0; 
   me = this_player();
   llvl = (int)me->query("kar"); 
   box = present("iron box", this_object());
   if(random(100) < llvl) {
      message_vision("铛．．得一声，$N的镐似乎敲在了一个铁东西上。\n", me);
      tell_object(me, "低头一看，土坑里露出了一个铁盒。\n");
      if(!objectp(box)) {
         box = new(__DIR__"obj/box");
         box->move(this_object());
        set("already",1);
      }
   }
   else {
      message_vision("地上出现了一个土坑，除了腐朽的枝叶，$N什么都没有发现。\n",me);
   }   
}   
