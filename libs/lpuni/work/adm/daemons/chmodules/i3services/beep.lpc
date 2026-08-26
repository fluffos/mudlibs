 /* beep.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 beep service

 */

varargs void send_error(mixed *packet, string err_code, string err_msg, int send_packet);

void rec_beep(mixed *packet)
{
    object o_user;

    if(!packet[D_USER] || !(o_user = find_player(packet[D_USER])))
    {
        send_error(packet, "unk-user", packet[D_USER] + "@" + packet[D_MUD] + " was not found!", 1);
        return;
    }

    tell_object(o_user, "%^BOLD%^BEEP!\a BEEP!\a BEEP!\a%^RESET%^\n");
    tell_object(o_user, capitalize(packet[6]) + "@" + packet[O_MUD] + " just beeped you!\n");
}
