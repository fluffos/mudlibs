#include <channels.h>

private mapping channels;

mapping query_channels()
{
    if (!mappingp(channels)) return ([]);
    return copy(channels);
}

void set_channels(mapping m) { channels = m; }

void
c_channel(string ch)
{
    if (!mappingp(channels)) channels = ([]);

    if (!pointerp(channels[ch]) || !channels[ch])
    {
	m_delete(channels, ch);
	channels += ([ ch: ({ 0, 0,0,0,0 }) ]);
    }
}

int
query_channel_status(string ch)
{
    int s;

    c_channel(ch);
    s = channels[ch][0];
    if (!this_object()->is_npc()
      && !interactive(this_object())) return (s | CHANNEL_LD);
    return s;
}

int
is_on_channel(string ch)
{
    if (!this_object()->is_npc() && !interactive(this_object())) return 0;
    c_channel(ch);
    return !(channels[ch][0] & (CHANNEL_OFF | CHANNEL_BAN));
}

int
query_channel_ban(string ch)
{
    c_channel(ch);
    return (channels[ch][0] & (CHANNEL_BAN));
}

void
channel_on(string ch)
{
    c_channel(ch);
    channels[ch][0] = (channels[ch][0] & (~CHANNEL_OFF));
}

void
channel_off(string ch)
{
    c_channel(ch);
    channels[ch][0] = (channels[ch][0] | CHANNEL_OFF);
}

void
set_channel_ban(string ch, int ban)
{
    c_channel(ch);
    if (ban)
	channels[ch][0] = (channels[ch][0] | CHANNEL_BAN);
    else
	channels[ch][0] = (channels[ch][0] & (~CHANNEL_BAN));
}
