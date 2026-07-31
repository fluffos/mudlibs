void init()
{
 object ob;
 ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
set("dex",100);
   this_player()->start_busy(1);
   remove_call_out("greeting");
   call_out("greeting",0,ob);
   }
 }
void greeting(object ob)
{
 if (!ob||environment(ob)!=environment()) return;
 if (!ob->query_temp("huanggon/enter")&&ob->query("gender")!="中性")
    {
if (ob->query("xxy/lvl")<4) {
    command("say 大胆狂徒,竟敢擅闯皇宫.\n");
    kill_ob(ob);
ob->start_busy(2);
}
    return;
  }
 if (ob->query("gender")=="中性"&&ob->query("combat_exp")>500000)  {
 	command("say "+name()+"见过"+ob->query("name")+"公公.\n");
    } 
  return;
 }
