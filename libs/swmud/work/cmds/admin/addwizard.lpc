inherit CMD;

private nomask void main(string arg)
{
   object ob;
   string err;

   if (!arg)
   {
      out("Usage: addwizard <user>\n");

      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 4))
   {
      out("You need to be an admin in order to add new wizards.\n");

      return;
   }

   arg = lower_case(arg);

   if (!USER_D->user_exists(arg))
   {
      printf("** Error: '%s' doesn't actually exist as a user.\n", arg);
      return;
   }

   if (SECURE_D->query_is_wizard(arg))
   {
      printf("** '%s' is already a wizard.\n", capitalize(arg));

      if (!is_directory(wiz_dir(arg)))
      {
         printf("However, %s doesn't exist.  Creating...\n", wiz_dir(arg));
         mkdir(wiz_dir(arg));
         SECURE_D->set_protection(wiz_dir(arg), 1, arg + ":");
      }

      return;
   }

   err = SECURE_D->create_wizard(arg);

   if (err)
   {
      printf("** Error: %s\n", err);
      return;
   }

   mkdir(wiz_dir(arg));
   SECURE_D->set_protection(wiz_dir(arg), 1, arg + ":");

   printf("'%s' is now a wizard.\n", capitalize(arg));

   //### switch to an action?
   ob = find_user(arg);

   if (ob)
   {
      tell(ob, "You are now a wizard.  Changing bodies...\n");

      ob->force_me("su");

      ob = find_user(arg);

      ob->add_channel("wiz");
   }
}