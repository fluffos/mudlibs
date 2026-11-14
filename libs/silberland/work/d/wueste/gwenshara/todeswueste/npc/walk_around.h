// Workaround, weil MNPCs warum auch immer nicht klappen
void walk_around()
{
  mapping exits;
  string *dirs, where;
  int i;

  exits = ENV(TO)->QueryProp(P_EXITS);
  dirs  = m_indices(exits);
  where = dirs[random(sizeof(dirs))];

  ENV(TO)->Message(BS(TO->Name(WER, 1)+" "+QueryProp(P_MSGOUT)+
                   " nach "+CAP(where)+"."), MSGFLAG_VISUAL);
  if(find_object(exits[where]))
    find_object(exits[where])->Message(BS(TO->Name(WER, 1)+" "+
                QueryProp(P_MSGIN)+"."), MSGFLAG_VISUAL);

  move(exits[where], M_GO|M_SILENT);
  call_out("walk_around", QueryProp(P_MNPC_WAIT)[1]+
                          random(QueryProp(P_MNPC_WAIT)[2]));
  return;
}
