// mojiao.h

int permit_recruit(object ob)
{
object me;

me = this_object();

if (ob->query("detach/血河派"))
{
message_vision("$N大怒道：我血河派岂能由你要来便来，要走便走？\n",me);
return 0;
}
if (ob->query("betrayer/times"))
{
command("say 血河派讲究的就是信义，你这判师之人焉能理解？");
return 0;
}
if( ob->query("family/family_name") &&
 ob->query("family/family_name") != "血河派" )
{
command("say 你既有了名师指点，就要勤下苦功，勿要三心二意！");
return 0;
}
return 1;
}

