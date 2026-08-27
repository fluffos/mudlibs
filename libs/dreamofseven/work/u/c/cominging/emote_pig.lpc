string *emote = EMOTE_D->query_all_emote();

void delay_(int tar)
{
  if( tar > (sizeof(emote)-1) ) return;
  for(int x=0;x<11;x++) EMOTE_D->do_emote(find_player("cominging"), emote[tar] ,0, 0,0);
  call_out("delay_", 1, tar+1);
}

void remove_()
{
  remove_call_out("delay_");
}

void main(){ emote = sort_array(emote, 1); delay_(0); }
