//Cracked by Roath
// /kungfu/skill/zuoyou-hubo.c
// by sdong 07/98

inherit SKILL;
void create() { seteuid(getuid()); }
void init()
{
        add_action("do_hubo", "hubo");
}
string type() { return "knowledge"; }
int valid_learn(object me)
{
        if ( (int)me->query("int") >25 )
          return  notify_fail("你的天性不适合学习左右互博术。\n");
      if ( me->query("family/master_id")!="zhou botong")
      return notify_fail("左右互博之术唯有向周伯通学习。\n");
      return 1;
}
void do_hubo (string arg)
{
      write ( "你全身放松，坐下来开始运功疗伤。\n" );
}
