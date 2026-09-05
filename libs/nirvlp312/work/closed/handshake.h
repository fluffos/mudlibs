mixed handshake_data;
int handshake;
/*
set_handshake(data) {
    handshake_data = data;
    handshake = random(100000000)+100;
    return handshake;
}
*/
get_handshake(confirm) {
#if 0 /* Rumplemintz - removing this */
if (version() != "3.01.02-DR")
{
write("/closed/handshake.h GETHANDSHAKE CALLED!\n");
return confirm;
}
#endif
    if (confirm == handshake && handshake) {
        handshake = 0;
	return handshake_data;
    } else {
        return 0;
    }
}

#define SET_HANDSHAKE(data) \
  handshake_data = data; \
  handshake = random(100000000)+100
