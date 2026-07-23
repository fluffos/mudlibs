void init()
{
object ob=this_object();
::init();
set("chat_chance", 1);
set("chat_msg", ({
ob->name()+"拿起玉笛，轻声吹出几音。\n",
ob->name()+"对你微微一笑。\n",
ob->name()+"随乐轻歌慢舞起来。\n",
ob->name()+"轻拨琵琶，划出一曲流水。\n",
ob->name()+"轻舒纤腰，随音而舞起来。\n",
ob->name()+"咯咯一笑，露出两个小酒窝。\n",
ob->name()+"纤手轻拨琴弦，发出如柳润风般的乐声。\n",
ob->name()+"玉臂轻晃，随乐而舞。\n",
ob->name()+"轻音而唱，如雀鸣莺歌。\n",
}) );
}

