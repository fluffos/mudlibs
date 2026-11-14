string handshake_data;
int handshake;

 /* replace holey function with secure macro...
  *                 -credit to Desmodus for pointing this out
  *   -W

set_handshake(data) {
    handshake_data = data;
    handshake = random(100000000)+100;
    return handshake;
}
*/

get_handshake(confirm) {
    if (confirm == handshake && handshake) {
	handshake = 0;
	return handshake_data;
    } else {
	return 0;
    }
}

#define SET_HANDSHAKE(data) \
    handshake_data = data; \
    handshake = random(1000000000)+100;
