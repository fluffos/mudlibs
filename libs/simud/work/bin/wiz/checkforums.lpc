int main() {
   string *forums = ({ "Bug", "Incoming Ideas", "Typo", "Helpfiles", "Newsoul" });
   string forum;
   object sql;
   mixed res;
   int count = 0;

   msg("Checking forums for open threads...");
   sql = clone_object("/secure/sql");
   sql->sql_connect("forums");
   foreach ( forum : forums ) {
	  int threads;
      res = sql->request("select fid from forum where name='"+forum+"'");
	  res = sql->request("select distinct thread from comment where status='open' and fid="+res[0][0]);
	  if (threads = sizeof(res)) {
	    msg(sprintf("%3d : %s",threads,forum));
		count += threads;
	  }
   }
   if (count)
      msg("A total of "+count+" threads are open in the player feedback forums.");
   else
      msg("No player feedback is pending on the forums. How wierd is that?");
   sql->sql_disconnect();
   destruct(sql);
   return 1;
}
