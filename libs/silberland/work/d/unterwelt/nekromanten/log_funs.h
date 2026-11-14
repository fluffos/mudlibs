void NotifyPlayerDeath(object player, object killer, int lostexp) {
  if(killer == ME && stringp(QueryProp(P_NEKRO_LOG_PLAYERDEATH))) {
    write_file(QueryProp(P_NEKRO_LOG_PLAYERDEATH), sprintf(
        "%s: %s[%d/%d/%d] killt %O[%d/%d-%s,lxp:%d]\n",
        ctime(),
        explode(file_name(ME), "#")[0], 
        QueryProp(P_LEVEL), 
        QueryProp(P_GUILD_LEVEL),
        QueryProp(P_GUILD_CIRCLE),
        player,
        player->QueryProp(P_LEVEL), 
        player->QueryProp(P_GUILD_LEVEL), player->QueryProp(P_GUILD),
        lostexp));
  }
}


varargs void die(int poisondeath) {
  object killer;

  killer = QueryProp(P_KILLER)||TP;
  if(stringp(QueryProp(P_NEKRO_LOG_DEATH)))  {
    if(objectp(killer)) {
      write_file(QueryProp(P_NEKRO_LOG_DEATH), sprintf(
          "%s: %O[%d/%d-%s] killt %s[%d/%d/%d]\n",
          ctime(),killer, killer->QueryProp(P_LEVEL), 
          killer->QueryProp(P_GUILD_LEVEL), killer->QueryProp(P_GUILD),
          explode(file_name(ME), "#")[0], QueryProp(P_LEVEL), 
          QueryProp(P_GUILD_LEVEL),
          QueryProp(P_GUILD_CIRCLE)));
    }
    else {
      write_file(QueryProp(P_NEKRO_LOG_DEATH), sprintf(
          "%s: Unbekannt killt %s[%d/%d/%d]\n",
          ctime(), 
          explode(file_name(ME), "#")[0], QueryProp(P_LEVEL), 
          QueryProp(P_GUILD_LEVEL),
          QueryProp(P_GUILD_CIRCLE)));
    }
  }
  return ::die(poisondeath);
}
