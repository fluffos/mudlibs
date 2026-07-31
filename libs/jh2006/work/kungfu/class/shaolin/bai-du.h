void attempt_apprentice(object ob)
{
 if (ob->query("passdu")&&ob->query("family/generation")>35) {
command("recruit " + ob->query("id"));
   return;
  }
command("say 对不起，老衲现在不收徒。");
}
