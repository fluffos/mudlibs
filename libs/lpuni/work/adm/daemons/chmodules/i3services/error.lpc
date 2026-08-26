 /* error.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 error service

 */

void rec_error(mixed *packet)
{
    object o_user;

    if(packet[D_USER] && (o_user = find_player(packet[D_USER])))
    {
        string emsg = sprintf("Error I3: %s", packet[7]);

        if(sizeof(packet[8]) && stringp(packet[8][D_MUD])) emsg += sprintf(" -- %s", packet[8][D_MUD]);

        tell_object(o_user, emsg + "\n");
    }

    I3LOG("Error [I3]: [" + packet[6] + "]: " + packet[7] +"\n" + sprintf("%O", packet[8]) + "\n");
}

varargs void send_error(mixed *packet, string err_code, string err_msg, int sendPacket)
{
    send_packet( ({
      "error",
      5,
      mud_name(),
      0,
      packet[O_MUD],
      packet[O_USER],
      err_code,
      err_msg,
      sendPacket ? packet : 0
    }) );
}