  if(this_object()->query_guild_name()) {
    if(sscanf(this_object()->query_guild_name(),"warrio%s",junk) 
    || sscanf(this_object()->query_guild_name(),"symbiot%s",junk) 
    || sscanf(this_object()->query_guild_name(),"Knights Temp%s",junk) 
    || sscanf(this_object()->query_guild_name(),"neo symbi%s",junk)) {
      if(auto_load && sscanf(auto_load, "%smaledicta/closed/w/gob%s",junk,junkb) == 2) {
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        write("****************************************************************************\n");
        write("maledicta's warriors are now closed.\n");
        write("clearing guild status and swapped exp.....\n");
        log_file("MAL_GUILD",cap_name+" "+guild_name+" "+guild_exp+" "+this_object()->query_guild_exp()*2/3+"\n");
        player_killing = 0;
        this_object()->set_guild_name(0);
        write(guild_name);
        experience += guild_exp*2/3;
        write(experience+" "+guild_exp);
        this_object()->add_guild_exp(-this_object()->query_guild_exp());
        this_object()->add_guild_rank(-this_object()->query_guild_rank());
        destruct(present("warrior_gob",this_object()));
        write("All set.\n");
        write("***************************************************************************\n");
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      }
      if(auto_load && sscanf(auto_load, "%smaledicta/venom%s",junk,junkb) == 2) {
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        write("****************************************************************************\n");
        write("maledicta's symbiotes are now closed.\n");
        write("clearing guild status and swapped exp.....\n");
        log_file("MAL_GUILD",cap_name+" "+guild_name+" "+guild_exp+" "+this_object()->query_exp()/3+"\n");
        player_killing = 0;
        this_object()->set_guild_name(0);
        this_object()->add_exp(this_object()->query_exp()/3);
        this_object()->add_guild_exp(-this_object()->query_guild_exp());
        this_object()->add_guild_rank(-this_object()->query_guild_rank());
        destruct(present("venom_object",this_object()));
        write("All set.\n");
        write("***************************************************************************\n");
        write("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      }
    }
  }
